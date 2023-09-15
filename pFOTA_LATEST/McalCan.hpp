#if !defined(CAN_API_H)
#define CAN_API_H
#ifdef __cplusplus
extern "C"
{
#endif

#include "CfgMcalCan.hpp"

#if(CAN_MIRROR_MODE == STD_ON)
#include "CDDMirror.hpp"
#define C_ENABLE_MIRROR_MODE
#endif

#define DRVCAN_SH2RSCANASR_VERSION              0x0606u
#define DRVCAN_SH2RSCANASR_RELEASE_VERSION      0x00u
#define CAN_COREVERSION           0x0800u
#define CAN_RELEASE_COREVERSION   0x00u
#define CAN_AR_RELEASE_MAJOR_VERSION      4u
#define CAN_AR_RELEASE_MINOR_VERSION      0u
#define CAN_AR_RELEASE_REVISION_VERSION   3u
#define CAN_SW_MAJOR_VERSION   ((DRVCAN_SH2RSCANASR_VERSION & 0xFF00u) >> 8)
#define CAN_SW_MINOR_VERSION   (DRVCAN_SH2RSCANASR_VERSION & 0x00FFu)
#define CAN_SW_PATCH_VERSION   (DRVCAN_SH2RSCANASR_RELEASE_VERSION & 0xFFu)
#define CAN_VENDOR_ID   30u
#define CAN_MODULE_ID   80u
#define CAN_INIT_ID            0x00u
#define CAN_INITCTR_ID         0x02u
#define CAN_SETCTR_ID          0x03u
#define CAN_DIINT_ID           0x04u
#define CAN_ENINT_ID           0x05u
#define CAN_WRITE_ID           0x06u
#define CAN_VERSION_ID         0x07u
#define CAN_MAINFCT_WRITE_ID   0x01u
#define CAN_MAINFCT_READ_ID    0x08u
#define CAN_MAINFCT_BO_ID      0x09u
#define CAN_MAINFCT_WU_ID      0x0Au
#define CAN_MAINFCT_MODE_ID    0x0Cu
#define CAN_CKWAKEUP_ID        0x0Bu
#define CAN_CHANGE_BR_ID       0x0Du
#define CAN_CHECK_BR_ID        0x0Eu
#define CAN_SET_BR_ID          0x0Fu
#define CAN_GETCTR_STATE_ID    0x11u
#define CAN_GETCTR_MODE_ID     0x12u
#define CAN_GETCTR_RXCNT_ID    0x30u
#define CAN_GETCTR_TXCNT_ID    0x31u
#define CAN_RXINDI_ID          0x50u
#define CAN_TXCNF_ID           0x51u
#define CAN_CTRWAKEUP_ID       0x52u
#define CAN_CTRBUSOFF_ID       0x53u
#define CAN_HW_ACCESS_ID       0x60u
#define CAN_E_NO_ERROR              (uint8)0x00u
#define CAN_E_PARAM_POINTER         (uint8)0x01u
#define CAN_E_PARAM_HANDLE          (uint8)0x02u
#define CAN_E_PARAM_DLC             (uint8)0x03u
#define CAN_E_PARAM_CONTROLLER      (uint8)0x04u
#define CAN_E_UNINIT                (uint8)0x05u
#define CAN_E_TRANSITION            (uint8)0x06u
#define CAN_E_DATALOST              (uint8)0x07u
#define CAN_E_PARAM_BAUDRATE        (uint8)0x08u
#define CAN_E_RXQUEUE               (uint8)0x10u
#define CAN_E_TIMEOUT_DET           (uint8)0x11u
#define CAN_E_GENDATA               (uint8)0x12u
#define CAN_STATUS_UNINIT           ((uint8)0x00u)
#define CAN_STATUS_START            ((uint8)0x01u)
#define CAN_STATUS_STOP             ((uint8)0x02u)
#define CAN_STATUS_INIT             ((uint8)0x04u)
#define CAN_STATUS_INCONSISTENT     ((uint8)0x08u)
#define CAN_STATUS_WARNING          ((uint8)0x10u)
#define CAN_STATUS_PASSIVE          ((uint8)0x20u)
#define CAN_STATUS_BUSOFF           ((uint8)0x40u)
#define CAN_STATUS_SLEEP            ((uint8)0x80u)
#define CAN_STATUS_MASK_NOMODE      ((uint8)0x0Cu)

#if defined(C_DRV_INTERNAL)
#define kCanModeSleep                 ((uint8)0x01u)
#define kCanModeStopReinitFast        ((uint8)0x03u)
#define kCanModeStopReinit            ((uint8)0x04u)
#define kCanModeStart                 ((uint8)0x05u)
#define kCanModeStartReinit           ((uint8)0x06u)
#define kCanModeWakeupStopReinit      ((uint8)0x07u)
#define kCanModeSilent                ((uint8)0x08u)
#define kCanModeResetBusOffStart      ((uint8)0x09u)
#define kCanModeResetBusOffEnd        ((uint8)0x0Au)
#define kCanModeNone                  ((uint8)0x10u)
#define kCanContinueBusOffRecovery    ((uint8)0x00u)
#define kCanFinishBusOffRecovery      ((uint8)0x01u)
#define kCanExecuteRamCheck           kCanTrue
#define kCanSuppressRamCheck          kCanFalse
#endif

#define CAN_HW_IS_OK(state)                     (((state) & (CAN_STATUS_WARNING |  \
                                                          CAN_STATUS_PASSIVE |  \
                                                          CAN_STATUS_BUSOFF) )    == 0u)
#define CAN_HW_IS_WARNING(state)                (((state) & CAN_STATUS_WARNING)      != (uint8)0u)
#define CAN_HW_IS_PASSIVE(state)                (((state) & CAN_STATUS_PASSIVE)      != (uint8)0u)
#define CAN_HW_IS_BUSOFF(state)                 (((state) & CAN_STATUS_BUSOFF)       != (uint8)0u)
#define CAN_HW_IS_WAKEUP(state)                 (((state) & CAN_STATUS_SLEEP)        == (uint8)0u)
#define CAN_HW_IS_SLEEP(state)                  (((state) & CAN_STATUS_SLEEP)        != (uint8)0u)
#define CAN_HW_IS_STOP(state)                   (((state) & CAN_STATUS_STOP)         != (uint8)0u)
#define CAN_HW_IS_START(state)                  (((state) & CAN_STATUS_START)        != (uint8)0u)
#define CAN_HW_IS_INCONSISTENT(state)           (((state) & CAN_STATUS_INCONSISTENT) != (uint8)0u)

