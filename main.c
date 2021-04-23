#define RCGCGPIO *((unsigned int *) 0x400FE608U)
#define GPIODATA *((unsigned int *) 0x400253FCU)
#define GPIODIR  *((unsigned int *) 0x40025400U)
#define GPIODEN  *((unsigned int *) 0x4002551CU)
#define RED             0x02U
#define BLUE            0x04U
#define PURPLE          0x06U    
#define GREEN           0x08U
#define YELLOW          0x0AU
#define LIGHTBLUE       0x0CU
#define WHITE           0x0EU

void delay(int lim){
  int volatile count = 0;
  while( count < lim){
    count++;
  }
}


int main()
{
  /*  GPIO Run Mode Clock Gating Control (RCGCGPIO) 
      set register to 0x20U to enable GPIO Port F in Run mode (pg 340) */
   RCGCGPIO = 0x20U;
   
  /*  GPIO Direction                     (GPIODIR)  
      set register to 0x0EU to configure pins 1,2,3 as an output (pg 663)*/
   GPIODIR  = 0x0EU;
   
  /*  GPIO Digital Enable                (GPIODEN)  
      set register to 0x0EU to configure pins 1,2,3 to eneable (pg 682)*/
   
   GPIODEN  = 0x0EU;
   
   unsigned int color_arr[] = { RED, BLUE, PURPLE, GREEN, YELLOW, LIGHTBLUE, WHITE};

  int i = 0; 
  
  while(1){
  
    i = i % 7;
    GPIODATA = color_arr[i];
    delay(1500000);
    i++;
      
  }
  
  return 0;
  
}
