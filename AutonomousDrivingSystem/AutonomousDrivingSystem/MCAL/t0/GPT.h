<<<<<<< HEAD
/*
 * GPT.h
 *
 * Created: 10/22/2022 2:21:46 PM
 *  Author: Joseph
 */ 


#ifndef GPT_H_
#define GPT_H_
#include "Std_Types.h"
#include "gptConfig.h"
typedef enum {
	normal,
	CTC,
	FastPWM,
	PhaseCorrect
}operationMode;

typedef enum {
	noClockSource,
	NoPreScaling,
	Eight_PreScaling,
	PreScaling_64,
	PreScaling_256,
	PreScaling_1024,
	Ext_Clock_Source_Falling_Edge,
	Ext_Clock_Source_Rising_Edge
}PreScaller;
typedef struct
{
	PreScaller	Prescale;
	operationMode mode;

}Timer_Config;



void Timer0_Init(const Timer_Config *config);
uint64 Timer0_Count();
extern const Timer_Config config;
=======
/*
 * GPT.h
 *
 * Created: 10/22/2022 2:21:46 PM
 *  Author: Joseph
 */ 


#ifndef GPT_H_
#define GPT_H_
#include "Std_Types.h"
#include "gptConfig.h"
typedef enum {
	normal,
	CTC,
	FastPWM,
	PhaseCorrect
}operationMode;

typedef enum {
	noClockSource,
	NoPreScaling,
	Eight_PreScaling,
	PreScaling_64,
	PreScaling_256,
	PreScaling_1024,
	Ext_Clock_Source_Falling_Edge,
	Ext_Clock_Source_Rising_Edge
}PreScaller;
typedef struct
{
	PreScaller	Prescale;
	operationMode mode;

}Timer_Config;



void Timer0_Init(const Timer_Config *config);
uint64 Timer0_Count();
extern const Timer_Config config;
>>>>>>> c3da444850ce6e33419849b101803a462f1c92d3
#endif /* GPT_H_ */