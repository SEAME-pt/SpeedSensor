#include <stdio.h>
#include <pigpio.h>
#include <iostream>

volatile int pulses = 0;

void pulse_callback(int gpio, int level, uint32_t tick) {
    if(level == 0) // FALLING edge
        pulses++;
}

int main() {
    if (gpioInitialise() < 0) {
        std::cerr << "ERROR! Failed inicialization of pigpio. Aborting...\n" << std::endl;
        return (1);
    }

    int PIN = 24; // GPI24 = pino físico 24
    gpioSetMode(PIN, PI_INPUT);
    gpioSetPullUpDown(PIN, PI_PUD_UP);

    gpioSetAlertFunc(PIN, pulse_callback);

    const int pulses_per_revolution = 20;
    while(1) {
        pulses = 0;
        gpioDelay(5000000); // 5 segundos
        double rpm = (pulses / 5.0) * 60.0 / pulses_per_revolution;
        printf("Pulsos=%d, RPM≈%.1f\n", pulses, rpm);
    }

    gpioTerminate();
    return 0;
}