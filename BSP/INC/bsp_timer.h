/*
*********************************************************************************************************
* @file    	bsp.h
* @author  	SY
* @version 	V1.0.0
* @date    	2016-10-11 15:10:28
* @IDE	 	Keil V5.18.0.0
* @Chip    	STM32F407VE
* @brief   	板级开发驱动包头文件
*********************************************************************************************************
* @attention
*
* 
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                              				Define to prevent recursive inclusion
*********************************************************************************************************
*/
#ifndef __BSP_TIMER_H
#define __BSP_TIMER_H

/*
*********************************************************************************************************
*                              				Exported Includes
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                              				Exported define
*********************************************************************************************************
*/
/*
	在此定义若干个软件定时器全局变量
	注意，必须增加__IO 即 volatile，因为这个变量在中断和主程序中同时被访问，有可能造成编译器错误优化。
*/
#define TMR_COUNT							10			/* 软件定时器的个数 （定时器ID范围 0 - 3) */
#define	TMR_COUNT_US						10			//软件计时器，用于计算事件耗时，计时器ID范围0-3	

/*
*********************************************************************************************************
*                              				Exported types
*********************************************************************************************************
*/
/* 定时器结构体，成员变量必须是 volatile, 否则C编译器优化时可能有问题 */
typedef enum
{
	TMR_ONCE_MODE = 0,		/* 一次工作模式 */
	TMR_AUTO_MODE = 1		/* 自动定时工作模式 */
}TMR_MODE_E;

/* 定时器结构体，成员变量必须是 volatile, 否则C编译器优化时可能有问题 */
typedef struct
{
	volatile uint8_t Mode;		/* 计数器模式，1次性 */
	volatile uint8_t Flag;		/* 定时到达标志  */
	volatile uint32_t Count;	/* 计数器 */
	volatile uint32_t PreLoad;	/* 计数器预装值 */
}SOFT_TMR;

 
/* uS级计时器结构体，成员变量必须是 volatile, 否则C编译器优化时可能有问题 */
typedef struct
{
	volatile uint32_t startRunTime;	/* 计数器 */
	volatile uint32_t startTick;	/* 计数器预装值 */
}SOFT_TMR_US;

typedef enum {
	ID_TIM_BSP_IO = 0,
	ID_TIM_MAIN_CYCLE,
}USER_TIM_ID_TypeDef;

/*
*********************************************************************************************************
*                              				Exported constants
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                              				Exported macro
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                              				Exported variables
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                              				Exported functions
*********************************************************************************************************
*/
void bsp_InitTimer(void);
void bsp_DelayMS(uint32_t n);
void bsp_DelayUS(uint32_t n);
void bsp_StartTimer(uint8_t _id, uint32_t _period);
void bsp_StartAutoTimer(uint8_t _id, uint32_t _period);
void bsp_StopTimer(uint8_t _id);
uint8_t bsp_CheckTimer(uint8_t _id);
uint32_t bsp_GetRunTime(void);

void bsp_StartTimeUS(uint8_t _id);
uint32_t bsp_GetTimeUS(uint8_t _id);

#endif
/************************ (C) COPYRIGHT STMicroelectronics **********END OF FILE*************************/
