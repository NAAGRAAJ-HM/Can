

#if !defined(CAN_LOCAL_H)
#define  CAN_LOCAL_H

#include "SchM_Can.hpp"
#include "McalCan.hpp"

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

#if defined(C_ENABLE_MIXED_ID) || defined(C_ENABLE_EXTENDED_ID)
#define CAN_ID_IDE_MASK            0x80000000UL
#define CAN_ID_FD_MASK             0x40000000UL
#define CAN_ID_MASK                0x1FFFFFFFUL
#define CAN_ID_MASK_STD            0x000007FFUL
#define CAN_ID_UNUSED_MASK         0x20000000UL
#else
#define CAN_ID_IDE_MASK            0x0000U
#define CAN_ID_FD_MASK             0x4000U
#define CAN_ID_MASK                0x07FFU
#define CAN_ID_MASK_STD            0x07FFU
#define CAN_ID_UNUSED_MASK         0x3800U
#endif
#define kCanAllChannels  ((CanChannelHandle)0xFFU)

#if !defined(C_DRV_INTERNAL)
# error "Can_Local.h should only be included by Can.c"
#endif

#define kCanNumberOfChannels  Can_GetControllerMax()

#define kCanNumberOfHwChannels  kCanNumberOfChannels

#if defined( C_SINGLE_RECEIVE_CHANNEL )

#define channel                                ((CanChannelHandle)0)
#define canHwChannel                           ((CanChannelHandle)0)
#define CAN_HL_HW_CHANNEL_STARTINDEX(ch)       ((CanChannelHandle)0)
#define CAN_HL_HW_CHANNEL_STOPINDEX(ch)        ((CanChannelHandle)0)
#else
#define channel                                Controller
#define canHwChannel                           Controller
#define CAN_HL_HW_CHANNEL_STARTINDEX(ch)       (ch)
#define CAN_HL_HW_CHANNEL_STOPINDEX(ch)        (ch)
#endif
#if !defined(CAN_TRANSITION_CHECK)
#define CAN_TRANSITION_CHECK STD_ON
#endif
#if !defined(CAN_REINIT_START)
#define CAN_REINIT_START STD_OFF
#endif

#if !defined(CAN_OS_TICK2MS)
# error "CAN_OS_TICK2MS() should be defined to OS_TICKS2MS_<counterShortName>() macro from OS"
#endif
#if !defined(CAN_OS_COUNTER_ID)
# error "CAN_OS_COUNTER_ID should be defined to 'counterShortName' from OS"
#endif

#if !defined(CAN_ID_MASK_IN_GENERIC_CALLOUT)
#define CAN_ID_MASK_IN_GENERIC_CALLOUT (CAN_ID_IDE_MASK | CAN_ID_FD_MASK | CAN_ID_MASK)

#endif

#define kCanBufferFree              (uint8)0xFF
#define kCanBufferCancel            (uint8)0xFE
#define kCanBufferCancelSw          (uint8)0xFD
#define kCanBufferSend              (uint8)0x01

#define kCanFailed                  (uint8)0x00
#define kCanOk                      (uint8)0x01
#define kCanRequested               (uint8)0x03

#define kCanFalse                   kCanFailed
#define kCanTrue                    kCanOk

#define Can_GetControllerMax()                        Can_GetSizeOfControllerData()
#define Can_GetCanToCanIfChannelMapping(Index)        Can_GetCanIfChannelId((Index))

#define Can_GetCanControllerDefaultBaudrate(logCh)    Can_GetCanControllerDefaultBaudrateOfControllerConfig(logCh)
#define Can_GetCanControllerDefaultBaudrateIdx(logCh) Can_GetCanControllerDefaultBaudrateIdxOfControllerConfig(logCh)
#if !defined(Can_GetMailboxRxBasicLengthOfControllerConfig)
#define Can_GetMailboxRxBasicLengthOfControllerConfig(logCh) 0u
#define Can_GetMailboxRxBasicStartIdxOfControllerConfig(logCh) 0u
#define Can_GetMailboxRxBasicEndIdxOfControllerConfig(logCh) 0u
#endif
#define Can_GetRxBasicHandleMax(logCh)                Can_GetMailboxRxBasicLengthOfControllerConfig(logCh)
#define Can_GetRxBasicHandleStart(logCh)              (Can_HwHandleType)Can_GetMailboxRxBasicStartIdxOfControllerConfig(logCh)
#define Can_GetRxBasicHandleStop(logCh)               (Can_HwHandleType)Can_GetMailboxRxBasicEndIdxOfControllerConfig(logCh)
#define Can_GetRxBasicHwStart(logCh)                  Can_GetRxBasicHwStartOfControllerConfig(logCh)
#define Can_GetRxBasicHwStop(logCh)                   Can_GetRxBasicHwStopOfControllerConfig(logCh)
#if !defined(Can_GetMailboxRxFullLengthOfControllerConfig)
#define Can_GetMailboxRxFullLengthOfControllerConfig(logCh) 0u
#define Can_GetMailboxRxFullStartIdxOfControllerConfig(logCh) 0u
#define Can_GetMailboxRxFullEndIdxOfControllerConfig(logCh) 0u
#endif
#define Can_GetRxFullHandleMax(logCh)                 Can_GetMailboxRxFullLengthOfControllerConfig(logCh)
#define Can_GetRxFullHandleStart(logCh)               (Can_HwHandleType)Can_GetMailboxRxFullStartIdxOfControllerConfig(logCh)
#define Can_GetRxFullHandleStop(logCh)                (Can_HwHandleType)Can_GetMailboxRxFullEndIdxOfControllerConfig(logCh)
#define Can_GetRxFullHwStart(logCh)                   Can_GetRxFullHwStartOfControllerConfig(logCh)
#define Can_GetRxFullHwStop(logCh)                    Can_GetRxFullHwStopOfControllerConfig(logCh)
#if !defined(Can_GetMailboxTxBasicLengthOfControllerConfig)
#define Can_GetMailboxTxBasicLengthOfControllerConfig(logCh) 0u
#define Can_GetMailboxTxBasicStartIdxOfControllerConfig(logCh) 0u
#define Can_GetMailboxTxBasicEndIdxOfControllerConfig(logCh) 0u
#endif
#define Can_GetTxBasicHandleMax(logCh)                Can_GetMailboxTxBasicLengthOfControllerConfig(logCh)
#define Can_GetTxBasicHandleStart(logCh)              (Can_HwHandleType)Can_GetMailboxTxBasicStartIdxOfControllerConfig(logCh)
#define Can_GetTxBasicHandleStop(logCh)               (Can_HwHandleType)Can_GetMailboxTxBasicEndIdxOfControllerConfig(logCh)
#define Can_GetTxBasicHwStart(logCh)                  Can_GetTxBasicHwStartOfControllerConfig(logCh)
#define Can_GetTxBasicHwStop(logCh)                   Can_GetTxBasicHwStopOfControllerConfig(logCh)
#if !defined(Can_GetMailboxTxFullLengthOfControllerConfig)
#define Can_GetMailboxTxFullLengthOfControllerConfig(logCh) 0u
#define Can_GetMailboxTxFullStartIdxOfControllerConfig(logCh) 0u
#define Can_GetMailboxTxFullEndIdxOfControllerConfig(logCh) 0u
#endif
#define Can_GetTxFullHandleMax(logCh)                 Can_GetMailboxTxFullLengthOfControllerConfig(logCh)
#define Can_GetTxFullHandleStart(logCh)               (Can_HwHandleType)Can_GetMailboxTxFullStartIdxOfControllerConfig(logCh)
#define Can_GetTxFullHandleStop(logCh)                (Can_HwHandleType)Can_GetMailboxTxFullEndIdxOfControllerConfig(logCh)
#define Can_GetTxFullHwStart(logCh)                   Can_GetTxFullHwStartOfControllerConfig(logCh)
#define Can_GetTxFullHwStop(logCh)                    Can_GetTxFullHwStopOfControllerConfig(logCh)
#if !defined(Can_GetMailboxUnusedLengthOfControllerConfig)
#define Can_GetMailboxUnusedLengthOfControllerConfig(logCh) 0u
#define Can_GetMailboxUnusedStartIdxOfControllerConfig(logCh) 0u
#define Can_GetMailboxUnusedEndIdxOfControllerConfig(logCh) 0u
#endif
#define Can_GetUnusedHandleMax(logCh)                 Can_GetMailboxUnusedLengthOfControllerConfig(logCh)
#define Can_GetUnusedHandleStart(logCh)               (Can_HwHandleType)Can_GetMailboxUnusedStartIdxOfControllerConfig(logCh)
#define Can_GetUnusedHandleStop(logCh)                (Can_HwHandleType)Can_GetMailboxUnusedEndIdxOfControllerConfig(logCh)
#define Can_GetUnusedHwStart(logCh)                   Can_GetUnusedHwStartOfControllerConfig(logCh)
#define Can_GetUnusedHwStop(logCh)                    Can_GetUnusedHwStopOfControllerConfig(logCh)

