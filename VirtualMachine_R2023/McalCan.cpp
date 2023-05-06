/******************************************************************************/
/* File   : McalCan.cpp                                                       */
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
#include "Std_Types.hpp"

#include "McalCan.hpp"

#include "CfgMcalCan.hpp"
#include "infEcuabCanIfMcalCan.hpp"
#include "CanTypes.hpp"
#include "infMcalCanSwcServiceEcuM.hpp"
#include "infMcalCanSwcServiceSchM.hpp"
#include "LibAutosarFifo.hpp"

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/

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
LibAutosarFifo_t          McalCan_stFifoIndexBufferRx;
LibAutosarFifo_tItem      McalCan_atBuffer[CfgMcalCan_dNumMaxRequests];

McalCan_tstRxFifioElement McalCan_astRxFifio[McalCan_LengthBuffer] = {
      {CfgEcuabCanIf_IdCanFrameExtendedRxUdsFunctional,  0, 0, 1, 0, 0, 8, {0x02, 0x3E, 0x00, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA}}
   ,  {CfgEcuabCanIf_IdCanFrameExtendedRxUdsFunctional,  0, 0, 0, 0, 0, 8, {0x02, 0x11, 0x02, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA}}
   ,  {CfgEcuabCanIf_IdCanFrameExtendedRxBcmVehicleInfo, 0, 0, 0, 0, 0, 8, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}}
   ,  {CfgEcuabCanIf_IdCanFrameExtendedRxBcmVehicleInfo, 0, 0, 0, 0, 0, 8, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}}
   ,  {CfgEcuabCanIf_IdCanFrameExtendedRxBcmVehicleInfo, 0, 0, 0, 0, 0, 8, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}}
   ,  {CfgEcuabCanIf_IdCanFrameExtendedRxBcmVehicleInfo, 0, 0, 0, 0, 0, 8, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}}
   ,  {CfgEcuabCanIf_IdCanFrameExtendedRxBcmVehicleInfo, 0, 0, 0, 0, 0, 8, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}}
   ,  {CfgEcuabCanIf_IdCanFrameExtendedRxBcmVehicleInfo, 0, 0, 0, 0, 0, 8, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}}
   ,  {CfgEcuabCanIf_IdCanFrameExtendedRxBcmVehicleInfo, 0, 0, 0, 0, 0, 8, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}}
   ,  {CfgEcuabCanIf_IdCanFrameExtendedRxBcmVehicleInfo, 0, 0, 0, 0, 0, 8, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}}
};

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
FUNC(void, MCALCAN_CODE) infMcalCanSwcServiceEcuM_InitFunction(void){
   (void)LibAutosarFifo_InitFunction( //TBD: Handle not OK cases
         &McalCan_stFifoIndexBufferRx
      ,  &McalCan_atBuffer[0]
      ,  CfgMcalCan_dNumMaxRequests
   );
   (void)LibAutosarFifo_Put(&McalCan_stFifoIndexBufferRx, 0); //TBD: Remove test code
   (void)LibAutosarFifo_Put(&McalCan_stFifoIndexBufferRx, 1); //TBD: Remove test code
}

FUNC(void, MCALCAN_CODE) infMcalCanSwcServiceEcuM_DeInitFunction(void){
}

FUNC(void, MCALCAN_CODE) infMcalCanSwcServiceSchM_MainFunction(void){
   uint8 lu8IndexBufferRx;
   while(
         LibAutosarFifo_eStatus_Underflow
      != LibAutosarFifo_Get(&McalCan_stFifoIndexBufferRx, &lu8IndexBufferRx)
   ){
      infEcuabCanIfMcalCan_RxIndication(lu8IndexBufferRx);
   }
}

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

