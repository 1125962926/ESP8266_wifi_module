#ifndef __OLED_H
#define __OLED_H		


#include "sys.h"
#include "stdlib.h"
#include "string.h" 	 
#include "delay.h"


//--------------OLED参数定义---------------------
//#define PAGE_SIZE			8
//#define XLevelL				0x00
//#define XLevelH				0x10
//#define YLevel				0xB0
//#define	Brightness		    0xFF 
//#define WIDTH				128
//#define HEIGHT				64	


//-------------写命令和数据定义-------------------
#define OLED_CMD			0		//写命令
#define OLED_DATA			1		//写数据 


//-----------------OLED端口定义----------------
#define OLED_SCK_PIN		GPIO_PIN_3							//时钟信号
#define OLED_SCK_PORT		GPIOA										
#define OLED_SCK_CLK_ENABLE()      do{ __HAL_RCC_GPIOA_CLK_ENABLE(); }while(0)

#define OLED_MOSI_PIN		GPIO_PIN_4							//数据发送信号
#define OLED_MOSI_PORT	    GPIOA										
#define OLED_MOSI_CLK_ENABLE()      do{ __HAL_RCC_GPIOA_CLK_ENABLE(); }while(0)

#define OLED_RES_PIN		GPIO_PIN_5							//复位信号
#define OLED_RES_PORT		GPIOA										
#define OLED_RES_CLK_ENABLE()      do{ __HAL_RCC_GPIOA_CLK_ENABLE(); }while(0)

#define OLED_DC_PIN			GPIO_PIN_6							//数据/命令控制信号
#define OLED_DC_PORT		GPIOA										
#define OLED_DC_CLK_ENABLE()      do{ __HAL_RCC_GPIOA_CLK_ENABLE(); }while(0)	



//-----------------OLED端口操作定义----------------

#define OLED_RST_PIN_Set(x) do{x ? HAL_GPIO_WritePin(OLED_RES_PORT,OLED_RES_PIN,GPIO_PIN_SET) : \
                            HAL_GPIO_WritePin(OLED_RES_PORT,OLED_RES_PIN,GPIO_PIN_RESET); } while(0)

#define OLED_DC_PIN_Set(x) do{x ? HAL_GPIO_WritePin(OLED_DC_PORT,OLED_DC_PIN,GPIO_PIN_SET) : \
                            HAL_GPIO_WritePin(OLED_DC_PORT,OLED_DC_PIN,GPIO_PIN_RESET); } while(0)

#define OLED_SCK_PIN_SET(x) do{x ? HAL_GPIO_WritePin(OLED_SCK_PORT,OLED_SCK_PIN,GPIO_PIN_SET) : \
                            HAL_GPIO_WritePin(OLED_SCK_PORT,OLED_SCK_PIN,GPIO_PIN_RESET); } while(0)

#define OLED_MOSI_PIN_SET(x) do{x ? HAL_GPIO_WritePin(OLED_MOSI_PORT,OLED_MOSI_PIN,GPIO_PIN_SET) : \
                            HAL_GPIO_WritePin(OLED_MOSI_PORT,OLED_MOSI_PIN,GPIO_PIN_RESET) ; } while(0)


void OLED_WR_Byte(uint8_t dat,uint8_t cmd);	    
void OLED_Display_On(void);
void OLED_Display_Off(void);
void OLED_Refresh_Gram(void);  		    
void OLED_Init(void);
void OLED_Clear(void);
void OLED_DrawPoint(uint8_t x,uint8_t y,uint8_t t);
void OLED_Fill(uint8_t x1,uint8_t y1,uint8_t x2,uint8_t y2,uint8_t dot);
void OLED_ShowChar(uint8_t x,uint8_t y,uint8_t chr,uint8_t size,uint8_t mode);
void OLED_ShowNum(uint8_t x,uint8_t y,uint32_t num,uint8_t len,uint8_t size);
void OLED_ShowString(uint8_t x,uint8_t y,const uint8_t *p,uint8_t size);
void OLED_Chinese_Text(uint8_t x,uint8_t y,uint8_t chr,uint8_t size,uint8_t mode); 																								//英文天气界面显示测试
void OLED_Init_GPIO(void);

#endif


