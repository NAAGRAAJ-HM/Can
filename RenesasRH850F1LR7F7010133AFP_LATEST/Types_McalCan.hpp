#pragma once
/******************************************************************************/
/* File   : Types_McalCan.hpp                                                 */
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
#include "ComStack_Cfg.hpp"

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
      McalCan_eReturn_OK
   ,  McalCan_eReturn_NOK
   ,  McalCan_eReturn_BUSY
}Type_McalCan_eReturn;

typedef enum{
      McalCan_eStatesTransition_START
   ,  McalCan_eStatesTransition_STOP
   ,  McalCan_eStatesTransition_SLEEP
   ,  McalCan_eStatesTransition_WAKEUP
   ,  McalCan_eStatesTransition_MAX
}Type_McalCan_eStatesTransition;

typedef uint16 Type_McalCan_tHandleHw;
typedef uint32 Type_McalCan_tId;

typedef struct{
   P2VAR(uint8, TYPEDEF, CAN_UPPER_READONLY) sdu;
   Type_McalCan_tId                          id;
   Type_SwcServiceCom_tIdPdu                 swPduHandle;
   uint8                                     length;
}Type_McalCan_stPdu;

typedef struct{
   uint32 ID    :29;
   uint32 THLEN :1;
   uint32 RTR   :1;
   uint32 IDE   :1;
   uint32 TS    :16;
   uint32 LBL   :12;
   uint32 DLC   :4;
   uint8  DB[8];
}Type_McalCan_stFrame;

/******************************************************************************/
/* CONSTS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* PARAMS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* OBJECTS                                                                    */
/******************************************************************************/

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

