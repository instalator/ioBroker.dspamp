
#ifndef _DEF_AD242X_H
#define _DEF_AD242X_H

#define _ADI_MSK(mask, type) ((type)(mask)) /* Make a bitmask */

/* ============================================================================================================================
        AD242x
   ============================================================================================================================ */
#define MOD_AD242X0_BASE                     0x00000000            /*  AD242x  */
#define MOD_AD242X0_MASK                     0x000000FF            /*  AD242x  */
#define REG_AD242X0_PINCFG_RESET             0x00000001            /*      Reset Value for PINCFG  */
#define REG_AD242X0_PINCFG                   0x00000052            /*  AD242x0 Pin Configuration Register */
#define REG_AD242X0_I2SRRATE_RESET           0x00000001            /*      Reset Value for I2SRRATE  */
#define REG_AD242X0_I2SRRATE                 0x00000056            /*  AD242x0 I2S Reduced Rate Register (Master Only, Auto-Broadcast) */
#define REG_AD242X0_I2SRRCTL_RESET           0x00000000            /*      Reset Value for I2SRRCTL  */
#define REG_AD242X0_I2SRRCTL                 0x00000057            /*  AD242x0 I2S Reduced Rate Control Register */
#define REG_AD242X0_I2SRRSOFFS_RESET         0x00000000            /*      Reset Value for I2SRRSOFFS  */
#define REG_AD242X0_I2SRRSOFFS               0x00000058            /*  AD242x0 I2S Reduced Rate SYNC Offset (Slave Only) */
#define REG_AD242X0_SUSCFG_RESET             0x00000000            /*      Reset Value for SUSCFG  */
#define REG_AD242X0_SUSCFG                   0x0000005C            /*  AD242x0 Sustain Configuration Register (Slave Only) */
#define REG_AD242X0_GPIODEN_RESET            0x00000000            /*      Reset Value for GPIODEN  */
#define REG_AD242X0_GPIODEN                  0x00000080            /*  AD242x0 GPIO Over Distance Enable Register */
#define REG_AD242X0_GPIOD0MSK_RESET          0x00000000            /*      Reset Value for GPIOD0MSK  */
#define REG_AD242X0_GPIOD0MSK                0x00000081            /*  AD242x0 GPIO Over Distance Mask 0 Register */
#define REG_AD242X0_GPIOD1MSK_RESET          0x00000000            /*      Reset Value for GPIOD1MSK  */
#define REG_AD242X0_GPIOD1MSK                0x00000082            /*  AD242x0 GPIO Over Distance Mask 1 Register */
#define REG_AD242X0_GPIOD2MSK_RESET          0x00000000            /*      Reset Value for GPIOD2MSK  */
#define REG_AD242X0_GPIOD2MSK                0x00000083            /*  AD242x0 GPIO Over Distance Mask 2 Register */
#define REG_AD242X0_GPIOD3MSK_RESET          0x00000000            /*      Reset Value for GPIOD3MSK  */
#define REG_AD242X0_GPIOD3MSK                0x00000084            /*  AD242x0 GPIO Over Distance Mask 3 Register */
#define REG_AD242X0_GPIOD4MSK_RESET          0x00000000            /*      Reset Value for GPIOD4MSK  */
#define REG_AD242X0_GPIOD4MSK                0x00000085            /*  AD242x0 GPIO Over Distance Mask 4 Register */
#define REG_AD242X0_GPIOD5MSK_RESET          0x00000000            /*      Reset Value for GPIOD5MSK  */
#define REG_AD242X0_GPIOD5MSK                0x00000086            /*  AD242x0 GPIO Over Distance Mask 5 Register */
#define REG_AD242X0_GPIOD6MSK_RESET          0x00000000            /*      Reset Value for GPIOD6MSK  */
#define REG_AD242X0_GPIOD6MSK                0x00000087            /*  AD242x0 GPIO Over Distance Mask 6 Register */
#define REG_AD242X0_GPIOD7MSK_RESET          0x00000000            /*      Reset Value for GPIOD7MSK  */
#define REG_AD242X0_GPIOD7MSK                0x00000088            /*  AD242x0 GPIO Over Distance Mask 7 Register */
#define REG_AD242X0_GPIODDAT_RESET           0x00000000            /*      Reset Value for GPIODDAT  */
#define REG_AD242X0_GPIODDAT                 0x00000089            /*  AD242x0 GPIO Over Distance Data Register */
#define REG_AD242X0_GPIODINV_RESET           0x00000000            /*      Reset Value for GPIODINV  */
#define REG_AD242X0_GPIODINV                 0x0000008A            /*  AD242x0 GPIO Over Distance Invert Register */
#define REG_AD242X0_MBOX0CTL_RESET           0x00000000            /*      Reset Value for MBOX0CTL  */
#define REG_AD242X0_MBOX0CTL                 0x00000090            /*  AD242x0 Mailbox 0 Control Register (Slave Only) */
#define REG_AD242X0_MBOX0STAT_RESET          0x00000002            /*      Reset Value for MBOX0STAT  */
#define REG_AD242X0_MBOX0STAT                0x00000091            /*  AD242x0 Mailbox 0 Status Register (Slave Only) */
#define REG_AD242X0_MBOX0B0_RESET            0x00000000            /*      Reset Value for MBOX0B0  */
#define REG_AD242X0_MBOX0B0                  0x00000092            /*  AD242x0 Mailbox 0 Byte 0 Register (Slave Only) */
#define REG_AD242X0_MBOX0B1_RESET            0x00000000            /*      Reset Value for MBOX0B1  */
#define REG_AD242X0_MBOX0B1                  0x00000093            /*  AD242x0 Mailbox 0 Byte 1 Register (Slave Only) */
#define REG_AD242X0_MBOX0B2_RESET            0x00000000            /*      Reset Value for MBOX0B2  */
#define REG_AD242X0_MBOX0B2                  0x00000094            /*  AD242x0 Mailbox 0 Byte 2 Register (Slave Only) */
#define REG_AD242X0_MBOX0B3_RESET            0x00000000            /*      Reset Value for MBOX0B3  */
#define REG_AD242X0_MBOX0B3                  0x00000095            /*  AD242x0 Mailbox 0 Byte 3 Register (Slave Only) */
#define REG_AD242X0_MBOX1CTL_RESET           0x00000002            /*      Reset Value for MBOX1CTL  */
#define REG_AD242X0_MBOX1CTL                 0x00000096            /*  AD242x0 Mailbox 1 Control Register (Slave Only) */
#define REG_AD242X0_MBOX1STAT_RESET          0x00000002            /*      Reset Value for MBOX1STAT  */
#define REG_AD242X0_MBOX1STAT                0x00000097            /*  AD242x0 Mailbox 1 Status Register (Slave Only) */
#define REG_AD242X0_MBOX1B0_RESET            0x00000000            /*      Reset Value for MBOX1B0  */
#define REG_AD242X0_MBOX1B0                  0x00000098            /*  AD242x0 Mailbox 1 Byte 0 Register (Slave Only) */
#define REG_AD242X0_MBOX1B1_RESET            0x00000000            /*      Reset Value for MBOX1B1  */
#define REG_AD242X0_MBOX1B1                  0x00000099            /*  AD242x0 Mailbox 1 Byte 1 Register (Slave Only) */
#define REG_AD242X0_MBOX1B2_RESET            0x00000000            /*      Reset Value for MBOX1B2  */
#define REG_AD242X0_MBOX1B2                  0x0000009A            /*  AD242x0 Mailbox 1 Byte 2 Register (Slave Only) */
#define REG_AD242X0_MBOX1B3_RESET            0x00000000            /*      Reset Value for MBOX1B3  */
#define REG_AD242X0_MBOX1B3                  0x0000009B            /*  AD242x0 Mailbox 1 Byte 3 Register (Slave Only) */
#define REG_AD242X0_AMSCTL0_RESET            0x00000000            /*      Reset Value for AMSCTL0  */
#define REG_AD242X0_AMSCTL0                  0x000000A0            /*  AD242x0 AMS Control Register 0 */
#define REG_AD242X0_AMSCTL1_RESET            0x00000000            /*      Reset Value for AMSCTL1  */
#define REG_AD242X0_AMSCTL1                  0x000000A1            /*  AD242x0 AMS Control Register 1 */
#define REG_AD242X0_AMSCTL2_RESET            0x00000000            /*      Reset Value for AMSCTL2  */
#define REG_AD242X0_AMSCTL2                  0x000000A2            /*  AD242x0 AMS Control Register 2 */
#define REG_AD242X0_AMSCTL3_RESET            0x00000000            /*      Reset Value for AMSCTL3  */
#define REG_AD242X0_AMSCTL3                  0x000000A3            /*  AD242x0 AMS Control Register 3 */
#define REG_AD242X0_AMSCTL4_RESET            0x00000000            /*      Reset Value for AMSCTL4  */
#define REG_AD242X0_AMSCTL4                  0x000000A4            /*  AD242x0 AMS Control Register 4 */
#define REG_AD242X0_AMSSTAT0_RESET           0x00000000            /*      Reset Value for AMSSTAT0  */
#define REG_AD242X0_AMSSTAT0                 0x000000A5            /*  AD242x0 AMS Status Register 0 */
#define REG_AD242X0_AMSSTAT1_RESET           0x00000000            /*      Reset Value for AMSSTAT1  */
#define REG_AD242X0_AMSSTAT1                 0x000000A6            /*  AD242x0 AMS Status Register 1 */
#define REG_AD242X0_AMSSTAT2_RESET           0x00000000            /*      Reset Value for AMSSTAT2  */
#define REG_AD242X0_AMSSTAT2                 0x000000A7            /*  AD242x0 AMS Status Register 2 */
/* ============================================================================================================================
      A2B_Analog_Tuning Register Definitions
   ============================================================================================================================ */
#define REG_AD242X0_VREGCTL_RESET            0x00000000            /*      Reset Value for VREGCTL  */
#define REG_AD242X0_VREGCTL                  0x0000002D            /*  AD242x0 Voltage Regulator Control Register */
#define REG_AD242X0_TXACTL_RESET             0x00000000            /*      Reset Value for TXACTL  */
#define REG_AD242X0_TXACTL                   0x0000002E            /*  AD242x0 LVDSA TX Control Register */
#define REG_AD242X0_RXACTL_RESET             0x00000000            /*      Reset Value for RXACTL  */
#define REG_AD242X0_RXACTL                   0x0000002F            /*  AD242x0 LVDSA RX Control Register */
#define REG_AD242X0_TXBCTL_RESET             0x00000000            /*      Reset Value for TXBCTL  */
#define REG_AD242X0_TXBCTL                   0x00000030            /*  AD242x0 LVDSB TX Control Register */
#define REG_AD242X0_RXBCTL_RESET             0x00000000            /*      Reset Value for RXBCTL  */
#define REG_AD242X0_RXBCTL                   0x00000031            /*  AD242x0 LVDSB RX Control Register */
/* ============================================================================================================================
      A2B_Config_MO_Auto_Broadcast_Shadowed Register Definitions
   ============================================================================================================================ */
#define REG_AD242X0_SLOTFMT_RESET            0x00000000            /*      Reset Value for SLOTFMT  */
#define REG_AD242X0_SLOTFMT                  0x00000010            /*  AD242x0 Slot Format Register (Master Only, Auto-Broadcast) */
#define REG_AD242X0_DATCTL_RESET             0x00000000            /*      Reset Value for DATCTL  */
#define REG_AD242X0_DATCTL                   0x00000011            /*  AD242x0 Data Control Register (Master Only, Auto-Broadcast) */
/* ============================================================================================================================
      A2B_Config_SO_Shadowed Register Definitions
   ============================================================================================================================ */
#define REG_AD242X0_BCDNSLOTS_RESET          0x00000000            /*      Reset Value for BCDNSLOTS  */
#define REG_AD242X0_BCDNSLOTS                0x0000000A            /*  AD242x0 Broadcast Downstream Slots Register (Slave Only) */
#define REG_AD242X0_LDNSLOTS_RESET           0x00000000            /*      Reset Value for LDNSLOTS  */
#define REG_AD242X0_LDNSLOTS                 0x0000000B            /*  AD242x0 Local Downstream Slots Register (Slave Only) */
#define REG_AD242X0_LUPSLOTS_RESET           0x00000000            /*      Reset Value for LUPSLOTS  */
#define REG_AD242X0_LUPSLOTS                 0x0000000C            /*  AD242x0 Local Upstream Slots Register (Slave Only) */
#define REG_AD242X0_UPOFFSET_RESET           0x00000000            /*      Reset Value for UPOFFSET  */
#define REG_AD242X0_UPOFFSET                 0x00000064            /*  AD242x0 Local Upstream Slots Offset Register (Slave Only) */
#define REG_AD242X0_DNOFFSET_RESET           0x00000000            /*      Reset Value for DNOFFSET  */
#define REG_AD242X0_DNOFFSET                 0x00000069            /*  AD242x0 Local Downstream Slots Offset Register (Slave Only) */
/* ============================================================================================================================
      A2B_Config_Shadowed Register Definitions
   ============================================================================================================================ */
#define REG_AD242X0_DNSLOTS_RESET            0x00000000            /*      Reset Value for DNSLOTS  */
#define REG_AD242X0_DNSLOTS                  0x0000000D            /*  AD242x0 Downstream Slots Register */
#define REG_AD242X0_UPSLOTS_RESET            0x00000000            /*      Reset Value for UPSLOTS  */
#define REG_AD242X0_UPSLOTS                  0x0000000E            /*  AD242x0 Upstream Slots Register */
#define REG_AD242X0_RESPCYCS_RESET           0x00000040            /*      Reset Value for RESPCYCS  */
#define REG_AD242X0_RESPCYCS                 0x0000000F            /*  AD242x0 Response Cycles Register */
#define REG_AD242X0_UPMASK0_RESET            0x00000000            /*      Reset Value for UPMASK0  */
#define REG_AD242X0_UPMASK0                  0x00000060            /*  AD242x0 Upstream Data RX Mask 0 (Slave Only) */
#define REG_AD242X0_UPMASK1_RESET            0x00000000            /*      Reset Value for UPMASK1  */
#define REG_AD242X0_UPMASK1                  0x00000061            /*  AD242x0 Upstream Data RX Mask 1 (Slave Only) */
#define REG_AD242X0_UPMASK2_RESET            0x00000000            /*      Reset Value for UPMASK2  */
#define REG_AD242X0_UPMASK2                  0x00000062            /*  AD242x0 Upstream Data RX Mask 2 (Slave Only) */
#define REG_AD242X0_UPMASK3_RESET            0x00000000            /*      Reset Value for UPMASK3  */
#define REG_AD242X0_UPMASK3                  0x00000063            /*  AD242x0 Upstream Data RX Mask 3 (Slave Only) */
#define REG_AD242X0_DNMASK0_RESET            0x00000000            /*      Reset Value for DNMASK0  */
#define REG_AD242X0_DNMASK0                  0x00000065            /*  AD242x0 Downstream Data RX Mask 0 (Slave Only) */
#define REG_AD242X0_DNMASK1_RESET            0x00000000            /*      Reset Value for DNMASK1  */
#define REG_AD242X0_DNMASK1                  0x00000066            /*  AD242x0 Downstream Data RX Mask 1 (Slave Only) */
#define REG_AD242X0_DNMASK2_RESET            0x00000000            /*      Reset Value for DNMASK2  */
#define REG_AD242X0_DNMASK2                  0x00000067            /*  AD242x0 Downstream Data RX Mask 2 (Slave Only) */
#define REG_AD242X0_DNMASK3_RESET            0x00000000            /*      Reset Value for DNMASK3  */
#define REG_AD242X0_DNMASK3                  0x00000068            /*  AD242x0 Downstream Data RX Mask 3 (Slave Only) */
/* ============================================================================================================================
      A2B_Configuration Register Definitions
   ============================================================================================================================ */
#define REG_AD242X0_SWCTL_RESET              0x00000000            /*      Reset Value for SWCTL  */
#define REG_AD242X0_SWCTL                    0x00000009            /*  AD242x0 Switch Control Register */
#define REG_AD242X0_BMMCFG_RESET             0x00000000            /*      Reset Value for BMMCFG  */
#define REG_AD242X0_BMMCFG                   0x0000005B            /*  AD242x0 Bus Monitor Mode Configuration Register */
/* ============================================================================================================================
      A2B_Control_MO Register Definitions
   ============================================================================================================================ */
#define REG_AD242X0_NODEADR_RESET            0x00000000            /*      Reset Value for NODEADR  */
#define REG_AD242X0_NODEADR                  0x00000001            /*  AD242x0 Node Address Register (Master Only) */
/* ============================================================================================================================
      A2B_Control_MO2 Register Definitions
   ============================================================================================================================ */
#define REG_AD242X0_CONTROL_RESET            0x00000000            /*      Reset Value for CONTROL  */
#define REG_AD242X0_CONTROL                  0x00000012            /*  AD242x0 Control Register */
/* ============================================================================================================================
      A2B_Start_Discovery_MO Register Definitions
   ============================================================================================================================ */
#define REG_AD242X0_DISCVRY_RESET            0x00000000            /*      Reset Value for DISCVRY  */
#define REG_AD242X0_DISCVRY                  0x00000013            /*  AD242x0 Discovery Register (Master Only) */
/* ============================================================================================================================
      A2B_Status Register Definitions
   ============================================================================================================================ */
#define REG_AD242X0_NODE_RESET               0x00000080            /*      Reset Value for NODE  */
#define REG_AD242X0_NODE                     0x00000029            /*  AD242x0 Node Register */
#define REG_AD242X0_TRANSTAT_RESET           0x00000000            /*      Reset Value for TRANSTAT  */
#define REG_AD242X0_TRANSTAT                 0x0000002A            /*  AD242x0 Transfer Status Register (Master Only) */
#define REG_AD242X0_DISCSTAT_RESET           0x00000000            /*      Reset Value for DISCSTAT  */
#define REG_AD242X0_DISCSTAT                 0x0000002B            /*  AD242x0 Discovery Status Register (Master Only) */
#define REG_AD242X0_NSCURCNT_RESET           0x00000000            /*      Reset Value for NSCURCNT  */
#define REG_AD242X0_NSCURCNT                 0x0000002C            /*  AD242x0 New Structure Current Count Register */
/* ============================================================================================================================
      A2B_Status_Registers Register Definitions
   ============================================================================================================================ */
#define REG_AD242X0_SWSTAT_RESET             0x00000000            /*      Reset Value for SWSTAT  */
#define REG_AD242X0_SWSTAT                   0x00000014            /*  AD242x0 Switch Status Register */
/* ============================================================================================================================
      Chip_Test Register Definitions
   ============================================================================================================================ */
#define REG_AD242X0_PTSTMODE_RESET           0x00000000            /*      Reset Value for PTSTMODE  */
#define REG_AD242X0_PTSTMODE                 0x0000003A            /*  AD242x0 Private Testmode Register */
#define REG_AD242X0_STRAPVAL_RESET           0x00000000            /*      Reset Value for STRAPVAL  */
#define REG_AD242X0_STRAPVAL                 0x0000003B            /*  AD242x0 Strap Values Register */
/* ============================================================================================================================
      EFuse Register Definitions
   ============================================================================================================================ */
#define REG_AD242X0_EFUSEADDR_RESET          0x00000000            /*      Reset Value for EFUSEADDR  */
#define REG_AD242X0_EFUSEADDR                0x000000F0            /*  AD242x0 EFuse Address Register */
#define REG_AD242X0_EFUSERDAT_RESET          0x00000000            /*      Reset Value for EFUSERDAT  */
#define REG_AD242X0_EFUSERDAT                0x000000F1            /*  AD242x0 EFuse Read Data Register */
#define REG_AD242X0_EFUSEWDAT_RESET          0x00000000            /*      Reset Value for EFUSEWDAT  */
#define REG_AD242X0_EFUSEWDAT                0x000000F2            /*  AD242x0 EFuse Write Data Register */
/* ============================================================================================================================
      I2C_Control_SO Register Definitions
   ============================================================================================================================ */
#define REG_AD242X0_CHIP_RESET               0x00000050            /*      Reset Value for CHIP  */
#define REG_AD242X0_CHIP                     0x00000000            /*  AD242x0 I2C Chip Address Register (Slave Only) */
/* ============================================================================================================================
      I2C_I2S_PDM_Control_Configuration Register Definitions
   ============================================================================================================================ */
#define REG_AD242X0_I2CCFG_RESET             0x00000000            /*      Reset Value for I2CCFG  */
#define REG_AD242X0_I2CCFG                   0x0000003F            /*  AD242x0 I2C Configuration Register */
#define REG_AD242X0_PLLCTL_RESET             0x00000000            /*      Reset Value for PLLCTL  */
#define REG_AD242X0_PLLCTL                   0x00000040            /*  AD242x0 PLL Control Register (Master Only) */
#define REG_AD242X0_I2SGCFG_RESET            0x00000000            /*      Reset Value for I2SGCFG  */
#define REG_AD242X0_I2SGCFG                  0x00000041            /*  AD242x0 I2S Global Configuration Register */
#define REG_AD242X0_I2SCFG_RESET             0x00000000            /*      Reset Value for I2SCFG  */
#define REG_AD242X0_I2SCFG                   0x00000042            /*  AD242x0 I2S Configuration Register */
#define REG_AD242X0_I2SRATE_RESET            0x00000000            /*      Reset Value for I2SRATE  */
#define REG_AD242X0_I2SRATE                  0x00000043            /*  AD242x0 I2S Rate Register (Slave Only) */
#define REG_AD242X0_I2STXOFFSET_RESET        0x00000000            /*      Reset Value for I2STXOFFSET  */
#define REG_AD242X0_I2STXOFFSET              0x00000044            /*  AD242x0 I2S Transmit Data Offset Register (Master Only) */
#define REG_AD242X0_I2SRXOFFSET_RESET        0x00000000            /*      Reset Value for I2SRXOFFSET  */
#define REG_AD242X0_I2SRXOFFSET              0x00000045            /*  AD242x0 I2S Receive Data Offset Register (Master Only) */
#define REG_AD242X0_SYNCOFFSET_RESET         0x00000000            /*      Reset Value for SYNCOFFSET  */
#define REG_AD242X0_SYNCOFFSET               0x00000046            /*  AD242x0 SYNC Offset Register (Slave Only) */
#define REG_AD242X0_PDMCTL_RESET             0x00000000            /*      Reset Value for PDMCTL  */
#define REG_AD242X0_PDMCTL                   0x00000047            /*  AD242x0 PDM Control Register */
#define REG_AD242X0_ERRMGMT_RESET            0x00000000            /*      Reset Value for ERRMGMT  */
#define REG_AD242X0_ERRMGMT                  0x00000048            /*  AD242x0 Error Management Register */
#define REG_AD242X0_I2STEST_RESET            0x00000000            /*      Reset Value for I2STEST  */
#define REG_AD242X0_I2STEST                  0x00000053            /*  AD242x0 I2S Test Register */
/* ============================================================================================================================
      ID_Registers Register Definitions
   ============================================================================================================================ */
#define REG_AD242X0_VENDOR_RESET             0x000000AD            /*      Reset Value for VENDOR  */
#define REG_AD242X0_VENDOR                   0x00000002            /*  AD242x0 Vendor ID Register */
#define REG_AD242X0_PRODUCT_RESET            0x00000025            /*      Reset Value for PRODUCT  */
#define REG_AD242X0_PRODUCT                  0x00000003            /*  AD242x0 Product ID Register */
#define REG_AD242X0_VERSION_RESET            0x00000000            /*      Reset Value for VERSION  */
#define REG_AD242X0_VERSION                  0x00000004            /*  AD242x0 Version ID Register */
#define REG_AD242X0_CAPABILITY_RESET         0x00000001            /*      Reset Value for CAPABILITY  */
#define REG_AD242X0_CAPABILITY               0x00000005            /*  AD242x0 Capability ID Register */
/* ============================================================================================================================
      Interrupt_Error_Registers Register Definitions
   ============================================================================================================================ */
#define REG_AD242X0_INTSTAT_RESET            0x00000000            /*      Reset Value for INTSTAT  */
#define REG_AD242X0_INTSTAT                  0x00000015            /*  AD242x0 Interrupt Status Register */
#define REG_AD242X0_INTSRC_RESET             0x00000000            /*      Reset Value for INTSRC  */
#define REG_AD242X0_INTSRC                   0x00000016            /*  AD242x0 Interrupt Source Register (Master Only) */
#define REG_AD242X0_INTTYPE_RESET            0x00000000            /*      Reset Value for INTTYPE  */
#define REG_AD242X0_INTTYPE                  0x00000017            /*  AD242x0 Interrupt Type Register (Master Only) */
#define REG_AD242X0_INTPND0_RESET            0x00000000            /*      Reset Value for INTPND0  */
#define REG_AD242X0_INTPND0                  0x00000018            /*  AD242x0 Interrupt Pending 0 Register */
#define REG_AD242X0_INTPND1_RESET            0x00000000            /*      Reset Value for INTPND1  */
#define REG_AD242X0_INTPND1                  0x00000019            /*  AD242x0 Interrupt Pending 1 Register */
#define REG_AD242X0_INTPND2_RESET            0x00000000            /*      Reset Value for INTPND2  */
#define REG_AD242X0_INTPND2                  0x0000001A            /*  AD242x0 Interrupt Pending 2 Register (Master Only) */
#define REG_AD242X0_INTMSK0_RESET            0x00000000            /*      Reset Value for INTMSK0  */
#define REG_AD242X0_INTMSK0                  0x0000001B            /*  AD242x0 Interrupt Mask 0 Register */
#define REG_AD242X0_INTMSK1_RESET            0x00000000            /*      Reset Value for INTMSK1  */
#define REG_AD242X0_INTMSK1                  0x0000001C            /*  AD242x0 Interrupt Mask 1 Register */
#define REG_AD242X0_INTMSK2_RESET            0x00000000            /*      Reset Value for INTMSK2  */
#define REG_AD242X0_INTMSK2                  0x0000001D            /*  AD242x0 Interrupt Mask 2 Register (Master Only) */
#define REG_AD242X0_BECCTL_RESET             0x00000000            /*      Reset Value for BECCTL  */
#define REG_AD242X0_BECCTL                   0x0000001E            /*  AD242x0 Bit Error Count Control Register */
#define REG_AD242X0_BECNT_RESET              0x00000000            /*      Reset Value for BECNT  */
#define REG_AD242X0_BECNT                    0x0000001F            /*  AD242x0 Bit Error Count Register */
#define REG_AD242X0_LINTTYPE_RESET           0x00000000            /*      Reset Value for LINTTYPE  */
#define REG_AD242X0_LINTTYPE                 0x0000003E            /*  AD242x0 Local Interrupt Type (Slave Only) */
#define REG_AD242X0_RAISE_RESET              0x00000000            /*      Reset Value for RAISE  */
#define REG_AD242X0_RAISE                    0x00000054            /*  AD242x0 Raise Interrupt Register */
#define REG_AD242X0_GENERR_RESET             0x00000000            /*      Reset Value for GENERR  */
#define REG_AD242X0_GENERR                   0x00000055            /*  AD242x0 Generate Bus Error */
/* ============================================================================================================================
      PRBS_Test Register Definitions
   ============================================================================================================================ */
#define REG_AD242X0_TESTMODE_RESET           0x00000000            /*      Reset Value for TESTMODE  */
#define REG_AD242X0_TESTMODE                 0x00000020            /*  AD242x0 Testmode Register */
#define REG_AD242X0_ERRCNT0_RESET            0x00000000            /*      Reset Value for ERRCNT0  */
#define REG_AD242X0_ERRCNT0                  0x00000021            /*  AD242x0 PRBS Error Count Byte 0 Register */
#define REG_AD242X0_ERRCNT1_RESET            0x00000000            /*      Reset Value for ERRCNT1  */
#define REG_AD242X0_ERRCNT1                  0x00000022            /*  AD242x0 PRBS Error Count Byte 1 Register */
#define REG_AD242X0_ERRCNT2_RESET            0x00000000            /*      Reset Value for ERRCNT2  */
#define REG_AD242X0_ERRCNT2                  0x00000023            /*  AD242x0 PRBS Error Count Byte 2 Register */
#define REG_AD242X0_ERRCNT3_RESET            0x00000000            /*      Reset Value for ERRCNT3  */
#define REG_AD242X0_ERRCNT3                  0x00000024            /*  AD242x0 PRBS Error Count Byte 3 Register */
#define REG_AD242X0_SEED0_RESET              0x00000079            /*      Reset Value for SEED0  */
#define REG_AD242X0_SEED0                    0x00000025            /*  AD242x0 PRBS Seed Byte 0 Register */
#define REG_AD242X0_SEED1_RESET              0x00000000            /*      Reset Value for SEED1  */
#define REG_AD242X0_SEED1                    0x00000026            /*  AD242x0 PRBS Seed Byte 1 Register */
#define REG_AD242X0_SEED2_RESET              0x00000000            /*      Reset Value for SEED2  */
#define REG_AD242X0_SEED2                    0x00000027            /*  AD242x0 PRBS Seed Byte 2 Register */
#define REG_AD242X0_SEED3_RESET              0x00000000            /*      Reset Value for SEED3  */
#define REG_AD242X0_SEED3                    0x00000028            /*  AD242x0 PRBS Seed Byte 3 Register */
/* ============================================================================================================================
      Pin_IO_Interrupt_Registers Register Definitions
   ============================================================================================================================ */
#define REG_AD242X0_GPIODAT_RESET            0x00000000            /*      Reset Value for GPIODAT  */
#define REG_AD242X0_GPIODAT                  0x0000004A            /*  AD242x0 GPIO Output Data Register */
#define REG_AD242X0_GPIODATSET_RESET         0x00000000            /*      Reset Value for GPIODATSET  */
#define REG_AD242X0_GPIODATSET               0x0000004B            /*  AD242x0 GPIO Output Data Set Register */
#define REG_AD242X0_GPIODATCLR_RESET         0x00000000            /*      Reset Value for GPIODATCLR  */
#define REG_AD242X0_GPIODATCLR               0x0000004C            /*  AD242x0 GPIO Output Data Clear Register */
#define REG_AD242X0_GPIOOEN_RESET            0x00000000            /*      Reset Value for GPIOOEN  */
#define REG_AD242X0_GPIOOEN                  0x0000004D            /*  AD242x0 GPIO Output Enable Register */
#define REG_AD242X0_GPIOIEN_RESET            0x00000000            /*      Reset Value for GPIOIEN  */
#define REG_AD242X0_GPIOIEN                  0x0000004E            /*  AD242x0 GPIO Input Enable Register */
#define REG_AD242X0_GPIOIN_RESET             0x00000000            /*      Reset Value for GPIOIN  */
#define REG_AD242X0_GPIOIN                   0x0000004F            /*  AD242x0 GPIO Input Value Register */
#define REG_AD242X0_PINTEN_RESET             0x00000000            /*      Reset Value for PINTEN  */
#define REG_AD242X0_PINTEN                   0x00000050            /*  AD242x0 Pin Interrupt Enable Register */
#define REG_AD242X0_PINTINV_RESET            0x00000000            /*      Reset Value for PINTINV  */
#define REG_AD242X0_PINTINV                  0x00000051            /*  AD242x0 Pin Interrupt Invert Register */
#define REG_AD242X0_CLK1CFG_RESET            0x00000000            /*      Reset Value for CLK1CFG  */
#define REG_AD242X0_CLK1CFG                  0x00000059            /*  AD242x0 CLKOUT1 Configuration Register */
#define REG_AD242X0_CLK2CFG_RESET            0x00000000            /*      Reset Value for CLK2CFG  */
#define REG_AD242X0_CLK2CFG                  0x0000005A            /*  AD242x0 CLKOUT2 Configuration Register */
/* ============================================================================================================================
      Shadow_Register_Committed_Copy_Read_Access Register Definitions
   ============================================================================================================================ */
