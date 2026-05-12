#ifndef V4IMPL_HEADER
#define V4IMPL_HEADER

#include <stdbool.h>

#define v4_header(name, name3, name2, number)                         \
  typedef union {                                                     \
    struct {                                                          \
      union {                                                         \
        name3 xyz;                                                    \
        struct {                                                      \
          number x, y, z;                                             \
        };                                                            \
      };                                                              \
      number w;                                                       \
    };                                                                \
    struct {                                                          \
      number _0;                                                      \
      name3 yzw;                                                      \
    };                                                                \
    struct {                                                          \
      name2 xy;                                                       \
      number _1;                                                      \
      number _2;                                                      \
    };                                                                \
    struct {                                                          \
      number _3;                                                      \
      name2 yz;                                                       \
      number _4;                                                      \
    };                                                                \
    struct {                                                          \
      number _5;                                                      \
      number _6;                                                      \
      name2 zw;                                                       \
    };                                                                \
    struct {                                                          \
      union {                                                         \
        name3 rgb;                                                    \
        struct {                                                      \
          number r, g, b;                                             \
        };                                                            \
      };                                                              \
      number a;                                                       \
    };                                                                \
    number raw[4];                                                    \
  } name;                                                             \
  /* Getters */                                                       \
  number name##_slen(name* a);                                        \
  number name##_len(name* a);                                         \
  /* Setters */                                                       \
  void name##_set(name* out, number x, number y, number z, number w); \
  void name##_copy(name* out, name* b);                               \
  void name##_0(name* out);                                           \
  void name##_1(name* out);                                           \
  void name##_euler(name* out, name3* euler);                         \
  /* Factories */                                                     \
  name name##_new(number x, number y, number z, number w);            \
  name name##_new_0();                                                \
  name name##_new_1();                                                \
  name name##_new_identity();                                         \
  name name##_new_euler(number pitch, number roll, number yaw);       \
  /* Operations */                                                    \
  void name##_neg(name* out, name* a);                                \
  void name##_add(name* out, name* a, name* b);                       \
  void name##_add_n(name* out, name* a, number n);                    \
  void name##_sub(name* out, name* a, name* b);                       \
  void name##_sub_n(name* out, name* a, number n);                    \
  void name##_mul(name* out, name* a, name* b);                       \
  void name##_mul_n(name* out, name* a, number n);                    \
  void name##_div(name* out, name* a, name* b);                       \
  void name##_div_n(name* out, name* a, number n);                    \
  number name##_dot(name* a, name* b);                                \
  bool name##_equal(name* a, name* b);                                \
  bool name##_equal_e(name* a, name* b, number e);