#define Can_GetMailboxSize(htrh)                      Can_GetMailboxSizeOfMailbox(htrh)
#define Can_GetMailboxHwHandle(htrh)                  Can_GetHwHandleOfMailbox(htrh)
#define Can_GetMailboxIDValue(htrh)                   Can_GetIDValueOfMailbox(htrh)
#define Can_GetMailboxType(htrh)                      Can_GetMailboxTypeOfMailbox(htrh)
#define Can_GetMailboxDataLen(htrh)                   Can_GetMaxDataLenOfMailbox(htrh)
#define Can_GetMailboxFdPadding(htrh)                 Can_GetFdPaddingOfMailbox(htrh)
#define Can_GetMailboxController(htrh)                (CanChannelHandle)Can_GetControllerConfigIdxOfMailbox(htrh)
#define Can_GetMailboxActiveSendObject(htrh)          Can_GetActiveSendObjectOfMailbox(htrh)
#define Can_GetMailboxActiveSendData(htrh)            Can_GetActiveSendDataOfMailbox(htrh)
#define Can_GetMailboxMemSecObjIndex(htrh)            Can_GetMemorySectionsIndexOfMailbox(htrh)
#define Can_IsMailboxIndivPolling(htrh)               Can_IsIsIndivPollingOfMailbox(htrh)
#define Can_GetMailboxTxHwFifo(htrh)                  Can_GetTxHwFifoOfMailbox(htrh)

#define Can_GetMemSecAddress(memSec)                  Can_GetMemoryStartAddressOfMemorySectionInfo(memSec)
#define Can_GetMemSecStartIndex(memSec)               Can_GetMemorySectionStartOfMemorySectionInfo(memSec)

#define Can_GetMemSecObjHwHandle(memSecObj)           Can_GetHwHandleOfMemorySectionObjects(memSecObj)
#define Can_GetMemSecObjMailboxElement(memSecObj)     Can_GetMailboxElementOfMemorySectionObjects(memSecObj)
#define Can_GetMemSecObjMailboxHandle(memSecObj)      Can_GetMailboxHandleOfMemorySectionObjects(memSecObj)
#define Can_IsMemSecObjIndivPolling(memSecObj)        Can_IsIsIndivPollingOfMemorySectionObjects(memSecObj)

#define Can_GetLastInitObject(Index)                   Can_GetLastInitObjectOfControllerData(Index)
#define Can_SetLastInitObject(Index, Value)            Can_SetLastInitObjectOfControllerData(Index, Value)
#define Can_GetCanInterruptOldStatus(Index)            Can_GetCanInterruptOldStatusOfControllerData(Index)
#define Can_SetCanInterruptOldStatus(Index, Value)     Can_SetCanInterruptOldStatusOfControllerData(Index, Value)
#define Can_GetCanInterruptCounter(Index)              Can_GetCanInterruptCounterOfControllerData(Index)
#define Can_SetCanInterruptCounter(Index, Value)       Can_SetCanInterruptCounterOfControllerData(Index, Value)
#define Can_IsIsWakeup(Index)                          Can_IsIsWakeupOfControllerData(Index)
#define Can_SetIsWakeup(Index, Value)                  Can_SetIsWakeupOfControllerData(Index, Value)
#define Can_IsIsBusOff(Index)                          Can_IsIsBusOffOfControllerData(Index)
#define Can_SetIsBusOff(Index, Value)                  Can_SetIsBusOffOfControllerData(Index, Value)
#define Can_GetBusOffCounter(Index)                    Can_GetBusOffCounterOfControllerData(Index)
#define Can_SetBusOffCounter(Index, Value)             Can_SetBusOffCounterOfControllerData(Index, Value)
#define Can_DecBusOffCounter(Index)                    Can_DecBusOffCounterOfControllerData(Index)
#define Can_GetModeTransitionRequest(Index)            Can_GetModeTransitionRequestOfControllerData(Index)
#define Can_SetModeTransitionRequest(Index, Value)     Can_SetModeTransitionRequestOfControllerData(Index, Value)
#define Can_GetBusOffTransitionRequest(Index)          Can_GetBusOffTransitionRequestOfControllerData(Index)
#define Can_SetBusOffTransitionRequest(Index, Value)   Can_SetBusOffTransitionRequestOfControllerData(Index, Value)
#define Can_GetRamCheckTransitionRequest(Index)        Can_GetRamCheckTransitionRequestOfControllerData(Index)
#define Can_SetRamCheckTransitionRequest(Index, Value) Can_SetRamCheckTransitionRequestOfControllerData(Index, Value)

#define Can_GetLogStatus(Index)                        Can_GetLogStatusOfControllerData(Index)
#define Can_SetLogStatus(Index, Value)                 Can_SetLogStatusOfControllerData(Index, Value)
#define Can_GetCanLoopTimeout(ch, Index)               (Can_GetLoopTimeoutOfControllerData(ch))[(Index)]
#define Can_GetMirrorModeState(Index)                  Can_GetMirrorModeStateOfControllerData(Index)
#define Can_SetMirrorModeState(Index, Value)           Can_SetMirrorModeStateOfControllerData(Index, Value)
#define Can_GetSilentModeState(Index)                  Can_GetSilentModeStateOfControllerData(Index)
#define Can_SetSilentModeState(Index, Value)           Can_SetSilentModeStateOfControllerData(Index, Value)

#define Can_GetActiveSendPdu(Index)                    Can_GetPduOfActiveSendObject(Index)
#define Can_SetActiveSendPdu(Index, Value)             Can_SetPduOfActiveSendObject(Index, Value)
#define Can_GetActiveSendState(Index)                  Can_GetStateOfActiveSendObject(Index)
#define Can_SetActiveSendState(Index, Value)           Can_SetStateOfActiveSendObject(Index, Value)
#define Can_GetActiveSendPduInfo(Index)                Can_GetPduInfoOfActiveSendObject(Index)
#define Can_GetActiveSendId(Index)                     (Can_GetPduInfoOfActiveSendObject(Index)).id
#define Can_SetActiveSendId(Index, Value)              (Can_GetPduInfoOfActiveSendObject(Index)).id = (Value)
#define Can_GetActiveSendLength(Index)                 (Can_GetPduInfoOfActiveSendObject(Index)).length
#define Can_SetActiveSendLength(Index, Value)          (Can_GetPduInfoOfActiveSendObject(Index)).length = (Value)
#define Can_GetActiveSendSdu(Index)                    (Can_GetPduInfoOfActiveSendObject(Index)).sdu
#define Can_SetActiveSendSdu(Index, Value)             (Can_GetPduInfoOfActiveSendObject(Index)).sdu = (Value)
#define Can_GetActiveSendSwPduHandle(Index)            (Can_GetPduInfoOfActiveSendObject(Index)).swPduHandle
#define Can_SetActiveSendSwPduHandle(Index, Value)     (Can_GetPduInfoOfActiveSendObject(Index)).swPduHandle = (Value)

#define Can_GetTxHwFifoWriteIndex(fifo)                Can_GetWriteIndexOfTxHwFifo(fifo)
#define Can_SetTxHwFifoWriteIndex(fifo, Value)         Can_SetWriteIndexOfTxHwFifo(fifo, Value)
#define Can_IncTxHwFifoWriteIndex(fifo)                Can_IncWriteIndexOfTxHwFifo(fifo)
#define Can_GetTxHwFifoReadIndex(fifo)                 Can_GetReadIndexOfTxHwFifo(fifo)
#define Can_SetTxHwFifoReadIndex(fifo, Value)          Can_SetReadIndexOfTxHwFifo(fifo, Value)
#define Can_IncTxHwFifoReadIndex(fifo)                 Can_IncReadIndexOfTxHwFifo(fifo)
#define Can_GetTxHwFifoFillCount(fifo)                 Can_GetFillCountOfTxHwFifo(fifo)
#define Can_SetTxHwFifoFillCount(fifo, Value)          Can_SetFillCountOfTxHwFifo(fifo, Value)
#define Can_IncTxHwFifoFillCount(fifo)                 Can_IncFillCountOfTxHwFifo(fifo)
#define Can_DecTxHwFifoFillCount(fifo)                 Can_DecFillCountOfTxHwFifo(fifo)

#define Can_GetRxTmpBuf(logCh)                        Can_GetRxTmpBufOfControllerData(logCh)
#define Can_GetRxFcCount(logCh)                       (vuint8) Can_GetRxFullHandleMax(logCh)
#if defined(C_ENABLE_TX_HW_FIFO)
#define Can_IsTxFifo(htrh)                           (Can_GetMailboxType(htrh) == CAN_TX_BASICCAN_FIFO_TYPE_MAILBOXTYPEOFMAILBOX)
#define Can_GetTxHwToMbHandle(logCh, Index)          Can_GetMemSecObjMailboxHandle(Can_GetMemSecStartIndex((logCh) << 1) + (Index))
#define Can_GetTxFifoHwToMbHandle(logCh, Index)      Can_GetMemSecObjMailboxHandle(Can_GetMemSecStartIndex(((logCh) << 1) + 1u) + (Index))
#else
#define Can_GetTxHwToMbHandle(logCh, Index)          Can_GetMemSecObjMailboxHandle(Can_GetMemSecStartIndex(logCh) + (Index))
#endif

#define C_HL_ENABLE_OVERRUN_IN_STATUS

#define C_HL_DISABLE_HW_RANGES_FILTER

#define C_HL_ENABLE_IDTYPE_IN_ID

#define C_LL_RX_IDTYPE_TABLE      CanRxId0
#define C_LL_TX_IDTYPE_TABLE      CanTxId0

#define C_HL_DISABLE_DUMMY_FCT_CALL

#define C_HL_DISABLE_TX_MSG_DESTROYED

