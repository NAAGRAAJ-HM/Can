#define C_DRV_INTERNAL
#define CAN_SOURCE
#define __CAN_SRC__
#if !defined(__CAN_SRC__)
#define __CAN_SRC__
#endif
#ifdef __cplusplus
extern "C"
{
#endif

#include "CanIf_Cbk.hpp"
#include "EcuabCanIf.hpp"
#include "Can_Local.hpp"

#if(CAN_DEV_ERROR_REPORT == STD_ON)
#include "SwcServiceDet.hpp"
#endif

#if !defined(CAN_AMD_RUNTIME_MEASUREMENT)
#define CAN_AMD_RUNTIME_MEASUREMENT STD_OFF
#endif
#if(CAN_AMD_RUNTIME_MEASUREMENT == STD_ON)
#include "AmdRtm.hpp"
#endif

#if !defined(CAN_RUNTIME_MEASUREMENT_SUPPORT)
#define CAN_RUNTIME_MEASUREMENT_SUPPORT STD_OFF
#endif
#if(CAN_RUNTIME_MEASUREMENT_SUPPORT == STD_ON)

#define C_ENABLE_RUNTIME_MEASUREMENT_SUPPORT
#include "Rtm.hpp"
#endif

#include "vstdlib.hpp"

#if(CAN_COREVERSION           != 0x0800u)
# error "Source and Header file are inconsistent!"
#endif
#if(CAN_RELEASE_COREVERSION   != 0x00u)
# error "Source and Header file are inconsistent!"
#endif
#if defined(CAN_GEN_BASE_CFG5_VERSION)
#if(CAN_GEN_BASE_CFG5_VERSION         != 0x0103u)
#error "Source and Generated Header file are inconsistent!"
#endif
#else
# error "No CAN_GEN_BASE_CFG5_VERSION is defined"
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

#if defined(CAN_USE_NO_VECTOR_IF)
#define CAN_USE_CRITICALSECTION_OVER_CONFIRMATION
#else
#if defined(CANIF_VENDOR_ID)
#if(CANIF_VENDOR_ID == 0x001E)
#define CAN_USE_VECTOR_IF
#if defined(IF_ASRIFCAN_VERSION)
#if(IF_ASRIFCAN_VERSION < 0x0410)
#define CAN_USE_CRITICALSECTION_OVER_CONFIRMATION
#endif
#endif
#else
#define CAN_USE_CRITICALSECTION_OVER_CONFIRMATION
#endif
#else
#define CAN_USE_CRITICALSECTION_OVER_CONFIRMATION
#endif
#endif

#if(CAN_RUNTIME_MEASUREMENT_SUPPORT == STD_ON)
#define CanHookBegin_Can_Init()                              Rtm_Start(RtmConf_RtmMeasurementPoint_Can_Init)
#define CanHookEnd_Can_Init()                                Rtm_Stop(RtmConf_RtmMeasurementPoint_Can_Init)
#define CanHookBegin_Can_SetControllerMode()                 Rtm_Start(RtmConf_RtmMeasurementPoint_Can_SetControllerMode)
#define CanHookEnd_Can_SetControllerMode()                   Rtm_Stop(RtmConf_RtmMeasurementPoint_Can_SetControllerMode)
#define CanHookBegin_Can_Write()                             Rtm_Start(RtmConf_RtmMeasurementPoint_Can_Write)
#define CanHookEnd_Can_Write()                               Rtm_Stop(RtmConf_RtmMeasurementPoint_Can_Write)

#else
#define CanHookBegin_Can_Init()
#define CanHookEnd_Can_Init()
#define CanHookBegin_Can_SetControllerMode() \

#define CanHookEnd_Can_SetControllerMode() \

#define CanHookBegin_Can_Write() \

#define CanHookEnd_Can_Write() \

#endif

#define CanHookBegin_CanHL_ReInit() \

#define CanHookEnd_CanHL_ReInit() \

#define CanHookBegin_CanHL_TxConfirmation() \

#define CanHookEnd_CanHL_TxConfirmation() \

#define CanHookBegin_CanHL_BasicCanMsgReceived() \

#define CanHookEnd_CanHL_BasicCanMsgReceived() \

#define CanHookBegin_CanHL_FullCanMsgReceived() \

#define CanHookEnd_CanHL_FullCanMsgReceived() \

#define CanHookBegin_Can_MainFunction_Write() \

#define CanHookEnd_Can_MainFunction_Write() \

#define CanHookBegin_Can_MainFunction_Read() \

#define CanHookEnd_Can_MainFunction_Read() \

#define kCanCrIntMaskBusoff            0x00000800u
#define kCanCrIntMaskCancel            0x00010000u
#define kCanCrListenOnlyMode           0x03000000u
#if defined(C_ENABLE_IMMEDIATE_BUSOFF_RECOVERY)
#define kCanCrHaltAtBusoff            0x00200000u
#else
#define kCanCrHaltAtBusoff            0x00400000u
#endif
#define kCanSrMaskBusoff               0x00000010u
#define kCanSrMaskPassive              0x00000008u
#define kCanSrMaskRec                  0x00FF0000u
#define kCanSrMaskTec                  0xFF000000u
#define kCanEfMaskBusoff               0x0008u
#define kCanEfMaskBusoffClear          0x7FF7u

#if defined(C_ENABLE_ALTERNATIVE_CLOCK_SOURCE)
#define kCanGlobCfg                   0x00000010u
#else
#define kCanGlobCfg                   0x00000000u
#endif
#define kCanIntMaskMessageLost         0x00000200u
#define kCanSrMaskRamIst               0x00000008u
#if defined (C_ENABLE_ECC_TX_ERROR)
#if(kCanMaxPhysChannels == 1u)
#define kCanEfMaskEccError           0x00010000u
#define kCanEfMaskEccErrorClear      0xFFFEFFFFu
# elif(kCanMaxPhysChannels == 2u)
#define kCanEfMaskEccError           0x00030000u
#define kCanEfMaskEccErrorClear      0xFFFCFFFFu
# elif(kCanMaxPhysChannels == 3u)
#define kCanEfMaskEccError           0x00070000u
#define kCanEfMaskEccErrorClear      0xFFF8FFFFu
# elif(kCanMaxPhysChannels == 4u)
#define kCanEfMaskEccError           0x000F0000u
#define kCanEfMaskEccErrorClear      0xFFF0FFFFu
# elif(kCanMaxPhysChannels == 5u)
#define kCanEfMaskEccError           0x001F0000u
#define kCanEfMaskEccErrorClear      0xFFE0FFFFu
# elif(kCanMaxPhysChannels == 6u)
#define kCanEfMaskEccError           0x003F0000u
#define kCanEfMaskEccErrorClear      0xFFC0FFFFu
# elif(kCanMaxPhysChannels == 7u)
#define kCanEfMaskEccError           0x007F0000u
#define kCanEfMaskEccErrorClear      0xFF80FFFFu
# elif(kCanMaxPhysChannels == 8u)
#define kCanEfMaskEccError           0x00FF0000u
#define kCanEfMaskEccErrorClear      0xFF00FFFFu
#endif
#endif
#define kCanHwRamTestEnable            0x00000004u
#define kCanHwRamTestDisable           0x00000000u
#define kCanProtectionUnlockData1      0x00007575u
#define kCanProtectionUnlockData2      0x00008A8Au

#define kCanRuleWrite                  0x00000100u
#define kCanRuleReceive                0x00000000u
#define kCanRuleUseBuf                 0x00008000u
#define kCanRuleStdMustMatch           0xC00007FFu
#define kCanRuleExtMustMatch           0xDFFFFFFFu
#define kCanRuleHeader                 0xC0000000u
#define kCanRuleHeaderClrMask          0x1FFFFFFFu
#define kCanRuleIndexMask              0x000Fu
#define kCanRulePageMask               0xFFF0u
#define kCanRulePageShiftVal           4u

#define kCanZero                       0u
#define kCanOne                        1u
#define kCanOne8                       0xFFu
#define kCanOne16                      0xFFFFu
#define kCanOne32                      0xFFFFFFFFu
#define kCanDlcMask                    0xF0000000u
#define kCanFdCfgMask                  0x00000007u
#define kCanRxFifoMask                 0x000000FFu

#define kCanModeMask                   0xFFFFFFF8u
#define kCanModeBits                   0x00000007u
#define kCanOperationMode              0x00000000u
#define kCanResetMode                  0x00000001u
#define kCanTestMode                   0x00000002u
#define kCanHaltMode                   0x00000002u
#define kCanStopMode                   0x00000005u

#define kCanCrTxBufReq                 0x01u
#define kCanCrTxBufCancel              0x02u
#define kCanSrTxBufMaskPending         0x06u
#define kCanSrTxBufMaskComplete        0x04u
#define kCanSrTxBufMaskCancel          0x02u
#define kCanSrTxBufMaskFree            0x1Fu
#define kCanSrTxBufMaskAReq            0x10u
#define kCanSrTxBufMaskTReq            0x08u

#define kCanCrFifoEnable               0x00000001u
#define kCanCrRxFifoSet                0x00001000u
#define kCanCrRxFifoIntEnable          0x00000002u
#define kCanSrFifoEmpty                0x00000001u
#define kCanSrFifoFull                 0x00000002u
#define kCanSrFifoOverrun              0x00000004u
#define kCanSrRxFifoIntFlag            0x00000008u
#define kCanSrTxFifoIntFlag            0x00000010u
#define kCanSrFifoMsgCount             0x0000FF00u
#define kCanPcrFifoPC                  0x000000FFu

#define kCanIntcEIMK                   ((vuint8) 0x80u)
#define kCanIntcEIMKNeg                ((vuint8) 0x7Fu)
#define kCanIntcEIRF                   ((vuint8) 0x10u)
#define kCanIntcEIRFNeg                ((vuint8) 0xEFu)

#define CanLL_WriteRegRegSize          CanLL_WriteReg32
#define CanLL_WriteRegGlobalRegSize    CanLL_WriteRegGlobal32
#define CanMemCheckValuesRegSize       CanMemCheckValues32bit

#if defined(C_ENABLE_IF_RSCAN)
#define kCanRamCheckMaskCGCFG        0xFFFFFF1Fu
#else
#if defined(C_ENABLE_RSCAN_FD_LAYOUT)
#define kCanRamCheckMaskCGCFG       0xFFFFFF3Fu
#else
#define kCanRamCheckMaskCGCFG       0xFFFFFFDFu
#endif
#endif
#if defined(C_ENABLE_RSCAN_FD_LAYOUT)
#define kCanRamCheckMaskCGCR         0x00000F00u
#else
#define kCanRamCheckMaskCGCR         0x00000700u
#endif
#if defined(C_ENABLE_IF_RSCAN_FD_V3)
#define kCanRamCheckMaskCRECR        0x0000013Fu
#else
#define kCanRamCheckMaskCRECR        0x0000011Fu
#endif
#if(kCanMaxPhysChannels == 1u)
#define kCanRamCheckMaskCRNCFG0      0xFF000000u
# elif(kCanMaxPhysChannels == 2u)
#define kCanRamCheckMaskCRNCFG0      0xFFFF0000u
# elif(kCanMaxPhysChannels == 3u)
#define kCanRamCheckMaskCRNCFG0      0xFFFFFF00u
# elif(kCanMaxPhysChannels >= 4u)
#define kCanRamCheckMaskCRNCFG0      0xFFFFFFFFu
#endif
#if(kCanMaxPhysChannels == 5u)
#define kCanRamCheckMaskCRNCFG1      0xFF000000u
# elif(kCanMaxPhysChannels == 6u)
#define kCanRamCheckMaskCRNCFG1      0xFFFF0000u
# elif(kCanMaxPhysChannels == 7u)
#define kCanRamCheckMaskCRNCFG1      0xFFFFFF00u
# elif(kCanMaxPhysChannels == 8u)
#define kCanRamCheckMaskCRNCFG1      0xFFFFFFFFu
#endif
#if defined(C_ENABLE_IF_RSCAN_FD_V3)
#define kCanRamCheckMaskCRBNUM       0x000007FFu
#else
#if defined(C_ENABLE_CAN_FD_USED)
#define kCanRamCheckMaskCRBNUM      0x000003FFu
#else
#define kCanRamCheckMaskCRBNUM      0x000000FFu
#endif
#endif
#if defined(C_ENABLE_RSCAN_FD_LAYOUT)
#define kCanRamCheckMaskCRFCR        0x0000F772u
#if defined(C_ENABLE_IF_RSCAN_FD_V3)
#define kCanRamCheckMaskTRFCR        0xFFFFFF76u
#else
#define kCanRamCheckMaskTRFCR        0xFFFFF776u
#endif
#else
#define kCanRamCheckMaskCRFCR        0x0000F702u
#define kCanRamCheckMaskTRFCR        0xFFFFF706u
#endif
#if defined(C_ENABLE_IF_RSCAN_FD)
#define kCanRamCheckMaskCGRMCFG      0x00000001u
#endif
#if defined(C_ENABLE_RSCAN_FD_LAYOUT)
#define kCanRamCheckMaskCGFDCFG      0x00000301u
#define kCanRamCheckMaskCGCRCCFG     0x00000001u
#endif
#define kCanRamCheckMaskRuleCode      0xFFFFFFFFu
#define kCanRamCheckMaskRuleMask      0xDFFFFFFFu
#if defined(C_ENABLE_IF_RSCAN_FD_V3)
#define kCanRamCheckMaskRuleBuf      0xFFFFFF0Fu
#else
#define kCanRamCheckMaskRuleBuf      0xFFFFFF00u
#endif
#if(kCanMaxPhysChannels == 1u)
#define kCanRamCheckMaskRuleFifo     0x000007FFu
# elif(kCanMaxPhysChannels == 2u)
#define kCanRamCheckMaskRuleFifo     0x00003FFFu
# elif(kCanMaxPhysChannels == 3u)
#define kCanRamCheckMaskRuleFifo     0x0001FFFFu
# elif(kCanMaxPhysChannels == 4u)
#define kCanRamCheckMaskRuleFifo     0x000FFFFFu
# elif(kCanMaxPhysChannels == 5u)
#define kCanRamCheckMaskRuleFifo     0x007FFFFFu
# elif(kCanMaxPhysChannels == 6u)
#define kCanRamCheckMaskRuleFifo     0x03FFFFFFu
# elif(kCanMaxPhysChannels == 7u)
#define kCanRamCheckMaskRuleFifo     0x1FFFFFFFu
# elif(kCanMaxPhysChannels == 8u)
#define kCanRamCheckMaskRuleFifo     0xFFFFFFFFu
#endif
#if defined(C_ENABLE_RSCAN_FD_LAYOUT)
#define kCanRamCheckMaskBCFG         0x1F7FFBFFu
#define kCanRamCheckMaskFDBCFG       0x077F00FFu
#if defined(C_ENABLE_IF_RSCAN_FD_V3)
#define kCanRamCheckMaskFDCFG       0x777F0707u
#else
#define kCanRamCheckMaskFDCFG       0x3F7F0707u
#endif
#define kCanRamCheckMaskCR           0x00EFFF00u
#else
#define kCanRamCheckMaskBCFG         0x037F03FFu
#define kCanRamCheckMaskCR           0x00E1FF00u
#endif

#define tCanIntCnt                     vuint8
#define tCanLoopRet                    Can_ReturnType

#if(CAN_SAFE_BSW == STD_ON)
#if !(CAN_SLEEP_SUPPORT == STD_ON)                                                         || \
     !defined(CAN_HL_HW_LAYOUT_TXBASIC_FIRST)                                               || \
     ((CAN_GET_STATUS == STD_ON) && !defined(C_ENABLE_EXTENDED_STATUS))                     || \
     !defined(C_HL_ENABLE_OVERRUN_IN_STATUS)                                                || \
     (defined(C_ENABLE_RX_FULLCAN_OBJECTS) && !defined(C_ENABLE_RX_FULLCAN_POLLING))        || \
     (defined(C_ENABLE_INTC_ACCESS_BY_APPL) || !defined(C_ENABLE_USE_OS_INTERRUPT_CONTROL))
#error "SafeBSW: An unsupported feature is active!"
#endif
#endif

#define CAN_HL_HW_TX_NORMAL_INDEX(hwch)     (Can_GetTxBasicHwStart(hwch))
#if defined(CAN_HL_HW_LAYOUT_TXBASIC_FIRST)
#define CAN_HL_HW_TX_STARTINDEX(hwch)      (Can_GetTxBasicHwStart(hwch))
#endif
#define CAN_HL_HW_TX_FULL_STARTINDEX(hwch)  (Can_GetTxFullHwStart(hwch))
#define CAN_HL_HW_UNUSED_STARTINDEX(hwch)   (Can_GetUnusedHwStart(hwch))
#define CAN_HL_HW_RX_FULL_STARTINDEX(hwch)  (Can_GetRxFullHwStart(hwch))
#define CAN_HL_HW_RX_BASIC_STARTINDEX(hwch) (Can_GetRxBasicHwStart(hwch))
#if defined(CAN_HL_HW_LAYOUT_TXBASIC_FIRST)
#define CAN_HL_HW_TX_STOPINDEX(hwch)       (Can_GetTxFullHwStop(hwch))
#endif
#define CAN_HL_HW_TX_FULL_STOPINDEX(hwch)   (Can_GetTxFullHwStop(hwch))
#define CAN_HL_HW_UNUSED_STOPINDEX(hwch)    (Can_GetUnusedHwStop(hwch))
#define CAN_HL_HW_RX_FULL_STOPINDEX(hwch)   (Can_GetRxFullHwStop(hwch))
#define CAN_HL_HW_RX_BASIC_STOPINDEX(hwch)  (Can_GetRxBasicHwStop(hwch))

#define CAN_HL_MB_RX_FULL_STARTINDEX(hwch)  (Can_GetRxFullHandleStart(hwch))
#define CAN_HL_MB_RX_BASIC_STARTINDEX(hwch) (Can_GetRxBasicHandleStart(hwch))
#define CAN_HL_MB_TX_FULL_STARTINDEX(hwch)  (Can_GetTxFullHandleStart(hwch))
#define CAN_HL_MB_TX_BASIC_STARTINDEX(hwch) (Can_GetTxBasicHandleStart(hwch))
#define CAN_HL_MB_RX_FULL_STOPINDEX(hwch)   (Can_GetRxFullHandleStop(hwch))
#define CAN_HL_MB_RX_BASIC_STOPINDEX(hwch)  (Can_GetRxBasicHandleStop(hwch))
#define CAN_HL_MB_TX_FULL_STOPINDEX(hwch)   (Can_GetTxFullHandleStop(hwch))
#define CAN_HL_MB_TX_BASIC_STOPINDEX(hwch)  (Can_GetTxBasicHandleStop(hwch))

#if defined(C_ENABLE_CAN_RAM_CHECK)
#if !defined(CAN_RAM_CHECK_MAILBOX_RESULT)
#if defined( C_SINGLE_RECEIVE_CHANNEL )
#define CAN_RAM_CHECK_MAILBOX_RESULT(ch, initParaPtr) CanLL_InitIsMailboxCorrupt((initParaPtr))
#else
#define CAN_RAM_CHECK_MAILBOX_RESULT(ch, initParaPtr) CanLL_InitIsMailboxCorrupt((ch), (initParaPtr))
#endif
#endif
#if !defined(CAN_RAM_CHECK_FINISHED_CTP)
#define CAN_RAM_CHECK_FINISHED_CTP(ch)
#endif
#endif
#if defined(C_ENABLE_CAN_RAM_CHECK_EXTENDED)
#if !defined(CAN_RAM_CHECK_BEGIN_REG_RESULT)
#if defined( C_SINGLE_RECEIVE_CHANNEL )
#define CAN_RAM_CHECK_BEGIN_REG_RESULT(ch, initParaPtr) CanLL_InitBeginIsRegisterCorrupt((initParaPtr))
#else
#define CAN_RAM_CHECK_BEGIN_REG_RESULT(ch, initParaPtr) CanLL_InitBeginIsRegisterCorrupt((ch), (initParaPtr))
#endif
#endif
#if !defined(CAN_RAM_CHECK_END_REG_RESULT)
#if defined( C_SINGLE_RECEIVE_CHANNEL )
#define CAN_RAM_CHECK_END_REG_RESULT(ch, initParaPtr) CanLL_InitEndIsRegisterCorrupt((initParaPtr))
#else
#define CAN_RAM_CHECK_END_REG_RESULT(ch, initParaPtr) CanLL_InitEndIsRegisterCorrupt((ch), (initParaPtr))
#endif
#endif
#if !defined(CAN_RAM_CHECK_READ_BACK_RESULT)
#define CAN_RAM_CHECK_READ_BACK_RESULT(ch)
#endif
#endif

#define CanHL_IsStart(ch) ((Can_GetLogStatus(ch) & CAN_STATUS_START) == CAN_STATUS_START)
#define CanHL_IsSleep(ch) ((Can_GetLogStatus(ch) & CAN_STATUS_SLEEP) == CAN_STATUS_SLEEP)
#define CanHL_IsStop(ch) ((Can_GetLogStatus(ch) & CAN_STATUS_STOP) == CAN_STATUS_STOP)
#define CanHL_IsBusOff(ch) (Can_IsIsBusOff(ch))
#define CanHL_IsControllerInit(ch) ((Can_GetLogStatus(ch) & CAN_STATUS_INIT) == CAN_STATUS_INIT)

#if defined(C_ENABLE_CAN_FD_USED)
#define CAN_DLC2LEN(dlc) (Can_DlcToFrameLenght[((uint8)(dlc)) & ((uint8)0xFu)])
#define CAN_LEN2DLC(length) ((uint8)Can_MessageLengthToDlc[(length)])
#else
#define CAN_DLC2LEN(dlc) (dlc)
#define CAN_LEN2DLC(length) (length)
#endif
#if defined(C_ENABLE_CAN_FD_FULL)
#define CAN_MAX_DATALEN_OBJ(Index) Can_GetMailboxDataLen(Index)
#else
#define CAN_MAX_DATALEN_OBJ(Index) 8u
#endif
#define CanHL_IsFdMessage(id) (((id) & (Can_IdType)CAN_ID_FD_MASK) == (Can_IdType)CAN_ID_FD_MASK)
#define CanHL_IsFdTxBrs(ch)   (Can_GetInitObjectFdBrsConfig(Can_GetLastInitObject(ch)) == CAN_FD_RXTX)

#if defined(C_SINGLE_PHYS_CHANNEL)
#define canPhysChannel                      kCanLogToPhys
#endif

#define CanLL_SL32(num) \
  ((vuint32) (((vuint32)0x00000001u)<<((vuint8)(num)&0x1Fu)))

#define CanLL_SL16(num) \
  ((vuint16) (((vuint16)0x0001u)<<((vuint8)(num)&0x0Fu)))

#define CanLL_SL8(num) \
  ((vuint8) (((vuint8)0x01u)<<((vuint8)(num)&0x07u)))

#define CanLL_SLRS(num) \
  CanLL_SL32(num)

#define CanLL_BitIndex(num) \
  (((num)>>5)&0x03u)

#define CanLL_ClearBitRS(num) \
  ((kCanRegSizeCast) ~CanLL_SLRS(num))

#define CanLL_SetBitRS(num) \
  ((kCanRegSizeCast) CanLL_SLRS(num))

#define CanLL_ByteIndex(pch) \
  (((pch)>>2)&0x01u)

#if defined(C_ENABLE_IF_RSCAN_FD_V3)
#define CanLL_TxMaskWord(pch) \
  ((kCanRegSize)kCanOne32)
#else
#define CanLL_TxMaskWord(pch) \
  ((kCanRegSize)(((kCanRegSize)0x0000FFFFu)<<(((pch)&0x01u)<<4)))
#endif

#if defined(C_ENABLE_IF_RSCAN_FD_V3)
#define CanLL_TxSharedRegToWord(pch, val) \
  ((kCanTxSize)(val))
#else
#define CanLL_TxSharedRegToWord(pch, val) \
  ((kCanTxSize)(((kCanRegSize)(val))>>(((pch)&0x01u)<<4)))
#endif

#if defined(C_ENABLE_IF_RSCAN_FD_V3)
#define CanLL_TxWordToSharedReg(pch, val) \
  ((kCanRegSize)(val))
#else
#define CanLL_TxWordToSharedReg(pch, val) \
  ((kCanRegSize)(((kCanRegSize)(val))<<(((pch)&0x01u)<<4)))
#endif

#if defined(C_ENABLE_IF_RSCAN_FD_V3)
#define CanLL_TxWordIndex(pch) \
  ((pch)&0x07u)
#else
#define CanLL_TxWordIndex(pch) \
  (((pch)>>1)&0x03u)
#endif

#if defined(C_ENABLE_IF_RSCAN_FD_V3)
#define CanLL_SLTS(num) \
  CanLL_SL32(num)
#else
#define CanLL_SLTS(num) \
  CanLL_SL16(num)
#endif

#define CanLL_TxMaskWordClear(pch) \
  ((kCanRegSize) ~CanLL_TxMaskWord(pch))

#define CanLL_ClearBitTS(num) \
  ((kCanTxSize) ~CanLL_SLTS(num))

#define CanLL_SetBitTS(num) \
  ((kCanTxSize) CanLL_SLTS(num))

#define CanLL_FilterListConfig(pch, val) \
  (kCanRegSize)(((kCanRegSize)(val)) << (24u-(((pch)&0x03u)<<3)))

#define CanLL_ModeReq_Log(ch, mode) \
  (Can->ChCtrl[mCanLogToPhys(ch)].CR = ((Can->ChCtrl[mCanLogToPhys(ch)].CR & kCanModeMask) | (mode)))

#define CanLL_ModeCheck_Log(ch, mode) \
  ((Can->ChCtrl[mCanLogToPhys(ch)].SR & kCanModeBits) == (mode))

#define CanLL_ModeReq_Phys(pch, mode) \
  (Can->ChCtrl[pch].CR = ((Can->ChCtrl[pch].CR & kCanModeMask) | (mode)))

#define CanLL_ModeCheck_Phys(pch, mode) \
  ((Can->ChCtrl[pch].SR & kCanModeBits) == (mode))

#define CanLL_GlobalModeReq(mode) \
  (Can->CGCR = ((Can->CGCR & kCanModeMask) | (mode)))

#define CanLL_GlobalModeCheck(mode) \
  (Can->CGSR == (mode))

#if defined(C_ENABLE_LL_CAN_INTCTRL) || defined(C_ENABLE_LL_CAN_WAKEUP_INTCTRL)
#if defined(C_ENABLE_INTC_ACCESS_BY_APPL)

#define CanLL_IntcIntEnable(id, reg) \
  ApplCanWriteIcr8((vuint32)(&(reg)), (vuint8)(ApplCanReadIcr8((vuint32)(&(reg))) & kCanIntcEIMKNeg))

#define CanLL_IntcIntEnableLoc(reg) \
  ((reg) &= kCanIntcEIMKNeg)

#define CanLL_IntcIntDisable(id, reg) \
  ApplCanWriteIcr8((vuint32)(&(reg)), (vuint8)(ApplCanReadIcr8((vuint32)(&(reg))) | kCanIntcEIMK))

#define CanLL_IntcIntDisableLoc(reg) \
  ((reg) |= kCanIntcEIMK)

#define CanLL_IntcIntFlag(id, reg) \
  ((ApplCanReadIcr8((vuint32)(&(reg))) & kCanIntcEIRF) == kCanIntcEIRF)

#define CanLL_IntcIntClear(id, reg) \
  ApplCanWriteIcr8((vuint32)(&(reg)), (vuint8)(ApplCanReadIcr8((vuint32)(&(reg))) & kCanIntcEIRFNeg))

#define CanLL_IntcIntSave(id, dst, src) \
  ((dst) = ApplCanReadIcr8((vuint32)(&(src))))

#define CanLL_IntcIntRestore(id, dst, src) \
  ApplCanWriteIcr8((vuint32)(&(dst)), (vuint8)(src))

# elif defined(C_ENABLE_USE_OS_INTERRUPT_CONTROL)

#define CanLL_IntcIntEnable(id, reg) \
  (void)osEnableInterruptSource((id), TRUE)

#define CanLL_IntcIntEnableLoc(reg) \
  ((reg) = TRUE)

#define CanLL_IntcIntDisable(id, reg) \
  (void)osDisableInterruptSource(id)

#define CanLL_IntcIntDisableLoc(reg) \
  ((reg) = FALSE)

#define CanLL_IntcIntFlag(id, reg) \
  (CanLL_OsIsInterruptPending(id) == TRUE)

#define CanLL_IntcIntClear(id, reg) \
  (void)osClearPendingInterrupt(id)

#define CanLL_IntcIntSave(id, dst, src) \
  ((dst) = (vuint8)CanLL_OsIsInterruptSourceEnabled(id))

#define CanLL_IntcIntRestore(id, dst, src) \
  CanLL_OsRestoreInterruptSource((id), (boolean)(src))

#else

#define CanLL_IntcIntEnable(id, reg) \
  ((reg) &= kCanIntcEIMKNeg)

#define CanLL_IntcIntEnableLoc(reg) \
  ((reg) &= kCanIntcEIMKNeg)

#define CanLL_IntcIntDisable(id, reg) \
  ((reg) |= kCanIntcEIMK)

#define CanLL_IntcIntDisableLoc(reg) \
  ((reg) |= kCanIntcEIMK)

#define CanLL_IntcIntFlag(id, reg) \
  (((reg) & kCanIntcEIRF) == kCanIntcEIRF)

#define CanLL_IntcIntClear(id, reg) \
  ((reg) &= kCanIntcEIRFNeg)

#define CanLL_IntcIntSave(id, dst, src) \
  ((dst) = (src))

#define CanLL_IntcIntRestore(id, dst, src) \
  ((dst) = (src))

#endif
#endif

#if defined(C_ENABLE_SLEEP_WAKEUP)
#define CanLL_HwIsSleep(hwCh) \
  (CanLL_ModeCheck_Log((hwCh), kCanStopMode))
#else
#define CanLL_HwIsSleep(hwCh) \
  (kCanFalse != kCanFalse)
#endif

#define CanLL_HwIsStop(hwCh) \
  (CanLL_ModeCheck_Log((hwCh), kCanResetMode) || CanLL_ModeCheck_Log((hwCh), kCanHaltMode))

#define CanLL_HwIsBusOff(hwCh) \
  ((Can->ChCtrl[mCanLogToPhys(hwCh)].SR & kCanSrMaskBusoff) == kCanSrMaskBusoff)

#define CanLL_HwWasBusOff(hwCh) \
  ((Can->ChCtrl[mCanLogToPhys(hwCh)].EF & kCanEfMaskBusoff) == kCanEfMaskBusoff)

#if defined(C_ENABLE_EXTENDED_STATUS)

#define CanLL_HwIsPassive(hwCh) \
  ((Can->ChCtrl[mCanLogToPhys(hwCh)].SR & kCanSrMaskPassive) == kCanSrMaskPassive)

#if defined(C_MULTIPLE_RECEIVE_CHANNEL)
#define CanLL_HwIsWarning(hwCh) \
  (((CanRxActualErrorCounter(hwCh) >= (96u)) && (CanRxActualErrorCounter(hwCh) < (128u))) || \
   ((CanTxActualErrorCounter(hwCh) >= (96u)) && (CanTxActualErrorCounter(hwCh) < (128u))))
#else
#define CanLL_HwIsWarning(hwCh) \
  (((CanRxActualErrorCounter() >= (96u)) && (CanRxActualErrorCounter() < (128u))) || \
   ((CanTxActualErrorCounter() >= (96u)) && (CanTxActualErrorCounter() < (128u))))
#endif
#endif

#if defined(C_MULTIPLE_RECEIVE_CHANNEL)
#define CanLL_ApplCanTimerStart(loop)   ApplCanTimerStart(channel, loop)
#define CanLL_ApplCanTimerEnd(loop)     ApplCanTimerEnd(channel, loop)
#define CanLL_ApplCanTimerLoop(loop)    ApplCanTimerLoop(channel, loop)
#else
#define CanLL_ApplCanTimerStart(loop)   ApplCanTimerStart(loop)
#define CanLL_ApplCanTimerEnd(loop)     ApplCanTimerEnd(loop)
#define CanLL_ApplCanTimerLoop(loop)    ApplCanTimerLoop(loop)
#endif

#if defined(C_ENABLE_HW_LOOP_TIMER)
#define CanLL_CanTimerStart(loop)       CanLL_ApplCanTimerStart(loop)
#define CanLL_CanTimerEnd(loop)         CanLL_ApplCanTimerEnd(loop)
#define CanLL_CanTimerLoop(loop)        CanLL_ApplCanTimerLoop(loop)
#else
#define CanLL_CanTimerStart(loop)
#define CanLL_CanTimerEnd(loop)
#define CanLL_CanTimerLoop(loop)        CAN_OK
#endif

#if(CAN_RUNTIME_MEASUREMENT_SUPPORT == STD_ON)
#define CanLL_RtmStart(point)           Rtm_Start(RtmConf_RtmMeasurementPoint_##point)
#define CanLL_RtmStop(point)            Rtm_Stop(RtmConf_RtmMeasurementPoint_##point)
#else
#define CanLL_RtmStart(point)
#define CanLL_RtmStop(point)
#endif

#define CAN_START_SEC_CONST_UNSPECIFIED
#include "MemMap.hpp"

#if defined(C_ENABLE_CAN_FD_USED)
V_DEF_CONST(CAN_STATIC, uint8, CONST) Can_DlcToFrameLenght[16] = {
  0u,  1u,  2u,  3u,
  4u,  5u,  6u,  7u,
  8u, 12u, 16u, 20u,
 24u, 32u, 48u, 64u
};

V_DEF_CONST(CAN_STATIC, uint8, CONST) Can_MessageLengthToDlc[65] = {
  0u,  1u,  2u,  3u,  4u,  5u,  6u,  7u,
  8u,  9u,  9u,  9u,  9u, 10u, 10u, 10u,
 10u, 11u, 11u, 11u, 11u, 12u, 12u, 12u,
 12u, 13u, 13u, 13u, 13u, 13u, 13u, 13u,
 13u, 14u, 14u, 14u, 14u, 14u, 14u, 14u,
 14u, 14u, 14u, 14u, 14u, 14u, 14u, 14u,
 14u, 15u, 15u, 15u, 15u, 15u, 15u, 15u,
 15u, 15u, 15u, 15u, 15u, 15u, 15u, 15u,
 15u
};
#endif

#if defined(C_ENABLE_CAN_RAM_CHECK)
V_DEF_CONST(CAN_STATIC, vuint32, CONST) CanMemCheckValues32bit[3] = {
  0xAAAAAAAAUL, 0x55555555UL, 0x00000000UL
};
#endif

#define CAN_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.hpp"

#define CAN_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.hpp"

V_DEF_VAR(CAN_STATIC, uint8, VAR_NOINIT) canIsRxTaskLocked;
#if defined(C_ENABLE_RX_QUEUE)
V_DEF_VAR(CAN_STATIC, uint16, VAR_NOINIT) canRxQueueMaxDataSize;
#endif

#if defined(C_ENABLE_LL_CAN_INTCTRL)

V_DEF_VAR(CAN_STATIC, tCanLLCanGlobalIntOld, VAR_NOINIT) canInterruptOldFlag;

#endif
#if defined(C_ENABLE_GLOBAL_INIT_POST_PROCESS)

V_DEF_VAR(CAN_STATIC, vuint8, VAR_NOINIT) CanAddFilterRulesStartPage;

V_DEF_VAR(CAN_STATIC, vuint8, VAR_NOINIT) CanAddFilterRulesStartIndex;

#endif
#if defined(C_ENABLE_CAN_RAM_CHECK_EXTENDED)

V_DEF_VAR(CAN_STATIC, vuint8, VAR_NOINIT) canIsCellCorrupt;

#endif
#if(CAN_SAFE_BSW == STD_ON)

V_DEF_VAR(CAN_STATIC, tCanDummyBuf, VAR_NOINIT) CanLL_DummyBuf;

#endif

#define CAN_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.hpp"

#define CAN_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.hpp"

V_DEF_VAR(CAN_STATIC, uint8, VAR_INIT) canConfigInitFlag = CAN_STATUS_UNINIT;
#define CAN_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.hpp"

#if defined(CAN_ENABLE_USE_INIT_ROOT_POINTER)
#define CAN_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.hpp"

V_DEF_P2CONST (V_NONE, Can_ConfigType, VAR_INIT, CONST_PBCFG) Can_ConfigDataPtr = NULL_PTR;
#define CAN_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.hpp"
#else
#define CAN_START_SEC_CONST_UNSPECIFIED
#include "MemMap.hpp"

V_DEF_CONSTP2CONST(V_NONE, Can_ConfigType, CONST, CONST_PBCFG) Can_ConfigDataPtr = (Can_ConfigType*) NULL_PTR;
#define CAN_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.hpp"
#endif

#if !defined(CAN_SAFE_BSW)
#define CAN_SAFE_BSW   STD_OFF
#else
#if(CAN_SAFE_BSW == STD_ON)
#if(CAN_DEV_ERROR_DETECT == STD_OFF) || (CAN_AMD_RUNTIME_MEASUREMENT == STD_ON)
#   error "Unsupported Feature activated for SafeBSW"
#endif
#endif
#endif

#if(CAN_TRANSMIT_BUFFER == STD_OFF) && defined(C_ENABLE_CANCEL_IN_HW)
# error "C_ENABLE_CANCEL_IN_HW need CAN_TRANSMIT_BUFFER == STD_ON (no FIFO buffering but PRIO_BY_CANID in CanIf) -> check Generated data"
#endif
#if !defined(C_ENABLE_SLEEP_WAKEUP)
#if(CAN_SLEEP_SUPPORT == STD_ON) && (CAN_WAKEUP_SUPPORT == STD_ON)
#error "C_ENABLE_SLEEP_WAKEUP organified but generated like supported"
#endif
#endif
#if(CAN_WAKEUP_SUPPORT == STD_ON) && (CAN_SLEEP_SUPPORT == STD_OFF)
# error "activated CAN_WAKEUP_SUPPORT need activated CAN_SLEEP_SUPPORT"
#endif
#if defined(C_ENABLE_HW_LOOP_TIMER)
#if(CAN_LOOP_MAX == 0)
#error "CAN_LOOP_MAX should not be generated as 0"
#endif
#else
#if(CAN_HARDWARE_CANCELLATION == STD_ON)
#error "C_ENABLE_HW_LOOP_TIMER organified but generated like supported"
#endif
#endif
#if defined(C_ENABLE_CANCEL_IN_HW)
#else
#if(CAN_HW_TRANSMIT_CANCELLATION == STD_ON)
#error "C_ENABLE_CANCEL_IN_HW organified but generated like supported"
#endif
#endif
#if(CAN_MIRROR_MODE == STD_ON) && (!defined(CAN_ENABLE_GENERIC_CONFIRMATION_API2) || (CAN_GENERIC_PRECOPY == STD_OFF))
# error "CAN_MIRROR_MODE need CAN_GENERIC_CONFIRMATION with CAN_API2 and CAN_GENERIC_PRECOPY as STD_ON"
#endif
#if(CAN_MULTIPLE_BASICCAN_TX == STD_ON)
#if(CAN_HW_TRANSMIT_CANCELLATION == STD_ON)

# error "CAN_MULTIPLE_BASICCAN_TX and CAN_HW_TRANSMIT_CANCELLATION are STD_ON but this combination is not supported"
#endif
#endif

#if((kCanMaxPhysChannels > kCanMaxPhysChannelsCell)           ||  \
     (kCanMaxRxFifos > kCanMaxRxFifosCell)                     ||  \
     (kCanMaxTxBuf > kCanMaxTxBufCell)                         ||  \
     (kCanMaxTxFifos > kCanMaxTxFifosCell)                     ||  \
     (kCanMaxRxBuf > kCanMaxRxBufCell)                         ||                   \
     (kCanNumberOfSharedReg16 > ((kCanMaxPhysChannels+1)>>1)))
