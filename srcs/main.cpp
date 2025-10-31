#include "../include/VelocityMonitor.hpp"

int main() {

	SpeedSensor_I2C sensor(0x68);  // example I2C address
	if (!sensor.init()) {
		std::cerr << "Failed to initialize sensor\n";
		return 1;
	}

	VelocityMonitor monitor(sensor);
	monitor.run();
	return 0;
}