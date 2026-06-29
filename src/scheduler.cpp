#include "scheduler.hpp"
#include "timer.hpp"

void scheduler::tick() const
{
    timer.tick();
}

void scheduler::stop()
{
    stopped = true;
    timer.set_div();
}

void scheduler::wake()
{
    stopped = false;
}