# error "Configuration exceeds RSCAN limitations, check the derivative data!"
#endif

#if((kCanBaseAdr == 0u)                                       || \
     (kCanMaxPhysChannels == 0u)                               || \
     (kCanMaxRxFifos == 0u)                                    || \
     (kCanMaxTxBuf == 0u)                                      || \
     (kCanMaxTxFifos == 0u)                                    || \
     (kCanMaxRxBuf == 0u)                                      || \
     (kCanNumberOfSharedReg16 == 0u))
# error "General configuration error!"
#endif

#if defined(C_ENABLE_LL_CAN_INTCTRL)
#if((kCanIntcRxFifoBaseAdr == 0u)                           || \
       (kCanIntcGErrorBaseAdr == 0u))
#   error "Interrupt control register address configuration error!"
#endif
#endif

#if !defined(C_ENABLE_IF_RSCAN) && !defined(C_ENABLE_IF_RSCAN_FD) && !defined(C_ENABLE_IF_RSCAN_FD_V3)
# error "CAN interface is not defined!"
#endif
#if defined(C_ENABLE_IF_RSCAN) && defined(C_ENABLE_IF_RSCAN_FD)
#error "Configuration of CAN interface is ambiguous!"
#endif
#if defined(C_ENABLE_IF_RSCAN) && defined(C_ENABLE_IF_RSCAN_FD_V3)
#error "Configuration of CAN interface is ambiguous!"
#endif
#if defined(C_ENABLE_IF_RSCAN_FD) && defined(C_ENABLE_IF_RSCAN_FD_V3)
#error "Configuration of CAN interface is ambiguous!"
#endif
#if defined(C_ENABLE_CAN_FD_USED)
#if defined(C_ENABLE_IF_RSCAN)
#   error "Usage of CAN-FD requires a RSCAN-FD hardware interface, check the configuration or used derivative!"
#endif
#endif

#if defined(C_ENABLE_RX_FULLCAN_OBJECTS)
#if !defined(C_ENABLE_RX_FULLCAN_POLLING)
#error "Rx FullCANs cannot be processed in interrupt context!"
#endif
#endif

#if defined(C_ENABLE_NESTED_INTERRUPTS)
#if defined(C_ENABLE_OSEK_OS) && defined(C_ENABLE_OSEK_OS_INTCAT2)
#error "Nesting of category 2 CAN interrupts must not be enabled by the driver!"
#endif
#if defined(C_ENABLE_ISRVOID)
#error "Nesting of void-void CAN interrupts must not be enabled by the driver!"
#endif
#endif

#if defined(C_ENABLE_SLEEP_WAKEUP)
#if !defined(C_ENABLE_BUSWAKEUP_SUPPORT)
#   error "Sleep/Wakeup functionality is not supported for this derivative!"
#endif
#endif

#if defined(C_ENABLE_TX_HW_FIFO)
#if defined(C_ENABLE_CANCEL_IN_HW)
#error "'Hardware (Transmit) Cancellation' is not supported if Tx Fifos are enabled!"
#endif
#endif

#define CAN_START_SEC_STATIC_CODE
#include "MemMap.hpp"

#if defined( C_SINGLE_RECEIVE_CHANNEL )
#define CanHL_ApplCanTimerStart( timerIdx )  ApplCanTimerStart( timerIdx );
#define CanHL_ApplCanTimerEnd( timerIdx )    ApplCanTimerEnd( timerIdx );
#else
#define CanHL_ApplCanTimerStart( timerIdx )  ApplCanTimerStart( channel, (timerIdx) );
#define CanHL_ApplCanTimerEnd( timerIdx )    ApplCanTimerEnd( channel, (timerIdx) );
#endif
#define CanHL_ApplCanTimerLoop( timerIdx )   if(ApplCanTimerLoop(CAN_CHANNEL_CANPARA_FIRST (timerIdx)) != CAN_OK) \
                                              { \
                                                break; \
                                              }

#if(CAN_HW_LOOP_SUPPORT_API == STD_OFF)

#if defined( C_SINGLE_RECEIVE_CHANNEL )

#define ApplCanTimerStart(source)     ((void)GetCounterValue( CAN_OS_COUNTER_ID, &Can_GetCanLoopTimeout(0, (source))))
#else
#define ApplCanTimerStart(ch, source) ((void)GetCounterValue( CAN_OS_COUNTER_ID, &Can_GetCanLoopTimeout((ch), (source))))
#endif

V_DEF_FUNC(CAN_LOCAL_INLINE, Can_ReturnType, STATIC_CODE) ApplCanTimerLoop( CAN_CHANNEL_CANTYPE_FIRST uint8 source ){

  Can_ReturnType retval;
  uint8 errorId;
  uint8 apiId;
  errorId = CAN_E_NO_ERROR;
  apiId = CAN_HW_ACCESS_ID;
  retval = CAN_NOT_OK;

#if(CAN_DEV_ERROR_DETECT == STD_ON)

  if(source > CAN_LOOP_MAX){
    errorId = CAN_E_PARAM_HANDLE;
  }
  else
#if !defined( C_SINGLE_RECEIVE_CHANNEL )
  if(channel >= kCanNumberOfChannels){
    errorId = CAN_E_PARAM_CONTROLLER;
  }
  else
#endif
#endif
  {

    TickType elapsedTime;
    TickType startTime;

    startTime = Can_GetCanLoopTimeout(channel, source);

    if( GetElapsedValue( CAN_OS_COUNTER_ID, &startTime, &elapsedTime ) != (StatusType)E_OK ){
      errorId = CAN_E_TIMEOUT_DET;
    }
    else{

      if( (TickType)CAN_OS_TICK2MS( elapsedTime ) < (TickType)CAN_TIMEOUT_DURATION )
      {
        retval = CAN_OK;
      }
#if defined(C_ENABLE_HW_LOOP_TIMER)
      else
      {

        if(source < CAN_LOOP_MAX)
        {
          errorId = CAN_E_TIMEOUT_DET;
        }
      }
#endif
    }
    CAN_DUMMY_STATEMENT(startTime);
  }

#if(CAN_DEV_ERROR_REPORT == STD_ON)
  if(errorId != CAN_E_NO_ERROR){
    Can_CallDetReportError(apiId, errorId);
  }
#else
  CAN_DUMMY_STATEMENT(apiId);
  CAN_DUMMY_STATEMENT(errorId);
#endif
  return retval;
}

#define ApplCanTimerEnd ApplCanTimerStart
#endif

V_DEF_FUNC(CAN_STATIC, uint8, STATIC_CODE) CanHL_ReInit( CAN_HW_CHANNEL_CANTYPE_FIRST uint8 doRamCheck ){

  uint8 errorId;
  tCanInitParaStruct initPara;
  CanHookBegin_CanHL_ReInit();
  errorId = CAN_E_NO_ERROR;
  initPara.isInitOk = kCanOk;

#if(CAN_DEV_ERROR_DETECT == STD_ON)

  if(canConfigInitFlag == CAN_STATUS_UNINIT){
    errorId = CAN_E_UNINIT;
  }
  else
#if !defined( C_SINGLE_RECEIVE_CHANNEL )
  if(channel >= kCanNumberOfChannels){
    errorId = CAN_E_PARAM_CONTROLLER;
  }
  else
#endif
#if(CAN_POSTBUILD_VARIANT_SUPPORT == STD_ON)
  if(Can_GetCanIfChannelId(channel) == kCanChannelNotUsed){
    errorId = CAN_E_PARAM_CONTROLLER;
  }
  else
#endif
#endif
  {

    initPara.initObject = Can_GetLastInitObject(channel);
#if defined(C_ENABLE_CAN_RAM_CHECK)
    initPara.doRamCheck = doRamCheck;
#endif
#if defined(C_ENABLE_CAN_RAM_CHECK_EXTENDED)
    initPara.isChRamCheckFail = kCanFalse;
#endif

#if defined(C_ENABLE_CAN_RAM_CHECK) && !defined(C_ENABLE_CAN_RAM_CHECK_EXTENDED)
    if(doRamCheck == kCanExecuteRamCheck){
      Can_SetLogStatus(channel, Can_GetLogStatus(channel) & (uint8)CAN_STATUS_INIT);
    }
    else
#endif
    {
      Can_SetLogStatus(channel, Can_GetLogStatus(channel) & ((uint8)(CAN_DEACTIVATE_CONTROLLER) | (uint8)((uint8)CAN_STATUS_INIT)));
    }

    initPara.isInitOk &= CanHL_InitBegin(CAN_CHANNEL_AND_HW_CHANNEL_CANPARA_FIRST &initPara);

    if(initPara.isInitOk == kCanOk){
#if defined(C_ENABLE_TX_FULLCAN_OBJECTS)

      initPara.isInitOk &= CanHL_InitTxFullCAN(CAN_CHANNEL_AND_HW_CHANNEL_CANPARA_FIRST &initPara);
#endif

      initPara.isInitOk &= CanHL_InitTxBasicCAN(CAN_CHANNEL_AND_HW_CHANNEL_CANPARA_FIRST &initPara);
#if defined(C_ENABLE_RX_FULLCAN_OBJECTS)

      initPara.isInitOk &= CanHL_InitRxFullCAN(CAN_CHANNEL_AND_HW_CHANNEL_CANPARA_FIRST &initPara);
#endif
#if defined(C_ENABLE_RX_BASICCAN_OBJECTS)

      initPara.isInitOk &= CanHL_InitRxBasicCAN(CAN_CHANNEL_AND_HW_CHANNEL_CANPARA_FIRST &initPara);
#endif

      initPara.isInitOk &= CanHL_InitEnd_InitMode(CAN_CHANNEL_AND_HW_CHANNEL_CANPARA_FIRST &initPara);
#if defined(C_ENABLE_CAN_RAM_CHECK)
      if(doRamCheck == kCanExecuteRamCheck)
      {
#if defined(C_ENABLE_CAN_RAM_CHECK_EXTENDED)

        if(initPara.isChRamCheckFail == kCanTrue)
        {
          CanIf_RamCheckCorruptController((uint8)Can_GetCanToCanIfChannelMapping(channel));
          Can_SetLogStatus(channel, Can_GetLogStatus(channel) | CAN_DEACTIVATE_CONTROLLER);
        }
#else
        if( (Can_GetLogStatus(channel) & CAN_DEACTIVATE_CONTROLLER) == CAN_DEACTIVATE_CONTROLLER )
        {
          if(Appl_CanRamCheckFailed((uint8)channel) != CAN_DEACTIVATE_CONTROLLER)
          {
            Can_SetLogStatus(channel, Can_GetLogStatus(channel) & (uint8)(~(CAN_DEACTIVATE_CONTROLLER)));
          }
        }
#endif
        CAN_RAM_CHECK_FINISHED_CTP(channel)
      }
#endif
    }
    if(initPara.isInitOk == kCanOk){
      Can_SetLogStatus(channel, Can_GetLogStatus(channel) | (CAN_STATUS_INIT));
    }
    else{
      Can_SetLogStatus(channel,  (Can_GetLogStatus(channel) & (uint8)(CAN_DEACTIVATE_CONTROLLER)));
      errorId = CAN_E_UNINIT;
    }
#if defined(C_ENABLE_SLEEP_WAKEUP)
    if(Can_IsIsWakeup(channel)){
      Can_SetIsWakeup(channel, FALSE);
      EcuM_SetWakeupEvent(Can_GetWakeupSourceRef(channel));
    }
#endif
  }

#if(CAN_DEV_ERROR_REPORT == STD_ON)
  if(errorId != CAN_E_NO_ERROR){
    Can_CallDetReportError(CAN_INITCTR_ID, errorId);
  }
#else
  CAN_DUMMY_STATEMENT(errorId);
#endif
#if !defined(C_ENABLE_CAN_RAM_CHECK)
  CAN_DUMMY_STATEMENT(doRamCheck);
#endif
  CanHookEnd_CanHL_ReInit();
  return initPara.isInitOk;
}

V_DEF_FUNC(CAN_LOCAL_INLINE, uint8, STATIC_CODE) CanHL_ModeTransition( CAN_CHANNEL_CANTYPE_FIRST uint8 transitionRequest, uint8 busOffRecovery, uint8 doRamCheck ){

  uint8 transitionState;

  transitionState = CanLL_ModeTransition(CAN_CHANNEL_AND_HW_CHANNEL_CANPARA_FIRST transitionRequest, busOffRecovery, doRamCheck);
  if(transitionState != kCanOk){
    CanHL_ApplCanTimerStart((uint8)CAN_LOOP_MAX);
    do
    {
      transitionState = CanLL_ModeTransition(CAN_CHANNEL_AND_HW_CHANNEL_CANPARA_FIRST transitionRequest, busOffRecovery, doRamCheck);
      CanHL_ApplCanTimerLoop((uint8)CAN_LOOP_MAX);
    } while( transitionState != kCanOk );
    CanHL_ApplCanTimerEnd ((uint8)CAN_LOOP_MAX);
  }
  if( transitionState == kCanRequested ){

    Can_SetModeTransitionRequest(channel, transitionRequest);
    Can_SetBusOffTransitionRequest(channel, busOffRecovery);
    Can_SetRamCheckTransitionRequest(channel, doRamCheck);
  }
  return transitionState;
}

V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanHL_NotifyTransition( CAN_CHANNEL_CANTYPE_FIRST uint8 canState, CanIf_ControllerModeType canIfState, uint8 transitionState ){

  if( transitionState == kCanOk ){

    Can_SetLogStatus(channel, (uint8)((Can_GetLogStatus(channel) & CAN_STATUS_MASK_NOMODE) | canState));

    Can_SetModeTransitionRequest(channel, kCanModeNone);

    CanIf_ControllerModeIndication( (uint8)Can_GetCanToCanIfChannelMapping(channel), canIfState );
  }
  CAN_DUMMY_STATEMENT(transitionState);
}

#if defined(C_ENABLE_CANCEL_IN_HW)

V_DEF_FUNC(CAN_LOCAL_INLINE, Can_ReturnType, STATIC_CODE) CanHL_IsHigherCanIdPrio( Can_IdType CanId1, Can_IdType CanId2 ){

  Can_ReturnType retval = CAN_NOT_OK;
  Can_IdType tmpCanId1, tmpCanId2;
  tmpCanId1 = CanId1;
  tmpCanId2 = CanId2;

#if defined(C_ENABLE_MIXED_ID)

  if(((tmpCanId1) & CAN_ID_IDE_MASK) == CAN_ID_IDE_MASK){
    tmpCanId1 = tmpCanId1 & (Can_IdType)(CAN_ID_MASK);
  } else {
    tmpCanId1 = (Can_IdType)(((tmpCanId1) & CAN_ID_MASK_STD) << 18);
  }
  if(((tmpCanId2) & CAN_ID_IDE_MASK) == CAN_ID_IDE_MASK){
    tmpCanId2 = tmpCanId2 & (Can_IdType)(CAN_ID_MASK);
  } else {
    tmpCanId2 = (Can_IdType)(((tmpCanId2) & CAN_ID_MASK_STD) << 18);
  }
#else

  tmpCanId1 = tmpCanId1 & (Can_IdType)CAN_ID_MASK;
  tmpCanId2 = tmpCanId2 & (Can_IdType)CAN_ID_MASK;
#endif

  if(tmpCanId1 < tmpCanId2){
    retval = CAN_OK;
  }
  return retval;
}
#endif

V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanHL_WritePrepare( CAN_CHANNEL_CANTYPE_FIRST CanTxTransmissionParaStructPtr txPara ){

  txPara->mailboxElement = 0u;
  txPara->activeSendObject = CanHL_GetActiveSendObject(txPara->mailboxHandle, 0u);
#if defined(C_ENABLE_TX_FULLCAN_OBJECTS)
  if( Can_GetMailboxType(txPara->mailboxHandle) != CAN_TX_FULLCAN_TYPE )
#endif
  {
#if defined(C_ENABLE_MULTIPLEXED_TRANSMISSION) || defined(C_ENABLE_TX_HW_FIFO) || defined(C_ENABLE_CANCEL_IN_HW)
    CanObjectHandle mailboxElement_max;
    mailboxElement_max = Can_GetMailboxSize(txPara->mailboxHandle);

#if defined(C_ENABLE_TX_HW_FIFO)
    if(Can_GetMailboxType(txPara->mailboxHandle) == CAN_TX_BASICCAN_FIFO_TYPE){
       txPara->mailboxElement = (CanObjectHandle)Can_GetTxHwFifoWriteIndex(Can_GetMailboxTxHwFifo(txPara->mailboxHandle));
       txPara->activeSendObject += txPara->mailboxElement;
    }
    else
#endif
    {
      CanObjectHandle mailboxElementFound;
      CanObjectHandle activeSendObjectFound;
      mailboxElementFound = mailboxElement_max;
      activeSendObjectFound = mailboxElement_max;
      for(txPara->mailboxElement = 0u; txPara->mailboxElement < mailboxElement_max; txPara->mailboxElement++)
      {
#if(CAN_IDENTICAL_ID_CANCELLATION == STD_ON) && defined(C_ENABLE_CANCEL_IN_HW)
        if( ((txPara->pdu.id) == Can_GetActiveSendId(txPara->activeSendObject) ) && (Can_GetActiveSendState(txPara->activeSendObject) != kCanBufferFree) )
        {
          mailboxElementFound = txPara->mailboxElement;
          activeSendObjectFound = txPara->activeSendObject;
          break;
        }
        if(Can_GetActiveSendState(txPara->activeSendObject) == kCanBufferFree)
        {
          mailboxElementFound = txPara->mailboxElement;
          activeSendObjectFound = txPara->activeSendObject;
        }
#else
        if(Can_GetActiveSendState(txPara->activeSendObject) == kCanBufferFree)
        {
          mailboxElementFound = txPara->mailboxElement;
          activeSendObjectFound = txPara->activeSendObject;
          break;
        }
#endif
        txPara->activeSendObject++;
      }
#if defined(C_ENABLE_CANCEL_IN_HW)
      if(mailboxElementFound == mailboxElement_max)
      {
        Can_IdType lowestPrioId = txPara->pdu.id;
        txPara->activeSendObject = CanHL_GetActiveSendObject(txPara->mailboxHandle, 0u);
        for(txPara->mailboxElement = 0u; txPara->mailboxElement < mailboxElement_max; txPara->mailboxElement++)
        {
          if(Can_GetActiveSendState(txPara->activeSendObject) == kCanBufferSend)
          {
            if(CanHL_IsHigherCanIdPrio(lowestPrioId, Can_GetActiveSendId(txPara->activeSendObject)) == CAN_OK)
            {
              lowestPrioId = Can_GetActiveSendId(txPara->activeSendObject);
              mailboxElementFound = txPara->mailboxElement;
              activeSendObjectFound = txPara->activeSendObject;
            }
          }
          txPara->activeSendObject++;
        }
      }
#endif
      if(mailboxElementFound == mailboxElement_max)
      {
        txPara->mailboxElement = 0u;
        txPara->activeSendObject = CanHL_GetActiveSendObject(txPara->mailboxHandle, 0u);
      }
      else
      {
        txPara->mailboxElement = mailboxElementFound;
        txPara->activeSendObject = activeSendObjectFound;
#if defined(C_ENABLE_CANCEL_IN_HW)
        CanHL_WritePrepareCancelTx(CAN_CHANNEL_CANPARA_FIRST txPara);
#endif
      }
    }
#endif
  }
  CAN_CHANNEL_DUMMY_STATEMENT;

}

#if defined(C_ENABLE_CANCEL_IN_HW) || \
   (defined(C_ENABLE_TX_HW_FIFO) && defined(CAN_ENABLE_GENERIC_CONFIRMATION_API2) )

V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanHL_WriteSavePduInfo( CanTxTransmissionParaStructPtr txPara ){

    uint16 activeSendData;
    activeSendData = CanHL_GetActiveSendData(txPara->mailboxHandle, txPara->mailboxElement);

    if(txPara->pdu.sdu != NULL_PTR){
#if(CAN_SAFE_BSW == STD_ON)
      if(Can_GetSizeOfActiveSendData() >= (activeSendData + txPara->pdu.length))
#endif
      {

        VStdMemCpy((void*)&Can_GetActiveSendData(activeSendData), (void*)txPara->pdu.sdu, txPara->pdu.length);
      }
    }

    Can_SetActiveSendId(txPara->activeSendObject, txPara->pdu.id);
    Can_SetActiveSendLength(txPara->activeSendObject, txPara->pdu.length);
    Can_SetActiveSendSdu(txPara->activeSendObject, &Can_GetActiveSendData(activeSendData));
    Can_SetActiveSendSwPduHandle(txPara->activeSendObject, txPara->pdu.swPduHandle);
}
#endif

#if defined(C_ENABLE_CANCEL_IN_HW)

V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanHL_WritePrepareCancelTx( CAN_CHANNEL_CANTYPE_FIRST CanTxTransmissionParaStructPtr txPara ){

  if(Can_GetActiveSendState(txPara->activeSendObject) == kCanBufferFree){
    CanHL_WriteSavePduInfo(txPara);
  }
  else if(Can_GetActiveSendState(txPara->activeSendObject) == kCanBufferSend){

    tCanTxCancellationParaStruct txCancellationPara;
    txCancellationPara.mailboxHandle = txPara->mailboxHandle;
    txCancellationPara.hwObjHandle = txPara->hwObjHandle;
    txCancellationPara.mailboxElement = txPara->mailboxElement;
    txCancellationPara.activeSendObject = txPara->activeSendObject;
    txCancellationPara.canHandleCurTxObj = kCanBufferCancel;

    CanLL_TxCancelInHw(CAN_CHANNEL_AND_HW_CHANNEL_CANPARA_FIRST &txCancellationPara);
    Can_SetActiveSendState(txPara->activeSendObject, kCanBufferCancel);

  }
  else{

  }
}
#endif

V_DEF_FUNC(CAN_LOCAL_INLINE, Can_ReturnType, STATIC_CODE) CanHL_WriteStart( CAN_CHANNEL_CANTYPE_FIRST CanTxTransmissionParaStructPtr txPara ){

  Can_ReturnType retval = CAN_OK;

  if(Can_GetActiveSendState(txPara->activeSendObject) == kCanBufferFree){
    uint8 llretval;

    Can_SetActiveSendPdu(txPara->activeSendObject, txPara->pdu.swPduHandle);
    Can_SetActiveSendState(txPara->activeSendObject, kCanBufferSend);
#if defined(C_ENABLE_PRETRANSMIT_FCT)

    Appl_GenericPreTransmit( (uint8)channel, &(txPara->pdu) );
#endif
#if defined(C_ENABLE_TX_HW_FIFO)
    if(Can_GetMailboxType(txPara->mailboxHandle) == CAN_TX_BASICCAN_FIFO_TYPE){
      uint16 txHwFifo;
#if defined(CAN_ENABLE_GENERIC_CONFIRMATION_API2)
      CanHL_WriteSavePduInfo(txPara);
#endif

      SchM_Enter_Can_CAN_EXCLUSIVE_AREA_7();
      txHwFifo = Can_GetMailboxTxHwFifo(txPara->mailboxHandle);
#if(CAN_SAFE_BSW == STD_ON)
      if(txHwFifo >= (uint16)Can_GetSizeOfTxHwFifo())
      {
        txHwFifo = 0u;
      }
#endif
      Can_IncTxHwFifoFillCount(txHwFifo);
      if(Can_GetTxHwFifoWriteIndex(txHwFifo) < ((uint16)Can_GetMailboxSize(txPara->mailboxHandle) - (uint16)1u) )
      {
        Can_IncTxHwFifoWriteIndex(txHwFifo);
      }
      else
      {
        Can_SetTxHwFifoWriteIndex(txHwFifo,0);
      }
      SchM_Exit_Can_CAN_EXCLUSIVE_AREA_7();
    }
#endif

    CanLL_TxBegin(CAN_CHANNEL_AND_HW_CHANNEL_CANPARA_FIRST txPara);

    txPara->dlcRaw = MK_TX_DLC(CAN_LEN2DLC(txPara->pdu.length));
#if defined(C_ENABLE_EXTENDED_ID)
#if defined(C_ENABLE_MIXED_ID)
    if( ((txPara->pdu.id) & CAN_ID_IDE_MASK) != CAN_ID_IDE_MASK){
      SET_PARASTRUCT_IDRAW_TX_STD(txPara, txPara->pdu.id);
    }
    else
#endif
    {
      SET_PARASTRUCT_IDRAW_TX_EXT(txPara, txPara->pdu.id);
    }
#else
    {
      SET_PARASTRUCT_IDRAW_TX_STD(txPara, txPara->pdu.id);
    }
#endif

    CanLL_TxSetMailbox(CAN_CHANNEL_AND_HW_CHANNEL_CANPARA_FIRST txPara);
    if(txPara->pdu.sdu != NULL_PTR){
      txPara->CanMemCopySrcPtr = txPara->pdu.sdu;
      CanLL_TxCopyToCan(CAN_CHANNEL_AND_HW_CHANNEL_CANPARA_FIRST txPara);
    }

    llretval = CanLL_TxStart(CAN_CHANNEL_AND_HW_CHANNEL_CANPARA_FIRST txPara);
    if(llretval == kCanFailed){
      retval = CAN_NOT_OK;
      Can_SetActiveSendState(txPara->activeSendObject, kCanBufferFree);
    }

    CanLL_TxEnd(CAN_CHANNEL_AND_HW_CHANNEL_CANPARA_FIRST txPara);
    CAN_DUMMY_STATEMENT(llretval);
  }
  else{
    retval = CAN_BUSY;
  }
  return retval;
}

V_DEF_FUNC(CAN_LOCAL_INLINE, CanObjectHandle, STATIC_CODE) CanHL_GetActiveSendObject( Can_HwHandleType mailboxHandle, Can_HwHandleType mailboxElement ){

  CanObjectHandle activeSendObject;

  activeSendObject = (CanObjectHandle) Can_GetMailboxActiveSendObject(mailboxHandle) + mailboxElement;
#if(CAN_SAFE_BSW == STD_ON)
  if(activeSendObject >= (Can_HwHandleType)Can_GetSizeOfActiveSendObject()){
    activeSendObject = ((Can_HwHandleType)Can_GetSizeOfActiveSendObject() - (Can_HwHandleType)1u);
#if(CAN_DEV_ERROR_REPORT == STD_ON)
    Can_CallDetReportError(CAN_WRITE_ID, CAN_E_PARAM_HANDLE);
#endif
  }
#endif
  return activeSendObject;
}

#if defined(C_ENABLE_CANCEL_IN_HW) || \
   (defined(C_ENABLE_TX_HW_FIFO) && defined(CAN_ENABLE_GENERIC_CONFIRMATION_API2) )

V_DEF_FUNC(CAN_LOCAL_INLINE, uint16, STATIC_CODE) CanHL_GetActiveSendData( Can_HwHandleType mailboxHandle, uint8 mailboxElement ){

  uint16 activeSendData;

  activeSendData = (uint16) (Can_GetMailboxActiveSendData(mailboxHandle) + ((uint16)mailboxElement * (uint16)Can_GetMailboxDataLen(mailboxHandle)));
#if(CAN_SAFE_BSW == STD_ON)
  if((activeSendData + Can_GetMailboxDataLen(mailboxHandle)) > Can_GetSizeOfActiveSendData()){
    activeSendData = 0u;
#if(CAN_DEV_ERROR_REPORT == STD_ON)
    Can_CallDetReportError(CAN_WRITE_ID, CAN_E_PARAM_HANDLE);
#endif
  }
#endif
  return activeSendData;
}
#endif

#if defined(C_ENABLE_CAN_RAM_CHECK)

V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanHL_RamCheckMailboxNotification( CAN_CHANNEL_CANTYPE_FIRST CanInitParaStructPtr initPara ){

  Can_SetMailboxState(initPara->mailboxHandle, kCanFailed);

  Can_SetLogStatus(channel, Can_GetLogStatus(channel) | CAN_DEACTIVATE_CONTROLLER);

#if defined(C_ENABLE_CAN_RAM_CHECK_EXTENDED)
  CanIf_RamCheckCorruptMailbox((uint8)Can_GetCanToCanIfChannelMapping(channel), initPara->mailboxHandle);
#else
#if defined(C_ENABLE_NOTIFY_CORRUPT_MAILBOX)
  Appl_CanCorruptMailbox((uint8)channel, (initPara->hwObjHandle));
#endif
#endif
}
#endif

V_DEF_FUNC(CAN_LOCAL_INLINE, uint8, STATIC_CODE) CanHL_InitBegin( CAN_CHANNEL_CANTYPE_FIRST CanInitParaStructPtr initPara ){

  uint8 initOk;

  initOk = kCanFailed;
  if(CanLL_InitBegin(CAN_CHANNEL_AND_HW_CHANNEL_CANPARA_FIRST initPara) == kCanOk){
#if defined(C_ENABLE_CAN_RAM_CHECK_EXTENDED)

    if(initPara->doRamCheck == kCanExecuteRamCheck){
      initPara->isChRamCheckFail |= CAN_RAM_CHECK_BEGIN_REG_RESULT(channel, initPara);
    }
#endif

    initOk = CanLL_InitBeginSetRegisters(CAN_CHANNEL_AND_HW_CHANNEL_CANPARA_FIRST initPara);
  }
  return initOk;
}

#if defined(C_ENABLE_TX_FULLCAN_OBJECTS)

V_DEF_FUNC(CAN_LOCAL_INLINE, uint8, STATIC_CODE) CanHL_InitTxFullCAN( CAN_CHANNEL_CANTYPE_FIRST CanInitParaStructPtr initPara ){

  uint8 initOk;
  uint8 mailboxState;
  CanObjectHandle activeSendObject;
#if defined(C_ENABLE_CAN_RAM_CHECK)
  uint8 isMbRamCheckFail;
#endif

  initOk = kCanOk;

  for(initPara->mailboxHandle = Can_GetTxFullHandleStart(canHwChannel); initPara->mailboxHandle < Can_GetTxFullHandleStop(canHwChannel); initPara->mailboxHandle++){
    initPara->hwObjHandle = Can_GetMailboxHwHandle(initPara->mailboxHandle);
    activeSendObject = CanHL_GetActiveSendObject(initPara->mailboxHandle, 0u);
    Can_SetActiveSendState(activeSendObject, kCanBufferFree);
#if defined(C_ENABLE_CAN_RAM_CHECK)

    isMbRamCheckFail = kCanFalse;
    if(initPara->doRamCheck == kCanExecuteRamCheck){
      isMbRamCheckFail = CAN_RAM_CHECK_MAILBOX_RESULT(channel, initPara);
    }
#endif

    mailboxState = CanLL_InitMailboxTx(CAN_CHANNEL_AND_HW_CHANNEL_CANPARA_FIRST initPara);
    initOk &= mailboxState;
#if defined(C_ENABLE_CAN_RAM_CHECK)
    if( (Can_GetLogStatus(channel) & CAN_STATUS_INIT) != CAN_STATUS_INIT ){
      Can_SetMailboxState(initPara->mailboxHandle, mailboxState);
    }
    if( (isMbRamCheckFail == kCanTrue) || (Can_GetMailboxState(initPara->mailboxHandle) == kCanFailed) ){
      CanLL_InitMailboxTxDeactivate(CAN_CHANNEL_AND_HW_CHANNEL_CANPARA_FIRST initPara);
      if(isMbRamCheckFail == kCanTrue)
      {
        CanHL_RamCheckMailboxNotification(CAN_CHANNEL_CANPARA_FIRST initPara);
      }
    }
#endif
  }
  return initOk;
}
#endif

