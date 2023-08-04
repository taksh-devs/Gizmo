
#ifndef CPU_H
#define CPU_H

#include "registers.h"
#include "clock.h"

class CPU {
  public:
    Clock clock;
    Registers registers;
};

#endif