/*
 * IRSpeed.h
 *
 * Created: 4/14/2023 3:58:42 PM
 *  Author: Josep
 */ 


#ifndef IRSPEED_H_
#define IRSPEED_H_
#include "GPT.h"
#include "gptConfig.h"
uint8 STEP=0;
uint64 TIMER=0;
uint8 value=0;
ISR(INT0_vect)
{
	_delay_ms(20);

	STEP=STEP+1;
_delay_ms(20);

	
}
void IR_Speed_Init(){
	Global_Interrupts_StateSet(GLOBAL_INT_ENABLE);
	Ext_Interrupts_Enable(EXT_INT0, EXT_INT_RISING_EDGE);
	Dio_ChannelDirectionSet(PORTD_DIR_REG,DIO_PIN2,DIO_INPUT);
		Timer0_Init(&config);
	TIMER=Timer0_Count();

}

uint8 IR_Speed_Read(){
	if(Timer0_Count()>=TIMER+75){
		TIMER=Timer0_Count();
		
			value=STEP;
			STEP=0;
			return value/2;
		
}
else{
			return value/2;
	
}
}


#endif /* IRSPEED_H_ */