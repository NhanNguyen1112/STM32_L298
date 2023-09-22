
#include "main.h"

int main(void)
{
  InitClockHSE();
  Init_TIM2_CH1_Delay();
  Init_TIM3_PWM_CH3_PB0();

  Enable_Disable_Clock_PortA(Enable);
  Enable_Disable_Clock_PortB(Enable);

  SetPinOutput(PORTB,PIN0,Alternate_PushPull); /* EN A */
  SetPinOutput(PORTB,PIN1,Alternate_PushPull); /* EN B */
  SetPinOutput(PORTA,PIN4, PushPull); /* IN1 */
  SetPinOutput(PORTA,PIN5, PushPull); /* IN2 */

  L298_Init(PORTA, 0, 0, PIN4, PIN5, 0, 0);

  while (1)
  {
    L298_Motor_A(CW,10);
  }
  
}

