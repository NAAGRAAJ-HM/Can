/******************************************************************************/
/* File   : McalCan.c                                                         */
/*                                                                            */
/* Author : Raajnaag HULIYAPURADA MATA                                        */
/*                                                                            */
/* License / Warranty / Terms and Conditions                                  */
/*                                                                            */
/* Everyone is permitted to copy and distribute verbatim copies of this lice- */
/* nse document, but changing it is not allowed. This is a free, copyright l- */
/* icense for software and other kinds of works. By contrast, this license is */
/* intended to guarantee your freedom to share and change all versions of a   */
/* program, to make sure it remains free software for all its users. You have */
/* certain responsibilities, if you distribute copies of the software, or if  */
/* you modify it: responsibilities to respect the freedom of others.          */
/*                                                                            */
/* All rights reserved. Copyright © 1982 Raajnaag HULIYAPURADA MATA           */
/*                                                                            */
/* Always refer latest software version from:                                 */
/* https://github.com/RaajnaagHuliyapuradaMata?tab=repositories               */
/*                                                                            */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "Std_Types.h"

#include "CfgMcalCan.h"
#include "infMcalCanEcuabCanIf.h"
#include "infMcalCanMcalMcu.h"
#include "infMcalCanSwcServiceEcuM.h"
#include "infMcalCanSwcServiceOs.h"

#include "infEcuabCanTrcvEcuabCanIf.h" //TBD: Needs better architecture
#include "EcuabCanIf.h"
#include "infMcalDioMcalCan.h"
#include "infEcuabCanIfMcalCan.h"
#include "CanIf_Integration.h"
#include "Os_ConfigInterrupts.h"
#include "uC_Can.h"

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/
#ifndef CAN_ENABLE
#define CAN_ENABLE                                                            1U
#endif

#define CAN_RX_RULE_TYPE                                            can_cre_type
#define RX_RULE_NUM_CH0                                                    (13U)
#define RX_RULE_NUM_CH1                                                     (0U)
#define RX_RULE_NUM_CH2                                                     (0U)
#define RX_RULE_NUM_CH3                                                     (0U)
#define RX_RULE_NUM_CH4                                                     (0U)
#define CAN_C0RN                                                 RX_RULE_NUM_CH0
#define CAN_C1RN                                                 RX_RULE_NUM_CH1
#define CAN_C2RN                                                 RX_RULE_NUM_CH2
#define CAN_C3RN                                                 RX_RULE_NUM_CH3
#define CAN_C4RN                                                 RX_RULE_NUM_CH4
#define CAN_RX_RULE_NUM   (CAN_C0RN + CAN_C1RN + CAN_C2RN + CAN_C3RN + CAN_C4RN)
#define CAN_PAGE_RX_RULE_IDX_MASK                                           0xfU
#define CAN_RX_RULE_PAGE_IDX_BIT_POS                                          4U
#define CAN_RX_RULE_TABLE                                     RX_RULE_TABLE_LIST
#define RX_RULE_NUM                                                        (13U)
#define CAN_CHNL_TX_BUF_NUM                                                  16U
#define CAN_CLR                                                               0U
#define CAN_TBTST_TRANSMITTING                                                1U
#define CAN_TBTR_BIT_POS                                                      0U
#define CAN_TBCR_TRM                            (CAN_ENABLE << CAN_TBTR_BIT_POS)

#define CanMsgCGW_VCU_Powertrain_Info                              (uint16)0x0C0   /* must be linked to BSW RX Mailbox #1  */
#define CanMsgCGW_TPMS_ApplicationReq                              (uint16)0x620   /* must be linked to BSW RX Mailbox #2  */
#define CanMsgCGW_ESP_Wheel_Pulses                                 (uint16)0x070   /* must be linked to BSW RX Mailbox #3  */
#define CGW_TPMS_UDS_PhyReq                                        (uint16)0x73A   /* must be linked to BSW RX Mailbox #4  */
#define CanMsgCGW_ODO                                              (uint16)0x351   /* must be linked to BSW RX Mailbox #5  */
#define CanMsgCGW_VCU_Ambient_Info                                 (uint16)0x300   /* must be linked to BSW RX Mailbox #6  */
#define CanMsgCGW_VCU_WheelSpeed_F                                 (uint16)0x341   /* must be linked to BSW RX Mailbox #7  */
#define CanMsgCGW_ESP_VehicleSpeed                                 (uint16)0x410   /* must be linked to BSW RX Mailbox #8  */
#define CanMsgBCM_Power_Mode                                       (uint16)0x107   /* must be linked to BSW RX Mailbox #9  */
#define CanMsgCGW_EPOCHTime                                        (uint16)0x060   /* must be linked to BSW RX Mailbox #10 */
#define CanMsgCGW_VCU_WheelSpeed_R                                 (uint16)0x342   /* must be linked to BSW RX Mailbox #11 */
#define RdcData_TPMS                                               (uint16)0x400   /* must be linked to BSW RX Mailbox #12 */
#define CGW_TPMS_UDS_FuncReq                                       (uint16)0x7DF   /* must be linked to BSW RX Mailbox #13 */
#define cBUSOFFTIMEOUT                                                       200   /* Force busoff recovery after 2 seconds */

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* TYPEDEFS                                                                   */
/******************************************************************************/
typedef struct{
   uint32 lword[4];
}can_cre_type;

