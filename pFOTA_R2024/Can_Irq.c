

#define C_DRV_INTERNAL
#define CAN_IRQ_SOURCE

#include "McalCan.hpp"
#if defined(V_OSTYPE_OSEK)
# include "osek.hpp"
#endif

#if defined(V_OSTYPE_AUTOSAR)
# include "SwcServiceOs.hpp"
#endif

#if(CAN_COREVERSION           != 0x0800u)
# error "Header file are inconsistent!"
#endif
#if(CAN_RELEASE_COREVERSION   != 0x00u)
# error "Header file are inconsistent!"
#endif
#if(DRVCAN_SH2RSCANASR_VERSION         != 0x0606u)
# error "Source and header files are inconsistent!"
#endif
#if(DRVCAN_SH2RSCANASR_RELEASE_VERSION != 0x00u)
# error "Source and header files are inconsistent!"
#endif
#if(CAN_GEN_SH2RSCANASR_VERSION        != 0x0302u)
# error "Static code and generated data are inconsistent!"
#endif

#if defined(CAN_ENABLE_USE_INIT_ROOT_POINTER)
# define CAN_START_SEC_VAR_INIT_UNSPECIFIED
# include "MemMap.hpp"
V_DEF_P2CONST (extern, Can_ConfigType, VAR_INIT, CONST_PBCFG) Can_ConfigDataPtr;
# define CAN_STOP_SEC_VAR_INIT_UNSPECIFIED
# include "MemMap.hpp"
#endif

#define CAN_START_SEC_CODE
#include "MemMap.hpp"

# if(CAN_POSTBUILD_VARIANT_SUPPORT == STD_ON)
#  define CAN_USE_PHYSTOLOG_MAPPING
# endif

#if defined( kCanPhysToLogChannelIndex_0 )
# if defined(C_ENABLE_TX_POLLING) && !defined(C_ENABLE_INDIVIDUAL_POLLING)
# else
#  if defined(C_ENABLE_OSEK_OS) && defined(C_ENABLE_OSEK_OS_INTCAT2)
#   if defined(osdIsrCanIsrTx_0Cat)
#    if(osdIsrCanIsrTx_0Cat != 2u)
#     error "inconsistent configuration of Osek-OS interrupt category between CANgen/GENy and OIL-configurator (CanIsr)"
#    endif
#   endif
ISR( CanIsrTx_0 )
#  else
#   if defined(C_ENABLE_OSEK_OS)
#    if defined(osdIsrCanIsrTx_0Cat)
#     if(osdIsrCanIsrTx_0Cat != 1u)
#      error "inconsistent configuration of Osek-OS interrupt category between CANgen/GENy and OIL-configurator (CanIsr)"
#     endif
#    endif
#   endif
#   if !defined(C_ENABLE_ISRVOID)
#    if defined(C_COMP_GHS_RH850_RSCAN)
#     if defined(C_ENABLE_NESTED_INTERRUPTS)
#pragma ghs interrupt(enabled)
#     else
#pragma ghs interrupt
#     endif
#    endif
#   endif

V_DEF_FUNC(C_ISR_KEYWORD, void, CODE) CanIsrTx_0( void )
#  endif
{

#  if defined(C_MULTIPLE_RECEIVE_CHANNEL)
#    if defined(CAN_USE_PHYSTOLOG_MAPPING)
  CanInterruptTx(Can_GetPhysToLogChannel(0));
#    else
  CanInterruptTx(kCanPhysToLogChannelIndex_0);
#    endif
#  else
  CanInterruptTx();
#  endif
}
# endif
#endif

#if defined(C_ENABLE_LL_WAKEUP_SUPPORT)

#if defined( kCanPhysToLogChannelIndex_0 )
# if !defined(C_ENABLE_WAKEUP_POLLING) || defined(C_ENABLE_USE_OS_INTERRUPT_CONTROL)
#  if defined(C_ENABLE_OSEK_OS) && defined(C_ENABLE_OSEK_OS_INTCAT2)
#   if defined(osdIsrCanIsrWakeup_0Cat)
#    if(osdIsrCanIsrWakeup_0Cat != 2u)
#     error "inconsistent configuration of Osek-OS interrupt category between CANgen/GENy and OIL-configurator (CanIsr)"
#    endif
#   endif
ISR( CanIsrWakeup_0 )
#  else
#   if defined(C_ENABLE_OSEK_OS)
#    if defined(osdIsrCanIsrWakeup_0Cat)
#     if(osdIsrCanIsrWakeup_0Cat != 1u)
#      error "inconsistent configuration of Osek-OS interrupt category between CANgen/GENy and OIL-configurator (CanIsr)"
#     endif
#    endif
#   endif
#   if !defined(C_ENABLE_ISRVOID)
#    if defined(C_COMP_GHS_RH850_RSCAN)
#     if defined(C_ENABLE_NESTED_INTERRUPTS)
#pragma ghs interrupt(enabled)
#     else
#pragma ghs interrupt
#     endif
#    endif
#   endif

V_DEF_FUNC(C_ISR_KEYWORD, void, CODE) CanIsrWakeup_0( void )
#  endif
{

#  if !defined(C_ENABLE_WAKEUP_POLLING)

#   if defined(C_MULTIPLE_RECEIVE_CHANNEL)
#     if defined(CAN_USE_PHYSTOLOG_MAPPING)
  CanInterruptWakeup(Can_GetPhysToLogChannel(0));
#     else
  CanInterruptWakeup(kCanPhysToLogChannelIndex_0);
#     endif
#   else
  CanInterruptWakeup();
#   endif
#  endif
}
# endif
#endif

#endif

#if defined( kCanPhysToLogChannelIndex_0 )
# if defined(C_ENABLE_ERROR_POLLING)
# else
#  if defined(C_ENABLE_OSEK_OS) && defined(C_ENABLE_OSEK_OS_INTCAT2)
#   if defined(osdIsrCanIsrStatus_0Cat)
#    if(osdIsrCanIsrStatus_0Cat != 2u)
#     error "inconsistent configuration of Osek-OS interrupt category between CANgen/GENy and OIL-configurator (CanIsr)"
#    endif
#   endif
ISR( CanIsrStatus_0 )
#  else
#   if defined(C_ENABLE_OSEK_OS)
#    if defined(osdIsrCanIsrStatus_0Cat)
#     if(osdIsrCanIsrStatus_0Cat != 1u)
#      error "inconsistent configuration of Osek-OS interrupt category between CANgen/GENy and OIL-configurator (CanIsr)"
#     endif
#    endif
#   endif
#   if !defined(C_ENABLE_ISRVOID)
#    if defined(C_COMP_GHS_RH850_RSCAN)
#     if defined(C_ENABLE_NESTED_INTERRUPTS)
#pragma ghs interrupt(enabled)
#     else
#pragma ghs interrupt
#     endif
#    endif
#   endif

