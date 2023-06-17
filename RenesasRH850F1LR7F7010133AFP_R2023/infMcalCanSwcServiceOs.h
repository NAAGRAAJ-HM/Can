#ifndef _INFMCALCANSWCSERVICEOS_H
#define _INFMCALCANSWCSERVICEOS_H
/******************************************************************************/
/* File   : infMcalCanSwcServiceOs.h                                          */
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
#include "CompilerCfg_McalCan.h"

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/
//TBD: make it enaum, modular and well architectured
#define CAN_RTN_OK                          0U
#define CAN_RTN_FIFO_FULL                   1U
#define CAN_RTN_BUFFER_EMPTY                2U
#define CAN_RTN_ERR                         255U

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* TYPEDEFS                                                                   */
/******************************************************************************/
typedef struct {
   uint32 ID    : 29;
   uint32 THLEN :  1;
   uint32 RTR   :  1;
   uint32 IDE   :  1;
   uint32 TS    : 16;
   uint32 LBL   : 12;
   uint32 DLC   :  4;
   uint8  DB[8];
}McalCan_FrameType;

typedef uint8 McalCan_RtnType;

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
extern FUNC(void, MCALCAN_CODE) McalCan_ClearRxFiFoInterruptFlag   (void);
extern FUNC(void, MCALCAN_CODE) McalCan_ClearTxBufferInterruptFlag (void);
extern FUNC(void, MCALCAN_CODE) McalCan_MainFunction_BusOff        (void);

extern FUNC(McalCan_RtnType, MCALCAN_CODE) McalCan_ReadRxFiFo            (      McalCan_FrameType* pFrame);
extern FUNC(void,            MCALCAN_CODE) McalCan_ForwardMessageToCanIf (const McalCan_FrameType* tCanFrame);

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

