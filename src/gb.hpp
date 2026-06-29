#pragma once

#include "scheduler.hpp"
#include "cpu.hpp"
#include "mmu.hpp"
#include "timer.hpp"
#include "interrupts.hpp"

class gb {
public:
    void run(long long cycles = -1);

private:
    interrupts interrupts{};
    timer timer{interrupts};
    mmu mmu{scheduler, timer, interrupts};
    cpu cpu{scheduler, mmu, interrupts};
    scheduler scheduler{timer};
};
