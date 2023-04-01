/******************************************************************************/
/* File   : McalCan.cpp                                                           */
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
#include "Module.hpp"
#include "McalCan.hpp"
#include "infMcalCan_Imp.hpp"

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
VAR(module_McalCan, CAN_VAR) McalCan;

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
FUNC(void, CAN_CODE) module_McalCan::InitFunction(
      CONSTP2CONST(ConstModule_TypeAbstract, CAN_CONST,       CAN_APPL_CONST) lptrConstModule
   ,  CONSTP2CONST(CfgModule_TypeAbstract,   CAN_CONFIG_DATA, CAN_APPL_CONST) lptrCfgModule
){
#if(STD_ON == McalCan_InitCheck)
   if(
         E_OK
      != IsInitDone
   ){
#endif
      if(
            (NULL_PTR != lptrConstModule)
         && (NULL_PTR != lptrCfgModule)
      ){
         lptrConst = (const ConstMcalCan_Type*)lptrConstModule;
         lptrCfg   = lptrCfgModule;
      }
      else{
#if(STD_ON == McalCan_DevErrorDetect)
         ServiceDet_ReportError(
               0 //TBD: IdModule
            ,  0 //TBD: IdInstance
            ,  0 //TBD: IdApi
            ,  0 //TBD: IdError
         );
#endif
      }
#if(STD_ON == McalCan_InitCheck)
      IsInitDone = E_OK;
   }
   else{
#if(STD_ON == McalCan_DevErrorDetect)
      ServiceDet_ReportError(
            0 //TBD: IdModule
         ,  0 //TBD: IdInstance
         ,  0 //TBD: IdApi
         ,  CAN_E_UNINIT
      );
#endif
   }
#endif
}

FUNC(void, CAN_CODE) module_McalCan::DeInitFunction(
   void
){
#if(STD_ON == McalCan_InitCheck)
   if(
         E_OK
      == IsInitDone
   ){
#endif
#if(STD_ON == McalCan_InitCheck)
      IsInitDone = E_NOT_OK;
   }
   else{
#if(STD_ON == McalCan_DevErrorDetect)
      ServiceDet_ReportError(
            0 //TBD: IdModule
         ,  0 //TBD: IdInstance
         ,  0 //TBD: IdApi
         ,  CAN_E_UNINIT
      );
#endif
   }
#endif
}

FUNC(void, CAN_CODE) module_McalCan::MainFunction(
   void
){
#if(STD_ON == McalCan_InitCheck)
   if(
         E_OK
      == IsInitDone
   ){
#endif
#if(STD_ON == McalCan_InitCheck)
   }
   else{
#if(STD_ON == McalCan_DevErrorDetect)
      ServiceDet_ReportError(
            0 //TBD: IdModule
         ,  0 //TBD: IdInstance
         ,  0 //TBD: IdApi
         ,  CAN_E_UNINIT
      );
#endif
   }
#endif
}

FUNC(void, CAN_CODE) module_McalCan::MainFunction_Write(
   void
){
}

FUNC(void, CAN_CODE) module_McalCan::MainFunction_Read(
   void
){
}

FUNC(void, CAN_CODE) module_McalCan::MainFunction_BusOff(
   void
){
}

FUNC(void, CAN_CODE) module_McalCan::MainFunction_Wakeup(
   void
){
}

FUNC(void, CAN_CODE) module_McalCan::MainFunction_Mode(
   void
){
}

FUNC(void, CAN_CODE) module_McalCan::SetBaudRate(
   void
){
}

FUNC(void, CAN_CODE) module_McalCan::SetControllerMode(
   void
){
}

FUNC(void, CAN_CODE) module_McalCan::DisableControllerInterrupts(
   void
){
}

FUNC(void, CAN_CODE) module_McalCan::EnableControllerInterrupts(
   void
){
}

FUNC(void, CAN_CODE) module_McalCan::CheckWakeUp(
   void
){
}

FUNC(void, CAN_CODE) module_McalCan::GetControllerErrorState(
   void
){
}

FUNC(void, CAN_CODE) module_McalCan::GetControllerMode(
   void
){
}

FUNC(void, CAN_CODE) module_McalCan::Write(
   void
){
}

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

