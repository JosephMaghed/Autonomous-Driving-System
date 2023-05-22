/*
 * GPT.c
 *
 * Created: 10/22/2022 2:21:23 PM
 *  Author: Josep
 */ 
#include "gptConfig.h"
#include "Std_Types.h"
#include "Macros.h"
#include <avr/io.h>

void Timer0_Init(const Timer_Config *config){
	TCNT0=0;
	switch(config->mode){
		case normal:
			CLEAR_BIT(TCCR0,WGM00);
			CLEAR_BIT(TCCR0,WGM01);
			break;
			case PhaseCorrect:
			SET_BIT(TCCR0,WGM00);
			CLEAR_BIT(TCCR0,WGM01);
			break;
			case CTC:
			SET_BIT(TCCR0,WGM01);
			CLEAR_BIT(TCCR0,WGM00);
			break;
			case FastPWM:
			SET_BIT(TCCR0,WGM00);
			SET_BIT(TCCR0,WGM01);
			break;}
			switch(config->Prescale){
				case NoPreScaling:
				SET_BIT(TCCR0,CS00);
				CLEAR_BIT(TCCR0,CS01);
				CLEAR_BIT(TCCR0,CS02);
				break;
				case Eight_PreScaling:
				CLEAR_BIT(TCCR0,CS02);
                SET_BIT(TCCR0,CS01);
				CLEAR_BIT(TCCR0,CS00);
				break;
				
				case PreScaling_64:
				CLEAR_BIT(TCCR0,CS02);
				SET_BIT(TCCR0,CS01);
				SET_BIT(TCCR0,CS00);
				break;
				
				case PreScaling_256:
				SET_BIT(TCCR0,CS02);
				CLEAR_BIT(TCCR0,CS01);
				CLEAR_BIT(TCCR0,CS00);
				break;
				case PreScaling_1024:
				SET_BIT(TCCR0,CS02);
				CLEAR_BIT(TCCR0,CS01);
				SET_BIT(TCCR0,CS00);
				break;
	
						}
			}
			static uint64 timer=0;
uint64 Timer0_Count(){
	
	if (TCNT0>=255)
	{
		TCNT0=193;
		
		timer++;
	}
	
	return timer;
}
		