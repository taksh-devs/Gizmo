
#ifndef VIRT_RAM_H
#define VIRT_RAM_H

#include <cstdlib>
#include "../logger.h"

const u_int64_t VIRT_RAM_LENGTH = 8 * 1024; // 8kB Virtual RAM

class VirtRAM {
  private:
    u_int8_t byts[VIRT_RAM_LENGTH] = { 0 };
  public:
    u_int8_t& operator[](int index) {
      if (index >= VIRT_RAM_LENGTH) {
        ERROR("Virtual RAM index out of bounds")
        exit(-1)
      }

      return byts[index];
    }
};

#endif