#define REG_AD242X0_RESPCCC_RESET            0x00000040            /*      Reset Value for RESPCCC  */
#define REG_AD242X0_RESPCCC                  0x00000032            /*  AD242x0 Response Cycles Committed Copy Register */
#define REG_AD242X0_DCTLCC_RESET             0x00000000            /*      Reset Value for DCTLCC  */
#define REG_AD242X0_DCTLCC                   0x00000033            /*  AD242x0 Data Control Committed Copy Register */
#define REG_AD242X0_DNSCC_RESET              0x00000000            /*      Reset Value for DNSCC  */
#define REG_AD242X0_DNSCC                    0x00000034            /*  AD242x0 Downstream Slots Committed Copy Register */
#define REG_AD242X0_LDNSCC_RESET             0x00000000            /*      Reset Value for LDNSCC  */
#define REG_AD242X0_LDNSCC                   0x00000035            /*  AD242x0 Local Downstream Slots Committed Copy Register (Slave Only) */
#define REG_AD242X0_UPSCC_RESET              0x00000000            /*      Reset Value for UPSCC  */
#define REG_AD242X0_UPSCC                    0x00000036            /*  AD242x0 Upstream Slots Committed Copy Register */
#define REG_AD242X0_LUPSCC_RESET             0x00000000            /*      Reset Value for LUPSCC  */
#define REG_AD242X0_LUPSCC                   0x00000037            /*  AD242x0 Local Upstream Slots Committed Copy Register (Slave Only) */
#define REG_AD242X0_BCDNSCC_RESET            0x00000000            /*      Reset Value for BCDNSCC  */
#define REG_AD242X0_BCDNSCC                  0x00000038            /*  AD242x0 Brcst Downstream Slots Committed Copy Register (Slave Only) */
#define REG_AD242X0_SFMTCC_RESET             0x00000000            /*      Reset Value for SFMTCC  */
#define REG_AD242X0_SFMTCC                   0x00000039            /*  AD242x0 Slot Format Committed Copy Register */
#define REG_AD242X0_UMSK0CC_RESET            0x00000000            /*      Reset Value for UMSK0CC  */
#define REG_AD242X0_UMSK0CC                  0x00000070            /*  AD242x0 Upstream Data RX Mask 0 Committed Copy Register */
#define REG_AD242X0_UMSK1CC_RESET            0x00000000            /*      Reset Value for UMSK1CC  */
#define REG_AD242X0_UMSK1CC                  0x00000071            /*  AD242x0 Upstream Data RX Mask 1 Committed Copy Register */
#define REG_AD242X0_UMSK2CC_RESET            0x00000000            /*      Reset Value for UMSK2CC  */
#define REG_AD242X0_UMSK2CC                  0x00000072            /*  AD242x0 Upstream Data RX Mask 2 Committed Copy Register */
#define REG_AD242X0_UMSK3CC_RESET            0x00000000            /*      Reset Value for UMSK3CC  */
#define REG_AD242X0_UMSK3CC                  0x00000073            /*  AD242x0 Upstream Data RX Mask 3 Committed Copy Register */
#define REG_AD242X0_UOFFSCC_RESET            0x00000000            /*      Reset Value for UOFFSCC  */
#define REG_AD242X0_UOFFSCC                  0x00000074            /*  AD242x0 Local Upstream Slots Offset Committed Copy Register */
#define REG_AD242X0_DMSK0CC_RESET            0x00000000            /*      Reset Value for DMSK0CC  */
#define REG_AD242X0_DMSK0CC                  0x00000075            /*  AD242x0 Downstream Data RX Mask 0 Committed Copy Register */
#define REG_AD242X0_DMSK1CC_RESET            0x00000000            /*      Reset Value for DMSK1CC  */
#define REG_AD242X0_DMSK1CC                  0x00000076            /*  AD242x0 Downstream Data RX Mask 1 Committed Copy Register */
#define REG_AD242X0_DMSK2CC_RESET            0x00000000            /*      Reset Value for DMSK2CC  */
#define REG_AD242X0_DMSK2CC                  0x00000077            /*  AD242x0 Downstream Data RX Mask 2 Committed Copy Register */
#define REG_AD242X0_DMSK3CC_RESET            0x00000000            /*      Reset Value for DMSK3CC  */
#define REG_AD242X0_DMSK3CC                  0x00000078            /*  AD242x0 Downstream Data RX Mask 3 Committed Copy Register */
#define REG_AD242X0_DOFFSCC_RESET            0x00000000            /*      Reset Value for DOFFSCC  */
#define REG_AD242X0_DOFFSCC                  0x00000079            /*  AD242x0 Local Downstream Slots Offset Committed Copy Register */

/* ============================================================================================================================
        AD242x Register BitMasks, Positions & Enumerations 
   ============================================================================================================================ */
/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_PINCFG                        Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_PINCFG_IRQTS              5            /*  Tristate IRQ */
#define BITP_AD242X_PINCFG_IRQINV             4            /*  Invert IRQ */
#define BITP_AD242X_PINCFG_TXBLP              2            /*  LVDS XCVRB Low Power TX Mode */
#define BITP_AD242X_PINCFG_TXALP              1            /*  LVDS XCVRA Low Power TX Mode */
#define BITP_AD242X_PINCFG_DRVSTR             0            /*  Digital Pin Drive Strength */
#define BITL_AD242X_PINCFG_DRVSTR             1            /*  Digital Pin Drive Strength */
#define BITL_AD242X_PINCFG_IRQINV             1            /*  Invert IRQ */
#define BITL_AD242X_PINCFG_IRQTS              1            /*  Tristate IRQ */
#define BITL_AD242X_PINCFG_TXALP              1            /*  LVDS XCVRA Low Power TX Mode */
#define BITL_AD242X_PINCFG_TXBLP              1            /*  LVDS XCVRB Low Power TX Mode */

#define BITM_AD242X_PINCFG_IRQTS             0x00000020    /*  Tristate IRQ */

#define BITM_AD242X_PINCFG_IRQINV            0x00000010    /*  Invert IRQ */

#define BITM_AD242X_PINCFG_TXBLP             0x00000004    /*  LVDS XCVRB Low Power TX Mode */

#define BITM_AD242X_PINCFG_TXALP             0x00000002    /*  LVDS XCVRA Low Power TX Mode */

#define BITM_AD242X_PINCFG_DRVSTR            0x00000001    /*  Digital Pin Drive Strength */
#define ENUM_AD242X_PINCFG_IRQTS_DIS         0x00000000            /*  IRQTS: IRQ Tristate Disabled (IRQ Always Driven) */
#define ENUM_AD242X_PINCFG_IRQTS_EN          0x00000020            /*  IRQTS: IRQ Tristate Enabled (IRQ Only Driven when Active) */
#define ENUM_AD242X_PINCFG_IRQINV_DIS        0x00000000            /*  IRQINV: IRQ Invert Disabled (IRQ Active High) */
#define ENUM_AD242X_PINCFG_IRQINV_EN         0x00000010            /*  IRQINV: IRQ Invert Enabled (IRQ Active Low) */

/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_I2SRRATE                      Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_I2SRRATE_RBUS             7            /*  Reduce Data Rate on A2B Bus */
#define BITP_AD242X_I2SRRATE_RRDIV            0            /*  System-level Reduced Rate Divide */
#define BITL_AD242X_I2SRRATE_RRDIV            6            /*  System-level Reduced Rate Divide */
#define BITL_AD242X_I2SRRATE_RBUS             1            /*  Reduce Data Rate on A2B Bus */

#define BITM_AD242X_I2SRRATE_RBUS            0x00000080    /*  Reduce Data Rate on A2B Bus */

#define BITM_AD242X_I2SRRATE_RRDIV           0x0000003F    /*  System-level Reduced Rate Divide */
#define ENUM_AD242X_I2SRRATE_RBUS_DIS        0x00000000            /*  RBUS: Reduced Data Rate on A2B Bus Disabled */
#define ENUM_AD242X_I2SRRATE_RBUS_EN         0x00000080            /*  RBUS: Reduced Data Rate on A2B Bus Enabled */
#define ENUM_AD242X_I2SRRATE_RRDIV_1         0x00000001            /*  RRDIV: RRDIV eq 1 */
#define ENUM_AD242X_I2SRRATE_RRDIV_2         0x00000002            /*  RRDIV: RRDIV eq 2 */
#define ENUM_AD242X_I2SRRATE_RRDIV_4         0x00000004            /*  RRDIV: RRDIV eq 4 */
#define ENUM_AD242X_I2SRRATE_RRDIV_8         0x00000008            /*  RRDIV: RRDIV eq 8 */
#define ENUM_AD242X_I2SRRATE_RRDIV_12        0x0000000C            /*  RRDIV: RRDIV eq 12 */
#define ENUM_AD242X_I2SRRATE_RRDIV_16        0x00000010            /*  RRDIV: RRDIV eq 16 */
#define ENUM_AD242X_I2SRRATE_RRDIV_20        0x00000014            /*  RRDIV: RRDIV eq 20 */
#define ENUM_AD242X_I2SRRATE_RRDIV_24        0x00000018            /*  RRDIV: RRDIV eq 24 */
#define ENUM_AD242X_I2SRRATE_RRDIV_28        0x0000001C            /*  RRDIV: RRDIV eq 28 */
#define ENUM_AD242X_I2SRRATE_RRDIV_32        0x00000020            /*  RRDIV: RRDIV eq 32 */

/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_I2SRRCTL                      Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_I2SRRCTL_ENCHAN           6            /*  Enable I2S Reduced Rate Valid Bits in Extra I2S Channel */
#define BITP_AD242X_I2SRRCTL_STRBDIR          5            /*  I2S Reduced Rate Strobe Direction */
#define BITP_AD242X_I2SRRCTL_ENSTRB           4            /*  Enable I2S Reduced Rate Strobe */
#define BITP_AD242X_I2SRRCTL_ENXBIT           1            /*  Enable I2S Reduced Rate Valid Bit in Extra Bit */
#define BITP_AD242X_I2SRRCTL_ENVLSB           0            /*  Enable I2S Reduced Rate Valid Bit in LSB */
#define BITL_AD242X_I2SRRCTL_ENCHAN           1            /*  Enable I2S Reduced Rate Valid Bits in Extra I2S Channel */
#define BITL_AD242X_I2SRRCTL_ENSTRB           1            /*  Enable I2S Reduced Rate Strobe */
#define BITL_AD242X_I2SRRCTL_ENVLSB           1            /*  Enable I2S Reduced Rate Valid Bit in LSB */
#define BITL_AD242X_I2SRRCTL_ENXBIT           1            /*  Enable I2S Reduced Rate Valid Bit in Extra Bit */
#define BITL_AD242X_I2SRRCTL_STRBDIR          1            /*  I2S Reduced Rate Strobe Direction */
#define BITM_AD242X_I2SRRCTL_ENCHAN          0x00000040    /*  Enable I2S Reduced Rate Valid Bits in Extra I2S Channel */
#define BITM_AD242X_I2SRRCTL_STRBDIR         0x00000020    /*  I2S Reduced Rate Strobe Direction */
#define BITM_AD242X_I2SRRCTL_ENSTRB          0x00000010    /*  Enable I2S Reduced Rate Strobe */
#define BITM_AD242X_I2SRRCTL_ENXBIT          0x00000002    /*  Enable I2S Reduced Rate Valid Bit in Extra Bit */
#define BITM_AD242X_I2SRRCTL_ENVLSB          0x00000001    /*  Enable I2S Reduced Rate Valid Bit in LSB */

/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_I2SRRSOFFS                    Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_I2SRRSOFFS_RRSOFFSET      0            /*  I2S Reduced Rate SYNC Offset Value */
#define BITL_AD242X_I2SRRSOFFS_RRSOFFSET      2            /*  I2S Reduced Rate SYNC Offset Value */
#define BITM_AD242X_I2SRRSOFFS_RRSOFFSET     0x00000003    /*  I2S Reduced Rate SYNC Offset Value */

/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_SUSCFG                        Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_SUSCFG_SUSDIS             5            /*  Sustain Disable */
#define BITP_AD242X_SUSCFG_SUSOE              4            /*  Sustain GPIO Output Enable */
#define BITP_AD242X_SUSCFG_SUSSEL             0            /*  Sustain GPIO Output Select */
#define BITL_AD242X_SUSCFG_SUSSEL             3            /*  Sustain GPIO Output Select */
#define BITL_AD242X_SUSCFG_SUSDIS             1            /*  Sustain Disable */
#define BITL_AD242X_SUSCFG_SUSOE              1            /*  Sustain GPIO Output Enable */

#define BITM_AD242X_SUSCFG_SUSDIS            0x00000020    /*  Sustain Disable */

#define BITM_AD242X_SUSCFG_SUSOE             0x00000010    /*  Sustain GPIO Output Enable */
#define BITM_AD242X_SUSCFG_SUSSEL            0x00000007    /*  Sustain GPIO Output Select */
#define ENUM_AD242X_SUSCFG_SUSDIS_DIS        0x00000000            /*  SUSDIS: Sustain Enabled */
#define ENUM_AD242X_SUSCFG_SUSDIS_EN         0x00000020            /*  SUSDIS: Sustain Disabled */
#define ENUM_AD242X_SUSCFG_SUSOE_DIS         0x00000000            /*  SUSOE: Sustain Output on GPIO Disabled */
#define ENUM_AD242X_SUSCFG_SUSOE_EN          0x00000010            /*  SUSOE: Sustain Output on GPIO Enabled */

/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_GPIODEN                       Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_GPIODEN_IOD7EN            7            /*  GPIO Over Distance IO7 Enable */
#define BITP_AD242X_GPIODEN_IOD6EN            6            /*  GPIO Over Distance IO6 Enable */
#define BITP_AD242X_GPIODEN_IOD5EN            5            /*  GPIO Over Distance IO5 Enable */
#define BITP_AD242X_GPIODEN_IOD4EN            4            /*  GPIO Over Distance IO4 Enable */
#define BITP_AD242X_GPIODEN_IOD3EN            3            /*  GPIO Over Distance IO3 Enable */
#define BITP_AD242X_GPIODEN_IOD2EN            2            /*  GPIO Over Distance IO2 Enable */
#define BITP_AD242X_GPIODEN_IOD1EN            1            /*  GPIO Over Distance IO1 Enable */
#define BITP_AD242X_GPIODEN_IOD0EN            0            /*  GPIO Over Distance IO0 Enable */
#define BITL_AD242X_GPIODEN_IOD0EN            1            /*  GPIO Over Distance IO0 Enable */
#define BITL_AD242X_GPIODEN_IOD1EN            1            /*  GPIO Over Distance IO1 Enable */
#define BITL_AD242X_GPIODEN_IOD2EN            1            /*  GPIO Over Distance IO2 Enable */
#define BITL_AD242X_GPIODEN_IOD3EN            1            /*  GPIO Over Distance IO3 Enable */
#define BITL_AD242X_GPIODEN_IOD4EN            1            /*  GPIO Over Distance IO4 Enable */
#define BITL_AD242X_GPIODEN_IOD5EN            1            /*  GPIO Over Distance IO5 Enable */
#define BITL_AD242X_GPIODEN_IOD6EN            1            /*  GPIO Over Distance IO6 Enable */
#define BITL_AD242X_GPIODEN_IOD7EN            1            /*  GPIO Over Distance IO7 Enable */

#define BITM_AD242X_GPIODEN_IOD7EN           0x00000080    /*  GPIO Over Distance IO7 Enable */

#define BITM_AD242X_GPIODEN_IOD6EN           0x00000040    /*  GPIO Over Distance IO6 Enable */

#define BITM_AD242X_GPIODEN_IOD5EN           0x00000020    /*  GPIO Over Distance IO5 Enable */

#define BITM_AD242X_GPIODEN_IOD4EN           0x00000010    /*  GPIO Over Distance IO4 Enable */

#define BITM_AD242X_GPIODEN_IOD3EN           0x00000008    /*  GPIO Over Distance IO3 Enable */

#define BITM_AD242X_GPIODEN_IOD2EN           0x00000004    /*  GPIO Over Distance IO2 Enable */

#define BITM_AD242X_GPIODEN_IOD1EN           0x00000002    /*  GPIO Over Distance IO1 Enable */

#define BITM_AD242X_GPIODEN_IOD0EN           0x00000001    /*  GPIO Over Distance IO0 Enable */
#define ENUM_AD242X_GPIODEN_IOD7EN_DIS       0x00000000            /*  IOD7EN: GPIO Over Distance for IO7 Disabled */
#define ENUM_AD242X_GPIODEN_IOD7EN_EN        0x00000080            /*  IOD7EN: GPIO Over Distance for IO7 Enabled */
#define ENUM_AD242X_GPIODEN_IOD6EN_DIS       0x00000000            /*  IOD6EN: GPIO Over Distance for IO6 Disabled */
#define ENUM_AD242X_GPIODEN_IOD6EN_EN        0x00000040            /*  IOD6EN: GPIO Over Distance for IO6 Enabled */
#define ENUM_AD242X_GPIODEN_IOD5EN_DIS       0x00000000            /*  IOD5EN: GPIO Over Distance for IO5 Disabled */
#define ENUM_AD242X_GPIODEN_IOD5EN_EN        0x00000020            /*  IOD5EN: GPIO Over Distance for IO5 Enabled */
#define ENUM_AD242X_GPIODEN_IOD4EN_DIS       0x00000000            /*  IOD4EN: GPIO Over Distance for IO4 Disabled */
#define ENUM_AD242X_GPIODEN_IOD4EN_EN        0x00000010            /*  IOD4EN: GPIO Over Distance for IO4 Enabled */
#define ENUM_AD242X_GPIODEN_IOD3EN_DIS       0x00000000            /*  IOD3EN: GPIO Over Distance for IO3 Disabled */
#define ENUM_AD242X_GPIODEN_IOD3EN_EN        0x00000008            /*  IOD3EN: GPIO Over Distance for IO3 Enabled */
#define ENUM_AD242X_GPIODEN_IOD2EN_DIS       0x00000000            /*  IOD2EN: GPIO Over Distance for IO2 Disabled */
#define ENUM_AD242X_GPIODEN_IOD2EN_EN        0x00000004            /*  IOD2EN: GPIO Over Distance for IO2 Enabled */
#define ENUM_AD242X_GPIODEN_IOD1EN_DIS       0x00000000            /*  IOD1EN: GPIO Over Distance for IO1 Disabled */
#define ENUM_AD242X_GPIODEN_IOD1EN_EN        0x00000002            /*  IOD1EN: GPIO Over Distance for IO1 Enabled */
#define ENUM_AD242X_GPIODEN_IOD0EN_DIS       0x00000000            /*  IOD0EN: GPIO Over Distance for IO0 Disabled */
#define ENUM_AD242X_GPIODEN_IOD0EN_EN        0x00000001            /*  IOD0EN: GPIO Over Distance for IO0 Enabled */

/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_GPIOD0MSK                     Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_GPIOD0MSK_IOD0MSK         0            /*  GPIO Over Distance IO0 Mask */
#define BITL_AD242X_GPIOD0MSK_IOD0MSK         8            /*  GPIO Over Distance IO0 Mask */
#define BITM_AD242X_GPIOD0MSK_IOD0MSK        0x000000FF    /*  GPIO Over Distance IO0 Mask */

/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_GPIOD1MSK                     Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_GPIOD1MSK_IOD1MSK         0            /*  GPIO Over Distance IO1 Mask */
#define BITL_AD242X_GPIOD1MSK_IOD1MSK         8            /*  GPIO Over Distance IO1 Mask */
#define BITM_AD242X_GPIOD1MSK_IOD1MSK        0x000000FF    /*  GPIO Over Distance IO1 Mask */

/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_GPIOD2MSK                     Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_GPIOD2MSK_IOD2MSK         0            /*  GPIO Over Distance IO2 Mask */
#define BITL_AD242X_GPIOD2MSK_IOD2MSK         8            /*  GPIO Over Distance IO2 Mask */
#define BITM_AD242X_GPIOD2MSK_IOD2MSK        0x000000FF    /*  GPIO Over Distance IO2 Mask */

/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_GPIOD3MSK                     Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_GPIOD3MSK_IOD3MSK         0            /*  GPIO Over Distance IO3 Mask */
#define BITL_AD242X_GPIOD3MSK_IOD3MSK         8            /*  GPIO Over Distance IO3 Mask */
#define BITM_AD242X_GPIOD3MSK_IOD3MSK        0x000000FF    /*  GPIO Over Distance IO3 Mask */

/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_GPIOD4MSK                     Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_GPIOD4MSK_IOD4MSK         0            /*  GPIO Over Distance IO4 Mask */
#define BITL_AD242X_GPIOD4MSK_IOD4MSK         8            /*  GPIO Over Distance IO4 Mask */
#define BITM_AD242X_GPIOD4MSK_IOD4MSK        0x000000FF    /*  GPIO Over Distance IO4 Mask */

/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_GPIOD5MSK                     Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_GPIOD5MSK_IOD5MSK         0            /*  GPIO Over Distance IO5 Mask */
#define BITL_AD242X_GPIOD5MSK_IOD5MSK         8            /*  GPIO Over Distance IO5 Mask */
#define BITM_AD242X_GPIOD5MSK_IOD5MSK        0x000000FF    /*  GPIO Over Distance IO5 Mask */

/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_GPIOD6MSK                     Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_GPIOD6MSK_IOD6MSK         0            /*  GPIO Over Distance IO6 Mask */
#define BITL_AD242X_GPIOD6MSK_IOD6MSK         8            /*  GPIO Over Distance IO6 Mask */
#define BITM_AD242X_GPIOD6MSK_IOD6MSK        0x000000FF    /*  GPIO Over Distance IO6 Mask */

/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_GPIOD7MSK                     Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_GPIOD7MSK_IOD7MSK         0            /*  GPIO Over Distance IO7 Mask */
#define BITL_AD242X_GPIOD7MSK_IOD7MSK         8            /*  GPIO Over Distance IO7 Mask */
#define BITM_AD242X_GPIOD7MSK_IOD7MSK        0x000000FF    /*  GPIO Over Distance IO7 Mask */

/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_GPIODDAT                      Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_GPIODDAT_IOD7DAT          7            /*  Bus GPIO Port Bit 7 Value */
#define BITP_AD242X_GPIODDAT_IOD6DAT          6            /*  Bus GPIO Port Bit 6 Value */
#define BITP_AD242X_GPIODDAT_IOD5DAT          5            /*  Bus GPIO Port Bit 5 Value */
#define BITP_AD242X_GPIODDAT_IOD4DAT          4            /*  Bus GPIO Port Bit 4 Value */
#define BITP_AD242X_GPIODDAT_IOD3DAT          3            /*  Bus GPIO Port Bit 3 Value */
#define BITP_AD242X_GPIODDAT_IOD2DAT          2            /*  Bus GPIO Port Bit 2 Value */
#define BITP_AD242X_GPIODDAT_IOD1DAT          1            /*  Bus GPIO Port Bit 1 Value */
#define BITP_AD242X_GPIODDAT_IOD0DAT          0            /*  Bus GPIO Port Bit 0 Value */
#define BITL_AD242X_GPIODDAT_IOD0DAT          1            /*  Bus GPIO Port Bit 0 Value */
#define BITL_AD242X_GPIODDAT_IOD1DAT          1            /*  Bus GPIO Port Bit 1 Value */
#define BITL_AD242X_GPIODDAT_IOD2DAT          1            /*  Bus GPIO Port Bit 2 Value */
#define BITL_AD242X_GPIODDAT_IOD3DAT          1            /*  Bus GPIO Port Bit 3 Value */
#define BITL_AD242X_GPIODDAT_IOD4DAT          1            /*  Bus GPIO Port Bit 4 Value */
#define BITL_AD242X_GPIODDAT_IOD5DAT          1            /*  Bus GPIO Port Bit 5 Value */
#define BITL_AD242X_GPIODDAT_IOD6DAT          1            /*  Bus GPIO Port Bit 6 Value */
#define BITL_AD242X_GPIODDAT_IOD7DAT          1            /*  Bus GPIO Port Bit 7 Value */
#define BITM_AD242X_GPIODDAT_IOD7DAT         0x00000080    /*  Bus GPIO Port Bit 7 Value */
#define BITM_AD242X_GPIODDAT_IOD6DAT         0x00000040    /*  Bus GPIO Port Bit 6 Value */
#define BITM_AD242X_GPIODDAT_IOD5DAT         0x00000020    /*  Bus GPIO Port Bit 5 Value */
#define BITM_AD242X_GPIODDAT_IOD4DAT         0x00000010    /*  Bus GPIO Port Bit 4 Value */
#define BITM_AD242X_GPIODDAT_IOD3DAT         0x00000008    /*  Bus GPIO Port Bit 3 Value */
#define BITM_AD242X_GPIODDAT_IOD2DAT         0x00000004    /*  Bus GPIO Port Bit 2 Value */
#define BITM_AD242X_GPIODDAT_IOD1DAT         0x00000002    /*  Bus GPIO Port Bit 1 Value */
#define BITM_AD242X_GPIODDAT_IOD0DAT         0x00000001    /*  Bus GPIO Port Bit 0 Value */

/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_GPIODINV                      Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_GPIODINV_IOD7INV          7            /*  GPIO Over Distance IO7 Invert */
#define BITP_AD242X_GPIODINV_IOD6INV          6            /*  GPIO Over Distance IO6 Invert */
#define BITP_AD242X_GPIODINV_IOD5INV          5            /*  GPIO Over Distance IO5 Invert */
#define BITP_AD242X_GPIODINV_IOD4INV          4            /*  GPIO Over Distance IO4 Invert */
#define BITP_AD242X_GPIODINV_IOD3INV          3            /*  GPIO Over Distance IO3 Invert */
#define BITP_AD242X_GPIODINV_IOD2INV          2            /*  GPIO Over Distance IO2 Invert */
#define BITP_AD242X_GPIODINV_IOD1INV          1            /*  GPIO Over Distance IO1 Invert */
#define BITP_AD242X_GPIODINV_IOD0INV          0            /*  GPIO Over Distance IO0 Invert */
#define BITL_AD242X_GPIODINV_IOD0INV          1            /*  GPIO Over Distance IO0 Invert */
#define BITL_AD242X_GPIODINV_IOD1INV          1            /*  GPIO Over Distance IO1 Invert */
#define BITL_AD242X_GPIODINV_IOD2INV          1            /*  GPIO Over Distance IO2 Invert */
#define BITL_AD242X_GPIODINV_IOD3INV          1            /*  GPIO Over Distance IO3 Invert */
#define BITL_AD242X_GPIODINV_IOD4INV          1            /*  GPIO Over Distance IO4 Invert */
#define BITL_AD242X_GPIODINV_IOD5INV          1            /*  GPIO Over Distance IO5 Invert */
#define BITL_AD242X_GPIODINV_IOD6INV          1            /*  GPIO Over Distance IO6 Invert */
#define BITL_AD242X_GPIODINV_IOD7INV          1            /*  GPIO Over Distance IO7 Invert */
#define BITM_AD242X_GPIODINV_IOD7INV         0x00000080    /*  GPIO Over Distance IO7 Invert */
#define BITM_AD242X_GPIODINV_IOD6INV         0x00000040    /*  GPIO Over Distance IO6 Invert */
#define BITM_AD242X_GPIODINV_IOD5INV         0x00000020    /*  GPIO Over Distance IO5 Invert */
#define BITM_AD242X_GPIODINV_IOD4INV         0x00000010    /*  GPIO Over Distance IO4 Invert */
#define BITM_AD242X_GPIODINV_IOD3INV         0x00000008    /*  GPIO Over Distance IO3 Invert */
#define BITM_AD242X_GPIODINV_IOD2INV         0x00000004    /*  GPIO Over Distance IO2 Invert */
#define BITM_AD242X_GPIODINV_IOD1INV         0x00000002    /*  GPIO Over Distance IO1 Invert */
#define BITM_AD242X_GPIODINV_IOD0INV         0x00000001    /*  GPIO Over Distance IO0 Invert */

/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_MBOX0CTL                      Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_MBOX0CTL_MB0LEN           4            /*  Mailbox 0 Length */
#define BITP_AD242X_MBOX0CTL_MB0FIEN          3            /*  Mailbox 0 Full Interrupt Enable */
#define BITP_AD242X_MBOX0CTL_MB0EIEN          2            /*  Mailbox 0 Empty Interrupt Enable */
#define BITP_AD242X_MBOX0CTL_MB0DIR           1            /*  Mailbox 0 Direction */
#define BITP_AD242X_MBOX0CTL_MB0EN            0            /*  Mailbox 0 Enable */
#define BITL_AD242X_MBOX0CTL_MB0LEN           2            /*  Mailbox 0 Length */
#define BITL_AD242X_MBOX0CTL_MB0DIR           1            /*  Mailbox 0 Direction */
#define BITL_AD242X_MBOX0CTL_MB0EIEN          1            /*  Mailbox 0 Empty Interrupt Enable */
#define BITL_AD242X_MBOX0CTL_MB0EN            1            /*  Mailbox 0 Enable */
#define BITL_AD242X_MBOX0CTL_MB0FIEN          1            /*  Mailbox 0 Full Interrupt Enable */

#define BITM_AD242X_MBOX0CTL_MB0LEN          0x00000030    /*  Mailbox 0 Length */

#define BITM_AD242X_MBOX0CTL_MB0FIEN         0x00000008    /*  Mailbox 0 Full Interrupt Enable */

#define BITM_AD242X_MBOX0CTL_MB0EIEN         0x00000004    /*  Mailbox 0 Empty Interrupt Enable */

#define BITM_AD242X_MBOX0CTL_MB0DIR          0x00000002    /*  Mailbox 0 Direction */

#define BITM_AD242X_MBOX0CTL_MB0EN           0x00000001    /*  Mailbox 0 Enable */
#define ENUM_AD242X_MBOX0CTL_MB0LEN_1        0x00000000            /*  MB0LEN: Mailbox 0 Length is 1 Byte */
#define ENUM_AD242X_MBOX0CTL_MB0LEN_2        0x00000010            /*  MB0LEN: Mailbox 0 Length is 2 Bytes */
#define ENUM_AD242X_MBOX0CTL_MB0LEN_3        0x00000020            /*  MB0LEN: Mailbox 0 Length is 3 Bytes */
#define ENUM_AD242X_MBOX0CTL_MB0LEN_4        0x00000030            /*  MB0LEN: Mailbox 0 Length is 4 Bytes */
#define ENUM_AD242X_MBOX0CTL_MB0FIEN_DIS     0x00000000            /*  MB0FIEN: Mailbox 0 Interrupt on Full Disabled */
#define ENUM_AD242X_MBOX0CTL_MB0FIEN_EN      0x00000008            /*  MB0FIEN: Mailbox 0 Interrupt on Full Enabled */
#define ENUM_AD242X_MBOX0CTL_MB0EIEN_DIS     0x00000000            /*  MB0EIEN: Mailbox 0 Interrupt on Empty Disabled */
#define ENUM_AD242X_MBOX0CTL_MB0EIEN_EN      0x00000004            /*  MB0EIEN: Mailbox 0 Interrupt on Empty Enabled */
#define ENUM_AD242X_MBOX0CTL_MB0DIR_RX       0x00000000            /*  MB0DIR: Mailbox 0 is Receive Mailbox */
#define ENUM_AD242X_MBOX0CTL_MB0DIR_TX       0x00000002            /*  MB0DIR: Mailbox 0 is Transmit Mailbox */
#define ENUM_AD242X_MBOX0CTL_MB0EN_DIS       0x00000000            /*  MB0EN: Mailbox 0 Disabled */
#define ENUM_AD242X_MBOX0CTL_MB0EN_EN        0x00000001            /*  MB0EN: Mailbox 0 Enabled */