/******************************************************************************/
/* CONSTS                                                                     */
/******************************************************************************/
const can_cre_type RX_RULE_TABLE_LIST[RX_RULE_NUM] = {
   {{0x00000107UL, 0xDFFFFFFFUL, 0x00000000UL, 0x00000001UL}},
   {{0x00000060UL, 0xDFFFFFFFUL, 0x00000000UL, 0x00000001UL}},
   {{0x00000410UL, 0xDFFFFFFFUL, 0x00000000UL, 0x00000001UL}},
   {{0x00000070UL, 0xDFFFFFFFUL, 0x00000000UL, 0x00000001UL}},
   {{0x00000351UL, 0xDFFFFFFFUL, 0x00000000UL, 0x00000001UL}},
   {{0x00000300UL, 0xDFFFFFFFUL, 0x00000000UL, 0x00000001UL}},
   {{0x000000C0UL, 0xDFFFFFFFUL, 0x00000000UL, 0x00000001UL}},
   {{0x00000341UL, 0xDFFFFFFFUL, 0x00000000UL, 0x00000001UL}},
   {{0x00000342UL, 0xDFFFFFFFUL, 0x00000000UL, 0x00000001UL}},
   {{0x00000620UL, 0xDFFFFFFFUL, 0x00000000UL, 0x00000001UL}},
   {{0x00000400UL, 0xDFFFFFFFUL, 0x00000000UL, 0x00000001UL}},
   {{0x0000073AUL, 0xDFFFFFFFUL, 0x00000000UL, 0x00000001UL}},
   {{0x000007DFUL, 0xDFFFFFFFUL, 0x00000000UL, 0x00000001UL}},
};

/******************************************************************************/
/* PARAMS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* OBJECTS                                                                    */
/******************************************************************************/
CanIf_ControllerModeType ucControllerMode = CANIF_CS_UNINIT;

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
static void SetRxRule(void){
   uint16 RxRuleIdx;
   uint8  PageRxRuleIdx;
   volatile CAN_RX_RULE_TYPE *pCRE;
   RSCAN0GAFLCFG0 |= (RX_RULE_NUM_CH0 << 24);
   pCRE = (volatile CAN_RX_RULE_TYPE*)&(RSCAN0GAFLID0);
   RSCAN0GAFLECTR |= 0x00000100u;

   for(
      RxRuleIdx = 0U;
      RxRuleIdx < CAN_RX_RULE_NUM;
      RxRuleIdx ++
   ){
      PageRxRuleIdx = (uint8)(RxRuleIdx & CAN_PAGE_RX_RULE_IDX_MASK);
      if(PageRxRuleIdx == 0U){
         RSCAN0GAFLECTR |= RxRuleIdx >> CAN_RX_RULE_PAGE_IDX_BIT_POS;
      }
      pCRE[PageRxRuleIdx] = CAN_RX_RULE_TABLE[RxRuleIdx];
   }
   RSCAN0GAFLECTR &= 0xfffffeffu;
}

