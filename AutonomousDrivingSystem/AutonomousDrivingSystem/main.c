//Import built in libraries


#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <string.h>
#include <stdlib.h>


//Import MCAL HCAL Layers


#include "Dio.h"
#include "ATmega32_Cfg.h"
#include "Ext_Interrupts.h"
#include "uart.h"
#include "IRSpeed.h"
#include "Adc.h"
#include "IR_Distance_Sensor.h"
#include "Pwm.h"
#include "TB6600Stepper.h"
// variables definition
volatile	 uint8 Str[20]="echo test";
volatile uint8 UART_Counter = 0;
uint8 Motor_speed=0;
char Angle[10];
char Speed[10];
char distance[10];

int main(void)
{
	
	
		


	uint64 TIMER1=0;
TIMER1=Timer0_Count();

	
	Dio_ChannelDirectionSet(PORTC_DIR_REG,DIO_PIN7,DIO_OUTPUT);//Testing led
	Dio_ChannelDirectionSet(PORTA_DIR_REG,DIO_PIN0,DIO_INPUT);//Angle sensor
		Dio_ChannelDirectionSet(PORTD_DIR_REG,DIO_PIN5,DIO_OUTPUT);//PWM Pin
		
		
		//Modules initialization
		
		
UART_init(9600);
TB6600STEPPER_Init();
Angle_sensor_init();
IRDISTANECE_Init();
	IR_Speed_Init();
	Pwm_Init(&gStrPwm_Configuration[PWM_CHANNEL_1]);
Pwm_SetDutyCycle(PWM_CHANNEL_1, 0);
TB6600STEPPER_Rotate(25);

	while(1)
	{
		
		IR_Speed_Read();
		//Stop the car if an obstacle is detected
		if (IRDISTANCE_ValueGet()<30)
		{
					
			
			Dio_ChannelWrite(PORTC_OUT_REG,DIO_PIN7,DIO_HIGH);
			Pwm_SetDutyCycle(PWM_CHANNEL_1,100U);

			}else{
			Dio_ChannelWrite(PORTC_OUT_REG,DIO_PIN7,DIO_LOW);

		}
					//Send data every 500 milliseconds
				if(Timer0_Count()>=TIMER1+12){
itoa(Angle_sensor_get_value(), Angle, 10);
UART_SendString("A:");
UART_SendString(Angle);

itoa(IR_Speed_Read(), Speed, 10);
UART_SendString("S:");
UART_SendString(Speed);

itoa(IRDISTANCE_ValueGet(), distance, 10);
UART_SendString("D:");
UART_SendString(distance);
UART_SendString("\n");
					TIMER1=Timer0_Count();


					
				}
					
		

	
		
	}
	}
	//Receive Interrupt
ISR (USART_RXC_vect)
{
	
		Str[UART_Counter]=UDR;
		UART_Counter=UART_Counter+1;
if (UART_Counter>=2)
{
	UART_Counter=0;
	
	if(Str[0]=='A'){
TB6600STEPPER_Rotate(Str[1]);
	}else if (Str[0]=='M')
	{
		Pwm_SetDutyCycle(PWM_CHANNEL_1,100- Str[1]);

	}
}
}