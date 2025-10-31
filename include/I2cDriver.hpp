#pragma once

#include <linux/i2c-dev.h> 
#include <cstdint>
#include <unistd.h>

class I2CDriver {

public:
	I2CDriver();

	bool openBus(const char *bus);
	bool writeBytes(uint8_t addr, const uint8_t *data, size_t len);
	bool readBytes(uint8_t addr, uint8_t *data, size_t len);
	void closeBus();

private:
	int	_fd;

};

//bool openBus(const char *bus = "/dev/i2c-1");