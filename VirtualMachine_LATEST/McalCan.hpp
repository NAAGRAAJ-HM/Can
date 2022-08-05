#pragma once
/******************************************************************************/
/* File   : McalCan.hpp                                                           */
/* Author : NAGARAJA HM (c) since 1982. All rights reserved.                  */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "ConstMcalCan.hpp"
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
      INTERFACES_EXPORTED_CAN
      public abstract_module
   ,  public class_McalCan_Functionality
{
   private:
/******************************************************************************/
/* OBJECTS                                                                    */
/******************************************************************************/
      const ConstMcalCan_Type* lptrConst = (ConstMcalCan_Type*)NULL_PTR;

   public:
/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
      FUNC(void, CAN_CODE) InitFunction(
            CONSTP2CONST(ConstModule_TypeAbstract, CAN_CONST,       CAN_APPL_CONST) lptrConstModule
         ,  CONSTP2CONST(CfgModule_TypeAbstract,   CAN_CONFIG_DATA, CAN_APPL_CONST) lptrCfgModule
      );
      FUNC(void, CAN_CODE) DeInitFunction      (void);
      FUNC(void, CAN_CODE) MainFunction        (void);
      CAN_CORE_FUNCTIONALITIES

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
extern VAR(module_McalCan, CAN_VAR) McalCan;

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