#define v4_source(name, name3, number, sqrtFunc, absFunc, cosFunc, sinFunc) \
  /* Getters */                                                             \
  number name##_slen(name* a) {                                             \
    return a->x * a->x + a->y * a->y + a->z * a->z + a->w * a->w;           \
  }                                                                         \
  number name##_len(name* a) {                                              \
    return sqrtFunc(a->x * a->x + a->y * a->y + a->z * a->z + a->w * a->w); \
  }                                                                         \
  /* Setters */                                                             \
  void name##_set(name* out, number x, number y, number z, number w) {      \
    out->x = x;                                                             \
    out->y = y;                                                             \
    out->z = z;                                                             \
    out->w = w;                                                             \
  }                                                                         \
  void name##_copy(name* out, name* b) {                                    \
    out->x = b->x;                                                          \
    out->y = b->y;                                                          \
    out->z = b->z;                                                          \
    out->w = b->w;                                                          \
  }                                                                         \
  void name##_0(name* out) {                                                \
    out->x = 0;                                                             \
    out->y = 0;                                                             \
    out->z = 0;                                                             \
    out->w = 0;                                                             \
  }                                                                         \
  void name##_1(name* out) {                                                \
    out->x = 1;                                                             \
    out->y = 1;                                                             \
    out->z = 1;                                                             \
    out->w = 1;                                                             \
  }                                                                         \
  void name##_euler(name* out, name3* euler) {                              \
    number hx = euler->x * 0.5;                                             \
    number hy = euler->y * 0.5;                                             \
    number hz = euler->z * 0.5;                                             \
    number sx = sinFunc(hx), cx = cosFunc(hx);                              \
    number sy = sinFunc(hy), cy = cosFunc(hy);                              \
    number sz = sinFunc(hz), cz = cosFunc(hz);                              \
    out->x = sx * cy * cz + cx * sy * sz;                                   \
    out->y = cx * sy * cz - sx * cy * sz;                                   \
    out->z = cx * cy * sz + sx * sy * cz;                                   \
    out->w = cx * cy * cz - sx * sy * sz;                                   \
  }                                                                         \
  /* Factories */                                                           \
  name name##_new(number x, number y, number z, number w) {                 \
    return (name){ .x = x, .y = y, .z = z, .w = w };                        \
  }                                                                         \
  name name##_new_0() {                                                     \
    return name##_new(0, 0, 0, 0);                                          \
  }                                                                         \
  name name##_new_1() {                                                     \
    return name##_new(1, 1, 1, 1);                                          \
  }                                                                         \
  name name##_new_identity() {                                              \
    return name##_new(0, 0, 0, 1);                                          \
  }                                                                         \
  name name##_new_euler(number pitch, number roll, number yaw) {            \
    number hx = pitch * 0.5;                                                \
    number hy = roll * 0.5;                                                 \
    number hz = yaw * 0.5;                                                  \
    number sx = sinFunc(hx), cx = cosFunc(hx);                              \
    number sy = sinFunc(hy), cy = cosFunc(hy);                              \
    number sz = sinFunc(hz), cz = cosFunc(hz);                              \
    return name##_new(                                                      \
      sx * cy * cz + cx * sy * sz,                                          \
      cx * sy * cz - sx * cy * sz,                                          \
      cx * cy * sz + sx * sy * cz,                                          \
      cx * cy * cz - sx * sy * sz);                                         \
  }                                                                         \
  /* Operations */                                                          \
  void name##_neg(name* out, name* a) {                                     \
    out->x = -a->x;                                                         \
    out->y = -a->y;                                                         \
    out->z = -a->z;                                                         \
    out->w = -a->w;                                                         \
  }                                                                         \
  void name##_add(name* out, name* a, name* b) {                            \
    out->x = a->x + b->x;                                                   \
    out->y = a->y + b->y;                                                   \
    out->z = a->z + b->z;                                                   \
    out->w = a->w + b->w;                                                   \
  }                                                                         \
  void name##_add_n(name* out, name* a, number n) {                         \
    out->x = a->x + n;                                                      \
    out->y = a->y + n;                                                      \
    out->z = a->z + n;                                                      \
    out->w = a->w + n;                                                      \
  }                                                                         \
  void name##_sub(name* out, name* a, name* b) {                            \
    out->x = a->x - b->x;                                                   \
    out->y = a->y - b->y;                                                   \
    out->z = a->z - b->z;                                                   \
    out->w = a->w - b->w;                                                   \
  }                                                                         \
  void name##_sub_n(name* out, name* a, number n) {                         \
    out->x = a->x - n;                                                      \
    out->y = a->y - n;                                                      \
    out->z = a->z - n;                                                      \
    out->w = a->w - n;                                                      \
  }                                                                         \
  void name##_mul(name* out, name* a, name* b) {                            \
    out->x = a->x * b->x;                                                   \
    out->y = a->y * b->y;                                                   \
    out->z = a->z * b->z;                                                   \
    out->w = a->w * b->w;                                                   \
  }                                                                         \
  void name##_mul_n(name* out, name* a, number n) {                         \
    out->x = a->x * n;                                                      \
    out->y = a->y * n;                                                      \
    out->z = a->z * n;                                                      \
    out->w = a->w * n;                                                      \
  }                                                                         \
  void name##_div(name* out, name* a, name* b) {                            \
    out->x = a->x / b->x;                                                   \
    out->y = a->y / b->y;                                                   \
    out->z = a->z / b->z;                                                   \
    out->w = a->w / b->w;                                                   \
  }                                                                         \
  void name##_div_n(name* out, name* a, number n) {                         \
    out->x = a->x / n;                                                      \
    out->y = a->y / n;                                                      \
    out->z = a->z / n;                                                      \
    out->w = a->w / n;                                                      \
  }                                                                         \
  number name##_dot(name* a, name* b) {                                     \
    return a->x * b->x + a->y * b->y + a->z * b->z + a->w * b->w;           \
  }                                                                         \
  bool name##_equal(name* a, name* b) {                                     \
    return a->x == b->x && a->y == b->y && a->z == b->z && a->w == b->w;    \
  }                                                                         \
  bool name##_equal_e(name* a, name* b, number e) {                         \
    return (                                                                \
      absFunc(a->x - b->x) < e &&                                           \
      absFunc(a->y - b->y) < e &&                                           \
      absFunc(a->z - b->z) < e &&                                           \
      absFunc(a->w - b->w) < e);                                            \
  }

#endif
