/*
 * Potentiometer.c
 *
 * Created: 10/7/2021 10:40:54 PM
 *  Author: Abdelaziz Moustafa
 */ 

#include "Potentiometer.h"

<<<<<<< HEAD
void Angle_sensor_init(void)
=======
void Pot_Init(void)
>>>>>>> c3da444850ce6e33419849b101803a462f1c92d3
{
	Adc_Init(&gStrAdc_Configuration);
}

<<<<<<< HEAD
uint16 Angle_sensor_get_value(void)
=======
uint16 Pot_ValueGet(void)
>>>>>>> c3da444850ce6e33419849b101803a462f1c92d3
{
	Adc_ValueType u16LocalAdcReading = 0U;
	Adc_StartGroupConversion(ADC_GROUP_0);
	Adc_ReadChannel(POT_PIN, gStrAdc_Configuration.Resolution, &u16LocalAdcReading);
	return u16LocalAdcReading;
}