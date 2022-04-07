/******************************************************************************/
/* File   : Can.cpp                                                           */
/* Author : NAGARAJA HM (c) since 1982. All rights reserved.                  */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "Module.hpp"
#include "infCan_EcuM.hpp"
#include "infCan_Dcm.hpp"
#include "infCan_SchM.hpp"

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
class module_Can:
      public abstract_module
{
   public:
      module_Can(Std_TypeVersionInfo lVersionInfo) : abstract_module(lVersionInfo){
      }
      FUNC(void, CAN_CODE) InitFunction(
         CONSTP2CONST(CfgModule_TypeAbstract, CAN_CONFIG_DATA, CAN_APPL_CONST) lptrCfgModule
      );
      FUNC(void, CAN_CODE) DeInitFunction      (void);
      FUNC(void, CAN_CODE) MainFunction        (void);

      FUNC(void, CAN_CODE) MainFunction_Write  (void);
      FUNC(void, CAN_CODE) MainFunction_Read   (void);
      FUNC(void, CAN_CODE) MainFunction_BusOff (void);
      FUNC(void, CAN_CODE) MainFunction_Wakeup (void);
      FUNC(void, CAN_CODE) MainFunction_Mode   (void);
};

extern VAR(module_Can, CAN_VAR) Can;

/******************************************************************************/
/* CONSTS                                                                     */
/******************************************************************************/
CONSTP2VAR(infEcuMClient, CAN_VAR, CAN_CONST) gptrinfEcuMClient_Can = &Can;
CONSTP2VAR(infDcmClient,  CAN_VAR, CAN_CONST) gptrinfDcmClient_Can  = &Can;
CONSTP2VAR(infSchMClient, CAN_VAR, CAN_CONST) gptrinfSchMClient_Can = &Can;

/******************************************************************************/
/* PARAMS                                                                     */
/******************************************************************************/
#include "CfgCan.hpp"

/******************************************************************************/
/* OBJECTS                                                                    */
/******************************************************************************/
VAR(module_Can, CAN_VAR) Can(
   {
         CAN_AR_RELEASE_VERSION_MAJOR
      ,  CAN_AR_RELEASE_VERSION_MINOR
      ,  0x00
      ,  0xFF
      ,  0x01
      ,  '0'
      ,  '1'
      ,  '0'
   }
);

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
FUNC(void, CAN_CODE) module_Can::InitFunction(
   CONSTP2CONST(CfgModule_TypeAbstract, CAN_CONFIG_DATA, CAN_APPL_CONST) lptrCfgModule
){
#if(STD_ON == Can_InitCheck)
   if(E_OK == IsInitDone){
#if(STD_ON == Can_DevErrorDetect)
      Det_ReportError(
      );
#endif
   }
   else{
#endif
      if(NULL_PTR == lptrCfgModule){
#if(STD_ON == Can_DevErrorDetect)
         Det_ReportError(
         );
#endif
      }
      else{
         if(STD_LOW){
// check lptrCfgModule for memory faults
            lptrCfg = lptrCfgModule;
         }
         else{
// use PBcfg_CanIf as back-up configuration
            lptrCfg = PBcfg_CanIf;
         }
      }
      IsInitDone = E_OK;
#if(STD_ON == Can_InitCheck)
   }
#endif
}

FUNC(void, CAN_CODE) module_Can::DeInitFunction(void){
#if(STD_ON == Can_InitCheck)
   if(E_OK != IsInitDone){
#if(STD_ON == Can_DevErrorDetect)
      Det_ReportError(
      );
#endif
   }
   else{
#endif
      IsInitDone = E_NOT_OK;
#if(STD_ON == Can_InitCheck)
   }
#endif
}

FUNC(void, CAN_CODE) module_Can::MainFunction(void){
#if(STD_ON == Can_InitCheck)
   if(E_OK != IsInitDone){
#if(STD_ON == Can_DevErrorDetect)
      Det_ReportError(
      );
#endif
   }
   else{
#endif
#if(STD_ON == Can_InitCheck)
   }
#endif
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

class class_Can_Unused{
   public:
      FUNC(void, CAN_CODE) SetBaudRate                 (void);
      FUNC(void, CAN_CODE) SetControllerMode           (void);
      FUNC(void, CAN_CODE) DisableControllerInterrupts (void);
      FUNC(void, CAN_CODE) EnableControllerInterrupts  (void);
      FUNC(void, CAN_CODE) CheckWakeUp                 (void);
      FUNC(void, CAN_CODE) GetControllerErrorState     (void);
      FUNC(void, CAN_CODE) GetControllerMode           (void);
      FUNC(void, CAN_CODE) Write                       (void);
};

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

