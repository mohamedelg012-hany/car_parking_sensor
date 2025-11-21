
/*
 * ultrasonic.c
 *
 *  Created on: Jun 26, 2025
 *      Author: mohamed elgendy
 */
#include "ultrasonic.h"
#include <util/delay.h>




static volatile uint16 g_pulse_time = 0;




void Ultrasonic_init(void)
{
	ICU_ConfigType ICU_Configurations = {F_CPU_8, RAISING};

	ICU_init(&ICU_Configurations);
	ICU_setCallBack(Ultrasonic_edgeProcessing);
	GPIO_setupPinDirection(TRIGGER_PORT_ID, TRIGGER_PIN_ID, PIN_OUTPUT);
}

void Ultrasonic_Trigger(void)
{
	GPIO_writePin(TRIGGER_PORT_ID, TRIGGER_PIN_ID, LOGIC_HIGH);
	_delay_us(10);
	GPIO_writePin(TRIGGER_PORT_ID, TRIGGER_PIN_ID, LOGIC_LOW);
}

uint16 Ultrasonic_readDistance(void)
{
	  uint16 distance = 0;
	  Ultrasonic_Trigger();
      while (g_pulse_time == 0);
       distance = (g_pulse_time / 117.6)+1;
       g_pulse_time = 0;
        return distance;

}

void Ultrasonic_edgeProcessing(void)
{
	static uint8 edge_count = 0;

	if(edge_count == 0)
	{
		ICU_clearTimerValue();
		ICU_setEdgeDetectionType(FALLING);
		edge_count = 1;
	}
	else
	{
		g_pulse_time = ICU_getInputCaptureValue();
		ICU_setEdgeDetectionType(RAISING);
		edge_count = 0;
	}
}