#define kCanLoopMode CAN_LOOP_MAX
#define kCanHwIsInit CAN_STATUS_INIT
#define kCanHwIsSleep CAN_STATUS_SLEEP
#define CAN_DEACTIVATE_CONTROLLER               CAN_STATUS_INCONSISTENT
#define CAN_ACTIVATE_CONTROLLER                 ((uint8)0x00u)

#define C_ENABLE_STOP
#if defined(V_OSTYPE_OSEK) || defined(V_OSTYPE_AUTOSAR)
#define C_ENABLE_OSEK_OS
#endif
#if(CAN_TX_PROCESSING == CAN_POLLING)
#define C_ENABLE_TX_POLLING
#endif
#if(CAN_RX_PROCESSING == CAN_POLLING)
#define C_ENABLE_RX_BASICCAN_POLLING
#define C_ENABLE_RX_FULLCAN_POLLING
#define C_ENABLE_RX_POLLING
#endif
#if(CAN_BUSOFF_PROCESSING == CAN_POLLING)
#define C_ENABLE_ERROR_POLLING
#endif
#if(CAN_WAKEUP_PROCESSING == CAN_POLLING)
#define C_ENABLE_WAKEUP_POLLING
#endif
#if(CAN_INDIVIDUAL_PROCESSING == STD_ON)
#define C_ENABLE_INDIVIDUAL_POLLING
#endif
#if(CAN_MULTIPLE_BASICCAN == STD_ON)
#define C_ENABLE_MULTIPLE_BASICCAN
#endif
#if(CAN_MULTIPLE_BASICCAN_TX == STD_ON)
#define C_ENABLE_MULTIPLE_BASICCAN_TX
#endif
#if(CAN_TX_FULLCAN_OBJECTS == STD_ON)
#define C_ENABLE_TX_FULLCAN_OBJECTS
#endif
#if(CAN_RX_FULLCAN_OBJECTS == STD_ON)
#define C_ENABLE_RX_FULLCAN_OBJECTS
#endif
#if(CAN_RX_BASICCAN_OBJECTS == STD_ON)
#define C_ENABLE_RX_BASICCAN_OBJECTS
#endif
#if(CAN_HW_TRANSMIT_CANCELLATION == STD_ON)
#define C_ENABLE_CANCEL_IN_HW
#endif

#if defined(C_ENABLE_CANCEL_IN_HW)
#define C_ENABLE_CANCEL_TX_IN_HW
#endif
#if(CAN_CANCEL_SUPPORT_API == STD_ON)
#define C_ENABLE_CANCEL_SUPPORT_API
#endif
#if(CAN_HARDWARE_CANCELLATION == STD_ON)
#define C_ENABLE_HW_LOOP_TIMER
#endif
#if(CAN_EXTENDED_ID == STD_ON)
#define C_ENABLE_EXTENDED_ID
#endif
#if(CAN_MIXED_ID == STD_ON)
#define C_ENABLE_MIXED_ID
#endif
#if(CAN_SLEEP_SUPPORT == STD_ON)
#if(CAN_WAKEUP_SUPPORT == STD_ON)

