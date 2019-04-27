
#include "stm32f10x_it.h"
#include "stm32f10x_tim.h"
#include "Timer.h" 
#include "misc.h"
#include "bit.h"

/*
通用定时器3中断初始化
arr：自动重装载值
psc：时钟预分频系数
*/
void TIM3_Int_Init(u16 arr,u16 psc)//定时公式：T=(arr+1)*(psc+1)/72M
{
    TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
    NVIC_InitTypeDef NVIC_InitStructure;

    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE); //时钟使能


    TIM_TimeBaseStructure.TIM_Period = arr; //自动重装载值
    TIM_TimeBaseStructure.TIM_Prescaler =psc; //时钟预分频系数
    TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; 
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  
    TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure); 

    TIM_ITConfig(TIM3,TIM_IT_Update,ENABLE ); 

    //中断优先级NVIC设置
    NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;  //TIM3中断
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;  
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;  
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure); 


    TIM_Cmd(TIM3, ENABLE);  //使能TIMx                     
}

//定时器3中断函数
void TIM3_IRQHandler(void)   
{
    if (TIM_GetITStatus(TIM3, TIM_IT_Update) != RESET)  
    {
//    TIM_ClearITPendingBit(TIM3, TIM_IT_Update  );  
//		PCOUT(13)=!	PCOUT(13);
    }
}
