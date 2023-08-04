
#ifndef COMMON_H
#define COMMON_H

#include "utils.h"
#include "cpu.h"
#include "memory_map/memory_map.h"

class State {
  public:
    std::string title = "Gizmo - GameBoy Emulator";
    Vector2D size = Vector2D(800, 600);
    CPU cpu;
    MemoryMap memMap;

    State() {}
};

extern State* gizmoState;

#endif