/*
 * Potentiometer.h
 *
 * Created: 10/7/2021 10:40:25 PM
 *  Author: Abdelaziz Moustafa
 */ 


#ifndef POTENTIOMETER_H_
#define POTENTIOMETER_H_

#include "Adc.h"

#define POT_PIN                        (ADC_CHANNEL_1)

<<<<<<< HEAD
void Angle_sensor_init(void);
uint16 Angle_sensor_get_value(void);
=======
void Pot_Init(void);
uint16 Pot_ValueGet(void);
>>>>>>> c3da444850ce6e33419849b101803a462f1c92d3

#endif /* POTENTIOMETER_H_ */