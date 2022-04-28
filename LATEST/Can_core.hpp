#pragma once
/******************************************************************************/
/* File   : Can_core.hpp                                                      */
/* Author : NAGARAJA HM (c) since 1982. All rights reserved.                  */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "CompilerCfg_Can.hpp"

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/
#define CAN_COREFUNCTIONALITIES                                                \
              FUNC(void, CAN_CODE) SetBaudRate                 (void);         \
              FUNC(void, CAN_CODE) SetControllerMode           (void);         \
              FUNC(void, CAN_CODE) DisableControllerInterrupts (void);         \
              FUNC(void, CAN_CODE) EnableControllerInterrupts  (void);         \
              FUNC(void, CAN_CODE) CheckWakeUp                 (void);         \
              FUNC(void, CAN_CODE) GetControllerErrorState     (void);         \
              FUNC(void, CAN_CODE) GetControllerMode           (void);         \
              FUNC(void, CAN_CODE) Write                       (void);         \

#define CAN_COREFUNCTIONALITIES_VIRTUAL                                        \
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
class class_Can_Functionality{
   public:
      CAN_COREFUNCTIONALITIES_VIRTUAL
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

