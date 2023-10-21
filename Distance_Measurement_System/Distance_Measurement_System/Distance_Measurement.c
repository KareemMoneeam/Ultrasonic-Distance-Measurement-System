/******************************************************************************
 *
 * File Name: Distance_Measurement.c
 *
 * Description: source file for the Application "Distance Measurement System"
 *
 * Author: Kareem Abd El-Moneam
 *
 *******************************************************************************/
#include "std_types.h"
#include "ultrasonic.h"
#include "lcd.h"
#include "gpio.h"
#include "avr/io.h"

int main(void)
{
	/* Variable to save the output distance */
	uint16 distance = 0;

	/* Enable Global Interrupt I-Bit */
	SREG |= (1<<7);

	/* Initialize the LCD Driver */
	LCD_init();

	/* Initialize the ultrasonic driver using ICU driver */
	Ultrasonic_init();

	LCD_displayString("Distance= ");

	/* Displaying the ultrasonic outputs on the LCD*/
	while(1)
	{
		/* Read the calculated distance value using ultrasonic */
		distance = Ultrasonic_readDistance();

		/* Display distance on LCD */
		LCD_moveCursor(0,10);
		LCD_intgerToString(distance);
		LCD_displayString(" cm");

		/* To override the additional digit shown after decrementing distance */
		if (distance < 100) {
			LCD_displayCharacter(' ');
		}
	}
}