V_DEF_FUNC(C_ISR_KEYWORD, void, CODE) CanIsrStatus_0( void )
#  endif
{

#  if defined(C_MULTIPLE_RECEIVE_CHANNEL)
#    if defined(CAN_USE_PHYSTOLOG_MAPPING)
  CanInterruptStatus(Can_GetPhysToLogChannel(0));
#    else
  CanInterruptStatus(kCanPhysToLogChannelIndex_0);
#    endif
#  else
  CanInterruptStatus();
#  endif
}
# endif
#endif

#if defined( kCanPhysToLogChannelIndex_1 )
# if defined(C_ENABLE_TX_POLLING) && !defined(C_ENABLE_INDIVIDUAL_POLLING)
# else
#  if defined(C_ENABLE_OSEK_OS) && defined(C_ENABLE_OSEK_OS_INTCAT2)
#   if defined(osdIsrCanIsrTx_1Cat)
#    if(osdIsrCanIsrTx_1Cat != 2u)
#     error "inconsistent configuration of Osek-OS interrupt category between CANgen/GENy and OIL-configurator (CanIsr)"
#    endif
#   endif
ISR( CanIsrTx_1 )
#  else
#   if defined(C_ENABLE_OSEK_OS)
#    if defined(osdIsrCanIsrTx_1Cat)
#     if(osdIsrCanIsrTx_1Cat != 1u)
#      error "inconsistent configuration of Osek-OS interrupt category between CANgen/GENy and OIL-configurator (CanIsr)"
#     endif
#    endif
#   endif
#   if !defined(C_ENABLE_ISRVOID)
#    if defined(C_COMP_GHS_RH850_RSCAN)
#     if defined(C_ENABLE_NESTED_INTERRUPTS)
#pragma ghs interrupt(enabled)
#     else
#pragma ghs interrupt
#     endif
#    endif
#   endif

V_DEF_FUNC(C_ISR_KEYWORD, void, CODE) CanIsrTx_1( void )
#  endif
{

#  if defined(C_MULTIPLE_RECEIVE_CHANNEL)
#    if defined(CAN_USE_PHYSTOLOG_MAPPING)
  CanInterruptTx(Can_GetPhysToLogChannel(1));
#    else
  CanInterruptTx(kCanPhysToLogChannelIndex_1);
#    endif
#  else
  CanInterruptTx();
#  endif
}
# endif
#endif

#if defined(C_ENABLE_LL_WAKEUP_SUPPORT)

#if defined( kCanPhysToLogChannelIndex_1 )
# if !defined(C_ENABLE_WAKEUP_POLLING) || defined(C_ENABLE_USE_OS_INTERRUPT_CONTROL)
#  if defined(C_ENABLE_OSEK_OS) && defined(C_ENABLE_OSEK_OS_INTCAT2)
#   if defined(osdIsrCanIsrWakeup_1Cat)
#    if(osdIsrCanIsrWakeup_1Cat != 2u)
#     error "inconsistent configuration of Osek-OS interrupt category between CANgen/GENy and OIL-configurator (CanIsr)"
#    endif
#   endif
ISR( CanIsrWakeup_1 )
#  else
#   if defined(C_ENABLE_OSEK_OS)
#    if defined(osdIsrCanIsrWakeup_1Cat)
#     if(osdIsrCanIsrWakeup_1Cat != 1u)
#      error "inconsistent configuration of Osek-OS interrupt category between CANgen/GENy and OIL-configurator (CanIsr)"
#     endif
#    endif
#   endif
#   if !defined(C_ENABLE_ISRVOID)
#    if defined(C_COMP_GHS_RH850_RSCAN)
#     if defined(C_ENABLE_NESTED_INTERRUPTS)
#pragma ghs interrupt(enabled)
#     else
#pragma ghs interrupt
#     endif
#    endif
#   endif

V_DEF_FUNC(C_ISR_KEYWORD, void, CODE) CanIsrWakeup_1( void )
#  endif
{

#  if !defined(C_ENABLE_WAKEUP_POLLING)

#   if defined(C_MULTIPLE_RECEIVE_CHANNEL)
#     if defined(CAN_USE_PHYSTOLOG_MAPPING)
  CanInterruptWakeup(Can_GetPhysToLogChannel(1));
#     else
  CanInterruptWakeup(kCanPhysToLogChannelIndex_1);
#     endif
#   else
  CanInterruptWakeup();
#   endif
#  endif
}
# endif
#endif

#endif

#if defined( kCanPhysToLogChannelIndex_1 )
# if defined(C_ENABLE_ERROR_POLLING)
# else
#  if defined(C_ENABLE_OSEK_OS) && defined(C_ENABLE_OSEK_OS_INTCAT2)
#   if defined(osdIsrCanIsrStatus_1Cat)
#    if(osdIsrCanIsrStatus_1Cat != 2u)
#     error "inconsistent configuration of Osek-OS interrupt category between CANgen/GENy and OIL-configurator (CanIsr)"
#    endif
#   endif
ISR( CanIsrStatus_1 )
#  else
#   if defined(C_ENABLE_OSEK_OS)
#    if defined(osdIsrCanIsrStatus_1Cat)
#     if(osdIsrCanIsrStatus_1Cat != 1u)
#      error "inconsistent configuration of Osek-OS interrupt category between CANgen/GENy and OIL-configurator (CanIsr)"
#     endif
#    endif
#   endif
#   if !defined(C_ENABLE_ISRVOID)
#    if defined(C_COMP_GHS_RH850_RSCAN)
#     if defined(C_ENABLE_NESTED_INTERRUPTS)
#pragma ghs interrupt(enabled)
#     else
#pragma ghs interrupt
#     endif
#    endif
#   endif

