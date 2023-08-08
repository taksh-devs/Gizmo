
#include "./virt_ram.h"

u_int8_t& VirtRAM::operator[](int index) {
  if (index >= VIRT_RAM_LENGTH) {
    ERROR("Virtual RAM index out of bounds");
    exit(-1);
  }

  return byts[index];
}