
#ifndef UTILS_H
#define UTILS_H

#include <cstdlib>

class Vector2D {
  public:
    double x;
    double y;

    Vector2D(double x_val, double y_val) {
      x = x_val;
      y = y_val;
    }

    Vector2D operator+(Vector2D rhs) {
      return Vector2D(x + rhs.x, y + rhs.y);
    }

    Vector2D operator-(Vector2D rhs) {
      return Vector2D(x - rhs.x, y - rhs.y);
    }

    Vector2D operator*(Vector2D rhs) {
      return Vector2D(x * rhs.x, y * rhs.y);
    }

    Vector2D operator/(Vector2D rhs) {
      return Vector2D(x / rhs.x, y / rhs.y);
    }
};

bool inRange_u16(u_int16_t val, u_int16_t low, u_int16_t high);

#endif