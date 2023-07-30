
#include <cstdlib>

class Registers {
  public:
    u_int8_t a = 0;
    u_int8_t b = 0;
    u_int8_t c = 0;
    u_int8_t d = 0;
    u_int8_t e = 0;
    u_int8_t f = 0;
    u_int8_t h = 0;
    u_int8_t l = 0;

    u_int16_t sp = 0xFFFE;
    u_int16_t pc = 0x0100;

    u_int16_t af() {
      return (a << 8) | f;
    }

    u_int16_t bc() {
      return (b << 8) | c;
    }

    u_int16_t de() {
      return (d << 8) | e;
    }

    u_int16_t hl() {
      return (h << 8) | l;
    }

    void set_af(u_int16_t val) {
      a = static_cast<u_int8_t>((val & 0xFF00) >> 8);
      f = static_cast<u_int8_t>(val & 0x00FF);
    }

    void set_bc(u_int16_t val) {
      b = static_cast<u_int8_t>((val & 0xFF00) >> 8);
      c = static_cast<u_int8_t>(val & 0x00FF);
    }

    void set_de(u_int16_t val) {
      d = static_cast<u_int8_t>((val & 0xFF00) >> 8);
      e = static_cast<u_int8_t>(val & 0x00FF);
    }

    void set_hl(u_int16_t val) {
      h = static_cast<u_int8_t>((val & 0xFF00) >> 8);
      l = static_cast<u_int8_t>(val & 0x00FF);
    }

};