V_DEF_FUNC(CAN_LOCAL_INLINE, uint8, STATIC_CODE) CanHL_InitTxBasicCAN( CAN_CHANNEL_CANTYPE_FIRST CanInitParaStructPtr initPara ){

  uint8 initOk;
  uint8 mailboxState;
  CanObjectHandle activeSendObject;
#if defined(C_ENABLE_CAN_RAM_CHECK)
  uint8 isMbRamCheckFail;
#endif

  initOk = kCanOk;
  initPara->mailboxHandle = Can_GetTxBasicHandleStart(canHwChannel);
#if defined(C_ENABLE_MULTIPLE_BASICCAN_TX)
  for(; initPara->mailboxHandle < Can_GetTxBasicHandleStop(canHwChannel); initPara->mailboxHandle++)
#endif
  {
#if defined(C_ENABLE_MULTIPLEXED_TRANSMISSION) || defined(C_ENABLE_TX_HW_FIFO)
    CanObjectHandle activeSendObjectStop;
#endif
    initPara->hwObjHandle = Can_GetMailboxHwHandle(initPara->mailboxHandle);
    activeSendObject = CanHL_GetActiveSendObject(initPara->mailboxHandle, 0u);
#if defined(C_ENABLE_MULTIPLEXED_TRANSMISSION) || defined(C_ENABLE_TX_HW_FIFO)
    activeSendObjectStop = activeSendObject + Can_GetMailboxSize(initPara->mailboxHandle);
    for(; activeSendObject < activeSendObjectStop; activeSendObject++)
#endif
    {
      Can_SetActiveSendState(activeSendObject, kCanBufferFree);
    }
#if defined(C_ENABLE_TX_HW_FIFO)
    if(Can_GetMailboxType(initPara->mailboxHandle) == CAN_TX_BASICCAN_FIFO_TYPE){
      uint16 txHwFifo;
      txHwFifo = Can_GetMailboxTxHwFifo(initPara->mailboxHandle);
#if(CAN_SAFE_BSW == STD_ON)
      if(txHwFifo >= (uint16)Can_GetSizeOfTxHwFifo())
      {
        txHwFifo = 0u;
        initOk = kCanFailed;
      }
#endif
      Can_SetTxHwFifoWriteIndex(txHwFifo, 0u);
      Can_SetTxHwFifoReadIndex(txHwFifo, 0u);
      Can_SetTxHwFifoFillCount(txHwFifo, 0u);
    }
#endif
#if defined(C_ENABLE_CAN_RAM_CHECK)

    isMbRamCheckFail = kCanFalse;
    if(initPara->doRamCheck == kCanExecuteRamCheck){
      isMbRamCheckFail = CAN_RAM_CHECK_MAILBOX_RESULT(channel, initPara);
    }
#endif

    mailboxState = CanLL_InitMailboxTx(CAN_CHANNEL_AND_HW_CHANNEL_CANPARA_FIRST initPara);
    initOk &= mailboxState;
#if defined(C_ENABLE_CAN_RAM_CHECK)
    if( (Can_GetLogStatus(channel) & CAN_STATUS_INIT) != CAN_STATUS_INIT ){
      Can_SetMailboxState(initPara->mailboxHandle, mailboxState);
    }
    if( (isMbRamCheckFail == kCanTrue) || (Can_GetMailboxState(initPara->mailboxHandle) == kCanFailed) ){
      CanLL_InitMailboxTxDeactivate(CAN_CHANNEL_AND_HW_CHANNEL_CANPARA_FIRST initPara);
      if(isMbRamCheckFail == kCanTrue)
      {
        CanHL_RamCheckMailboxNotification(CAN_CHANNEL_CANPARA_FIRST initPara);
      }
    }
#endif
  }
  return initOk;
}

#if defined(C_ENABLE_RX_FULLCAN_OBJECTS)

V_DEF_FUNC(CAN_LOCAL_INLINE, uint8, STATIC_CODE) CanHL_InitRxFullCAN( CAN_CHANNEL_CANTYPE_FIRST CanInitParaStructPtr initPara ){

  uint8 initOk;
  uint8 mailboxState;

  initOk = kCanOk;
  for(initPara->mailboxHandle = Can_GetRxFullHandleStart(canHwChannel); initPara->mailboxHandle < Can_GetRxFullHandleStop(canHwChannel); initPara->mailboxHandle++){
    initPara->hwObjHandle=Can_GetMailboxHwHandle(initPara->mailboxHandle);

#if defined(C_ENABLE_EXTENDED_ID)
#if defined(C_ENABLE_MIXED_ID)
    if( (Can_GetMailboxIDValue(initPara->mailboxHandle) & CAN_ID_IDE_MASK) != CAN_ID_IDE_MASK){
      initPara->idType = kCanIdTypeStd;
      SET_PARASTRUCT_IDRAW_RX_STD(initPara, Can_GetMailboxIDValue(initPara->mailboxHandle));
    }
    else
#endif
    {
      initPara->idType = kCanIdTypeExt;
      SET_PARASTRUCT_IDRAW_RX_EXT(initPara, Can_GetMailboxIDValue(initPara->mailboxHandle));
    }
#else
    initPara->idType = kCanIdTypeStd;
    SET_PARASTRUCT_IDRAW_RX_STD(initPara, Can_GetMailboxIDValue(initPara->mailboxHandle));
#endif

    mailboxState = CanLL_InitMailboxRxFullCan(CAN_CHANNEL_AND_HW_CHANNEL_CANPARA_FIRST initPara);
    initOk &= mailboxState;

  }
  return initOk;
}
#endif

#if defined(C_ENABLE_RX_BASICCAN_OBJECTS)

V_DEF_FUNC(CAN_LOCAL_INLINE, uint8, STATIC_CODE) CanHL_InitRxBasicCAN( CAN_CHANNEL_CANTYPE_FIRST CanInitParaStructPtr initPara ){

  uint8 initOk;
  uint8 mailboxState;

  initOk = kCanOk;
  for(initPara->mailboxHandle = Can_GetRxBasicHandleStart(canHwChannel); initPara->mailboxHandle < Can_GetRxBasicHandleStop(canHwChannel); initPara->mailboxHandle++){
    initPara->hwObjHandle = Can_GetMailboxHwHandle(initPara->mailboxHandle);

    mailboxState = CanLL_InitMailboxRxBasicCan(CAN_CHANNEL_AND_HW_CHANNEL_CANPARA_FIRST initPara);
    initOk &= mailboxState;
  }
  return initOk;
}
#endif

V_DEF_FUNC(CAN_LOCAL_INLINE, uint8, STATIC_CODE) CanHL_InitEnd_InitMode( CAN_CHANNEL_CANTYPE_FIRST CanInitParaStructPtr initPara ){

  uint8 initOk;

  initOk = kCanOk;

  initOk &= CanLL_InitEndSetRegisters(CAN_CHANNEL_AND_HW_CHANNEL_CANPARA_FIRST initPara);
  initOk &= CanLL_InitEnd( CAN_CHANNEL_AND_HW_CHANNEL_CANPARA_FIRST initPara );
  return initOk;
}

#if defined(C_ENABLE_RX_BASICCAN_OBJECTS)
#if defined(C_ENABLE_RX_BASICCAN_POLLING)

V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanHL_RxBasicCanPolling( CAN_HW_CHANNEL_CANTYPE_ONLY ){

  tCanTaskParaStruct taskPara;

  if(CanLL_RxBasicIsGlobalIndPending(CAN_HW_CHANNEL_CANPARA_ONLY) == kCanTrue){

    for(taskPara.mailboxHandle = Can_GetRxBasicHandleStart(canHwChannel); taskPara.mailboxHandle < Can_GetRxBasicHandleStop(canHwChannel); taskPara.mailboxHandle++){
      taskPara.hwObjHandle = Can_GetMailboxHwHandle(taskPara.mailboxHandle);
#if defined(C_ENABLE_INDIVIDUAL_POLLING)

      if( Can_IsMailboxIndivPolling(taskPara.mailboxHandle))
#endif
      {

        CanLL_RxBasicProcessPendings(CAN_HW_CHANNEL_CANPARA_FIRST &taskPara);
      }
    }
  }
}
#endif
#endif

#if defined(C_ENABLE_RX_FULLCAN_OBJECTS)
#if defined(C_ENABLE_RX_FULLCAN_POLLING)

V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanHL_RxFullCanPolling( CAN_HW_CHANNEL_CANTYPE_ONLY ){

  tCanTaskParaStruct taskPara;

  if(CanLL_RxFullIsGlobalIndPending(CAN_HW_CHANNEL_CANPARA_ONLY) == kCanTrue){

    for(taskPara.mailboxHandle = Can_GetRxFullHandleStart(canHwChannel); taskPara.mailboxHandle < Can_GetRxFullHandleStop(canHwChannel); taskPara.mailboxHandle++ ){
      taskPara.hwObjHandle = Can_GetMailboxHwHandle(taskPara.mailboxHandle);
#if defined(C_ENABLE_INDIVIDUAL_POLLING)

      if( Can_IsMailboxIndivPolling(taskPara.mailboxHandle))
#endif
      {

        CanLL_RxFullProcessPendings(CAN_HW_CHANNEL_CANPARA_FIRST &taskPara);
      }
    }
  }
}
#endif
#endif

#if defined(C_ENABLE_RX_FULLCAN_OBJECTS) || defined(C_ENABLE_RX_BASICCAN_OBJECTS)

V_DEF_FUNC(CAN_LOCAL_INLINE, uint8, STATIC_CODE) CanHL_RxMsgReceivedNotification( CAN_CHANNEL_CANTYPE_FIRST CanRxInfoStructPtr rxStructPtr ){

#if !defined(C_ENABLE_RX_QUEUE) && (CAN_GENERIC_PRECOPY == STD_ON)
  Can_ReturnType generic_retval;
#endif
  uint8 errorId;
  errorId = CAN_E_NO_ERROR;

#if defined(C_ENABLE_RX_QUEUE)

  SchM_Enter_Can_CAN_EXCLUSIVE_AREA_4();
  if(Can_GetRxQueueInfo().Count < Can_GetSizeOfRxQueueBuffer()){

    Can_GetRxQueueBuffer(Can_GetRxQueueInfo().WriteIndex).Hrh = rxStructPtr->localMailboxHandle;
    Can_GetRxQueueBuffer(Can_GetRxQueueInfo().WriteIndex).id  = rxStructPtr->localId;
    Can_GetRxQueueBuffer(Can_GetRxQueueInfo().WriteIndex).dlc = rxStructPtr->localDlc;

#if(CAN_DEV_ERROR_DETECT == STD_ON)
    if(canRxQueueMaxDataSize < rxStructPtr->localDlc){
      errorId = CAN_E_PARAM_DLC;
    }
    else
#endif
    {

      VStdMemCpy((void*)Can_GetRxQueueBuffer(Can_GetRxQueueInfo().WriteIndex).data, (void*)rxStructPtr->pChipData, rxStructPtr->localDlc);
    }

    Can_GetRxQueueInfo().Count++;
    if(Can_GetRxQueueInfo().WriteIndex < ((uint16)Can_GetSizeOfRxQueueBuffer() - (uint16)1u) ){
      Can_GetRxQueueInfo().WriteIndex++;
    }
    else{
      Can_GetRxQueueInfo().WriteIndex = 0u;
    }
  }
#if(CAN_DEV_ERROR_REPORT == STD_ON)
  else{
    errorId = CAN_E_RXQUEUE;
  }
#endif
  SchM_Exit_Can_CAN_EXCLUSIVE_AREA_4();
#else

#if(CAN_GENERIC_PRECOPY == STD_ON)
#if defined(C_ENABLE_MIRROR_MODE)
  if(Can_GetMirrorModeState(channel) == CDDMIRROR_INACTIVE){
    generic_retval = CAN_OK;
  }
  else
#endif
  {
    generic_retval = Appl_GenericPrecopy((uint8)channel, (rxStructPtr->localId & CAN_ID_MASK_IN_GENERIC_CALLOUT), rxStructPtr->localDlc, (Can_DataPtrType)rxStructPtr->pChipData);
  }
  if(generic_retval == CAN_OK)
#endif
  {
    EcuabCanIf_RxIndication(rxStructPtr->localMailboxHandle, rxStructPtr->localId, rxStructPtr->localDlc, (Can_DataPtrType)rxStructPtr->pChipData);
  }
#endif
  CAN_CHANNEL_DUMMY_STATEMENT;
  CAN_DUMMY_STATEMENT(errorId);
  return errorId;
}
#endif

#if defined(C_ENABLE_RX_QUEUE)

V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanHL_RxQueueExecution(void){

  uint8 errorId;
  errorId = CAN_E_NO_ERROR;

  while( Can_GetRxQueueInfo().Count != (uint16)0 ){
#if(CAN_GENERIC_PRECOPY == STD_ON)
    Can_ReturnType generic_retval;
    CAN_CHANNEL_CANTYPE_LOCAL
    generic_retval = CAN_NOT_OK;
#if !defined( C_SINGLE_RECEIVE_CHANNEL )
    channel = Can_GetMailboxController(Can_GetRxQueueBuffer(Can_GetRxQueueInfo().ReadIndex).Hrh);
#if(CAN_DEV_ERROR_DETECT == STD_ON)
    if(channel >= kCanNumberOfChannels){
      errorId = CAN_E_PARAM_CONTROLLER;
    }
    else
#endif
#endif
#if defined(C_ENABLE_MIRROR_MODE)
    if(Can_GetMirrorModeState(channel) == CDDMIRROR_INACTIVE){
      generic_retval = CAN_OK;
    }
    else
#endif
    {
      generic_retval = Appl_GenericPrecopy( (uint8)channel,
                (Can_GetRxQueueBuffer(Can_GetRxQueueInfo().ReadIndex).id & CAN_ID_MASK_IN_GENERIC_CALLOUT),
                Can_GetRxQueueBuffer(Can_GetRxQueueInfo().ReadIndex).dlc,
                (Can_DataPtrType)Can_GetRxQueueBuffer(Can_GetRxQueueInfo().ReadIndex).data );
    }
    if(generic_retval == CAN_OK)
#endif
    {
      EcuabCanIf_RxIndication( Can_GetRxQueueBuffer(Can_GetRxQueueInfo().ReadIndex).Hrh,
              Can_GetRxQueueBuffer(Can_GetRxQueueInfo().ReadIndex).id,
              Can_GetRxQueueBuffer(Can_GetRxQueueInfo().ReadIndex).dlc,
              (Can_DataPtrType)Can_GetRxQueueBuffer(Can_GetRxQueueInfo().ReadIndex).data );
    }

    SchM_Enter_Can_CAN_EXCLUSIVE_AREA_4();

    if(Can_GetRxQueueInfo().ReadIndex >= ((uint16)Can_GetSizeOfRxQueueBuffer() - (uint16)1u) ){
      Can_GetRxQueueInfo().ReadIndex = 0u;
    }
    else{
      Can_GetRxQueueInfo().ReadIndex++;
    }
    Can_GetRxQueueInfo().Count--;
    SchM_Exit_Can_CAN_EXCLUSIVE_AREA_4();
  }
#if(CAN_DEV_ERROR_REPORT == STD_ON)
  if(errorId != CAN_E_NO_ERROR){
    Can_CallDetReportError(CAN_MAINFCT_READ_ID, errorId);
  }
#else
  CAN_DUMMY_STATEMENT(errorId);
#endif
}
#endif

#if defined(C_ENABLE_CANCEL_TX_IN_HW)
#endif

V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_InitBegin( CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanInitParaStructPtr initPara ){

#if defined(C_ENABLE_LL_WAKEUP_SUPPORT)
#if !defined(C_ENABLE_WAKEUP_POLLING)
#if defined(C_ENABLE_LL_CAN_INTCTRL)

  CanLL_CanWakeupInterruptDisable(CAN_HW_CHANNEL_CANPARA_FIRST &Can_GetCanInterruptOldStatus(canHwChannel));
#endif
#if defined(C_ENABLE_LL_CAN_INTCB)

  ApplCanWakeupInterruptDisable(canHwChannel);
#endif
#endif
#endif

  CAN_CHANNEL_AND_HW_CHANNEL_DUMMY_STATEMENT;
  CAN_DUMMY_STATEMENT(initPara);
  return (kCanOk);
}

#if defined( C_ENABLE_CAN_RAM_CHECK_EXTENDED )

V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_InitBeginIsRegisterCorrupt( CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanInitParaStructPtr initPara ){

  vuint8 canRegCheckFailed;
  vuint8 idx;
#if defined(C_MULTIPLE_PHYS_CHANNEL)
  CanChannelHandle canPhysChannel = mCanLogToPhys(canHwChannel);
#endif

  canRegCheckFailed = kCanFalse;

  for(idx=0u; idx<3u; idx++){

    Can->ChCtrl[canPhysChannel].BCFG = (CanMemCheckValues32bit[idx] & kCanRamCheckMaskBCFG);
#if defined(C_ENABLE_RSCAN_FD_LAYOUT)

    Can->ChCtrlFd[canPhysChannel].BCFG = (CanMemCheckValues32bit[idx] & kCanRamCheckMaskFDBCFG);

    Can->ChCtrlFd[canPhysChannel].FDCFG = (CanMemCheckValues32bit[idx] & kCanRamCheckMaskFDCFG);
#endif

    Can->ChCtrl[canPhysChannel].CR = ((CanMemCheckValues32bit[idx] & kCanRamCheckMaskCR) | kCanResetMode);

    Can->CTBIER[CanLL_TxWordIndex(canPhysChannel)] =
      ((Can->CTBIER[CanLL_TxWordIndex(canPhysChannel)] & CanLL_TxMaskWordClear(canPhysChannel)) | (CanMemCheckValuesRegSize[idx] & CanLL_TxMaskWord(canPhysChannel)));

    if(   ((Can->ChCtrl[canPhysChannel].BCFG & kCanRamCheckMaskBCFG) != (CanMemCheckValues32bit[idx] & kCanRamCheckMaskBCFG))
#if defined(C_ENABLE_RSCAN_FD_LAYOUT)
        || ((Can->ChCtrlFd[canPhysChannel].BCFG & kCanRamCheckMaskFDBCFG) != (CanMemCheckValues32bit[idx] & kCanRamCheckMaskFDBCFG))
        || ((Can->ChCtrlFd[canPhysChannel].FDCFG & kCanRamCheckMaskFDCFG) != (CanMemCheckValues32bit[idx] & kCanRamCheckMaskFDCFG))
#endif
        || ((Can->ChCtrl[canPhysChannel].CR & kCanRamCheckMaskCR) != (CanMemCheckValues32bit[idx] & kCanRamCheckMaskCR))
        || ((Can->CTBIER[CanLL_TxWordIndex(canPhysChannel)] & CanLL_TxMaskWord(canPhysChannel)) != (CanMemCheckValuesRegSize[idx] & CanLL_TxMaskWord(canPhysChannel)))
       ){
      canRegCheckFailed = kCanTrue;
    }
  }

  if(Can->TQCR[canPhysChannel] != kCanZero){
    canRegCheckFailed = kCanTrue;
  }

  if(Can->THCR[canPhysChannel] != kCanZero){
    canRegCheckFailed = kCanTrue;
  }

  CAN_CHANNEL_AND_HW_CHANNEL_DUMMY_STATEMENT;
  CAN_DUMMY_STATEMENT(initPara);
  return (canRegCheckFailed);
}

#endif

V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_InitBeginSetRegisters( CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanInitParaStructPtr initPara ){

  vuint32 canTmpReg32;
  kCanRegSize canTmpRegRs;
#if defined(C_MULTIPLE_PHYS_CHANNEL)
  CanChannelHandle canPhysChannel = mCanLogToPhys(canHwChannel);
#endif

  CanLL_WriteReg32(CAN_CHANNEL_CANPARA_FIRST &Can->ChCtrl[canPhysChannel].BCFG, Can_GetInitObjectBitTiming(initPara->initObject), initPara);
#if defined(C_ENABLE_RSCAN_FD_LAYOUT)
  CanLL_WriteReg32(CAN_CHANNEL_CANPARA_FIRST &Can->ChCtrlFd[canPhysChannel].BCFG, Can_GetInitObjectBitTimingData(initPara->initObject), initPara);
  CanLL_WriteReg32(CAN_CHANNEL_CANPARA_FIRST &Can->ChCtrlFd[canPhysChannel].FDCFG, Can_GetInitObjectCanFdConfig(initPara->initObject), initPara);
#endif

  canTmpReg32 = kCanCrHaltAtBusoff | kCanResetMode;
#if !defined(C_ENABLE_ERROR_POLLING)
  canTmpReg32 |= kCanCrIntMaskBusoff;
#endif
#if defined(C_ENABLE_TX_POLLING) && !defined(C_ENABLE_INDIVIDUAL_POLLING)
#else
#if defined(C_ENABLE_CANCEL_IN_HW)
  canTmpReg32 |= kCanCrIntMaskCancel;
#endif
#endif
  CanLL_WriteReg32(CAN_CHANNEL_CANPARA_FIRST &Can->ChCtrl[canPhysChannel].CR, canTmpReg32, initPara);

  canTmpRegRs = ((Can->CTBIER[CanLL_TxWordIndex(canPhysChannel)] & CanLL_TxMaskWordClear(canPhysChannel)) |
                 CanLL_TxWordToSharedReg(canPhysChannel, Can_GetTxIntMaskOfChannelData(canHwChannel)));
  CanLL_WriteRegRegSize(CAN_CHANNEL_CANPARA_FIRST &Can->CTBIER[CanLL_TxWordIndex(canPhysChannel)], canTmpRegRs, initPara);

#if defined(C_ENABLE_RX_FULLCAN_OBJECTS)

  Can->CRBRCF[0] = ((kCanRegSizeCast) ~Can_GetRxFcMask0OfChannelData(canHwChannel));
#if(kCanNumberOfSharedReg16 > 1u)
  Can->CRBRCF[1] = ((kCanRegSizeCast) ~Can_GetRxFcMask1OfChannelData(canHwChannel));
#endif
#if(kCanNumberOfSharedReg16 > 2u)
  Can->CRBRCF[2] = ((kCanRegSizeCast) ~Can_GetRxFcMask2OfChannelData(canHwChannel));
#endif
#if(kCanNumberOfSharedReg16 > 3u)
  Can->CRBRCF[3] = ((kCanRegSizeCast) ~Can_GetRxFcMask3OfChannelData(canHwChannel));
#endif
#endif

  return (kCanOk);
}

V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_InitMailboxTx( CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanInitParaStructPtr initPara ){

  CAN_CHANNEL_AND_HW_CHANNEL_DUMMY_STATEMENT;
  CAN_DUMMY_STATEMENT(initPara);
  return (kCanOk);
}

#if(defined( C_ENABLE_CAN_RAM_CHECK ))

V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_InitMailboxTxDeactivate( CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanInitParaStructPtr initPara ){

  CAN_CHANNEL_AND_HW_CHANNEL_DUMMY_STATEMENT;
  CAN_DUMMY_STATEMENT(initPara);
}

#endif

#if defined( C_ENABLE_RX_FULLCAN_OBJECTS )

V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_InitMailboxRxFullCan( CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanInitParaStructPtr initPara ){

  CAN_CHANNEL_AND_HW_CHANNEL_DUMMY_STATEMENT;
  CAN_DUMMY_STATEMENT(initPara);
  return (kCanOk);
}

#endif

#if defined( C_ENABLE_RX_BASICCAN_OBJECTS )

V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_InitMailboxRxBasicCan( CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanInitParaStructPtr initPara ){

  vuint8 retVal = kCanFailed;

#if(CAN_SAFE_BSW == STD_ON)
  if(initPara->hwObjHandle < kCanMaxRxFifos)
#endif
  {

    Can->CRFCR[initPara->hwObjHandle] &= ((kCanRegSize) ~kCanCrFifoEnable);

    Can->CRFSR[initPara->hwObjHandle] &= ((kCanRegSize) ~(kCanSrRxFifoIntFlag | kCanSrFifoOverrun));

    Can->CRFCR[initPara->hwObjHandle] |= kCanCrFifoEnable;

    retVal = kCanOk;
  }

  CAN_CHANNEL_AND_HW_CHANNEL_DUMMY_STATEMENT;
  return (retVal);
}

#endif

V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_InitEndSetRegisters( CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanInitParaStructPtr initPara ){

  CAN_CHANNEL_AND_HW_CHANNEL_DUMMY_STATEMENT;
  CAN_DUMMY_STATEMENT(initPara);
  return (kCanOk);
}

V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_InitEnd( CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanInitParaStructPtr initPara ){

  CAN_CHANNEL_AND_HW_CHANNEL_DUMMY_STATEMENT;
  CAN_DUMMY_STATEMENT(initPara);
  return (kCanOk);
}

#if defined( C_ENABLE_CAN_RAM_CHECK )

V_DEF_FUNC(CAN_STATIC, vuint8, STATIC_CODE) CanLL_InitIsMailboxCorrupt( CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanInitParaStructPtr initPara ){

  tCanBufPtr Buf;
  CanObjectHandle mailboxElement = kCanZero;
  vuint8 idx;

  vuint8 canMailboxCheckFailed = kCanFalse;

#if defined(C_ENABLE_TX_HW_FIFO)

  if(!Can_IsTxFifo(initPara->mailboxHandle))
#endif
  {
#if defined(C_ENABLE_MULTIPLEXED_TRANSMISSION)

    for(; mailboxElement < Can_GetMailboxSize(initPara->mailboxHandle); mailboxElement++)
#endif
    {
#if(CAN_SAFE_BSW == STD_ON)
      if((initPara->hwObjHandle + mailboxElement) >= kCanMaxTxBuf)
      {
        canMailboxCheckFailed = kCanTrue;
      }
      else
#endif
      {
        Buf = pBufTm(mCanLogToPhys(canHwChannel), (initPara->hwObjHandle + mailboxElement));

        for(idx=0u; idx<3u; idx++)
        {

          Buf->Id         =  CanMemCheckValues32bit[idx];
          Buf->Dlc        = (CanMemCheckValues32bit[idx] & kCanDlcMask);
#if defined(C_ENABLE_CAN_FD_USED)
          Buf->Fd         = (CanMemCheckValues32bit[idx] & kCanFdCfgMask);
#endif
          Buf->u.iData[0] =  CanMemCheckValues32bit[idx];
          Buf->u.iData[1] =  CanMemCheckValues32bit[idx];
#if defined(C_ENABLE_CAN_FD_FULL)
          Buf->u.iData[2] =  CanMemCheckValues32bit[idx];
          Buf->u.iData[3] =  CanMemCheckValues32bit[idx];
          Buf->u.iData[4] =  CanMemCheckValues32bit[idx];
#endif

          if(   (Buf->Id         !=  CanMemCheckValues32bit[idx]                 )
              || (Buf->Dlc        != (CanMemCheckValues32bit[idx] & kCanDlcMask)  )
#if defined(C_ENABLE_CAN_FD_USED)
              || (Buf->Fd         != (CanMemCheckValues32bit[idx] & kCanFdCfgMask))
#endif
              || (Buf->u.iData[0] !=  CanMemCheckValues32bit[idx]                 )
              || (Buf->u.iData[1] !=  CanMemCheckValues32bit[idx]                 )
#if defined(C_ENABLE_CAN_FD_FULL)
              || (Buf->u.iData[2] !=  CanMemCheckValues32bit[idx]                 )
              || (Buf->u.iData[3] !=  CanMemCheckValues32bit[idx]                 )
              || (Buf->u.iData[4] !=  CanMemCheckValues32bit[idx]                 )
#endif
             )
          {
            canMailboxCheckFailed = kCanTrue;
          }

#if defined(C_ENABLE_CAN_FD_FULL)
#if defined(C_ENABLE_IF_RSCAN_FD)
          if(   ((initPara->hwObjHandle + mailboxElement) == 0u)
              || ((initPara->hwObjHandle + mailboxElement) == 3u)
             )
#endif
          {

            Buf->u.iData[5] =  CanMemCheckValues32bit[idx];
            Buf->u.iData[6] =  CanMemCheckValues32bit[idx];
            Buf->u.iData[7] =  CanMemCheckValues32bit[idx];
            Buf->u.iData[8] =  CanMemCheckValues32bit[idx];
            Buf->u.iData[9] =  CanMemCheckValues32bit[idx];
            Buf->u.iData[10] = CanMemCheckValues32bit[idx];
            Buf->u.iData[11] = CanMemCheckValues32bit[idx];
            Buf->u.iData[12] = CanMemCheckValues32bit[idx];
            Buf->u.iData[13] = CanMemCheckValues32bit[idx];
            Buf->u.iData[14] = CanMemCheckValues32bit[idx];
            Buf->u.iData[15] = CanMemCheckValues32bit[idx];

            if(   (Buf->u.iData[5] !=  CanMemCheckValues32bit[idx])
                || (Buf->u.iData[6] !=  CanMemCheckValues32bit[idx])
                || (Buf->u.iData[7] !=  CanMemCheckValues32bit[idx])
                || (Buf->u.iData[8] !=  CanMemCheckValues32bit[idx])
                || (Buf->u.iData[9] !=  CanMemCheckValues32bit[idx])
                || (Buf->u.iData[10] != CanMemCheckValues32bit[idx])
                || (Buf->u.iData[11] != CanMemCheckValues32bit[idx])
                || (Buf->u.iData[12] != CanMemCheckValues32bit[idx])
                || (Buf->u.iData[13] != CanMemCheckValues32bit[idx])
                || (Buf->u.iData[14] != CanMemCheckValues32bit[idx])
                || (Buf->u.iData[15] != CanMemCheckValues32bit[idx])
               )
            {
              canMailboxCheckFailed = kCanTrue;
            }
          }
#endif
        }
      }
    }
  }

  CAN_CHANNEL_AND_HW_CHANNEL_DUMMY_STATEMENT;
  return (canMailboxCheckFailed);
}

#endif

V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_InitPowerOn(void){

  CAN_CHANNEL_CANTYPE_LOCAL
  vuint8 retVal = kCanOk;
#if defined(C_ENABLE_IF_RSCAN_FD)
#if defined(C_ENABLE_CAN_RAM_CHECK_EXTENDED)
  vuint8 idx;
#endif
#endif

#if defined(C_MULTIPLE_RECEIVE_CHANNEL)
  channel = 0;
#endif

  CanLL_InitPowerOnModeTransitions();

#if(CAN_SAFE_BSW == STD_ON)

  retVal = CanLL_CheckGeneratedData();

  if(retVal == kCanOk)
#endif
  {
#if defined(C_ENABLE_IF_RSCAN_FD)

#if defined(C_ENABLE_CAN_RAM_CHECK_EXTENDED)
    canIsCellCorrupt = kCanFalse;

    for(idx=0u; idx<3u; idx++){

      Can->CGRMCFG = (CanMemCheckValuesRegSize[idx] & kCanRamCheckMaskCGRMCFG);
      if((Can->CGRMCFG & kCanRamCheckMaskCGRMCFG) != (CanMemCheckValuesRegSize[idx] & kCanRamCheckMaskCGRMCFG))
      {
        canIsCellCorrupt = kCanTrue;
      }
    }
#endif

#if defined(C_ENABLE_CAN_FD_USED)

    CanLL_WriteRegGlobal32(&Can->CGRMCFG, kCanOne);
#else

    CanLL_WriteRegGlobal32(&Can->CGRMCFG, kCanZero);
#endif
#endif

#if defined(C_ENABLE_CAN_RAM_CHECK_EXTENDED)

#if defined(C_ENABLE_IF_RSCAN_FD)
    if(canIsCellCorrupt == kCanFalse)
#endif
    {
      canIsCellCorrupt = CanLL_IsGlobalRegisterCorrupt();
    }
#endif

#if defined(C_ENABLE_RSCAN_FD_LAYOUT)
#if defined(C_ENABLE_CAN_FD_CONFIGURATION)
    CanLL_WriteRegGlobal32(&Can->CGFDCFG, (vuint32)C_ENABLE_CAN_FD_CONFIGURATION);
#endif
#if defined(C_ENABLE_CAN_CRC_CONFIGURATION)
    CanLL_WriteRegGlobal32(&Can->CGCRCCFG, (vuint32)C_ENABLE_CAN_CRC_CONFIGURATION);
#endif
#endif
    CanLL_WriteRegGlobal32(&Can->CGCFG, kCanGlobCfg);

    CanLL_InitPowerOnGlobalInit();

#if defined(C_ENABLE_LL_CAN_INTCTRL)
#if !defined(C_ENABLE_ERROR_POLLING) || ((defined(C_ENABLE_INDIVIDUAL_POLLING) || !defined(C_ENABLE_RX_BASICCAN_POLLING)))
    canInterruptOldFlag.GErrCnt = kCanZero;
#endif
#endif

#if !defined(C_ENABLE_ERROR_POLLING) && ((defined(C_ENABLE_RX_BASICCAN_OBJECTS) && defined(C_ENABLE_OVERRUN)))
    CanLL_WriteRegGlobal32(&Can->CGCR, (kCanOperationMode | kCanIntMaskMessageLost));
#else
    CanLL_WriteRegGlobal32(&Can->CGCR, kCanOperationMode);
#endif

    if(!CanLL_GlobalModeCheck(kCanOperationMode)){
      if(!CanLL_GlobalModeCheck(kCanOperationMode))
      {
        CanLL_GlobalModeWait(kCanOperationMode, kCanLoopGlobalInit);
      }
    }

#if defined(C_ENABLE_CAN_RAM_CHECK_EXTENDED)

    if(canIsCellCorrupt == kCanTrue){
      Appl_CanRamCheckCorruptCell();
    }
#endif
  }

  CAN_CHANNEL_DUMMY_STATEMENT;
  return (retVal);
}

V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_InitPowerOnChannelSpecific(CAN_CHANNEL_CANTYPE_ONLY){

  CAN_CHANNEL_DUMMY_STATEMENT;
  return (kCanOk);
}

V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_InitMemoryPowerOn(void){

}

#if defined( C_ENABLE_CANCEL_IN_HW )

V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_TxCancelInHw(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanTxCancellationParaStructPtr txCancellationPara){

  {
#if defined(C_ENABLE_MULTIPLEXED_TRANSMISSION)
    txCancellationPara->hwObjHandle += txCancellationPara->mailboxElement;
#endif

#if(CAN_SAFE_BSW == STD_ON)
    if(txCancellationPara->hwObjHandle < kCanMaxTxBuf)
#endif
    {
      Can->ChBC[mCanLogToPhys(canHwChannel)].TBCR[txCancellationPara->hwObjHandle] |= kCanCrTxBufCancel;
    }
  }

  CAN_CHANNEL_AND_HW_CHANNEL_DUMMY_STATEMENT;
}

#endif

V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_TxBegin(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanTxTransmissionParaStructPtr txPara){

#if defined(C_ENABLE_TX_HW_FIFO)
  if(Can_IsTxFifo(txPara->mailboxHandle)){
#if(CAN_SAFE_BSW == STD_ON)
    if(txPara->hwObjHandle >= kCanMaxTxFifos){
      txPara->Buf = &CanLL_DummyBuf;
    }
    else
#endif
    {
      txPara->Buf = pBufCf(mCanLogToPhys(canHwChannel), txPara->hwObjHandle);
    }
  }
  else
#endif
  {
#if defined(C_ENABLE_MULTIPLEXED_TRANSMISSION)
    txPara->hwObjHandle += txPara->mailboxElement;
#endif
#if(CAN_SAFE_BSW == STD_ON)
    if(txPara->hwObjHandle >= kCanMaxTxBuf){
      txPara->Buf = &CanLL_DummyBuf;
    }
    else
#endif
    {
      txPara->Buf = pBufTm(mCanLogToPhys(canHwChannel), txPara->hwObjHandle);
    }
  }

  CAN_CHANNEL_AND_HW_CHANNEL_DUMMY_STATEMENT;
}