/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_MBOX0STAT                     Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_MBOX0STAT_MB0EIRQ         5            /*  Mailbox 0 Signaling Empty IRQ */
#define BITP_AD242X_MBOX0STAT_MB0FIRQ         4            /*  Mailbox 0 Signaling Full IRQ */
#define BITP_AD242X_MBOX0STAT_MB0EMPTY        1            /*  Mailbox 0 Empty */
#define BITP_AD242X_MBOX0STAT_MB0FULL         0            /*  Mailbox 0 Full */
#define BITL_AD242X_MBOX0STAT_MB0EIRQ         1            /*  Mailbox 0 Signaling Empty IRQ */
#define BITL_AD242X_MBOX0STAT_MB0EMPTY        1            /*  Mailbox 0 Empty */
#define BITL_AD242X_MBOX0STAT_MB0FIRQ         1            /*  Mailbox 0 Signaling Full IRQ */
#define BITL_AD242X_MBOX0STAT_MB0FULL         1            /*  Mailbox 0 Full */

#define BITM_AD242X_MBOX0STAT_MB0EIRQ        0x00000020    /*  Mailbox 0 Signaling Empty IRQ */

#define BITM_AD242X_MBOX0STAT_MB0FIRQ        0x00000010    /*  Mailbox 0 Signaling Full IRQ */

#define BITM_AD242X_MBOX0STAT_MB0EMPTY       0x00000002    /*  Mailbox 0 Empty */

#define BITM_AD242X_MBOX0STAT_MB0FULL        0x00000001    /*  Mailbox 0 Full */
#define ENUM_AD242X_MBOX0STAT_MB0EIRQ_LO     0x00000000            /*  MB0EIRQ: Mailbox 0 Empty Interrupt Inactive */
#define ENUM_AD242X_MBOX0STAT_MB0EIRQ_HI     0x00000020            /*  MB0EIRQ: Mailbox 0 Empty Interrupt Active */
#define ENUM_AD242X_MBOX0STAT_MB0FIRQ_LO     0x00000000            /*  MB0FIRQ: Mailbox 0 Full Interrupt Inactive */
#define ENUM_AD242X_MBOX0STAT_MB0FIRQ_HI     0x00000010            /*  MB0FIRQ: Mailbox 0 Full Interrupt Active */
#define ENUM_AD242X_MBOX0STAT_MB0EMPTY_LO    0x00000000            /*  MB0EMPTY: Mailbox 0 Currently Not Empty */
#define ENUM_AD242X_MBOX0STAT_MB0EMPTY_HI    0x00000002            /*  MB0EMPTY: Mailbox 0 Currently Empty */
#define ENUM_AD242X_MBOX0STAT_MB0FULL_LO     0x00000000            /*  MB0FULL: Mailbox 0 Currently Not Full */
#define ENUM_AD242X_MBOX0STAT_MB0FULL_HI     0x00000001            /*  MB0FULL: Mailbox 0 Currently Full */

/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_MBOX0B0                       Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_MBOX0B0_MBOX0             0            /*  Mailbox 0 Data Byte 1 */
#define BITL_AD242X_MBOX0B0_MBOX0             8            /*  Mailbox 0 Data Byte 1 */
#define BITM_AD242X_MBOX0B0_MBOX0            0x000000FF    /*  Mailbox 0 Data Byte 1 */

/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_MBOX0B1                       Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_MBOX0B1_MBOX0             0            /*  Mailbox 0 Data Byte 1 */
#define BITL_AD242X_MBOX0B1_MBOX0             8            /*  Mailbox 0 Data Byte 1 */
#define BITM_AD242X_MBOX0B1_MBOX0            0x000000FF    /*  Mailbox 0 Data Byte 1 */

/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_MBOX0B2                       Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_MBOX0B2_MBOX0             0            /*  Mailbox 0 Data Byte 1 */
#define BITL_AD242X_MBOX0B2_MBOX0             8            /*  Mailbox 0 Data Byte 1 */
#define BITM_AD242X_MBOX0B2_MBOX0            0x000000FF    /*  Mailbox 0 Data Byte 1 */

/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_MBOX0B3                       Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_MBOX0B3_MBOX0             0            /*  Mailbox 0 Data Byte 1 */
#define BITL_AD242X_MBOX0B3_MBOX0             8            /*  Mailbox 0 Data Byte 1 */
#define BITM_AD242X_MBOX0B3_MBOX0            0x000000FF    /*  Mailbox 0 Data Byte 1 */

/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_MBOX1CTL                      Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_MBOX1CTL_MB1LEN           4            /*  Mailbox 1 Length */
#define BITP_AD242X_MBOX1CTL_MB1FIEN          3            /*  Mailbox 1 Full Interrupt Enable */
#define BITP_AD242X_MBOX1CTL_MB1EIEN          2            /*  Mailbox 1 Empty Interrupt Enable */
#define BITP_AD242X_MBOX1CTL_MB1DIR           1            /*  Mailbox 1 Direction */
#define BITP_AD242X_MBOX1CTL_MB1EN            0            /*  Mailbox 1 Enable */
#define BITL_AD242X_MBOX1CTL_MB1LEN           2            /*  Mailbox 1 Length */
#define BITL_AD242X_MBOX1CTL_MB1DIR           1            /*  Mailbox 1 Direction */
#define BITL_AD242X_MBOX1CTL_MB1EIEN          1            /*  Mailbox 1 Empty Interrupt Enable */
#define BITL_AD242X_MBOX1CTL_MB1EN            1            /*  Mailbox 1 Enable */
#define BITL_AD242X_MBOX1CTL_MB1FIEN          1            /*  Mailbox 1 Full Interrupt Enable */

#define BITM_AD242X_MBOX1CTL_MB1LEN          0x00000030    /*  Mailbox 1 Length */

#define BITM_AD242X_MBOX1CTL_MB1FIEN         0x00000008    /*  Mailbox 1 Full Interrupt Enable */

#define BITM_AD242X_MBOX1CTL_MB1EIEN         0x00000004    /*  Mailbox 1 Empty Interrupt Enable */

#define BITM_AD242X_MBOX1CTL_MB1DIR          0x00000002    /*  Mailbox 1 Direction */

#define BITM_AD242X_MBOX1CTL_MB1EN           0x00000001    /*  Mailbox 1 Enable */
#define ENUM_AD242X_MBOX1CTL_MB1LEN_1        0x00000000            /*  MB1LEN: Mailbox 1 Length is 1 Byte */
#define ENUM_AD242X_MBOX1CTL_MB1LEN_2        0x00000010            /*  MB1LEN: Mailbox 1 Length is 2 Bytes */
#define ENUM_AD242X_MBOX1CTL_MB1LEN_3        0x00000020            /*  MB1LEN: Mailbox 1 Length is 3 Bytes */
#define ENUM_AD242X_MBOX1CTL_MB1LEN_4        0x00000030            /*  MB1LEN: Mailbox 1 Length is 4 Bytes */
#define ENUM_AD242X_MBOX1CTL_MB1FIEN_DIS     0x00000000            /*  MB1FIEN: Mailbox 1 Interrupt on Full Disabled */
#define ENUM_AD242X_MBOX1CTL_MB1FIEN_EN      0x00000008            /*  MB1FIEN: Mailbox 1 Interrupt on Full Enabled */
#define ENUM_AD242X_MBOX1CTL_MB1EIEN_DIS     0x00000000            /*  MB1EIEN: Mailbox 1 Interrupt on Empty Disabled */
#define ENUM_AD242X_MBOX1CTL_MB1EIEN_EN      0x00000004            /*  MB1EIEN: Mailbox 1 Interrupt on Empty Enabled */
#define ENUM_AD242X_MBOX1CTL_MB1DIR_RX       0x00000000            /*  MB1DIR: Mailbox 1 is Receive Mailbox */
#define ENUM_AD242X_MBOX1CTL_MB1DIR_TX       0x00000002            /*  MB1DIR: Mailbox 1 is Transmit Mailbox */
#define ENUM_AD242X_MBOX1CTL_MB1EN_DIS       0x00000000            /*  MB1EN: Mailbox 1 Disabled */
#define ENUM_AD242X_MBOX1CTL_MB1EN_EN        0x00000001            /*  MB1EN: Mailbox 1 Enabled */

/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_MBOX1STAT                     Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_MBOX1STAT_MB1EIRQ         5            /*  Mailbox 1 Signaling Empty IRQ */
#define BITP_AD242X_MBOX1STAT_MB1FIRQ         4            /*  Mailbox 1 Signaling Full IRQ */
#define BITP_AD242X_MBOX1STAT_MB1EMPTY        1            /*  Mailbox 1 Empty */
#define BITP_AD242X_MBOX1STAT_MB1FULL         0            /*  Mailbox 1 Full */
#define BITL_AD242X_MBOX1STAT_MB1EIRQ         1            /*  Mailbox 1 Signaling Empty IRQ */
#define BITL_AD242X_MBOX1STAT_MB1EMPTY        1            /*  Mailbox 1 Empty */
#define BITL_AD242X_MBOX1STAT_MB1FIRQ         1            /*  Mailbox 1 Signaling Full IRQ */
#define BITL_AD242X_MBOX1STAT_MB1FULL         1            /*  Mailbox 1 Full */

#define BITM_AD242X_MBOX1STAT_MB1EIRQ        0x00000020    /*  Mailbox 1 Signaling Empty IRQ */

#define BITM_AD242X_MBOX1STAT_MB1FIRQ        0x00000010    /*  Mailbox 1 Signaling Full IRQ */

#define BITM_AD242X_MBOX1STAT_MB1EMPTY       0x00000002    /*  Mailbox 1 Empty */

#define BITM_AD242X_MBOX1STAT_MB1FULL        0x00000001    /*  Mailbox 1 Full */
#define ENUM_AD242X_MBOX1STAT_MB1EIRQ_LO     0x00000000            /*  MB1EIRQ: Mailbox 1 Empty Interrupt Inactive */
#define ENUM_AD242X_MBOX1STAT_MB1EIRQ_HI     0x00000020            /*  MB1EIRQ: Mailbox 1 Empty Interrupt Active */
#define ENUM_AD242X_MBOX1STAT_MB1FIRQ_LO     0x00000000            /*  MB1FIRQ: Mailbox 1 Full Interrupt Inactive */
#define ENUM_AD242X_MBOX1STAT_MB1FIRQ_HI     0x00000010            /*  MB1FIRQ: Mailbox 1 Full Interrupt Active */
#define ENUM_AD242X_MBOX1STAT_MB1EMPTY_LO    0x00000000            /*  MB1EMPTY: Mailbox 0 Currently Not Empty */
#define ENUM_AD242X_MBOX1STAT_MB1EMPTY_HI    0x00000002            /*  MB1EMPTY: Mailbox 0 Currently Empty */
#define ENUM_AD242X_MBOX1STAT_MB1FULL_LO     0x00000000            /*  MB1FULL: Mailbox 1 Currently Not Full */
#define ENUM_AD242X_MBOX1STAT_MB1FULL_HI     0x00000001            /*  MB1FULL: Mailbox 1 Currently Full */

/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_MBOX1B0                       Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_MBOX1B0_MBOX1             0            /*  Mailbox 1 Data */
#define BITL_AD242X_MBOX1B0_MBOX1             8            /*  Mailbox 1 Data */
#define BITM_AD242X_MBOX1B0_MBOX1            0x000000FF    /*  Mailbox 1 Data */

/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_MBOX1B1                       Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_MBOX1B1_MBOX1             0            /*  Mailbox 1 Data */
#define BITL_AD242X_MBOX1B1_MBOX1             8            /*  Mailbox 1 Data */
#define BITM_AD242X_MBOX1B1_MBOX1            0x000000FF    /*  Mailbox 1 Data */

/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_MBOX1B2                       Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_MBOX1B2_MBOX1             0            /*  Mailbox 1 Data */
#define BITL_AD242X_MBOX1B2_MBOX1             8            /*  Mailbox 1 Data */
#define BITM_AD242X_MBOX1B2_MBOX1            0x000000FF    /*  Mailbox 1 Data */

/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_MBOX1B3                       Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_MBOX1B3_MBOX1             0            /*  Mailbox 1 Data */
#define BITL_AD242X_MBOX1B3_MBOX1             8            /*  Mailbox 1 Data */
#define BITM_AD242X_MBOX1B3_MBOX1            0x000000FF    /*  Mailbox 1 Data */

/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_AMSCTL0                       Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_AMSCTL0_AMSCTL0           0            /*  AMSCTL0 Bit Field */
#define BITL_AD242X_AMSCTL0_AMSCTL0           8            /*  AMSCTL0 Bit Field */
#define BITM_AD242X_AMSCTL0_AMSCTL0          0x000000FF    /*  AMSCTL0 Bit Field */

/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_AMSCTL1                       Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_AMSCTL1_AMSCTL1           0            /*  AMSCTL1 Bit Field */
#define BITL_AD242X_AMSCTL1_AMSCTL1           8            /*  AMSCTL1 Bit Field */
#define BITM_AD242X_AMSCTL1_AMSCTL1          0x000000FF    /*  AMSCTL1 Bit Field */

/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_AMSCTL2                       Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_AMSCTL2_AMSCTL2           0            /*  AMSCTL2 Bit Field */
#define BITL_AD242X_AMSCTL2_AMSCTL2           8            /*  AMSCTL2 Bit Field */
#define BITM_AD242X_AMSCTL2_AMSCTL2          0x000000FF    /*  AMSCTL2 Bit Field */

/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_AMSCTL3                       Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_AMSCTL3_AMSCTL3           0            /*  AMSCTL3 Bit Field */
#define BITL_AD242X_AMSCTL3_AMSCTL3           8            /*  AMSCTL3 Bit Field */
#define BITM_AD242X_AMSCTL3_AMSCTL3          0x000000FF    /*  AMSCTL3 Bit Field */

/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_AMSCTL4                       Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_AMSCTL4_AMSCTL4           0            /*  AMSCTL4 Bit Field */
#define BITL_AD242X_AMSCTL4_AMSCTL4           8            /*  AMSCTL4 Bit Field */
#define BITM_AD242X_AMSCTL4_AMSCTL4          0x000000FF    /*  AMSCTL4 Bit Field */

/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_AMSSTAT0                      Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_AMSSTAT0_AMSSTAT0         0            /*  AMSSTAT0 Bit Field */
#define BITL_AD242X_AMSSTAT0_AMSSTAT0         8            /*  AMSSTAT0 Bit Field */
#define BITM_AD242X_AMSSTAT0_AMSSTAT0        0x000000FF    /*  AMSSTAT0 Bit Field */

/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_AMSSTAT1                      Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_AMSSTAT1_AMSSTAT1         0            /*  AMSSTAT1 Bit Field */
#define BITL_AD242X_AMSSTAT1_AMSSTAT1         8            /*  AMSSTAT1 Bit Field */
#define BITM_AD242X_AMSSTAT1_AMSSTAT1        0x000000FF    /*  AMSSTAT1 Bit Field */

/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_AMSSTAT2                      Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_AMSSTAT2_AMSSTAT2         0            /*  AMSSTAT2 Bit Field */
#define BITL_AD242X_AMSSTAT2_AMSSTAT2         8            /*  AMSSTAT2 Bit Field */
#define BITM_AD242X_AMSSTAT2_AMSSTAT2        0x000000FF    /*  AMSSTAT2 Bit Field */

/* ============================================================================================================================
 *    A2B_Analog_Tuning Register Field Definitions
 * ============================================================================================================================ */
/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_VREGCTL                       Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_VREGCTL_VSSEL             0            /*  Select Vsense */
#define BITL_AD242X_VREGCTL_VSSEL             1            /*  Select Vsense */
#define BITM_AD242X_VREGCTL_VSSEL            0x00000001    /*  Select Vsense */

/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_TXACTL                        Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_TXACTL_TXAOVREN           7            /*  TXA Control Override Enable */
#define BITP_AD242X_TXACTL_TXASLEW            4            /*  TXA Slew */
#define BITP_AD242X_TXACTL_TXAPE              2            /*  TXA Emphasis */
#define BITP_AD242X_TXACTL_TXALEVEL           0            /*  TXA Level */
#define BITL_AD242X_TXACTL_TXALEVEL           2            /*  TXA Level */
#define BITL_AD242X_TXACTL_TXAPE              2            /*  TXA Emphasis */
#define BITL_AD242X_TXACTL_TXASLEW            2            /*  TXA Slew */
#define BITL_AD242X_TXACTL_TXAOVREN           1            /*  TXA Control Override Enable */
#define BITM_AD242X_TXACTL_TXAOVREN          0x00000080    /*  TXA Control Override Enable */

#define BITM_AD242X_TXACTL_TXASLEW           0x00000030    /*  TXA Slew */

#define BITM_AD242X_TXACTL_TXAPE             0x0000000C    /*  TXA Emphasis */

#define BITM_AD242X_TXACTL_TXALEVEL          0x00000003    /*  TXA Level */

/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_RXACTL                        Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_RXACTL_RXAOVREN           7            /*  RXA Control Override Enable */
#define BITP_AD242X_RXACTL_RXAEQ              6            /*  RXA Equalization Control */
#define BITP_AD242X_RXACTL_RXATYPE            5            /*  RXA Receiver Type */
#define BITP_AD242X_RXACTL_RXASQEN            4            /*  RXA Squelch Enable */
#define BITP_AD242X_RXACTL_RXASQUELCH         2            /*  RXA Squelch Control */
#define BITP_AD242X_RXACTL_RXAHYS             0            /*  RXA Hysteresis Control */
#define BITL_AD242X_RXACTL_RXAHYS             2            /*  RXA Hysteresis Control */
#define BITL_AD242X_RXACTL_RXASQUELCH         2            /*  RXA Squelch Control */
#define BITL_AD242X_RXACTL_RXAEQ              1            /*  RXA Equalization Control */
#define BITL_AD242X_RXACTL_RXAOVREN           1            /*  RXA Control Override Enable */
#define BITL_AD242X_RXACTL_RXASQEN            1            /*  RXA Squelch Enable */
#define BITL_AD242X_RXACTL_RXATYPE            1            /*  RXA Receiver Type */
#define BITM_AD242X_RXACTL_RXAOVREN          0x00000080    /*  RXA Control Override Enable */

#define BITM_AD242X_RXACTL_RXAEQ             0x00000040    /*  RXA Equalization Control */

#define BITM_AD242X_RXACTL_RXATYPE           0x00000020    /*  RXA Receiver Type */

#define BITM_AD242X_RXACTL_RXASQEN           0x00000010    /*  RXA Squelch Enable */

#define BITM_AD242X_RXACTL_RXASQUELCH        0x0000000C    /*  RXA Squelch Control */

#define BITM_AD242X_RXACTL_RXAHYS            0x00000003    /*  RXA Hysteresis Control */

/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_TXBCTL                        Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_TXBCTL_TXBOVREN           7            /*  TXB Control Override Enable */
#define BITP_AD242X_TXBCTL_TXBSLEW            4            /*  TXB Slew */
#define BITP_AD242X_TXBCTL_TXBPE              2            /*  TXB Emphasis */
#define BITP_AD242X_TXBCTL_TXBLEVEL           0            /*  TXB Level */
#define BITL_AD242X_TXBCTL_TXBLEVEL           2            /*  TXB Level */
#define BITL_AD242X_TXBCTL_TXBPE              2            /*  TXB Emphasis */
#define BITL_AD242X_TXBCTL_TXBSLEW            2            /*  TXB Slew */
#define BITL_AD242X_TXBCTL_TXBOVREN           1            /*  TXB Control Override Enable */
#define BITM_AD242X_TXBCTL_TXBOVREN          0x00000080    /*  TXB Control Override Enable */

#define BITM_AD242X_TXBCTL_TXBSLEW           0x00000030    /*  TXB Slew */

#define BITM_AD242X_TXBCTL_TXBPE             0x0000000C    /*  TXB Emphasis */

#define BITM_AD242X_TXBCTL_TXBLEVEL          0x00000003    /*  TXB Level */

/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_RXBCTL                        Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_RXBCTL_RXBOVREN           7            /*  RXB Control Override Enable */
#define BITP_AD242X_RXBCTL_RXBEQ              6            /*  RXB Equalization Control */
#define BITP_AD242X_RXBCTL_RXBTYPE            5            /*  RXB Receiver Type */
#define BITP_AD242X_RXBCTL_RXBSQEN            4            /*  RXB Squelch Enable */
#define BITP_AD242X_RXBCTL_RXBSQUELCH         2            /*  RXB Squelch Control */
#define BITP_AD242X_RXBCTL_RXBHYS             0            /*  RXB Hysteresis Control */
#define BITL_AD242X_RXBCTL_RXBHYS             2            /*  RXB Hysteresis Control */
#define BITL_AD242X_RXBCTL_RXBSQUELCH         2            /*  RXB Squelch Control */
#define BITL_AD242X_RXBCTL_RXBEQ              1            /*  RXB Equalization Control */
#define BITL_AD242X_RXBCTL_RXBOVREN           1            /*  RXB Control Override Enable */
#define BITL_AD242X_RXBCTL_RXBSQEN            1            /*  RXB Squelch Enable */
#define BITL_AD242X_RXBCTL_RXBTYPE            1            /*  RXB Receiver Type */
#define BITM_AD242X_RXBCTL_RXBOVREN          0x00000080    /*  RXB Control Override Enable */

#define BITM_AD242X_RXBCTL_RXBEQ             0x00000040    /*  RXB Equalization Control */

#define BITM_AD242X_RXBCTL_RXBTYPE           0x00000020    /*  RXB Receiver Type */

#define BITM_AD242X_RXBCTL_RXBSQEN           0x00000010    /*  RXB Squelch Enable */

#define BITM_AD242X_RXBCTL_RXBSQUELCH        0x0000000C    /*  RXB Squelch Control */

#define BITM_AD242X_RXBCTL_RXBHYS            0x00000003    /*  RXB Hysteresis Control */

/* ============================================================================================================================
 *    A2B_Config_MO_Auto_Broadcast_Shadowed Register Field Definitions
 * ============================================================================================================================ */
/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_SLOTFMT                       Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_SLOTFMT_UPFMT             7            /*  Upstream Floating Point */
#define BITP_AD242X_SLOTFMT_UPSIZE            4            /*  Upstream Slot Size */
#define BITP_AD242X_SLOTFMT_DNFMT             3            /*  Downstream Floating-Point */
#define BITP_AD242X_SLOTFMT_DNSIZE            0            /*  Downstream Slot Size */
#define BITL_AD242X_SLOTFMT_DNSIZE            3            /*  Downstream Slot Size */
#define BITL_AD242X_SLOTFMT_UPSIZE            3            /*  Upstream Slot Size */
#define BITL_AD242X_SLOTFMT_DNFMT             1            /*  Downstream Floating-Point */
#define BITL_AD242X_SLOTFMT_UPFMT             1            /*  Upstream Floating Point */

#define BITM_AD242X_SLOTFMT_UPFMT            0x00000080    /*  Upstream Floating Point */

#define BITM_AD242X_SLOTFMT_UPSIZE           0x00000070    /*  Upstream Slot Size */

#define BITM_AD242X_SLOTFMT_DNFMT            0x00000008    /*  Downstream Floating-Point */

#define BITM_AD242X_SLOTFMT_DNSIZE           0x00000007    /*  Downstream Slot Size */
#define ENUM_AD242X_SLOTFMT_UPFMT_DIS        0x00000000            /*  UPFMT: Disabled (Normal Upstream Data Slot Format) */
#define ENUM_AD242X_SLOTFMT_UPFMT_EN         0x00000080            /*  UPFMT: Enabled (Alternate Upstream Data Slot Format) */
#define ENUM_AD242X_SLOTFMT_UPSIZE_8         0x00000000            /*  UPSIZE: 8 Bits */
#define ENUM_AD242X_SLOTFMT_UPSIZE_12        0x00000010            /*  UPSIZE: 12 Bits */
#define ENUM_AD242X_SLOTFMT_UPSIZE_16        0x00000020            /*  UPSIZE: 16 Bits */
#define ENUM_AD242X_SLOTFMT_UPSIZE_20        0x00000030            /*  UPSIZE: 20 Bits */
#define ENUM_AD242X_SLOTFMT_UPSIZE_24        0x00000040            /*  UPSIZE: 24 Bits */
#define ENUM_AD242X_SLOTFMT_UPSIZE_28        0x00000050            /*  UPSIZE: 28 Bits */
#define ENUM_AD242X_SLOTFMT_UPSIZE_32        0x00000060            /*  UPSIZE: 32 Bits */
#define ENUM_AD242X_SLOTFMT_DNFMT_DIS        0x00000000            /*  DNFMT: Disabled (Normal Downstream Data Slot Format) */
#define ENUM_AD242X_SLOTFMT_DNFMT_EN         0x00000008            /*  DNFMT: Enabled (Alternate Downstream Data Slot Format) */
#define ENUM_AD242X_SLOTFMT_DNSIZE_8         0x00000000            /*  DNSIZE: 8 Bits */
#define ENUM_AD242X_SLOTFMT_DNSIZE_12        0x00000001            /*  DNSIZE: 12 Bits */
#define ENUM_AD242X_SLOTFMT_DNSIZE_16        0x00000002            /*  DNSIZE: 16 Bits */
#define ENUM_AD242X_SLOTFMT_DNSIZE_20        0x00000003            /*  DNSIZE: 20 Bits */
#define ENUM_AD242X_SLOTFMT_DNSIZE_24        0x00000004            /*  DNSIZE: 24 Bits */
#define ENUM_AD242X_SLOTFMT_DNSIZE_28        0x00000005            /*  DNSIZE: 28 Bits */
#define ENUM_AD242X_SLOTFMT_DNSIZE_32        0x00000006            /*  DNSIZE: 32 Bits */

/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_DATCTL                        Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_DATCTL_STANDBY            7            /*  Enable Standby Mode */
#define BITP_AD242X_DATCTL_SCRDIS             6            /*  Disable Scrambler */
#define BITP_AD242X_DATCTL_ENDSNIFF           5            /*  Enable Data Output on Bus Monitor Node */
#define BITP_AD242X_DATCTL_UPS                1            /*  Enable Upstream Slots */
#define BITP_AD242X_DATCTL_DNS                0            /*  Enable Downstream Slots */
#define BITL_AD242X_DATCTL_DNS                1            /*  Enable Downstream Slots */
#define BITL_AD242X_DATCTL_ENDSNIFF           1            /*  Enable Data Output on Bus Monitor Node */
#define BITL_AD242X_DATCTL_SCRDIS             1            /*  Disable Scrambler */
#define BITL_AD242X_DATCTL_STANDBY            1            /*  Enable Standby Mode */
#define BITL_AD242X_DATCTL_UPS                1            /*  Enable Upstream Slots */

#define BITM_AD242X_DATCTL_STANDBY           0x00000080    /*  Enable Standby Mode */

#define BITM_AD242X_DATCTL_SCRDIS            0x00000040    /*  Disable Scrambler */

#define BITM_AD242X_DATCTL_ENDSNIFF          0x00000020    /*  Enable Data Output on Bus Monitor Node */

#define BITM_AD242X_DATCTL_UPS               0x00000002    /*  Enable Upstream Slots */

#define BITM_AD242X_DATCTL_DNS               0x00000001    /*  Enable Downstream Slots */
#define ENUM_AD242X_DATCTL_STANDBY_DIS       0x00000000            /*  STANDBY: Disabled */
#define ENUM_AD242X_DATCTL_STANDBY_EN        0x00000080            /*  STANDBY: Enabled */
#define ENUM_AD242X_DATCTL_SCRDIS_OFF        0x00000000            /*  SCRDIS: Scrambling Enabled */
#define ENUM_AD242X_DATCTL_SCRDIS_ON         0x00000040            /*  SCRDIS: Scrambling Disabled */
#define ENUM_AD242X_DATCTL_ENDSNIFF_DIS      0x00000000            /*  ENDSNIFF: Disable Data Output on Attached Bus Monitor Node */
#define ENUM_AD242X_DATCTL_ENDSNIFF_EN       0x00000020            /*  ENDSNIFF: Enable Data Output on Attached Bus Monitor Node */
#define ENUM_AD242X_DATCTL_UPS_DIS           0x00000000            /*  UPS: Disabled */
#define ENUM_AD242X_DATCTL_UPS_EN            0x00000002            /*  UPS: Enabled */
#define ENUM_AD242X_DATCTL_DNS_DIS           0x00000000            /*  DNS: Disabled */
#define ENUM_AD242X_DATCTL_DNS_EN            0x00000001            /*  DNS: Enabled */

/* ============================================================================================================================
 *    A2B_Config_SO_Shadowed Register Field Definitions
 * ============================================================================================================================ */
/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_BCDNSLOTS                     Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_BCDNSLOTS_BCDNSLOTS       0            /*  Broadcast Downstream Slots */
#define BITL_AD242X_BCDNSLOTS_BCDNSLOTS       6            /*  Broadcast Downstream Slots */
#define BITM_AD242X_BCDNSLOTS_BCDNSLOTS      0x0000003F    /*  Broadcast Downstream Slots */

/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_LDNSLOTS                      Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_LDNSLOTS_DNMASKEN         7            /*  New Downstream Broadcast Enable */
#define BITP_AD242X_LDNSLOTS_LDNSLOTS         0            /*  Number of Downstream Slots Targeted at Local Node */
#define BITL_AD242X_LDNSLOTS_LDNSLOTS         6            /*  Number of Downstream Slots Targeted at Local Node */
#define BITL_AD242X_LDNSLOTS_DNMASKEN         1            /*  New Downstream Broadcast Enable */

#define BITM_AD242X_LDNSLOTS_DNMASKEN        0x00000080    /*  New Downstream Broadcast Enable */
#define BITM_AD242X_LDNSLOTS_LDNSLOTS        0x0000003F    /*  Number of Downstream Slots Targeted at Local Node */
#define ENUM_AD242X_LDNSLOTS_DNMASKEN_DIS    0x00000000            /*  DNMASKEN: Downstream Data Slot Mask Disabled */
#define ENUM_AD242X_LDNSLOTS_DNMASKEN_EN     0x00000080            /*  DNMASKEN: Downstream Data Slot Mask Enabled */

/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_LUPSLOTS                      Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_LUPSLOTS_LUPSLOTS         0            /*  Number of Upstream Slots Generated by Local Node */
#define BITL_AD242X_LUPSLOTS_LUPSLOTS         6            /*  Number of Upstream Slots Generated by Local Node */
#define BITM_AD242X_LUPSLOTS_LUPSLOTS        0x0000003F    /*  Number of Upstream Slots Generated by Local Node */

/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_UPOFFSET                      Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_UPOFFSET_UPOFFSET         0            /*  Upstream Slots Offset for Local Node */
#define BITL_AD242X_UPOFFSET_UPOFFSET         5            /*  Upstream Slots Offset for Local Node */
#define BITM_AD242X_UPOFFSET_UPOFFSET        0x0000001F    /*  Upstream Slots Offset for Local Node */

/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_DNOFFSET                      Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_DNOFFSET_DNOFFSET         0            /*  Downstream Slots Offset for Local Node */
#define BITL_AD242X_DNOFFSET_DNOFFSET         5            /*  Downstream Slots Offset for Local Node */
#define BITM_AD242X_DNOFFSET_DNOFFSET        0x0000001F    /*  Downstream Slots Offset for Local Node */

/* ============================================================================================================================
 *    A2B_Config_Shadowed Register Field Definitions
 * ============================================================================================================================ */
/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_DNSLOTS                       Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_DNSLOTS_DNSLOTS           0            /*  Number of Downstream Slots */
#define BITL_AD242X_DNSLOTS_DNSLOTS           6            /*  Number of Downstream Slots */
#define BITM_AD242X_DNSLOTS_DNSLOTS          0x0000003F    /*  Number of Downstream Slots */

/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_UPSLOTS                       Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_UPSLOTS_UPSLOTS           0            /*  Number of Upstream Slots */
#define BITL_AD242X_UPSLOTS_UPSLOTS           6            /*  Number of Upstream Slots */
#define BITM_AD242X_UPSLOTS_UPSLOTS          0x0000003F    /*  Number of Upstream Slots */

/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_RESPCYCS                      Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_RESPCYCS_RESPCYCS         0            /*  Response Cycles */
#define BITL_AD242X_RESPCYCS_RESPCYCS         8            /*  Response Cycles */
#define BITM_AD242X_RESPCYCS_RESPCYCS        0x000000FF    /*  Response Cycles */