#define C_ENABLE_SLEEP_WAKEUP
#endif
#endif
#if(CAN_OVERRUN_NOTIFICATION == CAN_APPL)
#define C_ENABLE_OVERRUN
#define C_ENABLE_FULLCAN_OVERRUN
#endif
#if(CAN_OVERRUN_NOTIFICATION == CAN_DET)
#define C_ENABLE_OVERRUN
#define C_ENABLE_FULLCAN_OVERRUN
#if(CAN_DEV_ERROR_REPORT != STD_ON)
#error "CAN_OVERRUN_NOTIFICATION == CAN_DET need CAN_DEV_ERROR_REPORT == STD_ON"
#endif
#endif
#if(CAN_MULTIPLEXED_TRANSMISSION == STD_ON)
#define C_ENABLE_MULTIPLEXED_TRANSMISSION
#endif
#if(CAN_TX_HW_FIFO == STD_ON)
#define C_ENABLE_TX_HW_FIFO
#endif
#if(CAN_RX_QUEUE == STD_ON)
#define C_ENABLE_RX_QUEUE
#endif
#if(CAN_GENERIC_CONFIRMATION == STD_ON)
#define CAN_ENABLE_GENERIC_CONFIRMATION_API1
#endif
#if(CAN_GENERIC_CONFIRMATION == CAN_API2)
#define CAN_ENABLE_GENERIC_CONFIRMATION_API2
#endif
#if(CAN_GENERIC_PRETRANSMIT == STD_ON)
#define C_ENABLE_PRETRANSMIT_FCT
#endif
#if(CAN_ONE_CONTROLLER_OPTIMIZATION == STD_ON)
#define C_SINGLE_RECEIVE_CHANNEL
#define C_DISABLE_MULTICHANNEL_API
#define CAN_CHANNEL_CANTYPE_ONLY         void
#define CAN_CHANNEL_CANTYPE_FIRST
#define CAN_CHANNEL_CANTYPE_LOCAL
#define CAN_CHANNEL_CANPARA_ONLY
#define CAN_CHANNEL_CANPARA_FIRST
#define CAN_HW_CHANNEL_CANTYPE_ONLY      void
#define CAN_HW_CHANNEL_CANTYPE_FIRST
#define CAN_HW_CHANNEL_CANTYPE_LOCAL
#define CAN_HW_CHANNEL_CANPARA_ONLY
#define CAN_HW_CHANNEL_CANPARA_FIRST
#define CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_ONLY    void
#define CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST
#define CAN_CHANNEL_AND_HW_CHANNEL_CANPARA_ONLY
#define CAN_CHANNEL_AND_HW_CHANNEL_CANPARA_FIRST
#define CAN_CHANNEL_DUMMY_STATEMENT
#define CAN_HW_CHANNEL_DUMMY_STATEMENT
#define CAN_CHANNEL_AND_HW_CHANNEL_DUMMY_STATEMENT
#else
#define C_MULTIPLE_RECEIVE_CHANNEL
#define C_ENABLE_MULTICHANNEL_API
#define CAN_CHANNEL_CANTYPE_ONLY         CanChannelHandle  Controller
#define CAN_CHANNEL_CANTYPE_FIRST        CanChannelHandle  Controller,
#define CAN_CHANNEL_CANTYPE_LOCAL        CanChannelHandle  Controller;
#define CAN_CHANNEL_CANPARA_ONLY         (CanChannelHandle) Controller
#define CAN_CHANNEL_CANPARA_FIRST        (CanChannelHandle) Controller,
#define CAN_HW_CHANNEL_CANTYPE_ONLY      CanChannelHandle  Controller
#define CAN_HW_CHANNEL_CANTYPE_FIRST     CanChannelHandle  Controller,
#define CAN_HW_CHANNEL_CANTYPE_LOCAL     CanChannelHandle  Controller;
#define CAN_HW_CHANNEL_CANPARA_ONLY      (CanChannelHandle) Controller
#define CAN_HW_CHANNEL_CANPARA_FIRST     (CanChannelHandle) Controller,
#define CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_ONLY   CanChannelHandle Controller
#define CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST  CanChannelHandle Controller,
#define CAN_CHANNEL_AND_HW_CHANNEL_CANPARA_ONLY   Controller
#define CAN_CHANNEL_AND_HW_CHANNEL_CANPARA_FIRST  Controller,
#define CAN_CHANNEL_DUMMY_STATEMENT                 CAN_DUMMY_STATEMENT(Controller)
#define CAN_HW_CHANNEL_DUMMY_STATEMENT              CAN_DUMMY_STATEMENT(Controller)
#define CAN_CHANNEL_AND_HW_CHANNEL_DUMMY_STATEMENT  CAN_DUMMY_STATEMENT(Controller)
#endif
#if(CAN_GET_STATUS == STD_ON)
#define C_ENABLE_EXTENDED_STATUS
#endif
#if(CAN_RAM_CHECK == CAN_NOTIFY_ISSUE)
#define C_ENABLE_CAN_RAM_CHECK
#define C_ENABLE_CAN_RAM_CHECK_WAKEUP
#endif
#if(CAN_RAM_CHECK == CAN_NOTIFY_MAILBOX)
#define C_ENABLE_CAN_RAM_CHECK
#define C_ENABLE_CAN_RAM_CHECK_WAKEUP
#define C_ENABLE_NOTIFY_CORRUPT_MAILBOX
#endif
#if(CAN_RAM_CHECK == CAN_EXTENDED)
#define C_ENABLE_CAN_RAM_CHECK
#define C_ENABLE_CAN_RAM_CHECK_EXTENDED
#endif
#if(CAN_FD_SUPPORT != CAN_NONE)
#define C_ENABLE_CAN_FD_USED
#if(CAN_FD_SUPPORT == CAN_BRS)
#define C_ENABLE_CAN_FD_BRS
#endif
#if(CAN_FD_SUPPORT == CAN_FULL)
#define C_ENABLE_CAN_FD_FULL
#endif
#endif
#if(CAN_USE_INIT_POINTER == STD_ON)
#define CAN_ENABLE_USE_INIT_ROOT_POINTER
#endif
#if(CAN_USE_ECUM_BSW_ERROR_HOOK == STD_ON)
#define CAN_ENABLE_USE_ECUM_BSW_ERROR_HOOK
#endif
#if(CAN_USE_OS_INTERRUPT_CONTROL == STD_ON)
#define C_ENABLE_USE_OS_INTERRUPT_CONTROL
#endif
#if(CAN_SILENT_MODE == STD_ON)
#define C_ENABLE_SILENT_MODE
#endif
#if((CAN_INTLOCK == CAN_DRIVER) || (CAN_INTLOCK == CAN_BOTH))
#define C_ENABLE_CAN_CAN_INTERRUPT_CONTROL
#endif
#if( CAN_PROTECTED_MODE == STD_ON )
#define C_ENABLE_USER_MODE_OS
#endif
#if( CAN_FD_HW_BUFFER_OPTIMIZATION == STD_ON )
#define C_ENABLE_CAN_FD_HW_BUFFER_OPTIMIZATION
#endif
#if(CAN_CHECK_WAKEUP_CAN_RET_TYPE == STD_ON)
#define C_ENABLE_CHECK_WAKEUP_CAN_RET_TYPE
#endif

#if !defined(V_NULL)
#define V_NULL          NULL_PTR
#endif
#if !defined(V_NONE)
#define V_NONE
#define CAN_AUTOMATIC    AUTOMATIC
#define CAN_TYPEDEF      TYPEDEF
#endif
#if !defined(CAN_STATIC)
#if defined(STATIC)
#define CAN_STATIC  STATIC
#else
#define CAN_STATIC  static
#endif
#endif
#if !defined(CAN_LOCAL_INLINE)
#if defined(LOCAL_INLINE)
#define CAN_LOCAL_INLINE  LOCAL_INLINE
#else
#define CAN_LOCAL_INLINE
#endif
#endif

