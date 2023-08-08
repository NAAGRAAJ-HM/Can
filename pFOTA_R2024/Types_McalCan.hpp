#ifndef CAN_GENERAL_TYPES
#define CAN_GENERAL_TYPES

#define CAN_GENERAL_TYPES_MAJOR_VERSION     0x01
#define CAN_GENERAL_TYPES_MINOR_VERSION     0x01
#define CAN_GENERAL_TYPES_PATCH_VERSION     0x00

#include "Types_SwcServiceCom.hpp"

typedef enum CanTrcv_TrcvModeTypeTag{
  CANTRCV_TRCVMODE_NORMAL = 0u,
  CANTRCV_TRCVMODE_SLEEP,
  CANTRCV_TRCVMODE_STANDBY
}CanTrcv_TrcvModeType;

typedef enum CanTrcv_TrcvWakeupModeTypeTag{
  CANTRCV_WUMODE_ENABLE = 0u,
  CANTRCV_WUMODE_CLEAR,
  CANTRCV_WUMODE_DISABLE
}CanTrcv_TrcvWakeupModeType;

typedef enum CanTrcv_TrcvWakeupReasonTypeTag{
  CANTRCV_WU_ERROR = 0u,
  CANTRCV_WU_BY_BUS,
  CANTRCV_WU_BY_PIN,
  CANTRCV_WU_INTERNALLY,
  CANTRCV_WU_NOT_SUPPORTED,
  CANTRCV_WU_POWER_ON,
  CANTRCV_WU_RESET,
  CANTRCV_WU_BY_SYSERR
}CanTrcv_TrcvWakeupReasonType;

#include "Types_CfgMcalCan.hpp"
#include "InfoVersion_EcuabCanIf.hpp"

#endif
