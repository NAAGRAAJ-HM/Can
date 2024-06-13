#pragma once
/******************************************************************************/
/* File   : Types_McalCan.hpp                                                 */
/* Author : Nagaraja HULIYAPURADA-MATA                                        */
/* Date   : 01.02.1982                                                        */
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
      CAN_OK
   ,  CAN_NOT_OK
   ,  CAN_BUSY
}Type_McalCan_eReturn;

typedef enum{
      CAN_T_START
   ,  CAN_T_STOP
   ,  CAN_T_SLEEP
   ,  CAN_T_WAKEUP
   ,  CAN_T_MAXTRANSITION
}Type_McalCan_eStateTransition;

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
