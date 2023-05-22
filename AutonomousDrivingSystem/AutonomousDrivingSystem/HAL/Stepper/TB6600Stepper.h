/*
 * TB6600Stepper.h
 *
 * Created: 5/19/2023 6:31:59 PM
 *  Author: Josep
 */ 


#ifndef TB6600STEPPER_H_
#define TB6600STEPPER_H_
#include "ATmega32_Cfg.h"
#include "Dio.h"
#define stepperDir PORTC_DIR_REG
#define  stepperOut PORTC_OUT_REG
#define stepPin DIO_PIN0
#define dirPin DIO_PIN1
#define  enPin DIO_PIN2

void TB6600STEPPER_Init();
void TB6600STEPPER_Rotate(uint8 angle_of_rotation);

#endif /* TB6600STEPPER_H_ */