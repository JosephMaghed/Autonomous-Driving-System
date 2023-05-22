<<<<<<< HEAD
/*
 * TB6600Stepper.c
 *
 * Created: 5/19/2023 6:32:28 PM
 *  Author: Josep
 */ 
#include "TB6600Stepper.h"
#include <util/delay.h>
#define  F_CPU 16000000U
void TB6600STEPPER_Init(){
=======
/*
 * TB6600Stepper.c
 *
 * Created: 5/19/2023 6:32:28 PM
 *  Author: Josep
 */ 
#include "TB6600Stepper.h"
#include <util/delay.h>
#define  F_CPU 16000000U
void TB6600STEPPER_Init(){
>>>>>>> c3da444850ce6e33419849b101803a462f1c92d3
	Dio_ChannelDirectionSet(stepperDir,stepPin,DIO_OUTPUT);
	Dio_ChannelDirectionSet(stepperDir,dirPin,DIO_OUTPUT);
	Dio_ChannelDirectionSet(stepperDir,enPin,DIO_OUTPUT);

<<<<<<< HEAD
	Dio_ChannelWrite(stepperOut,enPin,DIO_LOW);
}


void TB6600STEPPER_Rotate(uint8 angle_of_rotation){
	int i=0,j=0;
=======
	Dio_ChannelWrite(stepperOut,enPin,DIO_LOW);
}


void TB6600STEPPER_Rotate(uint8 angle_of_rotation){
	int i=0,j=0;
>>>>>>> c3da444850ce6e33419849b101803a462f1c92d3
	while (i<=angle_of_rotation*45&&i<=200*45)
	{
		Dio_ChannelWrite(stepperOut,stepPin,DIO_HIGH);
		_delay_us(500);
		Dio_ChannelWrite(stepperOut,stepPin,DIO_LOW);
		_delay_us(500);


		i=i+1;
	}

	
	while (j<1)
	{
		Dio_ChannelWrite(stepperOut,stepPin,DIO_HIGH);
		_delay_us(500);
		Dio_ChannelWrite(stepperOut,stepPin,DIO_LOW);
		_delay_us(500);


		j=j+1;
<<<<<<< HEAD
	}
=======
	}
>>>>>>> c3da444850ce6e33419849b101803a462f1c92d3
}