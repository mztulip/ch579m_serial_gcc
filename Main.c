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

void Default_Handler(void)
{
	while(1)
	{
		
		mDelaymS(100);
		GPIOB_SetBits( GPIO_Pin_0 ); 
		mDelaymS(100);
		GPIOB_ResetBits( GPIO_Pin_0 );
	}
}


// https://www.embecosm.com/appnotes/ean9/ean9-howto-newlib-1.0.html#id2719973
int
_write (int   file,
        char *buf,
        int   nbytes)
{
  int i;

  /* Output character at at time */
  for (i = 0; i < nbytes; i++)
    {
      UART1_SendString (&buf[i], 1);
    }
        
  return nbytes;

} 

void *
_sbrk (int nbytes)
{
  static uint8_t heap[512];
  static uint16_t last = 0;
  if(last+nbytes < 512)
  {
    void* pointer = &heap[last];
    last+=nbytes;
    return pointer;
  }
  else
  {
    return  (void *) -1;
  }
}

#include <errno.h>

#undef errno
extern int  errno;

int
_close (int   file)
{
  errno = EBADF;
  
  return -1;                    /* Always fails */
}

int
_lseek (int   file,
        int   offset,
        int   whence)
{
  return  0;

} 

int
_read (int   file,
       char *ptr,
       int   len)
{
  return  0;                            /* EOF */

} 

#include <sys/stat.h>

int
_fstat (int          file,
        struct stat *st)
{
  st->st_mode = S_IFCHR;
  return  0;

}

int
_isatty (int   file)
{
  return  1;

}  