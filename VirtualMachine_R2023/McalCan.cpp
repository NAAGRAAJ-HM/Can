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

#include "infEcuabCanIfMcalCan.hpp"
#include "CanTypes.hpp"
#include "infMcalCanSwcServiceEcuM.hpp"
#include "infMcalCanSwcServiceSchM.hpp"

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
McalCan_tstRxFifioElement McalCan_astRxFifio[McalCan_LengthBuffer];

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
FUNC(void, MCALCAN_CODE) infMcalCanSwcServiceEcuM_InitFunction(void){
}

FUNC(void, MCALCAN_CODE) infMcalCanSwcServiceEcuM_DeInitFunction (void){
}

uint8 McalCan_ReadRxFifio(McalCan_teStatusReadRxFifio* ptrStatusReadRxFifio){
   //TBD: Simulate Can bus reading here!
   *ptrStatusReadRxFifio = McalCan_eStatusReadRxFifio_BufferOk;
   return 0; //TBD: returns the index from McalCan_auBufferRx[McalCan_BufferLength]
}

FUNC(void, MCALCAN_CODE) infMcalCanSwcServiceSchM_MainFunction(void){
   McalCan_teStatusReadRxFifio McalCan_StatusReadRxFifio = McalCan_eStatusReadRxFifio_BufferError;
   do{
      uint8 lu8IndexBufferRx = McalCan_ReadRxFifio(&McalCan_StatusReadRxFifio);
      infEcuabCanIfMcalCan_RxIndication(lu8IndexBufferRx);
   }while(McalCan_eStatusReadRxFifio_BufferEmpty != McalCan_StatusReadRxFifio);
}

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