/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_UPMASK0                       Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_UPMASK0_RXUPSLOT07        7            /*  Receive Upstream Data Slot 7 */
#define BITP_AD242X_UPMASK0_RXUPSLOT06        6            /*  Receive Upstream Data Slot 6 */
#define BITP_AD242X_UPMASK0_RXUPSLOT05        5            /*  Receive Upstream Data Slot 5 */
#define BITP_AD242X_UPMASK0_RXUPSLOT04        4            /*  Receive Upstream Data Slot 4 */
#define BITP_AD242X_UPMASK0_RXUPSLOT03        3            /*  Receive Upstream Data Slot 3 */
#define BITP_AD242X_UPMASK0_RXUPSLOT02        2            /*  Receive Upstream Data Slot 2 */
#define BITP_AD242X_UPMASK0_RXUPSLOT01        1            /*  Receive Upstream Data Slot 1 */
#define BITP_AD242X_UPMASK0_RXUPSLOT00        0            /*  Receive Upstream Data Slot 0 */
#define BITL_AD242X_UPMASK0_RXUPSLOT00        1            /*  Receive Upstream Data Slot 0 */
#define BITL_AD242X_UPMASK0_RXUPSLOT01        1            /*  Receive Upstream Data Slot 1 */
#define BITL_AD242X_UPMASK0_RXUPSLOT02        1            /*  Receive Upstream Data Slot 2 */
#define BITL_AD242X_UPMASK0_RXUPSLOT03        1            /*  Receive Upstream Data Slot 3 */
#define BITL_AD242X_UPMASK0_RXUPSLOT04        1            /*  Receive Upstream Data Slot 4 */
#define BITL_AD242X_UPMASK0_RXUPSLOT05        1            /*  Receive Upstream Data Slot 5 */
#define BITL_AD242X_UPMASK0_RXUPSLOT06        1            /*  Receive Upstream Data Slot 6 */
#define BITL_AD242X_UPMASK0_RXUPSLOT07        1            /*  Receive Upstream Data Slot 7 */

#define BITM_AD242X_UPMASK0_RXUPSLOT07       0x00000080    /*  Receive Upstream Data Slot 7 */

#define BITM_AD242X_UPMASK0_RXUPSLOT06       0x00000040    /*  Receive Upstream Data Slot 6 */

#define BITM_AD242X_UPMASK0_RXUPSLOT05       0x00000020    /*  Receive Upstream Data Slot 5 */

#define BITM_AD242X_UPMASK0_RXUPSLOT04       0x00000010    /*  Receive Upstream Data Slot 4 */

#define BITM_AD242X_UPMASK0_RXUPSLOT03       0x00000008    /*  Receive Upstream Data Slot 3 */

#define BITM_AD242X_UPMASK0_RXUPSLOT02       0x00000004    /*  Receive Upstream Data Slot 2 */

#define BITM_AD242X_UPMASK0_RXUPSLOT01       0x00000002    /*  Receive Upstream Data Slot 1 */

#define BITM_AD242X_UPMASK0_RXUPSLOT00       0x00000001    /*  Receive Upstream Data Slot 0 */
#define ENUM_AD242X_UPMASK0_RXUPSLOT07_DIS   0x00000000            /*  RXUPSLOT07: Upstream Data Slot 7 RX Disabled */
#define ENUM_AD242X_UPMASK0_RXUPSLOT07_EN    0x00000080            /*  RXUPSLOT07: Upstream Data Slot 7 RX Enabled */
#define ENUM_AD242X_UPMASK0_RXUPSLOT06_DIS   0x00000000            /*  RXUPSLOT06: Upstream Data Slot 6 RX Disabled */
#define ENUM_AD242X_UPMASK0_RXUPSLOT06_EN    0x00000040            /*  RXUPSLOT06: Upstream Data Slot 6 RX Enabled */
#define ENUM_AD242X_UPMASK0_RXUPSLOT05_DIS   0x00000000            /*  RXUPSLOT05: Upstream Data Slot 5 RX Disabled */
#define ENUM_AD242X_UPMASK0_RXUPSLOT05_EN    0x00000020            /*  RXUPSLOT05: Upstream Data Slot 5 RX Enabled */
#define ENUM_AD242X_UPMASK0_RXUPSLOT04_DIS   0x00000000            /*  RXUPSLOT04: Upstream Data Slot 4 RX Disabled */
#define ENUM_AD242X_UPMASK0_RXUPSLOT04_EN    0x00000010            /*  RXUPSLOT04: Upstream Data Slot 4 RX Enabled */
#define ENUM_AD242X_UPMASK0_RXUPSLOT03_DIS   0x00000000            /*  RXUPSLOT03: Upstream Data Slot 3 RX Disabled */
#define ENUM_AD242X_UPMASK0_RXUPSLOT03_EN    0x00000008            /*  RXUPSLOT03: Upstream Data Slot 3 RX Enabled */
#define ENUM_AD242X_UPMASK0_RXUPSLOT02_DIS   0x00000000            /*  RXUPSLOT02: Upstream Data Slot 2 RX Disabled */
#define ENUM_AD242X_UPMASK0_RXUPSLOT02_EN    0x00000004            /*  RXUPSLOT02: Upstream Data Slot 2 RX Enabled */
#define ENUM_AD242X_UPMASK0_RXUPSLOT01_DIS   0x00000000            /*  RXUPSLOT01: Upstream Data Slot 1 RX Disabled */
#define ENUM_AD242X_UPMASK0_RXUPSLOT01_EN    0x00000002            /*  RXUPSLOT01: Upstream Data Slot 1 RX Enabled */
#define ENUM_AD242X_UPMASK0_RXUPSLOT00_DIS   0x00000000            /*  RXUPSLOT00: Upstream Data Slot 0 RX Disabled */
#define ENUM_AD242X_UPMASK0_RXUPSLOT00_EN    0x00000001            /*  RXUPSLOT00: Upstream Data Slot 0 RX Enabled */

/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_UPMASK1                       Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_UPMASK1_RXUPSLOT15        7            /*  Receive Upstream Data Slot 15 */
#define BITP_AD242X_UPMASK1_RXUPSLOT14        6            /*  Receive Upstream Data Slot 14 */
#define BITP_AD242X_UPMASK1_RXUPSLOT13        5            /*  Receive Upstream Data Slot 13 */
#define BITP_AD242X_UPMASK1_RXUPSLOT12        4            /*  Receive Upstream Data Slot 12 */
#define BITP_AD242X_UPMASK1_RXUPSLOT11        3            /*  Receive Upstream Data Slot 11 */
#define BITP_AD242X_UPMASK1_RXUPSLOT10        2            /*  Receive Upstream Data Slot 10 */
#define BITP_AD242X_UPMASK1_RXUPSLOT09        1            /*  Receive Upstream Data Slot 9 */
#define BITP_AD242X_UPMASK1_RXUPSLOT08        0            /*  Receive Upstream Data Slot 8 */
#define BITL_AD242X_UPMASK1_RXUPSLOT08        1            /*  Receive Upstream Data Slot 8 */
#define BITL_AD242X_UPMASK1_RXUPSLOT09        1            /*  Receive Upstream Data Slot 9 */
#define BITL_AD242X_UPMASK1_RXUPSLOT10        1            /*  Receive Upstream Data Slot 10 */
#define BITL_AD242X_UPMASK1_RXUPSLOT11        1            /*  Receive Upstream Data Slot 11 */
#define BITL_AD242X_UPMASK1_RXUPSLOT12        1            /*  Receive Upstream Data Slot 12 */
#define BITL_AD242X_UPMASK1_RXUPSLOT13        1            /*  Receive Upstream Data Slot 13 */
#define BITL_AD242X_UPMASK1_RXUPSLOT14        1            /*  Receive Upstream Data Slot 14 */
#define BITL_AD242X_UPMASK1_RXUPSLOT15        1            /*  Receive Upstream Data Slot 15 */

#define BITM_AD242X_UPMASK1_RXUPSLOT15       0x00000080    /*  Receive Upstream Data Slot 15 */

#define BITM_AD242X_UPMASK1_RXUPSLOT14       0x00000040    /*  Receive Upstream Data Slot 14 */

#define BITM_AD242X_UPMASK1_RXUPSLOT13       0x00000020    /*  Receive Upstream Data Slot 13 */

#define BITM_AD242X_UPMASK1_RXUPSLOT12       0x00000010    /*  Receive Upstream Data Slot 12 */

#define BITM_AD242X_UPMASK1_RXUPSLOT11       0x00000008    /*  Receive Upstream Data Slot 11 */

#define BITM_AD242X_UPMASK1_RXUPSLOT10       0x00000004    /*  Receive Upstream Data Slot 10 */

#define BITM_AD242X_UPMASK1_RXUPSLOT09       0x00000002    /*  Receive Upstream Data Slot 9 */

#define BITM_AD242X_UPMASK1_RXUPSLOT08       0x00000001    /*  Receive Upstream Data Slot 8 */
#define ENUM_AD242X_UPMASK1_RXUPSLOT15_DIS   0x00000000            /*  RXUPSLOT15: Upstream Data Slot 15 RX Disabled */
#define ENUM_AD242X_UPMASK1_RXUPSLOT15_EN    0x00000080            /*  RXUPSLOT15: Upstream Data Slot 15 RX Enabled */
#define ENUM_AD242X_UPMASK1_RXUPSLOT14_DIS   0x00000000            /*  RXUPSLOT14: Upstream Data Slot 14 RX Disabled */
#define ENUM_AD242X_UPMASK1_RXUPSLOT14_EN    0x00000040            /*  RXUPSLOT14: Upstream Data Slot 14 RX Enabled */
#define ENUM_AD242X_UPMASK1_RXUPSLOT13_DIS   0x00000000            /*  RXUPSLOT13: Upstream Data Slot 13 RX Disabled */
#define ENUM_AD242X_UPMASK1_RXUPSLOT13_EN    0x00000020            /*  RXUPSLOT13: Upstream Data Slot 13 RX Enabled */
#define ENUM_AD242X_UPMASK1_RXUPSLOT12_DIS   0x00000000            /*  RXUPSLOT12: Upstream Data Slot 12 RX Disabled */
#define ENUM_AD242X_UPMASK1_RXUPSLOT12_EN    0x00000010            /*  RXUPSLOT12: Upstream Data Slot 12 RX Enabled */
#define ENUM_AD242X_UPMASK1_RXUPSLOT11_DIS   0x00000000            /*  RXUPSLOT11: Upstream Data Slot 11 RX Disabled */
#define ENUM_AD242X_UPMASK1_RXUPSLOT11_EN    0x00000008            /*  RXUPSLOT11: Upstream Data Slot 11 RX Enabled */
#define ENUM_AD242X_UPMASK1_RXUPSLOT10_DIS   0x00000000            /*  RXUPSLOT10: Upstream Data Slot 10 RX Disabled */
#define ENUM_AD242X_UPMASK1_RXUPSLOT10_EN    0x00000004            /*  RXUPSLOT10: Upstream Data Slot 10 RX Enabled */
#define ENUM_AD242X_UPMASK1_RXUPSLOT09_DIS   0x00000000            /*  RXUPSLOT09: Upstream Data Slot 9 RX Disabled */
#define ENUM_AD242X_UPMASK1_RXUPSLOT09_EN    0x00000002            /*  RXUPSLOT09: Upstream Data Slot 9 RX Enabled */
#define ENUM_AD242X_UPMASK1_RXUPSLOT08_DIS   0x00000000            /*  RXUPSLOT08: Upstream Data Slot 8 RX Disabled */
#define ENUM_AD242X_UPMASK1_RXUPSLOT08_EN    0x00000001            /*  RXUPSLOT08: Upstream Data Slot 8 RX Enabled */

/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_UPMASK2                       Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_UPMASK2_RXUPSLOT23        7            /*  Receive Upstream Data Slot 23 */
#define BITP_AD242X_UPMASK2_RXUPSLOT22        6            /*  Receive Upstream Data Slot 22 */
#define BITP_AD242X_UPMASK2_RXUPSLOT21        5            /*  Receive Upstream Data Slot 21 */
#define BITP_AD242X_UPMASK2_RXUPSLOT20        4            /*  Receive Upstream Data Slot 20 */
#define BITP_AD242X_UPMASK2_RXUPSLOT19        3            /*  Receive Upstream Data Slot 19 */
#define BITP_AD242X_UPMASK2_RXUPSLOT18        2            /*  Receive Upstream Data Slot 18 */
#define BITP_AD242X_UPMASK2_RXUPSLOT17        1            /*  Receive Upstream Data Slot 17 */
#define BITP_AD242X_UPMASK2_RXUPSLOT16        0            /*  Receive Upstream Data Slot 16 */
#define BITL_AD242X_UPMASK2_RXUPSLOT16        1            /*  Receive Upstream Data Slot 16 */
#define BITL_AD242X_UPMASK2_RXUPSLOT17        1            /*  Receive Upstream Data Slot 17 */
#define BITL_AD242X_UPMASK2_RXUPSLOT18        1            /*  Receive Upstream Data Slot 18 */
#define BITL_AD242X_UPMASK2_RXUPSLOT19        1            /*  Receive Upstream Data Slot 19 */
#define BITL_AD242X_UPMASK2_RXUPSLOT20        1            /*  Receive Upstream Data Slot 20 */
#define BITL_AD242X_UPMASK2_RXUPSLOT21        1            /*  Receive Upstream Data Slot 21 */
#define BITL_AD242X_UPMASK2_RXUPSLOT22        1            /*  Receive Upstream Data Slot 22 */
#define BITL_AD242X_UPMASK2_RXUPSLOT23        1            /*  Receive Upstream Data Slot 23 */

#define BITM_AD242X_UPMASK2_RXUPSLOT23       0x00000080    /*  Receive Upstream Data Slot 23 */

#define BITM_AD242X_UPMASK2_RXUPSLOT22       0x00000040    /*  Receive Upstream Data Slot 22 */

#define BITM_AD242X_UPMASK2_RXUPSLOT21       0x00000020    /*  Receive Upstream Data Slot 21 */

#define BITM_AD242X_UPMASK2_RXUPSLOT20       0x00000010    /*  Receive Upstream Data Slot 20 */

#define BITM_AD242X_UPMASK2_RXUPSLOT19       0x00000008    /*  Receive Upstream Data Slot 19 */

#define BITM_AD242X_UPMASK2_RXUPSLOT18       0x00000004    /*  Receive Upstream Data Slot 18 */

#define BITM_AD242X_UPMASK2_RXUPSLOT17       0x00000002    /*  Receive Upstream Data Slot 17 */

#define BITM_AD242X_UPMASK2_RXUPSLOT16       0x00000001    /*  Receive Upstream Data Slot 16 */
#define ENUM_AD242X_UPMASK2_RXUPSLOT23_DIS   0x00000000            /*  RXUPSLOT23: Upstream Data Slot 23 RX Disabled */
#define ENUM_AD242X_UPMASK2_RXUPSLOT23_EN    0x00000080            /*  RXUPSLOT23: Upstream Data Slot 23 RX Enabled */
#define ENUM_AD242X_UPMASK2_RXUPSLOT22_DIS   0x00000000            /*  RXUPSLOT22: Upstream Data Slot 22 RX Disabled */
#define ENUM_AD242X_UPMASK2_RXUPSLOT22_EN    0x00000040            /*  RXUPSLOT22: Upstream Data Slot 22 RX Enabled */
#define ENUM_AD242X_UPMASK2_RXUPSLOT21_DIS   0x00000000            /*  RXUPSLOT21: Upstream Data Slot 21 RX Disabled */
#define ENUM_AD242X_UPMASK2_RXUPSLOT21_EN    0x00000020            /*  RXUPSLOT21: Upstream Data Slot 21 RX Enabled */
#define ENUM_AD242X_UPMASK2_RXUPSLOT20_DIS   0x00000000            /*  RXUPSLOT20: Upstream Data Slot 20 RX Disabled */
#define ENUM_AD242X_UPMASK2_RXUPSLOT20_EN    0x00000010            /*  RXUPSLOT20: Upstream Data Slot 20 RX Enabled */
#define ENUM_AD242X_UPMASK2_RXUPSLOT19_DIS   0x00000000            /*  RXUPSLOT19: Upstream Data Slot 19 RX Disabled */
#define ENUM_AD242X_UPMASK2_RXUPSLOT19_EN    0x00000008            /*  RXUPSLOT19: Upstream Data Slot 19 RX Enabled */
#define ENUM_AD242X_UPMASK2_RXUPSLOT18_DIS   0x00000000            /*  RXUPSLOT18: Upstream Data Slot 18 RX Disabled */
#define ENUM_AD242X_UPMASK2_RXUPSLOT18_EN    0x00000004            /*  RXUPSLOT18: Upstream Data Slot 18 RX Enabled */
#define ENUM_AD242X_UPMASK2_RXUPSLOT17_DIS   0x00000000            /*  RXUPSLOT17: Upstream Data Slot 17 RX Disabled */
#define ENUM_AD242X_UPMASK2_RXUPSLOT17_EN    0x00000002            /*  RXUPSLOT17: Upstream Data Slot 17 RX Enabled */
#define ENUM_AD242X_UPMASK2_RXUPSLOT16_DIS   0x00000000            /*  RXUPSLOT16: Upstream Data Slot 16 RX Disabled */
#define ENUM_AD242X_UPMASK2_RXUPSLOT16_EN    0x00000001            /*  RXUPSLOT16: Upstream Data Slot 16 RX Enabled */

/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_UPMASK3                       Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_UPMASK3_RXUPSLOT31        7            /*  Receive Upstream Data Slot 31 */
#define BITP_AD242X_UPMASK3_RXUPSLOT30        6            /*  Receive Upstream Data Slot 30 */
#define BITP_AD242X_UPMASK3_RXUPSLOT29        5            /*  Receive Upstream Data Slot 29 */
#define BITP_AD242X_UPMASK3_RXUPSLOT28        4            /*  Receive Upstream Data Slot 28 */
#define BITP_AD242X_UPMASK3_RXUPSLOT27        3            /*  Receive Upstream Data Slot 27 */
#define BITP_AD242X_UPMASK3_RXUPSLOT26        2            /*  Receive Upstream Data Slot 26 */
#define BITP_AD242X_UPMASK3_RXUPSLOT25        1            /*  Receive Upstream Data Slot 25 */
#define BITP_AD242X_UPMASK3_RXUPSLOT24        0            /*  Receive Upstream Data Slot 24 */
#define BITL_AD242X_UPMASK3_RXUPSLOT24        1            /*  Receive Upstream Data Slot 24 */
#define BITL_AD242X_UPMASK3_RXUPSLOT25        1            /*  Receive Upstream Data Slot 25 */
#define BITL_AD242X_UPMASK3_RXUPSLOT26        1            /*  Receive Upstream Data Slot 26 */
#define BITL_AD242X_UPMASK3_RXUPSLOT27        1            /*  Receive Upstream Data Slot 27 */
#define BITL_AD242X_UPMASK3_RXUPSLOT28        1            /*  Receive Upstream Data Slot 28 */
#define BITL_AD242X_UPMASK3_RXUPSLOT29        1            /*  Receive Upstream Data Slot 29 */
#define BITL_AD242X_UPMASK3_RXUPSLOT30        1            /*  Receive Upstream Data Slot 30 */
#define BITL_AD242X_UPMASK3_RXUPSLOT31        1            /*  Receive Upstream Data Slot 31 */

#define BITM_AD242X_UPMASK3_RXUPSLOT31       0x00000080    /*  Receive Upstream Data Slot 31 */

#define BITM_AD242X_UPMASK3_RXUPSLOT30       0x00000040    /*  Receive Upstream Data Slot 30 */

#define BITM_AD242X_UPMASK3_RXUPSLOT29       0x00000020    /*  Receive Upstream Data Slot 29 */

#define BITM_AD242X_UPMASK3_RXUPSLOT28       0x00000010    /*  Receive Upstream Data Slot 28 */

#define BITM_AD242X_UPMASK3_RXUPSLOT27       0x00000008    /*  Receive Upstream Data Slot 27 */

#define BITM_AD242X_UPMASK3_RXUPSLOT26       0x00000004    /*  Receive Upstream Data Slot 26 */

#define BITM_AD242X_UPMASK3_RXUPSLOT25       0x00000002    /*  Receive Upstream Data Slot 25 */

#define BITM_AD242X_UPMASK3_RXUPSLOT24       0x00000001    /*  Receive Upstream Data Slot 24 */
#define ENUM_AD242X_UPMASK3_RXUPSLOT31_DIS   0x00000000            /*  RXUPSLOT31: Upstream Data Slot 31 RX Disabled */
#define ENUM_AD242X_UPMASK3_RXUPSLOT31_EN    0x00000080            /*  RXUPSLOT31: Upstream Data Slot 31 RX Enabled */
#define ENUM_AD242X_UPMASK3_RXUPSLOT30_DIS   0x00000000            /*  RXUPSLOT30: Upstream Data Slot 30 RX Disabled */
#define ENUM_AD242X_UPMASK3_RXUPSLOT30_EN    0x00000040            /*  RXUPSLOT30: Upstream Data Slot 30 RX Enabled */
#define ENUM_AD242X_UPMASK3_RXUPSLOT29_DIS   0x00000000            /*  RXUPSLOT29: Upstream Data Slot 29 RX Disabled */
#define ENUM_AD242X_UPMASK3_RXUPSLOT29_EN    0x00000020            /*  RXUPSLOT29: Upstream Data Slot 29 RX Enabled */
#define ENUM_AD242X_UPMASK3_RXUPSLOT28_DIS   0x00000000            /*  RXUPSLOT28: Upstream Data Slot 28 RX Disabled */
#define ENUM_AD242X_UPMASK3_RXUPSLOT28_EN    0x00000010            /*  RXUPSLOT28: Upstream Data Slot 28 RX Enabled */
#define ENUM_AD242X_UPMASK3_RXUPSLOT27_DIS   0x00000000            /*  RXUPSLOT27: Upstream Data Slot 27 RX Disabled */
#define ENUM_AD242X_UPMASK3_RXUPSLOT27_EN    0x00000008            /*  RXUPSLOT27: Upstream Data Slot 27 RX Enabled */
#define ENUM_AD242X_UPMASK3_RXUPSLOT26_DIS   0x00000000            /*  RXUPSLOT26: Upstream Data Slot 26 RX Disabled */
#define ENUM_AD242X_UPMASK3_RXUPSLOT26_EN    0x00000004            /*  RXUPSLOT26: Upstream Data Slot 26 RX Enabled */
#define ENUM_AD242X_UPMASK3_RXUPSLOT25_DIS   0x00000000            /*  RXUPSLOT25: Upstream Data Slot 25 RX Disabled */
#define ENUM_AD242X_UPMASK3_RXUPSLOT25_EN    0x00000002            /*  RXUPSLOT25: Upstream Data Slot 25 RX Enabled */
#define ENUM_AD242X_UPMASK3_RXUPSLOT24_DIS   0x00000000            /*  RXUPSLOT24: Upstream Data Slot 24 RX Disabled */
#define ENUM_AD242X_UPMASK3_RXUPSLOT24_EN    0x00000001            /*  RXUPSLOT24: Upstream Data Slot 24 RX Enabled */

/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_DNMASK0                       Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_DNMASK0_RXDNSLOT07        7            /*  Receive Downstream Data Slot 7 */
#define BITP_AD242X_DNMASK0_RXDNSLOT06        6            /*  Receive Downstream Data Slot 6 */
#define BITP_AD242X_DNMASK0_RXDNSLOT05        5            /*  Receive Downstream Data Slot 5 */
#define BITP_AD242X_DNMASK0_RXDNSLOT04        4            /*  Receive Downstream Data Slot 4 */
#define BITP_AD242X_DNMASK0_RXDNSLOT03        3            /*  Receive Downstream Data Slot 3 */
#define BITP_AD242X_DNMASK0_RXDNSLOT02        2            /*  Receive Downstream Data Slot 2 */
#define BITP_AD242X_DNMASK0_RXDNSLOT01        1            /*  Receive Downstream Data Slot 1 */
#define BITP_AD242X_DNMASK0_RXDNSLOT00        0            /*  Receive Downstream Data Slot 0 */
#define BITL_AD242X_DNMASK0_RXDNSLOT00        1            /*  Receive Downstream Data Slot 0 */
#define BITL_AD242X_DNMASK0_RXDNSLOT01        1            /*  Receive Downstream Data Slot 1 */
#define BITL_AD242X_DNMASK0_RXDNSLOT02        1            /*  Receive Downstream Data Slot 2 */
#define BITL_AD242X_DNMASK0_RXDNSLOT03        1            /*  Receive Downstream Data Slot 3 */
#define BITL_AD242X_DNMASK0_RXDNSLOT04        1            /*  Receive Downstream Data Slot 4 */
#define BITL_AD242X_DNMASK0_RXDNSLOT05        1            /*  Receive Downstream Data Slot 5 */
#define BITL_AD242X_DNMASK0_RXDNSLOT06        1            /*  Receive Downstream Data Slot 6 */
#define BITL_AD242X_DNMASK0_RXDNSLOT07        1            /*  Receive Downstream Data Slot 7 */

#define BITM_AD242X_DNMASK0_RXDNSLOT07       0x00000080    /*  Receive Downstream Data Slot 7 */

#define BITM_AD242X_DNMASK0_RXDNSLOT06       0x00000040    /*  Receive Downstream Data Slot 6 */

#define BITM_AD242X_DNMASK0_RXDNSLOT05       0x00000020    /*  Receive Downstream Data Slot 5 */

#define BITM_AD242X_DNMASK0_RXDNSLOT04       0x00000010    /*  Receive Downstream Data Slot 4 */

#define BITM_AD242X_DNMASK0_RXDNSLOT03       0x00000008    /*  Receive Downstream Data Slot 3 */

#define BITM_AD242X_DNMASK0_RXDNSLOT02       0x00000004    /*  Receive Downstream Data Slot 2 */

#define BITM_AD242X_DNMASK0_RXDNSLOT01       0x00000002    /*  Receive Downstream Data Slot 1 */

#define BITM_AD242X_DNMASK0_RXDNSLOT00       0x00000001    /*  Receive Downstream Data Slot 0 */
#define ENUM_AD242X_DNMASK0_RXDNSLOT07_DIS   0x00000000            /*  RXDNSLOT07: Downstream Data Slot 7 RX Disabled */
#define ENUM_AD242X_DNMASK0_RXDNSLOT07_EN    0x00000080            /*  RXDNSLOT07: Downstream Data Slot 7 RX Enabled */
#define ENUM_AD242X_DNMASK0_RXDNSLOT06_DIS   0x00000000            /*  RXDNSLOT06: Downstream Data Slot 6 RX Disabled */
#define ENUM_AD242X_DNMASK0_RXDNSLOT06_EN    0x00000040            /*  RXDNSLOT06: Downstream Data Slot 6 RX Enabled */
#define ENUM_AD242X_DNMASK0_RXDNSLOT05_DIS   0x00000000            /*  RXDNSLOT05: Downstream Data Slot 5 RX Disabled */
#define ENUM_AD242X_DNMASK0_RXDNSLOT05_EN    0x00000020            /*  RXDNSLOT05: Downstream Data Slot 5 RX Enabled */
#define ENUM_AD242X_DNMASK0_RXDNSLOT04_DIS   0x00000000            /*  RXDNSLOT04: Downstream Data Slot 4 RX Disabled */
#define ENUM_AD242X_DNMASK0_RXDNSLOT04_EN    0x00000010            /*  RXDNSLOT04: Downstream Data Slot 4 RX Enabled */
#define ENUM_AD242X_DNMASK0_RXDNSLOT03_DIS   0x00000000            /*  RXDNSLOT03: Downstream Data Slot 3 RX Disabled */
#define ENUM_AD242X_DNMASK0_RXDNSLOT03_EN    0x00000008            /*  RXDNSLOT03: Downstream Data Slot 3 RX Enabled */
#define ENUM_AD242X_DNMASK0_RXDNSLOT02_DIS   0x00000000            /*  RXDNSLOT02: Downstream Data Slot 2 RX Disabled */
#define ENUM_AD242X_DNMASK0_RXDNSLOT02_EN    0x00000004            /*  RXDNSLOT02: Downstream Data Slot 2 RX Enabled */
#define ENUM_AD242X_DNMASK0_RXDNSLOT01_DIS   0x00000000            /*  RXDNSLOT01: Downstream Data Slot 1 RX Disabled */
#define ENUM_AD242X_DNMASK0_RXDNSLOT01_EN    0x00000002            /*  RXDNSLOT01: Downstream Data Slot 1 RX Enabled */
#define ENUM_AD242X_DNMASK0_RXDNSLOT00_DIS   0x00000000            /*  RXDNSLOT00: Downstream Data Slot 0 RX Disabled */
#define ENUM_AD242X_DNMASK0_RXDNSLOT00_EN    0x00000001            /*  RXDNSLOT00: Downstream Data Slot 0 RX Enabled */

/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_DNMASK1                       Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_DNMASK1_RXDNSLOT15        7            /*  Receive Downstream Data Slot 15 */
#define BITP_AD242X_DNMASK1_RXDNSLOT14        6            /*  Receive Downstream Data Slot 14 */
#define BITP_AD242X_DNMASK1_RXDNSLOT13        5            /*  Receive Downstream Data Slot 13 */
#define BITP_AD242X_DNMASK1_RXDNSLOT12        4            /*  Receive Downstream Data Slot 12 */
#define BITP_AD242X_DNMASK1_RXDNSLOT11        3            /*  Receive Downstream Data Slot 11 */
#define BITP_AD242X_DNMASK1_RXDNSLOT10        2            /*  Receive Downstream Data Slot 10 */
#define BITP_AD242X_DNMASK1_RXDNSLOT09        1            /*  Receive Downstream Data Slot 9 */
#define BITP_AD242X_DNMASK1_RXDNSLOT08        0            /*  Receive Downstream Data Slot 8 */
#define BITL_AD242X_DNMASK1_RXDNSLOT08        1            /*  Receive Downstream Data Slot 8 */
#define BITL_AD242X_DNMASK1_RXDNSLOT09        1            /*  Receive Downstream Data Slot 9 */
#define BITL_AD242X_DNMASK1_RXDNSLOT10        1            /*  Receive Downstream Data Slot 10 */
#define BITL_AD242X_DNMASK1_RXDNSLOT11        1            /*  Receive Downstream Data Slot 11 */
#define BITL_AD242X_DNMASK1_RXDNSLOT12        1            /*  Receive Downstream Data Slot 12 */
#define BITL_AD242X_DNMASK1_RXDNSLOT13        1            /*  Receive Downstream Data Slot 13 */
#define BITL_AD242X_DNMASK1_RXDNSLOT14        1            /*  Receive Downstream Data Slot 14 */
#define BITL_AD242X_DNMASK1_RXDNSLOT15        1            /*  Receive Downstream Data Slot 15 */

#define BITM_AD242X_DNMASK1_RXDNSLOT15       0x00000080    /*  Receive Downstream Data Slot 15 */

#define BITM_AD242X_DNMASK1_RXDNSLOT14       0x00000040    /*  Receive Downstream Data Slot 14 */

#define BITM_AD242X_DNMASK1_RXDNSLOT13       0x00000020    /*  Receive Downstream Data Slot 13 */

#define BITM_AD242X_DNMASK1_RXDNSLOT12       0x00000010    /*  Receive Downstream Data Slot 12 */

#define BITM_AD242X_DNMASK1_RXDNSLOT11       0x00000008    /*  Receive Downstream Data Slot 11 */

#define BITM_AD242X_DNMASK1_RXDNSLOT10       0x00000004    /*  Receive Downstream Data Slot 10 */

#define BITM_AD242X_DNMASK1_RXDNSLOT09       0x00000002    /*  Receive Downstream Data Slot 9 */