void RS_CAN_Init(void){
   protected_write(
         PROTCMD1
      ,  PROTS1
      ,  CKSC_ICANOSCD_CTL
      ,  0x01u
   );

   while(0x01 != CKSC_ICANOSCD_ACT);

   protected_write(
         PROTCMD1
      ,  PROTS1
      ,  CKSC_ICANS_CTL
      ,  0x03
   );

   while(0x03 != CKSC_ICANS_ACT);

   infMcalDioMcalCan_InitFunction();

   while((RSCAN0GSTS & 0x00000008u)){}

   RSCAN0GCTR  &= 0xfffffffbu;
   RSCAN0C0CTR &= 0xfffffffbu;
   RSCAN0GCFG   = 0x00000010u;
   RSCAN0C0CFG  = 0x023a0001u;

   SetRxRule();

   RSCAN0RMNB   = 0x00;
   RSCAN0RFCC0 |= 0x1000;
   RSCAN0RFCC0 |= 0x400;
   RSCAN0RFCC0 |= 0x2;
   RSCAN0GCTR  &= 0xfffff8ffu;
   RSCAN0TMIEC0 = 0x000000ff;

   if(RSCAN0GSTS & 0x03u){
      RSCAN0GCTR &= 0xfffffffcu;
      while((RSCAN0GSTS & 0x02u) == 2u){}
      while((RSCAN0GSTS & 0x01u) == 1u){}
   }

   if(RSCAN0C0STS & 0x03u){
      RSCAN0C0CTR &= 0xfffffffcu;
      while((RSCAN0C0STS & 0x02u) == 2u){}
      while((RSCAN0C0STS & 0x01u) == 1u){}
   }

   RSCAN0RFCC0 |= 0x1;
}

FUNC(void, MCALCAN_CODE) infMcalCanSwcServiceEcuM_vInitFunction(void){
   protected_write(
         PROTCMD1
      ,  PROTS1
      ,  CKSC_ICANOSCD_CTL
      ,  0x01u
   );

   while(CKSC_ICANOSCD_ACT != 0x01);

   protected_write(
         PROTCMD1
      ,  PROTS1
      ,  CKSC_ICANS_CTL
      ,  0x03
   );

   while(CKSC_ICANS_ACT != 0x03);

   infMcalDioMcalCan_InitFunction();

   while((RSCAN0GSTS & 0x00000008u)){}

   RSCAN0GCTR  &= 0xfffffffbu;
   RSCAN0C0CTR &= 0xfffffffbu;
   RSCAN0GCFG   = 0x00000010u;
   RSCAN0C0CFG  = 0x023a0001u;

   SetRxRule();

   RSCAN0RMNB   = 0x00;
   RSCAN0RFCC0 |= 0x1000;
   RSCAN0RFCC0 |= 0x400;
   RSCAN0RFCC0 |= 0x2;
   RSCAN0GCTR  &= 0xfffff8ffu;
   RSCAN0TMIEC0 = 0x000000ff;

   if(RSCAN0GSTS & 0x03u){
      RSCAN0GCTR &= 0xfffffffcu;
      while((RSCAN0GSTS & 0x02u) == 2u){}
      while((RSCAN0GSTS & 0x01u) == 1u){}
   }

   if(RSCAN0C0STS & 0x03u){
      RSCAN0C0CTR &= 0xfffffffcu;
      while((RSCAN0C0STS & 0x02u) == 2u){}
      while((RSCAN0C0STS & 0x01u) == 1u){}
   }

   ucControllerMode = CANIF_CS_STARTED;
}

FUNC(void, MCALCAN_CODE) McalCan_ClearRxFiFoInterruptFlag(void){
   RSCAN0RFSTS0 &= ~0x8;
}

FUNC(void, MCALCAN_CODE) McalCan_ClearTxBufferInterruptFlag(void){
   uint8 ucTxBufIdx;
   VU8* pTBSR = &(RSCAN0TMSTS0);

   for(
      ucTxBufIdx = 0;
      ucTxBufIdx < CAN_CHNL_TX_BUF_NUM;
      ucTxBufIdx ++
   ){
      pTBSR[ucTxBufIdx] = CAN_CLR;
   }
}

