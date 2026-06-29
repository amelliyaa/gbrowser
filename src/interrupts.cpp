#include "interrupts.hpp"
#include <bit>

void interrupts::req(const u8 source)
{
    flag |= (1 << source);
}

u8 interrupts::pending() const
{
    return flag & enable;
}

u16 interrupts::consume()
{
    const u8 queued{pending()};

    if (queued == 0) [[unlikely]] {
        return 0x0000;
    }

    const int flag_bit{std::countr_zero(queued)};

    flag &= ~(1 << flag_bit);

    return handler[flag_bit];
}
