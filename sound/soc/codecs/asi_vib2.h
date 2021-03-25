// SPDX-License-Identifier: GPL-2.0
/*
 * Texas Instruments ASI_VIB2 Audio ADC
 *
 * Copyright (C) 2015-2017 Texas Instruments Incorporated - http://www.ti.com
 *	Andreas Dannenberg <dannenberg@ti.com>
 *	Andrew F. Davis <afd@ti.com>
 */

#ifndef _ASI_VIB2_H_
#define _ASI_VIB2_H_

#include <linux/pm.h>
#include <linux/regmap.h>

enum asi_vib2_type {
	ASI_VIB2,
};

#define ASI_VIB2_RATES	SNDRV_PCM_RATE_8000_192000
#define ASI_VIB2_FORMATS	(SNDRV_PCM_FMTBIT_S16_LE | \
			 SNDRV_PCM_FMTBIT_S20_3LE |\
			 SNDRV_PCM_FMTBIT_S24_LE | \
			 SNDRV_PCM_FMTBIT_S32_LE)

#define ASI_VIB2_PAGE_LEN		0x0100
#define ASI_VIB2_PAGE_BASE(n)		(ASI_VIB2_PAGE_LEN * n)

/* The page selection register address is the same on all pages */
#define ASI_VIB2_PAGE			0