#define BITM_AD242X_DNMASK1_RXDNSLOT08       0x00000001    /*  Receive Downstream Data Slot 8 */
#define ENUM_AD242X_DNMASK1_RXDNSLOT15_DIS   0x00000000            /*  RXDNSLOT15: Downstream Data Slot 15 RX Disabled */
#define ENUM_AD242X_DNMASK1_RXDNSLOT15_EN    0x00000080            /*  RXDNSLOT15: Downstream Data Slot 15 RX Enabled */
#define ENUM_AD242X_DNMASK1_RXDNSLOT14_DIS   0x00000000            /*  RXDNSLOT14: Downstream Data Slot 14 RX Disabled */
#define ENUM_AD242X_DNMASK1_RXDNSLOT14_EN    0x00000040            /*  RXDNSLOT14: Downstream Data Slot 14 RX Enabled */
#define ENUM_AD242X_DNMASK1_RXDNSLOT13_DIS   0x00000000            /*  RXDNSLOT13: Downstream Data Slot 13 RX Disabled */
#define ENUM_AD242X_DNMASK1_RXDNSLOT13_EN    0x00000020            /*  RXDNSLOT13: Downstream Data Slot 13 RX Enabled */
#define ENUM_AD242X_DNMASK1_RXDNSLOT12_DIS   0x00000000            /*  RXDNSLOT12: Downstream Data Slot 12 RX Disabled */
#define ENUM_AD242X_DNMASK1_RXDNSLOT12_EN    0x00000010            /*  RXDNSLOT12: Downstream Data Slot 12 RX Enabled */
#define ENUM_AD242X_DNMASK1_RXDNSLOT11_DIS   0x00000000            /*  RXDNSLOT11: Downstream Data Slot 11 RX Disabled */
#define ENUM_AD242X_DNMASK1_RXDNSLOT11_EN    0x00000008            /*  RXDNSLOT11: Downstream Data Slot 11 RX Enabled */
#define ENUM_AD242X_DNMASK1_RXDNSLOT10_DIS   0x00000000            /*  RXDNSLOT10: Downstream Data Slot 10 RX Disabled */
#define ENUM_AD242X_DNMASK1_RXDNSLOT10_EN    0x00000004            /*  RXDNSLOT10: Downstream Data Slot 10 RX Enabled */
#define ENUM_AD242X_DNMASK1_RXDNSLOT09_DIS   0x00000000            /*  RXDNSLOT09: Downstream Data Slot 9 RX Disabled */
#define ENUM_AD242X_DNMASK1_RXDNSLOT09_EN    0x00000002            /*  RXDNSLOT09: Downstream Data Slot 9 RX Enabled */
#define ENUM_AD242X_DNMASK1_RXDNSLOT08_DIS   0x00000000            /*  RXDNSLOT08: Downstream Data Slot 8 RX Disabled */
#define ENUM_AD242X_DNMASK1_RXDNSLOT08_EN    0x00000001            /*  RXDNSLOT08: Downstream Data Slot 8 RX Enabled */

/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_DNMASK2                       Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_DNMASK2_RXDNSLOT23        7            /*  Receive Downstream Data Slot 23 */
#define BITP_AD242X_DNMASK2_RXDNSLOT22        6            /*  Receive Downstream Data Slot 22 */
#define BITP_AD242X_DNMASK2_RXDNSLOT21        5            /*  Receive Downstream Data Slot 21 */
#define BITP_AD242X_DNMASK2_RXDNSLOT20        4            /*  Receive Downstream Data Slot 20 */
#define BITP_AD242X_DNMASK2_RXDNSLOT19        3            /*  Receive Downstream Data Slot 19 */
#define BITP_AD242X_DNMASK2_RXDNSLOT18        2            /*  Receive Downstream Data Slot 18 */
#define BITP_AD242X_DNMASK2_RXDNSLOT17        1            /*  Receive Downstream Data Slot 17 */
#define BITP_AD242X_DNMASK2_RXDNSLOT16        0            /*  Receive Downstream Data Slot 16 */
#define BITL_AD242X_DNMASK2_RXDNSLOT16        1            /*  Receive Downstream Data Slot 16 */
#define BITL_AD242X_DNMASK2_RXDNSLOT17        1            /*  Receive Downstream Data Slot 17 */
#define BITL_AD242X_DNMASK2_RXDNSLOT18        1            /*  Receive Downstream Data Slot 18 */
#define BITL_AD242X_DNMASK2_RXDNSLOT19        1            /*  Receive Downstream Data Slot 19 */
#define BITL_AD242X_DNMASK2_RXDNSLOT20        1            /*  Receive Downstream Data Slot 20 */
#define BITL_AD242X_DNMASK2_RXDNSLOT21        1            /*  Receive Downstream Data Slot 21 */
#define BITL_AD242X_DNMASK2_RXDNSLOT22        1            /*  Receive Downstream Data Slot 22 */
#define BITL_AD242X_DNMASK2_RXDNSLOT23        1            /*  Receive Downstream Data Slot 23 */

#define BITM_AD242X_DNMASK2_RXDNSLOT23       0x00000080    /*  Receive Downstream Data Slot 23 */

#define BITM_AD242X_DNMASK2_RXDNSLOT22       0x00000040    /*  Receive Downstream Data Slot 22 */

#define BITM_AD242X_DNMASK2_RXDNSLOT21       0x00000020    /*  Receive Downstream Data Slot 21 */

#define BITM_AD242X_DNMASK2_RXDNSLOT20       0x00000010    /*  Receive Downstream Data Slot 20 */

#define BITM_AD242X_DNMASK2_RXDNSLOT19       0x00000008    /*  Receive Downstream Data Slot 19 */

#define BITM_AD242X_DNMASK2_RXDNSLOT18       0x00000004    /*  Receive Downstream Data Slot 18 */

#define BITM_AD242X_DNMASK2_RXDNSLOT17       0x00000002    /*  Receive Downstream Data Slot 17 */

#define BITM_AD242X_DNMASK2_RXDNSLOT16       0x00000001    /*  Receive Downstream Data Slot 16 */
#define ENUM_AD242X_DNMASK2_RXDNSLOT23_DIS   0x00000000            /*  RXDNSLOT23: Downstream Data Slot 23 RX Disabled */
#define ENUM_AD242X_DNMASK2_RXDNSLOT23_EN    0x00000080            /*  RXDNSLOT23: Downstream Data Slot 23 RX Enabled */
#define ENUM_AD242X_DNMASK2_RXDNSLOT22_DIS   0x00000000            /*  RXDNSLOT22: Downstream Data Slot 22 RX Disabled */
#define ENUM_AD242X_DNMASK2_RXDNSLOT22_EN    0x00000040            /*  RXDNSLOT22: Downstream Data Slot 22 RX Enabled */
#define ENUM_AD242X_DNMASK2_RXDNSLOT21_DIS   0x00000000            /*  RXDNSLOT21: Downstream Data Slot 21 RX Disabled */
#define ENUM_AD242X_DNMASK2_RXDNSLOT21_EN    0x00000020            /*  RXDNSLOT21: Downstream Data Slot 21 RX Enabled */
#define ENUM_AD242X_DNMASK2_RXDNSLOT20_DIS   0x00000000            /*  RXDNSLOT20: Downstream Data Slot 20 RX Disabled */
#define ENUM_AD242X_DNMASK2_RXDNSLOT20_EN    0x00000010            /*  RXDNSLOT20: Downstream Data Slot 20 RX Enabled */
#define ENUM_AD242X_DNMASK2_RXDNSLOT19_DIS   0x00000000            /*  RXDNSLOT19: Downstream Data Slot 19 RX Disabled */
#define ENUM_AD242X_DNMASK2_RXDNSLOT19_EN    0x00000008            /*  RXDNSLOT19: Downstream Data Slot 19 RX Enabled */
#define ENUM_AD242X_DNMASK2_RXDNSLOT18_DIS   0x00000000            /*  RXDNSLOT18: Downstream Data Slot 18 RX Disabled */
#define ENUM_AD242X_DNMASK2_RXDNSLOT18_EN    0x00000004            /*  RXDNSLOT18: Downstream Data Slot 18 RX Enabled */
#define ENUM_AD242X_DNMASK2_RXDNSLOT17_DIS   0x00000000            /*  RXDNSLOT17: Downstream Data Slot 17 RX Disabled */
#define ENUM_AD242X_DNMASK2_RXDNSLOT17_EN    0x00000002            /*  RXDNSLOT17: Downstream Data Slot 17 RX Enabled */
#define ENUM_AD242X_DNMASK2_RXDNSLOT16_DIS   0x00000000            /*  RXDNSLOT16: Downstream Data Slot 16 RX Disabled */
#define ENUM_AD242X_DNMASK2_RXDNSLOT16_EN    0x00000001            /*  RXDNSLOT16: Downstream Data Slot 16 RX Enabled */

/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_DNMASK3                       Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_DNMASK3_RXDNSLOT31        7            /*  Receive Downstream Data Slot 31 */
#define BITP_AD242X_DNMASK3_RXDNSLOT30        6            /*  Receive Downstream Data Slot 30 */
#define BITP_AD242X_DNMASK3_RXDNSLOT29        5            /*  Receive Downstream Data Slot 29 */
#define BITP_AD242X_DNMASK3_RXDNSLOT28        4            /*  Receive Downstream Data Slot 28 */
#define BITP_AD242X_DNMASK3_RXDNSLOT27        3            /*  Receive Downstream Data Slot 27 */
#define BITP_AD242X_DNMASK3_RXDNSLOT26        2            /*  Receive Downstream Data Slot 26 */
#define BITP_AD242X_DNMASK3_RXDNSLOT25        1            /*  Receive Downstream Data Slot 25 */
#define BITP_AD242X_DNMASK3_RXDNSLOT24        0            /*  Receive Downstream Data Slot 24 */
#define BITL_AD242X_DNMASK3_RXDNSLOT24        1            /*  Receive Downstream Data Slot 24 */
#define BITL_AD242X_DNMASK3_RXDNSLOT25        1            /*  Receive Downstream Data Slot 25 */
#define BITL_AD242X_DNMASK3_RXDNSLOT26        1            /*  Receive Downstream Data Slot 26 */
#define BITL_AD242X_DNMASK3_RXDNSLOT27        1            /*  Receive Downstream Data Slot 27 */
#define BITL_AD242X_DNMASK3_RXDNSLOT28        1            /*  Receive Downstream Data Slot 28 */
#define BITL_AD242X_DNMASK3_RXDNSLOT29        1            /*  Receive Downstream Data Slot 29 */
#define BITL_AD242X_DNMASK3_RXDNSLOT30        1            /*  Receive Downstream Data Slot 30 */
#define BITL_AD242X_DNMASK3_RXDNSLOT31        1            /*  Receive Downstream Data Slot 31 */

#define BITM_AD242X_DNMASK3_RXDNSLOT31       0x00000080    /*  Receive Downstream Data Slot 31 */

#define BITM_AD242X_DNMASK3_RXDNSLOT30       0x00000040    /*  Receive Downstream Data Slot 30 */

#define BITM_AD242X_DNMASK3_RXDNSLOT29       0x00000020    /*  Receive Downstream Data Slot 29 */

#define BITM_AD242X_DNMASK3_RXDNSLOT28       0x00000010    /*  Receive Downstream Data Slot 28 */

#define BITM_AD242X_DNMASK3_RXDNSLOT27       0x00000008    /*  Receive Downstream Data Slot 27 */

#define BITM_AD242X_DNMASK3_RXDNSLOT26       0x00000004    /*  Receive Downstream Data Slot 26 */

#define BITM_AD242X_DNMASK3_RXDNSLOT25       0x00000002    /*  Receive Downstream Data Slot 25 */

#define BITM_AD242X_DNMASK3_RXDNSLOT24       0x00000001    /*  Receive Downstream Data Slot 24 */
#define ENUM_AD242X_DNMASK3_RXDNSLOT31_DIS   0x00000000            /*  RXDNSLOT31: Downstream Data Slot 31 RX Disabled */
#define ENUM_AD242X_DNMASK3_RXDNSLOT31_EN    0x00000080            /*  RXDNSLOT31: Downstream Data Slot 31 RX Enabled */
#define ENUM_AD242X_DNMASK3_RXDNSLOT30_DIS   0x00000000            /*  RXDNSLOT30: Downstream Data Slot 30 RX Disabled */
#define ENUM_AD242X_DNMASK3_RXDNSLOT30_EN    0x00000040            /*  RXDNSLOT30: Downstream Data Slot 30 RX Enabled */
#define ENUM_AD242X_DNMASK3_RXDNSLOT29_DIS   0x00000000            /*  RXDNSLOT29: Downstream Data Slot 29 RX Disabled */
#define ENUM_AD242X_DNMASK3_RXDNSLOT29_EN    0x00000020            /*  RXDNSLOT29: Downstream Data Slot 29 RX Enabled */
#define ENUM_AD242X_DNMASK3_RXDNSLOT28_DIS   0x00000000            /*  RXDNSLOT28: Downstream Data Slot 28 RX Disabled */
#define ENUM_AD242X_DNMASK3_RXDNSLOT28_EN    0x00000010            /*  RXDNSLOT28: Downstream Data Slot 28 RX Enabled */
#define ENUM_AD242X_DNMASK3_RXDNSLOT27_DIS   0x00000000            /*  RXDNSLOT27: Downstream Data Slot 27 RX Disabled */
#define ENUM_AD242X_DNMASK3_RXDNSLOT27_EN    0x00000008            /*  RXDNSLOT27: Downstream Data Slot 27 RX Enabled */
#define ENUM_AD242X_DNMASK3_RXDNSLOT26_DIS   0x00000000            /*  RXDNSLOT26: Downstream Data Slot 26 RX Disabled */
#define ENUM_AD242X_DNMASK3_RXDNSLOT26_EN    0x00000004            /*  RXDNSLOT26: Downstream Data Slot 26 RX Enabled */
#define ENUM_AD242X_DNMASK3_RXDNSLOT25_DIS   0x00000000            /*  RXDNSLOT25: Downstream Data Slot 25 RX Disabled */
#define ENUM_AD242X_DNMASK3_RXDNSLOT25_EN    0x00000002            /*  RXDNSLOT25: Downstream Data Slot 25 RX Enabled */
#define ENUM_AD242X_DNMASK3_RXDNSLOT24_DIS   0x00000000            /*  RXDNSLOT24: Downstream Data Slot 24 RX Disabled */
#define ENUM_AD242X_DNMASK3_RXDNSLOT24_EN    0x00000001            /*  RXDNSLOT24: Downstream Data Slot 24 RX Enabled */

/* ============================================================================================================================
 *    A2B_Configuration Register Field Definitions
 * ============================================================================================================================ */
/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_SWCTL                         Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_SWCTL_NAUTODISC           7            /*  No Auto Disconnect */
#define BITP_AD242X_SWCTL_DISNXT              6            /*  Disable Next */
#define BITP_AD242X_SWCTL_MODE                4            /*  External Switch Mode */
#define BITP_AD242X_SWCTL_DIAGMODE            3            /*  Enable Switch Diagnosis Mode */
#define BITP_AD242X_SWCTL_ORT                 1            /*  Open Reverse Timer */
#define BITP_AD242X_SWCTL_ENSW                0            /*  Enable Switch */
#define BITL_AD242X_SWCTL_MODE                2            /*  External Switch Mode */
#define BITL_AD242X_SWCTL_ORT                 2            /*  Open Reverse Timer */
#define BITL_AD242X_SWCTL_DIAGMODE            1            /*  Enable Switch Diagnosis Mode */
#define BITL_AD242X_SWCTL_DISNXT              1            /*  Disable Next */
#define BITL_AD242X_SWCTL_ENSW                1            /*  Enable Switch */
#define BITL_AD242X_SWCTL_NAUTODISC           1            /*  No Auto Disconnect */

#define BITM_AD242X_SWCTL_NAUTODISC          0x00000080    /*  No Auto Disconnect */

#define BITM_AD242X_SWCTL_DISNXT             0x00000040    /*  Disable Next */

#define BITM_AD242X_SWCTL_MODE               0x00000030    /*  External Switch Mode */

#define BITM_AD242X_SWCTL_DIAGMODE           0x00000008    /*  Enable Switch Diagnosis Mode */

#define BITM_AD242X_SWCTL_ORT                0x00000006    /*  Open Reverse Timer */

#define BITM_AD242X_SWCTL_ENSW               0x00000001    /*  Enable Switch */
#define ENUM_AD242X_SWCTL_DIAGMODE_DIS       0x00000000            /*  DIAGMODE: Switch Diagnosis Mode Disabled */
#define ENUM_AD242X_SWCTL_DIAGMODE_EN        0x00000008            /*  DIAGMODE: Switch Diagnosis Mode Enabled */
#define ENUM_AD242X_SWCTL_ENSW_DIS           0x00000000            /*  ENSW: Switches Disabled */
#define ENUM_AD242X_SWCTL_ENSW_EN            0x00000001            /*  ENSW: Switches Enabled */

/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_BMMCFG                        Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_BMMCFG_BMMNDSC            2            /*  BMM No Discovery Mode Enable */
#define BITP_AD242X_BMMCFG_BMMRXEN            1            /*  BMM LVDS XCVR RX Enable */
#define BITP_AD242X_BMMCFG_BMMEN              0            /*  Bus Monitor Mode Enable */
#define BITL_AD242X_BMMCFG_BMMEN              1            /*  Bus Monitor Mode Enable */
#define BITL_AD242X_BMMCFG_BMMNDSC            1            /*  BMM No Discovery Mode Enable */
#define BITL_AD242X_BMMCFG_BMMRXEN            1            /*  BMM LVDS XCVR RX Enable */

#define BITM_AD242X_BMMCFG_BMMNDSC           0x00000004    /*  BMM No Discovery Mode Enable */

#define BITM_AD242X_BMMCFG_BMMRXEN           0x00000002    /*  BMM LVDS XCVR RX Enable */

#define BITM_AD242X_BMMCFG_BMMEN             0x00000001    /*  Bus Monitor Mode Enable */
#define ENUM_AD242X_BMMCFG_BMMNDSC_DIS       0x00000000            /*  BMMNDSC: BMM No Discovery Mode Disabled */
#define ENUM_AD242X_BMMCFG_BMMNDSC_EN        0x00000004            /*  BMMNDSC: BMM No Discovery Mode Enabled */
#define ENUM_AD242X_BMMCFG_BMMRXEN_DIS       0x00000000            /*  BMMRXEN: BMM LVDS XCVR RX Disabled */
#define ENUM_AD242X_BMMCFG_BMMRXEN_EN        0x00000002            /*  BMMRXEN: BMM LVDS XCVR RX Enabled */
#define ENUM_AD242X_BMMCFG_BMMEN_DIS         0x00000000            /*  BMMEN: Bus Monitor Mode Disabled */
#define ENUM_AD242X_BMMCFG_BMMEN_EN          0x00000001            /*  BMMEN: Bus Monitor Mode Enabled */

/* ============================================================================================================================
 *    A2B_Control_MO Register Field Definitions
 * ============================================================================================================================ */
/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_NODEADR                       Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_NODEADR_BRCST             7            /*  Broadcast */
#define BITP_AD242X_NODEADR_PERI              5            /*  Enable Peripheral */
#define BITP_AD242X_NODEADR_NODE              0            /*  Addressed Slave Node */
#define BITL_AD242X_NODEADR_NODE              4            /*  Addressed Slave Node */
#define BITL_AD242X_NODEADR_BRCST             1            /*  Broadcast */
#define BITL_AD242X_NODEADR_PERI              1            /*  Enable Peripheral */

#define BITM_AD242X_NODEADR_BRCST            0x00000080    /*  Broadcast */

#define BITM_AD242X_NODEADR_PERI             0x00000020    /*  Enable Peripheral */

#define BITM_AD242X_NODEADR_NODE             0x0000000F    /*  Addressed Slave Node */
#define ENUM_AD242X_NODEADR_BRCST_DIS        0x00000000            /*  BRCST: Normal, directed register access */
#define ENUM_AD242X_NODEADR_BRCST_EN         0x00000080            /*  BRCST: Next write to slave nodes is handled as broadcast access */
#define ENUM_AD242X_NODEADR_PERI_DIS         0x00000000            /*  PERI: Remote Peripheral Access disabled */
#define ENUM_AD242X_NODEADR_PERI_EN          0x00000020            /*  PERI: Remote Peripheral Access enabled */
#define ENUM_AD242X_NODEADR_NODE0            0x00000000            /*  NODE: Node 0 */
#define ENUM_AD242X_NODEADR_NODE1            0x00000001            /*  NODE: Node 1 */
#define ENUM_AD242X_NODEADR_NODE2            0x00000002            /*  NODE: Node 2 */
#define ENUM_AD242X_NODEADR_NODE3            0x00000003            /*  NODE: Node 3 */
#define ENUM_AD242X_NODEADR_NODE4            0x00000004            /*  NODE: Node 4 */
#define ENUM_AD242X_NODEADR_NODE5            0x00000005            /*  NODE: Node 5 */

/* ============================================================================================================================
 *    A2B_Control_MO2 Register Field Definitions
 * ============================================================================================================================ */
/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_CONTROL                       Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_CONTROL_MSTR              7            /*  Master Node */
#define BITP_AD242X_CONTROL_SOFTRST           2            /*  Soft Reset of Protocol Engine */
#define BITP_AD242X_CONTROL_ENDDSC            1            /*  End Discovery Mode */
#define BITP_AD242X_CONTROL_NEWSTRCT          0            /*  New Structure */
#define BITL_AD242X_CONTROL_ENDDSC            1            /*  End Discovery Mode */
#define BITL_AD242X_CONTROL_MSTR              1            /*  Master Node */
#define BITL_AD242X_CONTROL_NEWSTRCT          1            /*  New Structure */
#define BITL_AD242X_CONTROL_SOFTRST           1            /*  Soft Reset of Protocol Engine */
#define BITM_AD242X_CONTROL_MSTR             0x00000080    /*  Master Node */

#define BITM_AD242X_CONTROL_SOFTRST          0x00000004    /*  Soft Reset of Protocol Engine */

#define BITM_AD242X_CONTROL_ENDDSC           0x00000002    /*  End Discovery Mode */

#define BITM_AD242X_CONTROL_NEWSTRCT         0x00000001    /*  New Structure */
#define ENUM_AD242X_CONTROL_SOFTRST_NO_ACTION 0x00000000            /*  SOFTRST: No Action */
#define ENUM_AD242X_CONTROL_RESET_PE         0x00000004            /*  SOFTRST: Reset Protocol Engine */
#define ENUM_AD242X_CONTROL_ENDDSC_NO_ACTION 0x00000000            /*  ENDDSC: No Action */
#define ENUM_AD242X_CONTROL_END_DISCOVERY    0x00000002            /*  ENDDSC: End Discovery */
#define ENUM_AD242X_CONTROL_NEWSTRCT_NO_ACTION 0x00000000            /*  NEWSTRCT: No Action */
#define ENUM_AD242X_CONTROL_START_NS         0x00000001            /*  NEWSTRCT: Enable New Structure */

/* ============================================================================================================================
 *    A2B_Start_Discovery_MO Register Field Definitions
 * ============================================================================================================================ */
/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_DISCVRY                       Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_DISCVRY_DRESPCYC          0            /*  Response Cycle Discovery */
#define BITL_AD242X_DISCVRY_DRESPCYC          8            /*  Response Cycle Discovery */
#define BITM_AD242X_DISCVRY_DRESPCYC         0x000000FF    /*  Response Cycle Discovery */

/* ============================================================================================================================
 *    A2B_Status Register Field Definitions
 * ============================================================================================================================ */
/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_NODE                          Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_NODE_LAST                 7            /*  Last Node */
#define BITP_AD242X_NODE_NLAST                6            /*  Next-to-Last Node */
#define BITP_AD242X_NODE_DISCVD               5            /*  Node Discovered */
#define BITP_AD242X_NODE_NUMBER               0            /*  Number Currently Assigned to Node */
#define BITL_AD242X_NODE_NUMBER               4            /*  Number Currently Assigned to Node */
#define BITL_AD242X_NODE_DISCVD               1            /*  Node Discovered */
#define BITL_AD242X_NODE_LAST                 1            /*  Last Node */
#define BITL_AD242X_NODE_NLAST                1            /*  Next-to-Last Node */

#define BITM_AD242X_NODE_LAST                0x00000080    /*  Last Node */

#define BITM_AD242X_NODE_NLAST               0x00000040    /*  Next-to-Last Node */

#define BITM_AD242X_NODE_DISCVD              0x00000020    /*  Node Discovered */
#define BITM_AD242X_NODE_NUMBER              0x0000000F    /*  Number Currently Assigned to Node */

/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_TRANSTAT                      Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_TRANSTAT_ECCERR           6            /*  ECC Error Code */
#define BITP_AD242X_TRANSTAT_INNS             3            /*  In New Structure Mode */
#define BITP_AD242X_TRANSTAT_INDISC           2            /*  In Discovery Mode */
#define BITL_AD242X_TRANSTAT_ECCERR           2            /*  ECC Error Code */
#define BITL_AD242X_TRANSTAT_INDISC           1            /*  In Discovery Mode */
#define BITL_AD242X_TRANSTAT_INNS             1            /*  In New Structure Mode */

#define BITM_AD242X_TRANSTAT_ECCERR          0x000000C0    /*  ECC Error Code */
#define BITM_AD242X_TRANSTAT_INNS            0x00000008    /*  In New Structure Mode */
#define BITM_AD242X_TRANSTAT_INDISC          0x00000004    /*  In Discovery Mode */

/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_DISCSTAT                      Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_DISCSTAT_DSCACT           7            /*  Discovery Active */
#define BITP_AD242X_DISCSTAT_DNODE            0            /*  Discovery Node */
#define BITL_AD242X_DISCSTAT_DNODE            4            /*  Discovery Node */
#define BITL_AD242X_DISCSTAT_DSCACT           1            /*  Discovery Active */
#define BITM_AD242X_DISCSTAT_DSCACT          0x00000080    /*  Discovery Active */
#define BITM_AD242X_DISCSTAT_DNODE           0x0000000F    /*  Discovery Node */

/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_NSCURCNT                      Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_NSCURCNT_CURCNT           0            /*  Current Count */
#define BITL_AD242X_NSCURCNT_CURCNT           3            /*  Current Count */
#define BITM_AD242X_NSCURCNT_CURCNT          0x00000007    /*  Current Count */

/* ============================================================================================================================
 *    A2B_Status_Registers Register Field Definitions
 * ============================================================================================================================ */
/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_SWSTAT                        Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_SWSTAT_FAULT_NLOC         7            /*  Cable Fault Not Localized */
#define BITP_AD242X_SWSTAT_FAULT_CODE         4            /*  Cable Fault Code */
#define BITP_AD242X_SWSTAT_FAULT              1            /*  Cable Fault */
#define BITP_AD242X_SWSTAT_FIN                0            /*  Switch Activation Complete */
#define BITL_AD242X_SWSTAT_FAULT_CODE         3            /*  Cable Fault Code */
#define BITL_AD242X_SWSTAT_FAULT              1            /*  Cable Fault */
#define BITL_AD242X_SWSTAT_FAULT_NLOC         1            /*  Cable Fault Not Localized */
#define BITL_AD242X_SWSTAT_FIN                1            /*  Switch Activation Complete */

#define BITM_AD242X_SWSTAT_FAULT_NLOC        0x00000080    /*  Cable Fault Not Localized */

#define BITM_AD242X_SWSTAT_FAULT_CODE        0x00000070    /*  Cable Fault Code */

#define BITM_AD242X_SWSTAT_FAULT             0x00000002    /*  Cable Fault */

#define BITM_AD242X_SWSTAT_FIN               0x00000001    /*  Switch Activation Complete */

/* ============================================================================================================================
 *    Chip_Test Register Field Definitions
 * ============================================================================================================================ */
/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_PTSTMODE                      Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_PTSTMODE_SWTHRSHLD        5            /*  Switch Threshold Signal */
#define BITP_AD242X_PTSTMODE_IGNSWFIN         4            /*  Ignore Switch Finished Signal */
#define BITP_AD242X_PTSTMODE_DISECC           3            /*  Disable ECC in EFuse */
#define BITP_AD242X_PTSTMODE_LDTRIMVAL        2            /*  Load Trim Value into EFuse */
#define BITP_AD242X_PTSTMODE_CRCDIS           1            /*  CRC Disable */
#define BITP_AD242X_PTSTMODE_VREGDIS          0            /*  Voltage Regulator Disable */
#define BITL_AD242X_PTSTMODE_CRCDIS           1            /*  CRC Disable */
#define BITL_AD242X_PTSTMODE_DISECC           1            /*  Disable ECC in EFuse */
#define BITL_AD242X_PTSTMODE_IGNSWFIN         1            /*  Ignore Switch Finished Signal */
#define BITL_AD242X_PTSTMODE_LDTRIMVAL        1            /*  Load Trim Value into EFuse */
#define BITL_AD242X_PTSTMODE_SWTHRSHLD        1            /*  Switch Threshold Signal */
#define BITL_AD242X_PTSTMODE_VREGDIS          1            /*  Voltage Regulator Disable */

#define BITM_AD242X_PTSTMODE_SWTHRSHLD       0x00000020    /*  Switch Threshold Signal */
#define BITM_AD242X_PTSTMODE_IGNSWFIN        0x00000010    /*  Ignore Switch Finished Signal */
#define BITM_AD242X_PTSTMODE_DISECC          0x00000008    /*  Disable ECC in EFuse */
#define BITM_AD242X_PTSTMODE_LDTRIMVAL       0x00000004    /*  Load Trim Value into EFuse */

#define BITM_AD242X_PTSTMODE_CRCDIS          0x00000002    /*  CRC Disable */

#define BITM_AD242X_PTSTMODE_VREGDIS         0x00000001    /*  Voltage Regulator Disable */

/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_STRAPVAL                      Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_STRAPVAL_STRAPVAL         0            /*  Captured Strap Pin Values */
#define BITL_AD242X_STRAPVAL_STRAPVAL         7            /*  Captured Strap Pin Values */

#define BITM_AD242X_STRAPVAL_STRAPVAL        0x0000007F    /*  Captured Strap Pin Values */

/* ============================================================================================================================
 *    EFuse Register Field Definitions
 * ============================================================================================================================ */
/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_EFUSEADDR                     Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_EFUSEADDR_ADDR            0            /*  EFuse Address */
#define BITL_AD242X_EFUSEADDR_ADDR            8            /*  EFuse Address */
#define BITM_AD242X_EFUSEADDR_ADDR           0x000000FF    /*  EFuse Address */

/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_EFUSERDAT                     Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_EFUSERDAT_RDATA           0            /*  Read Data */
#define BITL_AD242X_EFUSERDAT_RDATA           8            /*  Read Data */
#define BITM_AD242X_EFUSERDAT_RDATA          0x000000FF    /*  Read Data */

/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_EFUSEWDAT                     Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_EFUSEWDAT_WDATA           0            /*  Write Data */
#define BITL_AD242X_EFUSEWDAT_WDATA           8            /*  Write Data */
#define BITM_AD242X_EFUSEWDAT_WDATA          0x000000FF    /*  Write Data */

/* ============================================================================================================================
 *    I2C_Control_SO Register Field Definitions
 * ============================================================================================================================ */
/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_CHIP                          Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_CHIP_CHIPADR              0            /*  I2C Chip Address */
#define BITL_AD242X_CHIP_CHIPADR              7            /*  I2C Chip Address */
#define BITM_AD242X_CHIP_CHIPADR             0x0000007F    /*  I2C Chip Address */

/* ============================================================================================================================
 *    I2C_I2S_PDM_Control_Configuration Register Field Definitions
 * ============================================================================================================================ */
/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_I2CCFG                        Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_I2CCFG_FRAMERATE          2            /*  Audio Frame Rate (A2B Slave Only) */
#define BITP_AD242X_I2CCFG_EACK               1            /*  Early Acknowledge (A2B Master Only) */
#define BITP_AD242X_I2CCFG_DATARATE           0            /*  I2C Data Rate (A2B Slave Only) */
#define BITL_AD242X_I2CCFG_DATARATE           1            /*  I2C Data Rate (A2B Slave Only) */
#define BITL_AD242X_I2CCFG_EACK               1            /*  Early Acknowledge (A2B Master Only) */
#define BITL_AD242X_I2CCFG_FRAMERATE          1            /*  Audio Frame Rate (A2B Slave Only) */

