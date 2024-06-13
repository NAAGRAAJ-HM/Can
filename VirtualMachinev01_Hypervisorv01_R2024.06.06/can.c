/******************************************************************************/
/* File   : McalCan.c                                                         */
/* Author : Nagaraja HULIYAPURADA-MATA                                        */
/* Date   : 01.02.1982                                                        */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "Std_Types.hpp"

#include "infMcalCanSwcApplEcuM.hpp"
#include "infMcalCanSwcServiceSchM.hpp"
#include "infMcalCanEcuabCanIf.hpp"

#include "rscanX.hpp"
#include "Com_Cfg_SymbolicNames.hpp"
#include "Type_EcuabTrcvCan.hpp"

#include "device.hpp"
#include "CanIf.hpp"
#include "CanIf_Cfg_SymbolicNames.hpp"
#include "ComStack_Types.hpp"
#include "can_table.hpp"
#include "CanIf_Cbk.hpp"
#include "EcuM_Cbk.hpp"
#include "Os_ConfigInterrupts.hpp"
#include "CanTrcv.hpp"

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/
#define CAN_AR_RELEASE_MAJOR_VERSION                                           4
#define CAN_AR_RELEASE_MINOR_VERSION                                           2
#define CfgEcuabCanIf_dIdCanRx_UdsReqPhy                           (uint16)0x73A
#define CfgEcuabCanIf_dIdCanRx_UdsReqFunc                          (uint16)0x7DF
#define CfgEcuabCanIf_dIdCanRx_ApplicationReq                      (uint16)0x63A
#define CfgEcuabCanIf_dIdCanRx_BcmPeripheralMasterclock            (uint16)0x208
#define CfgEcuabCanIf_dIdCanRx_EspWheelSpeed_F                     (uint16)0x209
#define CfgEcuabCanIf_dIdCanRx_EspWheelSpeed_R                     (uint16)0x20A
#define CfgEcuabCanIf_dIdCanRx_EspWheelPulsesStamped               (uint16)0x20B
#define CfgEcuabCanIf_dIdCanRx_TmmStatus                           (uint16)0x315
#define CfgEcuabCanIf_dIdCanRx_TmpsRdcData                         (uint16)0x300
#define CfgEcuabCanIf_dIdCanRx_VehStatus                           (uint16)0x210
#define CfgEcuabCanIf_dIdCanRx_VmsStatusReq                        (uint16)0x330
#define cBUSOFFTIMEOUT                                                       200

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* TYPEDEFS                                                                   */
/******************************************************************************/

/******************************************************************************/
/* CONSTS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* PARAMS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* OBJECTS                                                                    */
/******************************************************************************/
Type_EcuabCanIf_eModesController eModeController = EcuabCanIf_eModeController_UNINIT;

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
void infMcalCanSwcApplEcuM_vInitFunction(void){
   RS_CAN_Init();
   eModeController = EcuabCanIf_eModeController_STARTED;
}

void Can_SetBaudrate(void){
}

Type_McalCan_eReturn infMcalCanEcuabCanIf_tSetModeController(
      uint8                         ucController
   ,  Type_McalCan_eStatesTransition leStateTransition
){
  switch(eModeController){
   case EcuabCanIf_eModeController_SLEEP:
      if(leStateTransition == McalCan_eStatesTransition_WAKEUP){
        RS_CAN_SetResetMode();
        Os_Disable_CAT2ISR_Can0Receive();
        Os_Disable_CAT2ISR_Can0Transmit();
        eModeController = EcuabCanIf_eModeController_STOPPED;
      }
   break;

   case EcuabCanIf_eModeController_STOPPED:
      if(leStateTransition == McalCan_eStatesTransition_START){
        RS_CAN_Init();
        Os_Enable_CAT2ISR_Can0Receive();
        Os_Enable_CAT2ISR_Can0Transmit();
        TRCV_Normal();
        eModeController = EcuabCanIf_eModeController_STARTED;
      }
      else if(leStateTransition == McalCan_eStatesTransition_SLEEP){
        RS_CAN_SetSleepMode();
        Os_Disable_CAT2ISR_Can0Receive();
        Os_Disable_CAT2ISR_Can0Transmit();
        TRCV_Standby();
        eModeController = EcuabCanIf_eModeController_SLEEP;
      }
   break;

   case EcuabCanIf_eModeController_STARTED:
      if(leStateTransition == McalCan_eStatesTransition_STOP){
        RS_CAN_SetResetMode();
        Os_Disable_CAT2ISR_Can0Receive();
        Os_Disable_CAT2ISR_Can0Transmit();
        eModeController = EcuabCanIf_eModeController_STOPPED;
      }
   break;

    default:
   break;
  }

  CanIf_ControllerModeIndication(ucController, eModeController);
  return McalCan_eReturn_OK;
}

