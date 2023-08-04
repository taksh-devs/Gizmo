
#include <glad/glad.h>

#include "../logger.h"
#include "../common.h"
#include "./window_events.h"

void processWindowResize(GLFWwindow* window, int width, int height) {
  INFO("Window resized");
  gizmoState->size.x = width;
  gizmoState->size.y = height;
  glViewport(0, 0, width, height);
}