<<<<<<< HEAD
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
=======
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
>>>>>>> c3da444850ce6e33419849b101803a462f1c92d3
#define stepperDir PORTC_DIR_REG
#define  stepperOut PORTC_OUT_REG
#define stepPin DIO_PIN0
#define dirPin DIO_PIN1
<<<<<<< HEAD
#define  enPin DIO_PIN2

void TB6600STEPPER_Init();
void TB6600STEPPER_Rotate(uint8 angle_of_rotation);

=======
#define  enPin DIO_PIN2

void TB6600STEPPER_Init();
void TB6600STEPPER_Rotate(uint8 angle_of_rotation);

>>>>>>> c3da444850ce6e33419849b101803a462f1c92d3
#endif /* TB6600STEPPER_H_ */