FUNC(void, MCALCAN_CODE) McalCan_ForwardMessageToCanIf(
   const McalCan_FrameType* tCanFrame
){
   Can_HwType               tCanMailbox;
   Type_stInfoPdu           tPduInfo;
   CanIf_ControllerModeType tCanIfControllerMode;

   CanIf_GetControllerMode(
         0
      ,  &tCanIfControllerMode
   );

   if(
         CANIF_CS_STARTED
      == tCanIfControllerMode
   ){
      tCanMailbox.CanId = tCanFrame->ID;
      switch(tCanMailbox.CanId){
         case CanMsgCGW_VCU_Powertrain_Info: tCanMailbox.Hoh = CanIfConf_CanIfHrhCfg_Can_Network_CANNODE_0_Rx_Std_MailBox_1_Config;  break;
         case CanMsgCGW_TPMS_ApplicationReq: tCanMailbox.Hoh = CanIfConf_CanIfHrhCfg_Can_Network_CANNODE_0_Rx_Std_MailBox_2_Config;  break;
         case CanMsgCGW_ESP_Wheel_Pulses:    tCanMailbox.Hoh = CanIfConf_CanIfHrhCfg_Can_Network_CANNODE_0_Rx_Std_MailBox_3_Config;  break;
         case CGW_TPMS_UDS_PhyReq:           tCanMailbox.Hoh = CanIfConf_CanIfHrhCfg_Can_Network_CANNODE_0_Rx_Std_MailBox_4_Config;  break;
         case CanMsgCGW_ODO:                 tCanMailbox.Hoh = CanIfConf_CanIfHrhCfg_Can_Network_CANNODE_0_Rx_Std_MailBox_5_Config;  break;
         case CanMsgCGW_VCU_Ambient_Info:    tCanMailbox.Hoh = CanIfConf_CanIfHrhCfg_Can_Network_CANNODE_0_Rx_Std_MailBox_6_Config;  break;
         case CanMsgCGW_VCU_WheelSpeed_F:    tCanMailbox.Hoh = CanIfConf_CanIfHrhCfg_Can_Network_CANNODE_0_Rx_Std_MailBox_7_Config;  break;
         case CanMsgCGW_ESP_VehicleSpeed:    tCanMailbox.Hoh = CanIfConf_CanIfHrhCfg_Can_Network_CANNODE_0_Rx_Std_MailBox_8_Config;  break;
         case CanMsgBCM_Power_Mode:          tCanMailbox.Hoh = CanIfConf_CanIfHrhCfg_Can_Network_CANNODE_0_Rx_Std_MailBox_9_Config;  break;
         case CanMsgCGW_EPOCHTime:           tCanMailbox.Hoh = CanIfConf_CanIfHrhCfg_Can_Network_CANNODE_0_Rx_Std_MailBox_10_Config; break;
         case CanMsgCGW_VCU_WheelSpeed_R:    tCanMailbox.Hoh = CanIfConf_CanIfHrhCfg_Can_Network_CANNODE_0_Rx_Std_MailBox_11_Config; break;
         case RdcData_TPMS:                  tCanMailbox.Hoh = CanIfConf_CanIfHrhCfg_Can_Network_CANNODE_0_Rx_Std_MailBox_12_Config; break;
         case CGW_TPMS_UDS_FuncReq:          tCanMailbox.Hoh = CanIfConf_CanIfHrhCfg_Can_Network_CANNODE_0_Rx_Std_MailBox_13_Config; break;
         default:                                                                                                                    break;
      }

      tCanMailbox.ControllerId = 0;
      tPduInfo.tLengthSdu       = tCanFrame->DLC;
      tPduInfo.ptru8DataSdu     = (uint8*)tCanFrame->DB;

      CanIf_RxIndication(
         &tCanMailbox,
         &tPduInfo
      );
   }
}

FUNC(void, MCALCAN_CODE) McalCan_MainFunction_BusOff(void){
   static uint8 ucBusoffTime = 0;

   if(RSCAN0C0STS & 0x10u){
      ucBusoffTime = cBUSOFFTIMEOUT;
   }

   if(ucBusoffTime > 0){
      infEcuabCanIfMcalCan_ControllerBusOff(0);
      if(--ucBusoffTime == 0){
         RSCAN0C0CTR |= 0x8;
         if(
               E_NOT_OK
            == CanIf_SetPduMode(
                     0
                  ,  CANIF_ONLINE
               )
         ){
            Mcu_PerformReset();
         }
      }
   }
}

FUNC(McalCan_RtnType, MCALCAN_CODE) McalCan_ReadRxFiFo(McalCan_FrameType* pFrame){
   if(0 == (RSCAN0RFSTS0 & 0x1)){
      pFrame->IDE   = (RSCAN0RFID0  & 0x80000000) >> 31;
      pFrame->RTR   = (RSCAN0RFID0  & 0x40000000) >> 30;
      pFrame->THLEN = (RSCAN0RFID0  & 0x20000000) >> 29;
      pFrame->ID    = (RSCAN0RFID0  & 0x1fffffff);
      pFrame->DLC   = (RSCAN0RFPTR0 & 0xf0000000) >> 28;
      pFrame->LBL   = (RSCAN0RFPTR0 & 0x0fff0000) >> 16;
      pFrame->TS    = (RSCAN0RFPTR0 & 0x0000ffff);
      pFrame->DB[7] = (RSCAN0RFDF10 & 0xff000000) >> 24;
      pFrame->DB[6] = (RSCAN0RFDF10 & 0x00ff0000) >> 16;
      pFrame->DB[5] = (RSCAN0RFDF10 & 0x0000ff00) >> 8;
      pFrame->DB[4] = (RSCAN0RFDF10 & 0x000000ff) >> 0;
      pFrame->DB[3] = (RSCAN0RFDF00 & 0xff000000) >> 24;
      pFrame->DB[2] = (RSCAN0RFDF00 & 0x00ff0000) >> 16;
      pFrame->DB[1] = (RSCAN0RFDF00 & 0x0000ff00) >> 8;
      pFrame->DB[0] = (RSCAN0RFDF00 & 0x000000ff) >> 0;
      RSCAN0RFPCTR0 = 0xff;
   }

   return(
      (RSCAN0RFSTS0 & 0x1)
      ?  CAN_RTN_BUFFER_EMPTY
      :  CAN_RTN_OK
   );
}

