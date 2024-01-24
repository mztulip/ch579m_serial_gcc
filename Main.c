//Author mztulip
//mateusz@tulip.lol

#include "CH57x_common.h"
#include <stdio.h>


void write_serial(char *str)
{
  uint8_t i = 0;
  const uint8_t limit = 100;
  while(str[i]!=0 && i < limit)
  {
    UART1_SendString(&str[i],1);
    i++;
  }
}

int main()
{       
	SystemInit();
	
	/* PB0-LED */
	GPIOB_ModeCfg(GPIO_Pin_0, GPIO_ModeOut_PP_20mA);
	GPIOA_ModeCfg(GPIO_Pin_8, GPIO_ModeIN_PU);
  GPIOA_ModeCfg(GPIO_Pin_9, GPIO_ModeOut_PP_5mA);


  UART1_DefInit();
  UART1_BaudRateCfg(9600);

  write_serial("\n\rHello");
  printf("\n\rHello from printf");

	while(1)
	{
		
		mDelaymS(500);
		GPIOB_SetBits( GPIO_Pin_0 ); 
		mDelaymS(500);
		UART1_SendString("*",1);
		GPIOB_ResetBits( GPIO_Pin_0 );
	}
}

void general_Handler(void)
{

}
