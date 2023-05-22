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

void Angle_sensor_init(void);
uint16 Angle_sensor_get_value(void);

#endif /* POTENTIOMETER_H_ */