#define V_DEF_VAR(storage, vartype, memclass)                    storage VAR(vartype, CAN_##memclass)
#define V_DEF_VAR_FAR(storage, vartype)                          storage VAR(vartype, CAN_VAR_FAR)
#define V_DEF_VAR_NEAR(storage, vartype)                         storage VAR(vartype, CAN_VAR_NEAR)
#define V_DEF_VAR_TYPE(storage, vartype)                         typedef storage VAR(vartype, TYPEDEF)
#define V_DEF_P2VAR(storage, ptrtype, memclass, ptrclass)        storage P2VAR(ptrtype, CAN_##memclass, CAN_##ptrclass)
#define V_DEF_P2VAR_TYPE(storage, ptrtype, ptrclass)             typedef storage P2VAR(ptrtype, TYPEDEF, CAN_##ptrclass )
#define V_DEF_P2VAR_PARA(storage, ptrtype, memclass, ptrclass)   storage P2VAR(ptrtype, CAN_##memclass, CAN_##ptrclass)
#define V_DEF_P2SFR_CAN(storage, ptrtype, memclass)              storage P2VAR(ptrtype, CAN_##memclass, CAN_REG_CANCELL)
#define V_DEF_P2SFR_CAN_TYPE(storage, ptrtype)                   typedef storage P2VAR(ptrtype, TYPEDEF, CAN_REG_CANCELL)
#define V_DEF_CONSTP2VAR(storage, ptrtype, memclass, ptrclass)   storage CONSTP2VAR(ptrtype, CAN_##memclass, CAN_##ptrclass)
#define V_DEF_CONST(storage, type, memclass)                     storage CONST(type, CAN_##memclass)
#define V_DEF_CONST_TYPE(storage, type, memclass)                typedef storage CONST(type, TYPEDEF)
#define V_DEF_P2CONST(storage, ptrtype, memclass, ptrclass)      storage P2CONST(ptrtype, CAN_##memclass, CAN_##ptrclass)
#define V_DEF_P2CONST_TYPE(storage, ptrtype, ptrclass)           typedef storage P2CONST(ptrtype, TYPEDEF, CAN_##ptrclass)
#define V_DEF_P2CONST_PARA(storage, ptrtype, memclass, ptrclass) storage P2CONST(ptrtype, CAN_##memclass, CAN_##ptrclass)
#define V_DEF_CONSTP2CONST(storage, ptrtype, memclass, ptrclass) storage CONSTP2CONST(ptrtype, CAN_##memclass, CAN_##ptrclass)
#define V_DEF_CONSTP2CONST_TYPE(storage, ptrtype, ptrclass)      typedef storage CONSTP2CONST(ptrtype, TYPEDEF, CAN_##ptrclass)
#define V_DEF_FUNC(storage, rettype, memclass)                   storage FUNC(rettype, CAN_##memclass)
#define V_DEF_FUNC_API(storage, rettype, memclass)               storage FUNC(rettype, CAN_##memclass)
#define V_DEF_FUNC_CBK(storage, rettype, memclass)               storage FUNC(rettype, CAN_##memclass)
#define V_DEF_P2FUNC(storage, rettype, ptrclass, fctname)        storage P2FUNC(rettype, CAN_##ptrclass, fctname)

#if !defined(vuint8)
#define CAN_HL_NO_V_DEF
#define vuint8 uint8
#endif
#if !defined(vsint8)
#define vsint8 sint8
#endif
#if !defined(vuint16)
#define vuint16 uint16
#endif
#if !defined(vsint16)
#define vsint16 sint16
#endif
#if !defined(vuint32)
#define vuint32 uint32
#endif
#if !defined(vsint32)
#define vsint32 sint32
#endif

#define kCanIdTypeStd                           0x00000000u
#define kCanIdTypeExt                           0x80000000u

#if defined( C_ENABLE_CAN_FD_USED )
#define kCanFdTypeFd                           0x04u
#define kCanFdTypeClassic                      0x00u
#define kCanFdBrsTypeTrue                      0x02u
#define kCanFdBrsTypeFalse                     0x00u
#endif
#define kCanStdIdMask                           0x000007FFu
#define kCanExtIdMask                           0x1FFFFFFFu
#define kCanRecMask                             0x00FF0000u
#define kCanTecMask                             0xFF000000u
#define kCanDlcLogMask                          0x0Fu

#define kCanLoopRamInit                         0x00u
#define kCanLoopGlobalInit                      0x01u
#define kCanLoopChannelTransition               0x02u
#define kCanLoopRxFcProcess                     0x03u

V_DEF_P2VAR_TYPE(V_NONE, Std_VersionInfoType, APPL_VAR) Can_VersionInfoPtrType;
V_DEF_P2CONST_TYPE(V_NONE, Can_ConfigType, CONST_PBCFG) Can_ConfigPtrType;
V_DEF_P2CONST_TYPE(V_NONE, Can_PduType, APPL_VAR)           Can_PduInfoPtrType;
V_DEF_P2VAR_TYPE(V_NONE, Can_PduType, APPL_VAR)             Can_PduInfoPtrType_var;
V_DEF_P2CONST_TYPE(V_NONE, uint8, RX_TX_DATA)               Can_DataPtrType;
V_DEF_P2VAR_TYPE(V_NONE, uint8, APPL_VAR)                   Can_ErrorCounterPtrType;
V_DEF_P2VAR_TYPE(V_NONE, Can_ControllerStateType, APPL_VAR) Can_ControllerStatePtrType;
V_DEF_P2VAR_TYPE(V_NONE, Can_ErrorStateType, APPL_VAR)      Can_ErrorStatePtrType;

typedef union
{
#if defined(C_ENABLE_CAN_FD_FULL)
  vuint8  bData[64];
  vuint16 wData[32];
  vuint32 iData[16];
#else
  vuint8  bData[8];
  vuint16 wData[4];
  vuint32 iData[2];
#endif
}tCanTmpData;

typedef vuint8            CanInitHandle;
#define CanObjectHandle   Can_HwHandleType

typedef vuint16           CanTransmitHandle;
typedef vuint16           CanReceiveHandle;

V_DEF_P2SFR_CAN_TYPE(volatile, tCanTmpMsgObj) CanChipMsgPtr;
V_DEF_P2SFR_CAN_TYPE(volatile, vuint32) CanChipMsgPtr32;
V_DEF_P2SFR_CAN_TYPE(volatile, vuint8) CanChipDataPtr;

#if defined(C_ENABLE_RX_FULLCAN_OBJECTS) || defined(C_ENABLE_RX_BASICCAN_OBJECTS)
V_DEF_P2VAR_TYPE(V_NONE, vuint8, VAR_NOINIT) CanVarPtr8;
#endif

