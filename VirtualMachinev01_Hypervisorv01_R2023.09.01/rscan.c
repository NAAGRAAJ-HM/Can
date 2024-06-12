#include "Std_Types.hpp"

#include "can_table.hpp"

#include "rscan.hpp"
#include "gpioX.hpp"

void RS_CAN_Init(void){
   protected_write(PROTCMD1,PROTS1,CKSC_ICANOSCD_CTL,0x01u);
   while(CKSC_ICANOSCD_ACT!=0x01);
   protected_write(PROTCMD1,PROTS1,CKSC_ICANS_CTL, 0x03);
   while(CKSC_ICANS_ACT!=0x03);
   GPIO_CanInit();
   while((RSCAN0GSTS & 0x00000008u)){}
   RSCAN0GCTR  &= 0xfffffffbu;
   RSCAN0C0CTR &= 0xfffffffbu;
   RSCAN0GCFG  = 0x00000010u;
   RSCAN0C0CFG = 0x023a0001u;
   McalCan_vSetRuleRx();
   RSCAN0RMNB  = 0x00;
   RSCAN0RFCC0 |= 0x1000;
   RSCAN0RFCC0 |= 0x400;
   RSCAN0RFCC0 |= 0x2;
   RSCAN0GCTR  &= 0xfffff8ffu;
   RSCAN0TMIEC0 = 0x000000ff;
   if(RSCAN0GSTS & 0x03u){
      RSCAN0GCTR &= 0xfffffffcu;
      while((RSCAN0GSTS & 0x02u) == 2u){
      }
      while((RSCAN0GSTS & 0x01u) == 1u){
      }
   }
   if(RSCAN0C0STS & 0x03u){
      RSCAN0C0CTR &= 0xfffffffcu;
      while((RSCAN0C0STS & 0x02u) == 2u){
      }
      while((RSCAN0C0STS & 0x01u) == 1u){
      }
   }
   RSCAN0RFCC0 |= 0x1;
}

void RS_CAN_SetSleepMode(void){
   RSCAN0C0CTR |= 0x2;
   RSCAN0GCTR  |= 0x2;
}

void RS_CAN_SetResetMode(void){
   RSCAN0C0CTR &= ~0x2;
   RSCAN0GCTR  &= ~0x2;
   RSCAN0C0CTR |=  0x1;
   RSCAN0GCTR  |=  0x1;
}

void RS_CAN_SetCommunicationMode(void){
   RSCAN0C0CTR &= ~0x2;
   RSCAN0GCTR  &= ~0x2;
   RSCAN0C0CTR &= ~0x1;
   RSCAN0GCTR  &= ~0x1;
}

Can_RtnType Can_ReadRxFiFo(Can_FrameType* pFrame){
  Can_RtnType tRetVal;
  if((RSCAN0RFSTS0 & 0x1) == 0){
      pFrame->IDE   = (RSCAN0RFID0  & 0x80000000) >> 31;
      pFrame->RTR   = (RSCAN0RFID0  & 0x40000000) >> 30;
      pFrame->THLEN = (RSCAN0RFID0  & 0x20000000) >> 29;
      pFrame->ID    = (RSCAN0RFID0  & 0x1fffffff);
      pFrame->DLC   = (RSCAN0RFPTR0 & 0xf0000000) >> 28;
      pFrame->LBL   = (RSCAN0RFPTR0 & 0x0fff0000) >> 16;
      pFrame->TS    = (RSCAN0RFPTR0 & 0x0000ffff);
      pFrame->DB[7] = (RSCAN0RFDF10 & 0xff000000) >> 24;
      pFrame->DB[6] = (RSCAN0RFDF10 & 0x00ff0000) >> 16;
      pFrame->DB[5] = (RSCAN0RFDF10 & 0x0000ff00) >> 8;
      pFrame->DB[4] = (RSCAN0RFDF10 & 0x000000ff) >> 0;
      pFrame->DB[3] = (RSCAN0RFDF00 & 0xff000000) >> 24;
      pFrame->DB[2] = (RSCAN0RFDF00 & 0x00ff0000) >> 16;
      pFrame->DB[1] = (RSCAN0RFDF00 & 0x0000ff00) >> 8;
      pFrame->DB[0] = (RSCAN0RFDF00 & 0x000000ff) >> 0;
      RSCAN0RFPCTR0 = 0xff;
  }
   if((RSCAN0RFSTS0 & 0x1) == 1){
      tRetVal = CAN_RTN_BUFFER_EMPTY;
   }
   else{
      tRetVal = CAN_RTN_OK;
   }
   return tRetVal;
}

Can_RtnType Can_SendTxBuffer(const Can_FrameType* pFrame){
   static uint8 ucTxBufIdx = 0;
   uint8 ucRetVal;
   VU8* pTBSR;
   VU8* pTBCR;
   Can_FrameType* pTxBuffer;
   pTBSR = &(RSCAN0TMSTS0);
   pTBCR = &(RSCAN0TMC0);
   if((pTBSR[ucTxBufIdx] & (VU8)0x01u) == CAN_TBTST_TRANSMITTING){
      ucRetVal = CAN_RTN_ERR;
   }
   else{
      pTxBuffer = (Can_FrameType*) &(RSCAN0TMID0);
      pTxBuffer[ucTxBufIdx] = *pFrame;
      pTBCR[ucTxBufIdx] = CAN_TBCR_TRM;
      ucRetVal = CAN_RTN_OK;
      ucTxBufIdx++;
      ucTxBufIdx %= CAN_CHNL_TX_BUF_NUM;
   }
   return ucRetVal;
}

void Can_ClearRxFiFoInterruptFlag(void){
   RSCAN0RFSTS0 &= ~0x8;
}

void Can_ClearTxBufferInterruptFlag(void){
   VU8* pTBSR;
   uint8 ucTxBufIdx;
   pTBSR = &(RSCAN0TMSTS0);
   for(ucTxBufIdx = 0; ucTxBufIdx < CAN_CHNL_TX_BUF_NUM; ucTxBufIdx++){
      pTBSR[ucTxBufIdx] = CAN_CLR;
   }
}

static void McalCan_vSetRuleRx(void){
            uint16                 lu16IndexRuleRx;
            uint8                  lu8PageRuleRx;
   volatile Type_McalCan_stRuleRx* pvstRegisterRuleRx;
   RSCAN0GAFLCFG0     |= (CfgMcalCan_dNumRulesRx << 24);
   pvstRegisterRuleRx  = (volatile Type_McalCan_stRuleRx*)&(RSCAN0GAFLID0);
   RSCAN0GAFLECTR     |= 0x00000100u;
   for(
      lu16IndexRuleRx = 0U;
      lu16IndexRuleRx < CfgMcalCan_dNumRulesRx;
      lu16IndexRuleRx ++
   ){
      lu8PageRuleRx = (uint8)(
            lu16IndexRuleRx
         &  McalCan_dMaskPageRuleRx
      );
      if(
            lu8PageRuleRx
         == 0U
      ){
         RSCAN0GAFLECTR |= lu16IndexRuleRx >> CAN_RX_RULE_PAGE_IDX_BIT_POS;
      }
      pvstRegisterRuleRx[lu8PageRuleRx] = CfgMcalCan_castListRulesRx[lu16IndexRuleRx]; //TBD: MemCpy for structures?
   }
   RSCAN0GAFLECTR &= 0xfffffeffu;
}