#define C_HL_DISABLE_CANCEL_IN_HW_TASK

#define C_HL_DISABLE_HW_EXIT_TRANSMIT

#define C_HL_DISABLE_ADJUST_RXHANDLE

#define C_HL_DISABLE_REJECT_UNWANTED_IDTYPE

#define C_HL_DISABLE_REJECT_REMOTE_FRAME

#define C_HL_DISABLE_REJECT_REMOTE_FRAME_FULLCAN

#define C_HL_ENABLE_REJECT_ILLEGAL_DLC

#define C_HL_DISABLE_COPROCESSOR_SUPPORT

#define C_HL_DISABLE_AVOID_REENTRANT_APPLCANCANCELNOTIFICATION

#define C_ENABLE_TX_ACTUAL_MACROS

#define CAN_HL_HW_LAYOUT_TXBASIC_FIRST

#if defined(C_ENABLE_IF_RSCAN_FD_V3)
#define C_ENABLE_RSCAN_FD_LAYOUT
#else
#if defined(C_ENABLE_CAN_FD_USED)
#define C_ENABLE_RSCAN_FD_LAYOUT
#endif
#endif

#define CAN_CAST_ADDR(val)                      (val)

#if defined(C_ENABLE_SINGLE_PHYS_CHANNEL_OPTIMIZATION)
#define C_SINGLE_PHYS_CHANNEL
#define mCanLogToPhys(ch)                      kCanLogToPhys
#define mCanIntcChTxAdr(ch)                   kCanIntcChTxBaseAdr
#define mCanIntcChErrorAdr(ch)                kCanIntcChErrorBaseAdr
#define mCanIntcChWakeupAdr(ch)               kCanIntcChWakeupBaseAdr
#else
#define C_MULTIPLE_PHYS_CHANNEL
#define mCanLogToPhys(ch)                      Can_GetLogToPhys(ch)
#define mCanIntcChTxAdr(ch)                    Can_GetIntcChTxBaseAdrOfIntcAddresses(ch)
#define mCanIntcChErrorAdr(ch)                 Can_GetIntcChErrorBaseAdrOfIntcAddresses(ch)
#define mCanIntcChWakeupAdr(ch)                Can_GetIntcChWakeupBaseAdrOfIntcAddresses(ch)
#endif

#define kCanNumberOfUsedCanRxIdTables           1u
#define kCanNumberOfUsedCanTxIdTables           1u

#define MK_RX_RANGE_MASK_IDSTD0(id)             (MK_STDID0(id))
#define MK_RX_RANGE_CODE_IDSTD0(id)             (MK_STDID0(id))
#define MK_RX_RANGE_MASK_IDEXT0(id)             (MK_EXTID0(id) & ~kCanIdTypeExt)
#define MK_RX_RANGE_CODE_IDEXT0(id)             (MK_EXTID0(id))

#define MK_STDID0(id)                           ((id) & kCanStdIdMask)
#define MK_EXTID0(id)                           (((id) & kCanExtIdMask) | kCanIdTypeExt)

#define MK_TX_DLC(dlc)                          ((tCanDlc)((dlc) & kCanDlcLogMask))
#define MK_TX_DLC_EXT(dlc)                      ((tCanDlc)((dlc) & kCanDlcLogMask))

#define XT_TX_DLC(dlc_raw)                      ((vuint8)(dlc_raw))

#define CanActualDLCToReg(dlc)                  ((kCanRegSize) (((kCanRegSize) (dlc)) << 28))

#define CanRegToActualDLC(reg)                  ((vuint8) ((reg) >> 28))

#define CanRxActualIdRaw0(rxStruct)             ((tCanRxId0)  ((rxStruct)->pChipMsgObj->Id))

#if defined(C_ENABLE_EXTENDED_ID)
#define CanRxActualIdExtHi(rxStruct)           ((vuint8)   ((((rxStruct)->pChipMsgObj->Id) >> 24) & 0x1Fu))
#define CanRxActualIdExtMidHi(rxStruct)        ((vuint8)    (((rxStruct)->pChipMsgObj->Id) >> 16))
#define CanRxActualIdExtMidLo(rxStruct)        ((vuint8)    (((rxStruct)->pChipMsgObj->Id) >> 8 ))
#define CanRxActualIdExtLo(rxStruct)           ((vuint8)     ((rxStruct)->pChipMsgObj->Id))
#endif
#define CanRxActualIdType(rxStruct)             ((tCanIdType)(((rxStruct)->pChipMsgObj->Id) & kCanIdTypeExt))
#define CanRxActualExtId(rxStruct)              ((vuint32)   (((rxStruct)->pChipMsgObj->Id) & kCanExtIdMask))
#define CanRxActualStdId(rxStruct)              ((vuint16)   (((rxStruct)->pChipMsgObj->Id) & kCanStdIdMask))
#define CanRxActualData(rxStruct, i)            ((vuint8)     ((rxStruct)->pChipData[i]))
#define CanRxActualDLC(rxStruct)                CAN_DLC2LEN(CanRegToActualDLC((rxStruct)->pChipMsgObj->Dlc))
#if defined(C_ENABLE_CAN_FD_USED)
#define CanRxActualFdType(rxStruct)            ((tCanFdType)(((rxStruct)->pChipMsgObj->Fd) & kCanFdTypeFd))
#endif

#define CanTxActualIdType(txConfStruct)         CanRxActualIdType(txConfStruct)
#define CanTxActualExtId(txConfStruct)          CanRxActualExtId(txConfStruct)
#define CanTxActualStdId(txConfStruct)          CanRxActualStdId(txConfStruct)
#define CanTxActualData(txConfStruct, i)        CanRxActualData((txConfStruct), (i))
#define CanTxActualDLC(txConfStruct)            CanRxActualDLC(txConfStruct)
#if defined(C_ENABLE_CAN_FD_USED)
#define CanTxActualFdType(txConfStruct)        CanRxActualFdType(txConfStruct)
#endif

#if defined(C_MULTIPLE_RECEIVE_CHANNEL)
#define CanRxActualErrorCounter(ch)            ((vuint8) ((Can->ChCtrl[mCanLogToPhys(ch)].SR & kCanRecMask) >> 16))
#define CanTxActualErrorCounter(ch)            ((vuint8) ((Can->ChCtrl[mCanLogToPhys(ch)].SR & kCanTecMask) >> 24))
#else
#define CanRxActualErrorCounter()              ((vuint8) ((Can->ChCtrl[mCanLogToPhys(0)].SR & kCanRecMask) >> 16))
#define CanTxActualErrorCounter()              ((vuint8) ((Can->ChCtrl[mCanLogToPhys(0)].SR & kCanTecMask) >> 24))
#endif

#if defined( C_ENABLE_CAN_FD_USED )
#define CanTxWriteActId(txStruct, id)          { ((txStruct).pChipMsgObj->Id) = MK_STDID0(id); ((txStruct).pChipMsgObj->Fd) = kCanFdTypeClassic | kCanFdBrsTypeFalse; }
#if defined(C_ENABLE_EXTENDED_ID)
#define CanTxWriteActExtId(txStruct, id)      { ((txStruct).pChipMsgObj->Id) = MK_EXTID0(id); ((txStruct).pChipMsgObj->Fd) = kCanFdTypeClassic | kCanFdBrsTypeFalse; }
#endif
#define CanTxWriteActFdId(txStruct, id)       { ((txStruct).pChipMsgObj->Id) = MK_STDID0(id); ((txStruct).pChipMsgObj->Fd) = kCanFdTypeFd | kCanFdBrsTypeTrue; }
#if defined(C_ENABLE_EXTENDED_ID)
#define CanTxWriteActFdExtId(txStruct, id)   { ((txStruct).pChipMsgObj->Id) = MK_EXTID0(id); ((txStruct).pChipMsgObj->Fd) = kCanFdTypeFd | kCanFdBrsTypeTrue; }
#endif
#else
#define CanTxWriteActId(txStruct, id)          { ((txStruct).pChipMsgObj->Id) = MK_STDID0(id); }
#if defined(C_ENABLE_EXTENDED_ID)
#define CanTxWriteActExtId(txStruct, id)      { ((txStruct).pChipMsgObj->Id) = MK_EXTID0(id); }
#endif
#endif
#define CanTxWriteActDLC(txStruct, len)         { ((txStruct).pChipMsgObj->Dlc) = CanActualDLCToReg(CAN_LEN2DLC(len)); }

#define CAN_HL_MIN(x, y) (((x)>(y)) ? (y) : (x))
#define CAN_HL_MAX(x, y) (((x)<(y)) ? (y) : (x))

#if !defined(CAN_DUMMY_STATEMENT)
#if defined(V_ENABLE_USE_DUMMY_STATEMENT)
#define CAN_DUMMY_STATEMENT(x) (x) = (x)
#else
#define CAN_DUMMY_STATEMENT(x)
#endif
#endif
#if !defined(CAN_DUMMY_STATEMENT_CONST)
#if defined(V_ENABLE_USE_DUMMY_STATEMENT)
#define CAN_DUMMY_STATEMENT_CONST(x) (void)(x)
#else
#define CAN_DUMMY_STATEMENT_CONST(x)
#endif
#endif

#if(CAN_DEV_ERROR_REPORT == STD_ON)

