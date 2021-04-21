#define RCGCGPIO *((unsigned int *) 0x400FE608U)
#define GPIODATA *((unsigned int *) 0x400253FCU)
#define GPIODIR  *((unsigned int *) 0x40025400U)
#define GPIODEN  *((unsigned int *) 0x4002551CU)
/* 
    GPIO Run Mode Clock Gating Control (RCGCGPIO)
    GPIO Direction                     (GPIODIR)
    GPIO Digital Enable                (GPIODEN)
    
     

*/
void delay(int lim){
  int count = 0;
  while( count < lim){
    count++;
  }
}
int main()
{
   RCGCGPIO = 0x20U;
   GPIODIR  = 0x0EU;
   GPIODEN  = 0x0EU;
   
   unsigned int color_arr[] = { 0x02U, 0x04U, 0x06U, 0x08U, 0x0AU, 0x0CU, 0x0EU};

  int i = 0; 
  while(1){
  
    /*
    GPIODATA = 0x08U;
    delay(10000000);
     
    GPIODATA = 0x0eU;
    delay(10000000);
    */
    i = i % 7;
    GPIODATA = color_arr[i];
    delay(1500000);
    i++;
      
  }
  return 0;
  
  /* clock gate */
  /* GPIO Direction (GPIODIR) set to out offset 0x0400*/
  /* GPIO Digital Enable (GPIODEN) offset 0x051C*/
}