V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_TxSetMailbox(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanTxTransmissionParaStructPtr txPara){

  txPara->Buf->Id = txPara->idRaw0;
  txPara->Buf->Dlc = CanActualDLCToReg(txPara->dlcRaw);
#if defined(C_ENABLE_CAN_FD_USED)
  txPara->Buf->Fd = (vuint32)(txPara->fdType | txPara->fdBrsType);
#endif

  CAN_CHANNEL_AND_HW_CHANNEL_DUMMY_STATEMENT;
}

V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_TxCopyToCan(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanTxTransmissionParaStructPtr txPara){

  tCanTmpData CanLL_TxTmpBuf;
#if defined(C_ENABLE_CAN_FD_FULL)
  vuint8 canCount;
#endif

#if defined(C_ENABLE_CAN_FD_FULL)
#if(CAN_SAFE_BSW == STD_ON)
  if((txPara->messageLen <= 64u) && (txPara->frameLen <= 64u))
#endif
  {
    for(canCount = 0; canCount < txPara->messageLen; canCount++){
      CanLL_TxTmpBuf.bData[canCount] = txPara->CanMemCopySrcPtr[canCount];
    }
    for(canCount = txPara->messageLen; canCount < txPara->frameLen; canCount++){
      CanLL_TxTmpBuf.bData[canCount] = txPara->paddingVal;
    }

    if(txPara->frameLen > 8u){

      for(canCount = 0; canCount < (txPara->frameLen >> 2); canCount++)
      {
        txPara->Buf->u.iData[canCount] = CanLL_TxTmpBuf.iData[canCount];
      }
    }
    else{
      txPara->Buf->u.iData[0] = CanLL_TxTmpBuf.iData[0];
      txPara->Buf->u.iData[1] = CanLL_TxTmpBuf.iData[1];
    }
  }
#else
  CanLL_TxTmpBuf.bData[0] = txPara->CanMemCopySrcPtr[0];
  CanLL_TxTmpBuf.bData[1] = txPara->CanMemCopySrcPtr[1];
  CanLL_TxTmpBuf.bData[2] = txPara->CanMemCopySrcPtr[2];
  CanLL_TxTmpBuf.bData[3] = txPara->CanMemCopySrcPtr[3];
  txPara->Buf->u.iData[0] = CanLL_TxTmpBuf.iData[0];
  CanLL_TxTmpBuf.bData[4] = txPara->CanMemCopySrcPtr[4];
  CanLL_TxTmpBuf.bData[5] = txPara->CanMemCopySrcPtr[5];
  CanLL_TxTmpBuf.bData[6] = txPara->CanMemCopySrcPtr[6];
  CanLL_TxTmpBuf.bData[7] = txPara->CanMemCopySrcPtr[7];
  txPara->Buf->u.iData[1] = CanLL_TxTmpBuf.iData[1];
#endif

  CAN_CHANNEL_AND_HW_CHANNEL_DUMMY_STATEMENT;
}

V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_TxStart(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanTxTransmissionParaStructPtr txPara){

  vuint8 retVal = kCanOk;
#if defined(C_MULTIPLE_PHYS_CHANNEL)
  CanChannelHandle canPhysChannel = mCanLogToPhys(canHwChannel);
#endif

#if defined(C_ENABLE_TX_HW_FIFO)
  if(Can_IsTxFifo(txPara->mailboxHandle)){
#if(CAN_SAFE_BSW == STD_ON)
    if(txPara->hwObjHandle >= kCanMaxTxFifos){
      retVal = kCanFailed;
    }
    else
#endif
    {
      Can->ChFPC[canPhysChannel].TRFPCR[txPara->hwObjHandle] = kCanPcrFifoPC;
    }
  }
  else
#endif
  {
    {
#if(CAN_SAFE_BSW == STD_ON)
      if(txPara->hwObjHandle >= kCanMaxTxBuf)
      {
        retVal = kCanFailed;
      }
      else
#endif
      {
        Can->ChBC[canPhysChannel].TBCR[txPara->hwObjHandle] |= kCanCrTxBufReq;
      }
    }
  }

  CAN_CHANNEL_AND_HW_CHANNEL_DUMMY_STATEMENT;
  return (retVal);
}

V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_TxEnd(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanTxTransmissionParaStructPtr txPara){

  CAN_CHANNEL_AND_HW_CHANNEL_DUMMY_STATEMENT;
  CAN_DUMMY_STATEMENT(txPara);
}

#if defined( C_ENABLE_TX_POLLING )

V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_TxIsGlobalConfPending(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_ONLY){
#if !defined(C_ENABLE_TX_HW_FIFO)

#if defined(C_MULTIPLE_PHYS_CHANNEL)
  CanChannelHandle canPhysChannel = mCanLogToPhys(canHwChannel);
#endif
  vuint8 retVal = kCanFalse;

  if(   ((Can->CTBTCSR[CanLL_TxWordIndex(canPhysChannel)] & CanLL_TxMaskWord(canPhysChannel)) != 0u)
#if defined(C_ENABLE_CANCEL_IN_HW)
      || ((Can->CTBASR[CanLL_TxWordIndex(canPhysChannel)] & CanLL_TxMaskWord(canPhysChannel)) != 0u)
#endif
     ){
    retVal = kCanTrue;
  }

  CAN_CHANNEL_AND_HW_CHANNEL_DUMMY_STATEMENT;
  return (retVal);
#else

  CAN_CHANNEL_AND_HW_CHANNEL_DUMMY_STATEMENT;
  return (kCanTrue);
#endif
}

V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_TxProcessPendings(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanTaskParaStructPtr taskPara){

  CanObjectHandle mailboxElement = kCanZero;
#if defined(C_ENABLE_TX_HW_FIFO)
  vuint8 canCount;
  vuint8 requestCount;
  vuint8 pendingCount;
#endif
#if defined(C_MULTIPLE_PHYS_CHANNEL)
  CanChannelHandle canPhysChannel = mCanLogToPhys(canHwChannel);
#endif

#if defined(C_ENABLE_TX_HW_FIFO)
  if(Can_IsTxFifo(taskPara->mailboxHandle)){

    canCount = Can_GetFifoProcCountOfChannelData(canHwChannel);
    requestCount = (vuint8)Can_GetTxHwFifoFillCount(Can_GetMailboxTxHwFifo(taskPara->mailboxHandle));
    pendingCount = (vuint8)((Can->ChFS[canPhysChannel].TRFSR[taskPara->hwObjHandle] & kCanSrFifoMsgCount) >> 8);
    while(((requestCount - pendingCount) > 0u) && (canCount > 0u)){
      canCount--;
      CanHL_TxConfirmationPolling(CAN_HW_CHANNEL_CANPARA_FIRST taskPara->mailboxHandle, kCanZero, taskPara->hwObjHandle);
      requestCount = (vuint8)Can_GetTxHwFifoFillCount(Can_GetMailboxTxHwFifo(taskPara->mailboxHandle));
      pendingCount = (vuint8)((Can->ChFS[canPhysChannel].TRFSR[taskPara->hwObjHandle] & kCanSrFifoMsgCount) >> 8);
    }
  }
  else
#endif
  {

#if defined(C_ENABLE_MULTIPLEXED_TRANSMISSION)
    for(; mailboxElement < Can_GetMailboxSize(taskPara->mailboxHandle); mailboxElement++)
#endif
    {
      if((Can->ChBS[canPhysChannel].TBSR[taskPara->hwObjHandle + mailboxElement] & kCanSrTxBufMaskPending) != 0u)
      {
        CanHL_TxConfirmationPolling(CAN_HW_CHANNEL_CANPARA_FIRST taskPara->mailboxHandle, mailboxElement, taskPara->hwObjHandle + mailboxElement);
      }
    }
  }
}

#endif

V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_TxConfBegin(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanTxConfirmationParaStructPtr txConfPara){

#if defined(C_MULTIPLE_PHYS_CHANNEL)
  CanChannelHandle canPhysChannel = mCanLogToPhys(canHwChannel);
#endif

#if defined(C_ENABLE_TX_HW_FIFO)
  if(!Can_IsTxFifo(txConfPara->mailboxHandle))
#endif
  {
#if(CAN_SAFE_BSW == STD_ON)
    if(txConfPara->hwObjHandle < kCanMaxTxBuf)
#endif
    {
#if defined(C_ENABLE_CANCEL_IN_HW)
      txConfPara->txBufferStatus = Can->ChBS[canPhysChannel].TBSR[txConfPara->hwObjHandle];
#endif

      Can->ChBS[canPhysChannel].TBSR[txConfPara->hwObjHandle] &= ((vuint8) ~kCanSrTxBufMaskPending);
    }
  }

  CAN_CHANNEL_AND_HW_CHANNEL_DUMMY_STATEMENT;
}

#if defined( C_ENABLE_CANCEL_IN_HW )

V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_TxConfIsMsgTransmitted(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanTxConfirmationParaStructPtr txConfPara){

  vuint8 retVal = kCanFalse;

  if((txConfPara->txBufferStatus & kCanSrTxBufMaskComplete) != 0u){
    retVal = kCanTrue;
  }

  CAN_CHANNEL_AND_HW_CHANNEL_DUMMY_STATEMENT;
  return (retVal);
}

#endif

#if defined(CAN_ENABLE_GENERIC_CONFIRMATION_API2)

V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_TxConfSetTxConfStruct(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanTxConfirmationParaStructPtr txConfPara){

  tCanBufPtr Buf;

#if(CAN_SAFE_BSW == STD_ON)
  if(txConfPara->hwObjHandle >= kCanMaxTxBuf){
    Buf = &CanLL_DummyBuf;
  }
  else
#endif
  {
    Buf = pBufTm(mCanLogToPhys(canHwChannel), txConfPara->hwObjHandle);
  }

  txConfPara->txStructConf->pChipMsgObj = (CanChipMsgPtr)(Buf);
  txConfPara->txStructConf->pChipData = (CanChipDataPtr)&(Buf->u.bData[0]);
}

#endif

V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_TxConfEnd(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanTxConfirmationParaStructPtr txConfPara){

  CAN_CHANNEL_AND_HW_CHANNEL_DUMMY_STATEMENT;
  CAN_DUMMY_STATEMENT(txConfPara);
}

#if defined( C_ENABLE_RX_BASICCAN_OBJECTS )

V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_RxBasicMsgReceivedBegin(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanRxBasicParaStructPtr rxBasicPara){

  tCanBufPtr Buf;
#if defined(C_ENABLE_CAN_FD_FULL)
  vuint8 canCount;
  vuint8 canDlc;
#endif
  vuint8 retVal = kCanOk;

#if(CAN_SAFE_BSW == STD_ON)
  if(rxBasicPara->hwObjHandle >= kCanMaxRxFifos){
    retVal = kCanFailed;
  }
  else
#endif
  {
    Buf = pBufRf(rxBasicPara->hwObjHandle);

    Can->CRFSR[rxBasicPara->hwObjHandle] &= ((kCanRegSize) ~kCanSrRxFifoIntFlag);

    Can_GetRxTmpBuf(canHwChannel).Id           = Buf->Id;
    Can_GetRxTmpBuf(canHwChannel).Dlc          = Buf->Dlc;
#if defined(C_ENABLE_CAN_FD_USED)
    Can_GetRxTmpBuf(canHwChannel).Fd           = Buf->Fd;
#endif
#if defined(C_ENABLE_CAN_FD_FULL)
    canDlc = CanRegToActualDLC(Can_GetRxTmpBuf(canHwChannel).Dlc);
    if(canDlc > 8u){

      for(canCount = 0u; canCount < (CAN_DLC2LEN(canDlc) >> 2); canCount++)
      {
        Can_GetRxTmpBuf(canHwChannel).u.iData[canCount] = Buf->u.iData[canCount];
      }
    }
    else
#endif
    {
      Can_GetRxTmpBuf(canHwChannel).u.iData[0] = Buf->u.iData[0];
      Can_GetRxTmpBuf(canHwChannel).u.iData[1] = Buf->u.iData[1];
    }

    Can->CRFPCR[rxBasicPara->hwObjHandle] = kCanPcrFifoPC;

    rxBasicPara->rxStruct.pChipMsgObj = (CanChipMsgPtr)&(Can_GetRxTmpBuf(canHwChannel));
    rxBasicPara->rxStruct.pChipData = (CanChipDataPtr)&(Can_GetRxTmpBuf(canHwChannel).u.bData[0]);

#if defined(C_ENABLE_CAN_FD_USED)

    if((Can_GetInitObjectFdBrsConfig(Can_GetLastInitObject(channel)) == CAN_NONE) && ((Can_GetRxTmpBuf(canHwChannel).Fd & kCanFdTypeFd) == kCanFdTypeFd)){
      retVal = kCanFailed;
    }
#endif
  }

#if defined(C_ENABLE_ECC_RX_REJECT)

  if(ApplCanEccRxReject(canHwChannel) == kCanTrue){
    retVal = kCanFailed;
  }
#endif

  return (retVal);
}

V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_RxBasicReleaseObj(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanRxBasicParaStructPtr rxBasicPara){

  CAN_CHANNEL_AND_HW_CHANNEL_DUMMY_STATEMENT;
  CAN_DUMMY_STATEMENT(rxBasicPara);
}

V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_RxBasicMsgReceivedEnd(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanRxBasicParaStructPtr rxBasicPara){

  CAN_CHANNEL_AND_HW_CHANNEL_DUMMY_STATEMENT;
  CAN_DUMMY_STATEMENT(rxBasicPara);
}

#if defined( C_ENABLE_RX_BASICCAN_POLLING )

V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_RxBasicIsGlobalIndPending(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_ONLY){

  vuint8 retVal = kCanFalse;

  if(((Can->CFESR & kCanRxFifoMask) & Can_GetRxBcMaskOfChannelData(canHwChannel)) != Can_GetRxBcMaskOfChannelData(canHwChannel)){
    retVal = kCanTrue;
  }

  return (retVal);
}

V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_RxBasicProcessPendings(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanTaskParaStructPtr taskPara){

  vuint8 canCount = Can_GetFifoProcCountOfChannelData(canHwChannel);

  while(((Can->CRFSR[taskPara->hwObjHandle] & kCanSrFifoEmpty) == 0u) && (canCount > 0u)){
    canCount--;
    CanHL_BasicCanMsgReceivedPolling(CAN_HW_CHANNEL_CANPARA_FIRST taskPara->mailboxHandle, taskPara->hwObjHandle);
  }
}

#endif
#endif

#if defined( C_ENABLE_RX_FULLCAN_OBJECTS )

V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_RxFullMsgReceivedBegin(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanRxFullParaStructPtr rxFullPara){

  tCanBufPtr Buf;
#if defined(C_ENABLE_HW_LOOP_TIMER)
  tCanLoopRet canHwLoopRetVal;
#endif
#if defined(C_ENABLE_CAN_FD_FULL)
  vuint8 canCount;
  vuint8 canDlc;
#endif
  vuint8 retVal = kCanOk;

#if(CAN_SAFE_BSW == STD_ON)
  if(CanLL_BitIndex(rxFullPara->hwObjHandle) >= kCanNumberOfSharedReg16){
    retVal = kCanFailed;
  }
  else
#endif
  {
    Buf = pBufRm(rxFullPara->hwObjHandle);

    Can->CRBRCF[CanLL_BitIndex(rxFullPara->hwObjHandle)] = CanLL_ClearBitRS(rxFullPara->hwObjHandle);

    Can_GetRxTmpBuf(canHwChannel).Id           = Buf->Id;
    Can_GetRxTmpBuf(canHwChannel).Dlc          = Buf->Dlc;
#if defined(C_ENABLE_CAN_FD_USED)
    Can_GetRxTmpBuf(canHwChannel).Fd           = Buf->Fd;
#endif
#if defined(C_ENABLE_CAN_FD_FULL)
    canDlc = CanRegToActualDLC(Can_GetRxTmpBuf(canHwChannel).Dlc);
    if(canDlc > 8u){

      for(canCount = 0u; canCount < (CAN_DLC2LEN(canDlc) >> 2); canCount++)
      {
        Can_GetRxTmpBuf(canHwChannel).u.iData[canCount] = Buf->u.iData[canCount];
      }
    }
    else
#endif
    {
      Can_GetRxTmpBuf(canHwChannel).u.iData[0] = Buf->u.iData[0];
      Can_GetRxTmpBuf(canHwChannel).u.iData[1] = Buf->u.iData[1];
    }

    if((Can->CRBRCF[CanLL_BitIndex(rxFullPara->hwObjHandle)] & CanLL_SLRS(rxFullPara->hwObjHandle)) != 0u){
      CanLL_CanTimerStart(kCanLoopRxFcProcess);
      do
      {

        Can->CRBRCF[CanLL_BitIndex(rxFullPara->hwObjHandle)] = CanLL_ClearBitRS(rxFullPara->hwObjHandle);

        Can_GetRxTmpBuf(canHwChannel).Id           = Buf->Id;
        Can_GetRxTmpBuf(canHwChannel).Dlc          = Buf->Dlc;
#if defined(C_ENABLE_CAN_FD_USED)
        Can_GetRxTmpBuf(canHwChannel).Fd           = Buf->Fd;
#endif
#if defined(C_ENABLE_CAN_FD_FULL)
        canDlc = CanRegToActualDLC(Can_GetRxTmpBuf(canHwChannel).Dlc);
        if(canDlc > 8u)
        {

          for(canCount = 0u; canCount < (CAN_DLC2LEN(canDlc) >> 2); canCount++)
          {
            Can_GetRxTmpBuf(canHwChannel).u.iData[canCount] = Buf->u.iData[canCount];
          }
        }
        else
#endif
        {
          Can_GetRxTmpBuf(canHwChannel).u.iData[0] = Buf->u.iData[0];
          Can_GetRxTmpBuf(canHwChannel).u.iData[1] = Buf->u.iData[1];
        }

#if defined(C_ENABLE_HW_LOOP_TIMER)
        canHwLoopRetVal = CanLL_CanTimerLoop(kCanLoopRxFcProcess);
      } while((canHwLoopRetVal != CAN_NOT_OK) && ((Can->CRBRCF[CanLL_BitIndex(rxFullPara->hwObjHandle)] & CanLL_SLRS(rxFullPara->hwObjHandle)) != 0u));
#else
      } while((Can->CRBRCF[CanLL_BitIndex(rxFullPara->hwObjHandle)] & CanLL_SLRS(rxFullPara->hwObjHandle)) != 0u);
#endif
      CanLL_CanTimerEnd(kCanLoopRxFcProcess);

#if defined(C_ENABLE_HW_LOOP_TIMER)

      if(canHwLoopRetVal == CAN_NOT_OK)
      {
        Can->CRBRCF[CanLL_BitIndex(rxFullPara->hwObjHandle)] = CanLL_ClearBitRS(rxFullPara->hwObjHandle);
        retVal = kCanFailed;
      }
#endif
    }

    rxFullPara->rxStruct.pChipMsgObj = (CanChipMsgPtr)&(Can_GetRxTmpBuf(canHwChannel));
    rxFullPara->rxStruct.pChipData = (CanChipDataPtr)&(Can_GetRxTmpBuf(canHwChannel).u.bData[0]);

#if defined(C_ENABLE_CAN_FD_USED)

    if((Can_GetInitObjectFdBrsConfig(Can_GetLastInitObject(channel)) == CAN_NONE) && ((Can_GetRxTmpBuf(canHwChannel).Fd & kCanFdTypeFd) == kCanFdTypeFd)){
      retVal = kCanFailed;
    }
#endif
  }

#if defined(C_ENABLE_ECC_RX_REJECT)

  if(ApplCanEccRxReject(canHwChannel) == kCanTrue){
    retVal = kCanFailed;
  }
#endif

  return (retVal);
}

 V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_RxFullReleaseObj(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanRxFullParaStructPtr rxFullPara){

  CAN_CHANNEL_AND_HW_CHANNEL_DUMMY_STATEMENT;
  CAN_DUMMY_STATEMENT(rxFullPara);
}

V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_RxFullMsgReceivedEnd(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanRxFullParaStructPtr rxFullPara){

  CAN_CHANNEL_AND_HW_CHANNEL_DUMMY_STATEMENT;
  CAN_DUMMY_STATEMENT(rxFullPara);
}

#if defined( C_ENABLE_RX_FULLCAN_POLLING )

V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_RxFullIsGlobalIndPending(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_ONLY){

  vuint8 retVal = kCanFalse;

  if(   ((Can->CRBRCF[0] & (kCanRegSizeCast)Can_GetRxFcMask0OfChannelData(canHwChannel)) != 0u)
#if(kCanNumberOfSharedReg16 > 1u)
      || ((Can->CRBRCF[1] & (kCanRegSizeCast)Can_GetRxFcMask1OfChannelData(canHwChannel)) != 0u)
#endif
#if(kCanNumberOfSharedReg16 > 2u)
      || ((Can->CRBRCF[2] & (kCanRegSizeCast)Can_GetRxFcMask2OfChannelData(canHwChannel)) != 0u)
#endif
#if(kCanNumberOfSharedReg16 > 3u)
      || ((Can->CRBRCF[3] & (kCanRegSizeCast)Can_GetRxFcMask3OfChannelData(canHwChannel)) != 0u)
#endif
     ){
    retVal = kCanTrue;
  }

  return (retVal);
}

V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_RxFullProcessPendings(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanTaskParaStructPtr taskPara){

  if((Can->CRBRCF[CanLL_BitIndex(taskPara->hwObjHandle)] & CanLL_SLRS(taskPara->hwObjHandle)) != 0u){
    CanHL_FullCanMsgReceivedPolling(CAN_HW_CHANNEL_CANPARA_FIRST taskPara->mailboxHandle, taskPara->hwObjHandle);
  }
}

#endif
#endif

V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_ErrorHandlingBegin(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_ONLY){

  CAN_CHANNEL_AND_HW_CHANNEL_DUMMY_STATEMENT;
}

V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_BusOffOccured(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_ONLY){

  vuint8 retVal = kCanFalse;

  if(CanLL_HwWasBusOff(canHwChannel)){
    Can->ChCtrl[mCanLogToPhys(canHwChannel)].EF = kCanEfMaskBusoffClear;
    retVal = kCanTrue;
  }

  CAN_CHANNEL_AND_HW_CHANNEL_DUMMY_STATEMENT;
  return (retVal);
}

#if defined( C_ENABLE_OVERRUN ) && defined( C_ENABLE_RX_BASICCAN_OBJECTS )

V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_RxBasicCanOverrun(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_ONLY){

  CanObjectHandle mailboxHandle;
  CanObjectHandle hwObjHandle;
  vuint8 retVal = kCanFalse;

  if(((Can->CFMLSR & kCanRxFifoMask) & Can_GetRxBcMaskOfChannelData(canHwChannel)) != 0u){
    mailboxHandle = CAN_HL_MB_RX_BASIC_STARTINDEX(canHwChannel);
#if defined(C_ENABLE_MULTIPLE_BASICCAN)
    for(; mailboxHandle < CAN_HL_MB_RX_BASIC_STOPINDEX(canHwChannel); mailboxHandle++)
#endif
    {
      hwObjHandle = Can_GetMailboxHwHandle(mailboxHandle);
#if(CAN_SAFE_BSW == STD_ON)
      if(hwObjHandle < kCanMaxRxFifos)
#endif
      {
        Can->CRFSR[hwObjHandle] &= ((kCanRegSize) ~kCanSrFifoOverrun);
      }
    }
    retVal = kCanTrue;
  }

  return (retVal);
}

#endif

V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_ErrorHandlingEnd(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_ONLY){

  CAN_CHANNEL_AND_HW_CHANNEL_DUMMY_STATEMENT;
}

#if defined( C_ENABLE_EXTENDED_STATUS )

V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_GetStatusBegin(CAN_CHANNEL_CANTYPE_ONLY){

  CAN_CHANNEL_DUMMY_STATEMENT;
}

#endif

#if defined( C_ENABLE_SLEEP_WAKEUP ) && defined( C_ENABLE_WAKEUP_POLLING )

V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_WakeUpOccured(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_ONLY){

  vuint8 retVal = kCanFalse;

  if(CanLL_HwIsSleep(canHwChannel) &&
      (
#if defined(C_ENABLE_LL_CAN_WAKEUP_INTCTRL)
        (CanLL_CanWakeupOccurred(CAN_HW_CHANNEL_CANPARA_ONLY) == kCanOk)
#endif
#if defined(C_ENABLE_LL_CAN_WAKEUP_INTCTRL) && defined(C_ENABLE_LL_CAN_WAKEUP_INTCB)
        ||
#endif
#if defined(C_ENABLE_LL_CAN_WAKEUP_INTCB)
        (ApplCanWakeupOccurred(canHwChannel) == CAN_OK)
#endif
      )
     ){
    retVal = kCanTrue;
  }

  return (retVal);
}

#endif

#if defined( C_ENABLE_SLEEP_WAKEUP )

V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_WakeUpHandling(CAN_CHANNEL_CANTYPE_ONLY){

  CAN_WAKEUP(channel);

  APPL_CAN_WAKEUP(channel);
}

#endif

V_DEF_FUNC(CAN_STATIC, vuint8, STATIC_CODE) CanLL_ModeTransition(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST vuint8 mode, vuint8 busOffRecovery, vuint8 ramCheck){

  vuint8 retVal = kCanFailed;

  if(mode == kCanModeResetBusOffStart){
    retVal = kCanOk;
  }
  else{

    if((busOffRecovery == kCanContinueBusOffRecovery) && CanLL_HwIsBusOff(canHwChannel)){
      retVal = kCanRequested;
    }
    else{

      if(CanLL_ChannelTransitionReset(CAN_CHANNEL_CANPARA_ONLY) == kCanOk)
      {

        switch(mode)
        {
          case kCanModeStopReinitFast:
          case kCanModeStopReinit:
#if defined(C_ENABLE_SLEEP_WAKEUP)
          case kCanModeWakeupStopReinit:

#endif
            retVal = CanHL_ReInit(CAN_CHANNEL_CANPARA_FIRST ramCheck);
            break;

#if defined(C_ENABLE_SLEEP_WAKEUP)

          case kCanModeSleep:
            retVal = CanLL_ChannelTransitionSleep(CAN_CHANNEL_CANPARA_ONLY);
            break;
#endif

          case kCanModeResetBusOffEnd:
#if(CAN_REINIT_START == STD_ON)
          case kCanModeStartReinit:
#endif
            if(CanHL_ReInit(CAN_CHANNEL_CANPARA_FIRST ramCheck) == kCanOk)
            {
              retVal = CanLL_ChannelTransitionStart(CAN_CHANNEL_CANPARA_ONLY);
            }
            break;

#if(CAN_REINIT_START == STD_OFF)
          case kCanModeStart:
            retVal = CanLL_ChannelTransitionStart(CAN_CHANNEL_CANPARA_ONLY);
            break;
#endif

#if defined(C_ENABLE_SILENT_MODE)
          case kCanModeSilent:
            if(CanLL_ChannelTransitionHalt(CAN_CHANNEL_CANPARA_ONLY) == kCanOk)
            {
              Can->ChCtrl[mCanLogToPhys(canHwChannel)].CR |= kCanCrListenOnlyMode;
              retVal = CanLL_ChannelTransitionStart(CAN_CHANNEL_CANPARA_ONLY);
            }
            break;
#endif

          default:

            break;
        }
      }
    }
  }

  return (retVal);
}

#if defined( C_ENABLE_CAN_CAN_INTERRUPT_CONTROL )

V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_CanInterruptDisable(CAN_HW_CHANNEL_CANTYPE_FIRST tCanLLCanIntOldPtr localInterruptOldFlagPtr){
#if defined(C_ENABLE_LL_CAN_INTCTRL)

#if defined(C_ENABLE_INTC_ACCESS_BY_APPL) || !defined(C_ENABLE_USE_OS_INTERRUPT_CONTROL)
  vuint8 canDummy = 0;
#if defined(C_ENABLE_INDIVIDUAL_POLLING) || !defined(C_ENABLE_TX_POLLING)
  tCanIntcChTxPtr CanIntcChTx = (tCanIntcChTxPtr)mCanIntcChTxAdr(canHwChannel);
#endif
#if !defined(C_ENABLE_ERROR_POLLING)
  tCanIntcChErrPtr CanIntcChErr = (tCanIntcChErrPtr)mCanIntcChErrorAdr(canHwChannel);
#endif
#if defined(C_ENABLE_LL_WAKEUP_SUPPORT) && !defined(C_ENABLE_WAKEUP_POLLING)
  tCanIntcChWupPtr CanIntcChWup = (tCanIntcChWupPtr)mCanIntcChWakeupAdr(canHwChannel);
#endif
#endif

  if(canInterruptOldFlag.GErrCnt == kCanZero){
#if(defined(C_ENABLE_INDIVIDUAL_POLLING) || !defined(C_ENABLE_RX_BASICCAN_POLLING)) && defined(C_ENABLE_RX_BASICCAN_OBJECTS)

    CanLL_IntcIntSave(CanIsrRxFifo, canInterruptOldFlag.RF, CanIntcRxFifo->RF);
    CanLL_IntcIntDisable(CanIsrRxFifo, CanIntcRxFifo->RF);
#if defined(C_ENABLE_INTC_ACCESS_BY_APPL) || !defined(C_ENABLE_USE_OS_INTERRUPT_CONTROL)
    CanLL_IntcIntSave(CanIsrRxFifo, canDummy, CanIntcRxFifo->RF);
#endif
#endif
#if !defined(C_ENABLE_ERROR_POLLING) && defined(C_ENABLE_OVERRUN) && defined(C_ENABLE_RX_BASICCAN_OBJECTS)

    CanLL_IntcIntSave(CanIsrGlobalStatus, canInterruptOldFlag.GErr, CanIntcGErr->GErr);
    CanLL_IntcIntDisable(CanIsrGlobalStatus, CanIntcGErr->GErr);
#if defined(C_ENABLE_INTC_ACCESS_BY_APPL) || !defined(C_ENABLE_USE_OS_INTERRUPT_CONTROL)
    CanLL_IntcIntSave(CanIsrGlobalStatus, canDummy, CanIntcGErr->GErr);
#endif
#endif
  }
  canInterruptOldFlag.GErrCnt++;
#if defined(C_ENABLE_INDIVIDUAL_POLLING) || !defined(C_ENABLE_TX_POLLING)

  CanLL_IntcIntSave(Can_GetIsrTxIdOfOsIsrId(canHwChannel), (*(localInterruptOldFlagPtr)).Tx, CanIntcChTx->Tx);
  CanLL_IntcIntDisable(Can_GetIsrTxIdOfOsIsrId(canHwChannel), CanIntcChTx->Tx);
#if defined(C_ENABLE_INTC_ACCESS_BY_APPL) || !defined(C_ENABLE_USE_OS_INTERRUPT_CONTROL)
  CanLL_IntcIntSave(Can_GetIsrTxIdOfOsIsrId(canHwChannel), canDummy, CanIntcChTx->Tx);
#endif
#endif
#if !defined(C_ENABLE_ERROR_POLLING)

  CanLL_IntcIntSave(Can_GetIsrStatusIdOfOsIsrId(canHwChannel), (*(localInterruptOldFlagPtr)).Err, CanIntcChErr->Err);
  CanLL_IntcIntDisable(Can_GetIsrStatusIdOfOsIsrId(canHwChannel), CanIntcChErr->Err);
#if defined(C_ENABLE_INTC_ACCESS_BY_APPL) || !defined(C_ENABLE_USE_OS_INTERRUPT_CONTROL)
  CanLL_IntcIntSave(Can_GetIsrStatusIdOfOsIsrId(canHwChannel), canDummy, CanIntcChErr->Err);
#endif
#endif
#if defined(C_ENABLE_LL_WAKEUP_SUPPORT) && !defined(C_ENABLE_WAKEUP_POLLING)

  CanLL_IntcIntSave(Can_GetIsrWakeupIdOfOsIsrId(canHwChannel), (*(localInterruptOldFlagPtr)).Wup, CanIntcChWup->Wup);
  CanLL_IntcIntDisable(Can_GetIsrWakeupIdOfOsIsrId(canHwChannel), CanIntcChWup->Wup);
#if defined(C_ENABLE_INTC_ACCESS_BY_APPL) || !defined(C_ENABLE_USE_OS_INTERRUPT_CONTROL)
  CanLL_IntcIntSave(Can_GetIsrWakeupIdOfOsIsrId(canHwChannel), canDummy, CanIntcChWup->Wup);
#endif
#endif

#if defined(C_ENABLE_INTC_ACCESS_BY_APPL) || !defined(C_ENABLE_USE_OS_INTERRUPT_CONTROL)

  CanLL_SYNCP();

  CAN_DUMMY_STATEMENT(canDummy);
#endif
#endif
  CAN_DUMMY_STATEMENT(localInterruptOldFlagPtr);
  CAN_HW_CHANNEL_DUMMY_STATEMENT;
}

V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_CanInterruptRestore(CAN_HW_CHANNEL_CANTYPE_FIRST tCanLLCanIntOld localInterruptOldFlag){
#if defined(C_ENABLE_LL_CAN_INTCTRL)

#if defined(C_ENABLE_INTC_ACCESS_BY_APPL) || !defined(C_ENABLE_USE_OS_INTERRUPT_CONTROL)
#if defined(C_ENABLE_INDIVIDUAL_POLLING) || !defined(C_ENABLE_TX_POLLING)
  tCanIntcChTxPtr CanIntcChTx = (tCanIntcChTxPtr)mCanIntcChTxAdr(canHwChannel);
#endif
#if !defined(C_ENABLE_ERROR_POLLING)
  tCanIntcChErrPtr CanIntcChErr = (tCanIntcChErrPtr)mCanIntcChErrorAdr(canHwChannel);
#endif
#if defined(C_ENABLE_LL_WAKEUP_SUPPORT) && !defined(C_ENABLE_WAKEUP_POLLING)
  tCanIntcChWupPtr CanIntcChWup = (tCanIntcChWupPtr)mCanIntcChWakeupAdr(canHwChannel);
#endif
#endif

  canInterruptOldFlag.GErrCnt--;

  if(canInterruptOldFlag.GErrCnt == kCanZero){
#if(defined(C_ENABLE_INDIVIDUAL_POLLING) || !defined(C_ENABLE_RX_BASICCAN_POLLING)) && defined(C_ENABLE_RX_BASICCAN_OBJECTS)

    CanLL_IntcIntRestore(CanIsrRxFifo, CanIntcRxFifo->RF, canInterruptOldFlag.RF);
#endif
#if !defined(C_ENABLE_ERROR_POLLING) && defined(C_ENABLE_OVERRUN) && defined(C_ENABLE_RX_BASICCAN_OBJECTS)

    CanLL_IntcIntRestore(CanIsrGlobalStatus, CanIntcGErr->GErr, canInterruptOldFlag.GErr);
#endif
  }
#if defined(C_ENABLE_INDIVIDUAL_POLLING) || !defined(C_ENABLE_TX_POLLING)

  CanLL_IntcIntRestore(Can_GetIsrTxIdOfOsIsrId(canHwChannel), CanIntcChTx->Tx, localInterruptOldFlag.Tx);
#endif
#if !defined(C_ENABLE_ERROR_POLLING)

  CanLL_IntcIntRestore(Can_GetIsrStatusIdOfOsIsrId(canHwChannel), CanIntcChErr->Err, localInterruptOldFlag.Err);
#endif
#if defined(C_ENABLE_LL_WAKEUP_SUPPORT) && !defined(C_ENABLE_WAKEUP_POLLING)

  CanLL_IntcIntRestore(Can_GetIsrWakeupIdOfOsIsrId(canHwChannel), CanIntcChWup->Wup, localInterruptOldFlag.Wup);
#endif
#endif
  CAN_DUMMY_STATEMENT(localInterruptOldFlag);
  CAN_HW_CHANNEL_DUMMY_STATEMENT;
}

