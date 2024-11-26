/*
 * Scheduler.h
 *
 *  Created on: Nov 12, 2024
 *      Author: baobu
 */

#ifndef INC_SCHEDULER_H_
#define INC_SCHEDULER_H_

#include "main.h"

typedef struct{
	void (*pTask) (void);
	uint32_t Delay;
	uint32_t Period;
	uint8_t RunMe;
	uint32_t TaskID;

} sTask;

#define SCH_MAX_TASKS 40
#define NO_TASK_ID 0


void SCH_init(void);
void SCH_update(void);
uint32_t SCH_Add_Task(void (*pFunction)(),uint32_t DELAY, uint32_t PERIOD);
void SCH_Dispatch_Tasks(void);
uint8_t SCH_Delete_Task(uint32_t TASKID);



#endif /* INC_SCHEDULER_H_ */
