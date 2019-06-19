#include <18F4620.h>
#fuses HS, NOFCMEN, NOIESO, PUT, NOBROWNOUT, NOWDT
#fuses NOPBADEN, NOMCLR, STVREN, NOLVP, NODEBUG
#use delay(clock=16000000)
int conteo = 1;

#define __DEBUG_SERIAL__ //Si comentas esta linea se deshabilita el debug por serial y el PIN_C6 puede ser usado en forma digital I/O

#ifdef __DEBUG_SERIAL__
   #define TX_232        PIN_C6
   #use RS232(BAUD=9600, XMIT=TX_232, BITS=8,PARITY=N, STOP=1)
   #use fast_io(c)
#endif

void main (void){
   set_tris_c(0x00);
   set_tris_b(0x00);
   set_tris_d(0x00);
   setup_oscillator(OSC_16MHZ);
#ifdef __DEBUG_SERIAL__ //Deberiamos de proteger nuestras depuraciones de esta forma o usar una macro ya protegida.
   printf("Hola Mundo\n");//Puedes usar putc o printf. Revisa la documentación de CCS para ver que mas puedes hacer.
#endif
   while(1){

   if(conteo==1)
   {
   output_b(0x03);
   delay_ms(200);
   output_b(0x30);
   delay_ms(200);
   set_tris_b(0xff);
   conteo=2;
   }
   else if(conteo==2)
   {
   output_c(0x03);
   delay_ms(200);
   output_c(0x30);
   delay_ms(200);
   set_tris_c(0xff);
   conteo=3;
   }
   else if (conteo==3)
   {
   output_d(0x03);
   delay_ms(200);
   output_d(0x30);
   delay_ms(200);
   set_tris_d(0xff);
   }
   
   



   
   
   
   
      
   }
}   
