
#include "./memory_map.h"

u_int8_t& MemoryMap::operator[](u_int16_t index) {
  if (inRange_u16(index, 0x0000, 0x8000)) { // 32kB Cartridge
    ERROR("TODO: Cartridge Memory");
    exit(-1);
  } else if (inRange_u16(index, 0x8000, 0xA000)) { // 8kB Virtual RAM
    return display.virt_ram[index - 0x8000];
  } else if (inRange_u16(index, 0xA000, 0xC000)) { // 8kB Switchable RAM Bank
    ERROR("TODO: Cartridge Switchable RAM Bank");
    exit(-1);
  } else if (inRange_u16(index, 0xC000, 0xE000)) { // 8kB Internal RAM
    return internal_ram0[index - 0xC000];
  } else if (inRange_u16(index, 0xE000, 0xFE00)) { // Echo of 8kB Internal RAM
    return internal_ram0[index - 0xE000];
  } else if (inRange_u16(index, 0xFE00, 0xFEA0)) { // 0xA0 Object-Attribute Memory
    return display.oam[index - 0xFE00];
  } else if (inRange_u16(index, 0xFEA0, 0xFF00)) { // Empty but unsable for I/O
    ERROR("TODO: Unusable I/O Area");
    exit(-1);
  } else if (inRange_u16(index, 0xFF00, 0xFF4C)) { // I/O Ports
    ERROR("TODO: I/O Area");
    exit(-1);
  } else if (inRange_u16(index, 0xFF4C, 0xFF80)) { // Empty but unusable for I/O
    ERROR("TODO: Unusable I/O Area");
    exit(-1);
  } else if (inRange_u16(index, 0xFF80, 0xFFFF)) { // More Internal RAM
    return internal_ram1[index - 0xFF80];
  } else if (index == 0xFFFF) {
    return interrupt_enable_register;
  } else {
    ERROR("Memory index out of bounds");
    exit(-1);
  }
}