V_DEF_FUNC(C_ISR_KEYWORD, void, CODE) CanIsrStatus_1( void )
#  endif
{

#  if defined(C_MULTIPLE_RECEIVE_CHANNEL)
#    if defined(CAN_USE_PHYSTOLOG_MAPPING)
  CanInterruptStatus(Can_GetPhysToLogChannel(1));
#    else
  CanInterruptStatus(kCanPhysToLogChannelIndex_1);
#    endif
#  else
  CanInterruptStatus();
#  endif
}
# endif
#endif

#if defined( kCanPhysToLogChannelIndex_2 )
# if defined(C_ENABLE_TX_POLLING) && !defined(C_ENABLE_INDIVIDUAL_POLLING)
# else
#  if defined(C_ENABLE_OSEK_OS) && defined(C_ENABLE_OSEK_OS_INTCAT2)
#   if defined(osdIsrCanIsrTx_2Cat)
#    if(osdIsrCanIsrTx_2Cat != 2u)
#     error "inconsistent configuration of Osek-OS interrupt category between CANgen/GENy and OIL-configurator (CanIsr)"
#    endif
#   endif
ISR( CanIsrTx_2 )
#  else
#   if defined(C_ENABLE_OSEK_OS)
#    if defined(osdIsrCanIsrTx_2Cat)
#     if(osdIsrCanIsrTx_2Cat != 1u)
#      error "inconsistent configuration of Osek-OS interrupt category between CANgen/GENy and OIL-configurator (CanIsr)"
#     endif
#    endif
#   endif
#   if !defined(C_ENABLE_ISRVOID)
#    if defined(C_COMP_GHS_RH850_RSCAN)
#     if defined(C_ENABLE_NESTED_INTERRUPTS)
#pragma ghs interrupt(enabled)
#     else
#pragma ghs interrupt
#     endif
#    endif
#   endif

V_DEF_FUNC(C_ISR_KEYWORD, void, CODE) CanIsrTx_2( void )
#  endif
{

#  if defined(C_MULTIPLE_RECEIVE_CHANNEL)
#    if defined(CAN_USE_PHYSTOLOG_MAPPING)
  CanInterruptTx(Can_GetPhysToLogChannel(2));
#    else
  CanInterruptTx(kCanPhysToLogChannelIndex_2);
#    endif
#  else
  CanInterruptTx();
#  endif
}
# endif
#endif

#if defined(C_ENABLE_LL_WAKEUP_SUPPORT)

#if defined( kCanPhysToLogChannelIndex_2 )
# if !defined(C_ENABLE_WAKEUP_POLLING) || defined(C_ENABLE_USE_OS_INTERRUPT_CONTROL)
#  if defined(C_ENABLE_OSEK_OS) && defined(C_ENABLE_OSEK_OS_INTCAT2)
#   if defined(osdIsrCanIsrWakeup_2Cat)
#    if(osdIsrCanIsrWakeup_2Cat != 2u)
#     error "inconsistent configuration of Osek-OS interrupt category between CANgen/GENy and OIL-configurator (CanIsr)"
#    endif
#   endif
ISR( CanIsrWakeup_2 )
#  else
#   if defined(C_ENABLE_OSEK_OS)
#    if defined(osdIsrCanIsrWakeup_2Cat)
#     if(osdIsrCanIsrWakeup_2Cat != 1u)
#      error "inconsistent configuration of Osek-OS interrupt category between CANgen/GENy and OIL-configurator (CanIsr)"
#     endif
#    endif
#   endif
#   if !defined(C_ENABLE_ISRVOID)
#    if defined(C_COMP_GHS_RH850_RSCAN)
#     if defined(C_ENABLE_NESTED_INTERRUPTS)
#pragma ghs interrupt(enabled)
#     else
#pragma ghs interrupt
#     endif
#    endif
#   endif

V_DEF_FUNC(C_ISR_KEYWORD, void, CODE) CanIsrWakeup_2( void )
#  endif
{

#  if !defined(C_ENABLE_WAKEUP_POLLING)

#   if defined(C_MULTIPLE_RECEIVE_CHANNEL)
#     if defined(CAN_USE_PHYSTOLOG_MAPPING)
  CanInterruptWakeup(Can_GetPhysToLogChannel(2));
#     else
  CanInterruptWakeup(kCanPhysToLogChannelIndex_2);
#     endif
#   else
  CanInterruptWakeup();
#   endif
#  endif
}
# endif
#endif

#endif

#if defined( kCanPhysToLogChannelIndex_2 )
# if defined(C_ENABLE_ERROR_POLLING)
# else
#  if defined(C_ENABLE_OSEK_OS) && defined(C_ENABLE_OSEK_OS_INTCAT2)
#   if defined(osdIsrCanIsrStatus_2Cat)
#    if(osdIsrCanIsrStatus_2Cat != 2u)
#     error "inconsistent configuration of Osek-OS interrupt category between CANgen/GENy and OIL-configurator (CanIsr)"
#    endif
#   endif
ISR( CanIsrStatus_2 )
#  else
#   if defined(C_ENABLE_OSEK_OS)
#    if defined(osdIsrCanIsrStatus_2Cat)
#     if(osdIsrCanIsrStatus_2Cat != 1u)
#      error "inconsistent configuration of Osek-OS interrupt category between CANgen/GENy and OIL-configurator (CanIsr)"
#     endif
#    endif
#   endif
#   if !defined(C_ENABLE_ISRVOID)
#    if defined(C_COMP_GHS_RH850_RSCAN)
#     if defined(C_ENABLE_NESTED_INTERRUPTS)
#pragma ghs interrupt(enabled)
#     else
#pragma ghs interrupt
#     endif
#    endif
#   endif

V_DEF_FUNC(C_ISR_KEYWORD, void, CODE) CanIsrStatus_2( void )
#  endif
{

#  if defined(C_MULTIPLE_RECEIVE_CHANNEL)
#    if defined(CAN_USE_PHYSTOLOG_MAPPING)
  CanInterruptStatus(Can_GetPhysToLogChannel(2));
#    else
  CanInterruptStatus(kCanPhysToLogChannelIndex_2);
#    endif
#  else
  CanInterruptStatus();
#  endif
}
# endif
#endif

