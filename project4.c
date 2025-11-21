
/*
 * ultrasonic.h
 *
 *  Created on: Jun 26, 2025
 *      Author: mobilap
 */
#include "lcd.h"
#include "buzzer.h"
#include "ultrasonic.h"
#include "gpio.h"
#include <util/delay.h>
#include "led.h"
#include <avr/io.h>

#define DISTANCE_ALERT 5
#define DISTANCE_ALL_LEDS 10
#define DISTANCE_GREEN_RED 15
#define DISTANCE_RED 20

void LED_control(uint16 distance) {
    if (distance <= DISTANCE_ALERT) {
        LED_toggle(BLUE_LED);
        LED_toggle(GREEN_LED);
        LED_toggle(RED_LED);
        Buzzer_on();
    }
    else if (distance <= DISTANCE_ALL_LEDS) {
        LED_on(BLUE_LED);
        LED_on(GREEN_LED);
        LED_on(RED_LED);
        Buzzer_off();
    }
    else if (distance <= DISTANCE_GREEN_RED) {
        LED_off(BLUE_LED);
        LED_on(GREEN_LED);
        LED_on(RED_LED);
        Buzzer_off();
    }
    else if (distance <= DISTANCE_RED) {
        LED_off(BLUE_LED);
        LED_off(GREEN_LED);
        LED_on(RED_LED);
        Buzzer_off();
    } else {
        LED_off(BLUE_LED);
        LED_off(GREEN_LED);
        LED_off(RED_LED);
        Buzzer_off();
    }
}

int main(void) {

    // Initialize the system components
    LCD_init();
    Ultrasonic_init();
    Buzzer_init();
    LEDS_init();
    SREG |= (1<<7); // Enable global interrupts

    uint16 distance = 0;
    LCD_displayString("Distance=  CM");

    while (1) {
        // Read distance from ultrasonic sensor
        distance = Ultrasonic_readDistance();
        LCD_moveCursor(0, 9);

        // Display the distance on the LCD
        if (distance >= 10) {
            LCD_intgerToString(distance);
        } else {
            LCD_intgerToString(distance);
            LCD_displayCharacter(' '); // Clear trailing digits
        }

        // Control the LEDs and buzzer based on distance
        LED_control(distance);

        // Display "STOP!" when distance is too close
        if (distance <= DISTANCE_ALERT) {

            LCD_displayStringRowColumn(1, 5, "STOP!");


        } else {
            LCD_displayStringRowColumn(1, 5, "     "); // Clear message
        }

        _delay_ms(200); // Small delay to stabilize sensor readings
    }
}
