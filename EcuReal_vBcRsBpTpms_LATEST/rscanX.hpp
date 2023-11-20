#ifndef _RSCAN_X_H_
#define _RSCAN_X_H_

#include "types.hpp"
#include "Types_McalCan.hpp"

#define CAN_RTN_OK                          0U
#define CAN_RTN_FIFO_FULL                   1U
#define CAN_RTN_BUFFER_EMPTY                2U
#define CAN_RTN_ERR                         255U

typedef uint8 Can_RtnType;

extern void RS_CAN_Init(void);
extern void RS_CAN_SetCommunicationMode(void);
extern void RS_CAN_SetResetMode(void);
extern void RS_CAN_SetSleepMode(void);
extern Can_RtnType Can_ReadRxFiFo(Type_McalCan_stFrame* pFrame);
extern Can_RtnType Can_SendTxBuffer(const Type_McalCan_stFrame* pFrame);
extern void Can_ClearRxFiFoInterruptFlag(void);
extern void Can_ClearTxBufferInterruptFlag(void);

#endif