void RS_CAN_SetSleepMode(void){
   RSCAN0C0CTR |= 0x2;
   RSCAN0GCTR  |= 0x2;
}

void RS_CAN_SetResetMode(void){
   RSCAN0C0CTR &= ~0x2;
   RSCAN0GCTR  &= ~0x2;
   RSCAN0C0CTR |= 0x1;
   RSCAN0GCTR  |= 0x1;
}

FUNC(Type_McalCan_eReturn, MCALCAN_CODE) McalCan_SetControllerMode(
      uint8                         ucController
   ,  Type_McalCan_eStateTransition ucMode
){
   switch(ucControllerMode){
      case CANIF_CS_SLEEP:
         if(ucMode == CAN_T_WAKEUP){
            RS_CAN_SetResetMode();
            Os_Disable_CAT2ISR_Can0Receive();
            Os_Disable_CAT2ISR_Can0Transmit();
            ucControllerMode = CANIF_CS_STOPPED;
         }
         break;

      case CANIF_CS_STOPPED:
         if(ucMode == CAN_T_START){
            RS_CAN_Init();
            Os_Enable_CAT2ISR_Can0Receive();
            Os_Enable_CAT2ISR_Can0Transmit();
            EcuabCanTrcvEcuabCanIf_SetModeNormal();
            ucControllerMode = CANIF_CS_STARTED;
         }
         else if(ucMode == CAN_T_SLEEP){
            RS_CAN_SetSleepMode();
            Os_Disable_CAT2ISR_Can0Receive();
            Os_Disable_CAT2ISR_Can0Transmit();
            EcuabCanTrcvEcuabCanIf_SetModeStandby();
            ucControllerMode = CANIF_CS_SLEEP;
         }
         break;

      case CANIF_CS_STARTED:
         if(ucMode == CAN_T_STOP){
            RS_CAN_SetResetMode();
            Os_Disable_CAT2ISR_Can0Receive();
            Os_Disable_CAT2ISR_Can0Transmit();
            ucControllerMode = CANIF_CS_STOPPED;
         }
         break;

      default:
         break;
   }

   CanIf_ControllerModeIndication(
         ucController
      ,  ucControllerMode
   );
   return CAN_OK;
}

McalCan_RtnType SendTxBuffer(const McalCan_FrameType* pFrame){
   static uint8              ucTxBufIdx = 0;
          McalCan_RtnType    ucRetVal;
          McalCan_FrameType* pTxBuffer;
          VU8*               pTBSR = &(RSCAN0TMSTS0);
          VU8*               pTBCR = &(RSCAN0TMC0); 

   if(
         CAN_TBTST_TRANSMITTING
      == (pTBSR[ucTxBufIdx] & (VU8)0x01u)
   ){
      ucRetVal = CAN_RTN_ERR;
   }
   else{
      pTxBuffer             = (McalCan_FrameType*) &(RSCAN0TMID0);
      pTxBuffer[ucTxBufIdx] = *pFrame;
      pTBCR[ucTxBufIdx]     = CAN_TBCR_TRM;
      ucRetVal              = CAN_RTN_OK;
      ucTxBufIdx++;
      ucTxBufIdx           %= CAN_CHNL_TX_BUF_NUM;
   }
   return ucRetVal;
}

FUNC(Type_McalCan_eReturn, MCALCAN_CODE) McalCan_Write(
            Type_McalCan_HwHandle ucHthRefId
   ,  const Type_McalCan_Pdu*     PduInfo_Write
){
   McalCan_FrameType tTxCanFrame;
   uint8 i;
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

   SendTxBuffer(&tTxCanFrame);
   infEcuabCanIfMcalCan_TxConfirmation(PduInfo_Write->swPduHandle);

   return CAN_OK;
}

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