#define BITM_AD242X_I2CCFG_FRAMERATE         0x00000004    /*  Audio Frame Rate (A2B Slave Only) */

#define BITM_AD242X_I2CCFG_EACK              0x00000002    /*  Early Acknowledge (A2B Master Only) */

#define BITM_AD242X_I2CCFG_DATARATE          0x00000001    /*  I2C Data Rate (A2B Slave Only) */

/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_PLLCTL                        Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_PLLCTL_DBWSEL             6            /*  Digital PLL Bandwidth Select */
#define BITP_AD242X_PLLCTL_ABWSEL             4            /*  Analog PLL Bandwidth Select */
#define BITP_AD242X_PLLCTL_DITHDIS            3            /*  Digital PLL Dither Disable */
#define BITP_AD242X_PLLCTL_BCLKSEL            2            /*  BCLK Bypass to PLL */
#define BITP_AD242X_PLLCTL_BCLKDIV            0            /*  BCLK PLL Multiplication Select */
#define BITL_AD242X_PLLCTL_ABWSEL             2            /*  Analog PLL Bandwidth Select */
#define BITL_AD242X_PLLCTL_BCLKDIV            2            /*  BCLK PLL Multiplication Select */
#define BITL_AD242X_PLLCTL_DBWSEL             2            /*  Digital PLL Bandwidth Select */
#define BITL_AD242X_PLLCTL_BCLKSEL            1            /*  BCLK Bypass to PLL */
#define BITL_AD242X_PLLCTL_DITHDIS            1            /*  Digital PLL Dither Disable */
#define BITM_AD242X_PLLCTL_DBWSEL            0x000000C0    /*  Digital PLL Bandwidth Select */

#define BITM_AD242X_PLLCTL_ABWSEL            0x00000030    /*  Analog PLL Bandwidth Select */
#define BITM_AD242X_PLLCTL_DITHDIS           0x00000008    /*  Digital PLL Dither Disable */

#define BITM_AD242X_PLLCTL_BCLKSEL           0x00000004    /*  BCLK Bypass to PLL */

#define BITM_AD242X_PLLCTL_BCLKDIV           0x00000003    /*  BCLK PLL Multiplication Select */
#define ENUM_AD242X_PLLCTL_ABWSEL_0          0x00000000            /*  ABWSEL: Zero */
#define ENUM_AD242X_PLLCTL_ABWSEL_1          0x00000010            /*  ABWSEL: One */
#define ENUM_AD242X_PLLCTL_ABWSEL_2          0x00000020            /*  ABWSEL: Two */
#define ENUM_AD242X_PLLCTL_ABWSEL_3          0x00000030            /*  ABWSEL: Three */
#define ENUM_AD242X_PLLCTL_BCLKSEL_DIS       0x00000000            /*  BCLKSEL: SYNC Selected */
#define ENUM_AD242X_PLLCTL_BCLKSEL_EN        0x00000004            /*  BCLKSEL: BCLK Selected */
#define ENUM_AD242X_PLLCTL_BCLKDIV_8X        0x00000000            /*  BCLKDIV: 1 x  (BCLK=12.288 MHz in TDM8) */
#define ENUM_AD242X_PLLCTL_BCLKDIV_4X        0x00000001            /*  BCLKDIV: 2  x (BCLK=24.576 MHz in TDM16) */
#define ENUM_AD242X_PLLCTL_BCLKDIV_2X        0x00000002            /*  BCLKDIV: 4  x  (BCLK=49.152 MHz for TDM32) */

/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_I2SGCFG                       Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_I2SGCFG_INV               7            /*  Invert Sync */
#define BITP_AD242X_I2SGCFG_EARLY             6            /*  Early Sync */
#define BITP_AD242X_I2SGCFG_ALT               5            /*  Alternating Sync */
#define BITP_AD242X_I2SGCFG_TDMSS             4            /*  TDM Slot Size */
#define BITP_AD242X_I2SGCFG_TDMMODE           0            /*  TDM Mode */
#define BITL_AD242X_I2SGCFG_TDMMODE           3            /*  TDM Mode */
#define BITL_AD242X_I2SGCFG_ALT               1            /*  Alternating Sync */
#define BITL_AD242X_I2SGCFG_EARLY             1            /*  Early Sync */
#define BITL_AD242X_I2SGCFG_INV               1            /*  Invert Sync */
#define BITL_AD242X_I2SGCFG_TDMSS             1            /*  TDM Slot Size */

#define BITM_AD242X_I2SGCFG_INV              0x00000080    /*  Invert Sync */

#define BITM_AD242X_I2SGCFG_EARLY            0x00000040    /*  Early Sync */

#define BITM_AD242X_I2SGCFG_ALT              0x00000020    /*  Alternating Sync */

#define BITM_AD242X_I2SGCFG_TDMSS            0x00000010    /*  TDM Slot Size */

#define BITM_AD242X_I2SGCFG_TDMMODE          0x00000007    /*  TDM Mode */
#define ENUM_AD242X_I2SGCFG_INV_DIS          0x00000000            /*  INV: Rising edge of SYNC pin corresponds to the start of an audio frame */
#define ENUM_AD242X_I2SGCFG_INV_EN           0x00000080            /*  INV: Falling edge of SYNC pin corresponds to the start of an audio frame */
#define ENUM_AD242X_I2SGCFG_EARLY_DIS        0x00000000            /*  EARLY: Change SYNC pin in same cycle */
#define ENUM_AD242X_I2SGCFG_EARLY_EN         0x00000040            /*  EARLY: Change SYNC pin in previous cycle */
#define ENUM_AD242X_I2SGCFG_ALT_DIS          0x00000000            /*  ALT: Drive SYNC Pin for 1 Cycle */
#define ENUM_AD242X_I2SGCFG_ALT_EN           0x00000020            /*  ALT: Drive SYNC Pin Alternating */
#define ENUM_AD242X_I2SGCFG_W32_BIT          0x00000000            /*  TDMSS: 32-Bit */
#define ENUM_AD242X_I2SGCFG_W16_BIT          0x00000010            /*  TDMSS: 16-Bit */
#define ENUM_AD242X_I2SGCFG_TDM2             0x00000000            /*  TDMMODE: TDM2 */
#define ENUM_AD242X_I2SGCFG_TDM4             0x00000001            /*  TDMMODE: TDM4 */
#define ENUM_AD242X_I2SGCFG_TDM8             0x00000002            /*  TDMMODE: TDM8 */
#define ENUM_AD242X_I2SGCFG_TDM12            0x00000003            /*  TDMMODE: TDM12 (No slave node support) */
#define ENUM_AD242X_I2SGCFG_TDM16            0x00000004            /*  TDMMODE: TDM16 */
#define ENUM_AD242X_I2SGCFG_TDM20            0x00000005            /*  TDMMODE: TDM20 (No slave node support) */
#define ENUM_AD242X_I2SGCFG_TDM24            0x00000006            /*  TDMMODE: TDM24 (No slave node support) */
#define ENUM_AD242X_I2SGCFG_TDM32            0x00000007            /*  TDMMODE: TDM32 */

/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_I2SCFG                        Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_I2SCFG_RXBCLKINV          7            /*  RX BCLK Invert */
#define BITP_AD242X_I2SCFG_RX2PINTL           6            /*  RX 2 Pin Interleave */
#define BITP_AD242X_I2SCFG_RX1EN              5            /*  I2S RX 1 Enable */
#define BITP_AD242X_I2SCFG_RX0EN              4            /*  I2S RX 0 Enable */
#define BITP_AD242X_I2SCFG_TXBCLKINV          3            /*  TX BCLK Invert */
#define BITP_AD242X_I2SCFG_TX2PINTL           2            /*  TX 2 Pin Interleave */
#define BITP_AD242X_I2SCFG_TX1EN              1            /*  I2S TX 1 Enable */
#define BITP_AD242X_I2SCFG_TX0EN              0            /*  I2S TX 0 Enable */
#define BITL_AD242X_I2SCFG_RX0EN              1            /*  I2S RX 0 Enable */
#define BITL_AD242X_I2SCFG_RX1EN              1            /*  I2S RX 1 Enable */
#define BITL_AD242X_I2SCFG_RX2PINTL           1            /*  RX 2 Pin Interleave */
#define BITL_AD242X_I2SCFG_RXBCLKINV          1            /*  RX BCLK Invert */
#define BITL_AD242X_I2SCFG_TX0EN              1            /*  I2S TX 0 Enable */
#define BITL_AD242X_I2SCFG_TX1EN              1            /*  I2S TX 1 Enable */
#define BITL_AD242X_I2SCFG_TX2PINTL           1            /*  TX 2 Pin Interleave */
#define BITL_AD242X_I2SCFG_TXBCLKINV          1            /*  TX BCLK Invert */

#define BITM_AD242X_I2SCFG_RXBCLKINV         0x00000080    /*  RX BCLK Invert */

#define BITM_AD242X_I2SCFG_RX2PINTL          0x00000040    /*  RX 2 Pin Interleave */

#define BITM_AD242X_I2SCFG_RX1EN             0x00000020    /*  I2S RX 1 Enable */

#define BITM_AD242X_I2SCFG_RX0EN             0x00000010    /*  I2S RX 0 Enable */

#define BITM_AD242X_I2SCFG_TXBCLKINV         0x00000008    /*  TX BCLK Invert */

#define BITM_AD242X_I2SCFG_TX2PINTL          0x00000004    /*  TX 2 Pin Interleave */

#define BITM_AD242X_I2SCFG_TX1EN             0x00000002    /*  I2S TX 1 Enable */

#define BITM_AD242X_I2SCFG_TX0EN             0x00000001    /*  I2S TX 0 Enable */
#define ENUM_AD242X_I2SCFG_RXBCLKINV_DIS     0x00000000            /*  RXBCLKINV: Disabled */
#define ENUM_AD242X_I2SCFG_RXBCLKINV_EN      0x00000080            /*  RXBCLKINV: Enabled */
#define ENUM_AD242X_I2SCFG_RX2PINTL_DIS      0x00000000            /*  RX2PINTL: Disabled */
#define ENUM_AD242X_I2SCFG_RX2PINTL_EN       0x00000040            /*  RX2PINTL: Enabled */
#define ENUM_AD242X_I2SCFG_RX1EN_DIS         0x00000000            /*  RX1EN: Disabled */
#define ENUM_AD242X_I2SCFG_RX1EN_EN          0x00000020            /*  RX1EN: Enabled */
#define ENUM_AD242X_I2SCFG_RX0EN_DIS         0x00000000            /*  RX0EN: Disabled */
#define ENUM_AD242X_I2SCFG_RX0EN_EN          0x00000010            /*  RX0EN: Enabled */
#define ENUM_AD242X_I2SCFG_TXBCLKINV_DIS     0x00000000            /*  TXBCLKINV: Disabled */
#define ENUM_AD242X_I2SCFG_TXBCLKINV_EN      0x00000008            /*  TXBCLKINV: Enabled */
#define ENUM_AD242X_I2SCFG_TX2PINTL_DIS      0x00000000            /*  TX2PINTL: Disabled */
#define ENUM_AD242X_I2SCFG_TX2PINTL_EN       0x00000004            /*  TX2PINTL: Enabled */
#define ENUM_AD242X_I2SCFG_TX1EN_DIS         0x00000000            /*  TX1EN: Disabled */
#define ENUM_AD242X_I2SCFG_TX1EN_EN          0x00000002            /*  TX1EN: Enabled */
#define ENUM_AD242X_I2SCFG_TX0EN_DIS         0x00000000            /*  TX0EN: Disabled */
#define ENUM_AD242X_I2SCFG_TX0EN_EN          0x00000001            /*  TX0EN: Enabled */

/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_I2SRATE                       Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_I2SRATE_SHARE             7            /*  Share A2B Bus Slots in Reduced Rate Mode */
#define BITP_AD242X_I2SRATE_REDUCE            6            /*  Reduce and Duplicate */
#define BITP_AD242X_I2SRATE_BCLKRATE          3            /*  Set BCLK Frequency */
#define BITP_AD242X_I2SRATE_I2SRATE           0            /*  I2S Rate Setting */
#define BITL_AD242X_I2SRATE_BCLKRATE          3            /*  Set BCLK Frequency */
#define BITL_AD242X_I2SRATE_I2SRATE           3            /*  I2S Rate Setting */
#define BITL_AD242X_I2SRATE_REDUCE            1            /*  Reduce and Duplicate */
#define BITL_AD242X_I2SRATE_SHARE             1            /*  Share A2B Bus Slots in Reduced Rate Mode */

#define BITM_AD242X_I2SRATE_SHARE            0x00000080    /*  Share A2B Bus Slots in Reduced Rate Mode */

#define BITM_AD242X_I2SRATE_REDUCE           0x00000040    /*  Reduce and Duplicate */

#define BITM_AD242X_I2SRATE_BCLKRATE         0x00000038    /*  Set BCLK Frequency */

#define BITM_AD242X_I2SRATE_I2SRATE          0x00000007    /*  I2S Rate Setting */
#define ENUM_AD242X_I2SRATE_SHARE_DIS        0x00000000            /*  SHARE: A2B Bus Slot Sharing Disabled */
#define ENUM_AD242X_I2SRATE_SHARE_EN         0x00000080            /*  SHARE: A2B Bus Slot Sharing Enabled */
#define ENUM_AD242X_I2SRATE_REDUCE_DIS       0x00000000            /*  REDUCE: Disabled */
#define ENUM_AD242X_I2SRATE_REDUCE_EN        0x00000040            /*  REDUCE: Enabled */
#define ENUM_AD242X_I2SRATE_BCLK_NOM         0x00000000            /*  BCLKRATE: BCLK Frequency Determined by Value of I2SGCFG */
#define ENUM_AD242X_I2SRATE_SYNC_X_2048      0x00000008            /*  BCLKRATE: BCLK Frequency is SYNC Frequency X 2048 */
#define ENUM_AD242X_I2SRATE_SYNC_X_4096      0x00000010            /*  BCLKRATE: BCLK Frequency is SYNC Frequency X 4096 */
#define ENUM_AD242X_I2SRATE_SFF_X_64         0x00000020            /*  BCLKRATE: BCLK Frequency is SFF Frequency X 64 */
#define ENUM_AD242X_I2SRATE_SFF_X_128        0x00000028            /*  BCLKRATE: BCLK Frequency is SFF Frequency X 128 */
#define ENUM_AD242X_I2SRATE_SFF_X_256        0x00000030            /*  BCLKRATE: BCLK Frequency is SFF Frequency X 256 */
#define ENUM_AD242X_I2SRATE_SNGL_SFF         0x00000000            /*  I2SRATE: SFF x 1 */
#define ENUM_AD242X_I2SRATE_HALF_SFF         0x00000001            /*  I2SRATE: SFF / 2 */
#define ENUM_AD242X_I2SRATE_QRTR_SFF         0x00000002            /*  I2SRATE: SFF / 4 */
#define ENUM_AD242X_I2SRATE_LOW_SFF          0x00000003            /*  I2SRATE: SFF / RRDIV */
#define ENUM_AD242X_I2SRATE_DBL_SFF          0x00000005            /*  I2SRATE: SFF x 2 */
#define ENUM_AD242X_I2SRATE_QUAD_SFF         0x00000006            /*  I2SRATE: SFF x 4 */

/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_I2STXOFFSET                   Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_I2STXOFFSET_TSBEFORE      7            /*  Three-State Before TX Slots */
#define BITP_AD242X_I2STXOFFSET_TSAFTER       6            /*  Three-State After TX Slots */
#define BITP_AD242X_I2STXOFFSET_TXOFFSET      0            /*  Serial TX Offset */
#define BITL_AD242X_I2STXOFFSET_TXOFFSET      6            /*  Serial TX Offset */
#define BITL_AD242X_I2STXOFFSET_TSAFTER       1            /*  Three-State After TX Slots */
#define BITL_AD242X_I2STXOFFSET_TSBEFORE      1            /*  Three-State Before TX Slots */

#define BITM_AD242X_I2STXOFFSET_TSBEFORE     0x00000080    /*  Three-State Before TX Slots */

#define BITM_AD242X_I2STXOFFSET_TSAFTER      0x00000040    /*  Three-State After TX Slots */

#define BITM_AD242X_I2STXOFFSET_TXOFFSET     0x0000003F    /*  Serial TX Offset */
#define ENUM_AD242X_I2STXOFFSET_TSBEFORE_DIS 0x00000000            /*  TSBEFORE: Disable */
#define ENUM_AD242X_I2STXOFFSET_TSBEFORE_EN  0x00000080            /*  TSBEFORE: Enable */
#define ENUM_AD242X_I2STXOFFSET_TSAFTER_DIS  0x00000000            /*  TSAFTER: Disable */
#define ENUM_AD242X_I2STXOFFSET_TSAFTER_EN   0x00000040            /*  TSAFTER: Enable */
#define ENUM_AD242X_I2STXOFFSET_TXOFFSET_00  0x00000000            /*  TXOFFSET: No TX Offset */
#define ENUM_AD242X_I2STXOFFSET_TXOFFSET_01  0x00000001            /*  TXOFFSET: TX Offset of 1 TDM Slot */
#define ENUM_AD242X_I2STXOFFSET_TXOFFSET_62  0x0000003E            /*  TXOFFSET: TX Offset of 62 TDM Slots */
#define ENUM_AD242X_I2STXOFFSET_TXOFFSET_63  0x0000003F            /*  TXOFFSET: TX Offset of 63 TDM Slots */

/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_I2SRXOFFSET                   Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_I2SRXOFFSET_RXOFFSET      0            /*  Serial RX Offset */
#define BITL_AD242X_I2SRXOFFSET_RXOFFSET      6            /*  Serial RX Offset */

#define BITM_AD242X_I2SRXOFFSET_RXOFFSET     0x0000003F    /*  Serial RX Offset */
#define ENUM_AD242X_I2SRXOFFSET_ZERO         0x00000000            /*  RXOFFSET: No RX Offset */

/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_SYNCOFFSET                    Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_SYNCOFFSET_SYNCOFFSET     0            /*  SYNC Offset */
#define BITL_AD242X_SYNCOFFSET_SYNCOFFSET     8            /*  SYNC Offset */

#define BITM_AD242X_SYNCOFFSET_SYNCOFFSET    0x000000FF    /*  SYNC Offset */
#define ENUM_AD242X_SYNCOFFSET_ZERO          0x00000000            /*  SYNCOFFSET: Zero */
#define ENUM_AD242X_SYNCOFFSET_PLUS127       0x0000007F            /*  SYNCOFFSET: Plus 127 */
#define ENUM_AD242X_SYNCOFFSET_MINUS128      0x00000080            /*  SYNCOFFSET: Minus 128 */

/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_PDMCTL                        Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_PDMCTL_PDMRATE            5            /*  PDM Sample Rate */
#define BITP_AD242X_PDMCTL_HPFEN              4            /*  Highpass Filter Enable */
#define BITP_AD242X_PDMCTL_PDM1SLOTS          3            /*  PDM1 Slots */
#define BITP_AD242X_PDMCTL_PDM1EN             2            /*  PDM1 Enable */
#define BITP_AD242X_PDMCTL_PDM0SLOTS          1            /*  PDM0 Slots */
#define BITP_AD242X_PDMCTL_PDM0EN             0            /*  PDM0 Enable */
#define BITL_AD242X_PDMCTL_PDMRATE            2            /*  PDM Sample Rate */
#define BITL_AD242X_PDMCTL_HPFEN              1            /*  Highpass Filter Enable */
#define BITL_AD242X_PDMCTL_PDM0EN             1            /*  PDM0 Enable */
#define BITL_AD242X_PDMCTL_PDM0SLOTS          1            /*  PDM0 Slots */
#define BITL_AD242X_PDMCTL_PDM1EN             1            /*  PDM1 Enable */
#define BITL_AD242X_PDMCTL_PDM1SLOTS          1            /*  PDM1 Slots */

#define BITM_AD242X_PDMCTL_PDMRATE           0x00000060    /*  PDM Sample Rate */

#define BITM_AD242X_PDMCTL_HPFEN             0x00000010    /*  Highpass Filter Enable */

#define BITM_AD242X_PDMCTL_PDM1SLOTS         0x00000008    /*  PDM1 Slots */

#define BITM_AD242X_PDMCTL_PDM1EN            0x00000004    /*  PDM1 Enable */

#define BITM_AD242X_PDMCTL_PDM0SLOTS         0x00000002    /*  PDM0 Slots */

#define BITM_AD242X_PDMCTL_PDM0EN            0x00000001    /*  PDM0 Enable */
#define ENUM_AD242X_PDMCTL_PDMRATE_FULL      0x00000000            /*  PDMRATE: PDM Samples Produced at Superframe Rate */
#define ENUM_AD242X_PDMCTL_PDMRATE_HALF      0x00000020            /*  PDMRATE: PDM Samples Produced at 1/2 the Superframe Rate */
#define ENUM_AD242X_PDMCTL_PDMRATE_QUARTER   0x00000040            /*  PDMRATE: PDM Samples Produced at 1/4 the Superframe Rate */
#define ENUM_AD242X_PDMCTL_HPFEN_DIS         0x00000000            /*  HPFEN: Disable Filter */
#define ENUM_AD242X_PDMCTL_HPFEN_EN          0x00000010            /*  HPFEN: Enable Filter */
#define ENUM_AD242X_PDMCTL_PDM1SLOTS_1       0x00000000            /*  PDM1SLOTS: 1 Slot */
#define ENUM_AD242X_PDMCTL_PDM1SLOTS_2       0x00000008            /*  PDM1SLOTS: 2 Slots */
#define ENUM_AD242X_PDMCTL_PDM1EN_DIS        0x00000000            /*  PDM1EN: Disable PDM reception on the pin. */
#define ENUM_AD242X_PDMCTL_PDM1EN_EN         0x00000004            /*  PDM1EN: Enable PDM reception on the pin */
#define ENUM_AD242X_PDMCTL_PDM0SLOTS_1       0x00000000            /*  PDM0SLOTS: 1 Slot */
#define ENUM_AD242X_PDMCTL_PDM0SLOTS_2       0x00000002            /*  PDM0SLOTS: 2 Slots */
#define ENUM_AD242X_PDMCTL_PDM0EN_DIS        0x00000000            /*  PDM0EN: Disable PDM reception on the pin */
#define ENUM_AD242X_PDMCTL_PDM0EN_EN         0x00000001            /*  PDM0EN: Enable PDM reception on the pin */

/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_ERRMGMT                       Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_ERRMGMT_ERRSLOT           2            /*  Add Error Indicating Channel to I2S/TDM Output */
#define BITP_AD242X_ERRMGMT_ERRSIG            1            /*  Show Data Error on Remaining Bits */
#define BITP_AD242X_ERRMGMT_ERRLSB            0            /*  Show Data Error on LSB */
#define BITL_AD242X_ERRMGMT_ERRLSB            1            /*  Show Data Error on LSB */
#define BITL_AD242X_ERRMGMT_ERRSIG            1            /*  Show Data Error on Remaining Bits */
#define BITL_AD242X_ERRMGMT_ERRSLOT           1            /*  Add Error Indicating Channel to I2S/TDM Output */

#define BITM_AD242X_ERRMGMT_ERRSLOT          0x00000004    /*  Add Error Indicating Channel to I2S/TDM Output */

#define BITM_AD242X_ERRMGMT_ERRSIG           0x00000002    /*  Show Data Error on Remaining Bits */

#define BITM_AD242X_ERRMGMT_ERRLSB           0x00000001    /*  Show Data Error on LSB */

/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_I2STEST                       Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_I2STEST_BUSLOOPBK         4            /*  Bus Loopback */
#define BITP_AD242X_I2STEST_SELRX1            3            /*  Select RX1 Block to Loopback Buffer */
#define BITP_AD242X_I2STEST_RX2LOOPBK         2            /*  RX Block to Loopback Buffer */
#define BITP_AD242X_I2STEST_LOOPBK2TX         1            /*  Loopback Data to TX Blocks */
#define BITP_AD242X_I2STEST_PATTRN2TX         0            /*  Default Bit Pattern to Serial TX Blocks */
#define BITL_AD242X_I2STEST_BUSLOOPBK         1            /*  Bus Loopback */
#define BITL_AD242X_I2STEST_LOOPBK2TX         1            /*  Loopback Data to TX Blocks */
#define BITL_AD242X_I2STEST_PATTRN2TX         1            /*  Default Bit Pattern to Serial TX Blocks */
#define BITL_AD242X_I2STEST_RX2LOOPBK         1            /*  RX Block to Loopback Buffer */
#define BITL_AD242X_I2STEST_SELRX1            1            /*  Select RX1 Block to Loopback Buffer */

#define BITM_AD242X_I2STEST_BUSLOOPBK        0x00000010    /*  Bus Loopback */

#define BITM_AD242X_I2STEST_SELRX1           0x00000008    /*  Select RX1 Block to Loopback Buffer */

#define BITM_AD242X_I2STEST_RX2LOOPBK        0x00000004    /*  RX Block to Loopback Buffer */

#define BITM_AD242X_I2STEST_LOOPBK2TX        0x00000002    /*  Loopback Data to TX Blocks */

#define BITM_AD242X_I2STEST_PATTRN2TX        0x00000001    /*  Default Bit Pattern to Serial TX Blocks */
#define ENUM_AD242X_I2STEST_BUSLOOPBK_DIS    0x00000000            /*  BUSLOOPBK: Bus Loopback Disabled */
#define ENUM_AD242X_I2STEST_BUSLOOPBK_EN     0x00000010            /*  BUSLOOPBK: Bus Loopback Enabled */
#define ENUM_AD242X_I2STEST_SELRX1_DIS       0x00000000            /*  SELRX1: DRX0 Selected for RX to Loopback */
#define ENUM_AD242X_I2STEST_SELRX1_EN        0x00000008            /*  SELRX1: DRX1 Selected for RX to Loopback */
#define ENUM_AD242X_I2STEST_RX2LOOPBK_DIS    0x00000000            /*  RX2LOOPBK: RX to Loopback Disabled */
#define ENUM_AD242X_I2STEST_RX2LOOPBK_EN     0x00000004            /*  RX2LOOPBK: RX to Loopback Enabled */
#define ENUM_AD242X_I2STEST_LOOPBK2TX_DIS    0x00000000            /*  LOOPBK2TX: Loopback to TX Disabled */
#define ENUM_AD242X_I2STEST_LOOPBK2TX_EN     0x00000002            /*  LOOPBK2TX: Loopback to TX Enabled */
#define ENUM_AD242X_I2STEST_PATTRN2TX_DIS    0x00000000            /*  PATTRN2TX: Pattern to TX Disabled */
#define ENUM_AD242X_I2STEST_PATTRN2TX_EN     0x00000001            /*  PATTRN2TX: Pattern to TX Enabled */

/* ============================================================================================================================
 *    ID_Registers Register Field Definitions
 * ============================================================================================================================ */
/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_VENDOR                        Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_VENDOR_VENDOR             0            /*  Vendor ID */
#define BITL_AD242X_VENDOR_VENDOR             8            /*  Vendor ID */
#define BITM_AD242X_VENDOR_VENDOR            0x000000FF    /*  Vendor ID */

/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_PRODUCT                       Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_PRODUCT_PRODUCT           0            /*  Product ID */
#define BITL_AD242X_PRODUCT_PRODUCT           8            /*  Product ID */
#define BITM_AD242X_PRODUCT_PRODUCT          0x000000FF    /*  Product ID */

/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_VERSION                       Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_VERSION_VERSION           0            /*  Version (Chip) */
#define BITL_AD242X_VERSION_VERSION           8            /*  Version (Chip) */
#define BITM_AD242X_VERSION_VERSION          0x000000FF    /*  Version (Chip) */

/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_CAPABILITY                    Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_CAPABILITY_I2CAVAIL       0            /*  I2C Interface Available */
#define BITL_AD242X_CAPABILITY_I2CAVAIL       1            /*  I2C Interface Available */

#define BITM_AD242X_CAPABILITY_I2CAVAIL      0x00000001    /*  I2C Interface Available */

/* ============================================================================================================================
 *    Interrupt_Error_Registers Register Field Definitions
 * ============================================================================================================================ */
/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_INTSTAT                       Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_INTSTAT_IRQ               0            /*  Interrupt Currently Asserted */
#define BITL_AD242X_INTSTAT_IRQ               1            /*  Interrupt Currently Asserted */

#define BITM_AD242X_INTSTAT_IRQ              0x00000001    /*  Interrupt Currently Asserted */
#define ENUM_AD242X_INTSTAT_IRQ_LOW          0x00000000            /*  IRQ: No Interrupt request */
#define ENUM_AD242X_INTSTAT_IRQ_HIGH         0x00000001            /*  IRQ: Interrupt request */

/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_INTSRC                        Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_INTSRC_MSTINT             7            /*  Master Interrupt */
#define BITP_AD242X_INTSRC_SLVINT             6            /*  Slave Interrupt */
#define BITP_AD242X_INTSRC_INODE              0            /*  ID for SLVINT */
#define BITL_AD242X_INTSRC_INODE              4            /*  ID for SLVINT */
#define BITL_AD242X_INTSRC_MSTINT             1            /*  Master Interrupt */
#define BITL_AD242X_INTSRC_SLVINT             1            /*  Slave Interrupt */
#define BITM_AD242X_INTSRC_MSTINT            0x00000080    /*  Master Interrupt */
#define BITM_AD242X_INTSRC_SLVINT            0x00000040    /*  Slave Interrupt */
#define BITM_AD242X_INTSRC_INODE             0x0000000F    /*  ID for SLVINT */

/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_INTTYPE                       Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_INTTYPE_TYPE              0            /*  Interrupt Type */
#define BITL_AD242X_INTTYPE_TYPE              8            /*  Interrupt Type */

#define BITM_AD242X_INTTYPE_TYPE             0x000000FF    /*  Interrupt Type */

/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_INTPND0                       Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_INTPND0_SRFCRCERR         7            /*  SRF CRC Error (Slave Only) */
#define BITP_AD242X_INTPND0_SRFERR            6            /*  Missed Synchronization Response Frame (SRF) */
#define BITP_AD242X_INTPND0_BECOVF            5            /*  Bit Error Count Error */
#define BITP_AD242X_INTPND0_PWRERR            4            /*  Switch Reporting Error on Downstream Power */
#define BITP_AD242X_INTPND0_DPERR             3            /*  Data Parity Error */
#define BITP_AD242X_INTPND0_CRCERR            2            /*  CRC Error */
#define BITP_AD242X_INTPND0_DDERR             1            /*  Data Decoding Error */
#define BITP_AD242X_INTPND0_HDCNTERR          0            /*  Header Count Error */
#define BITL_AD242X_INTPND0_BECOVF            1            /*  Bit Error Count Error */
#define BITL_AD242X_INTPND0_CRCERR            1            /*  CRC Error */
#define BITL_AD242X_INTPND0_DDERR             1            /*  Data Decoding Error */
#define BITL_AD242X_INTPND0_DPERR             1            /*  Data Parity Error */
#define BITL_AD242X_INTPND0_HDCNTERR          1            /*  Header Count Error */
#define BITL_AD242X_INTPND0_PWRERR            1            /*  Switch Reporting Error on Downstream Power */
#define BITL_AD242X_INTPND0_SRFCRCERR         1            /*  SRF CRC Error (Slave Only) */
#define BITL_AD242X_INTPND0_SRFERR            1            /*  Missed Synchronization Response Frame (SRF) */

#define BITM_AD242X_INTPND0_SRFCRCERR        0x00000080    /*  SRF CRC Error (Slave Only) */

#define BITM_AD242X_INTPND0_SRFERR           0x00000040    /*  Missed Synchronization Response Frame (SRF) */

#define BITM_AD242X_INTPND0_BECOVF           0x00000020    /*  Bit Error Count Error */

