/*
*
*
*Configuro el pin P2.10 como entrada digital
*Configuro el pin P0.22 como salida digital
*Voy a configurar el tiempo de blikeo
*
*
*/

#include "LPC17xx.h"
void configGpio(void);
void delay(uint32_t);
int main(void) {
	uint32_t tiempo;
    SystemInit();
    LPC_PINCON->PINMODE4|=(0b11<<20);//Asocia resistencia pull-down al pin P2.10
    while(1) {
     if((LPC_GPIO2->FIOPIN)&(1<<10)){
    	 tiempo=1000000;
     }else{
    	 tiempo=4000000;
     }
     LPC_GPIO0->FIOCLR|=(1<<22);//apago el led
     delay(tiempo);
     LPC_GPIO0->FIOSET|=(1<<22);//enciendo el led
     delay(tiempo);
    }
    return 0 ;
}

void configGpio(void){
	LPC_PINCON->PINSEL4&=~(0b11<<20);//Configura el pin P2.10 como GPIO
    LPC_PINCON->PINSEL1|=(0b11<<12);//Configura el pin P0.22 como GPIO
    LPC_GPIO2->FIODIR&=~(1<<10);//Configura el pin P2.10 como entrada digital
    LPC_GPIO0->FIODIR|=(1<<22);//Configura el pin P0.22 como salida digital

}
void delay(uint32_t tiempo){
	for (int cont=0;cont<tiempo;cont++){}
}
