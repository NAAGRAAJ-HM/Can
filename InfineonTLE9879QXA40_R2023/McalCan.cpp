/******************************************************************************/
/* File   : McalCan.cpp                                                       */
/* Author : Nagaraja HULIYAPURADA-MATA                                        */
/* Date   : 01.02.1982                                                        */
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

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/

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
VAR(module_McalCan, MCALCAN_VAR) McalCan;

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
FUNC(void, MCALCAN_CODE) module_McalCan::InitFunction(
      CONSTP2CONST(ConstModule_TypeAbstract, MCALCAN_CONST,       MCALCAN_APPL_CONST) lptrNvMBlocksRomModule
   ,  CONSTP2CONST(CfgModule_TypeAbstract,   MCALCAN_CONFIG_DATA, MCALCAN_APPL_CONST) lptrCfgModule
){
#if(STD_ON == McalCan_InitCheck)
   if(
         E_OK
      != IsInitDone
   ){
#endif
      if(
            (NULL_PTR != lptrNvMBlocksRomModule)
         && (NULL_PTR != lptrCfgModule)
      ){
         lptrNvMBlocksRom = lptrNvMBlocksRomModule;
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
         ,  MCALCAN_E_UNINIT
      );
#endif
   }
#endif
}

FUNC(void, MCALCAN_CODE) module_McalCan::DeInitFunction(
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
         ,  MCALCAN_E_UNINIT
      );
#endif
   }
#endif
}

FUNC(void, MCALCAN_CODE) module_McalCan::MainFunction(
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
         ,  MCALCAN_E_UNINIT
      );
#endif
   }
#endif
}

FUNC(void, MCALCAN_CODE) module_McalCan::MainFunction_Write(
   void
){
}

FUNC(void, MCALCAN_CODE) module_McalCan::MainFunction_Read(
   void
){
}

FUNC(void, MCALCAN_CODE) module_McalCan::MainFunction_BusOff(
   void
){
}

FUNC(void, MCALCAN_CODE) module_McalCan::MainFunction_Wakeup(
   void
){
}

FUNC(void, MCALCAN_CODE) module_McalCan::MainFunction_Mode(
   void
){
}

FUNC(void, MCALCAN_CODE) module_McalCan::SetBaudRate(
   void
){
}

FUNC(void, MCALCAN_CODE) module_McalCan::SetControllerMode(
   void
){
}

FUNC(void, MCALCAN_CODE) module_McalCan::DisableControllerInterrupts(
   void
){
}

FUNC(void, MCALCAN_CODE) module_McalCan::EnableControllerInterrupts(
   void
){
}

FUNC(void, MCALCAN_CODE) module_McalCan::CheckWakeUp(
   void
){
}

FUNC(void, MCALCAN_CODE) module_McalCan::GetControllerErrorState(
   void
){
}

FUNC(void, MCALCAN_CODE) module_McalCan::GetControllerMode(
   void
){
}

FUNC(void, MCALCAN_CODE) module_McalCan::Write(
   void
){
}

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