#if defined( kCanPhysToLogChannelIndex_3 )
# if defined(C_ENABLE_TX_POLLING) && !defined(C_ENABLE_INDIVIDUAL_POLLING)
# else
#  if defined(C_ENABLE_OSEK_OS) && defined(C_ENABLE_OSEK_OS_INTCAT2)
#   if defined(osdIsrCanIsrTx_3Cat)
#    if(osdIsrCanIsrTx_3Cat != 2u)
#     error "inconsistent configuration of Osek-OS interrupt category between CANgen/GENy and OIL-configurator (CanIsr)"
#    endif
#   endif
ISR( CanIsrTx_3 )
#  else
#   if defined(C_ENABLE_OSEK_OS)
#    if defined(osdIsrCanIsrTx_3Cat)
#     if(osdIsrCanIsrTx_3Cat != 1u)
#      error "inconsistent configuration of Osek-OS interrupt category between CANgen/GENy and OIL-configurator (CanIsr)"
#     endif
#    endif
#   endif
#   if !defined(C_ENABLE_ISRVOID)
#    if defined(C_COMP_GHS_RH850_RSCAN)
#     if defined(C_ENABLE_NESTED_INTERRUPTS)
#pragma ghs interrupt(enabled)
#     else
#pragma ghs interrupt
#     endif
#    endif
#   endif

V_DEF_FUNC(C_ISR_KEYWORD, void, CODE) CanIsrTx_3( void )
#  endif
{

#  if defined(C_MULTIPLE_RECEIVE_CHANNEL)
#    if defined(CAN_USE_PHYSTOLOG_MAPPING)
  CanInterruptTx(Can_GetPhysToLogChannel(3));
#    else
  CanInterruptTx(kCanPhysToLogChannelIndex_3);
#    endif
#  else
  CanInterruptTx();
#  endif
}
# endif
#endif

#if defined(C_ENABLE_LL_WAKEUP_SUPPORT)

#if defined( kCanPhysToLogChannelIndex_3 )
# if !defined(C_ENABLE_WAKEUP_POLLING) || defined(C_ENABLE_USE_OS_INTERRUPT_CONTROL)
#  if defined(C_ENABLE_OSEK_OS) && defined(C_ENABLE_OSEK_OS_INTCAT2)
#   if defined(osdIsrCanIsrWakeup_3Cat)
#    if(osdIsrCanIsrWakeup_3Cat != 2u)
#     error "inconsistent configuration of Osek-OS interrupt category between CANgen/GENy and OIL-configurator (CanIsr)"
#    endif
#   endif
ISR( CanIsrWakeup_3 )
#  else
#   if defined(C_ENABLE_OSEK_OS)
#    if defined(osdIsrCanIsrWakeup_3Cat)
#     if(osdIsrCanIsrWakeup_3Cat != 1u)
#      error "inconsistent configuration of Osek-OS interrupt category between CANgen/GENy and OIL-configurator (CanIsr)"
#     endif
#    endif
#   endif
#   if !defined(C_ENABLE_ISRVOID)
#    if defined(C_COMP_GHS_RH850_RSCAN)
#     if defined(C_ENABLE_NESTED_INTERRUPTS)
#pragma ghs interrupt(enabled)
#     else
#pragma ghs interrupt
#     endif
#    endif
#   endif

V_DEF_FUNC(C_ISR_KEYWORD, void, CODE) CanIsrWakeup_3( void )
#  endif
{

#  if !defined(C_ENABLE_WAKEUP_POLLING)

#   if defined(C_MULTIPLE_RECEIVE_CHANNEL)
#     if defined(CAN_USE_PHYSTOLOG_MAPPING)
  CanInterruptWakeup(Can_GetPhysToLogChannel(3));
#     else
  CanInterruptWakeup(kCanPhysToLogChannelIndex_3);
#     endif
#   else
  CanInterruptWakeup();
#   endif
#  endif
}
# endif
#endif

#endif

#if defined( kCanPhysToLogChannelIndex_3 )
# if defined(C_ENABLE_ERROR_POLLING)
# else
#  if defined(C_ENABLE_OSEK_OS) && defined(C_ENABLE_OSEK_OS_INTCAT2)
#   if defined(osdIsrCanIsrStatus_3Cat)
#    if(osdIsrCanIsrStatus_3Cat != 2u)
#     error "inconsistent configuration of Osek-OS interrupt category between CANgen/GENy and OIL-configurator (CanIsr)"
#    endif
#   endif
ISR( CanIsrStatus_3 )
#  else
#   if defined(C_ENABLE_OSEK_OS)
#    if defined(osdIsrCanIsrStatus_3Cat)
#     if(osdIsrCanIsrStatus_3Cat != 1u)
#      error "inconsistent configuration of Osek-OS interrupt category between CANgen/GENy and OIL-configurator (CanIsr)"
#     endif
#    endif
#   endif
#   if !defined(C_ENABLE_ISRVOID)
#    if defined(C_COMP_GHS_RH850_RSCAN)
#     if defined(C_ENABLE_NESTED_INTERRUPTS)
#pragma ghs interrupt(enabled)
#     else
#pragma ghs interrupt
#     endif
#    endif
#   endif

V_DEF_FUNC(C_ISR_KEYWORD, void, CODE) CanIsrStatus_3( void )
#  endif
{

#  if defined(C_MULTIPLE_RECEIVE_CHANNEL)
#    if defined(CAN_USE_PHYSTOLOG_MAPPING)
  CanInterruptStatus(Can_GetPhysToLogChannel(3));
#    else
  CanInterruptStatus(kCanPhysToLogChannelIndex_3);
#    endif
#  else
  CanInterruptStatus();
#  endif
}
# endif
#endif

#if defined( kCanPhysToLogChannelIndex_4 )
# if defined(C_ENABLE_TX_POLLING) && !defined(C_ENABLE_INDIVIDUAL_POLLING)
# else
#  if defined(C_ENABLE_OSEK_OS) && defined(C_ENABLE_OSEK_OS_INTCAT2)
#   if defined(osdIsrCanIsrTx_4Cat)
#    if(osdIsrCanIsrTx_4Cat != 2u)
#     error "inconsistent configuration of Osek-OS interrupt category between CANgen/GENy and OIL-configurator (CanIsr)"
#    endif
#   endif
ISR( CanIsrTx_4 )
#  else
#   if defined(C_ENABLE_OSEK_OS)
#    if defined(osdIsrCanIsrTx_4Cat)
#     if(osdIsrCanIsrTx_4Cat != 1u)
#      error "inconsistent configuration of Osek-OS interrupt category between CANgen/GENy and OIL-configurator (CanIsr)"
#     endif
#    endif
#   endif
#   if !defined(C_ENABLE_ISRVOID)
#    if defined(C_COMP_GHS_RH850_RSCAN)
#     if defined(C_ENABLE_NESTED_INTERRUPTS)
#pragma ghs interrupt(enabled)
#     else
#pragma ghs interrupt
#     endif
#    endif
#   endif

