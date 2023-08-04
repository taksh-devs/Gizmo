
#ifndef DISPLAY_H
#define DISPLAY_H

#include "./oam.h"
#include "./virt_ram.h"

class Display {
  public:
    OAM oam;
    VirtRAM virt_ram;
};

#endif