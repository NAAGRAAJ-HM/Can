#pragma once
/******************************************************************************/
/* File   : McalCan.hpp                                                       */
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
#include "infMcalCan_ServiceNvM_Types.hpp"
#include "CfgMcalCan.hpp"
#include "McalCan_core.hpp"
#include "infMcalCan_Exp.hpp"

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* TYPEDEFS                                                                   */
/******************************************************************************/
class module_McalCan:
      INTERFACES_EXPORTED_MCALCAN
      public abstract_module
   ,  public class_McalCan_Functionality
{
   private:
/******************************************************************************/
/* OBJECTS                                                                    */
/******************************************************************************/
      const ConstModule_TypeAbstract* lptrNvMBlocksRom = (ConstModule_TypeAbstract*)NULL_PTR;

   public:
/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
      FUNC(void, MCALCAN_CODE) InitFunction(
            CONSTP2CONST(ConstModule_TypeAbstract, MCALCAN_CONST,       MCALCAN_APPL_CONST) lptrNvMBlocksRomModule
         ,  CONSTP2CONST(CfgModule_TypeAbstract,   MCALCAN_CONFIG_DATA, MCALCAN_APPL_CONST) lptrCfgModule
      );
      FUNC(void, MCALCAN_CODE) DeInitFunction      (void);
      FUNC(void, MCALCAN_CODE) MainFunction        (void);
      MCALCAN_CORE_FUNCTIONALITIES

      FUNC(void, MCALCAN_CODE) MainFunction_Write  (void);
      FUNC(void, MCALCAN_CODE) MainFunction_Read   (void);
      FUNC(void, MCALCAN_CODE) MainFunction_BusOff (void);
      FUNC(void, MCALCAN_CODE) MainFunction_Wakeup (void);
      FUNC(void, MCALCAN_CODE) MainFunction_Mode   (void);
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
extern VAR(module_McalCan, MCALCAN_VAR) McalCan;

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

