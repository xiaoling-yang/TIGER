#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "lcd.h"
#include "usmart.h"
#include "adc.h"

//ALIENTEK 探索者STM32F407开发板 实验13
//LCD显示实验-库函数版本
//技术支持：www.openedv.com
//淘宝店铺：http://eboard.taobao.com  
//广州市星翼电子科技有限公司  
//作者：正点原子 @ALIENTEK

int main(void)
{ 

	
	unsigned int adcx,T;
 	u16 K;
	u8 lcd_id[12];				//存放LCD ID字符串
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//设置系统中断优先级分组2
	delay_init(168);      //初始化延时函数
	uart_init(115200);		//初始化串口波特率为115200
	usmart_dev.init(168);//SystemCoreClock/1000000
	LED_Init();					  //初始化LED
 	LCD_Init();           //初始化LCD FSMC接口
	Adc_Init();
	POINT_COLOR=BLACK;      //画笔颜色：红色
	sprintf((char*)lcd_id,"LCD ID:%04X",lcddev.id);//将LCD ID打印到lcd_id数组�
		LCD_ShowString(30,130,200,24,24,"ADC_CH5_VOTL:");			 	
	LCD_ShowString(30,226,300,24,24,"ADC_CH5_Lsensor:00");
	while(1) 
	{		 
		
		adcx=Get_Adc_Average(ADC_Channel_5,10);
		if(adcx>4000)
	T=100;
		else
		{
		T=(4096-adcx)/40;
		
		}
		
	
	  
		
		LCD_ShowxNum(30+14*12,130, adcx,4,24,0);
		LCD_ShowxNum(30+16*12,226, T,4,24,0);

//		Tempt=Tempt*100;
//		
//		LCD_ShowxNum(30+21*12,226,K/100,2,24,0);
//		LCD_ShowxNum(30+24*12,226,K%100,2,24,0);
//		LCD_ShowxNum(30+14*12,300,K,4,24,0);
		delay_ms(200);
		
		
		
		
		
		
			
		}
	  

	} 

