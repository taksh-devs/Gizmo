
#include "utils.h"

bool inRange_u16(u_int16_t val, u_int16_t low, u_int16_t high) {
  return (val >= low) && (val < high);
}