#define Can_CallDetReportError(api, err) ((void) Det_ReportError(CAN_MODULE_ID, CAN_INSTANCE_ID, (api), (err)))
#define assertHardware(a, b, c)  if(!(a)) {Can_CallDetReportError(CAN_HW_ACCESS_ID, (c));}
#define assertInternal(a, b, c)  if(!(a)) {Can_CallDetReportError(CAN_HW_ACCESS_ID, (c));}
#define assertUser(a, b, c)      if(!(a)) {Can_CallDetReportError(CAN_HW_ACCESS_ID, (c));}
#define assertGen(a, b, c)       if(!(a)) {Can_CallDetReportError(CAN_HW_ACCESS_ID, (c));}
#define C_ENABLE_HARDWARE_CHECK
#define C_ENABLE_INTERNAL_CHECK
#define C_ENABLE_USER_CHECK
#define C_ENABLE_GEN_CHECK
#else
#define Can_CallDetReportError(api, err)
#define assertHardware(a, b, c)
#define assertInternal(a, b, c)
#define assertUser(a, b, c)
#define assertGen(a, b, c)
#endif

#define CanDeclareGlobalInterruptOldStatus

#define CanSingleGlobalInterruptDisable()     SchM_Enter_Can_CAN_EXCLUSIVE_AREA_0()
#define CanSingleGlobalInterruptRestore()     SchM_Exit_Can_CAN_EXCLUSIVE_AREA_0()
#define CanGlobalInterruptDisable()           SchM_Enter_Can_CAN_EXCLUSIVE_AREA_0()
#define CanGlobalInterruptRestore()           SchM_Exit_Can_CAN_EXCLUSIVE_AREA_0()
#define CanNestedGlobalInterruptDisable()     SchM_Enter_Can_CAN_EXCLUSIVE_AREA_0()
#define CanNestedGlobalInterruptRestore()     SchM_Exit_Can_CAN_EXCLUSIVE_AREA_0()

#if defined(C_ENABLE_SLEEP_WAKEUP)
#define APPL_CAN_WAKEUP(ch)   (CanHL_WakeUpHandling( CAN_CHANNEL_CANPARA_ONLY ))
#define CAN_WAKEUP(ch)              ((void) Can_SetControllerMode((uint8)(ch), CAN_T_WAKEUP))
#endif

#define kCanMaxPhysChannelsCell         8u
#define kCanMaxRxFifosCell              8u
#define kCanMaxTxFifosCell              3u
#define kCanMaxRxBufCell                128u
#define kCanNumberOfSharedReg8Cell      2u
#define kCanNumberOfSharedReg16Cell     4u
#if defined(C_ENABLE_IF_RSCAN_FD_V3)
#define kCanMaxTxBufCell               32u
#define kCanNumberOfSharedRegTxCell    8u
#define kCanTxSize                     vuint32
#else
#define kCanMaxTxBufCell               16u
#define kCanNumberOfSharedRegTxCell    4u
#define kCanTxSize                     vuint16
#endif
#define kCanMaxRuleAccessCell           16u
#define kCanMaxRamTestAccessCell        64u
#define kCanRegSize                     vuint32
#define kCanRegSizeCast                 kCanRegSize

#define pBufRm(idx)                     (tCanBufPtr)&(Can->BufRm[idx])
#define pBufRf(idx)                     (tCanBufPtr)&(Can->BufRf[idx])
#define pBufCf(pch, idx)                (tCanBufPtr)&(Can->BufCfCh[pch].BufCf[idx])
#define pBufTm(pch, idx)                (tCanBufPtr)&(Can->BufTmCh[pch].BufTm[idx])
#define mTHAR0(idx)                     Can->THA[idx].THAR0
#define mTHAR1(idx)                     Can->THA[idx].THAR1
#define mRuleCode(idx)                  Can->Rule[idx].Code
#define mRuleMask(idx)                  Can->Rule[idx].Mask
#define mRuleBuf(idx)                   Can->Rule[idx].Buf
#define mRuleFifo(idx)                  Can->Rule[idx].Fifo
#define mCRAMTR(idx)                    Can->CRAMTR[idx]

typedef volatile struct{
  volatile vuint32      BCFG;
  volatile vuint32      CR;
  volatile vuint32      SR;
  volatile vuint16      EF;
  volatile vuint16      CRC;
}tCanChCtrl;

#if defined(C_ENABLE_RSCAN_FD_LAYOUT)
typedef volatile struct{
  volatile vuint32      BCFG;
  volatile vuint32      FDCFG;
  volatile vuint32      CR;
  volatile vuint32      SR;
  volatile vuint32      CRC;
  volatile vuint32      Unused04[3];
}tCanChCtrlFd;
#endif

typedef volatile struct{
  volatile vuint32      TRFCR[kCanMaxTxFifosCell];
}tCanChFC;

typedef volatile struct{
  volatile kCanRegSize  TRFSR[kCanMaxTxFifosCell];
}tCanChFS;

typedef volatile struct{
  volatile kCanRegSize  TRFPCR[kCanMaxTxFifosCell];
}tCanChFPC;

typedef volatile struct{
  volatile vuint8       TBCR[kCanMaxTxBufCell];
}tCanChBC;

typedef volatile struct{
  volatile vuint8       TBSR[kCanMaxTxBufCell];
}tCanChBS;

typedef volatile struct{
  volatile vuint32      Code;
  volatile vuint32      Mask;
  volatile vuint32      Buf;
  volatile vuint32      Fifo;
}tCanRule;

typedef volatile struct{
#if defined(C_ENABLE_IF_RSCAN_FD_V3)
  volatile kCanRegSize  THAR0;
  volatile kCanRegSize  THAR1;
#else
  volatile kCanRegSize  THAR0;
#endif
}tCanTHA;

#if defined(C_ENABLE_RSCAN_FD_LAYOUT)
typedef volatile struct{
  volatile vuint32      Id;
  volatile vuint32      Dlc;
  volatile vuint32      Fd;
  union
  {
    volatile vuint8     bData[64];
    volatile vuint16    wData[32];
    volatile vuint32    iData[16];
  } u;
  volatile vuint32      Unused07[13];
}tCanMsgObj64;

#if defined(C_ENABLE_IF_RSCAN_FD)
typedef volatile struct{
  volatile vuint32      Id;
  volatile vuint32      Dlc;
  volatile vuint32      Fd;
  union
  {
    volatile vuint8     bData[20];
    volatile vuint16    wData[10];
    volatile vuint32    iData[5];
  } u;
}tCanMsgObj20;

typedef volatile struct{
  tCanMsgObj20          BufTm[kCanMaxTxBufCell];
}tCanBufTm;
#else
typedef volatile struct{
  tCanMsgObj64          BufTm[kCanMaxTxBufCell];
}tCanBufTm;
#endif

typedef volatile struct{
  tCanMsgObj64          BufCf[kCanMaxTxFifosCell];
}tCanBufCf;
#else
typedef volatile struct{
  volatile vuint32      Id;
  volatile kCanRegSize  Dlc;
  union
  {
    volatile vuint8     bData[8];
    volatile vuint16    wData[4];
    volatile vuint32    iData[2];
  } u;
}tCanMsgObj8;

typedef volatile struct{
  tCanMsgObj8           BufCf[kCanMaxTxFifosCell];
}tCanBufCf;

typedef volatile struct{
  tCanMsgObj8           BufTm[kCanMaxTxBufCell];
}tCanBufTm;
#endif