#endif

#if defined(C_ENABLE_LL_CAN_INTCTRL) && defined(C_ENABLE_LL_WAKEUP_SUPPORT) && !defined(C_ENABLE_WAKEUP_POLLING)

V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_CanWakeupInterruptDisable(CAN_HW_CHANNEL_CANTYPE_FIRST tCanLLCanIntOldPtr localInterruptOldFlagPtr){

#if defined(C_ENABLE_INTC_ACCESS_BY_APPL) || !defined(C_ENABLE_USE_OS_INTERRUPT_CONTROL)
  tCanIntcChWupPtr CanIntcChWup = (tCanIntcChWupPtr)mCanIntcChWakeupAdr(canHwChannel);
#endif

  CanLL_IntcIntDisable(Can_GetIsrWakeupIdOfOsIsrId(canHwChannel), CanIntcChWup->Wup);
  CanLL_IntcIntDisableLoc((*(localInterruptOldFlagPtr)).Wup);
}

V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_CanWakeupInterruptEnable(CAN_HW_CHANNEL_CANTYPE_FIRST tCanLLCanIntOldPtr localInterruptOldFlagPtr){

#if defined(C_ENABLE_INTC_ACCESS_BY_APPL) || !defined(C_ENABLE_USE_OS_INTERRUPT_CONTROL)
  tCanIntcChWupPtr CanIntcChWup = (tCanIntcChWupPtr)mCanIntcChWakeupAdr(canHwChannel);
#endif

  if(Can_GetCanInterruptCounter(canHwChannel) == (tCanIntCnt)0){

    CanLL_IntcIntEnable(Can_GetIsrWakeupIdOfOsIsrId(canHwChannel), CanIntcChWup->Wup);
  }

  else{

    CanLL_IntcIntEnableLoc((*(localInterruptOldFlagPtr)).Wup);
  }
}

#endif

#if defined(C_ENABLE_LL_CAN_WAKEUP_INTCTRL) && defined(C_ENABLE_WAKEUP_POLLING)

V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_CanWakeupOccurred(CAN_HW_CHANNEL_CANTYPE_ONLY){

#if defined(C_ENABLE_INTC_ACCESS_BY_APPL) || !defined(C_ENABLE_USE_OS_INTERRUPT_CONTROL)
  tCanIntcChWupPtr CanIntcChWup = (tCanIntcChWupPtr)mCanIntcChWakeupAdr(canHwChannel);
#endif
  vuint8 retVal = kCanFailed;

  if(CanLL_IntcIntFlag(Can_GetIsrWakeupIdOfOsIsrId(canHwChannel), CanIntcChWup->uWup)){
    retVal = kCanOk;
  }

  return (retVal);
}

#endif

#if defined(C_ENABLE_LL_CAN_WAKEUP_INTCTRL)

V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_ClearCanWakeupInterruptFlag(CAN_HW_CHANNEL_CANTYPE_ONLY){

#if defined(C_ENABLE_INTC_ACCESS_BY_APPL) || !defined(C_ENABLE_USE_OS_INTERRUPT_CONTROL)
  tCanIntcChWupPtr CanIntcChWup = (tCanIntcChWupPtr)mCanIntcChWakeupAdr(canHwChannel);
#endif

  CanLL_IntcIntClear(Can_GetIsrWakeupIdOfOsIsrId(canHwChannel), CanIntcChWup->uWup);
}

#endif

#if defined(C_ENABLE_USE_OS_INTERRUPT_CONTROL)
#if !defined(C_ENABLE_INTC_ACCESS_BY_APPL)
#if defined(C_ENABLE_LL_CAN_INTCTRL)

V_DEF_FUNC(CAN_LOCAL_INLINE, boolean, STATIC_CODE) CanLL_OsIsInterruptSourceEnabled(Can_ExternalISRType IsrId){

  boolean retVal;

  (void)osIsInterruptSourceEnabled(IsrId, &retVal);
  return retVal;
}

V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_OsRestoreInterruptSource(Can_ExternalISRType IsrId, boolean OldFlag){

  if(OldFlag==TRUE){

    (void)osEnableInterruptSource(IsrId, FALSE);
  }
}

#endif

#if defined(C_ENABLE_LL_CAN_WAKEUP_INTCTRL) && defined(C_ENABLE_WAKEUP_POLLING)

V_DEF_FUNC(CAN_LOCAL_INLINE, boolean, STATIC_CODE) CanLL_OsIsInterruptPending(Can_ExternalISRType IsrId){

  boolean retVal;

  (void)osIsInterruptPending(IsrId, &retVal);
  return retVal;
}

#endif
#endif
#endif

V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_InitPowerOnModeTransitions(void){

#if defined(C_ENABLE_HW_LOOP_TIMER)
  CAN_CHANNEL_CANTYPE_LOCAL
#endif

#if defined(C_ENABLE_HW_LOOP_TIMER) && defined(C_MULTIPLE_RECEIVE_CHANNEL)
  channel = 0;
#endif

  if((Can->CGSR & kCanSrMaskRamIst) != 0u){
    CanLL_CanTimerStart(kCanLoopRamInit);
#if defined(C_ENABLE_HW_LOOP_TIMER)
    while(((Can->CGSR & kCanSrMaskRamIst) != 0u) && (CanLL_CanTimerLoop(kCanLoopRamInit) != CAN_NOT_OK))
#else
    while((Can->CGSR & kCanSrMaskRamIst) != 0u)
#endif
    {
      ;
    }
    CanLL_CanTimerEnd(kCanLoopRamInit);
  }

  if(!CanLL_GlobalModeCheck(kCanStopMode)){
    CanLL_GlobalModeReq(kCanResetMode);
    if(!CanLL_GlobalModeCheck(kCanResetMode)){
      CanLL_GlobalModeWait(kCanResetMode, kCanLoopGlobalInit);
    }
    CanLL_GlobalModeReq(kCanStopMode);
    if(!CanLL_GlobalModeCheck(kCanStopMode)){
      CanLL_GlobalModeWait(kCanStopMode, kCanLoopGlobalInit);
    }
  }

#if defined(C_ENABLE_ECC_CONFIGURATION)

  ApplCanEccConfiguration();
#endif

  CanLL_GlobalModeReq(kCanResetMode);
  if(!CanLL_GlobalModeCheck(kCanResetMode)){
    CanLL_GlobalModeWait(kCanResetMode, kCanLoopGlobalInit);
  }
}

V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_InitPowerOnGlobalInit(void){

  CAN_CHANNEL_CANTYPE_LOCAL
#if defined(C_MULTIPLE_PHYS_CHANNEL)
  CanChannelHandle canPhysChannel;
#endif
  vuint8 canFcObjTmp;
  vuint8 canPhysChannelIndex;
  vuint8 canFifoIndex;

  canFcObjTmp = kCanZero;

  CanLL_WriteRegGlobalRegSize(&Can->CRNCFG[0], kCanZero);
#if(kCanMaxPhysChannels > 4)
  CanLL_WriteRegGlobalRegSize(&Can->CRNCFG[1], kCanZero);
#endif

  for(canFifoIndex = 0; canFifoIndex < kCanMaxRxFifos; canFifoIndex++){
    CanLL_WriteRegGlobalRegSize(&Can->CRFCR[canFifoIndex], kCanZero);
  }
  for(canPhysChannelIndex = 0; canPhysChannelIndex < kCanMaxPhysChannels; canPhysChannelIndex++){
    for(canFifoIndex = 0; canFifoIndex < kCanMaxTxFifos; canFifoIndex++){
      CanLL_WriteRegGlobal32(&Can->ChFC[canPhysChannelIndex].TRFCR[canFifoIndex], kCanZero);
    }
  }

#if defined(C_MULTIPLE_RECEIVE_CHANNEL)

  for(channel = 0; channel < kCanNumberOfChannels; channel++)
#endif
  {

#if(CAN_POSTBUILD_VARIANT_SUPPORT == STD_ON)
    if(Can_GetCanIfChannelId(channel) != CAN_NO_CANIFCHANNELID)
#endif
    {
#if defined(C_MULTIPLE_PHYS_CHANNEL)
      canPhysChannel = mCanLogToPhys(channel);
#endif

      CanLL_ModeReq_Phys(canPhysChannel, kCanResetMode);
      if(!CanLL_ModeCheck_Phys(canPhysChannel, kCanResetMode))
      {
        CanLL_ModeWait(CAN_CHANNEL_CANPARA_FIRST canPhysChannel, kCanResetMode, kCanLoopGlobalInit);
      }

#if defined(C_ENABLE_RX_FULLCAN_OBJECTS)

      canFcObjTmp += Can_GetRxFcCount(channel);
#endif

      CanLL_WriteRegGlobalRegSize(&Can->TQCR[canPhysChannel], kCanZero);

#if defined(C_ENABLE_TX_HW_FIFO)

      for(canFifoIndex = kCanZero; canFifoIndex < Can_GetTxFifoCountOfChannelData(channel); canFifoIndex++)
      {
        CanLL_WriteRegGlobal32(&Can->ChFC[canPhysChannel].TRFCR[canFifoIndex], Can_GetTxFifoData(Can_GetTxFifoStartIndexOfChannelData(channel) + canFifoIndex));
      }
#endif

      CanLL_InitPowerOnRuleAndFifoInit(CAN_CHANNEL_CANPARA_ONLY);
    }
  }

#if defined(C_ENABLE_CAN_FD_FULL)
  CanLL_WriteRegGlobalRegSize(&Can->CRBNUM, ((((kCanRegSize)Can_GetRxBufferPayloadStorageSize()) << 8) | canFcObjTmp));
#else
  CanLL_WriteRegGlobalRegSize(&Can->CRBNUM, canFcObjTmp);
#endif

#if defined(C_ENABLE_GLOBAL_INIT_POST_PROCESS)
  ApplCanGlobalInitPostProcessing();
#endif

  CanLL_WriteRegGlobalRegSize(&Can->CRECR, kCanRuleReceive);
}

V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_InitPowerOnRuleAndFifoInit(CAN_CHANNEL_CANTYPE_ONLY){

#if defined(C_MULTIPLE_PHYS_CHANNEL)
#if defined(C_ENABLE_RX_FULLCAN_OBJECTS) || defined(C_ENABLE_RX_BASICCAN_OBJECTS) || defined(C_ENABLE_TX_HW_FIFO)
  CanChannelHandle canPhysChannel;
#endif
#endif
#if defined(C_ENABLE_RX_FULLCAN_OBJECTS) || defined(C_ENABLE_RX_BASICCAN_OBJECTS) || defined(C_ENABLE_TX_HW_FIFO)
  CanObjectHandle hwObjHandle;
#endif
#if defined(C_ENABLE_RX_FULLCAN_OBJECTS) || defined(C_ENABLE_RX_BASICCAN_OBJECTS)
  CanObjectHandle mailboxHandle;
  kCanRegSize canTmpRegRs;
  vuint8 canFilterRulesIndex;
  vuint8 canFilterRulesPage;
#endif
#if defined(C_ENABLE_RX_BASICCAN_OBJECTS)
  vuint8 canLogHwFifoHandle;
  vuint8 canFilterRulesBcIndex;
  vuint8 canFilterRulesBcStartIndex;
  vuint8 canFilterRulesBcStopIndex;
#endif

#if defined(C_MULTIPLE_PHYS_CHANNEL)
#if defined(C_ENABLE_RX_FULLCAN_OBJECTS) || defined(C_ENABLE_RX_BASICCAN_OBJECTS) || defined(C_ENABLE_TX_HW_FIFO)
  canPhysChannel = mCanLogToPhys(channel);
#endif
#endif

#if defined(C_ENABLE_RX_FULLCAN_OBJECTS) || defined(C_ENABLE_RX_BASICCAN_OBJECTS)

  canTmpRegRs = (Can->CRNCFG[CanLL_ByteIndex(canPhysChannel)] | CanLL_FilterListConfig(canPhysChannel, Can_GetFrTotalCountOfChannelData(channel)));
  CanLL_WriteRegGlobalRegSize(&Can->CRNCFG[CanLL_ByteIndex(canPhysChannel)], canTmpRegRs);

  canFilterRulesIndex = (vuint8) (Can_GetFrStartIndexOfChannelData(channel) & kCanRuleIndexMask);
  canFilterRulesPage = (vuint8) ((Can_GetFrStartIndexOfChannelData(channel) & kCanRulePageMask) >> kCanRulePageShiftVal);
  CanLL_WriteRegGlobalRegSize(&Can->CRECR, (kCanRegSize)(kCanRuleWrite | canFilterRulesPage));
#endif

#if defined(C_ENABLE_RX_FULLCAN_OBJECTS)

  for(mailboxHandle=CAN_HL_MB_RX_FULL_STARTINDEX(channel); mailboxHandle<CAN_HL_MB_RX_FULL_STOPINDEX(channel); mailboxHandle++){
    hwObjHandle = Can_GetMailboxHwHandle(mailboxHandle);

    CanLL_InitPowerOnRulePageUpdate(&canFilterRulesIndex, &canFilterRulesPage);

#if defined(C_ENABLE_EXTENDED_ID)
#if defined(C_ENABLE_MIXED_ID)
    if((Can_GetMailboxIDValue(mailboxHandle) & CAN_ID_IDE_MASK) != CAN_ID_IDE_MASK){
      CanLL_WriteRegGlobal32(&mRuleCode(canFilterRulesIndex), MK_STDID0(Can_GetMailboxIDValue(mailboxHandle)));
      CanLL_WriteRegGlobal32(&mRuleMask(canFilterRulesIndex), kCanRuleStdMustMatch);
    }
    else
#endif
    {
      CanLL_WriteRegGlobal32(&mRuleCode(canFilterRulesIndex), MK_EXTID0(Can_GetMailboxIDValue(mailboxHandle)));
      CanLL_WriteRegGlobal32(&mRuleMask(canFilterRulesIndex), kCanRuleExtMustMatch);
    }
#else
    {
      CanLL_WriteRegGlobal32(&mRuleCode(canFilterRulesIndex), MK_STDID0(Can_GetMailboxIDValue(mailboxHandle)));
      CanLL_WriteRegGlobal32(&mRuleMask(canFilterRulesIndex), kCanRuleStdMustMatch);
    }
#endif

    CanLL_WriteRegGlobal32(&mRuleBuf(canFilterRulesIndex), (kCanRuleUseBuf | (((vuint32)(hwObjHandle)) << 8)));
    CanLL_WriteRegGlobal32(&mRuleFifo(canFilterRulesIndex), kCanZero);
    canFilterRulesIndex++;
  }
#endif

#if defined(C_ENABLE_RX_BASICCAN_OBJECTS)

  mailboxHandle = CAN_HL_MB_RX_BASIC_STARTINDEX(channel);
  hwObjHandle = Can_GetMailboxHwHandle(mailboxHandle);
#if defined(C_ENABLE_MULTIPLE_BASICCAN)
  for(; mailboxHandle < CAN_HL_MB_RX_BASIC_STOPINDEX(channel); mailboxHandle++)
#endif
  {
#if(CAN_SAFE_BSW == STD_ON)
    if(hwObjHandle < kCanMaxRxFifos)
#endif
    {

      canLogHwFifoHandle = (vuint8)hwObjHandle;
      canFilterRulesBcStartIndex = Can_GetFilterStartIndexOfRxFifoData(canLogHwFifoHandle);
      canFilterRulesBcStopIndex = Can_GetFilterStopIndexOfRxFifoData(canLogHwFifoHandle);
      for(canFilterRulesBcIndex=canFilterRulesBcStartIndex; canFilterRulesBcIndex<canFilterRulesBcStopIndex; canFilterRulesBcIndex++)
      {
        CanLL_InitPowerOnRulePageUpdate(&canFilterRulesIndex, &canFilterRulesPage);

        CanLL_WriteRegGlobal32(&mRuleCode(canFilterRulesIndex), ((vuint32) Can_GetCodeOfInitFilterRules(canFilterRulesBcIndex)));
        CanLL_WriteRegGlobal32(&mRuleMask(canFilterRulesIndex), ((vuint32) (kCanRuleHeader | Can_GetMaskOfInitFilterRules(canFilterRulesBcIndex))));

        CanLL_WriteRegGlobal32(&mRuleBuf(canFilterRulesIndex), kCanZero);
        CanLL_WriteRegGlobal32(&mRuleFifo(canFilterRulesIndex), CanLL_SL32(hwObjHandle));
        canFilterRulesIndex++;
      }

#if defined(C_ENABLE_CAN_FD_FULL)
      canTmpRegRs = (kCanCrRxFifoSet | ((kCanRegSize)((kCanRegSize)Can_GetFifoDepthOfRxFifoData(canLogHwFifoHandle) << 8)) | ((kCanRegSize)((kCanRegSize)Can_GetFifoPayloadStorageSizeOfRxFifoData(canLogHwFifoHandle) << 4)));
#else
      canTmpRegRs = (kCanCrRxFifoSet | ((kCanRegSize)((kCanRegSize)Can_GetFifoDepthOfRxFifoData(canLogHwFifoHandle) << 8)));
#endif
#if defined(C_ENABLE_INDIVIDUAL_POLLING) || !defined(C_ENABLE_RX_BASICCAN_POLLING)
#if defined(C_ENABLE_INDIVIDUAL_POLLING)
      if(!Can_IsMailboxIndivPolling(mailboxHandle))
#endif
      {
        canTmpRegRs |= kCanCrRxFifoIntEnable;
      }
#endif
      CanLL_WriteRegGlobalRegSize(&Can->CRFCR[hwObjHandle], canTmpRegRs);
    }
#if defined(C_ENABLE_MULTIPLE_BASICCAN)
    hwObjHandle++;
#endif
  }
#endif

#if defined(C_ENABLE_GLOBAL_INIT_POST_PROCESS)

#if defined(C_ENABLE_RX_FULLCAN_OBJECTS) || defined(C_ENABLE_RX_BASICCAN_OBJECTS)
  CanLL_InitPowerOnRulePageUpdate(&canFilterRulesIndex, &canFilterRulesPage);
  CanAddFilterRulesStartPage = canFilterRulesPage;
  CanAddFilterRulesStartIndex = canFilterRulesIndex;
#else
  CanLL_WriteRegGlobalRegSize(&Can->CRECR, kCanRuleWrite);
  CanAddFilterRulesStartPage = 0;
  CanAddFilterRulesStartIndex = 0;
#endif
#endif

#if !defined(C_ENABLE_RX_FULLCAN_OBJECTS) && !defined(C_ENABLE_RX_BASICCAN_OBJECTS)
  CAN_CHANNEL_DUMMY_STATEMENT;
#endif
}

#if defined(C_ENABLE_RX_FULLCAN_OBJECTS) || defined(C_ENABLE_RX_BASICCAN_OBJECTS)

V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_InitPowerOnRulePageUpdate(CanVarPtr8 canFilterRulesIndexPtr, CanVarPtr8 canFilterRulesPagePtr){

  if(*canFilterRulesIndexPtr >= kCanMaxRuleAccessCell){

    (*canFilterRulesPagePtr)++;
    CanLL_WriteRegGlobalRegSize(&Can->CRECR, (kCanRegSize)(kCanRuleWrite | (*canFilterRulesPagePtr)));
    (*canFilterRulesIndexPtr) = 0;
  }
}

#endif

V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_WriteReg32(CAN_CHANNEL_CANTYPE_FIRST CanChipMsgPtr32 regPtr, vuint32 val, CanInitParaStructPtr initPara){
#if defined(C_ENABLE_CAN_RAM_CHECK_EXTENDED)

  volatile vuint32 readBack;
  vuint8 result = kCanFalse;
#endif

  *regPtr = val;

#if defined(C_ENABLE_CAN_RAM_CHECK_EXTENDED)
  if(initPara->doRamCheck == kCanExecuteRamCheck){

    readBack = *regPtr;

    if(readBack != val){
      result = kCanTrue;
    }
    CAN_RAM_CHECK_READ_BACK_RESULT(channel)
    initPara->isChRamCheckFail |= result;
  }
#else
  CAN_DUMMY_STATEMENT(initPara);
#endif
  CAN_CHANNEL_DUMMY_STATEMENT;
}

V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_WriteRegGlobal32(CanChipMsgPtr32 regPtr, vuint32 val){
#if defined(C_ENABLE_CAN_RAM_CHECK_EXTENDED)

  volatile vuint32 readBack;
#endif

  *regPtr = val;

#if defined(C_ENABLE_CAN_RAM_CHECK_EXTENDED)

  readBack = *regPtr;

  if(readBack != val){
    canIsCellCorrupt = kCanTrue;
  }
#endif
}

V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_ModeWait(CAN_CHANNEL_CANTYPE_FIRST CanChannelHandle PhysChannel, vuint8 Mode, vuint8 Loop){

  CanLL_CanTimerStart(Loop);
#if defined(C_ENABLE_HW_LOOP_TIMER)
  while((!CanLL_ModeCheck_Phys(PhysChannel, Mode)) && (CanLL_CanTimerLoop(Loop) != CAN_NOT_OK))
#else
  while(!CanLL_ModeCheck_Phys(PhysChannel, Mode))
#endif
  {
    ;
  }
  CanLL_CanTimerEnd(Loop);

#if !defined(C_ENABLE_HW_LOOP_TIMER)
  CAN_CHANNEL_DUMMY_STATEMENT;
  CAN_DUMMY_STATEMENT(Loop);
#endif
}

V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_GlobalModeWait(vuint8 Mode, vuint8 Loop){

#if defined(C_ENABLE_HW_LOOP_TIMER)
  CAN_CHANNEL_CANTYPE_LOCAL
#endif

#if defined(C_ENABLE_HW_LOOP_TIMER) && defined(C_MULTIPLE_RECEIVE_CHANNEL)
  channel = 0;
#endif

  CanLL_CanTimerStart(Loop);
#if defined(C_ENABLE_HW_LOOP_TIMER)
  while((!CanLL_GlobalModeCheck(Mode)) && (CanLL_CanTimerLoop(Loop) != CAN_NOT_OK))
#else
  while(!CanLL_GlobalModeCheck(Mode))
#endif
  {
    ;
  }
  CanLL_CanTimerEnd(Loop);

#if !defined(C_ENABLE_HW_LOOP_TIMER)
  CAN_DUMMY_STATEMENT(Loop);
#endif
}

V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_ChannelTransitionReset(CAN_CHANNEL_CANTYPE_ONLY){

#if defined(C_MULTIPLE_PHYS_CHANNEL)
  CanChannelHandle canPhysChannel = mCanLogToPhys(canHwChannel);
#endif
  vuint8 retVal = kCanFailed;

  CanLL_ModeReq_Phys(canPhysChannel, kCanResetMode);

  if(!CanLL_ModeCheck_Phys(canPhysChannel, kCanResetMode)){
    CanLL_ModeWait(CAN_CHANNEL_CANPARA_FIRST canPhysChannel, kCanResetMode, kCanLoopChannelTransition);
  }

#if defined(C_ENABLE_HW_LOOP_TIMER)
  if(CanLL_ModeCheck_Phys(canPhysChannel, kCanResetMode))
#endif
  {
    retVal = kCanOk;
  }

  return (retVal);
}

#if defined(C_ENABLE_SLEEP_WAKEUP)

V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_ChannelTransitionSleep(CAN_CHANNEL_CANTYPE_ONLY){

#if defined(C_MULTIPLE_PHYS_CHANNEL)
  CanChannelHandle canPhysChannel = mCanLogToPhys(canHwChannel);
#endif
  vuint8 retVal = kCanFailed;

  CanLL_ModeReq_Phys(canPhysChannel, kCanStopMode);

  if(!CanLL_ModeCheck_Phys(canPhysChannel, kCanStopMode)){
    CanLL_ModeWait(CAN_CHANNEL_CANPARA_FIRST canPhysChannel, kCanStopMode, kCanLoopChannelTransition);
  }

#if defined(C_ENABLE_HW_LOOP_TIMER)
  if(CanLL_ModeCheck_Phys(canPhysChannel, kCanStopMode))
#endif
  {

#if defined(C_ENABLE_LL_CAN_WAKEUP_INTCTRL)
    CanLL_ClearCanWakeupInterruptFlag(CAN_HW_CHANNEL_CANPARA_ONLY);
#endif
#if !defined(C_ENABLE_WAKEUP_POLLING) && defined(C_ENABLE_LL_CAN_INTCTRL)

    CanLL_CanWakeupInterruptEnable(CAN_HW_CHANNEL_CANPARA_FIRST &Can_GetCanInterruptOldStatus(canHwChannel));
#endif
#if defined(C_ENABLE_LL_CAN_INTCB) || defined(C_ENABLE_LL_CAN_WAKEUP_INTCB)

    ApplCanWakeupInterruptEnable(canHwChannel);
#endif
    retVal = kCanOk;
  }

  return (retVal);
}

#endif

V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_ChannelTransitionStart(CAN_CHANNEL_CANTYPE_ONLY){

#if defined(C_MULTIPLE_PHYS_CHANNEL)
  CanChannelHandle canPhysChannel = mCanLogToPhys(canHwChannel);
#endif
#if defined(C_ENABLE_TX_HW_FIFO)
  CanObjectHandle hwObjHandle;
#endif
  vuint8 retVal = kCanFailed;

#if defined(C_ENABLE_CAN_RAM_CHECK_EXTENDED)
  if(canIsCellCorrupt == kCanFalse)
#endif
  {

    CanLL_ModeReq_Phys(canPhysChannel, kCanOperationMode);

    CanLL_ModeWait(CAN_CHANNEL_CANPARA_FIRST canPhysChannel, kCanOperationMode, kCanLoopChannelTransition);

#if defined(C_ENABLE_HW_LOOP_TIMER)
    if(CanLL_ModeCheck_Phys(canPhysChannel, kCanOperationMode))
#endif
    {
#if defined(C_ENABLE_TX_HW_FIFO)

      for(hwObjHandle = kCanZero; hwObjHandle < Can_GetTxFifoCountOfChannelData(channel); hwObjHandle++)
      {
        Can->ChFC[canPhysChannel].TRFCR[hwObjHandle] |= kCanCrFifoEnable;
      }
#endif
      retVal = kCanOk;
    }
  }

  return (retVal);
}

#if defined(C_ENABLE_SILENT_MODE)

V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_ChannelTransitionHalt(CAN_CHANNEL_CANTYPE_ONLY){

#if defined(C_MULTIPLE_PHYS_CHANNEL)
  CanChannelHandle canPhysChannel = mCanLogToPhys(canHwChannel);
#endif
  vuint8 retVal = kCanFailed;

  CanLL_ModeReq_Phys(canPhysChannel, kCanHaltMode);

  CanLL_ModeWait(CAN_CHANNEL_CANPARA_FIRST canPhysChannel, kCanHaltMode, kCanLoopChannelTransition);

#if defined(C_ENABLE_HW_LOOP_TIMER)
  if(CanLL_ModeCheck_Phys(canPhysChannel, kCanHaltMode))
#endif
  {
    retVal = kCanOk;
  }

  return (retVal);
}

#endif

#if defined(C_ENABLE_CAN_RAM_CHECK_EXTENDED)

V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_IsGlobalRegisterCorrupt(void){

  vuint8 canGlobalRegCheckFailed;
  vuint8 idx;
  vuint8 canPhysChannelIndex;
  vuint8 canFifoIndex;
  vuint8 canFilterRulesIndex;

  canGlobalRegCheckFailed = kCanFalse;

  for(idx=0u; idx<3u; idx++){

    Can->CGCFG = (CanMemCheckValues32bit[idx] & kCanRamCheckMaskCGCFG);

    Can->CGCR = ((CanMemCheckValues32bit[idx] & kCanRamCheckMaskCGCR) | kCanResetMode);
#if defined(C_ENABLE_RSCAN_FD_LAYOUT)
#if defined(C_ENABLE_CAN_FD_CONFIGURATION)

    Can->CGFDCFG = (CanMemCheckValues32bit[idx] & kCanRamCheckMaskCGFDCFG);
#endif
#if defined(C_ENABLE_CAN_CRC_CONFIGURATION)

    Can->CGCRCCFG = (CanMemCheckValues32bit[idx] & kCanRamCheckMaskCGCRCCFG);
#endif
#endif

    Can->CRECR = (CanMemCheckValuesRegSize[idx] & kCanRamCheckMaskCRECR);

    Can->CRNCFG[0] = (CanMemCheckValuesRegSize[idx] & kCanRamCheckMaskCRNCFG0);
#if(kCanMaxPhysChannels > 4)
    Can->CRNCFG[1] = (CanMemCheckValuesRegSize[idx] & kCanRamCheckMaskCRNCFG1);
#endif

    Can->CRBNUM = (CanMemCheckValuesRegSize[idx] & kCanRamCheckMaskCRBNUM);

    if(   ((Can->CGCFG & kCanRamCheckMaskCGCFG) != (CanMemCheckValues32bit[idx] & kCanRamCheckMaskCGCFG))
        || ((Can->CGCR & kCanRamCheckMaskCGCR) != (CanMemCheckValues32bit[idx] & kCanRamCheckMaskCGCR))
#if defined(C_ENABLE_RSCAN_FD_LAYOUT)
#if defined(C_ENABLE_CAN_FD_CONFIGURATION)
        || ((Can->CGFDCFG & kCanRamCheckMaskCGFDCFG) != (CanMemCheckValues32bit[idx] & kCanRamCheckMaskCGFDCFG))
#endif
#if defined(C_ENABLE_CAN_CRC_CONFIGURATION)
        || ((Can->CGCRCCFG & kCanRamCheckMaskCGCRCCFG) != (CanMemCheckValues32bit[idx] & kCanRamCheckMaskCGCRCCFG))
#endif
#endif
        || ((Can->CRECR & kCanRamCheckMaskCRECR) != (CanMemCheckValuesRegSize[idx] & kCanRamCheckMaskCRECR))
        || ((Can->CRNCFG[0] & kCanRamCheckMaskCRNCFG0) != (CanMemCheckValuesRegSize[idx] & kCanRamCheckMaskCRNCFG0))
#if(kCanMaxPhysChannels > 4)
        || ((Can->CRNCFG[1] & kCanRamCheckMaskCRNCFG1) != (CanMemCheckValuesRegSize[idx] & kCanRamCheckMaskCRNCFG1))
#endif
        || ((Can->CRBNUM & kCanRamCheckMaskCRBNUM) != (CanMemCheckValuesRegSize[idx] & kCanRamCheckMaskCRBNUM))
       ){
      canGlobalRegCheckFailed = kCanTrue;
    }

    for(canFifoIndex=0; canFifoIndex<kCanMaxRxFifos; canFifoIndex++){

      Can->CRFCR[canFifoIndex] = (CanMemCheckValuesRegSize[idx] & kCanRamCheckMaskCRFCR);
      if((Can->CRFCR[canFifoIndex] & kCanRamCheckMaskCRFCR) != (CanMemCheckValuesRegSize[idx] & kCanRamCheckMaskCRFCR))
      {
        canGlobalRegCheckFailed = kCanTrue;
      }
    }

    for(canPhysChannelIndex = 0; canPhysChannelIndex < kCanMaxPhysChannels; canPhysChannelIndex++){
      for(canFifoIndex=0; canFifoIndex<kCanMaxTxFifos; canFifoIndex++)
      {

        Can->ChFC[canPhysChannelIndex].TRFCR[canFifoIndex] = (CanMemCheckValues32bit[idx] & kCanRamCheckMaskTRFCR);
        if((Can->ChFC[canPhysChannelIndex].TRFCR[canFifoIndex] & kCanRamCheckMaskTRFCR) != (CanMemCheckValues32bit[idx] & kCanRamCheckMaskTRFCR))
        {
          canGlobalRegCheckFailed = kCanTrue;
        }
      }
    }

    Can->CRECR = kCanRuleWrite | kCanZero;

    for(canFilterRulesIndex=0; canFilterRulesIndex<kCanMaxRuleAccessCell; canFilterRulesIndex++){

      mRuleCode(canFilterRulesIndex) = (CanMemCheckValues32bit[idx] & kCanRamCheckMaskRuleCode);
      mRuleMask(canFilterRulesIndex) = (CanMemCheckValues32bit[idx] & kCanRamCheckMaskRuleMask);
      mRuleBuf(canFilterRulesIndex) = (CanMemCheckValues32bit[idx] & kCanRamCheckMaskRuleBuf);
      mRuleFifo(canFilterRulesIndex) = (CanMemCheckValues32bit[idx] & kCanRamCheckMaskRuleFifo);

      if(   ((mRuleCode(canFilterRulesIndex) & kCanRamCheckMaskRuleCode) != (CanMemCheckValues32bit[idx] & kCanRamCheckMaskRuleCode))
          || ((mRuleMask(canFilterRulesIndex) & kCanRamCheckMaskRuleMask) != (CanMemCheckValues32bit[idx] & kCanRamCheckMaskRuleMask))
          || ((mRuleBuf(canFilterRulesIndex) & kCanRamCheckMaskRuleBuf) != (CanMemCheckValues32bit[idx] & kCanRamCheckMaskRuleBuf))
          || ((mRuleFifo(canFilterRulesIndex) & kCanRamCheckMaskRuleFifo) != (CanMemCheckValues32bit[idx] & kCanRamCheckMaskRuleFifo))
         )
      {
        canGlobalRegCheckFailed = kCanTrue;
      }
    }
  }

  Can->CGCR = kCanResetMode;

  return (canGlobalRegCheckFailed);
}

#endif

#if(CAN_SAFE_BSW == STD_ON)

V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_CheckGeneratedData(void){

  CAN_CHANNEL_CANTYPE_LOCAL
  CanChannelHandle physChannelIndex;
  vuint8 retVal = kCanOk;

#if defined(C_ENABLE_CAN_FD_FULL)
  if((sizeof(Can_GetRxTmpBuf(0).u.iData) / sizeof(Can_GetRxTmpBuf(0).u.iData[0])) < 16u)
#else
  if((sizeof(Can_GetRxTmpBuf(0).u.iData) / sizeof(Can_GetRxTmpBuf(0).u.iData[0])) < 2u)
#endif
  {
    retVal = kCanFailed;
  }
  else{
#if defined(C_MULTIPLE_RECEIVE_CHANNEL)

    for(channel = 0; channel < kCanNumberOfChannels; channel++)
#endif
    {
#if(CAN_POSTBUILD_VARIANT_SUPPORT == STD_ON)
      if(Can_GetCanIfChannelId(channel) != CAN_NO_CANIFCHANNELID)
#endif
      {
#if defined(C_ENABLE_TX_HW_FIFO)

        if(Can_GetTxFifoCountOfChannelData(channel) > kCanMaxTxFifos)
        {
          retVal = kCanFailed;
        }
        else
#endif
        {

          physChannelIndex = mCanLogToPhys(channel);
          if(physChannelIndex >= kCanMaxPhysChannels)
          {
            retVal = kCanFailed;
          }
#if defined(C_MULTIPLE_RECEIVE_CHANNEL)
          else
          {

#if(CAN_POSTBUILD_VARIANT_SUPPORT == STD_ON)
            if(Can_GetPhysToLogChannel(physChannelIndex) != channel)
            {
              retVal = kCanFailed;
            }
#else
            switch(physChannelIndex)
            {
#if defined(kCanPhysToLogChannelIndex_0)
              case 0:
                if(kCanPhysToLogChannelIndex_0 != channel)
                {
                  retVal = kCanFailed;
                }
                break;
#endif
#if defined(kCanPhysToLogChannelIndex_1)
              case 1:
                if(kCanPhysToLogChannelIndex_1 != channel)
                {
                  retVal = kCanFailed;
                }
                break;
#endif
#if defined(kCanPhysToLogChannelIndex_2)
              case 2:
                if(kCanPhysToLogChannelIndex_2 != channel)
                {
                  retVal = kCanFailed;
                }
                break;
#endif
#if defined(kCanPhysToLogChannelIndex_3)
              case 3:
                if(kCanPhysToLogChannelIndex_3 != channel)
                {
                  retVal = kCanFailed;
                }
                break;
#endif
#if defined(kCanPhysToLogChannelIndex_4)
              case 4:
                if(kCanPhysToLogChannelIndex_4 != channel)
                {
                  retVal = kCanFailed;
                }
                break;
#endif
#if defined(kCanPhysToLogChannelIndex_5)
              case 5:
                if(kCanPhysToLogChannelIndex_5 != channel)
                {
                  retVal = kCanFailed;
                }
                break;
#endif
#if defined(kCanPhysToLogChannelIndex_6)
              case 6:
                if(kCanPhysToLogChannelIndex_6 != channel)
                {
                  retVal = kCanFailed;
                }
                break;
#endif
#if defined(kCanPhysToLogChannelIndex_7)
              case 7:
                if(kCanPhysToLogChannelIndex_7 != channel)
                {
                  retVal = kCanFailed;
                }
                break;
#endif
              default:
                retVal = kCanFailed;
                break;
            }
#endif
          }
#endif
        }
      }
    }
  }

#if(CAN_DEV_ERROR_REPORT == STD_ON)
  if(retVal != kCanOk){
    Can_CallDetReportError(CAN_INIT_ID, CAN_E_GENDATA);
  }
#endif

  return (retVal);
}