#define BITM_AD242X_INTPND0_PWRERR           0x00000010    /*  Switch Reporting Error on Downstream Power */

#define BITM_AD242X_INTPND0_DPERR            0x00000008    /*  Data Parity Error */

#define BITM_AD242X_INTPND0_CRCERR           0x00000004    /*  CRC Error */

#define BITM_AD242X_INTPND0_DDERR            0x00000002    /*  Data Decoding Error */

#define BITM_AD242X_INTPND0_HDCNTERR         0x00000001    /*  Header Count Error */

/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_INTPND1                       Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_INTPND1_IO7PND            7            /*  IO7 Int Pending */
#define BITP_AD242X_INTPND1_IO6PND            6            /*  IO6 Int Pending */
#define BITP_AD242X_INTPND1_IO5PND            5            /*  IO5 Int Pending */
#define BITP_AD242X_INTPND1_IO4PND            4            /*  IO4 Int Pending */
#define BITP_AD242X_INTPND1_IO3PND            3            /*  IO3 Int Pending */
#define BITP_AD242X_INTPND1_IO2PND            2            /*  IO2 Int Pending */
#define BITP_AD242X_INTPND1_IO1PND            1            /*  IO1 Int Pending */
#define BITP_AD242X_INTPND1_IO0PND            0            /*  IO0 Int Pending (Slave Only) */
#define BITL_AD242X_INTPND1_IO0PND            1            /*  IO0 Int Pending (Slave Only) */
#define BITL_AD242X_INTPND1_IO1PND            1            /*  IO1 Int Pending */
#define BITL_AD242X_INTPND1_IO2PND            1            /*  IO2 Int Pending */
#define BITL_AD242X_INTPND1_IO3PND            1            /*  IO3 Int Pending */
#define BITL_AD242X_INTPND1_IO4PND            1            /*  IO4 Int Pending */
#define BITL_AD242X_INTPND1_IO5PND            1            /*  IO5 Int Pending */
#define BITL_AD242X_INTPND1_IO6PND            1            /*  IO6 Int Pending */
#define BITL_AD242X_INTPND1_IO7PND            1            /*  IO7 Int Pending */

#define BITM_AD242X_INTPND1_IO7PND           0x00000080    /*  IO7 Int Pending */

#define BITM_AD242X_INTPND1_IO6PND           0x00000040    /*  IO6 Int Pending */

#define BITM_AD242X_INTPND1_IO5PND           0x00000020    /*  IO5 Int Pending */

#define BITM_AD242X_INTPND1_IO4PND           0x00000010    /*  IO4 Int Pending */

#define BITM_AD242X_INTPND1_IO3PND           0x00000008    /*  IO3 Int Pending */

#define BITM_AD242X_INTPND1_IO2PND           0x00000004    /*  IO2 Int Pending */

#define BITM_AD242X_INTPND1_IO1PND           0x00000002    /*  IO1 Int Pending */

#define BITM_AD242X_INTPND1_IO0PND           0x00000001    /*  IO0 Int Pending (Slave Only) */

/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_INTPND2                       Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_INTPND2_SLVIRQ            3            /*  Slave Interrupt Received Master Only */
#define BITP_AD242X_INTPND2_ICRCERR           2            /*  Int Frame CRC Error Master Only */
#define BITP_AD242X_INTPND2_I2CERR            1            /*  I2C Transaction Error Master Only */
#define BITP_AD242X_INTPND2_DSCDONE           0            /*  Node Discovered Master Only */
#define BITL_AD242X_INTPND2_DSCDONE           1            /*  Node Discovered Master Only */
#define BITL_AD242X_INTPND2_I2CERR            1            /*  I2C Transaction Error Master Only */
#define BITL_AD242X_INTPND2_ICRCERR           1            /*  Int Frame CRC Error Master Only */
#define BITL_AD242X_INTPND2_SLVIRQ            1            /*  Slave Interrupt Received Master Only */

#define BITM_AD242X_INTPND2_SLVIRQ           0x00000008    /*  Slave Interrupt Received Master Only */

#define BITM_AD242X_INTPND2_ICRCERR          0x00000004    /*  Int Frame CRC Error Master Only */

#define BITM_AD242X_INTPND2_I2CERR           0x00000002    /*  I2C Transaction Error Master Only */

#define BITM_AD242X_INTPND2_DSCDONE          0x00000001    /*  Node Discovered Master Only */

/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_INTMSK0                       Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_INTMSK0_INTMSK0           0            /*  Mask for INTPND0 */
#define BITL_AD242X_INTMSK0_INTMSK0           8            /*  Mask for INTPND0 */

#define BITM_AD242X_INTMSK0_INTMSK0          0x000000FF    /*  Mask for INTPND0 */

/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_INTMSK1                       Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_INTMSK1_INTMSK1           0            /*  Mask for INTPND1 */
#define BITL_AD242X_INTMSK1_INTMSK1           8            /*  Mask for INTPND1 */

#define BITM_AD242X_INTMSK1_INTMSK1          0x000000FF    /*  Mask for INTPND1 */

/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_INTMSK2                       Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_INTMSK2_INTMSK2           0            /*  Mask for INTPND2 */
#define BITL_AD242X_INTMSK2_INTMSK2           8            /*  Mask for INTPND2 */

#define BITM_AD242X_INTMSK2_INTMSK2          0x000000FF    /*  Mask for INTPND2 */

/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_BECCTL                        Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_BECCTL_THRESHLD           5            /*  Threshold to Generate an Interrupt */
#define BITP_AD242X_BECCTL_ENICRC             4            /*  Enable ICRCERR Count */
#define BITP_AD242X_BECCTL_ENDP               3            /*  Enable DPERR Count */
#define BITP_AD242X_BECCTL_ENCRC              2            /*  Enable CRCERR Count */
#define BITP_AD242X_BECCTL_ENDD               1            /*  Enable DDERR Count */
#define BITP_AD242X_BECCTL_ENHDCNT            0            /*  Enable HDCNTERR Count */
#define BITL_AD242X_BECCTL_THRESHLD           3            /*  Threshold to Generate an Interrupt */
#define BITL_AD242X_BECCTL_ENCRC              1            /*  Enable CRCERR Count */
#define BITL_AD242X_BECCTL_ENDD               1            /*  Enable DDERR Count */
#define BITL_AD242X_BECCTL_ENDP               1            /*  Enable DPERR Count */
#define BITL_AD242X_BECCTL_ENHDCNT            1            /*  Enable HDCNTERR Count */
#define BITL_AD242X_BECCTL_ENICRC             1            /*  Enable ICRCERR Count */

#define BITM_AD242X_BECCTL_THRESHLD          0x000000E0    /*  Threshold to Generate an Interrupt */

#define BITM_AD242X_BECCTL_ENICRC            0x00000010    /*  Enable ICRCERR Count */

#define BITM_AD242X_BECCTL_ENDP              0x00000008    /*  Enable DPERR Count */

#define BITM_AD242X_BECCTL_ENCRC             0x00000004    /*  Enable CRCERR Count */

#define BITM_AD242X_BECCTL_ENDD              0x00000002    /*  Enable DDERR Count */

#define BITM_AD242X_BECCTL_ENHDCNT           0x00000001    /*  Enable HDCNTERR Count */
#define ENUM_AD242X_BECCTL_THRESHLD_2        0x00000000            /*  THRESHLD: Interrupt After 2 Errors */
#define ENUM_AD242X_BECCTL_THRESHLD_4        0x00000020            /*  THRESHLD: Interrupt After 4 Errors */
#define ENUM_AD242X_BECCTL_THRESHLD_8        0x00000040            /*  THRESHLD: Interrupt After 8 Errors */
#define ENUM_AD242X_BECCTL_THRESHLD_16       0x00000060            /*  THRESHLD: Interrupt After 16 Errors */
#define ENUM_AD242X_BECCTL_THRESHLD_32       0x00000080            /*  THRESHLD: Interrupt After 32 Errors */
#define ENUM_AD242X_BECCTL_THRESHLD_64       0x000000A0            /*  THRESHLD: Interrupt After 64 Errors */
#define ENUM_AD242X_BECCTL_THRESHLD_128      0x000000C0            /*  THRESHLD: Interrupt After 128 Errors */
#define ENUM_AD242X_BECCTL_THRESHLD_256      0x000000E0            /*  THRESHLD: Interrupt After 256 Errors */
#define ENUM_AD242X_BECCTL_ENICRC_DIS        0x00000000            /*  ENICRC: Disabled */
#define ENUM_AD242X_BECCTL_ENICRC_EN         0x00000010            /*  ENICRC: Enable Bit Error Counting */
#define ENUM_AD242X_BECCTL_ENDP_DIS          0x00000000            /*  ENDP: No Parity error */
#define ENUM_AD242X_BECCTL_ENDP_EN           0x00000008            /*  ENDP: Parity Error */
#define ENUM_AD242X_BECCTL_ENCRC_DIS         0x00000000            /*  ENCRC: No CRC Error */
#define ENUM_AD242X_BECCTL_ENCRC_EN          0x00000004            /*  ENCRC: CRC Error */
#define ENUM_AD242X_BECCTL_ENDD_DIS          0x00000000            /*  ENDD: Disabled */
#define ENUM_AD242X_BECCTL_ENDD_EN           0x00000002            /*  ENDD: Enabled */
#define ENUM_AD242X_BECCTL_ENHDCNT_DIS       0x00000000            /*  ENHDCNT: Disabled */
#define ENUM_AD242X_BECCTL_ENHDCNT_EN        0x00000001            /*  ENHDCNT: Enabled */

/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_BECNT                         Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_BECNT_BECNT               0            /*  Bit Error Count */
#define BITL_AD242X_BECNT_BECNT               8            /*  Bit Error Count */
#define BITM_AD242X_BECNT_BECNT              0x000000FF    /*  Bit Error Count */

/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_LINTTYPE                      Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_LINTTYPE_LTYPE            0            /*  Local Interrupt Type (Slave Only) */
#define BITL_AD242X_LINTTYPE_LTYPE            8            /*  Local Interrupt Type (Slave Only) */

#define BITM_AD242X_LINTTYPE_LTYPE           0x000000FF    /*  Local Interrupt Type (Slave Only) */

/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_RAISE                         Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_RAISE_RTYPE               0            /*  Interrupt Type to Raise */
#define BITL_AD242X_RAISE_RTYPE               8            /*  Interrupt Type to Raise */

#define BITM_AD242X_RAISE_RTYPE              0x000000FF    /*  Interrupt Type to Raise */

/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_GENERR                        Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_GENERR_GENICRCERR         4            /*  Generate Int Frame CRC Error (Slave Only) */
#define BITP_AD242X_GENERR_GENDPERR           3            /*  Generate Data Parity Error */
#define BITP_AD242X_GENERR_GENCRCERR          2            /*  Generate CRC Error */
#define BITP_AD242X_GENERR_GENDDERR           1            /*  Generate Data Decoding Error */
#define BITP_AD242X_GENERR_GENHCERR           0            /*  Generate Header Count Error */
#define BITL_AD242X_GENERR_GENCRCERR          1            /*  Generate CRC Error */
#define BITL_AD242X_GENERR_GENDDERR           1            /*  Generate Data Decoding Error */
#define BITL_AD242X_GENERR_GENDPERR           1            /*  Generate Data Parity Error */
#define BITL_AD242X_GENERR_GENHCERR           1            /*  Generate Header Count Error */
#define BITL_AD242X_GENERR_GENICRCERR         1            /*  Generate Int Frame CRC Error (Slave Only) */

#define BITM_AD242X_GENERR_GENICRCERR        0x00000010    /*  Generate Int Frame CRC Error (Slave Only) */

#define BITM_AD242X_GENERR_GENDPERR          0x00000008    /*  Generate Data Parity Error */

#define BITM_AD242X_GENERR_GENCRCERR         0x00000004    /*  Generate CRC Error */

#define BITM_AD242X_GENERR_GENDDERR          0x00000002    /*  Generate Data Decoding Error */

#define BITM_AD242X_GENERR_GENHCERR          0x00000001    /*  Generate Header Count Error */

/* ============================================================================================================================
 *    PRBS_Test Register Field Definitions
 * ============================================================================================================================ */
/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_TESTMODE                      Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_TESTMODE_RXDPTH           4            /*  RX Fifo Depth */
#define BITP_AD242X_TESTMODE_PRBSN2N          2            /*  PRBS N2N Mode */
#define BITP_AD242X_TESTMODE_PRBSDN           1            /*  PRBS Data Downstream */
#define BITP_AD242X_TESTMODE_PRBSUP           0            /*  PRBS Data Upstream */
#define BITL_AD242X_TESTMODE_RXDPTH           3            /*  RX Fifo Depth */
#define BITL_AD242X_TESTMODE_PRBSDN           1            /*  PRBS Data Downstream */
#define BITL_AD242X_TESTMODE_PRBSN2N          1            /*  PRBS N2N Mode */
#define BITL_AD242X_TESTMODE_PRBSUP           1            /*  PRBS Data Upstream */

#define BITM_AD242X_TESTMODE_RXDPTH          0x00000070    /*  RX Fifo Depth */

#define BITM_AD242X_TESTMODE_PRBSN2N         0x00000004    /*  PRBS N2N Mode */

#define BITM_AD242X_TESTMODE_PRBSDN          0x00000002    /*  PRBS Data Downstream */

#define BITM_AD242X_TESTMODE_PRBSUP          0x00000001    /*  PRBS Data Upstream */

/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_ERRCNT0                       Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_ERRCNT0_ERRCNT            0            /*  Contains 32-bit Error Count for PRBS */
#define BITL_AD242X_ERRCNT0_ERRCNT            8            /*  Contains 32-bit Error Count for PRBS */
#define BITM_AD242X_ERRCNT0_ERRCNT           0x000000FF    /*  Contains 32-bit Error Count for PRBS */

/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_ERRCNT1                       Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_ERRCNT1_ERRCNT            0            /*  Contains 32-bit Error Count for PRBS */
#define BITL_AD242X_ERRCNT1_ERRCNT            8            /*  Contains 32-bit Error Count for PRBS */
#define BITM_AD242X_ERRCNT1_ERRCNT           0x000000FF    /*  Contains 32-bit Error Count for PRBS */

/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_ERRCNT2                       Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_ERRCNT2_ERRCNT            0            /*  Contains 32-bit Error Count for PRBS */
#define BITL_AD242X_ERRCNT2_ERRCNT            8            /*  Contains 32-bit Error Count for PRBS */
#define BITM_AD242X_ERRCNT2_ERRCNT           0x000000FF    /*  Contains 32-bit Error Count for PRBS */

/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_ERRCNT3                       Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_ERRCNT3_ERRCNT            0            /*  Contains 32-bit Error Count for PRBS */
#define BITL_AD242X_ERRCNT3_ERRCNT            8            /*  Contains 32-bit Error Count for PRBS */
#define BITM_AD242X_ERRCNT3_ERRCNT           0x000000FF    /*  Contains 32-bit Error Count for PRBS */

/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_SEED0                         Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_SEED0_SEED                0            /*  Contains 32-bit Seed for PRBS */
#define BITL_AD242X_SEED0_SEED                8            /*  Contains 32-bit Seed for PRBS */
#define BITM_AD242X_SEED0_SEED               0x000000FF    /*  Contains 32-bit Seed for PRBS */

/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_SEED1                         Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_SEED1_SEED                0            /*  Contains 32-bit Seed for PRBS */
#define BITL_AD242X_SEED1_SEED                8            /*  Contains 32-bit Seed for PRBS */
#define BITM_AD242X_SEED1_SEED               0x000000FF    /*  Contains 32-bit Seed for PRBS */

/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_SEED2                         Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_SEED2_SEED                0            /*  Contains 32-bit Seed for PRBS */
#define BITL_AD242X_SEED2_SEED                8            /*  Contains 32-bit Seed for PRBS */
#define BITM_AD242X_SEED2_SEED               0x000000FF    /*  Contains 32-bit Seed for PRBS */

/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_SEED3                         Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_SEED3_SEED                0            /*  Contains 32-bit Seed for PRBS */
#define BITL_AD242X_SEED3_SEED                8            /*  Contains 32-bit Seed for PRBS */
#define BITM_AD242X_SEED3_SEED               0x000000FF    /*  Contains 32-bit Seed for PRBS */

/* ============================================================================================================================
 *    Pin_IO_Interrupt_Registers Register Field Definitions
 * ============================================================================================================================ */
/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_GPIODAT                       Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_GPIODAT_IO7DAT            7            /*  IO7 Output Data */
#define BITP_AD242X_GPIODAT_IO6DAT            6            /*  IO6 Output Data */
#define BITP_AD242X_GPIODAT_IO5DAT            5            /*  IO5 Output Data */
#define BITP_AD242X_GPIODAT_IO4DAT            4            /*  IO4 Output Data */
#define BITP_AD242X_GPIODAT_IO3DAT            3            /*  IO3 Output Data */
#define BITP_AD242X_GPIODAT_IO2DAT            2            /*  IO2 Output Data */
#define BITP_AD242X_GPIODAT_IO1DAT            1            /*  IO1 Output Data */
#define BITP_AD242X_GPIODAT_IO0DAT            0            /*  IO0 Output Data */
#define BITL_AD242X_GPIODAT_IO0DAT            1            /*  IO0 Output Data */
#define BITL_AD242X_GPIODAT_IO1DAT            1            /*  IO1 Output Data */
#define BITL_AD242X_GPIODAT_IO2DAT            1            /*  IO2 Output Data */
#define BITL_AD242X_GPIODAT_IO3DAT            1            /*  IO3 Output Data */
#define BITL_AD242X_GPIODAT_IO4DAT            1            /*  IO4 Output Data */
#define BITL_AD242X_GPIODAT_IO5DAT            1            /*  IO5 Output Data */
#define BITL_AD242X_GPIODAT_IO6DAT            1            /*  IO6 Output Data */
#define BITL_AD242X_GPIODAT_IO7DAT            1            /*  IO7 Output Data */

#define BITM_AD242X_GPIODAT_IO7DAT           0x00000080    /*  IO7 Output Data */

#define BITM_AD242X_GPIODAT_IO6DAT           0x00000040    /*  IO6 Output Data */

#define BITM_AD242X_GPIODAT_IO5DAT           0x00000020    /*  IO5 Output Data */

#define BITM_AD242X_GPIODAT_IO4DAT           0x00000010    /*  IO4 Output Data */

#define BITM_AD242X_GPIODAT_IO3DAT           0x00000008    /*  IO3 Output Data */

#define BITM_AD242X_GPIODAT_IO2DAT           0x00000004    /*  IO2 Output Data */

#define BITM_AD242X_GPIODAT_IO1DAT           0x00000002    /*  IO1 Output Data */

#define BITM_AD242X_GPIODAT_IO0DAT           0x00000001    /*  IO0 Output Data */
#define ENUM_AD242X_GPIODAT_IO7_LOW          0x00000000            /*  IO7DAT: Output Low */
#define ENUM_AD242X_GPIODAT_IO7_HIGH         0x00000080            /*  IO7DAT: Output High */
#define ENUM_AD242X_GPIODAT_IO6_LOW          0x00000000            /*  IO6DAT: Output Low */
#define ENUM_AD242X_GPIODAT_IO6_HIGH         0x00000040            /*  IO6DAT: Output High */
#define ENUM_AD242X_GPIODAT_IO5_LOW          0x00000000            /*  IO5DAT: Output Low */
#define ENUM_AD242X_GPIODAT_IO5_HIGH         0x00000020            /*  IO5DAT: Output High */
#define ENUM_AD242X_GPIODAT_IO4_LOW          0x00000000            /*  IO4DAT: Output Low */
#define ENUM_AD242X_GPIODAT_IO4_HIGH         0x00000010            /*  IO4DAT: Output High */
#define ENUM_AD242X_GPIODAT_IO3_LOW          0x00000000            /*  IO3DAT: Output Low */
#define ENUM_AD242X_GPIODAT_IO3_HIGH         0x00000008            /*  IO3DAT: Output High */
#define ENUM_AD242X_GPIODAT_IO2_LOW          0x00000000            /*  IO2DAT: Output Low */
#define ENUM_AD242X_GPIODAT_IO2_HIGH         0x00000004            /*  IO2DAT: Output High */
#define ENUM_AD242X_GPIODAT_IO1_LOW          0x00000000            /*  IO1DAT: Output Low */
#define ENUM_AD242X_GPIODAT_IO1_HIGH         0x00000002            /*  IO1DAT: Output High */
#define ENUM_AD242X_GPIODAT_IO0_LOW          0x00000000            /*  IO0DAT: Output Low */
#define ENUM_AD242X_GPIODAT_IO0_HIGH         0x00000001            /*  IO0DAT: Output High */

/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_GPIODATSET                    Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_GPIODATSET_IO7DSET        7            /*  Write 1 to Set IO6DAT */
#define BITP_AD242X_GPIODATSET_IO6DSET        6            /*  Write 1 to Set IO6DAT */
#define BITP_AD242X_GPIODATSET_IO5DSET        5            /*  Write 1 to Set IO5DAT */
#define BITP_AD242X_GPIODATSET_IO4DSET        4            /*  Write 1 to Set IO4DAT */
#define BITP_AD242X_GPIODATSET_IO3DSET        3            /*  Write 1 to Set IO3DAT */
#define BITP_AD242X_GPIODATSET_IO2DSET        2            /*  Write 1 to Set IO2DAT */
#define BITP_AD242X_GPIODATSET_IO1DSET        1            /*  Write 1 to Set IO1DAT */
#define BITP_AD242X_GPIODATSET_IO0DSET        0            /*  Write 1 to Set IO0DAT */
#define BITL_AD242X_GPIODATSET_IO0DSET        1            /*  Write 1 to Set IO0DAT */
#define BITL_AD242X_GPIODATSET_IO1DSET        1            /*  Write 1 to Set IO1DAT */
#define BITL_AD242X_GPIODATSET_IO2DSET        1            /*  Write 1 to Set IO2DAT */
#define BITL_AD242X_GPIODATSET_IO3DSET        1            /*  Write 1 to Set IO3DAT */
#define BITL_AD242X_GPIODATSET_IO4DSET        1            /*  Write 1 to Set IO4DAT */
#define BITL_AD242X_GPIODATSET_IO5DSET        1            /*  Write 1 to Set IO5DAT */
#define BITL_AD242X_GPIODATSET_IO6DSET        1            /*  Write 1 to Set IO6DAT */
#define BITL_AD242X_GPIODATSET_IO7DSET        1            /*  Write 1 to Set IO6DAT */

#define BITM_AD242X_GPIODATSET_IO7DSET       0x00000080    /*  Write 1 to Set IO6DAT */

#define BITM_AD242X_GPIODATSET_IO6DSET       0x00000040    /*  Write 1 to Set IO6DAT */

#define BITM_AD242X_GPIODATSET_IO5DSET       0x00000020    /*  Write 1 to Set IO5DAT */

#define BITM_AD242X_GPIODATSET_IO4DSET       0x00000010    /*  Write 1 to Set IO4DAT */

#define BITM_AD242X_GPIODATSET_IO3DSET       0x00000008    /*  Write 1 to Set IO3DAT */

#define BITM_AD242X_GPIODATSET_IO2DSET       0x00000004    /*  Write 1 to Set IO2DAT */

#define BITM_AD242X_GPIODATSET_IO1DSET       0x00000002    /*  Write 1 to Set IO1DAT */

#define BITM_AD242X_GPIODATSET_IO0DSET       0x00000001    /*  Write 1 to Set IO0DAT */
#define ENUM_AD242X_GPIODATSET_IO7_NO_ACTION 0x00000000            /*  IO7DSET: No Action */
#define ENUM_AD242X_GPIODATSET_IO7_SET       0x00000080            /*  IO7DSET: Set Bit */
#define ENUM_AD242X_GPIODATSET_IO6_NO_ACTION 0x00000000            /*  IO6DSET: No Action */
#define ENUM_AD242X_GPIODATSET_IO6_SET       0x00000040            /*  IO6DSET: Set Bit */
#define ENUM_AD242X_GPIODATSET_IO5_NO_ACTION 0x00000000            /*  IO5DSET: No Action */
#define ENUM_AD242X_GPIODATSET_IO5_SET       0x00000020            /*  IO5DSET: Set Bit */
#define ENUM_AD242X_GPIODATSET_IO4_NO_ACTION 0x00000000            /*  IO4DSET: No Action */
#define ENUM_AD242X_GPIODATSET_IO4_SET       0x00000010            /*  IO4DSET: Set Bit */
#define ENUM_AD242X_GPIODATSET_IO3_NO_ACTION 0x00000000            /*  IO3DSET: No Action */
#define ENUM_AD242X_GPIODATSET_IO3_SET       0x00000008            /*  IO3DSET: Set Bit */
#define ENUM_AD242X_GPIODATSET_IO2_NO_ACTION 0x00000000            /*  IO2DSET: No Action */
#define ENUM_AD242X_GPIODATSET_IO2_SET       0x00000004            /*  IO2DSET: Set Bit */
#define ENUM_AD242X_GPIODATSET_IO1_NO_ACTION 0x00000000            /*  IO1DSET: No Action */
#define ENUM_AD242X_GPIODATSET_IO1_SET       0x00000002            /*  IO1DSET: Set Bit */
#define ENUM_AD242X_GPIODATSET_IO0_NO_ACTION 0x00000000            /*  IO0DSET: No Action */
#define ENUM_AD242X_GPIODATSET_IO0_SET       0x00000001            /*  IO0DSET: Set Bit */

/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_GPIODATCLR                    Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_GPIODATCLR_IO7DCLR        7            /*  Write 1 to Clear IO7DAT */
#define BITP_AD242X_GPIODATCLR_IO6DCLR        6            /*  Write 1 to Clear IO6DAT */
#define BITP_AD242X_GPIODATCLR_IO5DCLR        5            /*  Write 1 to Clear IO5DAT */
#define BITP_AD242X_GPIODATCLR_IO4DCLR        4            /*  Write 1 to Clear IO4DAT */
#define BITP_AD242X_GPIODATCLR_IO3DCLR        3            /*  Write 1 to Clear IO3DAT */
#define BITP_AD242X_GPIODATCLR_IO2DCLR        2            /*  Write 1 to Clear IO2DAT */
#define BITP_AD242X_GPIODATCLR_IO1DCLR        1            /*  Write 1 to Clear IO1DAT */
#define BITP_AD242X_GPIODATCLR_IO0DCLR        0            /*  Write 1 to Clear IO0DAT */
#define BITL_AD242X_GPIODATCLR_IO0DCLR        1            /*  Write 1 to Clear IO0DAT */
#define BITL_AD242X_GPIODATCLR_IO1DCLR        1            /*  Write 1 to Clear IO1DAT */
#define BITL_AD242X_GPIODATCLR_IO2DCLR        1            /*  Write 1 to Clear IO2DAT */
#define BITL_AD242X_GPIODATCLR_IO3DCLR        1            /*  Write 1 to Clear IO3DAT */
#define BITL_AD242X_GPIODATCLR_IO4DCLR        1            /*  Write 1 to Clear IO4DAT */
#define BITL_AD242X_GPIODATCLR_IO5DCLR        1            /*  Write 1 to Clear IO5DAT */
#define BITL_AD242X_GPIODATCLR_IO6DCLR        1            /*  Write 1 to Clear IO6DAT */
#define BITL_AD242X_GPIODATCLR_IO7DCLR        1            /*  Write 1 to Clear IO7DAT */

#define BITM_AD242X_GPIODATCLR_IO7DCLR       0x00000080    /*  Write 1 to Clear IO7DAT */

#define BITM_AD242X_GPIODATCLR_IO6DCLR       0x00000040    /*  Write 1 to Clear IO6DAT */

#define BITM_AD242X_GPIODATCLR_IO5DCLR       0x00000020    /*  Write 1 to Clear IO5DAT */

#define BITM_AD242X_GPIODATCLR_IO4DCLR       0x00000010    /*  Write 1 to Clear IO4DAT */

#define BITM_AD242X_GPIODATCLR_IO3DCLR       0x00000008    /*  Write 1 to Clear IO3DAT */

#define BITM_AD242X_GPIODATCLR_IO2DCLR       0x00000004    /*  Write 1 to Clear IO2DAT */

#define BITM_AD242X_GPIODATCLR_IO1DCLR       0x00000002    /*  Write 1 to Clear IO1DAT */

#define BITM_AD242X_GPIODATCLR_IO0DCLR       0x00000001    /*  Write 1 to Clear IO0DAT */
#define ENUM_AD242X_GPIODATCLR_IO7_NO_ACTION 0x00000000            /*  IO7DCLR: No Action */
#define ENUM_AD242X_GPIODATCLR_IO7_CLEAR     0x00000080            /*  IO7DCLR: Clear Bit */
#define ENUM_AD242X_GPIODATCLR_IO6_NO_ACTION 0x00000000            /*  IO6DCLR: No Action */
#define ENUM_AD242X_GPIODATCLR_IO6_CLEAR     0x00000040            /*  IO6DCLR: Clear Bit */
#define ENUM_AD242X_GPIODATCLR_IO5_NO_ACTION 0x00000000            /*  IO5DCLR: No Action */
#define ENUM_AD242X_GPIODATCLR_IO5_CLEAR     0x00000020            /*  IO5DCLR: Clear Bit */
#define ENUM_AD242X_GPIODATCLR_IO4_NO_ACTION 0x00000000            /*  IO4DCLR: No Action */
#define ENUM_AD242X_GPIODATCLR_IO4_CLEAR     0x00000010            /*  IO4DCLR: Clear Bit */
#define ENUM_AD242X_GPIODATCLR_IO3_NO_ACTION 0x00000000            /*  IO3DCLR: No Action */
#define ENUM_AD242X_GPIODATCLR_IO3_CLEAR     0x00000008            /*  IO3DCLR: Clear Bit */
#define ENUM_AD242X_GPIODATCLR_IO2_NO_ACTION 0x00000000            /*  IO2DCLR: No Action */
#define ENUM_AD242X_GPIODATCLR_IO2_CLEAR     0x00000004            /*  IO2DCLR: Clear Bit */
#define ENUM_AD242X_GPIODATCLR_IO1_NO_ACTION 0x00000000            /*  IO1DCLR: No Action */
#define ENUM_AD242X_GPIODATCLR_IO1_CLEAR     0x00000002            /*  IO1DCLR: Clear Bit */
#define ENUM_AD242X_GPIODATCLR_IO0_NO_ACTION 0x00000000            /*  IO0DCLR: No Action */
#define ENUM_AD242X_GPIODATCLR_IO0_CLEAR     0x00000001            /*  IO0DCLR: Clear Bit */

/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_GPIOOEN                       Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_GPIOOEN_IO7OEN            7            /*  IO7 Output Enable */
#define BITP_AD242X_GPIOOEN_IO6OEN            6            /*  IO6 Output Enable */
#define BITP_AD242X_GPIOOEN_IO5OEN            5            /*  IO5 Output Enable */
#define BITP_AD242X_GPIOOEN_IO4OEN            4            /*  IO4 Output Enable */
#define BITP_AD242X_GPIOOEN_IO3OEN            3            /*  IO3 Output Enable */
#define BITP_AD242X_GPIOOEN_IO2OEN            2            /*  IO2 Output Enable */
#define BITP_AD242X_GPIOOEN_IO1OEN            1            /*  IO1 Output Enable */
#define BITP_AD242X_GPIOOEN_IO0OEN            0            /*  IO0 Output Enable */
#define BITL_AD242X_GPIOOEN_IO0OEN            1            /*  IO0 Output Enable */
#define BITL_AD242X_GPIOOEN_IO1OEN            1            /*  IO1 Output Enable */
#define BITL_AD242X_GPIOOEN_IO2OEN            1            /*  IO2 Output Enable */
#define BITL_AD242X_GPIOOEN_IO3OEN            1            /*  IO3 Output Enable */
#define BITL_AD242X_GPIOOEN_IO4OEN            1            /*  IO4 Output Enable */
#define BITL_AD242X_GPIOOEN_IO5OEN            1            /*  IO5 Output Enable */
#define BITL_AD242X_GPIOOEN_IO6OEN            1            /*  IO6 Output Enable */
#define BITL_AD242X_GPIOOEN_IO7OEN            1            /*  IO7 Output Enable */

