/*
 * NAME : RCC_interface.h
 * DATE : 8-8-2023
 * AUTHOR :Mai_Kamel
 * VESION : _v1_
 * NOTE :
 *
 */


/**********************************************************************************
 ***********************guard of file will call on time in .c *********************
 *********************************************************************************/
#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_

typedef enum{
	AHB1 =0,
	AHB2,
	APB1,
	APB2
}BusName_t;

#define AHB1_BUS 0
#define AHB2_BUS 1
#define APB1_BUS 2
#define APB2_BUS 3

/*
 *Function To Enable Peripheral:
  	  	  BusName_t : Bus of Peripheral
  	  	  copy_u8perNum : t=The order of Peripheral on the selected register
 */
void MRCC_vEnableClock(BusName_t BusName, u8 copy_u8perNum);

/*
 *Function To Disable Peripheral:
  	  	  BusName_t : Bus of Peripheral
  	  	  copy_u8perNum : t=The order of Peripheral on the selected register
 */
void MRCC_vDisableClock(BusName_t BusName, u8 copy_u8perNum);


typedef enum{
	RCC_HSE = 0,
	RCC_HSI,
	RCC_PLL

}CLKSrcName_t;
#define HSE 0u
#define HSI 1u
#define PLL 2u


typedef enum{
	HSE_CRYSTAL = 0,
	HSE_RC
}HSESrc_t;
#define _HSE_CRYSTAL  0u
#define _HSE_RC       1u


typedef enum{
	HSE_pll = 0,
	HSI_pll
}PLLSrc_t;
#define HSE_pll 0u
#define HSI_pll 1u

void MRCC_vInitClock(CLKSrcName_t copy_tCLKSrc, HSESrc_t copy_tHSESrc_t, PLLSrc_t copy_tPLLSrc_t);
#endif