typedef volatile struct{

  tCanChCtrl            ChCtrl[kCanMaxPhysChannelsCell];
  volatile kCanRegSize  Unused01[1];
  volatile vuint32      CGCFG;
  volatile vuint32      CGCR;
  volatile kCanRegSize  CGSR;
  volatile kCanRegSize  CGEF;
  volatile kCanRegSize  CTS;

  volatile kCanRegSize  CRECR;
  volatile kCanRegSize  CRNCFG[kCanNumberOfSharedReg8Cell];

  volatile kCanRegSize  CRBNUM;
  volatile kCanRegSize  CRBRCF[kCanNumberOfSharedReg16Cell];

  volatile kCanRegSize  CRFCR[kCanMaxRxFifosCell];
  volatile kCanRegSize  CRFSR[kCanMaxRxFifosCell];
  volatile kCanRegSize  CRFPCR[kCanMaxRxFifosCell];
  tCanChFC              ChFC[kCanMaxPhysChannelsCell];
  tCanChFS              ChFS[kCanMaxPhysChannelsCell];
  tCanChFPC             ChFPC[kCanMaxPhysChannelsCell];
  volatile kCanRegSize  CFESR;
  volatile kCanRegSize  CFFSR;
  volatile kCanRegSize  CFMLSR;
  volatile kCanRegSize  CRFISR;
  volatile kCanRegSize  CTRFRISR;
  volatile kCanRegSize  CTRFTISR;

  tCanChBC              ChBC[kCanMaxPhysChannelsCell];
  tCanChBS              ChBS[kCanMaxPhysChannelsCell];
  volatile kCanRegSize  CTBTRSR[kCanNumberOfSharedRegTxCell];
  volatile kCanRegSize  CTBARSR[kCanNumberOfSharedRegTxCell];
  volatile kCanRegSize  CTBTCSR[kCanNumberOfSharedRegTxCell];
  volatile kCanRegSize  CTBASR[kCanNumberOfSharedRegTxCell];
  volatile kCanRegSize  CTBIER[kCanNumberOfSharedRegTxCell];
#if defined(C_ENABLE_IF_RSCAN_FD_V3)
  volatile vuint32      Unused0x[24];
#endif

  volatile kCanRegSize  TQCR[kCanMaxPhysChannelsCell];
  volatile kCanRegSize  TQSR[kCanMaxPhysChannelsCell];
  volatile kCanRegSize  TQPCR[kCanMaxPhysChannelsCell];

  volatile kCanRegSize  THCR[kCanMaxPhysChannelsCell];
  volatile kCanRegSize  THSR[kCanMaxPhysChannelsCell];
  volatile kCanRegSize  THPCR[kCanMaxPhysChannelsCell];

  volatile kCanRegSize  CGTINTSTS[kCanNumberOfSharedReg8Cell];
  volatile kCanRegSize  CGTCFG;
  volatile kCanRegSize  CGTCR;
#if defined(C_ENABLE_RSCAN_FD_LAYOUT)
  volatile kCanRegSize  Unused02;

  volatile kCanRegSize  CGFDCFG;
  volatile kCanRegSize  CGCRCCFG;
#else
  volatile kCanRegSize  Unused02[3];
#endif
  volatile kCanRegSize  CGTPUR;
#if defined(C_ENABLE_IF_RSCAN)
  volatile kCanRegSize  Unused03[32];
#endif
#if defined(C_ENABLE_IF_RSCAN_FD)
  volatile kCanRegSize  Unused03[31];
  volatile kCanRegSize  CGRMCFG;
#endif
#if defined(C_ENABLE_IF_RSCAN_FD_V3)
  volatile kCanRegSize  Unused03[52];
#endif
#if defined(C_ENABLE_RSCAN_FD_LAYOUT)

  tCanChCtrlFd          ChCtrlFd[kCanMaxPhysChannelsCell];
#if defined(C_ENABLE_IF_RSCAN_FD_V3)
  volatile vuint32      Unused05[512];

  tCanRule              Rule[kCanMaxRuleAccessCell];
  volatile vuint32      Unused06[960];

  tCanMsgObj64          BufRm[kCanMaxRxBufCell];
  tCanMsgObj64          BufRf[kCanMaxRxFifosCell];
  tCanBufCf             BufCfCh[kCanMaxPhysChannelsCell];
  volatile vuint32      Unused08[1024];
  tCanBufTm             BufTmCh[kCanMaxPhysChannelsCell];
  tCanTHA               THA[kCanMaxPhysChannelsCell];
  volatile vuint32      Unused09[240];
#else
  volatile vuint32      Unused05[640];

  tCanRule              Rule[kCanMaxRuleAccessCell];
  volatile vuint32      Unused06[960];

  tCanMsgObj20          BufRm[kCanMaxRxBufCell];
  tCanMsgObj64          BufRf[kCanMaxRxFifosCell];
  tCanBufCf             BufCfCh[kCanMaxPhysChannelsCell];
  tCanBufTm             BufTmCh[kCanMaxPhysChannelsCell];
  volatile vuint32      Unused08[1024];
  tCanTHA               THA[kCanMaxPhysChannelsCell];
  volatile vuint32      Unused09[248];
#endif
#else

  tCanRule              Rule[kCanMaxRuleAccessCell];

  tCanMsgObj8           BufRm[kCanMaxRxBufCell];
  tCanMsgObj8           BufRf[kCanMaxRxFifosCell];
  tCanBufCf             BufCfCh[kCanMaxPhysChannelsCell];
  tCanBufTm             BufTmCh[kCanMaxPhysChannelsCell];
  tCanTHA               THA[kCanMaxPhysChannelsCell];
  volatile kCanRegSize  Unused04[56];
#endif

  volatile vuint32      CRAMTR[kCanMaxRamTestAccessCell];
}tCanCell;

V_DEF_P2SFR_CAN_TYPE(V_NONE, tCanCell) tCanCellPtr;
#define Can ((tCanCellPtr) CAN_CAST_ADDR(kCanBaseAdr))

#if defined(C_ENABLE_RSCAN_FD_LAYOUT)
V_DEF_P2SFR_CAN_TYPE(V_NONE, tCanMsgObj64) tCanBufPtr;
#if(CAN_SAFE_BSW == STD_ON)
V_DEF_VAR_TYPE(V_NONE, tCanMsgObj64) tCanDummyBuf;
#endif
#else
V_DEF_P2SFR_CAN_TYPE(V_NONE, tCanMsgObj8) tCanBufPtr;
#if(CAN_SAFE_BSW == STD_ON)
V_DEF_VAR_TYPE(V_NONE, tCanMsgObj8) tCanDummyBuf;
#endif
#endif

#if defined(C_ENABLE_LL_CAN_INTCTRL)
#if defined(C_ENABLE_INDIVIDUAL_POLLING) || !defined(C_ENABLE_TX_POLLING)
typedef volatile struct{
  volatile vuint8       Tx;
  volatile vuint8       uTx;
}tCanIntcChTxObj;

V_DEF_P2SFR_CAN_TYPE(V_NONE, tCanIntcChTxObj) tCanIntcChTxPtr;
#endif

#if !defined(C_ENABLE_ERROR_POLLING)
typedef volatile struct{
  volatile vuint8       Err;
  volatile vuint8       uErr;
}tCanIntcChErrObj;

V_DEF_P2SFR_CAN_TYPE(V_NONE, tCanIntcChErrObj) tCanIntcChErrPtr;
#endif

#if((defined(C_ENABLE_INDIVIDUAL_POLLING) || !defined(C_ENABLE_RX_BASICCAN_POLLING)) && defined(C_ENABLE_RX_BASICCAN_OBJECTS))
typedef volatile struct{
  volatile vuint8       RF;
  volatile vuint8       uRF;
}tCanIntcRxFifoObj;

V_DEF_P2SFR_CAN_TYPE(V_NONE, tCanIntcRxFifoObj) tCanIntcRxFifoPtr;
#define CanIntcRxFifo ((tCanIntcRxFifoPtr) CAN_CAST_ADDR(kCanIntcRxFifoBaseAdr))
#endif

#if(!defined(C_ENABLE_ERROR_POLLING) && defined(C_ENABLE_OVERRUN) && defined(C_ENABLE_RX_BASICCAN_OBJECTS))
typedef volatile struct{
  volatile vuint8       GErr;
  volatile vuint8       uGErr;
}tCanIntcGErrObj;

V_DEF_P2SFR_CAN_TYPE(V_NONE, tCanIntcGErrObj) tCanIntcGErrPtr;
#define CanIntcGErr ((tCanIntcGErrPtr) CAN_CAST_ADDR(kCanIntcGErrorBaseAdr))
#endif
#endif

#if defined(C_ENABLE_LL_WAKEUP_SUPPORT)
#if(defined(C_ENABLE_LL_CAN_WAKEUP_INTCTRL) || (defined(C_ENABLE_WAKEUP_POLLING) && !defined(C_ENABLE_LL_CAN_WAKEUP_INTCB)))
typedef volatile struct{
  volatile vuint8       Wup;
  volatile vuint8       uWup;
}tCanIntcChWupObj;

V_DEF_P2SFR_CAN_TYPE(V_NONE, tCanIntcChWupObj) tCanIntcChWupPtr;
#endif
#endif

#if defined( C_ENABLE_RX_FULLCAN_OBJECTS )
#if( kCanNumberOfUsedCanRxIdTables > 4 )
#define SET_PARASTRUCT_IDRAW_RX_STD(paraStruct, id) \
                                   (paraStruct)->idRaw0 = MK_STDID0(id); \
                                   (paraStruct)->idRaw1 = MK_STDID1(id); \
                                   (paraStruct)->idRaw2 = MK_STDID2(id); \
                                   (paraStruct)->idRaw3 = MK_STDID3(id); \
                                   (paraStruct)->idRaw4 = MK_STDID4(id)
#define SET_PARASTRUCT_IDRAW_RX_EXT(paraStruct, id) \
                                   (paraStruct)->idRaw0 = MK_EXTID0(id); \
                                   (paraStruct)->idRaw1 = MK_EXTID1(id); \
                                   (paraStruct)->idRaw2 = MK_EXTID2(id); \
                                   (paraStruct)->idRaw3 = MK_EXTID3(id); \
                                   (paraStruct)->idRaw4 = MK_EXTID4(id)
# elif( kCanNumberOfUsedCanRxIdTables > 3 )
#define SET_PARASTRUCT_IDRAW_RX_STD(paraStruct, id) \
                                   (paraStruct)->idRaw0 = MK_STDID0(id); \
                                   (paraStruct)->idRaw1 = MK_STDID1(id); \
                                   (paraStruct)->idRaw2 = MK_STDID2(id); \
                                   (paraStruct)->idRaw3 = MK_STDID3(id)
#define SET_PARASTRUCT_IDRAW_RX_EXT(paraStruct, id) \
                                   (paraStruct)->idRaw0 = MK_EXTID0(id); \
                                   (paraStruct)->idRaw1 = MK_EXTID1(id); \
                                   (paraStruct)->idRaw2 = MK_EXTID2(id); \
                                   (paraStruct)->idRaw3 = MK_EXTID3(id)
# elif( kCanNumberOfUsedCanRxIdTables > 2 )
#define SET_PARASTRUCT_IDRAW_RX_STD(paraStruct, id) \
                                   (paraStruct)->idRaw0 = MK_STDID0(id); \
                                   (paraStruct)->idRaw1 = MK_STDID1(id); \
                                   (paraStruct)->idRaw2 = MK_STDID2(id)
