#include "stm32f10x.h"    
#include "bit.h"
#include "delay.h"
#include "Timer.h" 
#include "Usart.h"	 
#include "misc.h"
#include "ads1256.h"

u8 command_success =0;//usart

//PA9  -----> Tx
//PA10 -----> Rx

//***************************   	 
//			STM32	 	 ADS1256
//		GPIOB_Pin_11 --- DRDY
//		GPIOB_Pin_12 --- CS
//		GPIOB_Pin_13 --- SCK
//		GPIOB_Pin_14 --- DOUT
//		GPIOB_Pin_15 --- DIN
//		         3.3 --- RST_N
//***************************		

int main(void)
{
		u8 i=0;
	  int Adc;
	  float Volts;
	
	  u16 len;//usart
    char *sp = NULL;//usart

	
	  SystemInit();
    Delay_Init(72);
	  uart1_init(115200);//usart
	  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //设置NVIC中断分组2:2位抢占优先级，2位响应优先级
	 // TIM3_Int_Init(10000-1,7200-1);  

	  GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable , ENABLE);//使能SWJ，禁止JTAG

	  delay_us(300);

	  ADS1256_Init();

//			while(1)
//	{	
//i=0;
//Adc = ADS1256ReadData( (i << 3) | ADS1256_MUXN_AINCOM);
//Volts = Adc*0.000000598;
//printf(" %x\n  ",Adc);
//printf(" %.4fV  ",Volts);

//		
////		for(i = 0;i < 8;i++)
////		{

////			Adc = ADS1256ReadData( (i << 4) | ADS1256_MUXN_AINCOM);// 相当于 ( ADS1256_MUXP_AIN0 | ADS1256_MUXN_AINCOM);		

////			 /*差分采集方式*/
////	    //Adc = ADS1256ReadData( ADS1256_MUXP_AIN0|ADS1256_MUXN_AIN1); //P = AIN0 ,N = AIN1 差分方式*/
////			Volts = Adc*0.000000598;
////			
////			
////			printf(" %.4fV  ",Volts);

////		}
////		printf("\r\n"); 
//	  delay_ms(1000);
//	}



	

}


