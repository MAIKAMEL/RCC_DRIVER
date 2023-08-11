/*

 * RCC_prog.c

 *
 *  Created on: Aug 8, 2023
 *      Author: ME
 */


#include <BIT_math.h>
#include <RCC_private.h>
#include <RCC_config.h>
#include <RCC_interface.h>
#include "../../RCCdriver/include/STD_TYPES.h"

MRCC_vEnableClock(BusName_t BusName, u8 copy_u8perNum){
	switch(BusName){
		case AHB1_BUS: SET_BIT(RCC_AHB1ENR, copy_u8perNum); break;
		case AHB2_BUS: SET_BIT(RCC_AHB2ENR, copy_u8perNum); break;
		case APB1_BUS: SET_BIT(RCC_APB1ENR, copy_u8perNum); break;
		case APB2_BUS: SET_BIT(RCC_APB2ENR, copy_u8perNum); break;
		default: break;
	}
}

MRCC_vDisableClock(BusName_t BusName, u8 copy_u8perNum){
	switch(BusName){
		case AHB1_BUS: CLR_BIT(RCC_AHB1ENR, copy_u8perNum); break;
		case AHB2_BUS: CLR_BIT(RCC_AHB2ENR, copy_u8perNum); break;
		case APB1_BUS: CLR_BIT(RCC_APB1ENR, copy_u8perNum); break;
		case APB2_BUS: CLR_BIT(RCC_APB2ENR, copy_u8perNum); break;
		default: break;
	}
}

MRCC_vInitClock(CLKSrcName_t copy_tCLKSrc, HSESrc_t copy_tHSESrc_t, PLLSrc_t copy_tPLLSrc_t)
{
	/*******************************81- switch on copy_tCLKSrc***********************************/
	switch(copy_tCLKSrc)
	{
		case HSE :
		/************************there are 2 options of HSE --> RCC or crystal*******************/
		switch(copy_tHSESrc_t)
		{
			case HSE_CRYSTAL:
			/********************1- Enable HSE BY RCC_CR register----bit 16**********************/
			SET_BIT(RCC_CR, 16U);
			while(GET_BIT(RCC_CR, 17U) == 0);
			/**********************Beause we use crystal, we need to Disable PYPASS**************/
			CLR_BIT(RCC_CR, 18U);
			/******************************Input system clock***********************************/
			SET_BIT(RCC_CFGR, 0U);
			CLR_BIT(RCC_CFGR, 1U);
			break;
			/************************************************************************************/
			case HSE_RC:
			/*******************1- Enable HSE BY RCC_CR register----bit 16***********************/
			SET_BIT(RCC_CR, 16U);
			while(GET_BIT(RCC_CR, 17U) == 0);
			/*******************Beause we use RC, we need to Enaable PYPASS**********************/
			SET_BIT(RCC_CR, 18U);
			/*Input system clock*/
			SET_BIT(RCC_CFGR, 0U);
			CLR_BIT(RCC_CFGR, 1U);
			break;
			/*************************************************************************************/
			default:   break;
		}
			break;
		/*****************************************************************************************/
		case HSI :
		/*************************1- Enable HSI BY RCC_CR register----bit 0**********************/
		SET_BIT(RCC_CR, 0U);
		while(GET_BIT(RCC_CR, 1U) == 0);
		/*********************We don't have a RC, we don't need to enable PYPASS*****************/
		/******************************Input system clock***************************************/
		CLR_BIT(RCC_CFGR, 0U);
		CLR_BIT(RCC_CFGR, 1U);
		break;
		/**************************************************************************************/
		case PLL :
		/**************************THere are 2 options, feed from HSE or HSI ******************/
		switch(copy_tPLLSrc_t)
		{
			case HSE_pll:
			/*********************1- Enable HSE BY RCC_CR register----bit 16******************/
			SET_BIT(RCC_CR, 16U);
			while(GET_BIT(RCC_CR, 17U) == 0);
			/****************************2- Enable PLL by RCC_CR register*********************/
			SET_BIT(RCC_CR, 24U);
			while(GET_BIT(RCC_CR, 25U) == 0);
			/*******************************SHE clock will choose to enter********************/
			SET_BIT(RCC_PLLCFGR, 22U);
			/************************************Input system clock***************************/
			CLR_BIT(RCC_CFGR, 0U);
			SET_BIT(RCC_CFGR, 1U);
			break;
			/*********************************************************************************/
			case HSI_pll:
			/********************1- Enable HSI BY RCC_CR register----bit 0********************/
			SET_BIT(RCC_CR, 0U);
			while(GET_BIT(RCC_CR, 1U) == 0);
			/**********************2- Enable PLL by RCC_CR register***************************/
			SET_BIT(RCC_CR, 24U);
			/**************************SHI clock will choose to enter*************************/
			CLR_BIT(RCC_PLLCFGR, 22U);
			/*******************************Input system clock********************************/
			CLR_BIT(RCC_CFGR, 0U);
			SET_BIT(RCC_CFGR, 1U);
			break;
		}
		break;
	}
}













