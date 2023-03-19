/******************************************************************************/
/* File   : McalCan.cpp                                                       */
/* Author : NAGARAJA HM (c) since 1982. All rights reserved.                  */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "Std_Types.hpp"

#include "McalCan.hpp"

#include "infEcuabCanIfMcalCan.hpp"
#include "CanTypes.hpp"
#include "infMcalCanServiceSwcEcuM.hpp"
#include "infMcalCanServiceSwcSchM.hpp"

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* TYPEDEFS                                                                   */
/******************************************************************************/
typedef enum{
      McalCan_eIdMsg_RxUds_Physical   = 0x73A
   ,  McalCan_eIdMsg_RxUds_Functional = 0x7DF
}McalCan_teIdMsg;

typedef enum{
      McalCan_eStatusReadRxFifio_BufferOk = 0U
   ,  McalCan_eStatusReadRxFifio_BufferFull
   ,  McalCan_eStatusReadRxFifio_BufferEmpty
   ,  McalCan_eStatusReadRxFifio_BufferError
}McalCan_teStatusReadRxFifio;

/******************************************************************************/
/* CONSTS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* PARAMS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* OBJECTS                                                                    */
/******************************************************************************/
McalCan_tuBufferElement McalCan_auBufferRx[McalCan_BufferLength];

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
FUNC(void, MCALCAN_CODE) infMcalCanServiceSwcEcuM_InitFunction(void){
}

FUNC(void, MCALCAN_CODE) infMcalCanServiceSwcEcuM_DeInitFunction (void){
}

uint8 McalCan_ReadRxFifio(McalCan_teStatusReadRxFifio* ptrStatusReadRxFifio){
   //TBD: Simulate Can bus reading here!
   *ptrStatusReadRxFifio = McalCan_eStatusReadRxFifio_BufferOk;
   return 0; //TBD: returns the index from McalCan_auBufferRx[McalCan_BufferLength]
}

FUNC(void, MCALCAN_CODE) infMcalCanServiceSwcSchM_MainFunction(void){
   McalCan_teStatusReadRxFifio McalCan_StatusReadRxFifio;

   do{
      uint8 lu8IndexBufferRx = McalCan_ReadRxFifio(&McalCan_StatusReadRxFifio);

      //TBD: Initialization code not yet implemented! - refer reference project
      switch(McalCan_auBufferRx[lu8IndexBufferRx].McalCan_stContext.McalCan_stFrameExtended.ID){
         case McalCan_eIdMsg_RxUds_Functional: McalCan_auBufferRx[lu8IndexBufferRx].McalCan_stContext.eHardwareObjectHandle = EcuabCanIf_eHardwareObjectHandle_RxUds_Functional; break;
         case McalCan_eIdMsg_RxUds_Physical:   McalCan_auBufferRx[lu8IndexBufferRx].McalCan_stContext.eHardwareObjectHandle = EcuabCanIf_eHardwareObjectHandle_RxUds_Physical;   break;
      }
      McalCan_auBufferRx[lu8IndexBufferRx].McalCan_stContext.u8IdController = 0;

      infEcuabCanIfMcalCan_RxIndication(lu8IndexBufferRx);

   }while(McalCan_eStatusReadRxFifio_BufferEmpty != McalCan_StatusReadRxFifio);
}

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