V_DEF_FUNC(C_ISR_KEYWORD, void, CODE) CanIsrTx_4( void )
#  endif
{

#  if defined(C_MULTIPLE_RECEIVE_CHANNEL)
#    if defined(CAN_USE_PHYSTOLOG_MAPPING)
  CanInterruptTx(Can_GetPhysToLogChannel(4));
#    else
  CanInterruptTx(kCanPhysToLogChannelIndex_4);
#    endif
#  else
  CanInterruptTx();
#  endif
}
# endif
#endif

#if defined(C_ENABLE_LL_WAKEUP_SUPPORT)

#if defined( kCanPhysToLogChannelIndex_4 )
# if !defined(C_ENABLE_WAKEUP_POLLING) || defined(C_ENABLE_USE_OS_INTERRUPT_CONTROL)
#  if defined(C_ENABLE_OSEK_OS) && defined(C_ENABLE_OSEK_OS_INTCAT2)
#   if defined(osdIsrCanIsrWakeup_4Cat)
#    if(osdIsrCanIsrWakeup_4Cat != 2u)
#     error "inconsistent configuration of Osek-OS interrupt category between CANgen/GENy and OIL-configurator (CanIsr)"
#    endif
#   endif
ISR( CanIsrWakeup_4 )
#  else
#   if defined(C_ENABLE_OSEK_OS)
#    if defined(osdIsrCanIsrWakeup_4Cat)
#     if(osdIsrCanIsrWakeup_4Cat != 1u)
#      error "inconsistent configuration of Osek-OS interrupt category between CANgen/GENy and OIL-configurator (CanIsr)"
#     endif
#    endif
#   endif
#   if !defined(C_ENABLE_ISRVOID)
#    if defined(C_COMP_GHS_RH850_RSCAN)
#     if defined(C_ENABLE_NESTED_INTERRUPTS)
#pragma ghs interrupt(enabled)
#     else
#pragma ghs interrupt
#     endif
#    endif
#   endif

V_DEF_FUNC(C_ISR_KEYWORD, void, CODE) CanIsrWakeup_4( void )
#  endif
{

#  if !defined(C_ENABLE_WAKEUP_POLLING)

#   if defined(C_MULTIPLE_RECEIVE_CHANNEL)
#     if defined(CAN_USE_PHYSTOLOG_MAPPING)
  CanInterruptWakeup(Can_GetPhysToLogChannel(4));
#     else
  CanInterruptWakeup(kCanPhysToLogChannelIndex_4);
#     endif
#   else
  CanInterruptWakeup();
#   endif
#  endif
}
# endif
#endif

#endif

#if defined( kCanPhysToLogChannelIndex_4 )
# if defined(C_ENABLE_ERROR_POLLING)
# else
#  if defined(C_ENABLE_OSEK_OS) && defined(C_ENABLE_OSEK_OS_INTCAT2)
#   if defined(osdIsrCanIsrStatus_4Cat)
#    if(osdIsrCanIsrStatus_4Cat != 2u)
#     error "inconsistent configuration of Osek-OS interrupt category between CANgen/GENy and OIL-configurator (CanIsr)"
#    endif
#   endif
ISR( CanIsrStatus_4 )
#  else
#   if defined(C_ENABLE_OSEK_OS)
#    if defined(osdIsrCanIsrStatus_4Cat)
#     if(osdIsrCanIsrStatus_4Cat != 1u)
#      error "inconsistent configuration of Osek-OS interrupt category between CANgen/GENy and OIL-configurator (CanIsr)"
#     endif
#    endif
#   endif
#   if !defined(C_ENABLE_ISRVOID)
#    if defined(C_COMP_GHS_RH850_RSCAN)
#     if defined(C_ENABLE_NESTED_INTERRUPTS)
#pragma ghs interrupt(enabled)
#     else
#pragma ghs interrupt
#     endif
#    endif
#   endif

V_DEF_FUNC(C_ISR_KEYWORD, void, CODE) CanIsrStatus_4( void )
#  endif
{

#  if defined(C_MULTIPLE_RECEIVE_CHANNEL)
#    if defined(CAN_USE_PHYSTOLOG_MAPPING)
  CanInterruptStatus(Can_GetPhysToLogChannel(4));
#    else
  CanInterruptStatus(kCanPhysToLogChannelIndex_4);
#    endif
#  else
  CanInterruptStatus();
#  endif
}
# endif
#endif

#if defined( kCanPhysToLogChannelIndex_5 )
# if defined(C_ENABLE_TX_POLLING) && !defined(C_ENABLE_INDIVIDUAL_POLLING)
# else
#  if defined(C_ENABLE_OSEK_OS) && defined(C_ENABLE_OSEK_OS_INTCAT2)
#   if defined(osdIsrCanIsrTx_5Cat)
#    if(osdIsrCanIsrTx_5Cat != 2u)
#     error "inconsistent configuration of Osek-OS interrupt category between CANgen/GENy and OIL-configurator (CanIsr)"
#    endif
#   endif
ISR( CanIsrTx_5 )
#  else
#   if defined(C_ENABLE_OSEK_OS)
#    if defined(osdIsrCanIsrTx_5Cat)
#     if(osdIsrCanIsrTx_5Cat != 1u)
#      error "inconsistent configuration of Osek-OS interrupt category between CANgen/GENy and OIL-configurator (CanIsr)"
#     endif
#    endif
#   endif
#   if !defined(C_ENABLE_ISRVOID)
#    if defined(C_COMP_GHS_RH850_RSCAN)
#     if defined(C_ENABLE_NESTED_INTERRUPTS)
#pragma ghs interrupt(enabled)
#     else
#pragma ghs interrupt
#     endif
#    endif
#   endif

