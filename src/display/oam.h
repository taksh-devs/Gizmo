
#ifndef OAM_H
#define OAM_H

#include <cstdlib>
#include "../logger.h"

const u_int64_t OAM_LENGTH = 0xA0; // Object-Attribute Memory Length

class OAM {
  private:
    u_int8_t byts[OAM_LENGTH] = { 0 };
  public:
    u_int8_t& operator[](int index);
};

#endif