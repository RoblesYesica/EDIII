/*
* Parpadea un led.
* Descripcion : Este programa prende y apaga un LED conectado al pin P0.22(PUERTO 0 - PIN 22)
*de forma intermitente.
*P0.22 13:12 PINSEL1
*/


#include "LPC17xx.h"


void delay(uint32_t tiempo){
	uint32_t j;

		for(j=0;j<tiempo;j++){}
}



int main(void) {

   SystemInit(); //Configuracion del clock y PLL
   LPC_PINCON->PINSEL1&=~(0b11<<12);//Configura el pin P0.22 como GPIO
   LPC_GPIO0->FIODIR|=(1<<22);//Configura el pin P0.22 como salida 1Salida
  // LPC_GPIO0->FIODIR2|=(1<<6);//accedo a la misma posicion de memoria
  // LPC_GPIO0->FIODIRH|=(1<<6);


   while(1) {
	   LPC_GPIO0->FIOCLR |=(1<<22);//apago el LED |saco un 0 |FIOCLR/SET se activan con 1
	   delay(6000000);
	   LPC_GPIO0->FIOSET |=(1<<22);//enciendo el LED |saco un 1
	   delay(6000000);
    }
    return 0 ;
}



