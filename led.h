/*
 * led.h
 *
 *  Created on: May 16, 2025
 *      Author: mobilap
 */

#ifndef LED_H_
#define LED_H_
#include "std_types.h"

#define RED_LED_PORT_ID                 PORTC_ID
#define RED_LED_PIN_ID                  PIN0_ID
#define RED_LED_LOGIC                   POSITIVE_LOGIC

#define GREEN_LED_PORT_ID               PORTC_ID
#define GREEN_LED_PIN_ID                PIN1_ID
#define GREEN_LED_LOGIC                 POSITIVE_LOGIC

#define BLUE_LED_PORT_ID                PORTC_ID
#define BLUE_LED_PIN_ID                 PIN2_ID
#define BLUE_LED_LOGIC                  POSITIVE_LOGIC
/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/
typedef enum{
	POSITIVE_LOGIC,NEGATIVE_LOGIC
}LED_LogicType;

typedef enum{
	RED_LED,GREEN_LED,BLUE_LED
}LED_ID;

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

/*
 * Description :
 * function responsible for initializing all leds as off no matter the logic
 */
void LEDS_init(void);

/*
 * Description :
 * function responsible for turning on a specified led
 */
void LED_on(LED_ID id);

/*
 * Description :
 * function responsible for turning off a specified led
 */
void LED_off(LED_ID id);
void LED_toggle(LED_ID id);



#endif /* LED_H_ */