#endif

#if defined(C_ENABLE_TX_POLLING)

V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanHL_TxConfirmationPolling( CAN_HW_CHANNEL_CANTYPE_FIRST CanObjectHandle mailboxHandle, CanObjectHandle mailboxElement, CanObjectHandle hwObjHandle ){

  Can_DisableControllerInterrupts((uint8)channel);

  CanHL_TxConfirmation(CAN_HW_CHANNEL_CANPARA_FIRST mailboxHandle, mailboxElement, hwObjHandle);
  Can_EnableControllerInterrupts((uint8)channel);
}
#endif

V_DEF_FUNC(CAN_STATIC, void, STATIC_CODE) CanHL_TxConfirmation( CAN_HW_CHANNEL_CANTYPE_FIRST CanObjectHandle mailboxHandle, CanObjectHandle mailboxElement, CanObjectHandle hwObjHandle ){

  uint8 errorId;
  tCanTxConfirmationParaStruct txConfPara;
#if defined(CAN_ENABLE_GENERIC_CONFIRMATION_API2)
  tCanTxConfInfoStruct txConfInfoStruct;
#endif
  CanHookBegin_CanHL_TxConfirmation();
  errorId = CAN_E_NO_ERROR;
  txConfPara.mailboxHandle = mailboxHandle;
  txConfPara.mailboxElement = mailboxElement;
  txConfPara.hwObjHandle = hwObjHandle;
#if defined(CAN_ENABLE_GENERIC_CONFIRMATION_API2)
  txConfPara.txStructConf = &txConfInfoStruct;
#endif

#if(CAN_DEV_ERROR_DETECT == STD_ON)
#if !defined(C_ENABLE_TX_POLLING)

#if !defined( C_SINGLE_RECEIVE_CHANNEL )
  if(channel >= kCanNumberOfChannels){
    errorId = CAN_E_PARAM_CONTROLLER;
  }
  else
#endif
  if(
#if defined(C_ENABLE_TX_FULLCAN_OBJECTS)
       ((txConfPara.mailboxHandle < Can_GetTxFullHandleStart(canHwChannel)) || (txConfPara.mailboxHandle >= Can_GetTxFullHandleStop(canHwChannel))) &&
#endif
       ((txConfPara.mailboxHandle < Can_GetTxBasicHandleStart(canHwChannel)) || (txConfPara.mailboxHandle >= Can_GetTxBasicHandleStop(canHwChannel))) ){
    errorId = CAN_E_PARAM_HANDLE;
  }
  else
#endif
#endif
  {

    PduIdType tmp_pdu;
#if defined(C_ENABLE_CANCEL_SUPPORT_API)
    uint8_least tmp_state;
#endif
#if defined(CAN_ENABLE_GENERIC_CONFIRMATION_API2)
    Can_ReturnType generic_retval;
#endif
#if defined(C_ENABLE_TX_HW_FIFO)
    uint16 txHwFifo;
#endif
#if(defined(CAN_USE_CRITICALSECTION_OVER_CONFIRMATION) && (CAN_TRANSMIT_BUFFER == STD_ON)) || defined(CAN_ENABLE_GENERIC_CONFIRMATION_API2)

    SchM_Enter_Can_CAN_EXCLUSIVE_AREA_3();
#endif
#if defined(C_ENABLE_TX_HW_FIFO)
    if(Can_GetMailboxType(txConfPara.mailboxHandle) == CAN_TX_BASICCAN_FIFO_TYPE){
      SchM_Enter_Can_CAN_EXCLUSIVE_AREA_7();
      txHwFifo = Can_GetMailboxTxHwFifo(txConfPara.mailboxHandle);
#if(CAN_SAFE_BSW == STD_ON)
      if(txHwFifo >= (uint16)Can_GetSizeOfTxHwFifo())
      {
        txHwFifo = 0u;
      }
#endif
      txConfPara.mailboxElement = (CanObjectHandle)Can_GetTxHwFifoReadIndex(txHwFifo);

      if(Can_GetTxHwFifoReadIndex(txHwFifo) < ((uint16)Can_GetMailboxSize(txConfPara.mailboxHandle) - (uint16)1u) )
      {
        Can_IncTxHwFifoReadIndex(txHwFifo);
      }
      else
      {
        Can_SetTxHwFifoReadIndex(txHwFifo, 0u);
      }
      Can_DecTxHwFifoFillCount(txHwFifo);
      SchM_Exit_Can_CAN_EXCLUSIVE_AREA_7();
    }
#endif
    txConfPara.activeSendObject = CanHL_GetActiveSendObject(txConfPara.mailboxHandle, txConfPara.mailboxElement);
    {

      CanLL_TxConfBegin(CAN_CHANNEL_AND_HW_CHANNEL_CANPARA_FIRST &txConfPara);

      tmp_pdu   = Can_GetActiveSendPdu(txConfPara.activeSendObject);
#if defined(C_ENABLE_CANCEL_SUPPORT_API)

      tmp_state = (uint8_least)Can_GetActiveSendState(txConfPara.activeSendObject);
#endif
#if defined(C_ENABLE_CANCEL_TX_IN_HW)

      if(CanLL_TxConfIsMsgTransmitted(CAN_CHANNEL_AND_HW_CHANNEL_CANPARA_FIRST &txConfPara) == kCanTrue)
#endif
      {

#if defined(CAN_ENABLE_GENERIC_CONFIRMATION_API1)
        Can_SetActiveSendState(txConfPara.activeSendObject, kCanBufferFree);
        if(Appl_GenericConfirmation( tmp_pdu ) == CAN_OK)
#elif defined(CAN_ENABLE_GENERIC_CONFIRMATION_API2)
#if defined(C_ENABLE_MIRROR_MODE)
        if(Can_GetMirrorModeState(channel) == CDDMIRROR_INACTIVE)
        {
          Can_SetActiveSendState(txConfPara.activeSendObject, kCanBufferFree);
          generic_retval = CAN_OK;
        }
        else
#endif
        {
#if defined(C_ENABLE_TX_HW_FIFO)
          if(Can_GetMailboxType(txConfPara.mailboxHandle) == CAN_TX_BASICCAN_FIFO_TYPE)
          {
            Can_SetActiveSendState(txConfPara.activeSendObject, kCanBufferFree);

            generic_retval = Appl_GenericConfirmation( (uint8)channel, &Can_GetActiveSendPduInfo(txConfPara.activeSendObject) );
          }
          else
#endif
          {
            Can_PduType canPdu;
            CanLL_TxConfSetTxConfStruct(CAN_CHANNEL_AND_HW_CHANNEL_CANPARA_FIRST &txConfPara);
            canPdu.sdu = (Can_SduPtrType) txConfPara.txStructConf->pChipData;
            canPdu.length = CanTxActualDLC(txConfPara.txStructConf);
#if defined(C_ENABLE_EXTENDED_ID)
#if defined(C_ENABLE_MIXED_ID)
            if( CanTxActualIdType(txConfPara.txStructConf) == kCanIdTypeStd)
            {
              canPdu.id = (Can_IdType)CanTxActualStdId(txConfPara.txStructConf);
            }
            else
#endif
            {
              canPdu.id = (Can_IdType)(CanTxActualExtId(txConfPara.txStructConf) | CAN_ID_IDE_MASK);
            }
#else
            canPdu.id = CanTxActualStdId(txConfPara.txStructConf);
#endif
#if defined(C_ENABLE_CAN_FD_USED)
            if( CanTxActualFdType(txConfPara.txStructConf) == kCanFdTypeFd )
            {
              canPdu.id |= (Can_IdType)CAN_ID_FD_MASK;
            }
#endif
            canPdu.id &= CAN_ID_MASK_IN_GENERIC_CALLOUT;
            canPdu.swPduHandle = tmp_pdu;
            Can_SetActiveSendState(txConfPara.activeSendObject, kCanBufferFree);

            generic_retval = Appl_GenericConfirmation( (uint8)channel, &canPdu );
          }
        }

        if(generic_retval == CAN_OK)
#else
        Can_SetActiveSendState(txConfPara.activeSendObject, kCanBufferFree);
#endif
        {
#if defined(C_ENABLE_CANCEL_SUPPORT_API)

          if(tmp_state == kCanBufferCancelSw)
          {
            CanIf_CancelTxNotification(tmp_pdu, FALSE);
          }
          else
#endif
          {
            EcuabCanIf_TxConfirmation(tmp_pdu);
          }
        }
#if(defined(CAN_ENABLE_GENERIC_CONFIRMATION_API1) || defined(CAN_ENABLE_GENERIC_CONFIRMATION_API2)) && (CAN_TRANSMIT_BUFFER == STD_ON)

        else
        {
#if defined(C_ENABLE_CANCEL_SUPPORT_API)
          CanIf_CancelTxNotification( tmp_pdu, FALSE );
#else
#error "When using Generic Confirmation and Transmit buffer (If) the Cancel-support-api (if) has to be activated"
#endif
        }
#endif
      }
#if defined(C_ENABLE_CANCEL_TX_IN_HW)

      else
      {
#if defined(C_ENABLE_CANCEL_SUPPORT_API)
        if(tmp_state == kCanBufferCancelSw)
        {
          Can_SetActiveSendState(txConfPara.activeSendObject, kCanBufferFree);

          CanIf_CancelTxNotification( tmp_pdu, TRUE );
        }
        else
#endif
        {
#if defined(C_ENABLE_CANCEL_IN_HW)

#if(CAN_DEV_ERROR_DETECT == STD_ON)

          if(Can_GetActiveSendState(txConfPara.activeSendObject) == kCanBufferFree)
          {
            errorId = CAN_E_PARAM_HANDLE;
          }
          else
#endif
          {
            SchM_Enter_Can_CAN_EXCLUSIVE_AREA_3();

            Can_SetActiveSendState(txConfPara.activeSendObject, kCanBufferFree);

            CanIf_CancelTxConfirmation( Can_GetActiveSendSwPduHandle(txConfPara.activeSendObject), &Can_GetActiveSendPduInfo(txConfPara.activeSendObject) );
            SchM_Exit_Can_CAN_EXCLUSIVE_AREA_3();
          }
#endif
        }
      }
#endif

      CanLL_TxConfEnd(CAN_CHANNEL_AND_HW_CHANNEL_CANPARA_FIRST &txConfPara);
    }

#if(defined(CAN_USE_CRITICALSECTION_OVER_CONFIRMATION) && (CAN_TRANSMIT_BUFFER == STD_ON)) || defined(CAN_ENABLE_GENERIC_CONFIRMATION_API2)
    SchM_Exit_Can_CAN_EXCLUSIVE_AREA_3();
#endif
  }

#if(CAN_DEV_ERROR_REPORT == STD_ON)
#if !defined(C_ENABLE_TX_POLLING)
  if(errorId != CAN_E_NO_ERROR){
    Can_CallDetReportError(CAN_TXCNF_ID, errorId);
  }
#endif
#endif
  CAN_DUMMY_STATEMENT(errorId);
  CanHookEnd_CanHL_TxConfirmation();
}

#if defined(C_ENABLE_RX_BASICCAN_OBJECTS)
#if defined(C_ENABLE_RX_BASICCAN_POLLING)

V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanHL_BasicCanMsgReceivedPolling( CAN_HW_CHANNEL_CANTYPE_FIRST CanObjectHandle rxMailboxHandle, CanObjectHandle hwObjHandle ){

  Can_DisableControllerInterrupts((uint8)channel);

  CanHL_BasicCanMsgReceived( CAN_HW_CHANNEL_CANPARA_FIRST rxMailboxHandle, hwObjHandle );
  Can_EnableControllerInterrupts((uint8)channel);
}
#endif

