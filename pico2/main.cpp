#include "pico/stdlib.h"
#include <stdio.h>

int main(){
	const uint LED_PIN = 16;
	const uint BUTTON_PIN = 17;

	gpio_init(LED_PIN);
	gpio_set_dir(LED_PIN, GPIO_OUT);

	gpio_init(BUTTON_PIN);
	gpio_set_dir(BUTTON_PIN, GPIO_IN);
	gpio_pull_up(BUTTON_PIN);

	//default value off
	bool led_on = 0;

	gpio_put(LED_PIN, led_on);

	//start value
	bool lastPressed = 0;

	while (true){
		bool isPressed = !gpio_get(BUTTON_PIN);

		if (isPressed && !lastPressed){
			led_on = !led_on;
			gpio_put(LED_PIN, led_on);
		}

		lastPressed = isPressed;
		sleep_ms(50);
	}
}
