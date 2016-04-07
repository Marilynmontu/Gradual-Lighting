 #include "delay.h"
 #include "stdio.h"
 #include "stdlib.h"
 #include "key.h"
 #include "led.h" 
 #include "sys.h"
 #include "usart.h"

 void calculator(int i,int j,int k,char *a)
{
	if(a[i]=='+') printf("%d\n",j+k);
	else if(a[i]=='-') printf("%d\n",j-k);
	else if(a[i]=='*') printf("%d\n",j*k);
	else if(a[i]=='/') {
	if(k==0) printf("error!")
	else printf("%d\n",j/k);
	}
	else printf("error operator!");
	
}
void converse(char*x)
{
	int k;
	char n1[5],n2[5];
	int num1,num2;
	int i,j;
	for(i=0;x[i]>='0'&&x[i]<='9';i++)
	{
            n1[i]=x[i]; 
	}
	j=i;
	n1[i]='\0';
	num1=atoi(n1);
	k=i+1;
	while(x[k]!='\0')
	{
	if(x[k]!=' '){
	for(i=0;x[k]>='0'&&x[k]<='9';i++,k++)
	{
	 n2[i]=x[k];
	}
	n2[i]='\0';
	num2=atoi(n2);
	calculator(j,num1,num2,x);
      }
	else k++;
}
}			
 int main(void)
 {		
 	u8 t;
	u8 len;	
	u16 times=0;
	delay_init();	    	  
	NVIC_Configuration(); 	 
	uart_init(9600);
  
	 
 	while(1)
	{
		if(USART_RX_STA&0x8000)
		{	
			
			char x[200];				   
			len=USART_RX_STA&0x3fff;
			USART_RX_STA=0;
			USART_RX_BUF[len] = '\0';
			printf("\r\nPlease write your code!\r\n\r\n");
			for(t=0;t<=len;t++)
			{
				x[t]=USART_RX_BUF[t];
				if(USART_RX_BUF[t]=='\0') 
				{converse(x);}	
			}
			
		}

	}
}