#define SET_PARASTRUCT_IDRAW_RX_EXT(paraStruct, id) \
                                   (paraStruct)->idRaw0 = MK_EXTID0(id); \
                                   (paraStruct)->idRaw1 = MK_EXTID1(id); \
                                   (paraStruct)->idRaw2 = MK_EXTID2(id)
# elif( kCanNumberOfUsedCanRxIdTables > 1 )
#define SET_PARASTRUCT_IDRAW_RX_STD(paraStruct, id) \
                                   (paraStruct)->idRaw0 = MK_STDID0(id); \
                                   (paraStruct)->idRaw1 = MK_STDID1(id)
#define SET_PARASTRUCT_IDRAW_RX_EXT(paraStruct, id) \
                                   (paraStruct)->idRaw0 = MK_EXTID0(id); \
                                   (paraStruct)->idRaw1 = MK_EXTID1(id)
#else
#define SET_PARASTRUCT_IDRAW_RX_STD(paraStruct, id) \
                                   (paraStruct)->idRaw0 = MK_STDID0(id)
#define SET_PARASTRUCT_IDRAW_RX_EXT(paraStruct, id) \
                                   (paraStruct)->idRaw0 = MK_EXTID0(id)
#endif
#endif

#if( kCanNumberOfUsedCanTxIdTables > 4 )
#define SET_PARASTRUCT_IDRAW_TX_STD(paraStruct, id) \
                                   (paraStruct)->idRaw0 = MK_STDID0(id); \
                                   (paraStruct)->idRaw1 = MK_STDID1(id); \
                                   (paraStruct)->idRaw2 = MK_STDID2(id); \
                                   (paraStruct)->idRaw3 = MK_STDID3(id); \
                                   (paraStruct)->idRaw4 = MK_STDID4(id)
#define SET_PARASTRUCT_IDRAW_TX_EXT(paraStruct, id) \
                                   (paraStruct)->idRaw0 = MK_EXTID0(id); \
                                   (paraStruct)->idRaw1 = MK_EXTID1(id); \
                                   (paraStruct)->idRaw2 = MK_EXTID2(id); \
                                   (paraStruct)->idRaw3 = MK_EXTID3(id); \
                                   (paraStruct)->idRaw4 = MK_EXTID4(id)
#elif( kCanNumberOfUsedCanTxIdTables > 3 )
#define SET_PARASTRUCT_IDRAW_TX_STD(paraStruct, id) \
                                   (paraStruct)->idRaw0 = MK_STDID0(id); \
                                   (paraStruct)->idRaw1 = MK_STDID1(id); \
                                   (paraStruct)->idRaw2 = MK_STDID2(id); \
                                   (paraStruct)->idRaw3 = MK_STDID3(id)
#define SET_PARASTRUCT_IDRAW_TX_EXT(paraStruct, id) \
                                   (paraStruct)->idRaw0 = MK_EXTID0(id); \
                                   (paraStruct)->idRaw1 = MK_EXTID1(id); \
                                   (paraStruct)->idRaw2 = MK_EXTID2(id); \
                                   (paraStruct)->idRaw3 = MK_EXTID3(id)
#elif( kCanNumberOfUsedCanTxIdTables > 2 )
#define SET_PARASTRUCT_IDRAW_TX_STD(paraStruct, id) \
                                   (paraStruct)->idRaw0 = MK_STDID0(id); \
                                   (paraStruct)->idRaw1 = MK_STDID1(id); \
                                   (paraStruct)->idRaw2 = MK_STDID2(id)
#define SET_PARASTRUCT_IDRAW_TX_EXT(paraStruct, id) \
                                   (paraStruct)->idRaw0 = MK_EXTID0(id); \
                                   (paraStruct)->idRaw1 = MK_EXTID1(id); \
                                   (paraStruct)->idRaw2 = MK_EXTID2(id)
#elif( kCanNumberOfUsedCanTxIdTables > 1 )
#define SET_PARASTRUCT_IDRAW_TX_STD(paraStruct, id) \
                                   (paraStruct)->idRaw0 = MK_STDID0(id); \
                                   (paraStruct)->idRaw1 = MK_STDID1(id)
#define SET_PARASTRUCT_IDRAW_TX_EXT(paraStruct, id) \
                                   (paraStruct)->idRaw0 = MK_EXTID0(id); \
                                   (paraStruct)->idRaw1 = MK_EXTID1(id)
#else
#define SET_PARASTRUCT_IDRAW_TX_STD(paraStruct, id) \
                                   (paraStruct)->idRaw0 = MK_STDID0(id)
#define SET_PARASTRUCT_IDRAW_TX_EXT(paraStruct, id) \
                                   (paraStruct)->idRaw0 = MK_EXTID0(id)
#endif

typedef struct sCanRxInfostruct{
  CanChipMsgPtr     pChipMsgObj;
  CanChipDataPtr    pChipData;
  CanObjectHandle   localMailboxHandle;
  Can_IdType               localId;
  uint8                    localDlc;

}tCanRxInfoStruct;
V_DEF_P2VAR_TYPE(V_NONE, tCanRxInfoStruct, VAR_NOINIT) CanRxInfoStructPtr;

typedef struct sCanTxConfInfostruct{
  CanChipMsgPtr     pChipMsgObj;
  CanChipDataPtr    pChipData;

}tCanTxConfInfoStruct;
V_DEF_P2VAR_TYPE(V_NONE, tCanTxConfInfoStruct, VAR_NOINIT) CanTxConfInfoStructPtr;

typedef struct sCanInitParastruct{
  CanInitHandle     initObject;
  CanObjectHandle   mailboxHandle;
  CanObjectHandle   hwObjHandle;
#if defined( C_ENABLE_RX_FULLCAN_OBJECTS )
  tCanRxId0                idRaw0;
#if( kCanNumberOfUsedCanRxIdTables > 1 )
  tCanRxId1                idRaw1;
#endif
#if( kCanNumberOfUsedCanRxIdTables > 2 )
  tCanRxId2                idRaw2;
#endif
#if( kCanNumberOfUsedCanRxIdTables > 3 )
  tCanRxId3                idRaw3;
#endif
#if( kCanNumberOfUsedCanRxIdTables > 4 )
  tCanRxId4                idRaw4;
#endif
  tCanIdType               idType;
#endif
#if defined(C_ENABLE_CAN_RAM_CHECK)
  uint8                    doRamCheck;
#if defined(C_ENABLE_CAN_RAM_CHECK_EXTENDED)
  uint8                    isChRamCheckFail;
#endif
#endif
  uint8                    isInitOk;

}tCanInitParaStruct;
V_DEF_P2VAR_TYPE(V_NONE, tCanInitParaStruct, VAR_NOINIT) CanInitParaStructPtr;

#define TxDataPtr Can_SduPtrType
typedef struct sCanTxTransmissionParastruct{

  CanObjectHandle   mailboxHandle;
  CanObjectHandle   mailboxElement;
  CanObjectHandle   hwObjHandle;
  CanObjectHandle   activeSendObject;
  tCanTxId0                idRaw0;
#if( kCanNumberOfUsedCanTxIdTables > 1 )
  tCanTxId1                idRaw1;
#endif
#if( kCanNumberOfUsedCanTxIdTables > 2 )
  tCanTxId2                idRaw2;
#endif
#if( kCanNumberOfUsedCanTxIdTables > 3 )
  tCanTxId3                idRaw3;
#endif
#if( kCanNumberOfUsedCanTxIdTables > 4 )
  tCanTxId4                idRaw4;
#endif
  tCanDlc                  dlcRaw;
  TxDataPtr                CanMemCopySrcPtr;
#if defined( C_ENABLE_CAN_FD_USED )
  tCanFdType               fdType;
  tCanFdBrsType            fdBrsType;
  uint8                    messageLen;
  uint8                    frameLen;
  uint8                    paddingVal;
#endif
  Can_PduType              pdu;

  tCanBufPtr               Buf;
}tCanTxTransmissionParaStruct;
V_DEF_P2VAR_TYPE(V_NONE, tCanTxTransmissionParaStruct, VAR_NOINIT) CanTxTransmissionParaStructPtr;

typedef struct sCanRxBasicParastruct{
  CanObjectHandle   mailboxHandle;
  CanObjectHandle   hwObjHandle;
#if !defined( C_HL_ENABLE_OVERRUN_IN_STATUS ) && defined( C_ENABLE_OVERRUN )
#endif
  tCanRxInfoStruct         rxStruct;

}tCanRxBasicParaStruct;
V_DEF_P2VAR_TYPE(V_NONE, tCanRxBasicParaStruct, VAR_NOINIT) CanRxBasicParaStructPtr;

typedef struct sCanRxFullParastruct{
  CanObjectHandle   mailboxHandle;
  CanObjectHandle   hwObjHandle;
  tCanRxInfoStruct         rxStruct;

}tCanRxFullParaStruct;
V_DEF_P2VAR_TYPE(V_NONE, tCanRxFullParaStruct, VAR_NOINIT) CanRxFullParaStructPtr;

