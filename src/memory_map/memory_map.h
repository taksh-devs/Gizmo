
#ifndef MEMORY_MAP_H
#define MEMORY_MAP_H

#include <cstdlib>
#include "../utils.h"
#include "../logger.h"
#include "../display/display.h"

const u_int64_t INTERNAL_RAM0 = 8 * 1024; // 8kB Internal RAM
const u_int64_t INTERNAL_RAM1 = 0x7F;     // More Internal RAM

class MemoryMap {
  private:
    Display display;
    u_int8_t internal_ram0[INTERNAL_RAM0] = { 0 };
    u_int8_t internal_ram1[INTERNAL_RAM1] = { 0 };
    u_int8_t interrupt_enable_register = 0;
  public:
    u_int8_t& operator[](u_int16_t index);
};

#endif