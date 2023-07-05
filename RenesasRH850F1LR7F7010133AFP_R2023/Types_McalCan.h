#ifndef _TYPES_MCALCAN_H
#define _TYPES_MCALCAN_H
/******************************************************************************/
/* File   : Types_McalCan.h                                                   */
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
#include "ComStack_Cfg.h"

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
      CAN_OK
   ,  CAN_NOT_OK
   ,  CAN_BUSY
} Type_McalCan_eReturn;

typedef enum{
      CAN_T_START,
      CAN_T_STOP,
      CAN_T_SLEEP,
      CAN_T_WAKEUP,
      CAN_T_MAXTRANSITION
}Type_McalCan_eStateTransition;

typedef uint16 Type_McalCan_HwHandle;
typedef uint32 Type_McalCan_Id;

typedef struct{
   uint8*          sdu;
   Type_McalCan_Id id;
   Type_tIdPdu     swPduHandle;
   uint8           length;
}Type_McalCan_Pdu;

typedef struct{
   Type_McalCan_Id       CanId;
   Type_McalCan_HwHandle Hoh;
   uint8                 ControllerId;
}Can_HwType;

typedef enum{
      CANTRCV_TRCVMODE_NORMAL = 0,
      CANTRCV_TRCVMODE_SLEEP,
      CANTRCV_TRCVMODE_STANDBY
}CanTrcv_TrcvModeType;

typedef enum{
      CANTRCV_WUMODE_ENABLE = 0,
      CANTRCV_WUMODE_DISABLE,
      CANTRCV_WUMODE_CLEAR
}CanTrcv_TrcvWakeupModeType;

typedef enum{
      CANTRCV_WU_ERROR = 0,
      CANTRCV_WU_NOT_SUPPORTED,
      CANTRCV_WU_BY_BUS,
      CANTRCV_WU_INTERNALLY,
      CANTRCV_WU_RESET,
      CANTRCV_WU_POWER_ON,
      CANTRCV_WU_BY_PIN
}CanTrcv_TrcvWakeupReasonType;

/******************************************************************************/
/* FUNCTIONS                                                                  */
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

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/
#endif

