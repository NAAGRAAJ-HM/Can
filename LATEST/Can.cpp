/******************************************************************************/
/* File   : Can.cpp                                                           */
/* Author : NAGARAJA HM (c) since 1982. All rights reserved.                  */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "module.h"
#include "infCan_Version.h"
#include "infCan_EcuM.h"
#include "infCan_Dcm.h"
#include "infCan_SchM.h"

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* TYPEDEFS                                                                   */
/******************************************************************************/
class module_Can:
      public abstract_module
{
   public:
      FUNC(void, CAN_CODE) InitFunction        (void);
      FUNC(void, CAN_CODE) DeInitFunction      (void);
      FUNC(void, CAN_CODE) GetVersionInfo      (void);
      FUNC(void, CAN_CODE) MainFunction        (void);
      FUNC(void, CAN_CODE) MainFunction_Write  (void);
      FUNC(void, CAN_CODE) MainFunction_Read   (void);
      FUNC(void, CAN_CODE) MainFunction_BusOff (void);
      FUNC(void, CAN_CODE) MainFunction_Wakeup (void);
      FUNC(void, CAN_CODE) MainFunction_Mode   (void);
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
VAR(module_Can, CAN_VAR) Can;
CONSTP2VAR(infEcuMClient, CAN_VAR, CAN_CONST) gptrinfEcuMClient_Can = &Can;
CONSTP2VAR(infDcmClient,  CAN_VAR, CAN_CONST) gptrinfDcmClient_Can  = &Can;
CONSTP2VAR(infSchMClient, CAN_VAR, CAN_CONST) gptrinfSchMClient_Can = &Can;

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
FUNC(void, CAN_CODE) module_Can::InitFunction(void){
   Can.IsInitDone = E_OK;
}

FUNC(void, CAN_CODE) module_Can::DeInitFunction(void){
   Can.IsInitDone = E_NOT_OK;
}

FUNC(void, CAN_CODE) module_Can::GetVersionInfo(void){
}

FUNC(void, CAN_CODE) module_Can::MainFunction(void){
}

FUNC(void, CAN_CODE) module_Can::MainFunction_Write(void){
}

FUNC(void, CAN_CODE) module_Can::MainFunction_Read(void){
}

FUNC(void, CAN_CODE) module_Can::MainFunction_BusOff(void){
}

FUNC(void, CAN_CODE) module_Can::MainFunction_Wakeup(void){
}

FUNC(void, CAN_CODE) module_Can::MainFunction_Mode(void){
}

#include "Can_Unused.h"

FUNC(void, CAN_CODE) class_Can_Unused::SetBaudRate(void){
}

FUNC(void, CAN_CODE) class_Can_Unused::SetControllerMode(void){
}

FUNC(void, CAN_CODE) class_Can_Unused::DisableControllerInterrupts(void){
}

FUNC(void, CAN_CODE) class_Can_Unused::EnableControllerInterrupts(void){
}

FUNC(void, CAN_CODE) class_Can_Unused::CheckWakeUp(void){
}

FUNC(void, CAN_CODE) class_Can_Unused::GetControllerErrorState(void){
}

FUNC(void, CAN_CODE) class_Can_Unused::GetControllerMode(void){
}

FUNC(void, CAN_CODE) class_Can_Unused::Write(void){
}

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

