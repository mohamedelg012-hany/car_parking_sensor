/*
 * buzzer.h
 *
 *  Created on: May 16, 2025
 *      Author: mohamed elgendy
 */

#ifndef BUZZER_H_
#define BUZZER_H_

#include "std_types.h"

#define BUZZER_PORT_ID  PORTC_ID
#define BUZZER_PIN_ID   PIN5_ID



void Buzzer_init(void);

void Buzzer_on(void);

void Buzzer_off(void);



#endif /* BUZZER_H_ */