#if defined( C_ENABLE_CANCEL_IN_HW ) || defined( C_ENABLE_CANCEL_SUPPORT_API )
typedef struct{
  CanObjectHandle   mailboxHandle;
  CanObjectHandle   mailboxElement;
  CanObjectHandle   hwObjHandle;
  CanObjectHandle   activeSendObject;
  CanTransmitHandle   canHandleCurTxObj;
}tCanTxCancellationParaStruct;
V_DEF_P2VAR_TYPE(V_NONE, tCanTxCancellationParaStruct, VAR_NOINIT) CanTxCancellationParaStructPtr;
#endif

typedef struct{
  CanObjectHandle   mailboxHandle;
  CanObjectHandle   mailboxElement;
  CanObjectHandle   hwObjHandle;
  CanObjectHandle   activeSendObject;
#if defined(CAN_ENABLE_GENERIC_CONFIRMATION_API2)
  CanTxConfInfoStructPtr   txStructConf;
#endif
#if defined( C_ENABLE_CANCEL_IN_HW )
  vuint8                   txBufferStatus;
#endif
}tCanTxConfirmationParaStruct;
V_DEF_P2VAR_TYPE(V_NONE, tCanTxConfirmationParaStruct, VAR_NOINIT) CanTxConfirmationParaStructPtr;

typedef struct sCanTaskParastruct{
  CanObjectHandle mailboxHandle;
  CanObjectHandle hwObjHandle;

}tCanTaskParaStruct;
V_DEF_P2VAR_TYPE(V_NONE, tCanTaskParaStruct, VAR_NOINIT) CanTaskParaStructPtr;

#define CAN_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.hpp"

#define CAN_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.hpp"

#define CAN_START_SEC_STATIC_CODE
#include "MemMap.hpp"

V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_InitBegin( CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanInitParaStructPtr initPara );

#if defined( C_ENABLE_CAN_RAM_CHECK_EXTENDED )

V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_InitBeginIsRegisterCorrupt( CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanInitParaStructPtr initPara );

#endif

V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_InitBeginSetRegisters( CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanInitParaStructPtr initPara );

V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_InitMailboxTx( CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanInitParaStructPtr initPara );

#if(defined( C_ENABLE_CAN_RAM_CHECK ))

V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_InitMailboxTxDeactivate( CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanInitParaStructPtr initPara );

#endif

#if defined( C_ENABLE_RX_FULLCAN_OBJECTS )

V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_InitMailboxRxFullCan( CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanInitParaStructPtr initPara );

#endif

#if defined( C_ENABLE_RX_BASICCAN_OBJECTS )

V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_InitMailboxRxBasicCan( CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanInitParaStructPtr initPara );

#endif

V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_InitEndSetRegisters( CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanInitParaStructPtr initPara );

V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_InitEnd( CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanInitParaStructPtr initPara );

#if defined( C_ENABLE_CAN_RAM_CHECK )

V_DEF_FUNC(CAN_STATIC, vuint8, STATIC_CODE) CanLL_InitIsMailboxCorrupt( CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanInitParaStructPtr initPara );

#endif

V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_InitPowerOn(void);

V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_InitPowerOnChannelSpecific( CAN_CHANNEL_CANTYPE_ONLY );

V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_InitMemoryPowerOn(void);

#if defined( C_ENABLE_CANCEL_IN_HW )

V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_TxCancelInHw(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanTxCancellationParaStructPtr txCancellationPara);

#endif

V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_TxBegin(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanTxTransmissionParaStructPtr txPara);

V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_TxSetMailbox(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanTxTransmissionParaStructPtr txPara);

V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_TxCopyToCan(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanTxTransmissionParaStructPtr txPara);

V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_TxStart(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanTxTransmissionParaStructPtr txPara);

V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_TxEnd(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanTxTransmissionParaStructPtr txPara);

#if defined( C_ENABLE_TX_POLLING )

V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_TxIsGlobalConfPending(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_ONLY);

V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_TxProcessPendings(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanTaskParaStructPtr taskPara);

#endif

V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_TxConfBegin(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanTxConfirmationParaStructPtr txConfPara);

#if defined( C_ENABLE_CANCEL_IN_HW )

V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_TxConfIsMsgTransmitted(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanTxConfirmationParaStructPtr txConfPara);

#endif

#if defined(CAN_ENABLE_GENERIC_CONFIRMATION_API2)

V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_TxConfSetTxConfStruct(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanTxConfirmationParaStructPtr txConfPara);

#endif

V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_TxConfEnd(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanTxConfirmationParaStructPtr txConfPara);

#if defined( C_ENABLE_RX_BASICCAN_OBJECTS )

V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_RxBasicMsgReceivedBegin(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanRxBasicParaStructPtr rxBasicPara);

V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_RxBasicReleaseObj(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanRxBasicParaStructPtr rxBasicPara);

V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_RxBasicMsgReceivedEnd(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanRxBasicParaStructPtr rxBasicPara);

#if defined( C_ENABLE_RX_BASICCAN_POLLING )

V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_RxBasicIsGlobalIndPending(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_ONLY);

V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_RxBasicProcessPendings(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanTaskParaStructPtr taskPara);

#endif
#endif

#if defined( C_ENABLE_RX_FULLCAN_OBJECTS )

V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_RxFullMsgReceivedBegin(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanRxFullParaStructPtr rxFullPara);

V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_RxFullReleaseObj(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanRxFullParaStructPtr rxFullPara);

V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_RxFullMsgReceivedEnd(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanRxFullParaStructPtr rxFullPara);

V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_RxFullIsGlobalIndPending(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_ONLY);

V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_RxFullProcessPendings(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanTaskParaStructPtr taskPara);

#endif

V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_ErrorHandlingBegin(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_ONLY);

V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_BusOffOccured(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_ONLY);

#if defined( C_ENABLE_OVERRUN ) && defined( C_ENABLE_RX_BASICCAN_OBJECTS )

V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_RxBasicCanOverrun(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_ONLY);

#endif

V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_ErrorHandlingEnd(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_ONLY);

#if defined( C_ENABLE_EXTENDED_STATUS )

V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_GetStatusBegin(CAN_CHANNEL_CANTYPE_ONLY);

#endif

#if defined( C_ENABLE_SLEEP_WAKEUP ) && defined( C_ENABLE_WAKEUP_POLLING )

V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_WakeUpOccured(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_ONLY);

#endif

#if defined( C_ENABLE_SLEEP_WAKEUP )

V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_WakeUpHandling(CAN_CHANNEL_CANTYPE_ONLY);

#endif

V_DEF_FUNC(CAN_STATIC, vuint8, STATIC_CODE) CanLL_ModeTransition(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST vuint8 mode, vuint8 busOffRecovery, vuint8 ramCheck);

#if defined( C_ENABLE_CAN_CAN_INTERRUPT_CONTROL )

V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_CanInterruptDisable(CAN_HW_CHANNEL_CANTYPE_FIRST tCanLLCanIntOldPtr localInterruptOldFlagPtr);

V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_CanInterruptRestore(CAN_HW_CHANNEL_CANTYPE_FIRST tCanLLCanIntOld localInterruptOldFlag);

#endif

#if defined(C_ENABLE_LL_CAN_INTCTRL) && defined(C_ENABLE_LL_WAKEUP_SUPPORT) && !defined(C_ENABLE_WAKEUP_POLLING)

V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_CanWakeupInterruptDisable(CAN_HW_CHANNEL_CANTYPE_FIRST tCanLLCanIntOldPtr localInterruptOldFlagPtr);

V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_CanWakeupInterruptEnable(CAN_HW_CHANNEL_CANTYPE_FIRST tCanLLCanIntOldPtr localInterruptOldFlagPtr);

#endif

#if defined(C_ENABLE_LL_CAN_WAKEUP_INTCTRL) && defined(C_ENABLE_WAKEUP_POLLING)

V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_CanWakeupOccurred(CAN_HW_CHANNEL_CANTYPE_ONLY);

#endif

#if defined(C_ENABLE_LL_CAN_WAKEUP_INTCTRL)

V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_ClearCanWakeupInterruptFlag(CAN_HW_CHANNEL_CANTYPE_ONLY);

#endif

#if !defined(C_ENABLE_INTC_ACCESS_BY_APPL)
#if defined(C_ENABLE_USE_OS_INTERRUPT_CONTROL)
#if defined(C_ENABLE_LL_CAN_INTCTRL)

V_DEF_FUNC(CAN_LOCAL_INLINE, boolean, STATIC_CODE) CanLL_OsIsInterruptSourceEnabled(Can_ExternalISRType IsrId);

V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_OsRestoreInterruptSource(Can_ExternalISRType IsrId, boolean OldFlag);

#endif

#if defined(C_ENABLE_LL_CAN_WAKEUP_INTCTRL) && defined(C_ENABLE_WAKEUP_POLLING)

V_DEF_FUNC(CAN_LOCAL_INLINE, boolean, STATIC_CODE) CanLL_OsIsInterruptPending(Can_ExternalISRType IsrId);

#endif
#endif
#endif

V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_InitPowerOnModeTransitions(void);

V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_InitPowerOnGlobalInit(void);

V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_InitPowerOnRuleAndFifoInit(CAN_CHANNEL_CANTYPE_ONLY);

#if defined(C_ENABLE_RX_FULLCAN_OBJECTS) || defined(C_ENABLE_RX_BASICCAN_OBJECTS)

V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_InitPowerOnRulePageUpdate(CanVarPtr8 canFilterRulesIndexPtr, CanVarPtr8 canFilterRulesPagePtr);

#endif