V_DEF_FUNC(C_ISR_KEYWORD, void, CODE) CanIsrTx_5( void )
#  endif
{

#  if defined(C_MULTIPLE_RECEIVE_CHANNEL)
#    if defined(CAN_USE_PHYSTOLOG_MAPPING)
  CanInterruptTx(Can_GetPhysToLogChannel(5));
#    else
  CanInterruptTx(kCanPhysToLogChannelIndex_5);
#    endif
#  else
  CanInterruptTx();
#  endif
}
# endif
#endif

#if defined(C_ENABLE_LL_WAKEUP_SUPPORT)

#if defined( kCanPhysToLogChannelIndex_5 )
# if !defined(C_ENABLE_WAKEUP_POLLING) || defined(C_ENABLE_USE_OS_INTERRUPT_CONTROL)
#  if defined(C_ENABLE_OSEK_OS) && defined(C_ENABLE_OSEK_OS_INTCAT2)
#   if defined(osdIsrCanIsrWakeup_5Cat)
#    if(osdIsrCanIsrWakeup_5Cat != 2u)
#     error "inconsistent configuration of Osek-OS interrupt category between CANgen/GENy and OIL-configurator (CanIsr)"
#    endif
#   endif
ISR( CanIsrWakeup_5 )
#  else
#   if defined(C_ENABLE_OSEK_OS)
#    if defined(osdIsrCanIsrWakeup_5Cat)
#     if(osdIsrCanIsrWakeup_5Cat != 1u)
#      error "inconsistent configuration of Osek-OS interrupt category between CANgen/GENy and OIL-configurator (CanIsr)"
#     endif
#    endif
#   endif
#   if !defined(C_ENABLE_ISRVOID)
#    if defined(C_COMP_GHS_RH850_RSCAN)
#     if defined(C_ENABLE_NESTED_INTERRUPTS)
#pragma ghs interrupt(enabled)
#     else
#pragma ghs interrupt
#     endif
#    endif
#   endif

V_DEF_FUNC(C_ISR_KEYWORD, void, CODE) CanIsrWakeup_5( void )
#  endif
{

#  if !defined(C_ENABLE_WAKEUP_POLLING)

#   if defined(C_MULTIPLE_RECEIVE_CHANNEL)
#     if defined(CAN_USE_PHYSTOLOG_MAPPING)
  CanInterruptWakeup(Can_GetPhysToLogChannel(5));
#     else
  CanInterruptWakeup(kCanPhysToLogChannelIndex_5);
#     endif
#   else
  CanInterruptWakeup();
#   endif
#  endif
}
# endif
#endif

#endif

#if defined( kCanPhysToLogChannelIndex_5 )
# if defined(C_ENABLE_ERROR_POLLING)
# else
#  if defined(C_ENABLE_OSEK_OS) && defined(C_ENABLE_OSEK_OS_INTCAT2)
#   if defined(osdIsrCanIsrStatus_5Cat)
#    if(osdIsrCanIsrStatus_5Cat != 2u)
#     error "inconsistent configuration of Osek-OS interrupt category between CANgen/GENy and OIL-configurator (CanIsr)"
#    endif
#   endif
ISR( CanIsrStatus_5 )
#  else
#   if defined(C_ENABLE_OSEK_OS)
#    if defined(osdIsrCanIsrStatus_5Cat)
#     if(osdIsrCanIsrStatus_5Cat != 1u)
#      error "inconsistent configuration of Osek-OS interrupt category between CANgen/GENy and OIL-configurator (CanIsr)"
#     endif
#    endif
#   endif
#   if !defined(C_ENABLE_ISRVOID)
#    if defined(C_COMP_GHS_RH850_RSCAN)
#     if defined(C_ENABLE_NESTED_INTERRUPTS)
#pragma ghs interrupt(enabled)
#     else
#pragma ghs interrupt
#     endif
#    endif
#   endif

V_DEF_FUNC(C_ISR_KEYWORD, void, CODE) CanIsrStatus_5( void )
#  endif
{

#  if defined(C_MULTIPLE_RECEIVE_CHANNEL)
#    if defined(CAN_USE_PHYSTOLOG_MAPPING)
  CanInterruptStatus(Can_GetPhysToLogChannel(5));
#    else
  CanInterruptStatus(kCanPhysToLogChannelIndex_5);
#    endif
#  else
  CanInterruptStatus();
#  endif
}
# endif
#endif

#if defined( kCanPhysToLogChannelIndex_6 )
# if defined(C_ENABLE_TX_POLLING) && !defined(C_ENABLE_INDIVIDUAL_POLLING)
# else
#  if defined(C_ENABLE_OSEK_OS) && defined(C_ENABLE_OSEK_OS_INTCAT2)
#   if defined(osdIsrCanIsrTx_6Cat)
#    if(osdIsrCanIsrTx_6Cat != 2u)
#     error "inconsistent configuration of Osek-OS interrupt category between CANgen/GENy and OIL-configurator (CanIsr)"
#    endif
#   endif
ISR( CanIsrTx_6 )
#  else
#   if defined(C_ENABLE_OSEK_OS)
#    if defined(osdIsrCanIsrTx_6Cat)
#     if(osdIsrCanIsrTx_6Cat != 1u)
#      error "inconsistent configuration of Osek-OS interrupt category between CANgen/GENy and OIL-configurator (CanIsr)"
#     endif
#    endif
#   endif
#   if !defined(C_ENABLE_ISRVOID)
#    if defined(C_COMP_GHS_RH850_RSCAN)
#     if defined(C_ENABLE_NESTED_INTERRUPTS)
#pragma ghs interrupt(enabled)
#     else
#pragma ghs interrupt
#     endif
#    endif
#   endif

V_DEF_FUNC(C_ISR_KEYWORD, void, CODE) CanIsrTx_6( void )
#  endif
{

#  if defined(C_MULTIPLE_RECEIVE_CHANNEL)
#    if defined(CAN_USE_PHYSTOLOG_MAPPING)
  CanInterruptTx(Can_GetPhysToLogChannel(6));
#    else
  CanInterruptTx(kCanPhysToLogChannelIndex_6);
#    endif
#  else
  CanInterruptTx();
#  endif
}
# endif
#endif

#if defined(C_ENABLE_LL_WAKEUP_SUPPORT)