/* Register Definitions - Page 0 */
#define ASI_VIB2_PGA_VAL_CH1_L		(ASI_VIB2_PAGE_BASE(0) +   1)
#define ASI_VIB2_PGA_VAL_CH1_R		(ASI_VIB2_PAGE_BASE(0) +   2)
#define ASI_VIB2_PGA_VAL_CH2_L		(ASI_VIB2_PAGE_BASE(0) +   3)
#define ASI_VIB2_PGA_VAL_CH2_R		(ASI_VIB2_PAGE_BASE(0) +   4)
#define ASI_VIB2_PGA_CTRL		(ASI_VIB2_PAGE_BASE(0) +   5)
#define ASI_VIB2_ADC1_INPUT_SEL_L	(ASI_VIB2_PAGE_BASE(0) +   6)
#define ASI_VIB2_ADC1_INPUT_SEL_R	(ASI_VIB2_PAGE_BASE(0) +   7)
#define ASI_VIB2_ADC2_INPUT_SEL_L	(ASI_VIB2_PAGE_BASE(0) +   8)
#define ASI_VIB2_ADC2_INPUT_SEL_R	(ASI_VIB2_PAGE_BASE(0) +   9)
#define ASI_VIB2_AUXADC_INPUT_SEL	(ASI_VIB2_PAGE_BASE(0) +  10)
#define ASI_VIB2_PCM_CFG			(ASI_VIB2_PAGE_BASE(0) +  11)
#define ASI_VIB2_TDM_TX_SEL		(ASI_VIB2_PAGE_BASE(0) +  12)
#define ASI_VIB2_TDM_TX_OFFSET		(ASI_VIB2_PAGE_BASE(0) +  13)
#define ASI_VIB2_TDM_RX_OFFSET		(ASI_VIB2_PAGE_BASE(0) +  14)
#define ASI_VIB2_DPGA_VAL_CH1_L		(ASI_VIB2_PAGE_BASE(0) +  15)
#define ASI_VIB2_GPIO1_0_CTRL		(ASI_VIB2_PAGE_BASE(0) +  16)
#define ASI_VIB2_GPIO3_2_CTRL		(ASI_VIB2_PAGE_BASE(0) +  17)
#define ASI_VIB2_GPIO1_0_DIR_CTRL	(ASI_VIB2_PAGE_BASE(0) +  18)
#define ASI_VIB2_GPIO3_2_DIR_CTRL	(ASI_VIB2_PAGE_BASE(0) +  19)
#define ASI_VIB2_GPIO_IN_OUT		(ASI_VIB2_PAGE_BASE(0) +  20)
#define ASI_VIB2_GPIO_PULL_CTRL		(ASI_VIB2_PAGE_BASE(0) +  21)
#define ASI_VIB2_DPGA_VAL_CH1_R		(ASI_VIB2_PAGE_BASE(0) +  22)
#define ASI_VIB2_DPGA_VAL_CH2_L		(ASI_VIB2_PAGE_BASE(0) +  23)
#define ASI_VIB2_DPGA_VAL_CH2_R		(ASI_VIB2_PAGE_BASE(0) +  24)
#define ASI_VIB2_DPGA_GAIN_CTRL		(ASI_VIB2_PAGE_BASE(0) +  25)
#define ASI_VIB2_DPGA_MIC_CTRL		(ASI_VIB2_PAGE_BASE(0) +  26)
#define ASI_VIB2_DIN_RESAMP_CTRL		(ASI_VIB2_PAGE_BASE(0) +  27)
#define ASI_VIB2_CLK_CTRL		(ASI_VIB2_PAGE_BASE(0) +  32)
#define ASI_VIB2_DSP1_CLK_DIV		(ASI_VIB2_PAGE_BASE(0) +  33)
#define ASI_VIB2_DSP2_CLK_DIV		(ASI_VIB2_PAGE_BASE(0) +  34)
#define ASI_VIB2_ADC_CLK_DIV		(ASI_VIB2_PAGE_BASE(0) +  35)
#define ASI_VIB2_PLL_SCK_DIV		(ASI_VIB2_PAGE_BASE(0) +  37)
#define ASI_VIB2_BCK_DIV			(ASI_VIB2_PAGE_BASE(0) +  38)
#define ASI_VIB2_LRK_DIV			(ASI_VIB2_PAGE_BASE(0) +  39)
#define ASI_VIB2_PLL_CTRL		(ASI_VIB2_PAGE_BASE(0) +  40)
#define ASI_VIB2_PLL_P_DIV		(ASI_VIB2_PAGE_BASE(0) +  41)
#define ASI_VIB2_PLL_R_DIV		(ASI_VIB2_PAGE_BASE(0) +  42)
#define ASI_VIB2_PLL_J_DIV		(ASI_VIB2_PAGE_BASE(0) +  43)
#define ASI_VIB2_PLL_D_DIV_LSB		(ASI_VIB2_PAGE_BASE(0) +  44)
#define ASI_VIB2_PLL_D_DIV_MSB		(ASI_VIB2_PAGE_BASE(0) +  45)
#define ASI_VIB2_SIGDET_MODE		(ASI_VIB2_PAGE_BASE(0) +  48)
#define ASI_VIB2_SIGDET_MASK		(ASI_VIB2_PAGE_BASE(0) +  49)
#define ASI_VIB2_SIGDET_STAT		(ASI_VIB2_PAGE_BASE(0) +  50)
#define ASI_VIB2_SIGDET_LOSS_TIME	(ASI_VIB2_PAGE_BASE(0) +  52)
#define ASI_VIB2_SIGDET_SCAN_TIME	(ASI_VIB2_PAGE_BASE(0) +  53)
#define ASI_VIB2_SIGDET_INT_INTVL	(ASI_VIB2_PAGE_BASE(0) +  54)
#define ASI_VIB2_SIGDET_DC_REF_CH1_L	(ASI_VIB2_PAGE_BASE(0) +  64)
#define ASI_VIB2_SIGDET_DC_DIFF_CH1_L	(ASI_VIB2_PAGE_BASE(0) +  65)
#define ASI_VIB2_SIGDET_DC_LEV_CH1_L	(ASI_VIB2_PAGE_BASE(0) +  66)
#define ASI_VIB2_SIGDET_DC_REF_CH1_R	(ASI_VIB2_PAGE_BASE(0) +  67)
#define ASI_VIB2_SIGDET_DC_DIFF_CH1_R	(ASI_VIB2_PAGE_BASE(0) +  68)
#define ASI_VIB2_SIGDET_DC_LEV_CH1_R	(ASI_VIB2_PAGE_BASE(0) +  69)
#define ASI_VIB2_SIGDET_DC_REF_CH2_L	(ASI_VIB2_PAGE_BASE(0) +  70)
#define ASI_VIB2_SIGDET_DC_DIFF_CH2_L	(ASI_VIB2_PAGE_BASE(0) +  71)
#define ASI_VIB2_SIGDET_DC_LEV_CH2_L	(ASI_VIB2_PAGE_BASE(0) +  72)
#define ASI_VIB2_SIGDET_DC_REF_CH2_R	(ASI_VIB2_PAGE_BASE(0) +  73)
#define ASI_VIB2_SIGDET_DC_DIFF_CH2_R	(ASI_VIB2_PAGE_BASE(0) +  74)
#define ASI_VIB2_SIGDET_DC_LEV_CH2_R	(ASI_VIB2_PAGE_BASE(0) +  75)
#define ASI_VIB2_SIGDET_DC_REF_CH3_L	(ASI_VIB2_PAGE_BASE(0) +  76)
#define ASI_VIB2_SIGDET_DC_DIFF_CH3_L	(ASI_VIB2_PAGE_BASE(0) +  77)
#define ASI_VIB2_SIGDET_DC_LEV_CH3_L	(ASI_VIB2_PAGE_BASE(0) +  78)
#define ASI_VIB2_SIGDET_DC_REF_CH3_R	(ASI_VIB2_PAGE_BASE(0) +  79)
#define ASI_VIB2_SIGDET_DC_DIFF_CH3_R	(ASI_VIB2_PAGE_BASE(0) +  80)
#define ASI_VIB2_SIGDET_DC_LEV_CH3_R	(ASI_VIB2_PAGE_BASE(0) +  81)
#define ASI_VIB2_SIGDET_DC_REF_CH4_L	(ASI_VIB2_PAGE_BASE(0) +  82)
#define ASI_VIB2_SIGDET_DC_DIFF_CH4_L	(ASI_VIB2_PAGE_BASE(0) +  83)
#define ASI_VIB2_SIGDET_DC_LEV_CH4_L	(ASI_VIB2_PAGE_BASE(0) +  84)
#define ASI_VIB2_SIGDET_DC_REF_CH4_R	(ASI_VIB2_PAGE_BASE(0) +  85)
#define ASI_VIB2_SIGDET_DC_DIFF_CH4_R	(ASI_VIB2_PAGE_BASE(0) +  86)
#define ASI_VIB2_SIGDET_DC_LEV_CH4_R	(ASI_VIB2_PAGE_BASE(0) +  87)
#define ASI_VIB2_AUXADC_DATA_CTRL	(ASI_VIB2_PAGE_BASE(0) +  88)
#define ASI_VIB2_AUXADC_DATA_LSB		(ASI_VIB2_PAGE_BASE(0) +  89)
#define ASI_VIB2_AUXADC_DATA_MSB		(ASI_VIB2_PAGE_BASE(0) +  90)
#define ASI_VIB2_INT_ENABLE		(ASI_VIB2_PAGE_BASE(0) +  96)
#define ASI_VIB2_INT_FLAG		(ASI_VIB2_PAGE_BASE(0) +  97)
#define ASI_VIB2_INT_POL_WIDTH		(ASI_VIB2_PAGE_BASE(0) +  98)
#define ASI_VIB2_POWER_CTRL		(ASI_VIB2_PAGE_BASE(0) + 112)
#define ASI_VIB2_FILTER_MUTE_CTRL	(ASI_VIB2_PAGE_BASE(0) + 113)
#define ASI_VIB2_DEVICE_STATUS		(ASI_VIB2_PAGE_BASE(0) + 114)
#define ASI_VIB2_FSAMPLE_STATUS		(ASI_VIB2_PAGE_BASE(0) + 115)
#define ASI_VIB2_DIV_STATUS		(ASI_VIB2_PAGE_BASE(0) + 116)
#define ASI_VIB2_CLK_STATUS		(ASI_VIB2_PAGE_BASE(0) + 117)
#define ASI_VIB2_SUPPLY_STATUS		(ASI_VIB2_PAGE_BASE(0) + 120)