V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_WriteReg32(CAN_CHANNEL_CANTYPE_FIRST CanChipMsgPtr32 regPtr, vuint32 val, CanInitParaStructPtr initPara);

V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_WriteRegGlobal32(CanChipMsgPtr32 regPtr, vuint32 val);

V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_ModeWait(CAN_CHANNEL_CANTYPE_FIRST CanChannelHandle PhysChannel, vuint8 Mode, vuint8 Loop);

V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_GlobalModeWait(vuint8 Mode, vuint8 Loop);

V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_ChannelTransitionReset(CAN_CHANNEL_CANTYPE_ONLY);

#if defined(C_ENABLE_SLEEP_WAKEUP)

V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_ChannelTransitionSleep(CAN_CHANNEL_CANTYPE_ONLY);

#endif

V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_ChannelTransitionStart(CAN_CHANNEL_CANTYPE_ONLY);

#if defined(C_ENABLE_SILENT_MODE)

V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_ChannelTransitionHalt(CAN_CHANNEL_CANTYPE_ONLY);

#endif

#if defined(C_ENABLE_CAN_RAM_CHECK_EXTENDED)

V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_IsGlobalRegisterCorrupt(void);

#endif

#if(CAN_SAFE_BSW == STD_ON)

V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_CheckGeneratedData(void);

#endif

#if(CAN_HW_LOOP_SUPPORT_API == STD_OFF)

V_DEF_FUNC(CAN_LOCAL_INLINE, Can_ReturnType, STATIC_CODE) ApplCanTimerLoop(CAN_CHANNEL_CANTYPE_FIRST uint8 source);
#endif

V_DEF_FUNC(CAN_LOCAL_INLINE, uint8, STATIC_CODE) CanHL_ModeTransition(CAN_CHANNEL_CANTYPE_FIRST uint8 transitionRequest, uint8 busOffRecovery, uint8 doRamCheck);

V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanHL_NotifyTransition(CAN_CHANNEL_CANTYPE_FIRST uint8 canState, CanIf_ControllerModeType canIfState, uint8 transitionState);

#if defined(C_ENABLE_CANCEL_IN_HW)

V_DEF_FUNC(CAN_LOCAL_INLINE, Can_ReturnType, STATIC_CODE) CanHL_IsHigherCanIdPrio(Can_IdType CanId1, Can_IdType CanId2);
#endif

V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanHL_WritePrepare(CAN_CHANNEL_CANTYPE_FIRST CanTxTransmissionParaStructPtr txPara);

#if defined(C_ENABLE_CANCEL_IN_HW) || \
   (defined(C_ENABLE_TX_HW_FIFO) && defined(CAN_ENABLE_GENERIC_CONFIRMATION_API2) )

V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanHL_WriteSavePduInfo(CanTxTransmissionParaStructPtr txPara);
#endif

#if defined(C_ENABLE_CANCEL_IN_HW)

V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanHL_WritePrepareCancelTx(CAN_CHANNEL_CANTYPE_FIRST CanTxTransmissionParaStructPtr txPara);
#endif

V_DEF_FUNC(CAN_LOCAL_INLINE, Can_ReturnType, STATIC_CODE) CanHL_WriteStart(CAN_CHANNEL_CANTYPE_FIRST CanTxTransmissionParaStructPtr txPara);

V_DEF_FUNC(CAN_LOCAL_INLINE, CanObjectHandle, STATIC_CODE) CanHL_GetActiveSendObject(Can_HwHandleType mailboxHandle, Can_HwHandleType mailboxElement);

#if defined(C_ENABLE_CANCEL_IN_HW) || \
   (defined(C_ENABLE_TX_HW_FIFO) && defined(CAN_ENABLE_GENERIC_CONFIRMATION_API2) )

V_DEF_FUNC(CAN_LOCAL_INLINE, uint16, STATIC_CODE) CanHL_GetActiveSendData(Can_HwHandleType mailboxHandle, uint8 mailboxElement);
#endif

#if defined(C_ENABLE_CAN_RAM_CHECK)

V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanHL_RamCheckMailboxNotification(CAN_CHANNEL_CANTYPE_FIRST CanInitParaStructPtr initPara);
#endif

V_DEF_FUNC(CAN_LOCAL_INLINE, uint8, STATIC_CODE) CanHL_InitBegin(CAN_CHANNEL_CANTYPE_FIRST CanInitParaStructPtr initPara);

#if defined(C_ENABLE_TX_FULLCAN_OBJECTS)

V_DEF_FUNC(CAN_LOCAL_INLINE, uint8, STATIC_CODE) CanHL_InitTxFullCAN(CAN_CHANNEL_CANTYPE_FIRST CanInitParaStructPtr initPara);
#endif

V_DEF_FUNC(CAN_LOCAL_INLINE, uint8, STATIC_CODE) CanHL_InitTxBasicCAN(CAN_CHANNEL_CANTYPE_FIRST CanInitParaStructPtr initPara);

#if defined(C_ENABLE_RX_FULLCAN_OBJECTS)

V_DEF_FUNC(CAN_LOCAL_INLINE, uint8, STATIC_CODE) CanHL_InitRxFullCAN(CAN_CHANNEL_CANTYPE_FIRST CanInitParaStructPtr initPara);
#endif

#if defined(C_ENABLE_RX_BASICCAN_OBJECTS)

V_DEF_FUNC(CAN_LOCAL_INLINE, uint8, STATIC_CODE) CanHL_InitRxBasicCAN(CAN_CHANNEL_CANTYPE_FIRST CanInitParaStructPtr initPara);
#endif

V_DEF_FUNC(CAN_LOCAL_INLINE, uint8, STATIC_CODE) CanHL_InitEnd_InitMode(CAN_CHANNEL_CANTYPE_FIRST CanInitParaStructPtr initPara);

#if defined(C_ENABLE_RX_BASICCAN_OBJECTS)
#if defined(C_ENABLE_RX_BASICCAN_POLLING)

V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanHL_RxBasicCanPolling(CAN_HW_CHANNEL_CANTYPE_ONLY);
#endif
#endif

#if defined(C_ENABLE_RX_FULLCAN_OBJECTS)
#if defined(C_ENABLE_RX_FULLCAN_POLLING)

V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanHL_RxFullCanPolling(CAN_HW_CHANNEL_CANTYPE_ONLY);
#endif
#endif

#if defined(C_ENABLE_RX_FULLCAN_OBJECTS) || defined(C_ENABLE_RX_BASICCAN_OBJECTS)

V_DEF_FUNC(CAN_LOCAL_INLINE, uint8, STATIC_CODE) CanHL_RxMsgReceivedNotification(CAN_CHANNEL_CANTYPE_FIRST CanRxInfoStructPtr rxStructPtr);
#endif

#if defined(C_ENABLE_RX_QUEUE)

V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanHL_RxQueueExecution(void);
#endif

#if defined(C_ENABLE_TX_POLLING)

V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanHL_TxConfirmationPolling(CAN_HW_CHANNEL_CANTYPE_FIRST CanObjectHandle mailboxHandle, CanObjectHandle mailboxElement, CanObjectHandle hwObjHandle);
#endif

V_DEF_FUNC(CAN_STATIC, void, STATIC_CODE) CanHL_TxConfirmation(CAN_HW_CHANNEL_CANTYPE_FIRST CanObjectHandle mailboxHandle, CanObjectHandle mailboxElement, CanObjectHandle hwObjHandle);

#if defined(C_ENABLE_RX_BASICCAN_OBJECTS)
#if defined(C_ENABLE_RX_BASICCAN_POLLING)

V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanHL_BasicCanMsgReceivedPolling(CAN_HW_CHANNEL_CANTYPE_FIRST CanObjectHandle rxMailboxHandle, CanObjectHandle hwObjHandle);
#endif

V_DEF_FUNC(CAN_STATIC, void, STATIC_CODE) CanHL_BasicCanMsgReceived(CAN_HW_CHANNEL_CANTYPE_FIRST CanObjectHandle rxMailboxHandle, CanObjectHandle hwObjHandle);
#endif

#if defined(C_ENABLE_RX_FULLCAN_OBJECTS)
#if defined(C_ENABLE_RX_FULLCAN_POLLING)

V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanHL_FullCanMsgReceivedPolling(CAN_HW_CHANNEL_CANTYPE_FIRST CanObjectHandle rxMailboxHandle, CanObjectHandle hwObjHandle);
#endif

V_DEF_FUNC(CAN_STATIC, void, STATIC_CODE) CanHL_FullCanMsgReceived(CAN_HW_CHANNEL_CANTYPE_FIRST CanObjectHandle rxMailboxHandle, CanObjectHandle hwObjHandle);
#endif

V_DEF_FUNC(CAN_STATIC, void, STATIC_CODE) CanHL_ErrorHandling(CAN_HW_CHANNEL_CANTYPE_ONLY);

#if defined(C_ENABLE_SLEEP_WAKEUP)

V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanHL_WakeUpHandling(CAN_CHANNEL_CANTYPE_ONLY);
#endif

#if defined(C_ENABLE_CANCEL_TX_IN_HW)
#endif

V_DEF_FUNC(CAN_STATIC, uint8, STATIC_CODE) CanHL_ReInit(CAN_HW_CHANNEL_CANTYPE_FIRST uint8 doRamCheck);

#define CAN_STOP_SEC_STATIC_CODE
#include "MemMap.hpp"

#endif

