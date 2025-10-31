#pragma once

class ISensor {
public:
    virtual bool init() = 0;
    virtual float readVelocity() = 0;
    virtual ~ISensor() {}
};