/* Register Definitions - Page 1 */
#define ASI_VIB2_MMAP_STAT_CTRL		(ASI_VIB2_PAGE_BASE(1) +   1)
#define ASI_VIB2_MMAP_ADDRESS		(ASI_VIB2_PAGE_BASE(1) +   2)
#define ASI_VIB2_MEM_WDATA0		(ASI_VIB2_PAGE_BASE(1) +   4)
#define ASI_VIB2_MEM_WDATA1		(ASI_VIB2_PAGE_BASE(1) +   5)
#define ASI_VIB2_MEM_WDATA2		(ASI_VIB2_PAGE_BASE(1) +   6)
#define ASI_VIB2_MEM_WDATA3		(ASI_VIB2_PAGE_BASE(1) +   7)
#define ASI_VIB2_MEM_RDATA0		(ASI_VIB2_PAGE_BASE(1) +   8)
#define ASI_VIB2_MEM_RDATA1		(ASI_VIB2_PAGE_BASE(1) +   9)
#define ASI_VIB2_MEM_RDATA2		(ASI_VIB2_PAGE_BASE(1) +  10)
#define ASI_VIB2_MEM_RDATA3		(ASI_VIB2_PAGE_BASE(1) +  11)

/* Register Definitions - Page 3 */
#define ASI_VIB2_OSC_PWR_DOWN_CTRL	(ASI_VIB2_PAGE_BASE(3) +  18)
#define ASI_VIB2_MIC_BIAS_CTRL		(ASI_VIB2_PAGE_BASE(3) +  21)

/* Register Definitions - Page 253 */
#define ASI_VIB2_CURR_TRIM_CTRL		(ASI_VIB2_PAGE_BASE(253) +  20)

#define ASI_VIB2_MAX_REGISTER		ASI_VIB2_CURR_TRIM_CTRL

/* ASI_VIB2_PAGE */
#define ASI_VIB2_RESET			0xfe

/* ASI_VIB2_ADCX_INPUT_SEL_X */
#define ASI_VIB2_ADC_INPUT_SEL_POL	BIT(7)
#define ASI_VIB2_ADC_INPUT_SEL_MASK	GENMASK(5, 0)

