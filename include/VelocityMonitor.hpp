#pragma once

#include <iostream>
#include <fcntl.h>      // for open()
#include <unistd.h>     // for read(), write(), close()
#include <sys/ioctl.h>  // for ioctl()
#include <linux/i2c-dev.h>  // for I2C_SLAVE
#include <cstdint>      // for uint8_t, uint16_t

class VelocityMonitor {

public:
	VelocityMonitor();
	~VelocityMonitor();

	void	run();

};