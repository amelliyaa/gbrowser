#pragma once

#include "types.hpp"

class interrupts {
public:
    enum source : unsigned {
        vblank = 0,
        lcd = 1,
        timer = 2,
        serial = 3,
        joypad = 4,
    };

    u8 flag{0xE1};
    u8 enable{0x00};

    void req(u8 source);

    [[nodiscard]] u8 pending() const;

    [[nodiscard]] u16 consume();

private:
    static constexpr u8 handler[5]{0x40, 0x48, 0x50, 0x58, 0x60};
};