/* ASI_VIB2_PCM_CFG */
#define ASI_VIB2_PCM_CFG_RX_WLEN_MASK	GENMASK(7, 6)
#define ASI_VIB2_PCM_CFG_RX_WLEN_SHIFT	6
#define ASI_VIB2_PCM_CFG_RX_WLEN_32	0x00
#define ASI_VIB2_PCM_CFG_RX_WLEN_24	0x01
#define ASI_VIB2_PCM_CFG_RX_WLEN_20	0x02
#define ASI_VIB2_PCM_CFG_RX_WLEN_16	0x03
#define ASI_VIB2_PCM_CFG_TDM_LRCK_MODE	BIT(4)
#define ASI_VIB2_PCM_CFG_TX_WLEN_MASK	GENMASK(3, 2)
#define ASI_VIB2_PCM_CFG_TX_WLEN_SHIFT	2
#define ASI_VIB2_PCM_CFG_TX_WLEN_32	0x00
#define ASI_VIB2_PCM_CFG_TX_WLEN_24	0x01
#define ASI_VIB2_PCM_CFG_TX_WLEN_20	0x02
#define ASI_VIB2_PCM_CFG_TX_WLEN_16	0x03
#define ASI_VIB2_PCM_CFG_FMT_MASK	GENMASK(1, 0)
#define ASI_VIB2_PCM_CFG_FMT_SHIFT	0
#define ASI_VIB2_PCM_CFG_FMT_I2S		0x00
#define ASI_VIB2_PCM_CFG_FMT_LEFTJ	0x01
#define ASI_VIB2_PCM_CFG_FMT_RIGHTJ	0x02
#define ASI_VIB2_PCM_CFG_FMT_TDM		0x03

/* ASI_VIB2_TDM_TX_SEL */
#define ASI_VIB2_TDM_TX_SEL_2CH		0x00
#define ASI_VIB2_TDM_TX_SEL_4CH		0x01
#define ASI_VIB2_TDM_TX_SEL_6CH		0x02
#define ASI_VIB2_TDM_TX_SEL_MASK		0x03

/* ASI_VIB2_CLK_CTRL */
#define ASI_VIB2_CLK_CTRL_SCK_XI_SEL1	BIT(7)
#define ASI_VIB2_CLK_CTRL_SCK_XI_SEL0	BIT(6)
#define ASI_VIB2_CLK_CTRL_SCK_SRC_PLL	BIT(5)
#define ASI_VIB2_CLK_CTRL_MST_MODE	BIT(4)
#define ASI_VIB2_CLK_CTRL_ADC_SRC_PLL	BIT(3)
#define ASI_VIB2_CLK_CTRL_DSP2_SRC_PLL	BIT(2)
#define ASI_VIB2_CLK_CTRL_DSP1_SRC_PLL	BIT(1)
#define ASI_VIB2_CLK_CTRL_CLKDET_EN	BIT(0)

/* ASI_VIB2_PLL_CTRL */
#define ASI_VIB2_PLL_CTRL_LOCK		BIT(4)
#define ASI_VIB2_PLL_CTRL_REF_SEL	BIT(1)
#define ASI_VIB2_PLL_CTRL_EN		BIT(0)

/* ASI_VIB2_POWER_CTRL */
#define ASI_VIB2_PWR_CTRL_PWRDN		BIT(2)
#define ASI_VIB2_PWR_CTRL_SLEEP		BIT(1)
#define ASI_VIB2_PWR_CTRL_STBY		BIT(0)

/* ASI_VIB2_CLK_STATUS */
#define ASI_VIB2_CLK_STATUS_LRCKHLT	BIT(6)
#define ASI_VIB2_CLK_STATUS_BCKHLT	BIT(5)
#define ASI_VIB2_CLK_STATUS_SCKHLT	BIT(4)
#define ASI_VIB2_CLK_STATUS_LRCKERR	BIT(2)
#define ASI_VIB2_CLK_STATUS_BCKERR	BIT(1)
#define ASI_VIB2_CLK_STATUS_SCKERR	BIT(0)

/* ASI_VIB2_SUPPLY_STATUS */
#define ASI_VIB2_SUPPLY_STATUS_DVDD	BIT(2)
#define ASI_VIB2_SUPPLY_STATUS_AVDD	BIT(1)
#define ASI_VIB2_SUPPLY_STATUS_LDO	BIT(0)

/* ASI_VIB2_MMAP_STAT_CTRL */
#define ASI_VIB2_MMAP_STAT_DONE		BIT(4)
#define ASI_VIB2_MMAP_STAT_BUSY		BIT(2)
#define ASI_VIB2_MMAP_STAT_R_REQ		BIT(1)
#define ASI_VIB2_MMAP_STAT_W_REQ		BIT(0)

extern const struct regmap_config asi_vib2_regmap;

int asi_vib2_probe(struct device *dev, enum asi_vib2_type type, int irq,
		  struct regmap *regmap);

#endif /* _ASI_VIB2_H_ */