V_DEF_FUNC(CAN_STATIC, void, STATIC_CODE) CanHL_BasicCanMsgReceived( CAN_HW_CHANNEL_CANTYPE_FIRST CanObjectHandle rxMailboxHandle, CanObjectHandle hwObjHandle ){

  uint8 errorId;
  tCanRxBasicParaStruct rxBasicPara;
  CanHookBegin_CanHL_BasicCanMsgReceived();
  errorId = CAN_E_NO_ERROR;
  rxBasicPara.mailboxHandle = rxMailboxHandle;
  rxBasicPara.hwObjHandle = hwObjHandle;

#if(CAN_DEV_ERROR_DETECT == STD_ON) && !defined(C_ENABLE_RX_BASICCAN_POLLING)
#if !defined( C_SINGLE_RECEIVE_CHANNEL )

  if(channel >= kCanNumberOfChannels){
    errorId = CAN_E_PARAM_CONTROLLER;
  }
  else
#endif
#endif
  {

    if(CanLL_RxBasicMsgReceivedBegin(CAN_CHANNEL_CANPARA_FIRST &rxBasicPara) == kCanOk){
#if defined(C_ENABLE_CAN_RAM_CHECK)

      if((Can_GetLogStatus(channel) & CAN_DEACTIVATE_CONTROLLER) != CAN_DEACTIVATE_CONTROLLER)
#endif
      {
#if defined(C_ENABLE_OVERRUN)
#if !defined(C_HL_ENABLE_OVERRUN_IN_STATUS)
#endif
#endif

        {

          rxBasicPara.rxStruct.localDlc = CanRxActualDLC((&(rxBasicPara.rxStruct)));

#if defined(C_ENABLE_EXTENDED_ID)
#if defined(C_ENABLE_MIXED_ID)
          if( CanRxActualIdType((&(rxBasicPara.rxStruct))) == kCanIdTypeStd)
          {
            rxBasicPara.rxStruct.localId = (Can_IdType)CanRxActualStdId((&(rxBasicPara.rxStruct)));
          }
          else
#endif
          {
            rxBasicPara.rxStruct.localId = (Can_IdType)(CanRxActualExtId((&(rxBasicPara.rxStruct))) | CAN_ID_IDE_MASK);
          }
          {
#else
          {
            rxBasicPara.rxStruct.localId = CanRxActualStdId((&(rxBasicPara.rxStruct)));
#endif
#if defined(C_ENABLE_CAN_FD_USED)
            if( CanRxActualFdType((&(rxBasicPara.rxStruct))) == kCanFdTypeFd )
            {
              rxBasicPara.rxStruct.localId |= (Can_IdType)CAN_ID_FD_MASK;
            }

            if((CanRxActualFdType((&(rxBasicPara.rxStruct))) != kCanFdTypeFd) && (rxBasicPara.rxStruct.localDlc > 8u))
            {
              errorId = CAN_E_PARAM_DLC;
            }
            else
#endif
#if(CAN_DEV_ERROR_DETECT == STD_ON)
#if(!defined(C_ENABLE_RX_BASICCAN_POLLING) || defined(C_ENABLE_INDIVIDUAL_POLLING))

            if( (rxBasicPara.mailboxHandle < Can_GetRxBasicHandleStart(canHwChannel)) ||
                 (rxBasicPara.mailboxHandle >= Can_GetRxBasicHandleStop(canHwChannel)) )
            {
              errorId = CAN_E_PARAM_HANDLE;
            }
            else
#endif
#endif

            if(rxBasicPara.rxStruct.localDlc > CAN_MAX_DATALEN_OBJ(rxBasicPara.mailboxHandle))
            {
              errorId = CAN_E_PARAM_DLC;
            }
            else
            {

              rxBasicPara.rxStruct.localMailboxHandle = rxBasicPara.mailboxHandle;
              errorId = CanHL_RxMsgReceivedNotification(CAN_CHANNEL_CANPARA_FIRST &(rxBasicPara.rxStruct));
            }
          }
        }
      }
    }

    CanLL_RxBasicReleaseObj(CAN_CHANNEL_CANPARA_FIRST &rxBasicPara);
    CanLL_RxBasicMsgReceivedEnd(CAN_CHANNEL_CANPARA_FIRST &rxBasicPara);
  }

#if(CAN_DEV_ERROR_REPORT == STD_ON)
  if(errorId != CAN_E_NO_ERROR){
    Can_CallDetReportError(CAN_RXINDI_ID, errorId);
  }
#else
  CAN_DUMMY_STATEMENT(errorId);
#endif
  CanHookEnd_CanHL_BasicCanMsgReceived();
}
#endif

#if defined(C_ENABLE_RX_FULLCAN_OBJECTS)
#if defined(C_ENABLE_RX_FULLCAN_POLLING)

V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanHL_FullCanMsgReceivedPolling( CAN_HW_CHANNEL_CANTYPE_FIRST CanObjectHandle rxMailboxHandle, CanObjectHandle hwObjHandle ){

  Can_DisableControllerInterrupts((uint8)channel);

  CanHL_FullCanMsgReceived( CAN_HW_CHANNEL_CANPARA_FIRST rxMailboxHandle, hwObjHandle );
  Can_EnableControllerInterrupts((uint8)channel);
}
#endif

V_DEF_FUNC(CAN_STATIC, void, STATIC_CODE) CanHL_FullCanMsgReceived( CAN_HW_CHANNEL_CANTYPE_FIRST CanObjectHandle rxMailboxHandle, CanObjectHandle hwObjHandle ){

  uint8 errorId;
  tCanRxFullParaStruct rxFullPara;
  CanHookBegin_CanHL_FullCanMsgReceived();
  errorId = CAN_E_NO_ERROR;
  rxFullPara.mailboxHandle = rxMailboxHandle;
  rxFullPara.hwObjHandle = hwObjHandle;

#if(CAN_DEV_ERROR_DETECT == STD_ON)
#if !defined(C_ENABLE_RX_FULLCAN_POLLING)
#if !defined( C_SINGLE_RECEIVE_CHANNEL )

  if(channel >= kCanNumberOfChannels){
    errorId = CAN_E_PARAM_CONTROLLER;
  }
  else
#endif
#endif
#endif
  {

    if(CanLL_RxFullMsgReceivedBegin(CAN_CHANNEL_AND_HW_CHANNEL_CANPARA_FIRST &rxFullPara) == kCanOk){

#if defined(C_ENABLE_CAN_RAM_CHECK)
      if((Can_GetLogStatus(channel) & CAN_DEACTIVATE_CONTROLLER) != CAN_DEACTIVATE_CONTROLLER)
#endif
      {

        {

          rxFullPara.rxStruct.localDlc = CanRxActualDLC((&(rxFullPara.rxStruct)));

#if defined(C_ENABLE_EXTENDED_ID)
#if defined(C_ENABLE_MIXED_ID)
          if( CanRxActualIdType((&(rxFullPara.rxStruct))) == kCanIdTypeStd)
          {
            rxFullPara.rxStruct.localId = (Can_IdType)CanRxActualStdId((&(rxFullPara.rxStruct)));
          }
          else
#endif
          {
            rxFullPara.rxStruct.localId = (Can_IdType)(CanRxActualExtId((&(rxFullPara.rxStruct))) | CAN_ID_IDE_MASK);
          }
#else
          rxFullPara.rxStruct.localId = CanRxActualStdId((&(rxFullPara.rxStruct)));
#endif
          {
#if defined(C_ENABLE_CAN_FD_USED)
            if( CanRxActualFdType((&(rxFullPara.rxStruct))) == kCanFdTypeFd )
            {
              rxFullPara.rxStruct.localId |= (Can_IdType)CAN_ID_FD_MASK;
            }

            if((CanRxActualFdType((&(rxFullPara.rxStruct))) != kCanFdTypeFd) && (rxFullPara.rxStruct.localDlc > 8u))
            {
              errorId = CAN_E_PARAM_DLC;
            }
            else
#endif
#if(CAN_DEV_ERROR_DETECT == STD_ON)
#if(!defined(C_ENABLE_RX_FULLCAN_POLLING) || defined(C_ENABLE_INDIVIDUAL_POLLING))

            if( (rxFullPara.mailboxHandle < Can_GetRxFullHandleStart(canHwChannel)) ||
                 (rxFullPara.mailboxHandle >= Can_GetRxFullHandleStop(canHwChannel)) )
            {
              errorId = CAN_E_PARAM_HANDLE;
            }
            else
#endif
#endif

            if(rxFullPara.rxStruct.localDlc > CAN_MAX_DATALEN_OBJ(rxFullPara.mailboxHandle))
            {
              errorId = CAN_E_PARAM_DLC;
            }
            else
            {

              rxFullPara.rxStruct.localMailboxHandle = rxFullPara.mailboxHandle;
              errorId = CanHL_RxMsgReceivedNotification(CAN_CHANNEL_CANPARA_FIRST &(rxFullPara.rxStruct));
            }
          }
        }
      }
    }

    CanLL_RxFullReleaseObj(CAN_CHANNEL_AND_HW_CHANNEL_CANPARA_FIRST &rxFullPara);
    CanLL_RxFullMsgReceivedEnd(CAN_CHANNEL_AND_HW_CHANNEL_CANPARA_FIRST &rxFullPara);
  }

#if(CAN_DEV_ERROR_REPORT == STD_ON)
  if(errorId != CAN_E_NO_ERROR){
    Can_CallDetReportError(CAN_RXINDI_ID, errorId);
  }
#else
  CAN_DUMMY_STATEMENT(errorId);
#endif
  CanHookEnd_CanHL_FullCanMsgReceived();
}
#endif

V_DEF_FUNC(CAN_STATIC, void, STATIC_CODE) CanHL_ErrorHandling( CAN_HW_CHANNEL_CANTYPE_ONLY ){

  uint8 errorId;
  errorId = CAN_E_NO_ERROR;

#if(CAN_DEV_ERROR_DETECT == STD_ON)
#if !defined(C_ENABLE_ERROR_POLLING)
#if !defined( C_SINGLE_RECEIVE_CHANNEL )

  if(channel >= kCanNumberOfChannels){
    errorId = CAN_E_PARAM_CONTROLLER;
  }
  else
#endif
#endif
#endif
  {

    CanLL_ErrorHandlingBegin(CAN_CHANNEL_AND_HW_CHANNEL_CANPARA_ONLY);
    if( (CanLL_BusOffOccured(CAN_CHANNEL_AND_HW_CHANNEL_CANPARA_ONLY) == kCanTrue) && (!Can_IsIsBusOff(channel) )){

      SchM_Enter_Can_CAN_EXCLUSIVE_AREA_6();

      Can_SetBusOffCounter(channel, 3);
      Can_SetIsBusOff(channel, TRUE);

      (void)CanHL_ModeTransition(CAN_CHANNEL_AND_HW_CHANNEL_CANPARA_FIRST kCanModeResetBusOffStart, kCanContinueBusOffRecovery, kCanSuppressRamCheck);

      Can_SetLogStatus(channel, (uint8)((Can_GetLogStatus(channel) & CAN_STATUS_MASK_NOMODE) | CAN_STATUS_STOP));
      SchM_Exit_Can_CAN_EXCLUSIVE_AREA_6();

      CanIf_ControllerBusOff((uint8)Can_GetCanToCanIfChannelMapping(channel));
    }
#if defined(C_HL_ENABLE_OVERRUN_IN_STATUS)

#if defined(C_ENABLE_OVERRUN) && defined(C_ENABLE_RX_BASICCAN_OBJECTS)

    if(CanLL_RxBasicCanOverrun(CAN_CHANNEL_AND_HW_CHANNEL_CANPARA_ONLY) == kCanTrue){
#if(CAN_OVERRUN_NOTIFICATION == CAN_DET)
      errorId = CAN_E_DATALOST;
#else
      Appl_CanOverrun( (uint8)channel );
#endif
    }
#endif
#endif

    CanLL_ErrorHandlingEnd(CAN_CHANNEL_AND_HW_CHANNEL_CANPARA_ONLY);
  }

#if(CAN_DEV_ERROR_REPORT == STD_ON)
  if(errorId != CAN_E_NO_ERROR){
    Can_CallDetReportError(CAN_CTRBUSOFF_ID, errorId);
  }
#else
  CAN_DUMMY_STATEMENT(errorId);
#endif
}

#if defined(C_ENABLE_SLEEP_WAKEUP)

V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanHL_WakeUpHandling( CAN_CHANNEL_CANTYPE_ONLY ){

#if(CAN_DEV_ERROR_DETECT == STD_ON)
#if !defined(C_ENABLE_WAKEUP_POLLING)
#if !defined( C_SINGLE_RECEIVE_CHANNEL )

  if(channel >= kCanNumberOfChannels){
#     if(CAN_DEV_ERROR_REPORT == STD_ON)

    Can_CallDetReportError(CAN_CTRWAKEUP_ID, CAN_E_PARAM_CONTROLLER);
#     endif
  }
  else
#endif
#endif
#endif
  {

    Can_SetIsWakeup(channel, TRUE);

    EcuM_CheckWakeup(Can_GetWakeupSourceRef(channel));
  }
}
#endif

#define CAN_STOP_SEC_STATIC_CODE
#include "MemMap.hpp"

#define CAN_START_SEC_CODE
#include "MemMap.hpp"

#if(CAN_VERSION_INFO_API == STD_ON)

V_DEF_FUNC(V_NONE, void, CODE) Can_GetVersionInfo( Can_VersionInfoPtrType VersionInfo ){

  uint8 errorId;
  errorId = CAN_E_NO_ERROR;

#if(CAN_DEV_ERROR_DETECT == STD_ON)

  if(VersionInfo == NULL_PTR){
    errorId = CAN_E_PARAM_POINTER;
  }
  else
#endif
  {

    VersionInfo->vendorID   = CAN_VENDOR_ID;
    VersionInfo->moduleID   = CAN_MODULE_ID;
    VersionInfo->sw_major_version = (uint8)CAN_SW_MAJOR_VERSION;
    VersionInfo->sw_minor_version = (uint8)CAN_SW_MINOR_VERSION;
    VersionInfo->sw_patch_version = (uint8)CAN_SW_PATCH_VERSION;
  }

#if(CAN_DEV_ERROR_REPORT == STD_ON)
  if(errorId != CAN_E_NO_ERROR){
    Can_CallDetReportError(CAN_VERSION_ID, errorId);
  }
#else
  CAN_DUMMY_STATEMENT(errorId);
#endif
}
#endif

V_DEF_FUNC(V_NONE, void, CODE) Can_InitMemory(void){

  canConfigInitFlag = CAN_STATUS_UNINIT;
#if defined(CAN_ENABLE_USE_INIT_ROOT_POINTER)

  Can_ConfigDataPtr = NULL_PTR;
#endif

  CanLL_InitMemoryPowerOn();
#if(CAN_DEV_ERROR_DETECT == STD_OFF)
  CAN_DUMMY_STATEMENT(canConfigInitFlag);
#endif
}

#if((CAN_CHANGE_BAUDRATE_API == STD_ON) || (CAN_SET_BAUDRATE_API == STD_OFF))

V_DEF_FUNC(V_NONE, Std_ReturnType, CODE) Can_ChangeBaudrate( uint8 Controller, V_DEF_CONST(V_NONE, uint16, APPL_CONST) Baudrate ){

  Std_ReturnType retval;
  uint8 errorId;
  retval = E_NOT_OK;
  errorId = CAN_E_PARAM_BAUDRATE;

#if(CAN_DEV_ERROR_DETECT == STD_ON)

  if( canConfigInitFlag == CAN_STATUS_UNINIT ){
    errorId = CAN_E_UNINIT;
  }
  else
#if !defined( C_SINGLE_RECEIVE_CHANNEL )
  if( channel >= kCanNumberOfChannels ){
    errorId = CAN_E_PARAM_CONTROLLER;
  }
  else
#endif
  if( (Can_GetLogStatus(channel) & CAN_STATUS_STOP) != CAN_STATUS_STOP ){
    errorId = CAN_E_TRANSITION;
  }
  else
#endif
  {

    uint8_least baudrateIndex;
    for(baudrateIndex = Can_GetInitObjectStartIndex(channel); baudrateIndex < Can_GetInitObjectStartIndex(channel + 1u); baudrateIndex++){
      if(Can_GetInitObjectBaudrate(baudrateIndex) == Baudrate)
      {
        uint8 transitionState;
        Can_SetLastInitObject(channel, (uint8)baudrateIndex);
        transitionState = CanHL_ModeTransition(CAN_CHANNEL_CANPARA_FIRST kCanModeStopReinit, kCanFinishBusOffRecovery, kCanSuppressRamCheck);
        if(transitionState == kCanOk)
        {
          Can_SetLogStatus(channel, Can_GetLogStatus(channel) | CAN_STATUS_STOP);
        }
        retval = E_OK;
        errorId = CAN_E_NO_ERROR;
        break;
      }
    }
  }

#if(CAN_DEV_ERROR_REPORT == STD_ON)
  if(errorId != CAN_E_NO_ERROR){
    Can_CallDetReportError(CAN_CHANGE_BR_ID, errorId);
  }
#else
  CAN_DUMMY_STATEMENT(errorId);
#endif
#if defined( C_SINGLE_RECEIVE_CHANNEL )
  CAN_DUMMY_STATEMENT(Controller);
#endif
  return retval;
}
#endif

#if(CAN_CHANGE_BAUDRATE_API == STD_ON)

V_DEF_FUNC(V_NONE, Std_ReturnType, CODE) Can_CheckBaudrate( uint8 Controller, V_DEF_CONST(V_NONE, uint16, APPL_CONST) Baudrate ){

  Std_ReturnType retval;
  uint8 errorId;
  retval = E_NOT_OK;
  errorId = CAN_E_PARAM_BAUDRATE;

#if(CAN_DEV_ERROR_DETECT == STD_ON)

  if( canConfigInitFlag == CAN_STATUS_UNINIT ){
    errorId = CAN_E_UNINIT;
  }
  else
#if !defined( C_SINGLE_RECEIVE_CHANNEL )
  if( channel >= kCanNumberOfChannels ){
    errorId = CAN_E_PARAM_CONTROLLER;
  }
  else
#endif
#endif
  {

    uint8_least baudrateIndex;
    for(baudrateIndex = Can_GetInitObjectStartIndex(channel); baudrateIndex < Can_GetInitObjectStartIndex(channel + 1u); baudrateIndex++){
      if(Can_GetInitObjectBaudrate(baudrateIndex) == Baudrate)
      {
        retval = E_OK;
        errorId = CAN_E_NO_ERROR;
        break;
      }
    }
  }

#if(CAN_DEV_ERROR_REPORT == STD_ON)
  if(errorId != CAN_E_NO_ERROR){
    Can_CallDetReportError(CAN_CHECK_BR_ID, errorId);
  }
#else
  CAN_DUMMY_STATEMENT(errorId);
#endif
#if defined( C_SINGLE_RECEIVE_CHANNEL )
  CAN_DUMMY_STATEMENT(Controller);
#endif
  return retval;
}
#endif

#if(CAN_SET_BAUDRATE_API == STD_ON)

V_DEF_FUNC(V_NONE, Std_ReturnType, CODE) Can_SetBaudrate( uint8 Controller, uint16 BaudRateConfigID ){

  Std_ReturnType retval;
  uint8 errorId;

  retval = E_NOT_OK;
  errorId = CAN_E_NO_ERROR;

#if(CAN_DEV_ERROR_DETECT == STD_ON)

  if( canConfigInitFlag == CAN_STATUS_UNINIT ){
    errorId = CAN_E_UNINIT;
  }
  else
#if !defined( C_SINGLE_RECEIVE_CHANNEL )
  if( channel >= kCanNumberOfChannels ){
    errorId = CAN_E_PARAM_CONTROLLER;
  }
  else
#endif
  if( (Can_GetLogStatus(channel) & CAN_STATUS_STOP) != CAN_STATUS_STOP ){
    errorId = CAN_E_TRANSITION;
  }
  else
  if( BaudRateConfigID >= (uint16)(Can_GetInitObjectStartIndex(channel + 1u) - Can_GetInitObjectStartIndex(channel)) ){
    errorId = CAN_E_PARAM_BAUDRATE;
  }
  else
#endif
  {
    uint8 transitionState;

    Can_SetLastInitObject(channel, (uint8)(Can_GetInitObjectStartIndex(channel) + BaudRateConfigID));
    transitionState = CanHL_ModeTransition(CAN_CHANNEL_CANPARA_FIRST kCanModeStopReinit, kCanFinishBusOffRecovery, kCanSuppressRamCheck);

    if(transitionState == kCanOk){
      retval = E_OK;
      Can_SetLogStatus(channel, Can_GetLogStatus(channel) | CAN_STATUS_STOP);
    }
  }

#if(CAN_DEV_ERROR_REPORT == STD_ON)
  if(errorId != CAN_E_NO_ERROR){
    Can_CallDetReportError(CAN_SET_BR_ID, errorId);
  }
#else
  CAN_DUMMY_STATEMENT(errorId);
#endif
#if defined( C_SINGLE_RECEIVE_CHANNEL )
  CAN_DUMMY_STATEMENT(Controller);
#endif
  return retval;
}
#endif

V_DEF_FUNC(V_NONE, void, CODE) Can_Init( Can_ConfigPtrType ConfigPtr ){

  uint8 errorId;
  CAN_CHANNEL_CANTYPE_LOCAL
  CanHookBegin_Can_Init();
  errorId = CAN_E_NO_ERROR;
#if defined(CAN_ENABLE_USE_INIT_ROOT_POINTER)
  Can_ConfigDataPtr = ConfigPtr;
#if defined(CAN_ENABLE_USE_ECUM_BSW_ERROR_HOOK)
  if(ConfigPtr == NULL_PTR){
    EcuM_BswErrorHook((uint16) CAN_MODULE_ID, (uint8) ECUM_BSWERROR_NULLPTR);
  }
  else
#if(CAN_FINALMAGICNUMBER == STD_ON)
  if(Can_GetFinalMagicNumber() != 20510u){
    EcuM_BswErrorHook((uint16) CAN_MODULE_ID, (uint8) ECUM_BSWERROR_MAGICNUMBER);
  }
  else
#endif
#else

#if(CAN_DEV_ERROR_DETECT == STD_ON)

  if(ConfigPtr == NULL_PTR){
    errorId = CAN_E_PARAM_POINTER;
  }
  else
#endif
#endif
#else
  CAN_DUMMY_STATEMENT(ConfigPtr);
#if defined(V_ENABLE_USE_DUMMY_STATEMENT)
  ConfigPtr = Can_ConfigDataPtr;
#endif
#endif
#if(CAN_DEV_ERROR_DETECT == STD_ON)
  if(canConfigInitFlag != CAN_STATUS_UNINIT){

    errorId = CAN_E_TRANSITION;
  }
  else
#endif
  if(  ( Can_GetBaseDll_GeneratorVersion()     != (uint16)CAN_GEN_BASE_CFG5_VERSION ) ||
        ( Can_GetPlatformDll_GeneratorVersion() != (uint16)CAN_GEN_SH2RSCANASR_VERSION ) ){

#if defined(CAN_ENABLE_USE_ECUM_BSW_ERROR_HOOK)
    EcuM_BswErrorHook((uint16) CAN_MODULE_ID, (uint8) ECUM_BSWERROR_COMPATIBILITYVERSION);
#else
    errorId = CAN_E_UNINIT;
#endif
  }
  else{

    {
      canIsRxTaskLocked = kCanFalse;
#if defined(C_ENABLE_RX_QUEUE)

      Can_GetRxQueueInfo().WriteIndex = 0u;
      Can_GetRxQueueInfo().ReadIndex = 0u;
      Can_GetRxQueueInfo().Count = 0u;
      canRxQueueMaxDataSize = (uint16) (sizeof(Can_GetRxQueueBuffer(0).data) / sizeof(Can_GetRxQueueBuffer(0).data[0]));
#endif

      if(CanLL_InitPowerOn() == kCanOk)
      {
        canConfigInitFlag = CAN_STATUS_INIT;
#if !defined( C_SINGLE_RECEIVE_CHANNEL )
        for(channel = 0u; channel < kCanNumberOfChannels; channel++)
#endif
        {
#if(CAN_POSTBUILD_VARIANT_SUPPORT == STD_ON)
          if( Can_GetCanIfChannelId(channel) == kCanChannelNotUsed )
          {
            continue;
          }
#endif

          Can_SetLogStatus(channel, CAN_STATUS_UNINIT);
          Can_SetModeTransitionRequest(channel, kCanModeNone);
          Can_SetBusOffTransitionRequest(channel, kCanFinishBusOffRecovery);
          Can_SetRamCheckTransitionRequest(channel, kCanSuppressRamCheck);
          Can_SetBusOffCounter(channel, 0u);
          Can_SetIsBusOff(channel, FALSE);
#if defined(C_ENABLE_SLEEP_WAKEUP)
          Can_SetIsWakeup(channel, FALSE);
#endif
          Can_SetCanInterruptCounter(channel, 0u);
#if defined(C_ENABLE_MIRROR_MODE)
          Can_SetMirrorModeState(channel, CDDMIRROR_INACTIVE);
#endif
#if defined(C_ENABLE_SILENT_MODE)
          Can_SetSilentModeState(channel, CAN_SILENT_INACTIVE);
#endif

          if(CanLL_InitPowerOnChannelSpecific(CAN_CHANNEL_CANPARA_ONLY) == kCanOk)
          {
            uint8 transitionState;

            Can_SetLastInitObject(channel, (uint8)(Can_GetInitObjectStartIndex(channel) + Can_GetCanControllerDefaultBaudrateIdx(CAN_HL_HW_CHANNEL_STARTINDEX(channel))));
            transitionState = CanHL_ModeTransition(CAN_CHANNEL_CANPARA_FIRST kCanModeStopReinit, kCanFinishBusOffRecovery, kCanExecuteRamCheck);
            if(transitionState == kCanOk)
            {
              Can_SetLogStatus(channel, Can_GetLogStatus(channel) | CAN_STATUS_STOP);
            }
#if(CAN_DEV_ERROR_DETECT == STD_ON)
            else
            {
              errorId = CAN_E_TRANSITION;
            }
#endif
          }
        }
      }
    }
  }

#if(CAN_DEV_ERROR_REPORT == STD_ON)
  if(errorId != CAN_E_NO_ERROR){
    Can_CallDetReportError(CAN_INIT_ID, errorId);
  }
#else
  CAN_DUMMY_STATEMENT(errorId);
#endif
  CanHookEnd_Can_Init();
}

V_DEF_FUNC(V_NONE, Can_ReturnType, CODE) Can_SetControllerMode( uint8 Controller, Can_StateTransitionType Transition ){

  uint8 errorId;
  Can_ReturnType retval;
  uint8 transitionRequest;
  uint8 busOffRecovery;
  uint8 doRamCheck;
  uint8 transitionState;
  CanHookBegin_Can_SetControllerMode();
  retval = CAN_NOT_OK;
  transitionState = kCanFailed;
  errorId = CAN_E_NO_ERROR;

#if(CAN_DEV_ERROR_DETECT == STD_ON)

  if(canConfigInitFlag == CAN_STATUS_UNINIT){
    errorId = CAN_E_UNINIT;
  }
  else
#if !defined( C_SINGLE_RECEIVE_CHANNEL )
  if(channel >= kCanNumberOfChannels){
    errorId = CAN_E_PARAM_CONTROLLER;
  }
  else
#endif
#if(CAN_POSTBUILD_VARIANT_SUPPORT == STD_ON)
  if(Can_GetCanIfChannelId(channel) == kCanChannelNotUsed){
    errorId = CAN_E_PARAM_CONTROLLER;
  }
  else
#endif
#endif
  {
#if(CAN_DEV_ERROR_DETECT == STD_ON)
    if(!CanHL_IsControllerInit(channel)){
      errorId = CAN_E_UNINIT;
    }
    else
    if((!CanHL_IsStop(channel)) && (Transition == CAN_T_START)){
      errorId = CAN_E_TRANSITION;
    }
    else
#if(CAN_TRANSITION_CHECK == STD_ON)
    if( ((!CanHL_IsStop(channel)) && (!CanHL_IsSleep(channel)) && ((Transition == CAN_T_WAKEUP) || (Transition == CAN_T_SLEEP))) ||
         ((CanHL_IsSleep(channel)) && (Transition == CAN_T_STOP)) ){

      errorId = CAN_E_TRANSITION;
    }
    else
#endif
#endif
#if defined(C_ENABLE_CAN_RAM_CHECK_EXTENDED)

    if((Can_GetLogStatus(channel) & CAN_DEACTIVATE_CONTROLLER) != CAN_DEACTIVATE_CONTROLLER)
#endif
    {

      SchM_Enter_Can_CAN_EXCLUSIVE_AREA_6();

      switch(Transition)
      {
      case CAN_T_START:

        if(Can_IsIsBusOff(channel))
        {
          transitionRequest = kCanModeResetBusOffEnd;
        }
        else
        {
#if defined(C_ENABLE_SILENT_MODE)
          if(Can_GetSilentModeState(channel) == CAN_SILENT_ACTIVE)
          {
            transitionRequest = kCanModeSilent;
          }
          else
#endif
          {
#if(CAN_REINIT_START == STD_ON)
            transitionRequest = kCanModeStartReinit;
#else
            transitionRequest = kCanModeStart;
#endif
          }
        }
        busOffRecovery = kCanContinueBusOffRecovery;
        doRamCheck = kCanSuppressRamCheck;
        transitionState = CanHL_ModeTransition(CAN_CHANNEL_CANPARA_FIRST transitionRequest, busOffRecovery, doRamCheck);
        if( transitionState == kCanOk )
        {
          Can_SetIsBusOff(channel, FALSE);
        }
        CanHL_NotifyTransition(CAN_CHANNEL_CANPARA_FIRST CAN_STATUS_START, CANIF_CS_STARTED, transitionState);
        break;

      case CAN_T_STOP:

        transitionRequest = kCanModeStopReinitFast;
        if(Can_GetBusOffCounter(channel) == 0u)
        {
          busOffRecovery = kCanFinishBusOffRecovery;
        }
        else
        {
          Can_DecBusOffCounter(channel);
          busOffRecovery = kCanContinueBusOffRecovery;
        }
        doRamCheck = kCanSuppressRamCheck;
        transitionState = CanHL_ModeTransition(CAN_CHANNEL_CANPARA_FIRST transitionRequest, busOffRecovery, doRamCheck);
        CanHL_NotifyTransition(CAN_CHANNEL_CANPARA_FIRST CAN_STATUS_STOP, CANIF_CS_STOPPED, transitionState);
        break;

      case CAN_T_WAKEUP:

#if defined(C_ENABLE_SLEEP_WAKEUP)
        if( (Can_GetModeTransitionRequest(channel) & kCanModeSleep) == kCanModeSleep )
        {
          errorId = CAN_E_TRANSITION;
          break;
        }
#endif
#if defined(C_ENABLE_CAN_RAM_CHECK) && !defined(C_ENABLE_CAN_RAM_CHECK_EXTENDED)
        if(!CanHL_IsStop(channel)) {

          transitionRequest = kCanModeStopReinit;
          doRamCheck = kCanExecuteRamCheck;
        }
        else
#endif
        {
          transitionRequest = kCanModeStopReinitFast;
          doRamCheck = kCanSuppressRamCheck;
        }
#if defined(C_ENABLE_SLEEP_WAKEUP)
        if(Can_GetWakeupSourceRef(channel) != 0u)
        {
          transitionRequest = kCanModeWakeupStopReinit;
          busOffRecovery = kCanFinishBusOffRecovery;
        }
        else
#endif
        {
          busOffRecovery = kCanFinishBusOffRecovery;
        }
        transitionState = CanHL_ModeTransition(CAN_CHANNEL_CANPARA_FIRST transitionRequest, busOffRecovery, doRamCheck);
        CanHL_NotifyTransition(CAN_CHANNEL_CANPARA_FIRST CAN_STATUS_STOP, CANIF_CS_STOPPED, transitionState);
        break;

      case CAN_T_SLEEP:

#if defined(C_ENABLE_SLEEP_WAKEUP)

        if(Can_GetWakeupSourceRef(channel) != 0u)
        {
          transitionRequest = kCanModeSleep;
          busOffRecovery = kCanFinishBusOffRecovery;
          doRamCheck = kCanSuppressRamCheck;
          transitionState = CanHL_ModeTransition(CAN_CHANNEL_CANPARA_FIRST transitionRequest, busOffRecovery, doRamCheck);
        }
        else
#endif
        {
          transitionState = kCanOk;
        }
        CanHL_NotifyTransition(CAN_CHANNEL_CANPARA_FIRST CAN_STATUS_SLEEP, CANIF_CS_SLEEP, transitionState);
        break;

      default:

        errorId = CAN_E_TRANSITION;
        break;
      }
      SchM_Exit_Can_CAN_EXCLUSIVE_AREA_6();
    }
  }
  if( transitionState != kCanFailed ){
    retval = CAN_OK;
  }

#if(CAN_DEV_ERROR_REPORT == STD_ON)
  if(errorId != CAN_E_NO_ERROR){
    Can_CallDetReportError(CAN_SETCTR_ID, errorId);
  }
#else
  CAN_DUMMY_STATEMENT(errorId);
#endif
#if defined( C_SINGLE_RECEIVE_CHANNEL )
  CAN_DUMMY_STATEMENT(Controller);
#endif
  CanHookEnd_Can_SetControllerMode();
  return retval;
}

V_DEF_FUNC(V_NONE, void, CODE) Can_DisableControllerInterrupts( uint8 Controller ){

  uint8 errorId;
  errorId = CAN_E_NO_ERROR;

#if(CAN_DEV_ERROR_DETECT == STD_ON)

  if(canConfigInitFlag == CAN_STATUS_UNINIT){
    errorId = CAN_E_UNINIT;
  }
  else
#if !defined( C_SINGLE_RECEIVE_CHANNEL )
  if(channel >= kCanNumberOfChannels){
    errorId = CAN_E_PARAM_CONTROLLER;
  }
  else
#endif
#if(CAN_POSTBUILD_VARIANT_SUPPORT == STD_ON)
  if(Can_GetCanIfChannelId(channel) == kCanChannelNotUsed){
    errorId = CAN_E_PARAM_CONTROLLER;
  }
  else
#endif
  if(!CanHL_IsControllerInit(channel)){
    errorId = CAN_E_UNINIT;
  }
  else
#endif
  {

    SchM_Enter_Can_CAN_EXCLUSIVE_AREA_1();
    if(Can_GetCanInterruptCounter(channel) == 0u){
#if(CAN_INTLOCK == CAN_DRIVER) || (CAN_INTLOCK == CAN_BOTH)
      {
        CanLL_CanInterruptDisable(CAN_CHANNEL_CANPARA_FIRST  &Can_GetCanInterruptOldStatus(canHwChannel));
      }
#endif
#if(CAN_INTLOCK == CAN_APPL) || (CAN_INTLOCK == CAN_BOTH)

      ApplCanInterruptDisable((uint8)channel);
#endif
    }
    Can_SetCanInterruptCounter(channel, Can_GetCanInterruptCounter(channel) + 1u);
    SchM_Exit_Can_CAN_EXCLUSIVE_AREA_1();
  }

#if(CAN_DEV_ERROR_REPORT == STD_ON)
  if(errorId != CAN_E_NO_ERROR){
    Can_CallDetReportError(CAN_DIINT_ID, errorId);
  }
#else
  CAN_DUMMY_STATEMENT(errorId);
#endif
#if defined( C_SINGLE_RECEIVE_CHANNEL )
  CAN_DUMMY_STATEMENT(Controller);
#endif
}

V_DEF_FUNC(V_NONE, void, CODE) Can_EnableControllerInterrupts( uint8 Controller ){

  uint8 errorId;
  errorId = CAN_E_NO_ERROR;

#if(CAN_DEV_ERROR_DETECT == STD_ON)

  if(canConfigInitFlag == CAN_STATUS_UNINIT){
    errorId = CAN_E_UNINIT;
  }
  else
#if !defined( C_SINGLE_RECEIVE_CHANNEL )
  if(channel >= kCanNumberOfChannels){
    errorId = CAN_E_PARAM_CONTROLLER;
  }
  else
#endif
#if(CAN_POSTBUILD_VARIANT_SUPPORT == STD_ON)
  if(Can_GetCanIfChannelId(channel) == kCanChannelNotUsed){
    errorId = CAN_E_PARAM_CONTROLLER;
  }
  else
#endif
  if(!CanHL_IsControllerInit(channel)){
    errorId = CAN_E_UNINIT;
  }
  else
#endif
  {

    SchM_Enter_Can_CAN_EXCLUSIVE_AREA_1();
    if(Can_GetCanInterruptCounter(channel) != 0u){
      Can_SetCanInterruptCounter(channel, Can_GetCanInterruptCounter(channel)-1u);
      if(Can_GetCanInterruptCounter(channel) == 0u)
      {
#if(CAN_INTLOCK == CAN_DRIVER) || (CAN_INTLOCK == CAN_BOTH)
        {
          CanLL_CanInterruptRestore(CAN_CHANNEL_CANPARA_FIRST Can_GetCanInterruptOldStatus(canHwChannel));
        }
#endif
#if(CAN_INTLOCK == CAN_APPL) || (CAN_INTLOCK == CAN_BOTH)

        ApplCanInterruptRestore((uint8)channel);
#endif
      }
    }
    SchM_Exit_Can_CAN_EXCLUSIVE_AREA_1();
  }

#if(CAN_DEV_ERROR_REPORT == STD_ON)
  if(errorId != CAN_E_NO_ERROR){
    Can_CallDetReportError(CAN_ENINT_ID, errorId);
  }
#else
  CAN_DUMMY_STATEMENT(errorId);
#endif
#if defined( C_SINGLE_RECEIVE_CHANNEL )
  CAN_DUMMY_STATEMENT(Controller);
#endif
}

V_DEF_FUNC(V_NONE, Can_ReturnType, CODE) Can_Write(
   Can_HwHandleType Hth, Can_PduInfoPtrType PduInfo
){
   Can_ReturnType retval;
   CAN_CHANNEL_CANTYPE_LOCAL
   uint8 errorId;
   CanHookBegin_Can_Write();
   errorId = CAN_E_NO_ERROR;
   retval = CAN_NOT_OK;
#if(CAN_DEV_ERROR_DETECT == STD_ON)
   if(canConfigInitFlag == CAN_STATUS_UNINIT){
      errorId = CAN_E_UNINIT;
   }
   else if(Hth >= Can_GetSizeOfMailbox()
   ){
      errorId = CAN_E_PARAM_HANDLE;
   }
   else
#endif
  {
#if !defined( C_SINGLE_RECEIVE_CHANNEL )
    channel = Can_GetMailboxController(Hth);
#endif
#if(CAN_DEV_ERROR_DETECT == STD_ON)
#if !defined( C_SINGLE_RECEIVE_CHANNEL )
    if(channel >= kCanNumberOfChannels){
      errorId = CAN_E_PARAM_HANDLE;
    }
    else
#endif
#if(CAN_POSTBUILD_VARIANT_SUPPORT == STD_ON)
    if(Can_GetCanIfChannelId(channel) == kCanChannelNotUsed){
      errorId = CAN_E_PARAM_HANDLE;
    }
    else
#endif
    if(!CanHL_IsControllerInit(channel)){
      errorId = CAN_E_UNINIT;
    }
    else
#if defined(C_ENABLE_TX_FULLCAN_OBJECTS)
    if((Can_GetMailboxType(Hth) != CAN_TX_BASICCAN_TYPE) && (Can_GetMailboxType(Hth) != CAN_TX_BASICCAN_MUX_TYPE) && (Can_GetMailboxType(Hth) != CAN_TX_BASICCAN_FIFO_TYPE) && (Can_GetMailboxType(Hth) != CAN_TX_FULLCAN_TYPE))
#else
    if((Can_GetMailboxType(Hth) != CAN_TX_BASICCAN_TYPE) && (Can_GetMailboxType(Hth) != CAN_TX_BASICCAN_MUX_TYPE) && (Can_GetMailboxType(Hth) != CAN_TX_BASICCAN_FIFO_TYPE))
#endif
    {
      errorId = CAN_E_PARAM_HANDLE;
    }
    else
    if((PduInfo == NULL_PTR) || ((PduInfo->sdu == NULL_PTR) && (PduInfo->length != 0u))){
      errorId = CAN_E_PARAM_POINTER;
    }
    else
#if !defined(C_ENABLE_CAN_FD_USED)
    if( CanHL_IsFdMessage(PduInfo->id) ){
      errorId = CAN_E_PARAM_POINTER;
    }
    else
#endif
#if defined(C_ENABLE_CAN_FD_FULL)
    if( ((PduInfo->length > 8u) && (Can_GetInitObjectFdBrsConfig(Can_GetLastInitObject(channel)) == CAN_NONE)) ||
         (PduInfo->length > CAN_MAX_DATALEN_OBJ(Hth)) )
         {

      errorId = CAN_E_PARAM_DLC;
    }
    else
#else
   if(
         PduInfo->length
      >  CAN_MAX_DATALEN_OBJ(Hth)
   ){
      errorId = CAN_E_PARAM_DLC;
   }
    else
#endif
#if defined(C_ENABLE_MIXED_ID)
    if( ((PduInfo->id & (Can_IdType)CAN_ID_IDE_MASK) != (Can_IdType)CAN_ID_IDE_MASK ) && ( (PduInfo->id & (Can_IdType)CAN_ID_MASK) > (Can_IdType)CAN_ID_MASK_STD ) ){
      errorId = CAN_E_PARAM_POINTER;
    }
    else
#endif
    if( (PduInfo->id & (Can_IdType)CAN_ID_UNUSED_MASK) != (Can_IdType)0UL ){
      errorId = CAN_E_PARAM_POINTER;
    }
    else
#endif

#if defined(C_ENABLE_CAN_RAM_CHECK)

    if(Can_GetMailboxState(Hth) == kCanFailed){
      retval = CAN_NOT_OK;
    }
    else
#endif

    if(Can_IsIsBusOff(channel)){
      retval = CAN_NOT_OK;
    }
    else
#if defined(C_ENABLE_CAN_RAM_CHECK)

    if((Can_GetLogStatus(channel) & CAN_DEACTIVATE_CONTROLLER) != CAN_DEACTIVATE_CONTROLLER)
#endif
    {

      tCanTxTransmissionParaStruct txPara;

#if !defined(CAN_USE_VECTOR_IF)
      SchM_Enter_Can_CAN_EXCLUSIVE_AREA_2();
#endif
      txPara.mailboxHandle = Hth;
      txPara.hwObjHandle = Can_GetMailboxHwHandle(Hth);
      txPara.pdu.id = PduInfo->id;
      txPara.pdu.length = PduInfo->length;
      txPara.pdu.sdu = PduInfo->sdu;
      txPara.pdu.swPduHandle = PduInfo->swPduHandle;
#if defined(C_ENABLE_CAN_FD_USED)
      if(txPara.pdu.length <= 8u)
      {
        if(Can_GetInitObjectFdBrsConfig(Can_GetLastInitObject(channel)) == CAN_NONE)
        {

          txPara.pdu.id = txPara.pdu.id & ((Can_IdType)(CAN_ID_IDE_MASK | CAN_ID_MASK));
        }
      }
      txPara.fdBrsType = kCanFdBrsTypeFalse;
      if(CanHL_IsFdMessage(txPara.pdu.id))
      {
        txPara.fdType = kCanFdTypeFd;
        if(CanHL_IsFdTxBrs(channel))
        {
          txPara.fdBrsType = kCanFdBrsTypeTrue;
        }
      } else {
        txPara.fdType = kCanFdTypeClassic;
      }
      txPara.messageLen = txPara.pdu.length;
      txPara.frameLen = CAN_DLC2LEN(CAN_LEN2DLC(txPara.messageLen));
#if defined(C_ENABLE_CAN_FD_FULL)
      txPara.paddingVal = Can_GetMailboxFdPadding(txPara.mailboxHandle);
#endif
#endif

      CanHL_WritePrepare(CAN_CHANNEL_CANPARA_FIRST &txPara);

      retval = CanHL_WriteStart(CAN_CHANNEL_CANPARA_FIRST &txPara);

#if !defined(CAN_USE_VECTOR_IF)

      SchM_Exit_Can_CAN_EXCLUSIVE_AREA_2();
#endif
    }
  }

#if(CAN_DEV_ERROR_REPORT == STD_ON)
  if(errorId != CAN_E_NO_ERROR){
    Can_CallDetReportError(CAN_WRITE_ID, errorId);
  }
#else
  CAN_DUMMY_STATEMENT(errorId);
#endif
  CanHookEnd_Can_Write();
  return retval;
}

#if defined(C_ENABLE_CHECK_WAKEUP_CAN_RET_TYPE)
#define CAN_CHECKWAKEUP_RETTYPE Can_ReturnType
#define CAN_CHECKWAKEUP_RETVAL_OK     CAN_OK
#define CAN_CHECKWAKEUP_RETVAL_NOT_OK CAN_NOT_OK
V_DEF_FUNC(V_NONE, Can_ReturnType, CODE) Can_CheckWakeup( uint8 Controller )
#else
#define CAN_CHECKWAKEUP_RETTYPE Std_ReturnType
#define CAN_CHECKWAKEUP_RETVAL_OK     E_OK
#define CAN_CHECKWAKEUP_RETVAL_NOT_OK E_NOT_OK
V_DEF_FUNC(V_NONE, Std_ReturnType, CODE) Can_CheckWakeup( uint8 Controller )
#endif
{

  CAN_CHECKWAKEUP_RETTYPE retval;
  retval = CAN_CHECKWAKEUP_RETVAL_NOT_OK;
#if defined(C_ENABLE_SLEEP_WAKEUP)
  {
    uint8 errorId;
    errorId = CAN_E_NO_ERROR;

#if(CAN_DEV_ERROR_DETECT == STD_ON)

    if(canConfigInitFlag == CAN_STATUS_UNINIT){
      errorId = CAN_E_UNINIT;
    }
    else
#if !defined( C_SINGLE_RECEIVE_CHANNEL )
    if(channel >= kCanNumberOfChannels){
      errorId = CAN_E_PARAM_CONTROLLER;
    }
    else
#endif
#if(CAN_POSTBUILD_VARIANT_SUPPORT == STD_ON)
    if(Can_GetCanIfChannelId(channel) == kCanChannelNotUsed){
      errorId = CAN_E_PARAM_CONTROLLER;
    }
    else
#endif
    if(!CanHL_IsControllerInit(channel)){
      errorId = CAN_E_UNINIT;
    }
    else
#endif
    {

     if(Can_IsIsWakeup(channel))
      {
        Can_SetIsWakeup(channel, FALSE);

        EcuM_SetWakeupEvent(Can_GetWakeupSourceRef(channel));
        retval = CAN_CHECKWAKEUP_RETVAL_OK;
      }
    }

#if(CAN_DEV_ERROR_REPORT == STD_ON)
    if(errorId != CAN_E_NO_ERROR){
      Can_CallDetReportError(CAN_CKWAKEUP_ID, errorId);
    }
#else
    CAN_DUMMY_STATEMENT(errorId);
#endif
#if defined( C_SINGLE_RECEIVE_CHANNEL )
    CAN_DUMMY_STATEMENT(Controller);
#endif
  }
#else
  CAN_DUMMY_STATEMENT(Controller);
#endif
  return retval;
}

V_DEF_FUNC(V_NONE, void, CODE) Can_MainFunction_Write(void){

#if defined(C_ENABLE_TX_POLLING)
  CAN_CHANNEL_CANTYPE_LOCAL
  uint8 errorId;
  errorId = CAN_E_NO_ERROR;
  CanHookBegin_Can_MainFunction_Write();

#if(CAN_DEV_ERROR_DETECT == STD_ON)
  if(canConfigInitFlag == CAN_STATUS_UNINIT){
    errorId = CAN_E_UNINIT;
  }
  else
#endif
  {

#if !defined( C_SINGLE_RECEIVE_CHANNEL )
    for(channel = 0u; channel < kCanNumberOfChannels; channel++)
#endif
    {
#if(CAN_POSTBUILD_VARIANT_SUPPORT == STD_ON)
      if( Can_GetCanIfChannelId(channel) == kCanChannelNotUsed )
      {
        continue;
      }
#endif
#if(CAN_DEV_ERROR_DETECT == STD_ON)
      if(!CanHL_IsControllerInit(channel))
      {
        errorId = CAN_E_UNINIT;
      }
      else
#endif
      {
        if( !CanHL_IsSleep(channel) )
        {
          tCanTaskParaStruct taskPara;
#if defined(C_ENABLE_TX_POLLING)

          if( CanLL_TxIsGlobalConfPending(CAN_CHANNEL_AND_HW_CHANNEL_CANPARA_ONLY) == kCanTrue )
          {
            for( taskPara.mailboxHandle = Can_GetTxBasicHandleStart(canHwChannel); taskPara.mailboxHandle < Can_GetTxBasicHandleStop(canHwChannel); taskPara.mailboxHandle++ )
            {
              taskPara.hwObjHandle = Can_GetMailboxHwHandle(taskPara.mailboxHandle);
#if defined(C_ENABLE_INDIVIDUAL_POLLING)
              if( Can_IsMailboxIndivPolling(taskPara.mailboxHandle))
#endif
              {

                CanLL_TxProcessPendings(CAN_CHANNEL_AND_HW_CHANNEL_CANPARA_FIRST &taskPara);
              }
            }
          }
#endif
#if defined(C_ENABLE_CANCEL_TX_IN_HW)
#endif
#if defined(C_ENABLE_TX_FULLCAN_OBJECTS)
#if defined(C_ENABLE_TX_POLLING)

          if( CanLL_TxIsGlobalConfPending(CAN_CHANNEL_AND_HW_CHANNEL_CANPARA_ONLY) == kCanTrue )
          {
            for( taskPara.mailboxHandle = Can_GetTxFullHandleStart(canHwChannel); taskPara.mailboxHandle < Can_GetTxFullHandleStop(canHwChannel); taskPara.mailboxHandle++ )
            {
              taskPara.hwObjHandle = Can_GetMailboxHwHandle(taskPara.mailboxHandle);
#if defined(C_ENABLE_INDIVIDUAL_POLLING)
              if( Can_IsMailboxIndivPolling(taskPara.mailboxHandle))
#endif
              {

                CanLL_TxProcessPendings(CAN_CHANNEL_AND_HW_CHANNEL_CANPARA_FIRST &taskPara);
              }
            }
          }
#endif
#if defined(C_ENABLE_CANCEL_TX_IN_HW)
#endif
#endif
        }
      }
    }
  }

#if(CAN_DEV_ERROR_REPORT == STD_ON)
  if(errorId != CAN_E_NO_ERROR){
    Can_CallDetReportError(CAN_MAINFCT_WRITE_ID, errorId);
  }
#else
  CAN_DUMMY_STATEMENT(errorId);
#endif

#else
  CanHookBegin_Can_MainFunction_Write();
#endif
  CanHookEnd_Can_MainFunction_Write();
}

V_DEF_FUNC(V_NONE, void, CODE) Can_MainFunction_Read(void){

  uint8 errorId;
  CanHookBegin_Can_MainFunction_Read();
  errorId = CAN_E_NO_ERROR;

#if(CAN_DEV_ERROR_DETECT == STD_ON)

  if(canConfigInitFlag == CAN_STATUS_UNINIT){
    errorId = CAN_E_UNINIT;
  }
  else
#endif

  if( canIsRxTaskLocked == kCanFalse ){
#if defined(C_ENABLE_RX_POLLING)
    CAN_CHANNEL_CANTYPE_LOCAL
#endif
    canIsRxTaskLocked = kCanTrue;
#if defined(C_ENABLE_RX_POLLING)
#if !defined( C_SINGLE_RECEIVE_CHANNEL )
    for(channel = 0u; channel < kCanNumberOfChannels; channel++)
#endif
    {
#if(CAN_POSTBUILD_VARIANT_SUPPORT == STD_ON)
      if( Can_GetCanIfChannelId(channel) == kCanChannelNotUsed )
      {
        continue;
      }
#endif
#if(CAN_DEV_ERROR_DETECT == STD_ON)
      if(!CanHL_IsControllerInit(channel))
      {
        errorId = CAN_E_UNINIT;
      }
      else
#endif
      {
        if( !CanHL_IsSleep(channel) )
        {

#if defined(C_ENABLE_RX_FULLCAN_OBJECTS)

          CanHL_RxFullCanPolling(CAN_HW_CHANNEL_CANPARA_ONLY);
#endif
#if defined(C_ENABLE_RX_BASICCAN_OBJECTS)

          CanHL_RxBasicCanPolling(CAN_HW_CHANNEL_CANPARA_ONLY);
#endif
        }
      }
    }
#endif
#if defined(C_ENABLE_RX_QUEUE)

    CanHL_RxQueueExecution();
#endif
    canIsRxTaskLocked = kCanFalse;
  }

#if(CAN_DEV_ERROR_REPORT == STD_ON)
  if(errorId != CAN_E_NO_ERROR){
    Can_CallDetReportError(CAN_MAINFCT_READ_ID, errorId);
  }
#else
  CAN_DUMMY_STATEMENT(errorId);
#endif
  CanHookEnd_Can_MainFunction_Read();
}

V_DEF_FUNC(V_NONE, void, CODE) Can_MainFunction_BusOff(void){

#if defined(C_ENABLE_ERROR_POLLING)
  CAN_CHANNEL_CANTYPE_LOCAL
  uint8 errorId;
  errorId = CAN_E_NO_ERROR;

#if(CAN_DEV_ERROR_DETECT == STD_ON)
  if(canConfigInitFlag == CAN_STATUS_UNINIT){
    errorId = CAN_E_UNINIT;
  }
  else
#endif
  {

#if !defined( C_SINGLE_RECEIVE_CHANNEL )
    for(channel = 0u; channel < kCanNumberOfChannels; channel++)
#endif
    {
#if(CAN_POSTBUILD_VARIANT_SUPPORT == STD_ON)
      if( Can_GetCanIfChannelId(channel) == kCanChannelNotUsed )
      {
        continue;
      }
#endif
#if(CAN_DEV_ERROR_DETECT == STD_ON)
      if(!CanHL_IsControllerInit(channel))
      {
        errorId = CAN_E_UNINIT;
      }
      else
#endif
      {
        if( !CanHL_IsSleep(channel) )
        {

          Can_DisableControllerInterrupts((uint8)channel);

          CanHL_ErrorHandling( CAN_HW_CHANNEL_CANPARA_ONLY );
          Can_EnableControllerInterrupts((uint8)channel);
        }
      }
    }
  }

#if(CAN_DEV_ERROR_REPORT == STD_ON)
  if(errorId != CAN_E_NO_ERROR){
    Can_CallDetReportError(CAN_MAINFCT_BO_ID, errorId);
  }
#else
  CAN_DUMMY_STATEMENT(errorId);
#endif
#endif
}

V_DEF_FUNC(V_NONE, void, CODE) Can_MainFunction_Wakeup(void){

#if defined(C_ENABLE_WAKEUP_POLLING)
#if defined(C_ENABLE_SLEEP_WAKEUP)
  CAN_CHANNEL_CANTYPE_LOCAL
  uint8 errorId;
  errorId = CAN_E_NO_ERROR;

#if(CAN_DEV_ERROR_DETECT == STD_ON)
  if(canConfigInitFlag == CAN_STATUS_UNINIT){
    errorId = CAN_E_UNINIT;
  }
  else
#endif
  {

#if !defined( C_SINGLE_RECEIVE_CHANNEL )
    for(channel = 0u; channel < kCanNumberOfChannels; channel++)
#endif
    {
#if(CAN_POSTBUILD_VARIANT_SUPPORT == STD_ON)
      if( Can_GetCanIfChannelId(channel) == kCanChannelNotUsed )
      {
        continue;
      }
#endif
#if(CAN_DEV_ERROR_DETECT == STD_ON)
      if(!CanHL_IsControllerInit(channel))
      {
        errorId = CAN_E_UNINIT;
      }
      else
#endif
      {

        if(CanLL_WakeUpOccured(CAN_CHANNEL_AND_HW_CHANNEL_CANPARA_ONLY) == kCanTrue)
        {

          SchM_Enter_Can_CAN_EXCLUSIVE_AREA_5();

          CanLL_WakeUpHandling(CAN_CHANNEL_CANPARA_ONLY);
          SchM_Exit_Can_CAN_EXCLUSIVE_AREA_5();
        }
      }
    }
  }

#if(CAN_DEV_ERROR_REPORT == STD_ON)
  if(errorId != CAN_E_NO_ERROR){
    Can_CallDetReportError(CAN_MAINFCT_WU_ID, errorId);
  }
#else
  CAN_DUMMY_STATEMENT(errorId);
#endif
#endif
#endif
}

V_DEF_FUNC(V_NONE, void, CODE) Can_MainFunction_Mode(void){

  CAN_CHANNEL_CANTYPE_LOCAL
  uint8 errorId;
  errorId = CAN_E_NO_ERROR;

#if(CAN_DEV_ERROR_DETECT == STD_ON)
  if(canConfigInitFlag == CAN_STATUS_UNINIT){
    errorId = CAN_E_UNINIT;
  }
  else
#endif
  {

    SchM_Enter_Can_CAN_EXCLUSIVE_AREA_6();
#if !defined( C_SINGLE_RECEIVE_CHANNEL )
    for(channel = 0u; channel < kCanNumberOfChannels; channel++)
#endif
    {
#if(CAN_POSTBUILD_VARIANT_SUPPORT == STD_ON)
      if( Can_GetCanIfChannelId(channel) == kCanChannelNotUsed )
      {
        continue;
      }
#endif
#if(CAN_DEV_ERROR_DETECT == STD_ON)
      if(!CanHL_IsControllerInit(channel))
      {
        errorId = CAN_E_UNINIT;
      }
      else
#endif
      {
        uint8 transitionRequest;
        uint8 busOffRecovery;
        uint8 doRamCheck;
        uint8 transitionState;
        transitionRequest = Can_GetModeTransitionRequest(channel);
        busOffRecovery = Can_GetBusOffTransitionRequest(channel);
        doRamCheck = Can_GetRamCheckTransitionRequest(channel);

        if(transitionRequest != kCanModeNone)
        {
          transitionState = CanLL_ModeTransition(CAN_CHANNEL_AND_HW_CHANNEL_CANPARA_FIRST transitionRequest, busOffRecovery, doRamCheck);
          switch(transitionRequest)
          {
#if defined(C_ENABLE_SLEEP_WAKEUP)
            case kCanModeSleep:
              CanHL_NotifyTransition(CAN_CHANNEL_CANPARA_FIRST CAN_STATUS_SLEEP, CANIF_CS_SLEEP, transitionState);
              break;
#endif
            case kCanModeStopReinitFast:
            case kCanModeStopReinit:
#if defined(C_ENABLE_SLEEP_WAKEUP)
            case kCanModeWakeupStopReinit:
#endif
              CanHL_NotifyTransition(CAN_CHANNEL_CANPARA_FIRST CAN_STATUS_STOP, CANIF_CS_STOPPED, transitionState);
              break;
            case kCanModeStart:
            case kCanModeStartReinit:
            case kCanModeResetBusOffEnd:
#if defined(C_ENABLE_SILENT_MODE)
            case kCanModeSilent:
#endif
              CanHL_NotifyTransition(CAN_CHANNEL_CANPARA_FIRST CAN_STATUS_START, CANIF_CS_STARTED, transitionState);
              if( transitionState == kCanOk )
              {
                Can_SetIsBusOff(channel, FALSE);
              }
              break;
            case kCanModeResetBusOffStart:
            default:
              break;
          }
        }
      }
    }
    SchM_Exit_Can_CAN_EXCLUSIVE_AREA_6();
  }

#if(CAN_DEV_ERROR_REPORT == STD_ON)
  if(errorId != CAN_E_NO_ERROR){
    Can_CallDetReportError(CAN_MAINFCT_MODE_ID, errorId);
  }
#else
  CAN_DUMMY_STATEMENT(errorId);
#endif
}

V_DEF_FUNC(V_NONE, void, CODE) Can_CancelTx( Can_HwHandleType Hth, PduIdType PduId ){

#if defined(C_ENABLE_CANCEL_SUPPORT_API)
  CAN_CHANNEL_CANTYPE_LOCAL
  tCanTxCancellationParaStruct txCancellationPara;
  uint8 errorId;
  errorId = CAN_E_NO_ERROR;

#if(CAN_DEV_ERROR_DETECT == STD_ON)
  if(canConfigInitFlag == CAN_STATUS_UNINIT){
    errorId = CAN_E_UNINIT;
  }
  else
  if(Hth >= Can_GetSizeOfMailbox()){
    errorId = CAN_E_PARAM_HANDLE;
  }
  else
#if defined(C_ENABLE_TX_FULLCAN_OBJECTS)
  if((Can_GetMailboxType(Hth) != CAN_TX_BASICCAN_TYPE) && (Can_GetMailboxType(Hth) != CAN_TX_BASICCAN_MUX_TYPE) && (Can_GetMailboxType(Hth) != CAN_TX_BASICCAN_FIFO_TYPE) && (Can_GetMailboxType(Hth) != CAN_TX_FULLCAN_TYPE))
#else
  if((Can_GetMailboxType(Hth) != CAN_TX_BASICCAN_TYPE) && (Can_GetMailboxType(Hth) != CAN_TX_BASICCAN_MUX_TYPE) && (Can_GetMailboxType(Hth) != CAN_TX_BASICCAN_FIFO_TYPE))
#endif
  {
    errorId = CAN_E_PARAM_HANDLE;
  }
  else
#endif
  {
#if !defined( C_SINGLE_RECEIVE_CHANNEL )
    channel = Can_GetMailboxController(Hth);
#endif
#if(CAN_DEV_ERROR_DETECT == STD_ON)
#if !defined( C_SINGLE_RECEIVE_CHANNEL )
    if(channel >= kCanNumberOfChannels){
      errorId = CAN_E_PARAM_CONTROLLER;
    }
    else
#endif
#if(CAN_POSTBUILD_VARIANT_SUPPORT == STD_ON)
    if(Can_GetCanIfChannelId(channel) == kCanChannelNotUsed){
      errorId = CAN_E_PARAM_CONTROLLER;
    }
    else
#endif
    if(!CanHL_IsControllerInit(channel)){
      errorId = CAN_E_UNINIT;
    }
    else
#endif
    {

      txCancellationPara.mailboxHandle = Hth;
#if defined(C_ENABLE_CANCEL_TX_IN_HW)
      txCancellationPara.hwObjHandle = Can_GetMailboxHwHandle(Hth);
#endif
      txCancellationPara.mailboxElement = 0u;
      txCancellationPara.activeSendObject = CanHL_GetActiveSendObject(txCancellationPara.mailboxHandle, txCancellationPara.mailboxElement);

#if defined (C_ENABLE_TX_FULLCAN_OBJECTS)
      if( Can_GetMailboxType(Hth) != CAN_TX_FULLCAN_TYPE )
#endif
      {
#if defined(C_ENABLE_MULTIPLEXED_TRANSMISSION) || defined(C_ENABLE_TX_HW_FIFO)
        for(; txCancellationPara.mailboxElement < Can_GetMailboxSize(Hth); txCancellationPara.mailboxElement++, txCancellationPara.activeSendObject++)
#endif
        {
          if(Can_GetActiveSendPdu(txCancellationPara.activeSendObject) == PduId)
          {
            if((Can_GetActiveSendState(txCancellationPara.activeSendObject) == kCanBufferSend)
#if defined(C_ENABLE_CANCEL_TX_IN_HW)
                || (Can_GetActiveSendState(txCancellationPara.activeSendObject) == kCanBufferCancel)
#endif
                )
            {

#if defined(C_ENABLE_CANCEL_IN_HW)
              {

                txCancellationPara.canHandleCurTxObj = kCanBufferCancelSw;
                CanLL_TxCancelInHw(CAN_CHANNEL_AND_HW_CHANNEL_CANPARA_FIRST &txCancellationPara);
                Can_SetActiveSendState(txCancellationPara.activeSendObject, kCanBufferCancelSw);
              }
#else
              Can_SetActiveSendState(txCancellationPara.activeSendObject, kCanBufferCancelSw);
#endif
#if defined(C_ENABLE_MULTIPLEXED_TRANSMISSION) || defined(C_ENABLE_TX_HW_FIFO)
              break;
#endif
            }
          }
        }
      }
#if defined (C_ENABLE_TX_FULLCAN_OBJECTS)
      else
      {
        if(Can_GetActiveSendPdu(txCancellationPara.activeSendObject) == PduId)
        {
          if((Can_GetActiveSendState(txCancellationPara.activeSendObject) == kCanBufferSend)
#if defined(C_ENABLE_CANCEL_TX_IN_HW)
              || (Can_GetActiveSendState(txCancellationPara.activeSendObject) == kCanBufferCancel)
#endif
             )
          {

#if defined(C_ENABLE_CANCEL_TX_IN_HW)
            {

              txCancellationPara.canHandleCurTxObj = kCanBufferCancelSw;
              CanLL_TxCancelInHw(CAN_CHANNEL_AND_HW_CHANNEL_CANPARA_FIRST &txCancellationPara);
              Can_SetActiveSendState(txCancellationPara.activeSendObject, kCanBufferCancelSw);
            }
#endif
            Can_SetActiveSendState(txCancellationPara.activeSendObject, kCanBufferCancelSw);
          }
        }
      }
#endif
    }
    CAN_CHANNEL_DUMMY_STATEMENT;
  }

#if(CAN_DEV_ERROR_REPORT == STD_ON)
  if(errorId != CAN_E_NO_ERROR){
    Can_CallDetReportError(CAN_WRITE_ID, errorId);
  }
#else
  CAN_DUMMY_STATEMENT(errorId);
#endif
#else
  CAN_DUMMY_STATEMENT(Hth);
  CAN_DUMMY_STATEMENT(PduId);
#endif
}

#if(CAN_GET_STATUS == STD_ON)

V_DEF_FUNC(V_NONE, uint8, CODE) Can_GetStatus( uint8 Controller ){

  uint8 canReturnCode;
  uint8 errorId;
  errorId = CAN_E_NO_ERROR;
  canReturnCode = CAN_STATUS_INCONSISTENT;

#if(CAN_DEV_ERROR_DETECT == STD_ON)

  if(canConfigInitFlag == CAN_STATUS_UNINIT){
    errorId = CAN_E_UNINIT;
  }
  else
#if !defined( C_SINGLE_RECEIVE_CHANNEL )
  if(channel >= kCanNumberOfChannels){
    errorId = CAN_E_PARAM_CONTROLLER;
  }
  else
#endif
#if(CAN_POSTBUILD_VARIANT_SUPPORT == STD_ON)
  if(Can_GetCanIfChannelId(channel) == kCanChannelNotUsed){
    errorId = CAN_E_PARAM_CONTROLLER;
  }
  else
#endif
  if(!CanHL_IsControllerInit(channel)){
    errorId = CAN_E_UNINIT;
  }
  else
#endif
  {

    CanLL_GetStatusBegin(CAN_CHANNEL_CANPARA_ONLY);

    canReturnCode = (uint8)Can_GetLogStatus(channel);
    if( CanLL_HwIsBusOff(channel) ){
      canReturnCode |= CAN_STATUS_BUSOFF;
    }
#if defined(C_ENABLE_EXTENDED_STATUS)
    {
      if( CanLL_HwIsPassive(channel) )
      {
        canReturnCode |= CAN_STATUS_PASSIVE;
      }
      if( CanLL_HwIsWarning(channel) )
      {
        canReturnCode |= CAN_STATUS_WARNING;
      }
    }
#endif
  }

#if(CAN_DEV_ERROR_REPORT == STD_ON)
  if(errorId != CAN_E_NO_ERROR){
    Can_CallDetReportError(CAN_HW_ACCESS_ID, errorId);
  }
#else
  CAN_DUMMY_STATEMENT(errorId);
#endif
#if defined( C_SINGLE_RECEIVE_CHANNEL )
  CAN_DUMMY_STATEMENT(Controller);
#endif
  return (uint8)canReturnCode;
}

V_DEF_FUNC(V_NONE, Std_ReturnType, CODE) Can_GetControllerMode( uint8 Controller, Can_ControllerStatePtrType ControllerModePtr ){

  Std_ReturnType canReturnCode;
  uint8 errorId;
  errorId = CAN_E_NO_ERROR;
  canReturnCode = E_NOT_OK;

#if(CAN_DEV_ERROR_DETECT == STD_ON)

  if(canConfigInitFlag == CAN_STATUS_UNINIT){
    errorId = CAN_E_UNINIT;
  }
  else
#if !defined( C_SINGLE_RECEIVE_CHANNEL )
  if(channel >= kCanNumberOfChannels){
    errorId = CAN_E_PARAM_CONTROLLER;
  }
  else
#endif
#if(CAN_POSTBUILD_VARIANT_SUPPORT == STD_ON)
  if(Can_GetCanIfChannelId(channel) == kCanChannelNotUsed){
    errorId = CAN_E_PARAM_CONTROLLER;
  }
  else
#endif
  if(ControllerModePtr == NULL_PTR){
    errorId = CAN_E_PARAM_POINTER;
  }
  else
#endif
  {

    if(!CanHL_IsControllerInit(channel)){
      *ControllerModePtr = CAN_CS_UNINIT;
    }
    else if(CanHL_IsStart(channel)){
      *ControllerModePtr = CAN_CS_STARTED;
    }
    else if(CanHL_IsSleep(channel)){
      *ControllerModePtr = CAN_CS_SLEEP;
    }
    else{
      *ControllerModePtr = CAN_CS_STOPPED;
    }
    canReturnCode = E_OK;
  }

#if(CAN_DEV_ERROR_REPORT == STD_ON)
  if(errorId != CAN_E_NO_ERROR){
    Can_CallDetReportError(CAN_GETCTR_MODE_ID, errorId);
  }
#else
  CAN_DUMMY_STATEMENT(errorId);
#endif
#if defined( C_SINGLE_RECEIVE_CHANNEL )
  CAN_DUMMY_STATEMENT(Controller);
#endif
  return canReturnCode;
}

V_DEF_FUNC(V_NONE, Std_ReturnType, CODE) Can_GetControllerErrorState( uint8 Controller, Can_ErrorStatePtrType ErrorStatePtr ){

  Std_ReturnType canReturnCode;
  uint8 errorId;
  errorId = CAN_E_NO_ERROR;
  canReturnCode = E_NOT_OK;

#if(CAN_DEV_ERROR_DETECT == STD_ON)

  if(canConfigInitFlag == CAN_STATUS_UNINIT){
    errorId = CAN_E_UNINIT;
  }
  else
#if !defined( C_SINGLE_RECEIVE_CHANNEL )
  if(channel >= kCanNumberOfChannels){
    errorId = CAN_E_PARAM_CONTROLLER;
  }
  else
#endif
#if(CAN_POSTBUILD_VARIANT_SUPPORT == STD_ON)
  if(Can_GetCanIfChannelId(channel) == kCanChannelNotUsed){
    errorId = CAN_E_PARAM_CONTROLLER;
  }
  else
#endif
  if(!CanHL_IsControllerInit(channel)){
    errorId = CAN_E_UNINIT;
  }
  else
  if(ErrorStatePtr == NULL_PTR){
    errorId = CAN_E_PARAM_POINTER;
  }
  else
#endif
  {

    CanLL_GetStatusBegin(CAN_CHANNEL_CANPARA_ONLY);
    if( CanLL_HwIsBusOff(channel) ){
      *ErrorStatePtr = CAN_ERRORSTATE_BUSOFF;
    }
#if defined(C_ENABLE_EXTENDED_STATUS)
    else if( CanLL_HwIsPassive(channel) ){
      *ErrorStatePtr = CAN_ERRORSTATE_PASSIVE;
    }
#endif
    else{
      *ErrorStatePtr = CAN_ERRORSTATE_ACTIVE;
    }
    canReturnCode = E_OK;
  }

#if(CAN_DEV_ERROR_REPORT == STD_ON)
  if(errorId != CAN_E_NO_ERROR){
    Can_CallDetReportError(CAN_GETCTR_STATE_ID, errorId);
  }
#else
  CAN_DUMMY_STATEMENT(errorId);
#endif
#if defined( C_SINGLE_RECEIVE_CHANNEL )
  CAN_DUMMY_STATEMENT(Controller);
#endif
  return canReturnCode;
}

V_DEF_FUNC(V_NONE, Std_ReturnType, CODE) Can_GetControllerTxErrorCounter( uint8 Controller, Can_ErrorCounterPtrType TxErrorCounterPtr ){

  Std_ReturnType canReturnCode;
  uint8 errorId;
  errorId = CAN_E_NO_ERROR;
  canReturnCode = E_NOT_OK;

#if(CAN_DEV_ERROR_DETECT == STD_ON)

  if(canConfigInitFlag == CAN_STATUS_UNINIT){
    errorId = CAN_E_UNINIT;
  }
  else
#if !defined( C_SINGLE_RECEIVE_CHANNEL )
  if(channel >= kCanNumberOfChannels){
    errorId = CAN_E_PARAM_CONTROLLER;
  }
  else
#endif
#if(CAN_POSTBUILD_VARIANT_SUPPORT == STD_ON)
  if(Can_GetCanIfChannelId(channel) == kCanChannelNotUsed){
    errorId = CAN_E_PARAM_CONTROLLER;
  }
  else
#endif
  if(!CanHL_IsControllerInit(channel)){
    errorId = CAN_E_UNINIT;
  }
  else
  if(TxErrorCounterPtr == NULL_PTR){
    errorId = CAN_E_PARAM_POINTER;
  }
  else
#endif
  {

#if defined( C_SINGLE_RECEIVE_CHANNEL )
    *TxErrorCounterPtr = CanTxActualErrorCounter();
#else
    *TxErrorCounterPtr = CanTxActualErrorCounter(channel);
#endif
    canReturnCode = E_OK;
  }

#if(CAN_DEV_ERROR_REPORT == STD_ON)
  if(errorId != CAN_E_NO_ERROR){
    Can_CallDetReportError(CAN_GETCTR_TXCNT_ID, errorId);
  }
#else
  CAN_DUMMY_STATEMENT(errorId);
#endif
#if defined( C_SINGLE_RECEIVE_CHANNEL )
  CAN_DUMMY_STATEMENT(Controller);
#endif
  return canReturnCode;
}

V_DEF_FUNC(V_NONE, Std_ReturnType, CODE) Can_GetControllerRxErrorCounter( uint8 Controller, Can_ErrorCounterPtrType RxErrorCounterPtr ){

  Std_ReturnType canReturnCode;
  uint8 errorId;
  errorId = CAN_E_NO_ERROR;
  canReturnCode = E_NOT_OK;

#if(CAN_DEV_ERROR_DETECT == STD_ON)

  if(canConfigInitFlag == CAN_STATUS_UNINIT){
    errorId = CAN_E_UNINIT;
  }
  else
#if !defined( C_SINGLE_RECEIVE_CHANNEL )
  if(channel >= kCanNumberOfChannels){
    errorId = CAN_E_PARAM_CONTROLLER;
  }
  else
#endif
#if(CAN_POSTBUILD_VARIANT_SUPPORT == STD_ON)
  if(Can_GetCanIfChannelId(channel) == kCanChannelNotUsed){
    errorId = CAN_E_PARAM_CONTROLLER;
  }
  else
#endif
  if(!CanHL_IsControllerInit(channel)){
    errorId = CAN_E_UNINIT;
  }
  else
  if(RxErrorCounterPtr == NULL_PTR){
    errorId = CAN_E_PARAM_POINTER;
  }
  else
#endif
  {

#if defined( C_SINGLE_RECEIVE_CHANNEL )
    *RxErrorCounterPtr = CanRxActualErrorCounter();
#else
    *RxErrorCounterPtr = CanRxActualErrorCounter(channel);
#endif
    canReturnCode = E_OK;
  }

#if(CAN_DEV_ERROR_REPORT == STD_ON)
  if(errorId != CAN_E_NO_ERROR){
    Can_CallDetReportError(CAN_GETCTR_RXCNT_ID, errorId);
  }
#else
  CAN_DUMMY_STATEMENT(errorId);
#endif
#if defined( C_SINGLE_RECEIVE_CHANNEL )
  CAN_DUMMY_STATEMENT(Controller);
#endif
  return canReturnCode;
}

#endif

#if defined(C_ENABLE_MIRROR_MODE)

V_DEF_FUNC(V_NONE, void, CODE) Can_SetMirrorMode( uint8 Controller, CddMirror_MirrorModeType mirrorMode ){

  uint8 errorId;
  errorId = CAN_E_NO_ERROR;

#if(CAN_DEV_ERROR_DETECT == STD_ON)
  if(canConfigInitFlag == CAN_STATUS_UNINIT){
    errorId = CAN_E_UNINIT;
  }
  else
#if !defined( C_SINGLE_RECEIVE_CHANNEL )
  if(channel >= kCanNumberOfChannels){
    errorId = CAN_E_PARAM_CONTROLLER;
  }
  else
#endif
#endif
  {

    Can_SetMirrorModeState(channel, mirrorMode);
  }

#if(CAN_DEV_ERROR_REPORT == STD_ON)
  if(errorId != CAN_E_NO_ERROR){
    Can_CallDetReportError(CAN_HW_ACCESS_ID, errorId);
  }
#else
  CAN_DUMMY_STATEMENT(errorId);
#endif
#if defined( C_SINGLE_RECEIVE_CHANNEL )
  CAN_DUMMY_STATEMENT(Controller);
#endif
}
#endif

#if defined(C_ENABLE_SILENT_MODE)

V_DEF_FUNC(V_NONE, Std_ReturnType, CODE) Can_SetSilentMode( uint8 Controller, Can_SilentModeType silentMode ){

  uint8 errorId;
  Std_ReturnType retval;
  errorId = CAN_E_NO_ERROR;
  retval = E_NOT_OK;

#if(CAN_DEV_ERROR_DETECT == STD_ON)
  if(canConfigInitFlag == CAN_STATUS_UNINIT){
    errorId = CAN_E_UNINIT;
  }
  else
#if !defined( C_SINGLE_RECEIVE_CHANNEL )
  if(channel >= kCanNumberOfChannels){
    errorId = CAN_E_PARAM_CONTROLLER;
  }
  else
#endif
#endif
  {

    Can_SetSilentModeState(channel, silentMode);
    retval = E_OK;
  }

#if(CAN_DEV_ERROR_REPORT == STD_ON)
  if(errorId != CAN_E_NO_ERROR){
    Can_CallDetReportError(CAN_HW_ACCESS_ID, errorId);
  }
#else
  CAN_DUMMY_STATEMENT(errorId);
#endif
#if defined( C_SINGLE_RECEIVE_CHANNEL )
  CAN_DUMMY_STATEMENT(Controller);
#endif
  return retval;
}
#endif

#if defined(C_ENABLE_CAN_RAM_CHECK_EXTENDED)

V_DEF_FUNC(V_NONE, void, CODE) Can_RamCheckExecute( uint8 Controller ){

  uint8 errorId;
  errorId = CAN_E_NO_ERROR;

#if(CAN_DEV_ERROR_DETECT == STD_ON)
  if(canConfigInitFlag == CAN_STATUS_UNINIT){
    errorId = CAN_E_UNINIT;
  }
  else
#if !defined( C_SINGLE_RECEIVE_CHANNEL )
  if(channel >= kCanNumberOfChannels){
    errorId = CAN_E_PARAM_CONTROLLER;
  }
  else
#endif
#endif
  {
    uint8 transitionState;

    transitionState = CanHL_ModeTransition(CAN_CHANNEL_CANPARA_FIRST kCanModeStopReinit, kCanFinishBusOffRecovery, kCanExecuteRamCheck);
    if(transitionState == kCanOk){
      Can_SetLogStatus(channel, Can_GetLogStatus(channel) | CAN_STATUS_STOP);
    }
  }

#if(CAN_DEV_ERROR_REPORT == STD_ON)
  if(errorId != CAN_E_NO_ERROR){
    Can_CallDetReportError(CAN_HW_ACCESS_ID, errorId);
  }
#else
  CAN_DUMMY_STATEMENT(errorId);
#endif
#if defined( C_SINGLE_RECEIVE_CHANNEL )
  CAN_DUMMY_STATEMENT(Controller);
#endif
}

V_DEF_FUNC(V_NONE, void, CODE) Can_RamCheckEnableMailbox( Can_HwHandleType htrh ){

  uint8 errorId;
  errorId = CAN_E_NO_ERROR;

#if(CAN_DEV_ERROR_DETECT == STD_ON)
  if(canConfigInitFlag == CAN_STATUS_UNINIT){
    errorId = CAN_E_UNINIT;
  }
  else
  if(htrh >= Can_GetSizeOfMailbox()) {
    errorId = CAN_E_PARAM_HANDLE;
  }
  else
#endif
  {

    Can_SetLogStatus(Can_GetMailboxController(htrh), CAN_DEACTIVATE_CONTROLLER);

    Can_SetMailboxState(htrh, kCanOk);
  }

#if(CAN_DEV_ERROR_REPORT == STD_ON)
  if(errorId != CAN_E_NO_ERROR){
    Can_CallDetReportError(CAN_HW_ACCESS_ID, errorId);
  }
#else
  CAN_DUMMY_STATEMENT(errorId);
#endif
}

V_DEF_FUNC(V_NONE, void, CODE) Can_RamCheckEnableController( uint8 Controller ){

  uint8 errorId;
  errorId = CAN_E_NO_ERROR;

#if(CAN_DEV_ERROR_DETECT == STD_ON)
  if(canConfigInitFlag == CAN_STATUS_UNINIT){
    errorId = CAN_E_UNINIT;
  }
  else
#if !defined( C_SINGLE_RECEIVE_CHANNEL )
  if(channel >= kCanNumberOfChannels){
    errorId = CAN_E_PARAM_CONTROLLER;
  }
  else
#endif
#endif
  {

    if( (Can_GetLogStatus(channel) & CAN_DEACTIVATE_CONTROLLER) == CAN_DEACTIVATE_CONTROLLER ){
      uint8 transitionState;

      Can_SetLogStatus(channel, Can_GetLogStatus(channel) & (uint8)(~(CAN_DEACTIVATE_CONTROLLER)));
      transitionState = CanHL_ModeTransition(CAN_CHANNEL_CANPARA_FIRST kCanModeStopReinit, kCanFinishBusOffRecovery, kCanSuppressRamCheck);
      if(transitionState == kCanOk)
      {
        Can_SetLogStatus(channel, Can_GetLogStatus(channel) | CAN_STATUS_STOP);
      }
    }
  }

#if(CAN_DEV_ERROR_REPORT == STD_ON)
  if(errorId != CAN_E_NO_ERROR){
    Can_CallDetReportError(CAN_HW_ACCESS_ID, errorId);
  }
#else
  CAN_DUMMY_STATEMENT(errorId);
#endif
#if defined( C_SINGLE_RECEIVE_CHANNEL )
  CAN_DUMMY_STATEMENT(Controller);
#endif
}
#endif

#if defined (C_ENABLE_ECC_TX_ERROR)

V_DEF_FUNC_API(V_NONE, vuint8, CODE) CanEccTxError(CanChannelHandle Controller){

  vuint8 retVal = kCanFalse;
  vuint32 bitmask;

  if(Controller == kCanChannelNotUsed){
    bitmask = kCanEfMaskEccError;
  }
  else{
    bitmask = CanLL_SL32(mCanLogToPhys(Controller) + 16u);
  }

  if((Can->CGEF & bitmask) != kCanZero){
    retVal = kCanTrue;
  }

  return (retVal);
}

V_DEF_FUNC_API(V_NONE, void, CODE) CanEccTxErrorClear(CanChannelHandle Controller){

  vuint32 bitmask;

  if(Controller == kCanChannelNotUsed){
    bitmask = kCanEfMaskEccErrorClear;
  }
  else{
    bitmask = ((vuint32) ~CanLL_SL32(mCanLogToPhys(Controller) + 16u));
  }

  Can->CGEF = bitmask;
}

#endif

#if defined(C_ENABLE_GLOBAL_INIT_POST_PROCESS)

V_DEF_FUNC_API(V_NONE, vuint8, CODE) CanGetFilterRulesStartPage(void){

  return (CanAddFilterRulesStartPage);
}

V_DEF_FUNC_API(V_NONE, vuint8, CODE) CanGetFilterRulesStartIndex(void){

  return (CanAddFilterRulesStartIndex);
}

#endif

#if defined(C_ENABLE_RX_BASICCAN_OBJECTS)
#if defined(C_ENABLE_RX_BASICCAN_POLLING ) && !defined(C_ENABLE_INDIVIDUAL_POLLING)
#else

V_DEF_FUNC(V_NONE, void, CODE) CanInterruptRxFifo(void){

  CAN_HW_CHANNEL_CANTYPE_LOCAL
  CanObjectHandle mailboxHandle;
  CanObjectHandle hwObjHandle;
  vuint8 canCount;

  CanLL_RtmStart(CanInterruptRxFifo);
  CanLL_EI();

#     if defined(C_MULTIPLE_RECEIVE_CHANNEL)

    for(canHwChannel=0; canHwChannel<kCanNumberOfChannels; canHwChannel++)
#     endif
    {

#     if(CAN_POSTBUILD_VARIANT_SUPPORT == STD_ON)
      if(Can_GetCanIfChannelId(channel) != CAN_NO_CANIFCHANNELID)
#     endif
      {

        mailboxHandle = CAN_HL_MB_RX_BASIC_STARTINDEX(canHwChannel);
#     if defined(C_ENABLE_MULTIPLE_BASICCAN)
        for(; mailboxHandle < CAN_HL_MB_RX_BASIC_STOPINDEX(canHwChannel); mailboxHandle++)
#     endif
        {
#     if defined(C_ENABLE_INDIVIDUAL_POLLING)

          if(!Can_IsMailboxIndivPolling(mailboxHandle))
#     endif
          {

            hwObjHandle = Can_GetMailboxHwHandle(mailboxHandle);
            if((Can->CRFSR[hwObjHandle] & kCanSrFifoEmpty) == 0u)
            {
              canCount = Can_GetFifoProcCountOfChannelData(canHwChannel);

              do
              {
                canCount--;

                CanHL_BasicCanMsgReceived(CAN_HW_CHANNEL_CANPARA_FIRST mailboxHandle, hwObjHandle);
              } while(((Can->CRFSR[hwObjHandle] & kCanSrFifoEmpty) == 0u) && (canCount > 0u));
            }
          }
        }
      }
    }

  CanLL_DI();
  CanLL_RtmStop(CanInterruptRxFifo);
}

#endif
#endif

#if defined(C_ENABLE_TX_POLLING) && !defined(C_ENABLE_INDIVIDUAL_POLLING)
#else

V_DEF_FUNC(V_NONE, void, CODE) CanInterruptTx(CAN_HW_CHANNEL_CANTYPE_ONLY){

  kCanTxSize localReg;
  CanObjectHandle mailboxHandle;
  CanObjectHandle hwObjHandle;
  CanObjectHandle mailboxElement = kCanZero;
#if defined(C_ENABLE_TX_HW_FIFO)
  vuint8 canCount;
  vuint8 requestCount;
  vuint8 pendingCount;
#endif
#if defined(C_MULTIPLE_PHYS_CHANNEL)
  CanChannelHandle canPhysChannel = mCanLogToPhys(canHwChannel);
#endif

  CanLL_RtmStart(CanInterruptTx);
  CanLL_EI();

    localReg = CanLL_TxSharedRegToWord(canPhysChannel, Can->CTBTCSR[CanLL_TxWordIndex(canPhysChannel)]) & Can_GetTxIntMaskOfChannelData(canHwChannel);
#if defined(C_ENABLE_CANCEL_IN_HW)

#if defined(C_ENABLE_INDIVIDUAL_POLLING)
    localReg |= CanLL_TxSharedRegToWord(canPhysChannel, Can->CTBASR[CanLL_TxWordIndex(canPhysChannel)]);
#    else
    localReg |= CanLL_TxSharedRegToWord(canPhysChannel, Can->CTBASR[CanLL_TxWordIndex(canPhysChannel)]) & Can_GetTxIntMaskOfChannelData(canHwChannel);
#endif
#endif

    if(localReg != 0u){

#if defined(C_ENABLE_IF_RSCAN_FD_V3)
      if      ((localReg & 0x000000FFu) != 0u) { hwObjHandle = 0u; }
      else if((localReg & 0x0000FF00u) != 0u) { hwObjHandle = 8u; }
      else if((localReg & 0x00FF0000u) != 0u) { hwObjHandle = 16u; }
      else                                     { hwObjHandle = 24u; }
#else
      if      ((localReg & 0x000Fu) != 0u) { hwObjHandle = 0u; }
      else if((localReg & 0x00F0u) != 0u) { hwObjHandle = 4u; }
      else if((localReg & 0x0F00u) != 0u) { hwObjHandle = 8u; }
      else                                 { hwObjHandle = 12u; }
#endif

      do
      {
        if((localReg & CanLL_SLTS(hwObjHandle)) != 0u)
        {

          mailboxHandle = Can_GetTxHwToMbHandle(canHwChannel, hwObjHandle);
#if defined(C_ENABLE_MULTIPLEXED_TRANSMISSION)
          mailboxElement = hwObjHandle - Can_GetMailboxHwHandle(mailboxHandle);
#endif
          CanHL_TxConfirmation(CAN_HW_CHANNEL_CANPARA_FIRST mailboxHandle, mailboxElement, hwObjHandle);
          localReg &= (localReg-1u);
        }
        hwObjHandle++;
      }  while(localReg != 0u);
    }

#if defined(C_ENABLE_TX_HW_FIFO)

  for(hwObjHandle = kCanZero; hwObjHandle < Can_GetTxFifoCountOfChannelData(channel); hwObjHandle++){
    mailboxHandle = Can_GetTxFifoHwToMbHandle(canHwChannel, hwObjHandle);
#if defined(C_ENABLE_INDIVIDUAL_POLLING)
    if(!Can_IsMailboxIndivPolling(mailboxHandle))
#endif
    {
      if((Can->ChFS[canPhysChannel].TRFSR[hwObjHandle] & kCanSrTxFifoIntFlag) != 0u)
      {

        Can->ChFS[canPhysChannel].TRFSR[hwObjHandle] &= ((kCanRegSize) ~kCanSrTxFifoIntFlag);

        canCount = Can_GetFifoProcCountOfChannelData(canHwChannel);
        requestCount = (vuint8)Can_GetTxHwFifoFillCount(Can_GetMailboxTxHwFifo(mailboxHandle));
        pendingCount = (vuint8)((Can->ChFS[canPhysChannel].TRFSR[hwObjHandle] & kCanSrFifoMsgCount) >> 8);
        while(((requestCount - pendingCount) > 0u) && (canCount > 0u))
        {
          canCount--;
          CanHL_TxConfirmation(CAN_HW_CHANNEL_CANPARA_FIRST mailboxHandle, kCanZero, hwObjHandle);
          requestCount = (vuint8)Can_GetTxHwFifoFillCount(Can_GetMailboxTxHwFifo(mailboxHandle));
          pendingCount = (vuint8)((Can->ChFS[canPhysChannel].TRFSR[hwObjHandle] & kCanSrFifoMsgCount) >> 8);
        }
      }
    }
  }
#endif

  CanLL_DI();
  CanLL_RtmStop(CanInterruptTx);
}

#endif

#if defined(C_ENABLE_LL_WAKEUP_SUPPORT)
#if defined(C_ENABLE_WAKEUP_POLLING)
#else

V_DEF_FUNC(V_NONE, void, CODE) CanInterruptWakeup(CAN_HW_CHANNEL_CANTYPE_ONLY){

  CanLL_RtmStart(CanInterruptWakeup);
  CanLL_EI();

  CanLL_WakeUpHandling(CAN_HW_CHANNEL_CANPARA_ONLY);

  CanLL_DI();
  CanLL_RtmStop(CanInterruptWakeup);
}

#endif
#endif

#if defined(C_ENABLE_ERROR_POLLING)
#else

V_DEF_FUNC(V_NONE, void, CODE) CanInterruptStatus(CAN_HW_CHANNEL_CANTYPE_ONLY){

  CanLL_RtmStart(CanInterruptStatus);
  CanLL_EI();

  CanHL_ErrorHandling(CAN_HW_CHANNEL_CANPARA_ONLY);

  CanLL_DI();
  CanLL_RtmStop(CanInterruptStatus);
}

#if(defined(C_ENABLE_RX_BASICCAN_OBJECTS) && defined(C_ENABLE_OVERRUN))

V_DEF_FUNC(V_NONE, void, CODE) CanInterruptGlobalStatus(void){

  CAN_HW_CHANNEL_CANTYPE_LOCAL

  CanLL_RtmStart(CanInterruptGlobalStatus);
  CanLL_EI();

#if defined(C_MULTIPLE_RECEIVE_CHANNEL)

    for(canHwChannel=0; canHwChannel<kCanNumberOfChannels; canHwChannel++)
#endif
    {

#if(CAN_POSTBUILD_VARIANT_SUPPORT == STD_ON)
      if(Can_GetCanIfChannelId(canHwChannel) != CAN_NO_CANIFCHANNELID)
#endif
      {

        CanHL_ErrorHandling(CAN_HW_CHANNEL_CANPARA_ONLY);
      }
    }

  CanLL_DI();
  CanLL_RtmStop(CanInterruptGlobalStatus);
}

#endif
#endif

#define CAN_STOP_SEC_CODE
#include "MemMap.hpp"

#ifdef __cplusplus
}
#endif
