/*****************************************************/
/* File   : Can.cpp                                  */
/* Author : Naagraaj HM                              */
/*****************************************************/

/*****************************************************/
/* #INCLUDES                                         */
/*****************************************************/
#include "module.h"
#include "Can_EcuM.h"
#include "Can_SchM.h"
#include "Can_Unused.h"

/*****************************************************/
/* #DEFINES                                          */
/*****************************************************/

/*****************************************************/
/* MACROS                                            */
/*****************************************************/

/*****************************************************/
/* TYPEDEFS                                          */
/*****************************************************/
class module_Can:
      public abstract_module
{
   public:
      FUNC(void, CAN_CODE) InitFunction        (void);
      FUNC(void, CAN_CODE) DeInitFunction      (void);
      FUNC(void, CAN_CODE) MainFunction        (void);
      FUNC(void, CAN_CODE) MainFunction_Write  (void);
      FUNC(void, CAN_CODE) MainFunction_Read   (void);
      FUNC(void, CAN_CODE) MainFunction_BusOff (void);
      FUNC(void, CAN_CODE) MainFunction_Wakeup (void);
      FUNC(void, CAN_CODE) MainFunction_Mode   (void);
};

/*****************************************************/
/* CONSTS                                            */
/*****************************************************/

/*****************************************************/
/* PARAMS                                            */
/*****************************************************/

/*****************************************************/
/* OBJECTS                                           */
/*****************************************************/
module_Can     Can;
infEcuMClient* gptrinfEcuMClient_Can = &Can;
infSchMClient* gptrinfSchMClient_Can = &Can;

/*****************************************************/
/* FUNCTIONS                                         */
/*****************************************************/
FUNC(void, CAN_CODE) module_Can::InitFunction(void){
}

FUNC(void, CAN_CODE) module_Can::DeInitFunction(void){
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

FUNC(void, CAN_CODE) class_Can_Unused::GetVersionInfo(void){
}

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

/*****************************************************/
/* EOF                                               */
/*****************************************************/

