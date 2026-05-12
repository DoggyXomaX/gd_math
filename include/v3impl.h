#ifndef V3IMPL_HEADER
#define V3IMPL_HEADER

#include <stdbool.h>

#define v3_header(name, name2, number)                                 \
  typedef union {                                                      \
    struct {                                                           \
      union {                                                          \
        name2 xy;                                                      \
        struct {                                                       \
          number x, y;                                                 \
        };                                                             \
      };                                                               \
      number z;                                                        \
    };                                                                 \
    struct {                                                           \
      number _0;                                                       \
      name2 yz;                                                        \
    };                                                                 \
    struct {                                                           \
      number u, v, w;                                                  \
    };                                                                 \
    struct {                                                           \
      number r, g, b;                                                  \
    };                                                                 \
    struct {                                                           \
      number width, height, length;                                    \
    };                                                                 \
    number raw[3];                                                     \
  } name;                                                              \
  /* Getters */                                                        \
  number name##_slen(name* a);                                         \
  number name##_len(name* a);                                          \
  /* Setters */                                                        \
  void name##_set(name* out, number x, number y, number z);            \
  void name##_copy(name* out, name* a);                                \
  void name##_0(name* out);                                            \
  void name##_1(name* out);                                            \
  /* Factories */                                                      \
  name name##_new(number x, number y, number z);                       \
  name name##_new_0();                                                 \
  name name##_new_1();                                                 \
  name name##_new_right();                                             \
  name name##_new_left();                                              \
  name name##_new_up();                                                \
  name name##_new_down();                                              \
  name name##_new_front();                                             \
  name name##_new_back();                                              \
  /* Operations */                                                     \
  void name##_neg(name* out, name* a);                                 \
  void name##_add(name* out, name* a, name* b);                        \
  void name##_add_n(name* out, name* a, number n);                     \
  void name##_sub(name* out, name* a, name* b);                        \
  void name##_sub_n(name* out, name* a, number n);                     \
  void name##_mul(name* out, name* a, name* b);                        \
  void name##_mul_n(name* out, name* a, number n);                     \
  void name##_div(name* out, name* a, name* b);                        \
  void name##_div_n(name* out, name* a, number n);                     \
  void name##_rotx(name* out, name* a, number angle);                  \
  void name##_roty(name* out, name* a, number angle);                  \
  void name##_rotz(name* out, name* a, number angle);                  \
  void name##_rot(name* out, name* a, name* rot, const char order[3]); \
  bool name##_equal(name* a, name* b);                                 \
  bool name##_equal_e(name* a, name* b, number e);                     \
  void name##_cross(name* out, name* a, name* b);                      \
  number name##_dot(name* a, name* b);

