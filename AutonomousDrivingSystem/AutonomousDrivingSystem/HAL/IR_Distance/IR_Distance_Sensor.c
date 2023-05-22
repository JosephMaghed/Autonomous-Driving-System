/*
 * IR_Distance_Sensor.c
 *
 * Created: 4/20/2023 7:00:45 PM
 *  Author: Josep
 */ 

#include "IR_Distance_Sensor.h"
#include <math.h>
void IRDISTANECE_Init(void)
{
	Adc_Init(&gStrAdc_Configuration);
}


uint8 IRDISTANCE_ValueGet(void)
{
		Adc_ValueType u16LocalAdcReading = 0U;
		uint8 u8LocalTemp = 0U;
		uint16 u16LocalAdcPrecision = 0U;
	Adc_StartGroupConversion(ADC_GROUP_0);
	Adc_ReadChannel(TEMP_SENSOR_PIN, gStrAdc_Configuration.Resolution, &u16LocalAdcReading);
	switch(gStrAdc_Configuration.Resolution)
	{
		case ADC_TEN_BIT:
		u16LocalAdcPrecision = ADC_TEN_BIT_PRECISION;
		break;
		case ADC_EIGHT_BIT:
		u16LocalAdcPrecision = ADC_EIGHT_BIT_PRECISION;
		break;
		default:
		break;
	}
	/* !Comment: IrDistance Sensor equation */
	u8LocalTemp = (pow(((u16LocalAdcReading * ADC_5_VOLT_REF) / u16LocalAdcPrecision),-1.173)*56.22 ) ;
	
	return (u8LocalTemp);}