typedef vuint32          tCanRxId0;
typedef vuint32          tCanTxId0;
typedef vuint32          tCanIdType;
typedef vuint8           tCanDlc;

#if defined( C_ENABLE_CAN_FD_USED )

typedef vuint8           tCanFdType;
typedef vuint8           tCanFdBrsType;
#endif

#if defined(C_ENABLE_SLEEP_WAKEUP)
#define C_ENABLE_LL_WAKEUP_SUPPORT
#endif
#if defined(C_ENABLE_LL_WAKEUP_SUPPORT)
#if defined(C_ENABLE_WAKEUP_POLLING)
#define C_ENABLE_LL_WAKEUP_POLLING
#endif
#else
#define C_ENABLE_LL_WAKEUP_POLLING
#endif

#if((CAN_INTLOCK == CAN_DRIVER ) || (CAN_INTLOCK == CAN_BOTH))
#if((defined(C_ENABLE_RX_BASICCAN_OBJECTS) && !defined(C_ENABLE_RX_BASICCAN_POLLING)) || \
       (defined(C_ENABLE_RX_FULLCAN_OBJECTS)  && !defined(C_ENABLE_RX_FULLCAN_POLLING))  || \
       !defined(C_ENABLE_TX_POLLING)         || \
        defined(C_ENABLE_INDIVIDUAL_POLLING) || \
       !defined(C_ENABLE_ERROR_POLLING)      || \
       !defined(C_ENABLE_LL_WAKEUP_POLLING))
#define C_ENABLE_LL_CAN_INTCTRL
#endif
#if defined(C_ENABLE_LL_WAKEUP_SUPPORT)
#define C_ENABLE_LL_CAN_WAKEUP_INTCTRL
#endif
#endif
#if((CAN_INTLOCK == CAN_APPL ) || (CAN_INTLOCK == CAN_BOTH))
#if((defined(C_ENABLE_RX_BASICCAN_OBJECTS) && !defined(C_ENABLE_RX_BASICCAN_POLLING)) || \
       (defined(C_ENABLE_RX_FULLCAN_OBJECTS)  && !defined(C_ENABLE_RX_FULLCAN_POLLING))  || \
       !defined(C_ENABLE_TX_POLLING)         || \
        defined(C_ENABLE_INDIVIDUAL_POLLING) || \
       !defined(C_ENABLE_ERROR_POLLING)      || \
       !defined(C_ENABLE_LL_WAKEUP_POLLING))
#define C_ENABLE_LL_CAN_INTCB
#endif
#if defined(C_ENABLE_LL_WAKEUP_SUPPORT)
#define C_ENABLE_LL_CAN_WAKEUP_INTCB
#endif
#endif

#if defined(C_ENABLE_LL_CAN_INTCTRL)
typedef struct{
  vuint8  RF;
  vuint8  GErr;
  vuint8  GErrCnt;
}tCanLLCanGlobalIntOld;
#endif

V_DEF_P2VAR_TYPE(V_NONE, tCanLLCanIntOld, VAR_NOINIT) tCanLLCanIntOldPtr;

#define CAN_START_SEC_CODE
#include "MemMap.hpp"

V_DEF_FUNC(V_NONE, void, CODE) Can_InitMemory(void);
V_DEF_FUNC(V_NONE, void, CODE) Can_Init( Can_ConfigPtrType ConfigPtr );

#if((CAN_CHANGE_BAUDRATE_API == STD_ON) || (CAN_SET_BAUDRATE_API == STD_OFF))
V_DEF_FUNC(V_NONE, Std_ReturnType, CODE) Can_ChangeBaudrate( uint8 Controller, V_DEF_CONST(V_NONE, uint16, APPL_CONST) Baudrate );
#endif

#if(CAN_CHANGE_BAUDRATE_API == STD_ON)
V_DEF_FUNC(V_NONE, Std_ReturnType, CODE) Can_CheckBaudrate( uint8 Controller, V_DEF_CONST(V_NONE, uint16, APPL_CONST) Baudrate );
#endif

#if(CAN_SET_BAUDRATE_API == STD_ON)
V_DEF_FUNC(V_NONE, Std_ReturnType, CODE) Can_SetBaudrate( uint8 Controller, uint16 BaudRateConfigID );
#endif

#if(CAN_VERSION_INFO_API == STD_ON)
V_DEF_FUNC(V_NONE, void, CODE) Can_GetVersionInfo( Can_VersionInfoPtrType VersionInfo );
#endif

#if(CAN_GET_STATUS == STD_ON)
V_DEF_FUNC(V_NONE, uint8, CODE) Can_GetStatus( uint8 Controller );
V_DEF_FUNC(V_NONE, Std_ReturnType, CODE) Can_GetControllerMode( uint8 Controller, Can_ControllerStatePtrType ControllerModePtr );
V_DEF_FUNC(V_NONE, Std_ReturnType, CODE) Can_GetControllerErrorState( uint8 Controller, Can_ErrorStatePtrType ErrorStatePtr );
V_DEF_FUNC(V_NONE, Std_ReturnType, CODE) Can_GetControllerTxErrorCounter( uint8 Controller, Can_ErrorCounterPtrType TxErrorCounterPtr );
V_DEF_FUNC(V_NONE, Std_ReturnType, CODE) Can_GetControllerRxErrorCounter( uint8 Controller, Can_ErrorCounterPtrType RxErrorCounterPtr );
#endif

V_DEF_FUNC(V_NONE, Can_ReturnType, CODE) Can_SetControllerMode( uint8 Controller, Can_StateTransitionType Transition );
V_DEF_FUNC(V_NONE, Can_ReturnType, CODE) Can_Write( Can_HwHandleType Hth, Can_PduInfoPtrType PduInfo );
V_DEF_FUNC(V_NONE, void, CODE) Can_CancelTx( Can_HwHandleType Hth, PduIdType PduId );

#if defined(C_ENABLE_MIRROR_MODE)
V_DEF_FUNC(V_NONE, void, CODE) Can_SetMirrorMode( uint8 Controller, CddMirror_MirrorModeType mirrorMode );
#endif

