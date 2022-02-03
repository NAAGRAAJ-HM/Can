/*****************************************************/
/* File   : Can.cpp                                  */
/* Author : Naagraaj HM                              */
/*****************************************************/

/*****************************************************/
/* #INCLUDES                                         */
/*****************************************************/
#include "Can.h"

#include "Can_EcuM.h"

/*****************************************************/
/* #DEFINES                                          */
/*****************************************************/

/*****************************************************/
/* MACROS                                            */
/*****************************************************/

/*****************************************************/
/* TYPEDEFS                                          */
/*****************************************************/

/*****************************************************/
/* CONSTS                                            */
/*****************************************************/

/*****************************************************/
/* PARAMS                                            */
/*****************************************************/

/*****************************************************/
/* OBJECTS                                           */
/*****************************************************/
class_Can_EcuM Can_EcuM;
class_EcuM_Client *EcuM_Client_ptr_Can = &Can_EcuM;
class_Can Can;

/*****************************************************/
/* FUNCTIONS                                         */
/*****************************************************/
FUNC(void, CAN_CODE) class_Can_EcuM::InitFunction(void){
}

FUNC(void, CAN_CODE) class_Can_EcuM::DeInitFunction(void){
}

FUNC(void, CAN_CODE) class_Can::GetVersionInfo(void){
}

FUNC(void, CAN_CODE) class_Can::SetBaudRate(void){
}

FUNC(void, CAN_CODE) class_Can::SetControllerMode(void){
}

FUNC(void, CAN_CODE) class_Can::DisableControllerInterrupts(void){
}

FUNC(void, CAN_CODE) class_Can::EnableControllerInterrupts(void){
}

FUNC(void, CAN_CODE) class_Can::CheckWakeUp(void){
}

FUNC(void, CAN_CODE) class_Can::GetControllerErrorState(void){
}

FUNC(void, CAN_CODE) class_Can::GetControllerMode(void){
}

FUNC(void, CAN_CODE) class_Can::Write(void){
}

FUNC(void, CAN_CODE) class_Can::MainFunction_Write(void){
}

FUNC(void, CAN_CODE) class_Can::MainFunction_Read(void){
}

FUNC(void, CAN_CODE) class_Can::MainFunction_BusOff(void){
}

FUNC(void, CAN_CODE) class_Can::MainFunction_Wakeup(void){
}

FUNC(void, CAN_CODE) class_Can::MainFunction_Mode(void){
}

/*****************************************************/
/* EOF                                               */
/*****************************************************/

