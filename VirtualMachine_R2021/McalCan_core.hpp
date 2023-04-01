#pragma once
/******************************************************************************/
/* File   : McalCan_core.hpp                                                      */
/*                                                                            */
/* Author : Nagaraja HULIYAPURADA MATA                                        */
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
/* All rights reserved. Copyright © 1982 Nagaraja HULIYAPURADA MATA           */
/*                                                                            */
/* Always refer latest software version from:                                 */
/* https://github.com/NagarajaHuliyapuradaMata?tab=repositories               */
/*                                                                            */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "CompilerCfg_McalCan.hpp"

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/
#define CAN_CORE_FUNCTIONALITIES                                               \
              FUNC(void, CAN_CODE) SetBaudRate                 (void);         \
              FUNC(void, CAN_CODE) SetControllerMode           (void);         \
              FUNC(void, CAN_CODE) DisableControllerInterrupts (void);         \
              FUNC(void, CAN_CODE) EnableControllerInterrupts  (void);         \
              FUNC(void, CAN_CODE) CheckWakeUp                 (void);         \
              FUNC(void, CAN_CODE) GetControllerErrorState     (void);         \
              FUNC(void, CAN_CODE) GetControllerMode           (void);         \
              FUNC(void, CAN_CODE) Write                       (void);         \

#define CAN_CORE_FUNCTIONALITIES_VIRTUAL                                       \
      virtual FUNC(void, CAN_CODE) SetBaudRate                 (void) = 0;     \
      virtual FUNC(void, CAN_CODE) SetControllerMode           (void) = 0;     \
      virtual FUNC(void, CAN_CODE) DisableControllerInterrupts (void) = 0;     \
      virtual FUNC(void, CAN_CODE) EnableControllerInterrupts  (void) = 0;     \
      virtual FUNC(void, CAN_CODE) CheckWakeUp                 (void) = 0;     \
      virtual FUNC(void, CAN_CODE) GetControllerErrorState     (void) = 0;     \
      virtual FUNC(void, CAN_CODE) GetControllerMode           (void) = 0;     \
      virtual FUNC(void, CAN_CODE) Write                       (void) = 0;     \

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* TYPEDEFS                                                                   */
/******************************************************************************/
class class_McalCan_Functionality{
   public:
      CAN_CORE_FUNCTIONALITIES_VIRTUAL
};

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

