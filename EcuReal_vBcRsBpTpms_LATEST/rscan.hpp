#ifndef _RSCAN_H_
#define _RSCAN_H_

#include "device.hpp"
#include "Types.hpp"
#include "can_table.hpp"
#include "rscanX.hpp"

#if(COMPILER == COMP_GHS)
typedef          unsigned char  U8;
typedef            signed char  S8;
typedef          unsigned short U16;
typedef            signed short S16;
typedef          unsigned long  U32;
typedef            signed long  S32;
typedef          unsigned char  BOOL;
typedef volatile unsigned char  VU8;
typedef volatile unsigned short VU16;
typedef volatile unsigned long  VU32;
#endif

#ifndef CAN_ENABLE
#define CAN_ENABLE                                                            1U
#endif

#ifndef CAN_DISABLE
#define CAN_DISABLE                                                           0U
#endif

#define CAN_SET                                                               1U
#define CAN_CLR                                                               0U

#define CAN_1_BIT_MASK                                                        1U
#define CAN_2_BIT_MASK                                                        3U
#define CAN_3_BIT_MASK                                                        7U
#define CAN_4_BIT_MASK                                                      0xfU
#define CAN_5_BIT_MASK                                                     0x1fU

#define CAN_B0_BIT_POS                                                        0U
#define CAN_B1_BIT_POS                                                        1U
#define CAN_B2_BIT_POS                                                        2U
#define CAN_B3_BIT_POS                                                        3U
#define CAN_B4_BIT_POS                                                        4U
#define CAN_B5_BIT_POS                                                        5U
#define CAN_B6_BIT_POS                                                        6U
#define CAN_B7_BIT_POS                                                        7U
#define CAN_B8_BIT_POS                                                        8U
#define CAN_B9_BIT_POS                                                        9U
#define CAN_B10_BIT_POS                                                      10U
#define CAN_B11_BIT_POS                                                      11U
#define CAN_B12_BIT_POS                                                      12U
#define CAN_B13_BIT_POS                                                      13U
#define CAN_B14_BIT_POS                                                      14U
#define CAN_B15_BIT_POS                                                      15U

#define RS_CAN_CH0                                                    CAN_ENABLE
#define RS_CAN_CH1                                                    CAN_ENABLE

#define CAN_CHNL_TX_BUF_NUM                                                  16U

#define CAN_CRBRCF0_RX_BUF_NUM                                               32U
#define CAN_CRBRCF1_RX_BUF_NUM                                               32U
#define CAN_CRBRCF2_RX_BUF_NUM                                               32U
#define McalCan_dMaskPageRuleRx                                             0xfU
#define CAN_RX_RULE_PAGE_IDX_BIT_POS                                          4U
#define CAN_RAM_LW_SIZE                                          (0x1C20U >> 2U)
#define CAN_RAM_PAGE_IDX_BIT_POS                                              6U
#define CAN_RAM_DATA_IDX_MASK                                              0x3fU

#define CAN_TBTST_NOT_TRANSMITTING                                            0U
#define CAN_TBTST_TRANSMITTING                                                1U

#define GET_BIT(reg, pos)                                (((reg) >> (pos)) & 1U)
#define SET_BIT(reg, pos)                                 ((reg) |= 1U << (pos))
#define CLR_BIT(reg, pos)                             ((reg) &= ~(1UL << (pos)))

#define CAN_TBTR_BIT_POS                                                      0U
#define CAN_TBAR_BIT_POS                                                      1U
#define CAN_TBOE_BIT_POS                                                      2U

#define CAN_TBCR_TRM                            (CAN_ENABLE << CAN_TBTR_BIT_POS)

static void McalCan_vSetRuleRx(void);

#endif