#if defined(C_ENABLE_SILENT_MODE)
V_DEF_FUNC(V_NONE, Std_ReturnType, CODE) Can_SetSilentMode( uint8 Controller, Can_SilentModeType silentMode );
#endif

#if defined(C_ENABLE_CHECK_WAKEUP_CAN_RET_TYPE)
V_DEF_FUNC(V_NONE, Can_ReturnType, CODE) Can_CheckWakeup( uint8 Controller );
#else
V_DEF_FUNC(V_NONE, Std_ReturnType, CODE) Can_CheckWakeup( uint8 Controller );
#endif

V_DEF_FUNC(V_NONE, void, CODE) Can_DisableControllerInterrupts( uint8 Controller );
V_DEF_FUNC(V_NONE, void, CODE) Can_EnableControllerInterrupts( uint8 Controller );
V_DEF_FUNC(extern, void, CODE) Can_MainFunction_Write(void);
V_DEF_FUNC(extern, void, CODE) Can_MainFunction_Read(void);
V_DEF_FUNC(extern, void, CODE) Can_MainFunction_BusOff(void);
V_DEF_FUNC(extern, void, CODE) Can_MainFunction_Wakeup(void);
V_DEF_FUNC(extern, void, CODE) Can_MainFunction_Mode(void);

#if defined(C_ENABLE_CAN_RAM_CHECK_EXTENDED)
V_DEF_FUNC(V_NONE, void, CODE) Can_RamCheckExecute( uint8 Controller );
V_DEF_FUNC(V_NONE, void, CODE) Can_RamCheckEnableMailbox( Can_HwHandleType htrh );
V_DEF_FUNC(V_NONE, void, CODE) Can_RamCheckEnableController( uint8 Controller );
#endif

#if defined(C_ENABLE_ECC_TX_ERROR)
V_DEF_FUNC_API(V_NONE, vuint8, CODE) CanEccTxError(CanChannelHandle Controller);
V_DEF_FUNC_API(V_NONE, void, CODE) CanEccTxErrorClear(CanChannelHandle Controller);
#endif

#if defined(C_ENABLE_GLOBAL_INIT_POST_PROCESS)
V_DEF_FUNC_API(V_NONE, vuint8, CODE) CanGetFilterRulesStartPage(void);
V_DEF_FUNC_API(V_NONE, vuint8, CODE) CanGetFilterRulesStartIndex(void);
#endif

#if(CAN_NESTED_INTERRUPTS == STD_ON)
#define C_ENABLE_NESTED_INTERRUPTS
#else
#define C_DISABLE_NESTED_INTERRUPTS
#endif

#if defined(C_ENABLE_NESTED_INTERRUPTS)
#if defined(C_COMP_GHS_RH850_RSCAN)
#define CanLL_DI()
#define CanLL_EI()
#else
#define CanLL_DI()        __asm(" di")
#define CanLL_EI()        __asm(" ei")
#endif
#else
#define CanLL_DI()
#define CanLL_EI()
#endif

#define CanLL_SYNCP()      __asm(" syncp")

#if defined(C_ENABLE_ISRVOID)
#define C_ISR_KEYWORD      V_NONE
#else
#if defined(C_COMP_GHS_RH850_RSCAN)
#define C_ISR_KEYWORD     V_NONE
#endif
#endif

#if !(defined(C_ENABLE_ISR_PROTOTYPE) || defined(C_DISABLE_ISR_PROTOTYPE))
#define C_ENABLE_ISR_PROTOTYPE
#endif

#if defined(C_ENABLE_ISR_PROTOTYPE)
#if defined(C_ENABLE_OSEK_OS) && defined(C_ENABLE_OSEK_OS_INTCAT2)

#else
#if defined( kCanPhysToLogChannelIndex_0 )

#if defined(C_ENABLE_TX_POLLING) && !defined(C_ENABLE_INDIVIDUAL_POLLING)
#    else

V_DEF_FUNC(C_ISR_KEYWORD, void, CODE) CanIsrTx_0(void);

#endif

#if defined(C_ENABLE_LL_WAKEUP_SUPPORT)

#     if !defined(C_ENABLE_WAKEUP_POLLING) || defined(C_ENABLE_USE_OS_INTERRUPT_CONTROL)

V_DEF_FUNC(C_ISR_KEYWORD, void, CODE) CanIsrWakeup_0(void);

#     endif
#endif

#if defined(C_ENABLE_ERROR_POLLING)
#    else

V_DEF_FUNC(C_ISR_KEYWORD, void, CODE) CanIsrStatus_0(void);

#endif

#endif
#if defined( kCanPhysToLogChannelIndex_1 )

#if defined(C_ENABLE_TX_POLLING) && !defined(C_ENABLE_INDIVIDUAL_POLLING)
#    else

V_DEF_FUNC(C_ISR_KEYWORD, void, CODE) CanIsrTx_1(void);

#endif

#if defined(C_ENABLE_LL_WAKEUP_SUPPORT)

#     if !defined(C_ENABLE_WAKEUP_POLLING) || defined(C_ENABLE_USE_OS_INTERRUPT_CONTROL)

V_DEF_FUNC(C_ISR_KEYWORD, void, CODE) CanIsrWakeup_1(void);

#     endif
#endif

#if defined(C_ENABLE_ERROR_POLLING)
#    else

V_DEF_FUNC(C_ISR_KEYWORD, void, CODE) CanIsrStatus_1(void);

#endif

#endif
#if defined( kCanPhysToLogChannelIndex_2 )

#if defined(C_ENABLE_TX_POLLING) && !defined(C_ENABLE_INDIVIDUAL_POLLING)
#    else

V_DEF_FUNC(C_ISR_KEYWORD, void, CODE) CanIsrTx_2(void);

#endif

#if defined(C_ENABLE_LL_WAKEUP_SUPPORT)

#     if !defined(C_ENABLE_WAKEUP_POLLING) || defined(C_ENABLE_USE_OS_INTERRUPT_CONTROL)

V_DEF_FUNC(C_ISR_KEYWORD, void, CODE) CanIsrWakeup_2(void);

