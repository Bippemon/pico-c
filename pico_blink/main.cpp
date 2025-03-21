#include "pico/stdlib.h"

int main(){
	//init LED on gpio pin 17
	const uint LED = 17;
	gpio_init(LED);
	gpio_set_dir(LED, GPIO_OUT);

	gpio_put(LED, 1);

	return 0;
}