#define v3_source(name, number, sqrtFunc, absFunc, cosFunc, sinFunc)    \
  /* Getters */                                                         \
  number name##_slen(name* a) {                                         \
    return a->x * a->x + a->y * a->y + a->z * a->z;                     \
  }                                                                     \
  number name##_len(name* a) {                                          \
    return sqrtFunc(a->x * a->x + a->y * a->y + a->z * a->z);           \
  }                                                                     \
  /* Setters */                                                         \
  void name##_set(name* out, number x, number y, number z) {            \
    out->x = x;                                                         \
    out->y = y;                                                         \
    out->z = z;                                                         \
  }                                                                     \
  void name##_copy(name* out, name* a) {                                \
    out->x = a->x;                                                      \
    out->y = a->y;                                                      \
    out->z = a->z;                                                      \
  }                                                                     \
  void name##_0(name* out) {                                            \
    out->x = 0;                                                         \
    out->y = 0;                                                         \
    out->z = 0;                                                         \
  }                                                                     \
  void name##_1(name* out) {                                            \
    out->x = 1;                                                         \
    out->y = 1;                                                         \
    out->z = 1;                                                         \
  }                                                                     \
  /* Factories */                                                       \
  name name##_new(number x, number y, number z) {                       \
    return (name){ .x = x, .y = y, .z = z };                            \
  }                                                                     \
  name name##_new_0() {                                                 \
    return name##_new(0, 0, 0);                                         \
  }                                                                     \
  name name##_new_1() {                                                 \
    return name##_new(1, 1, 1);                                         \
  }                                                                     \
  name name##_new_right() {                                             \
    return name##_new(1, 0, 0);                                         \
  }                                                                     \
  name name##_new_left() {                                              \
    return name##_new(-1, 0, 0);                                        \
  }                                                                     \
  name name##_new_up() {                                                \
    return name##_new(0, 1, 0);                                         \
  }                                                                     \
  name name##_new_down() {                                              \
    return name##_new(0, -1, 0);                                        \
  }                                                                     \
  name name##_new_front() {                                             \
    return name##_new(0, 0, 1);                                         \
  }                                                                     \
  name name##_new_back() {                                              \
    return name##_new(0, 0, -1);                                        \
  }                                                                     \
  /* Operations */                                                      \
  void name##_neg(name* out, name* a) {                                 \
    out->x = -a->x;                                                     \
    out->y = -a->y;                                                     \
    out->z = -a->z;                                                     \
  }                                                                     \
  void name##_add(name* out, name* a, name* b) {                        \
    out->x = a->x + b->x;                                               \
    out->y = a->y + b->y;                                               \
    out->z = a->z + b->z;                                               \
  }                                                                     \
  void name##_add_n(name* out, name* a, number n) {                     \
    out->x = a->x + n;                                                  \
    out->y = a->y + n;                                                  \
    out->z = a->z + n;                                                  \
  }                                                                     \
  void name##_sub(name* out, name* a, name* b) {                        \
    out->x = a->x - b->x;                                               \
    out->y = a->y - b->y;                                               \
    out->z = a->z - b->z;                                               \
  }                                                                     \
  void name##_sub_n(name* out, name* a, number n) {                     \
    out->x = a->x - n;                                                  \
    out->y = a->y - n;                                                  \
    out->z = a->z - n;                                                  \
  }                                                                     \
  void name##_mul(name* out, name* a, name* b) {                        \
    out->x = a->x * b->x;                                               \
    out->y = a->y * b->y;                                               \
    out->z = a->z * b->z;                                               \
  }                                                                     \
  void name##_mul_n(name* out, name* a, number n) {                     \
    out->x = a->x * n;                                                  \
    out->y = a->y * n;                                                  \
    out->z = a->z * n;                                                  \
  }                                                                     \
  void name##_div(name* out, name* a, name* b) {                        \
    out->x = a->x / b->x;                                               \
    out->y = a->y / b->y;                                               \
    out->z = a->z / b->z;                                               \
  }                                                                     \
  void name##_div_n(name* out, name* a, number n) {                     \
    out->x = a->x / n;                                                  \
    out->y = a->y / n;                                                  \
    out->z = a->z / n;                                                  \
  }                                                                     \
  void name##_rotx(name* out, name* a, number angle) {                  \
    number cx = cosFunc(angle);                                         \
    number sx = sinFunc(angle);                                         \
    number outX = a->x;                                                 \
    number outY = a->y * cx - a->z * sx;                                \
    number outZ = a->z * cx + a->y * sx;                                \
    out->x = outX;                                                      \
    out->y = outY;                                                      \
    out->z = outZ;                                                      \
  }                                                                     \
  void name##_roty(name* out, name* a, number angle) {                  \
    number cy = cosFunc(angle);                                         \
    number sy = sinFunc(angle);                                         \
    number outX = a->x * cy + a->z * sy;                                \
    number outY = a->y;                                                 \
    number outZ = a->z * cy - a->x * sy;                                \
    out->x = outX;                                                      \
    out->y = outY;                                                      \
    out->z = outZ;                                                      \
  }                                                                     \
  void name##_rotz(name* out, name* a, number angle) {                  \
    number cz = cosFunc(angle);                                         \
    number sz = sinFunc(angle);                                         \
    number outX = a->x * cz - a->y * sz;                                \
    number outY = a->y * cz + a->x * sz;                                \
    number outZ = a->z;                                                 \
    out->x = outX;                                                      \
    out->y = outY;                                                      \
    out->z = outZ;                                                      \
  }                                                                     \
  void name##_rot(name* out, name* a, name* rot, const char order[3]) { \
    name##_copy(out, a);                                                \
    for (int i = 0; i < 3; i++) {                                       \
      switch (order[i]) {                                               \
      case 'x':                                                         \
        name##_rotx(out, out, rot->x);                                  \
        break;                                                          \
      case 'y':                                                         \
        name##_roty(out, out, rot->y);                                  \
        break;                                                          \
      case 'z':                                                         \
        name##_rotz(out, out, rot->z);                                  \
        break;                                                          \
      }                                                                 \
    }                                                                   \
  }                                                                     \
  bool name##_equal(name* a, name* b) {                                 \
    return a->x == b->x && a->y == b->y && a->z == b->z;                \
  }                                                                     \
  bool name##_equal_e(name* a, name* b, number e) {                     \
    return (                                                            \
      absFunc(a->x - b->x) < e &&                                       \
      absFunc(a->y - b->y) < e &&                                       \
      absFunc(a->z - b->z) < e);                                        \
  }                                                                     \
  void name##_cross(name* out, name* a, name* b) {                      \
    number outX = a->y * b->z - a->z * b->y;                            \
    number outY = a->z * b->x - a->x * b->z;                            \
    number outZ = a->x * b->y - a->y * b->x;                            \
    out->x = outX;                                                      \
    out->y = outY;                                                      \
    out->z = outZ;                                                      \
  }                                                                     \
  number name##_dot(name* a, name* b) {                                 \
    return a->x * b->x + a->y * b->y + a->z * b->z;                     \
  }

#endif
