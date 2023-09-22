
#include "L298.h"

static char L298_PORT=0;
static char PIN_EN_A=0;
static char PIN_EN_B=0;
static char PIN_IN1=0;
static char PIN_IN2=0;
static char PIN_IN3=0;
static char PIN_IN4=0;

/* 
  @ brief: L298 init
  @ Details: PWM use TIM3: CH3-PB0, CH4-PB1
  @ param[in]:
    _PORT: A, B, C, D, E, F, G
    _ENA: Input PWM
    _ENB: Input PWM
    _IN1, IN2, IN3, IN4: Pin control CW, CCW
  @ return: void
*/
void L298_Init(char PORT, const char ENA, const char ENB,
              const char IN1, const char IN2, const char IN3, const char IN4)
{
  L298_PORT=PORT;
  PIN_EN_A = ENA;
  PIN_EN_B = ENB;
  PIN_IN1 = IN1; 
  PIN_IN2 = IN2; 
  PIN_IN3 = IN3; 
  PIN_IN4 = IN4;   
}

static void L298_SET_OUT(char PORT, const unsigned char PIN1, const unsigned char PIN2, 
                        DigitalState_enum STATE1, DigitalState_enum STATE2)
{
  switch (PORT)
  {
    case PORTA:
      WritePin(PORTA,PIN1,STATE1);
      WritePin(PORTA,PIN2,STATE2);
      break;
    case PORTB:
      WritePin(PORTB,PIN1,STATE1);
      WritePin(PORTB,PIN2,STATE2);
      break;
    case PORTC:
      WritePin(PORTC,PIN1,STATE1);
      WritePin(PORTC,PIN2,STATE2);
      break;    
    case PORTD:
      WritePin(PORTD,PIN1,STATE1);
      WritePin(PORTD,PIN2,STATE2);
      break;  
    case PORTE:
      WritePin(PORTE,PIN1,STATE1);
      WritePin(PORTE,PIN2,STATE2);
      break;  
    case PORTF:
      WritePin(PORTF,PIN1,STATE1);
      WritePin(PORTF,PIN2,STATE2);
      break;  
    case PORTG:
      WritePin(PORTG,PIN1,STATE1);
      WritePin(PORTG,PIN2,STATE2);
      break;                            
  }
}

/* 
  @ brief: L298 control motor A with Max power
  @ Details: 
  @ param[in]: Direction is CW or CCW
  @ return: void
*/
void L298_Motor_A_MAX(const char Direction)
{
  if(Direction == CW) /* THUAN */
  {
    L298_SET_OUT(L298_PORT, PIN_IN1, PIN_IN2, LOW, HIGH);
  }
  else /* NGHICH */
  {
    L298_SET_OUT(L298_PORT, PIN_IN1, PIN_IN2, HIGH, LOW);
  }
}

/* 
  @ brief: L298 control motor B with Max power
  @ Details: 
  @ param[in]: Direction is CW or CCW
  @ return: void
*/
void L298_Motor_B_MAX(const char Direction)
{
  if(Direction == CW) /* THUAN */
  {
    L298_SET_OUT(L298_PORT, PIN_IN3, PIN_IN4, LOW, HIGH);
  }
  else /* NGHICH */
  {
    L298_SET_OUT(L298_PORT, PIN_IN3, PIN_IN4, HIGH, LOW);
  }
}

/* 
  @ brief: L298 control motor A use PWM
  @ Details: if PULSE>100 then do nothing
  @ param[in]: 
    - Direction is CW or CCW
    - PULSE: 0-100 %
  @ return: void
*/
void L298_Motor_A(const char Direction, const unsigned int PULSE)
{
  if(Direction == CW) /* THUAN */
  {
    L298_SET_OUT(L298_PORT, PIN_IN1, PIN_IN2, LOW, HIGH);
  }
  else /* NGHICH */
  {
    L298_SET_OUT(L298_PORT, PIN_IN1, PIN_IN2, HIGH, LOW);
  }

  if(PULSE<=100)TIM3_CH3_PWM_OUTPUT(PULSE);
}

/* 
  @ brief: L298 control motor B use PWM
  @ Details: if PULSE>100 then do nothing
  @ param[in]: 
    - Direction is CW or CCW
    - PULSE: 0-100 %
  @ return: void
*/
void L298_Motor_B(const char Direction, const unsigned int PULSE)
{
  if(Direction == CW) /* THUAN */
  {
    L298_SET_OUT(L298_PORT, PIN_IN3, PIN_IN4, LOW, HIGH);
  }
  else /* NGHICH */
  {
    L298_SET_OUT(L298_PORT, PIN_IN3, PIN_IN4, HIGH, LOW);
  }
  
  if(PULSE<=100)TIM3_CH3_PWM_OUTPUT(PULSE);
}

/* 
  @ brief: L298 STOP MOTOR
  @ Details: 
  @ param[in]: MOTOR is MOTOR_A, MOTOR_B, ALL_MOTOR
  @ return: void
*/
void L298_STOP(STOPMOTOR_enum MOTOR)
{
  switch (MOTOR)
  {
    case MOTOR_A:
      L298_SET_OUT(L298_PORT, PIN_IN1, PIN_IN2, LOW, LOW);
      break;
    case MOTOR_B:
      L298_SET_OUT(L298_PORT, PIN_IN3, PIN_IN4, LOW, LOW);
      break; 
    case ALL_MOTOR:
      L298_SET_OUT(L298_PORT, PIN_IN1, PIN_IN2, LOW, LOW);
      L298_SET_OUT(L298_PORT, PIN_IN3, PIN_IN4, LOW, LOW);
      break;        
  }
}