#if defined( kCanPhysToLogChannelIndex_6 )
# if !defined(C_ENABLE_WAKEUP_POLLING) || defined(C_ENABLE_USE_OS_INTERRUPT_CONTROL)
#  if defined(C_ENABLE_OSEK_OS) && defined(C_ENABLE_OSEK_OS_INTCAT2)
#   if defined(osdIsrCanIsrWakeup_6Cat)
#    if(osdIsrCanIsrWakeup_6Cat != 2u)
#     error "inconsistent configuration of Osek-OS interrupt category between CANgen/GENy and OIL-configurator (CanIsr)"
#    endif
#   endif
ISR( CanIsrWakeup_6 )
#  else
#   if defined(C_ENABLE_OSEK_OS)
#    if defined(osdIsrCanIsrWakeup_6Cat)
#     if(osdIsrCanIsrWakeup_6Cat != 1u)
#      error "inconsistent configuration of Osek-OS interrupt category between CANgen/GENy and OIL-configurator (CanIsr)"
#     endif
#    endif
#   endif
#   if !defined(C_ENABLE_ISRVOID)
#    if defined(C_COMP_GHS_RH850_RSCAN)
#     if defined(C_ENABLE_NESTED_INTERRUPTS)
#pragma ghs interrupt(enabled)
#     else
#pragma ghs interrupt
#     endif
#    endif
#   endif

V_DEF_FUNC(C_ISR_KEYWORD, void, CODE) CanIsrWakeup_6( void )
#  endif
{

#  if !defined(C_ENABLE_WAKEUP_POLLING)

#   if defined(C_MULTIPLE_RECEIVE_CHANNEL)
#     if defined(CAN_USE_PHYSTOLOG_MAPPING)
  CanInterruptWakeup(Can_GetPhysToLogChannel(6));
#     else
  CanInterruptWakeup(kCanPhysToLogChannelIndex_6);
#     endif
#   else
  CanInterruptWakeup();
#   endif
#  endif
}
# endif
#endif

#endif

#if defined( kCanPhysToLogChannelIndex_6 )
# if defined(C_ENABLE_ERROR_POLLING)
# else
#  if defined(C_ENABLE_OSEK_OS) && defined(C_ENABLE_OSEK_OS_INTCAT2)
#   if defined(osdIsrCanIsrStatus_6Cat)
#    if(osdIsrCanIsrStatus_6Cat != 2u)
#     error "inconsistent configuration of Osek-OS interrupt category between CANgen/GENy and OIL-configurator (CanIsr)"
#    endif
#   endif
ISR( CanIsrStatus_6 )
#  else
#   if defined(C_ENABLE_OSEK_OS)
#    if defined(osdIsrCanIsrStatus_6Cat)
#     if(osdIsrCanIsrStatus_6Cat != 1u)
#      error "inconsistent configuration of Osek-OS interrupt category between CANgen/GENy and OIL-configurator (CanIsr)"
#     endif
#    endif
#   endif
#   if !defined(C_ENABLE_ISRVOID)
#    if defined(C_COMP_GHS_RH850_RSCAN)
#     if defined(C_ENABLE_NESTED_INTERRUPTS)
#pragma ghs interrupt(enabled)
#     else
#pragma ghs interrupt
#     endif
#    endif
#   endif

V_DEF_FUNC(C_ISR_KEYWORD, void, CODE) CanIsrStatus_6( void )
#  endif
{

#  if defined(C_MULTIPLE_RECEIVE_CHANNEL)
#    if defined(CAN_USE_PHYSTOLOG_MAPPING)
  CanInterruptStatus(Can_GetPhysToLogChannel(6));
#    else
  CanInterruptStatus(kCanPhysToLogChannelIndex_6);
#    endif
#  else
  CanInterruptStatus();
#  endif
}
# endif
#endif

#if defined( kCanPhysToLogChannelIndex_7 )
# if defined(C_ENABLE_TX_POLLING) && !defined(C_ENABLE_INDIVIDUAL_POLLING)
# else
#  if defined(C_ENABLE_OSEK_OS) && defined(C_ENABLE_OSEK_OS_INTCAT2)
#   if defined(osdIsrCanIsrTx_7Cat)
#    if(osdIsrCanIsrTx_7Cat != 2u)
#     error "inconsistent configuration of Osek-OS interrupt category between CANgen/GENy and OIL-configurator (CanIsr)"
#    endif
#   endif
ISR( CanIsrTx_7 )
#  else
#   if defined(C_ENABLE_OSEK_OS)
#    if defined(osdIsrCanIsrTx_7Cat)
#     if(osdIsrCanIsrTx_7Cat != 1u)
#      error "inconsistent configuration of Osek-OS interrupt category between CANgen/GENy and OIL-configurator (CanIsr)"
#     endif
#    endif
#   endif
#   if !defined(C_ENABLE_ISRVOID)
#    if defined(C_COMP_GHS_RH850_RSCAN)
#     if defined(C_ENABLE_NESTED_INTERRUPTS)
#pragma ghs interrupt(enabled)
#     else
#pragma ghs interrupt
#     endif
#    endif
#   endif

V_DEF_FUNC(C_ISR_KEYWORD, void, CODE) CanIsrTx_7( void )
#  endif
{

#  if defined(C_MULTIPLE_RECEIVE_CHANNEL)
#    if defined(CAN_USE_PHYSTOLOG_MAPPING)
  CanInterruptTx(Can_GetPhysToLogChannel(7));
#    else
  CanInterruptTx(kCanPhysToLogChannelIndex_7);
#    endif
#  else
  CanInterruptTx();
#  endif
}
# endif
#endif

#if defined(C_ENABLE_LL_WAKEUP_SUPPORT)