#     endif
#endif

#if defined(C_ENABLE_ERROR_POLLING)
#    else

V_DEF_FUNC(C_ISR_KEYWORD, void, CODE) CanIsrStatus_2(void);

#endif

#endif
#if defined( kCanPhysToLogChannelIndex_3 )

#if defined(C_ENABLE_TX_POLLING) && !defined(C_ENABLE_INDIVIDUAL_POLLING)
#    else

V_DEF_FUNC(C_ISR_KEYWORD, void, CODE) CanIsrTx_3(void);

#endif

#if defined(C_ENABLE_LL_WAKEUP_SUPPORT)

#     if !defined(C_ENABLE_WAKEUP_POLLING) || defined(C_ENABLE_USE_OS_INTERRUPT_CONTROL)

V_DEF_FUNC(C_ISR_KEYWORD, void, CODE) CanIsrWakeup_3(void);

#     endif
#endif

#if defined(C_ENABLE_ERROR_POLLING)
#    else

V_DEF_FUNC(C_ISR_KEYWORD, void, CODE) CanIsrStatus_3(void);

#endif

#endif
#if defined( kCanPhysToLogChannelIndex_4 )

#if defined(C_ENABLE_TX_POLLING) && !defined(C_ENABLE_INDIVIDUAL_POLLING)
#    else

V_DEF_FUNC(C_ISR_KEYWORD, void, CODE) CanIsrTx_4(void);

#endif

#if defined(C_ENABLE_LL_WAKEUP_SUPPORT)

#     if !defined(C_ENABLE_WAKEUP_POLLING) || defined(C_ENABLE_USE_OS_INTERRUPT_CONTROL)

V_DEF_FUNC(C_ISR_KEYWORD, void, CODE) CanIsrWakeup_4(void);

#     endif
#endif

#if defined(C_ENABLE_ERROR_POLLING)
#    else

V_DEF_FUNC(C_ISR_KEYWORD, void, CODE) CanIsrStatus_4(void);

#endif

#endif
#if defined( kCanPhysToLogChannelIndex_5 )

#if defined(C_ENABLE_TX_POLLING) && !defined(C_ENABLE_INDIVIDUAL_POLLING)
#    else

V_DEF_FUNC(C_ISR_KEYWORD, void, CODE) CanIsrTx_5(void);

#endif

#if defined(C_ENABLE_LL_WAKEUP_SUPPORT)

#     if !defined(C_ENABLE_WAKEUP_POLLING) || defined(C_ENABLE_USE_OS_INTERRUPT_CONTROL)

V_DEF_FUNC(C_ISR_KEYWORD, void, CODE) CanIsrWakeup_5(void);

#     endif
#endif

#if defined(C_ENABLE_ERROR_POLLING)
#    else

V_DEF_FUNC(C_ISR_KEYWORD, void, CODE) CanIsrStatus_5(void);

#endif

#endif
#if defined( kCanPhysToLogChannelIndex_6 )

#if defined(C_ENABLE_TX_POLLING) && !defined(C_ENABLE_INDIVIDUAL_POLLING)
#    else

V_DEF_FUNC(C_ISR_KEYWORD, void, CODE) CanIsrTx_6(void);

#endif

#if defined(C_ENABLE_LL_WAKEUP_SUPPORT)

#     if !defined(C_ENABLE_WAKEUP_POLLING) || defined(C_ENABLE_USE_OS_INTERRUPT_CONTROL)

V_DEF_FUNC(C_ISR_KEYWORD, void, CODE) CanIsrWakeup_6(void);

#     endif
#endif

#if defined(C_ENABLE_ERROR_POLLING)
#    else

V_DEF_FUNC(C_ISR_KEYWORD, void, CODE) CanIsrStatus_6(void);

#endif

#endif
#if defined( kCanPhysToLogChannelIndex_7 )

#if defined(C_ENABLE_TX_POLLING) && !defined(C_ENABLE_INDIVIDUAL_POLLING)
#    else

V_DEF_FUNC(C_ISR_KEYWORD, void, CODE) CanIsrTx_7(void);

#endif

#if defined(C_ENABLE_LL_WAKEUP_SUPPORT)

#     if !defined(C_ENABLE_WAKEUP_POLLING) || defined(C_ENABLE_USE_OS_INTERRUPT_CONTROL)

V_DEF_FUNC(C_ISR_KEYWORD, void, CODE) CanIsrWakeup_7(void);

#     endif
#endif

#if defined(C_ENABLE_ERROR_POLLING)
#    else

V_DEF_FUNC(C_ISR_KEYWORD, void, CODE) CanIsrStatus_7(void);

#endif

#endif

#if(defined(C_ENABLE_RX_BASICCAN_OBJECTS) && defined(C_ENABLE_OVERRUN))

#if defined(C_ENABLE_ERROR_POLLING)
#    else

V_DEF_FUNC(C_ISR_KEYWORD, void, CODE) CanIsrGlobalStatus(void);

#endif
#endif

#if defined(C_ENABLE_RX_BASICCAN_OBJECTS)

#if defined(C_ENABLE_RX_BASICCAN_POLLING) && !defined(C_ENABLE_INDIVIDUAL_POLLING)
#    else

V_DEF_FUNC(C_ISR_KEYWORD, void, CODE) CanIsrRxFifo(void);

#endif
#endif
#endif
#endif

#if defined(C_ENABLE_TX_POLLING) && !defined(C_ENABLE_INDIVIDUAL_POLLING)
#else

V_DEF_FUNC(V_NONE, void, CODE) CanInterruptTx(CAN_HW_CHANNEL_CANTYPE_ONLY);

#endif

#if defined(C_ENABLE_LL_WAKEUP_SUPPORT)

#if defined(C_ENABLE_WAKEUP_POLLING)
#   else

V_DEF_FUNC(V_NONE, void, CODE) CanInterruptWakeup(CAN_HW_CHANNEL_CANTYPE_ONLY);

#endif
#endif

#if defined(C_ENABLE_ERROR_POLLING)
#else

V_DEF_FUNC(V_NONE, void, CODE) CanInterruptStatus(CAN_HW_CHANNEL_CANTYPE_ONLY);