void infMcalCanSwcServiceSchM_vMainFunctionBusOff(void){
  static uint8 ucBusoffTime = 0;
  if(RSCAN0C0STS & 0x10u){
   ucBusoffTime = cBUSOFFTIMEOUT;
  }
  if(ucBusoffTime > 0){
   CanIf_ControllerBusOff(0);
   if(--ucBusoffTime == 0){
      RSCAN0C0CTR |= 0x8;
      if(CanIf_SetPduMode(0, EcuabCanIf_eModePdu_ONLINE) == E_NOT_OK){
        ApplMcu_vPerformReset();
      }
   }
  }
}

FUNC(void, MCALCAN_CODE) infMcalMcuSwcServiceSchM_vRunnableRx(
   const Type_McalCan_stFrame* tCanFrame
){
   Can_HwType                   tCanMailbox;
   Type_SwcServiceCom_stInfoPdu tPduInfo;
   Type_EcuabCanIf_eModesController tCanIfControllerMode;

   CanIf_GetControllerMode(
         0
      ,  &tCanIfControllerMode
   );
   if(
         tCanIfControllerMode
      == EcuabCanIf_eModeController_STARTED
   ){
      tCanMailbox.CanId = tCanFrame->ID;
      switch(
         tCanMailbox.CanId
      ){
         case CfgEcuabCanIf_dIdCanRx_ApplicationReq:           tCanMailbox.Hoh = CanIfConf_CanIfHrhCfg_Can_Network_CANNODE_0_Rx_Std_MailBox_1_Config;  break;
         case CfgEcuabCanIf_dIdCanRx_BcmPeripheralMasterclock: tCanMailbox.Hoh = CanIfConf_CanIfHrhCfg_Can_Network_CANNODE_0_Rx_Std_MailBox_2_Config;  break;
         case CfgEcuabCanIf_dIdCanRx_EspWheelSpeed_F:          tCanMailbox.Hoh = CanIfConf_CanIfHrhCfg_Can_Network_CANNODE_0_Rx_Std_MailBox_3_Config;  break;
         case CfgEcuabCanIf_dIdCanRx_UdsReqPhy:                tCanMailbox.Hoh = CanIfConf_CanIfHrhCfg_Can_Network_CANNODE_0_Rx_Std_MailBox_4_Config;  break;
         case CfgEcuabCanIf_dIdCanRx_UdsReqFunc:               tCanMailbox.Hoh = CanIfConf_CanIfHrhCfg_Can_Network_CANNODE_0_Rx_Std_MailBox_5_Config;  break;
         case CfgEcuabCanIf_dIdCanRx_EspWheelSpeed_R:          tCanMailbox.Hoh = CanIfConf_CanIfHrhCfg_Can_Network_CANNODE_0_Rx_Std_MailBox_6_Config;  break;
         case CfgEcuabCanIf_dIdCanRx_EspWheelPulsesStamped:    tCanMailbox.Hoh = CanIfConf_CanIfHrhCfg_Can_Network_CANNODE_0_Rx_Std_MailBox_7_Config;  break;
         case CfgEcuabCanIf_dIdCanRx_TmmStatus:                tCanMailbox.Hoh = CanIfConf_CanIfHrhCfg_Can_Network_CANNODE_0_Rx_Std_MailBox_8_Config;  break;
         case CfgEcuabCanIf_dIdCanRx_TmpsRdcData:              tCanMailbox.Hoh = CanIfConf_CanIfHrhCfg_Can_Network_CANNODE_0_Rx_Std_MailBox_9_Config;  break;
         case CfgEcuabCanIf_dIdCanRx_VehStatus:                tCanMailbox.Hoh = CanIfConf_CanIfHrhCfg_Can_Network_CANNODE_0_Rx_Std_MailBox_10_Config; break;
         case CfgEcuabCanIf_dIdCanRx_VmsStatusReq:             tCanMailbox.Hoh = CanIfConf_CanIfHrhCfg_Can_Network_CANNODE_0_Rx_Std_MailBox_11_Config; break;
         default:                                                                                                                                      break;
      }
      tCanMailbox.ControllerId = 0;
      tPduInfo.SduLength       = tCanFrame->DLC;
      tPduInfo.SduDataPtr      = (uint8*)tCanFrame->DB;

      CanIf_RxIndication_Internal(
            &tCanMailbox
         ,  &tPduInfo
      );
   }
}

Type_McalCan_eReturn infMcalCanEcuabCanIf_tWrite(
            Type_McalCan_tHandleHw ucHthRefId
   ,  const Type_McalCan_stPdu*    PduInfo_Write
){
   Type_McalCan_stFrame tTxCanFrame;
   uint8         i;
   for(
      i = 0;
      i < PduInfo_Write->length;
      i ++
   ){
      tTxCanFrame.DB[i] = PduInfo_Write->sdu[i];
   }
   tTxCanFrame.DLC   = PduInfo_Write->length;
   tTxCanFrame.ID    = PduInfo_Write->id;
   tTxCanFrame.IDE   = 0;
   tTxCanFrame.RTR   = 0;
   tTxCanFrame.THLEN = 0;
   Can_SendTxBuffer(
      &tTxCanFrame
   );
   CanIf_TxConfirmation(
      PduInfo_Write->swPduHandle
   );
   return McalCan_eReturn_OK;
}

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

