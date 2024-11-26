/*
 * Scheduler.c
 *
 *  Created on: Nov 12, 2024
 *      Author: baobu
 */

#include "Scheduler.h"
#include "global.h"

sTask SCH_Tasks_G[SCH_MAX_TASKS];

void SCH_init(void){
	uint8_t i;
	for( i=0; i< SCH_MAX_TASKS; i++){
		SCH_Delete_Task(i);
	}
}

void SCH_update(void){
	uint8_t Index;
	blink_yellow();
	for ( Index = 0; Index < SCH_MAX_TASKS; Index++) {
		if(SCH_Tasks_G[Index].pTask!=0){
			if(SCH_Tasks_G[Index].Delay==0){

				SCH_Tasks_G[Index].RunMe += 1;
				if(SCH_Tasks_G[Index].Period){
					SCH_Tasks_G[Index].Delay = SCH_Tasks_G[Index].Period;
				}
			}
			else{
				SCH_Tasks_G[Index].Delay -= 1;
			}
		}
	}
}


uint32_t SCH_Add_Task(void (*pFunction)(),uint32_t DELAY, uint32_t PERIOD){
	uint8_t Index=0;

	while((SCH_Tasks_G[Index].pTask != 0) && (Index < SCH_MAX_TASKS)){
		Index++;
	}
	if(Index == SCH_MAX_TASKS){
		return SCH_MAX_TASKS;
	}
	SCH_Tasks_G[Index].pTask = pFunction;
	SCH_Tasks_G[Index].Delay = DELAY;
	SCH_Tasks_G[Index].Period = PERIOD;
	SCH_Tasks_G[Index].RunMe = 0;
	return Index;
}

void SCH_Dispatch_Tasks(void){
	uint8_t Index=0;

	for( Index=0; Index < SCH_MAX_TASKS ; Index++){
		if(SCH_Tasks_G[Index].RunMe > 0){
			(*SCH_Tasks_G[Index].pTask)();
			SCH_Tasks_G[Index].RunMe -= 1;
			if(SCH_Tasks_G[Index].Period == 0)
				SCH_Delete_Task(Index);
		}
	}
}

uint8_t SCH_Delete_Task(uint32_t TASKID){
	uint8_t Return_code;
	if(SCH_Tasks_G[TASKID].pTask == 0){
		Return_code = 1;
	}
	else{
		Return_code = 0;
	}
	SCH_Tasks_G[TASKID].pTask = 0x0000;
	SCH_Tasks_G[TASKID].Delay = 0;
	SCH_Tasks_G[TASKID].Period = 0;
	SCH_Tasks_G[TASKID].RunMe = 0;
	return Return_code;
}


