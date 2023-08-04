
#include "../logger.h"
#include "./input_events.h"

void processInput(GLFWwindow* window) {
  if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
    INFO("Exiting Gizmo");
    glfwSetWindowShouldClose(window, true);
  }
}