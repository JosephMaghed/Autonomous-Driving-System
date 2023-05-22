<<<<<<< HEAD
/*
 * IR_Distance_Sensor.h
 *
 * Created: 4/20/2023 7:00:07 PM
 *  Author: Josep
 */ 


#ifndef IR_DISTANCE_SENSOR_H_
#define IR_DISTANCE_SENSOR_H_


#include "Adc.h"

#define TEMP_SENSOR_PIN                (ADC_CHANNEL_0)

#define ADC_TEN_BIT_PRECISION          (1024U)
#define ADC_EIGHT_BIT_PRECISION        (256U)
#define ADC_5_VOLT_REF                 (5.0)
#define ADC_3_3V_VOLT_REF              (3.3)

void IRDISTANECE_Init(void);
uint8 IRDISTANCE_ValueGet(void);


=======
/*
 * IR_Distance_Sensor.h
 *
 * Created: 4/20/2023 7:00:07 PM
 *  Author: Josep
 */ 


#ifndef IR_DISTANCE_SENSOR_H_
#define IR_DISTANCE_SENSOR_H_


#include "Adc.h"

#define TEMP_SENSOR_PIN                (ADC_CHANNEL_0)

#define ADC_TEN_BIT_PRECISION          (1024U)
#define ADC_EIGHT_BIT_PRECISION        (256U)
#define ADC_5_VOLT_REF                 (5.0)
#define ADC_3_3V_VOLT_REF              (3.3)

void IRDISTANECE_Init(void);
uint8 IRDISTANCE_ValueGet(void);


>>>>>>> c3da444850ce6e33419849b101803a462f1c92d3
#endif /* IR_DISTANCE_SENSOR_H_ */