#if(defined(C_ENABLE_RX_BASICCAN_OBJECTS) && defined(C_ENABLE_OVERRUN))

V_DEF_FUNC(V_NONE, void, CODE) CanInterruptGlobalStatus(void);

#endif
#endif

#if defined(C_ENABLE_RX_BASICCAN_OBJECTS)
#if defined(C_ENABLE_RX_BASICCAN_POLLING ) && !defined(C_ENABLE_INDIVIDUAL_POLLING)
#else

V_DEF_FUNC(V_NONE, void, CODE) CanInterruptRxFifo(void);

#endif
#endif

#define CAN_STOP_SEC_CODE
#include "MemMap.hpp"

#define CAN_START_SEC_CODE_APPL
#include "MemMap.hpp"

#if(CAN_GENERIC_PRECOPY == STD_ON)
V_DEF_FUNC(extern, Can_ReturnType, APPL_CODE) Appl_GenericPrecopy( uint8 Controller, Can_IdType ID, uint8 DataLength, Can_DataPtrType DataPtr );
#endif

#if defined(CAN_ENABLE_GENERIC_CONFIRMATION_API1)
V_DEF_FUNC(extern, Can_ReturnType, APPL_CODE) Appl_GenericConfirmation( PduIdType PduId );
#endif

#if defined(CAN_ENABLE_GENERIC_CONFIRMATION_API2)
V_DEF_FUNC(extern, Can_ReturnType, APPL_CODE) Appl_GenericConfirmation( uint8 Controller, Can_PduInfoPtrType DataPtr );
#endif

#if defined(C_ENABLE_PRETRANSMIT_FCT)
V_DEF_FUNC(extern, void, APPL_CODE) Appl_GenericPreTransmit( uint8 Controller, Can_PduInfoPtrType_var DataPtr );
#endif

#if(CAN_HW_LOOP_SUPPORT_API == STD_ON)
V_DEF_FUNC(V_NONE, void, APPL_CODE) ApplCanTimerStart( CAN_CHANNEL_CANTYPE_FIRST uint8 source );
V_DEF_FUNC(V_NONE, Can_ReturnType, APPL_CODE) ApplCanTimerLoop( CAN_CHANNEL_CANTYPE_FIRST uint8 source );
V_DEF_FUNC(V_NONE, void, APPL_CODE) ApplCanTimerEnd( CAN_CHANNEL_CANTYPE_FIRST uint8 source );
#endif

#if(CAN_INTLOCK != CAN_DRIVER)
V_DEF_FUNC(extern, void, APPL_CODE) ApplCanInterruptDisable( uint8 Controller );
V_DEF_FUNC(extern, void, APPL_CODE) ApplCanInterruptRestore( uint8 Controller );
#endif

#if(CAN_OVERRUN_NOTIFICATION == CAN_APPL)
V_DEF_FUNC(extern, void, APPL_CODE) Appl_CanOverrun ( uint8 Controller );
V_DEF_FUNC(extern, void, APPL_CODE) Appl_CanFullCanOverrun ( uint8 Controller );
#endif

#if defined(C_ENABLE_CAN_RAM_CHECK)
#if !defined(C_ENABLE_CAN_RAM_CHECK_EXTENDED)
#if defined(C_ENABLE_NOTIFY_CORRUPT_MAILBOX)
V_DEF_FUNC(extern, void, APPL_CODE) Appl_CanCorruptMailbox(uint8 Controller, Can_HwHandleType hwObjHandle);
#endif

V_DEF_FUNC(extern, uint8, APPL_CODE) Appl_CanRamCheckFailed(uint8 Controller);
#endif
#endif

#if defined(C_ENABLE_LL_WAKEUP_SUPPORT)
#if defined(C_ENABLE_LL_CAN_INTCB) || defined(C_ENABLE_LL_CAN_WAKEUP_INTCB)
V_DEF_FUNC_CBK(extern, void, APPL_CODE) ApplCanWakeupInterruptEnable(CanChannelHandle Controller);
V_DEF_FUNC_CBK(extern, void, APPL_CODE) ApplCanWakeupInterruptDisable(CanChannelHandle Controller);
#endif

#if defined(C_ENABLE_WAKEUP_POLLING) && defined(C_ENABLE_LL_CAN_WAKEUP_INTCB)
V_DEF_FUNC_CBK(extern, Can_ReturnType, APPL_CODE) ApplCanWakeupOccurred(CanChannelHandle Controller);
#endif
#endif

#if defined(C_ENABLE_INTC_ACCESS_BY_APPL)
V_DEF_FUNC_CBK(extern, void, APPL_CODE) ApplCanWriteIcr8(vuint32 Address, vuint8 Value);
V_DEF_FUNC_CBK(extern, vuint8, APPL_CODE) ApplCanReadIcr8(vuint32 Address);
#endif

#if defined(C_ENABLE_ECC_CONFIGURATION)
V_DEF_FUNC_CBK(extern, void, APPL_CODE) ApplCanEccConfiguration(void);
#endif

#if defined(C_ENABLE_ECC_RX_REJECT)
V_DEF_FUNC_CBK(extern, vuint8, APPL_CODE) ApplCanEccRxReject(CanChannelHandle Controller);
#endif

#if defined(C_ENABLE_CAN_RAM_CHECK_EXTENDED)
V_DEF_FUNC_CBK(extern, void, APPL_CODE) Appl_CanRamCheckCorruptCell(void);
#endif

#if defined(C_ENABLE_GLOBAL_INIT_POST_PROCESS)
V_DEF_FUNC_CBK(extern, void, APPL_CODE) ApplCanGlobalInitPostProcessing(void);
#endif

#define CAN_STOP_SEC_CODE_APPL
#include "MemMap.hpp"

#if !defined(C_DRV_INTERNAL)
#if defined(CAN_HL_NO_V_DEF)
#  undef vuint8
#  undef vsint8
#  undef vuint16
#  undef vsint16
#  undef vuint32
#  undef vsint32
#endif
#endif

#ifdef __cplusplus
}
#endif
#endif

