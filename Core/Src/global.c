/*
 * global.c
 *
 *  Created on: Nov 12, 2024
 *      Author: baobu
 */

#include "global.h"

void blink_red(){
	HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
}
void blink_yellow(){
	HAL_GPIO_TogglePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin);
}
void blink_green(){
	HAL_GPIO_TogglePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin);
}