#define BITM_AD242X_GPIOOEN_IO7OEN           0x00000080    /*  IO7 Output Enable */

#define BITM_AD242X_GPIOOEN_IO6OEN           0x00000040    /*  IO6 Output Enable */

#define BITM_AD242X_GPIOOEN_IO5OEN           0x00000020    /*  IO5 Output Enable */

#define BITM_AD242X_GPIOOEN_IO4OEN           0x00000010    /*  IO4 Output Enable */

#define BITM_AD242X_GPIOOEN_IO3OEN           0x00000008    /*  IO3 Output Enable */

#define BITM_AD242X_GPIOOEN_IO2OEN           0x00000004    /*  IO2 Output Enable */

#define BITM_AD242X_GPIOOEN_IO1OEN           0x00000002    /*  IO1 Output Enable */

#define BITM_AD242X_GPIOOEN_IO0OEN           0x00000001    /*  IO0 Output Enable */
#define ENUM_AD242X_GPIOOEN_IO7_DIS          0x00000000            /*  IO7OEN: Disable */
#define ENUM_AD242X_GPIOOEN_IO7_EN           0x00000080            /*  IO7OEN: Enable */
#define ENUM_AD242X_GPIOOEN_IO6_DIS          0x00000000            /*  IO6OEN: Disable */
#define ENUM_AD242X_GPIOOEN_IO6_EN           0x00000040            /*  IO6OEN: Enable */
#define ENUM_AD242X_GPIOOEN_IO5_DIS          0x00000000            /*  IO5OEN: Disable */
#define ENUM_AD242X_GPIOOEN_IO5_EN           0x00000020            /*  IO5OEN: Enable */
#define ENUM_AD242X_GPIOOEN_IO4_DIS          0x00000000            /*  IO4OEN: Disable */
#define ENUM_AD242X_GPIOOEN_IO4_EN           0x00000010            /*  IO4OEN: Enable */
#define ENUM_AD242X_GPIOOEN_IO3_DIS          0x00000000            /*  IO3OEN: Disable */
#define ENUM_AD242X_GPIOOEN_IO3_EN           0x00000008            /*  IO3OEN: Enable */
#define ENUM_AD242X_GPIOOEN_IO2_DIS          0x00000000            /*  IO2OEN: Disable */
#define ENUM_AD242X_GPIOOEN_IO2_EN           0x00000004            /*  IO2OEN: Enable */
#define ENUM_AD242X_GPIOOEN_IO1_DIS          0x00000000            /*  IO1OEN: Disable */
#define ENUM_AD242X_GPIOOEN_IO1_EN           0x00000002            /*  IO1OEN: Enable */
#define ENUM_AD242X_GPIOOEN_IO0_DIS          0x00000000            /*  IO0OEN: Disable */
#define ENUM_AD242X_GPIOOEN_IO0_EN           0x00000001            /*  IO0OEN: Enable */

/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_GPIOIEN                       Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_GPIOIEN_IO7IEN            7            /*  IO7 Input Enable */
#define BITP_AD242X_GPIOIEN_IO6IEN            6            /*  IO6 Input Enable */
#define BITP_AD242X_GPIOIEN_IO5IEN            5            /*  IO5 Input Enable */
#define BITP_AD242X_GPIOIEN_IO4IEN            4            /*  IO4 Input Enable */
#define BITP_AD242X_GPIOIEN_IO3IEN            3            /*  IO3 Input Enable */
#define BITP_AD242X_GPIOIEN_IO2IEN            2            /*  IO2 Input Enable */
#define BITP_AD242X_GPIOIEN_IO1IEN            1            /*  IO1 Input Enable */
#define BITP_AD242X_GPIOIEN_IO0IEN            0            /*  IO0 Input Enable */
#define BITL_AD242X_GPIOIEN_IO0IEN            1            /*  IO0 Input Enable */
#define BITL_AD242X_GPIOIEN_IO1IEN            1            /*  IO1 Input Enable */
#define BITL_AD242X_GPIOIEN_IO2IEN            1            /*  IO2 Input Enable */
#define BITL_AD242X_GPIOIEN_IO3IEN            1            /*  IO3 Input Enable */
#define BITL_AD242X_GPIOIEN_IO4IEN            1            /*  IO4 Input Enable */
#define BITL_AD242X_GPIOIEN_IO5IEN            1            /*  IO5 Input Enable */
#define BITL_AD242X_GPIOIEN_IO6IEN            1            /*  IO6 Input Enable */
#define BITL_AD242X_GPIOIEN_IO7IEN            1            /*  IO7 Input Enable */

#define BITM_AD242X_GPIOIEN_IO7IEN           0x00000080    /*  IO7 Input Enable */

#define BITM_AD242X_GPIOIEN_IO6IEN           0x00000040    /*  IO6 Input Enable */

#define BITM_AD242X_GPIOIEN_IO5IEN           0x00000020    /*  IO5 Input Enable */

#define BITM_AD242X_GPIOIEN_IO4IEN           0x00000010    /*  IO4 Input Enable */

#define BITM_AD242X_GPIOIEN_IO3IEN           0x00000008    /*  IO3 Input Enable */

#define BITM_AD242X_GPIOIEN_IO2IEN           0x00000004    /*  IO2 Input Enable */

#define BITM_AD242X_GPIOIEN_IO1IEN           0x00000002    /*  IO1 Input Enable */

#define BITM_AD242X_GPIOIEN_IO0IEN           0x00000001    /*  IO0 Input Enable */
#define ENUM_AD242X_GPIOIEN_IO7_DIS          0x00000000            /*  IO7IEN: Disable */
#define ENUM_AD242X_GPIOIEN_IO7_EN           0x00000080            /*  IO7IEN: Enable */
#define ENUM_AD242X_GPIOIEN_IO6_DIS          0x00000000            /*  IO6IEN: Disable */
#define ENUM_AD242X_GPIOIEN_IO6_EN           0x00000040            /*  IO6IEN: Enable */
#define ENUM_AD242X_GPIOIEN_IO5_DIS          0x00000000            /*  IO5IEN: Disable */
#define ENUM_AD242X_GPIOIEN_IO5_EN           0x00000020            /*  IO5IEN: Enable */
#define ENUM_AD242X_GPIOIEN_IO4_DIS          0x00000000            /*  IO4IEN: Disable */
#define ENUM_AD242X_GPIOIEN_IO4_EN           0x00000010            /*  IO4IEN: Enable */
#define ENUM_AD242X_GPIOIEN_IO3_DIS          0x00000000            /*  IO3IEN: Disable */
#define ENUM_AD242X_GPIOIEN_IO3_EN           0x00000008            /*  IO3IEN: Enable */
#define ENUM_AD242X_GPIOIEN_IO2_DIS          0x00000000            /*  IO2IEN: Disable */
#define ENUM_AD242X_GPIOIEN_IO2_EN           0x00000004            /*  IO2IEN: Enable */
#define ENUM_AD242X_GPIOIEN_IO1_DIS          0x00000000            /*  IO1IEN: Disable */
#define ENUM_AD242X_GPIOIEN_IO1_EN           0x00000002            /*  IO1IEN: Enable */
#define ENUM_AD242X_GPIOIEN_IO0_DIS          0x00000000            /*  IO0IEN: Disable */
#define ENUM_AD242X_GPIOIEN_IO0_EN           0x00000001            /*  IO0IEN: Enable */

/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_GPIOIN                        Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_GPIOIN_IO7IN              7            /*  IO7 Input Value */
#define BITP_AD242X_GPIOIN_IO6IN              6            /*  IO6 Input Value */
#define BITP_AD242X_GPIOIN_IO5IN              5            /*  IO5 Input Value */
#define BITP_AD242X_GPIOIN_IO4IN              4            /*  IO4 Input Value */
#define BITP_AD242X_GPIOIN_IO3IN              3            /*  IO3 Input Value */
#define BITP_AD242X_GPIOIN_IO2IN              2            /*  IO2 Input Value */
#define BITP_AD242X_GPIOIN_IO1IN              1            /*  IO1 Input Value */
#define BITP_AD242X_GPIOIN_IO0IN              0            /*  IO0 Input Value */
#define BITL_AD242X_GPIOIN_IO0IN              1            /*  IO0 Input Value */
#define BITL_AD242X_GPIOIN_IO1IN              1            /*  IO1 Input Value */
#define BITL_AD242X_GPIOIN_IO2IN              1            /*  IO2 Input Value */
#define BITL_AD242X_GPIOIN_IO3IN              1            /*  IO3 Input Value */
#define BITL_AD242X_GPIOIN_IO4IN              1            /*  IO4 Input Value */
#define BITL_AD242X_GPIOIN_IO5IN              1            /*  IO5 Input Value */
#define BITL_AD242X_GPIOIN_IO6IN              1            /*  IO6 Input Value */
#define BITL_AD242X_GPIOIN_IO7IN              1            /*  IO7 Input Value */
#define BITM_AD242X_GPIOIN_IO7IN             0x00000080    /*  IO7 Input Value */
#define BITM_AD242X_GPIOIN_IO6IN             0x00000040    /*  IO6 Input Value */
#define BITM_AD242X_GPIOIN_IO5IN             0x00000020    /*  IO5 Input Value */
#define BITM_AD242X_GPIOIN_IO4IN             0x00000010    /*  IO4 Input Value */
#define BITM_AD242X_GPIOIN_IO3IN             0x00000008    /*  IO3 Input Value */
#define BITM_AD242X_GPIOIN_IO2IN             0x00000004    /*  IO2 Input Value */
#define BITM_AD242X_GPIOIN_IO1IN             0x00000002    /*  IO1 Input Value */
#define BITM_AD242X_GPIOIN_IO0IN             0x00000001    /*  IO0 Input Value */

/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_PINTEN                        Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_PINTEN_IO7IE              7            /*  IO7 Interrupt Request Capability Enable */
#define BITP_AD242X_PINTEN_IO6IE              6            /*  DRX1/IO6 Interrupt Request Capability Enable */
#define BITP_AD242X_PINTEN_IO5IE              5            /*  DRX0/IO5 Interrupt Request Capability Enable */
#define BITP_AD242X_PINTEN_IO4IE              4            /*  DTX1/IO4 Interrupt Request Capability Enable */
#define BITP_AD242X_PINTEN_IO3IE              3            /*  DTX0/IO3 Interrupt Request Capability Enable */
#define BITP_AD242X_PINTEN_IO2IE              2            /*  ADR2/IO2 Interrupt Request Capability Enable */
#define BITP_AD242X_PINTEN_IO1IE              1            /*  ADR1/IO1 Interrupt Request Capability Enable */
#define BITP_AD242X_PINTEN_IO0IE              0            /*  IRQ/IO0 Interrupt Request Capability Enable */
#define BITL_AD242X_PINTEN_IO0IE              1            /*  IRQ/IO0 Interrupt Request Capability Enable */
#define BITL_AD242X_PINTEN_IO1IE              1            /*  ADR1/IO1 Interrupt Request Capability Enable */
#define BITL_AD242X_PINTEN_IO2IE              1            /*  ADR2/IO2 Interrupt Request Capability Enable */
#define BITL_AD242X_PINTEN_IO3IE              1            /*  DTX0/IO3 Interrupt Request Capability Enable */
#define BITL_AD242X_PINTEN_IO4IE              1            /*  DTX1/IO4 Interrupt Request Capability Enable */
#define BITL_AD242X_PINTEN_IO5IE              1            /*  DRX0/IO5 Interrupt Request Capability Enable */
#define BITL_AD242X_PINTEN_IO6IE              1            /*  DRX1/IO6 Interrupt Request Capability Enable */
#define BITL_AD242X_PINTEN_IO7IE              1            /*  IO7 Interrupt Request Capability Enable */

#define BITM_AD242X_PINTEN_IO7IE             0x00000080    /*  IO7 Interrupt Request Capability Enable */

#define BITM_AD242X_PINTEN_IO6IE             0x00000040    /*  DRX1/IO6 Interrupt Request Capability Enable */

#define BITM_AD242X_PINTEN_IO5IE             0x00000020    /*  DRX0/IO5 Interrupt Request Capability Enable */

#define BITM_AD242X_PINTEN_IO4IE             0x00000010    /*  DTX1/IO4 Interrupt Request Capability Enable */

#define BITM_AD242X_PINTEN_IO3IE             0x00000008    /*  DTX0/IO3 Interrupt Request Capability Enable */

#define BITM_AD242X_PINTEN_IO2IE             0x00000004    /*  ADR2/IO2 Interrupt Request Capability Enable */

#define BITM_AD242X_PINTEN_IO1IE             0x00000002    /*  ADR1/IO1 Interrupt Request Capability Enable */

#define BITM_AD242X_PINTEN_IO0IE             0x00000001    /*  IRQ/IO0 Interrupt Request Capability Enable */
#define ENUM_AD242X_PINTEN_IO7_DIS           0x00000000            /*  IO7IE: Disable Interrupt Request Capability */
#define ENUM_AD242X_PINTEN_IO7_EN            0x00000080            /*  IO7IE: Enable Interrupt Request Capability */
#define ENUM_AD242X_PINTEN_IO6_DIS           0x00000000            /*  IO6IE: Disable Interrupt Request Capability */
#define ENUM_AD242X_PINTEN_IO6_EN            0x00000040            /*  IO6IE: Enable Interrupt Request Capability */
#define ENUM_AD242X_PINTEN_IO5_DIS           0x00000000            /*  IO5IE: Disable Interrupt Request Capability */
#define ENUM_AD242X_PINTEN_IO5_EN            0x00000020            /*  IO5IE: Enable Interrupt Request Capability */
#define ENUM_AD242X_PINTEN_IO4_DIS           0x00000000            /*  IO4IE: Disable Interrupt Request Capability */
#define ENUM_AD242X_PINTEN_IO4_EN            0x00000010            /*  IO4IE: Enable Interrupt Request Capability */
#define ENUM_AD242X_PINTEN_IO3_DIS           0x00000000            /*  IO3IE: Disable Interrupt Request Capability */
#define ENUM_AD242X_PINTEN_IO3_EN            0x00000008            /*  IO3IE: Enable Interrupt Request Capability */
#define ENUM_AD242X_PINTEN_IO2_DIS           0x00000000            /*  IO2IE: Disable Interrupt Request Capability */
#define ENUM_AD242X_PINTEN_IO2_EN            0x00000004            /*  IO2IE: Enable Interrupt Request Capability */
#define ENUM_AD242X_PINTEN_IO1_DIS           0x00000000            /*  IO1IE: Disable Interrupt Request Capability */
#define ENUM_AD242X_PINTEN_IO1_EN            0x00000002            /*  IO1IE: Enable Interrupt Request Capability */
#define ENUM_AD242X_PINTEN_IO0_DIS           0x00000000            /*  IO0IE: Disable Interrupt Request Capability */
#define ENUM_AD242X_PINTEN_IO0_EN            0x00000001            /*  IO0IE: Enable Interrupt Request Capability */

/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_PINTINV                       Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_PINTINV_IO7INV            7            /*  Invert IO7 */
#define BITP_AD242X_PINTINV_IO6INV            6            /*  Invert IO6 */
#define BITP_AD242X_PINTINV_IO5INV            5            /*  Invert IO5 */
#define BITP_AD242X_PINTINV_IO4INV            4            /*  Invert IO4 */
#define BITP_AD242X_PINTINV_IO3INV            3            /*  Invert IO3 */
#define BITP_AD242X_PINTINV_IO2INV            2            /*  Invert IO2 */
#define BITP_AD242X_PINTINV_IO1INV            1            /*  Invert IO1 */
#define BITP_AD242X_PINTINV_IO0INV            0            /*  Invert IO0 */
#define BITL_AD242X_PINTINV_IO0INV            1            /*  Invert IO0 */
#define BITL_AD242X_PINTINV_IO1INV            1            /*  Invert IO1 */
#define BITL_AD242X_PINTINV_IO2INV            1            /*  Invert IO2 */
#define BITL_AD242X_PINTINV_IO3INV            1            /*  Invert IO3 */
#define BITL_AD242X_PINTINV_IO4INV            1            /*  Invert IO4 */
#define BITL_AD242X_PINTINV_IO5INV            1            /*  Invert IO5 */
#define BITL_AD242X_PINTINV_IO6INV            1            /*  Invert IO6 */
#define BITL_AD242X_PINTINV_IO7INV            1            /*  Invert IO7 */

#define BITM_AD242X_PINTINV_IO7INV           0x00000080    /*  Invert IO7 */

#define BITM_AD242X_PINTINV_IO6INV           0x00000040    /*  Invert IO6 */

#define BITM_AD242X_PINTINV_IO5INV           0x00000020    /*  Invert IO5 */

#define BITM_AD242X_PINTINV_IO4INV           0x00000010    /*  Invert IO4 */

#define BITM_AD242X_PINTINV_IO3INV           0x00000008    /*  Invert IO3 */

#define BITM_AD242X_PINTINV_IO2INV           0x00000004    /*  Invert IO2 */

#define BITM_AD242X_PINTINV_IO1INV           0x00000002    /*  Invert IO1 */

#define BITM_AD242X_PINTINV_IO0INV           0x00000001    /*  Invert IO0 */
#define ENUM_AD242X_PINTINV_IO7_DIS          0x00000000            /*  IO7INV: Disable Inverter */
#define ENUM_AD242X_PINTINV_IO7_EN           0x00000080            /*  IO7INV: Active Low (Falling Edge) */
#define ENUM_AD242X_PINTINV_IO6_DIS          0x00000000            /*  IO6INV: Disable Inverter */
#define ENUM_AD242X_PINTINV_IO6_EN           0x00000040            /*  IO6INV: Active Low (Falling Edge) */
#define ENUM_AD242X_PINTINV_IO5_DIS          0x00000000            /*  IO5INV: Active High (Rising Edge) */
#define ENUM_AD242X_PINTINV_IO5_EN           0x00000020            /*  IO5INV: Active Low (Falling Edge) */
#define ENUM_AD242X_PINTINV_IO4_DIS          0x00000000            /*  IO4INV: Active High (Rising Edge) */
#define ENUM_AD242X_PINTINV_IO4_EN           0x00000010            /*  IO4INV: Active Low (Falling Edge) */
#define ENUM_AD242X_PINTINV_IO3_DIS          0x00000000            /*  IO3INV: Active High (Rising Edge) */
#define ENUM_AD242X_PINTINV_IO3_EN           0x00000008            /*  IO3INV: Active Low (Falling Edge) */
#define ENUM_AD242X_PINTINV_IO2_DIS          0x00000000            /*  IO2INV: Active High (Rising Edge) */
#define ENUM_AD242X_PINTINV_IO2_EN           0x00000004            /*  IO2INV: Active Low (Falling Edge) */
#define ENUM_AD242X_PINTINV_IO1_DIS          0x00000000            /*  IO1INV: Active High (Rising Edge) */
#define ENUM_AD242X_PINTINV_IO1_EN           0x00000002            /*  IO1INV: Active Low (Falling Edge) */
#define ENUM_AD242X_PINTINV_IO0_DIS          0x00000000            /*  IO0INV: Active High (Rising Edge) */
#define ENUM_AD242X_PINTINV_IO0_EN           0x00000001            /*  IO0INV: Active Low (Falling Edge) */

/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_CLK1CFG                       Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_CLK1CFG_CLK1EN            7            /*  CLKOUT1 Enable */
#define BITP_AD242X_CLK1CFG_CLK1INV           6            /*  CLKOUT1 Invert Enable */
#define BITP_AD242X_CLK1CFG_CLK1PDIV          5            /*  Pre-Divide Value for CLKOUT1 */
#define BITP_AD242X_CLK1CFG_CLK1DIV           0            /*  Divide Value for CLKOUT1 */
#define BITL_AD242X_CLK1CFG_CLK1DIV           4            /*  Divide Value for CLKOUT1 */
#define BITL_AD242X_CLK1CFG_CLK1EN            1            /*  CLKOUT1 Enable */
#define BITL_AD242X_CLK1CFG_CLK1INV           1            /*  CLKOUT1 Invert Enable */
#define BITL_AD242X_CLK1CFG_CLK1PDIV          1            /*  Pre-Divide Value for CLKOUT1 */

#define BITM_AD242X_CLK1CFG_CLK1EN           0x00000080    /*  CLKOUT1 Enable */

#define BITM_AD242X_CLK1CFG_CLK1INV          0x00000040    /*  CLKOUT1 Invert Enable */

#define BITM_AD242X_CLK1CFG_CLK1PDIV         0x00000020    /*  Pre-Divide Value for CLKOUT1 */
#define BITM_AD242X_CLK1CFG_CLK1DIV          0x0000000F    /*  Divide Value for CLKOUT1 */
#define ENUM_AD242X_CLK1CFG_CLK1EN_DIS       0x00000000            /*  CLK1EN: CLKOUT1 Generation Disabled */
#define ENUM_AD242X_CLK1CFG_CLK1EN_EN        0x00000080            /*  CLK1EN: CLKOUT1 Generation Enabled */
#define ENUM_AD242X_CLK1CFG_CLK1INV_DIS      0x00000000            /*  CLK1INV: CLKOUT1 Inversion Disabled */
#define ENUM_AD242X_CLK1CFG_CLK1INV_EN       0x00000040            /*  CLK1INV: CLKOUT1 Inversion Enabled */
#define ENUM_AD242X_CLK1CFG_CLK1PDIV_2       0x00000000            /*  CLK1PDIV: CLKOUT1 Pre-Divide is 2 */
#define ENUM_AD242X_CLK1CFG_CLK1PDIV_32      0x00000020            /*  CLK1PDIV: CLKOUT1 Pre-Divide is 32 */

/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_CLK2CFG                       Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_CLK2CFG_CLK2EN            7            /*  CLKOUT2 Enable */
#define BITP_AD242X_CLK2CFG_CLK2INV           6            /*  CLKOUT2 Invert Enable */
#define BITP_AD242X_CLK2CFG_CLK2PDIV          5            /*  Pre-Divide Value for CLKOUT2 */
#define BITP_AD242X_CLK2CFG_CLK2DIV           0            /*  Divide Value for CLKOUT2 */
#define BITL_AD242X_CLK2CFG_CLK2DIV           4            /*  Divide Value for CLKOUT2 */
#define BITL_AD242X_CLK2CFG_CLK2EN            1            /*  CLKOUT2 Enable */
#define BITL_AD242X_CLK2CFG_CLK2INV           1            /*  CLKOUT2 Invert Enable */
#define BITL_AD242X_CLK2CFG_CLK2PDIV          1            /*  Pre-Divide Value for CLKOUT2 */

#define BITM_AD242X_CLK2CFG_CLK2EN           0x00000080    /*  CLKOUT2 Enable */

#define BITM_AD242X_CLK2CFG_CLK2INV          0x00000040    /*  CLKOUT2 Invert Enable */

#define BITM_AD242X_CLK2CFG_CLK2PDIV         0x00000020    /*  Pre-Divide Value for CLKOUT2 */
#define BITM_AD242X_CLK2CFG_CLK2DIV          0x0000000F    /*  Divide Value for CLKOUT2 */
#define ENUM_AD242X_CLK2CFG_CLK2EN_DIS       0x00000000            /*  CLK2EN: CLKOUT2 Generation Disabled */
#define ENUM_AD242X_CLK2CFG_CLK2EN_EN        0x00000080            /*  CLK2EN: CLKOUT2 Generation Enabled */
#define ENUM_AD242X_CLK2CFG_CLK2INV_DIS      0x00000000            /*  CLK2INV: CLKOUT2 Inversion Disabled */
#define ENUM_AD242X_CLK2CFG_CLK2INV_EN       0x00000040            /*  CLK2INV: CLKOUT2 Inversion Enabled */
#define ENUM_AD242X_CLK2CFG_CLK2PDIV_2       0x00000000            /*  CLK2PDIV: CLKOUT2 Pre-Divide is 2 */
#define ENUM_AD242X_CLK2CFG_CLK2PDIV_32      0x00000020            /*  CLK2PDIV: CLKOUT2 Pre-Divide is 32 */

/* ============================================================================================================================
 *    Shadow_Register_Committed_Copy_Read_Access Register Field Definitions
 * ============================================================================================================================ */
/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_RESPCCC                       Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_RESPCCC_RESPCCC           0            /*  Response Cycles Committed */
#define BITL_AD242X_RESPCCC_RESPCCC           8            /*  Response Cycles Committed */
#define BITM_AD242X_RESPCCC_RESPCCC          0x000000FF    /*  Response Cycles Committed */

/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_DCTLCC                        Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_DCTLCC_DCTLCC             0            /*  Data Control Committed */
#define BITL_AD242X_DCTLCC_DCTLCC             8            /*  Data Control Committed */
#define BITM_AD242X_DCTLCC_DCTLCC            0x000000FF    /*  Data Control Committed */

/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_DNSCC                         Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_DNSCC_DNSCC               0            /*  Downstream Slots Committed Copy */
#define BITL_AD242X_DNSCC_DNSCC               8            /*  Downstream Slots Committed Copy */
#define BITM_AD242X_DNSCC_DNSCC              0x000000FF    /*  Downstream Slots Committed Copy */

/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_LDNSCC                        Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_LDNSCC_LDNSCC             0            /*  Local Downstream Slots Committed Copy */
#define BITL_AD242X_LDNSCC_LDNSCC             8            /*  Local Downstream Slots Committed Copy */
#define BITM_AD242X_LDNSCC_LDNSCC            0x000000FF    /*  Local Downstream Slots Committed Copy */

/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_UPSCC                         Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_UPSCC_UPSCC               0            /*  Upstream Slots Committed Copy */
#define BITL_AD242X_UPSCC_UPSCC               8            /*  Upstream Slots Committed Copy */
#define BITM_AD242X_UPSCC_UPSCC              0x000000FF    /*  Upstream Slots Committed Copy */

/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_LUPSCC                        Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_LUPSCC_LUPSCC             0            /*  Local Upstream Slots Committed Copy */
#define BITL_AD242X_LUPSCC_LUPSCC             8            /*  Local Upstream Slots Committed Copy */
#define BITM_AD242X_LUPSCC_LUPSCC            0x000000FF    /*  Local Upstream Slots Committed Copy */

/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_BCDNSCC                       Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_BCDNSCC_BCDNSCC           0            /*  Broadcast Downstream Slots Committed Copy */
#define BITL_AD242X_BCDNSCC_BCDNSCC           8            /*  Broadcast Downstream Slots Committed Copy */
#define BITM_AD242X_BCDNSCC_BCDNSCC          0x000000FF    /*  Broadcast Downstream Slots Committed Copy */

/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_SFMTCC                        Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_SFMTCC_SFMTCC             0            /*  Slot Format Committed Copy */
#define BITL_AD242X_SFMTCC_SFMTCC             8            /*  Slot Format Committed Copy */
#define BITM_AD242X_SFMTCC_SFMTCC            0x000000FF    /*  Slot Format Committed Copy */

/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_UMSK0CC                       Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_UMSK0CC_UMSK0CC           0            /*  Upstream Data RX Mask 0 Committed Copy */
#define BITL_AD242X_UMSK0CC_UMSK0CC           8            /*  Upstream Data RX Mask 0 Committed Copy */
#define BITM_AD242X_UMSK0CC_UMSK0CC          0x000000FF    /*  Upstream Data RX Mask 0 Committed Copy */

/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_UMSK1CC                       Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_UMSK1CC_UMSK1CC           0            /*  Upstream Data RX Mask 1 Committed Copy */
#define BITL_AD242X_UMSK1CC_UMSK1CC           8            /*  Upstream Data RX Mask 1 Committed Copy */
#define BITM_AD242X_UMSK1CC_UMSK1CC          0x000000FF    /*  Upstream Data RX Mask 1 Committed Copy */

/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_UMSK2CC                       Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_UMSK2CC_UMSK2CC           0            /*  Upstream Data RX Mask 2 Committed Copy */
#define BITL_AD242X_UMSK2CC_UMSK2CC           8            /*  Upstream Data RX Mask 2 Committed Copy */
#define BITM_AD242X_UMSK2CC_UMSK2CC          0x000000FF    /*  Upstream Data RX Mask 2 Committed Copy */

/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_UMSK3CC                       Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_UMSK3CC_UMSK3CC           0            /*  Upstream Data RX Mask 3 Committed Copy */
#define BITL_AD242X_UMSK3CC_UMSK3CC           8            /*  Upstream Data RX Mask 3 Committed Copy */
#define BITM_AD242X_UMSK3CC_UMSK3CC          0x000000FF    /*  Upstream Data RX Mask 3 Committed Copy */

/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_UOFFSCC                       Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_UOFFSCC_UOFFSCC           0            /*  Local Upstream Slots Offset Committed Copy */
#define BITL_AD242X_UOFFSCC_UOFFSCC           8            /*  Local Upstream Slots Offset Committed Copy */
#define BITM_AD242X_UOFFSCC_UOFFSCC          0x000000FF    /*  Local Upstream Slots Offset Committed Copy */

/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_DMSK0CC                       Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_DMSK0CC_DMSK0CC           0            /*  Downstream Data RX Mask 0 Committed Copy */
#define BITL_AD242X_DMSK0CC_DMSK0CC           8            /*  Downstream Data RX Mask 0 Committed Copy */
#define BITM_AD242X_DMSK0CC_DMSK0CC          0x000000FF    /*  Downstream Data RX Mask 0 Committed Copy */

/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_DMSK1CC                       Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_DMSK1CC_DMSK1CC           0            /*  Downstream Data RX Mask 1 Committed Copy */
#define BITL_AD242X_DMSK1CC_DMSK1CC           8            /*  Downstream Data RX Mask 1 Committed Copy */
#define BITM_AD242X_DMSK1CC_DMSK1CC          0x000000FF    /*  Downstream Data RX Mask 1 Committed Copy */

/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_DMSK2CC                       Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_DMSK2CC_DMSK2CC           0            /*  Downstream Data RX Mask 2 Committed Copy */
#define BITL_AD242X_DMSK2CC_DMSK2CC           8            /*  Downstream Data RX Mask 2 Committed Copy */
#define BITM_AD242X_DMSK2CC_DMSK2CC          0x000000FF    /*  Downstream Data RX Mask 2 Committed Copy */

/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_DMSK3CC                       Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_DMSK3CC_DMSK3CC           0            /*  Downstream Data RX Mask 3 Committed Copy */
#define BITL_AD242X_DMSK3CC_DMSK3CC           8            /*  Downstream Data RX Mask 3 Committed Copy */
#define BITM_AD242X_DMSK3CC_DMSK3CC          0x000000FF    /*  Downstream Data RX Mask 3 Committed Copy */

/* -------------------------------------------------------------------------------------------------------------------------
          AD242x_DOFFSCC                       Pos/Masks         Description
   ------------------------------------------------------------------------------------------------------------------------- */
#define BITP_AD242X_DOFFSCC_DOFFSCC           0            /*  Local Downstream Slots Offset Committed Copy */
#define BITL_AD242X_DOFFSCC_DOFFSCC           8            /*  Local Downstream Slots Offset Committed Copy */
#define BITM_AD242X_DOFFSCC_DOFFSCC          0x000000FF    /*  Local Downstream Slots Offset Committed Copy */


/* AD242x Parameters */

/***** AD242x0  */
#define PARAM_AD242X0_ALLREGS               1
#define PARAM_AD242X0_MASTER                0
#define PARAM_AD242X0_SLAVE                 0
#define PARAM_AD242X0_BMON                  0
/* -------------------------------------------------------------------------------------------------------------------------
 *
 *  AD242x (AD242x) Parameters
 *
 * ------------------------------------------------------------------------------------------------------------------------- */
#define PARAM_AD242x_ALLREGS                 0x1
#define PARAM_AD242x_BMON                    0x0
#define PARAM_AD242x_MASTER                  0x0
#define PARAM_AD242x_SLAVE                   0x0

#endif  /* end ifndef _DEF_AD242X_H */
