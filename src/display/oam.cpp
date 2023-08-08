
#include "./oam.h"

u_int8_t& OAM::operator[](int index) {
  if (index >= OAM_LENGTH) {
    ERROR("Object-Attribute Memory index out of bounds");
    exit(-1);
  }

  return byts[index];
}