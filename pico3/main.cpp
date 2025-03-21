#include "pico/stdlib.h"

const uint P1 = 14;
const uint P2 = 15;
const uint P3 = 16;
const uint P4 = 17;
const uint BUTTON = 18;

int main(){

	gpio_init(P1);
	gpio_init(P2);
	gpio_init(P3);
	gpio_init(P4);
	gpio_init(BUTTON);

	gpio_set_dir(P1, GPIO_OUT);
	gpio_set_dir(P2, GPIO_OUT);
	gpio_set_dir(P3, GPIO_OUT);
	gpio_set_dir(P4, GPIO_OUT);
	gpio_set_dir(BUTTON, GPIO_IN);

	gpio_pull_up(BUTTON);

	bool lastPressed = false;
	int num = P1, lastNum = P1-1;

	while (true) {
		bool isPressed = !gpio_get(BUTTON);

		if (isPressed && !lastPressed) {
			gpio_put(lastNum, 0);
			gpio_put(num, 1);

			num++;
			lastNum++;
		}

		if (num > 17) {
			num = 14;
		}
		if (lastNum > 17) {
			lastNum = 14;
		}

		lastPressed = isPressed;
		sleep_ms(50);
}

	return 0;
}

