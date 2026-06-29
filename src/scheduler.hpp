#pragma once

#include "types.hpp"

class timer;

class scheduler {
public:
    explicit scheduler(timer& t)
        : timer{t}
    {}

    bool stopped{false};

    void tick() const;

    void stop();

    void wake();

private:
    timer& timer;
    u32 cycle{};
};
