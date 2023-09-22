
#ifndef __L298__
#define __L298__

#include "main.h"

typedef enum STOPMOTOR 
{
  MOTOR_A,
  MOTOR_B,
  ALL_MOTOR
}STOPMOTOR_enum;

typedef enum Direction
{
  CW,
  CCW
}Direction_enum;

void L298_Init(char PORT, const char ENA, const char ENB,
              const char IN1, const char IN2, const char IN3, const char IN4);

void L298_Motor_A_MAX(const char Direction);
void L298_Motor_B_MAX(const char Direction);
void L298_Motor_A(const char Direction, const unsigned int PULSE);
void L298_Motor_B(const char Direction, const unsigned int PULSE);
void L298_STOP(STOPMOTOR_enum MOTOR);


#endif /*__L298__*/