#if defined( kCanPhysToLogChannelIndex_7 )
# if !defined(C_ENABLE_WAKEUP_POLLING) || defined(C_ENABLE_USE_OS_INTERRUPT_CONTROL)
#  if defined(C_ENABLE_OSEK_OS) && defined(C_ENABLE_OSEK_OS_INTCAT2)
#   if defined(osdIsrCanIsrWakeup_7Cat)
#    if(osdIsrCanIsrWakeup_7Cat != 2u)
#     error "inconsistent configuration of Osek-OS interrupt category between CANgen/GENy and OIL-configurator (CanIsr)"
#    endif
#   endif
ISR( CanIsrWakeup_7 )
#  else
#   if defined(C_ENABLE_OSEK_OS)
#    if defined(osdIsrCanIsrWakeup_7Cat)
#     if(osdIsrCanIsrWakeup_7Cat != 1u)
#      error "inconsistent configuration of Osek-OS interrupt category between CANgen/GENy and OIL-configurator (CanIsr)"
#     endif
#    endif
#   endif
#   if !defined(C_ENABLE_ISRVOID)
#    if defined(C_COMP_GHS_RH850_RSCAN)
#     if defined(C_ENABLE_NESTED_INTERRUPTS)
#pragma ghs interrupt(enabled)
#     else
#pragma ghs interrupt
#     endif
#    endif
#   endif

V_DEF_FUNC(C_ISR_KEYWORD, void, CODE) CanIsrWakeup_7( void )
#  endif
{

#  if !defined(C_ENABLE_WAKEUP_POLLING)

#   if defined(C_MULTIPLE_RECEIVE_CHANNEL)
#     if defined(CAN_USE_PHYSTOLOG_MAPPING)
  CanInterruptWakeup(Can_GetPhysToLogChannel(7));
#     else
  CanInterruptWakeup(kCanPhysToLogChannelIndex_7);
#     endif
#   else
  CanInterruptWakeup();
#   endif
#  endif
}
# endif
#endif

#endif

#if defined( kCanPhysToLogChannelIndex_7 )
# if defined(C_ENABLE_ERROR_POLLING)
# else
#  if defined(C_ENABLE_OSEK_OS) && defined(C_ENABLE_OSEK_OS_INTCAT2)
#   if defined(osdIsrCanIsrStatus_7Cat)
#    if(osdIsrCanIsrStatus_7Cat != 2u)
#     error "inconsistent configuration of Osek-OS interrupt category between CANgen/GENy and OIL-configurator (CanIsr)"
#    endif
#   endif
ISR( CanIsrStatus_7 )
#  else
#   if defined(C_ENABLE_OSEK_OS)
#    if defined(osdIsrCanIsrStatus_7Cat)
#     if(osdIsrCanIsrStatus_7Cat != 1u)
#      error "inconsistent configuration of Osek-OS interrupt category between CANgen/GENy and OIL-configurator (CanIsr)"
#     endif
#    endif
#   endif
#   if !defined(C_ENABLE_ISRVOID)
#    if defined(C_COMP_GHS_RH850_RSCAN)
#     if defined(C_ENABLE_NESTED_INTERRUPTS)
#pragma ghs interrupt(enabled)
#     else
#pragma ghs interrupt
#     endif
#    endif
#   endif

V_DEF_FUNC(C_ISR_KEYWORD, void, CODE) CanIsrStatus_7( void )
#  endif
{

#  if defined(C_MULTIPLE_RECEIVE_CHANNEL)
#    if defined(CAN_USE_PHYSTOLOG_MAPPING)
  CanInterruptStatus(Can_GetPhysToLogChannel(7));
#    else
  CanInterruptStatus(kCanPhysToLogChannelIndex_7);
#    endif
#  else
  CanInterruptStatus();
#  endif
}
# endif
#endif

#if(defined(C_ENABLE_RX_BASICCAN_OBJECTS) && defined(C_ENABLE_OVERRUN))

# if defined(C_ENABLE_ERROR_POLLING)
# else
#  if defined(C_ENABLE_OSEK_OS) && defined(C_ENABLE_OSEK_OS_INTCAT2)
#   if defined(osdIsrCanIsrGlobalStatusCat)
#    if(osdIsrCanIsrGlobalStatusCat != 2u)
#     error "inconsistent configuration of Osek-OS interrupt category between CANgen/GENy and OIL-configurator (CanIsr)"
#    endif
#   endif
ISR( CanIsrGlobalStatus )
#  else
#   if defined(C_ENABLE_OSEK_OS)
#    if defined(osdIsrCanIsrGlobalStatusCat)
#     if(osdIsrCanIsrGlobalStatusCat != 1u)
#      error "inconsistent configuration of Osek-OS interrupt category between CANgen/GENy and OIL-configurator (CanIsr)"
#     endif
#    endif
#   endif
#   if !defined(C_ENABLE_ISRVOID)
#    if defined(C_COMP_GHS_RH850_RSCAN)
#     if defined(C_ENABLE_NESTED_INTERRUPTS)
#pragma ghs interrupt(enabled)
#     else
#pragma ghs interrupt
#     endif
#    endif
#   endif

V_DEF_FUNC(C_ISR_KEYWORD, void, CODE) CanIsrGlobalStatus( void )
#  endif
{

  CanInterruptGlobalStatus();
}
# endif

#endif

#if defined(C_ENABLE_RX_BASICCAN_OBJECTS)
# if defined(C_ENABLE_RX_BASICCAN_POLLING) && !defined(C_ENABLE_INDIVIDUAL_POLLING)
# else

#  if defined(C_ENABLE_OSEK_OS) && defined(C_ENABLE_OSEK_OS_INTCAT2)
#   if defined(osdIsrCanIsrRxFifoCat)
#    if(osdIsrCanIsrRxFifoCat != 2u)
#     error "inconsistent configuration of Osek-OS interrupt category between CANgen/GENy and OIL-configurator (CanIsr)"
#    endif
#   endif
ISR( CanIsrRxFifo )
#  else
#   if defined(C_ENABLE_OSEK_OS)
#    if defined(osdIsrCanIsrRxFifoCat)
#     if(osdIsrCanIsrRxFifoCat != 1u)
#      error "inconsistent configuration of Osek-OS interrupt category between CANgen/GENy and OIL-configurator (CanIsr)"
#     endif
#    endif
#   endif
#   if !defined(C_ENABLE_ISRVOID)
#    if defined(C_COMP_GHS_RH850_RSCAN)
#     if defined(C_ENABLE_NESTED_INTERRUPTS)
#pragma ghs interrupt(enabled)
#     else
#pragma ghs interrupt
#     endif
#    endif
#   endif

V_DEF_FUNC(C_ISR_KEYWORD, void, CODE) CanIsrRxFifo( void )
#  endif
{

  CanInterruptRxFifo();
}

# endif
#endif

#define CAN_STOP_SEC_CODE
#include "MemMap.hpp"

