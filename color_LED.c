 #include "delay.h"
 #include "sys.h"
 #include "usart.h"
 #include "gpio.h"
 void light_r(int n)
 {
	 if(n>0)
	 {
	  GPIO_SetBits(GPIOD,GPIO_Pin_1);
		delay_us(10);
		GPIO_ResetBits(GPIOD,GPIO_Pin_1);
	}
	 else 
	 {
    GPIO_ResetBits(GPIOD,GPIO_Pin_1);
		delay_us(10);
	 }
}
 void light_g(int n)
 {
	if(n>0)
	{
   	GPIO_SetBits(GPIOD,GPIO_Pin_3);
		delay_us(10);
		GPIO_ResetBits(GPIOD,GPIO_Pin_3);
	}
	else 
	{
	  GPIO_ResetBits(GPIOD,GPIO_Pin_3);
		delay_us(10);
	}
}
 void light_b(int n)
 {
	 if(n>0)
	{
		 GPIO_SetBits(GPIOD,GPIO_Pin_4);
		 delay_us(10);
		 GPIO_ResetBits(GPIOD,GPIO_Pin_4);
  }
	 else 
	 {
	    delay_us(10);
		  GPIO_ResetBits(GPIOD,GPIO_Pin_4);
	 } 
}
void light(int r,int g,int b)
{
	int time;
	for(time=1;time<=255;time++)
	{ 
		light_r(r);r--;
		light_g(g);g--;
		light_b(b);b--;
  }
}
 int main(void)
 {		
	u16 times=0;
	int red=0;
	int green=0;
	int blue=0;
  delay_init();   	  
	NVIC_Configuration(); 	 
	uart_init(9600);
  GP_Init();

  while(1)
	{	
		
		red=255;blue=0;
		for(green=0;green<=255;green++) light(red,green,blue); green=255;
		for(red=255;red>=0;red--) light(red,green,blue); red=0;	
		for(blue=0;blue<=255;blue++) light(red,green,blue); blue=255;
	  for(green=255;green>=0;green--) light(red,green,blue); green=0;
    for(red=0;red<=255;red++) light(red,green,blue); red=255;
		for(blue=255;blue>=0;blue--) light(red,green,blue);
	}	
}
