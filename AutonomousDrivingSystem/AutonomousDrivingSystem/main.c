#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <string.h>
#include <stdlib.h>
#include "Dio.h"
#include "ATmega32_Cfg.h"
#include "Ext_Interrupts.h"
#include "uart.h"
#include "IRSpeed.h"
#include "Adc.h"
#include "IR_Distance_Sensor.h"
#include "Pwm.h"
#include "TB6600Stepper.h"
volatile	 uint8 Str[20]="echo test";
volatile uint8 k = 0;
volatile uint8 uart_flag = 0;
uint8 Motor_speed=0;
int main(void)
{
	UART_init(9600);
	char Angle[10];
		char Speed[10];
		char distance[10];
		


	uint64 TIMER1=0;
TIMER1=Timer0_Count();

	
	Dio_ChannelDirectionSet(PORTC_DIR_REG,DIO_PIN7,DIO_OUTPUT);
		Dio_ChannelDirectionSet(PORTB_DIR_REG,DIO_PIN0,DIO_INPUT);
	Dio_ChannelDirectionSet(PORTA_DIR_REG,DIO_PIN0,DIO_INPUT);
		Dio_ChannelDirectionSet(PORTD_DIR_REG,DIO_PIN5,DIO_OUTPUT);
				Dio_ChannelDirectionSet(PORTD_DIR_REG,DIO_PIN6,DIO_OUTPUT);

TB6600STEPPER_Init();
Pot_Init();
IRDISTANECE_Init();
	IR_Speed_Init();
	Pwm_Init(&gStrPwm_Configuration[PWM_CHANNEL_1]);
Pwm_SetDutyCycle(PWM_CHANNEL_1, 0);
TB6600STEPPER_Rotate(25);

	while(1)
	{
		
		IR_Speed_Read();
		if (IRDISTANCE_ValueGet()<30)
		{
					if (IRDISTANCE_ValueGet()<30)
					{
			
			Dio_ChannelWrite(PORTC_OUT_REG,DIO_PIN7,DIO_HIGH);
			Pwm_SetDutyCycle(PWM_CHANNEL_1,100U);

			}else{
			Dio_ChannelWrite(PORTC_OUT_REG,DIO_PIN7,DIO_LOW);

		}
					}
				if(Timer0_Count()>=TIMER1+12){
itoa(Pot_ValueGet(), Angle, 10);
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

/*
itoa(k, C, 10);
UART_SendString(C);

UART_SendString("\n");
UART_SendString(Str);*/

					
				}
					
		if (Dio_ChannelRead(PORTB_INP_REG,DIO_PIN0))
		{
			
		}

	
		
	}
	}
ISR (USART_RXC_vect)
{
	
		Str[k]=UDR;
		k=k+1;
if (k>=2)
{
	k=0;
	
	if(Str[0]=='A'){
TB6600STEPPER_Rotate(Str[1]);
	}else if (Str[0]=='M')
	{
		Pwm_SetDutyCycle(PWM_CHANNEL_1,100- Str[1]);

	}
}
}