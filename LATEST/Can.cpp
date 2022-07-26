/******************************************************************************/
/* File   : Can.cpp                                                           */
/* Author : NAGARAJA HM (c) since 1982. All rights reserved.                  */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "Module.hpp"
#include "Can.hpp"
#include "infCan_Imp.hpp"

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/
#define CAN_AR_RELEASE_VERSION_MAJOR                                           4
#define CAN_AR_RELEASE_VERSION_MINOR                                           3

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/
#if(CAN_AR_RELEASE_VERSION_MAJOR != STD_AR_RELEASE_VERSION_MAJOR)
   #error "Incompatible CAN_AR_RELEASE_VERSION_MAJOR!"
#endif

#if(CAN_AR_RELEASE_VERSION_MINOR != STD_AR_RELEASE_VERSION_MINOR)
   #error "Incompatible CAN_AR_RELEASE_VERSION_MINOR!"
#endif

/******************************************************************************/
/* TYPEDEFS                                                                   */
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
VAR(module_Can, CAN_VAR) Can;

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
FUNC(void, CAN_CODE) module_Can::InitFunction(
      CONSTP2CONST(ConstModule_TypeAbstract, CAN_CONST,       CAN_APPL_CONST) lptrConstModule
   ,  CONSTP2CONST(CfgModule_TypeAbstract,   CAN_CONFIG_DATA, CAN_APPL_CONST) lptrCfgModule
){
#if(STD_ON == Can_InitCheck)
   if(
         E_OK
      != IsInitDone
   ){
#endif
      if(
            (NULL_PTR != lptrConstModule)
         && (NULL_PTR != lptrCfgModule)
      ){
         lptrConst = (const ConstCan_Type*)lptrConstModule;
         lptrCfg   = lptrCfgModule;
      }
      else{
#if(STD_ON == Can_DevErrorDetect)
         Det_ReportError(
               0 //TBD: IdModule
            ,  0 //TBD: IdInstance
            ,  0 //TBD: IdApi
            ,  0 //TBD: IdError
         );
#endif
      }
#if(STD_ON == Can_InitCheck)
      IsInitDone = E_OK;
   }
   else{
#if(STD_ON == Can_DevErrorDetect)
      Det_ReportError(
            0 //TBD: IdModule
         ,  0 //TBD: IdInstance
         ,  0 //TBD: IdApi
         ,  CAN_E_UNINIT
      );
#endif
   }
#endif
}

FUNC(void, CAN_CODE) module_Can::DeInitFunction(
   void
){
#if(STD_ON == Can_InitCheck)
   if(
         E_OK
      == IsInitDone
   ){
#endif
#if(STD_ON == Can_InitCheck)
      IsInitDone = E_NOT_OK;
   }
   else{
#if(STD_ON == Can_DevErrorDetect)
      Det_ReportError(
            0 //TBD: IdModule
         ,  0 //TBD: IdInstance
         ,  0 //TBD: IdApi
         ,  CAN_E_UNINIT
      );
#endif
   }
#endif
}

FUNC(void, CAN_CODE) module_Can::MainFunction(
   void
){
#if(STD_ON == Can_InitCheck)
   if(
         E_OK
      == IsInitDone
   ){
#endif
#if(STD_ON == Can_InitCheck)
   }
   else{
#if(STD_ON == Can_DevErrorDetect)
      Det_ReportError(
            0 //TBD: IdModule
         ,  0 //TBD: IdInstance
         ,  0 //TBD: IdApi
         ,  CAN_E_UNINIT
      );
#endif
   }
#endif
}

FUNC(void, CAN_CODE) module_Can::MainFunction_Write(
   void
){
}

FUNC(void, CAN_CODE) module_Can::MainFunction_Read(
   void
){
}

FUNC(void, CAN_CODE) module_Can::MainFunction_BusOff(
   void
){
}

FUNC(void, CAN_CODE) module_Can::MainFunction_Wakeup(
   void
){
}

FUNC(void, CAN_CODE) module_Can::MainFunction_Mode(
   void
){
}

FUNC(void, CAN_CODE) module_Can::SetBaudRate(
   void
){
}

FUNC(void, CAN_CODE) module_Can::SetControllerMode(
   void
){
}

FUNC(void, CAN_CODE) module_Can::DisableControllerInterrupts(
   void
){
}

FUNC(void, CAN_CODE) module_Can::EnableControllerInterrupts(
   void
){
}

FUNC(void, CAN_CODE) module_Can::CheckWakeUp(
   void
){
}

FUNC(void, CAN_CODE) module_Can::GetControllerErrorState(
   void
){
}

FUNC(void, CAN_CODE) module_Can::GetControllerMode(
   void
){
}

FUNC(void, CAN_CODE) module_Can::Write(
   void
){
}

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

