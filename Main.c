//Author mztulip
//mateusz@tulip.lol

#include "CH57x_common.h"

int main()
{       
	SystemInit();
	
	/* PB0-LED */
	GPIOB_ModeCfg( GPIO_Pin_0, GPIO_ModeOut_PP_20mA );
	while(1)
	{
		
		mDelaymS(100);
		GPIOB_SetBits( GPIO_Pin_0 ); 
		mDelaymS(100);
		GPIOB_ResetBits( GPIO_Pin_0 );
	}
}

void Default_Handler(void)
{
	while(1);
}
