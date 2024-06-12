#pragma once
/******************************************************************************/
/* File   : McalCan_core.hpp                                                      */
/* Author : Nagaraja HULIYAPURADA-MATA                                        */
/* Date   : 01.02.1982                                                        */
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

