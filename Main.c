//Author mztulip
//mateusz@tulip.lol

#include "CH57x_common.h"

int main()
{       
	SystemInit();
	
	/* PB0-LED */
	GPIOB_ModeCfg( GPIO_Pin_0, GPIO_ModeOut_PP_20mA );
	GPIOA_ModeCfg(GPIO_Pin_8, GPIO_ModeIN_PU);
    GPIOA_ModeCfg(GPIO_Pin_9, GPIO_ModeOut_PP_5mA);

    UART1_DefInit();
    UART1_BaudRateCfg(9600);
    UART1_ByteTrigCfg(UART_1BYTE_TRIG);
    UART1_INTCfg(TRUE, RB_IER_RECV_RDY);
    NVIC_EnableIRQ(UART1_IRQn);
    GPIOB_SetBits(GPIO_Pin_0);

    UART1_SendString("a",1);

	while(1)
	{
		
		mDelaymS(1000);
		GPIOB_SetBits( GPIO_Pin_0 ); 
		mDelaymS(1000);
		UART1_SendString("a",1);
		GPIOB_ResetBits( GPIO_Pin_0 );
	}
}

void Default_Handler(void)
{
	while(1);
}
