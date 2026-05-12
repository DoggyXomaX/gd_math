#ifndef V2IMPL_HEADER
#define V2IMPL_HEADER

#include <stdbool.h>

#define v2_header(name, number)                         \
  typedef union {                                       \
    struct {                                            \
      number x, y;                                      \
    };                                                  \
    struct {                                            \
      number u, v;                                      \
    };                                                  \
    struct {                                            \
      number width, height;                             \
    };                                                  \
    number raw[2];                                      \
  } name;                                               \
  /* Getters */                                         \
  number name##_slen(name* a);                          \
  number name##_len(name* a);                           \
  /* Setters */                                         \
  void name##_set(name* out, number x, number y);       \
  void name##_copy(name* out, name* b);                 \
  void name##_0(name* out);                             \
  void name##_1(name* out);                             \
  /* Factories */                                       \
  name name##_new(number x, number y);                  \
  name name##_new_0();                                  \
  name name##_new_1();                                  \
  name name##_new_right();                              \
  name name##_new_left();                               \
  name name##_new_up();                                 \
  name name##_new_down();                               \
  /* Operations */                                      \
  void name##_neg(name* out, name* a);                  \
  void name##_add(name* out, name* a, name* b);         \
  void name##_sub(name* out, name* a, name* b);         \
  void name##_mul(name* out, name* a, name* b);         \
  void name##_mul_n(name* out, name* a, number n);      \
  void name##_div(name* out, name* a, name* b);         \
  void name##_div_n(name* out, name* a, number n);      \
  void name##_rotate(name* out, name* a, number angle); \
  bool name##_equal(name* a, name* b);                  \
  bool name##_equal_e(name* a, name* b, number e);      \
  number name##_dot(name* a, name* b);                  \
  number name##_cross(name* a, name* b);

#define v2_source(name, number, sqrtFunc, absFunc, cosFunc, sinFunc) \
  /* Getters */                                                      \
  number name##_slen(name* a) {                                      \
    return a->x * a->x + a->y * a->y;                                \
  }                                                                  \
  number name##_len(name* a) {                                       \
    return sqrtFunc(a->x * a->x + a->y * a->y);                      \
  }                                                                  \
  /* Setters */                                                      \
  void name##_set(name* a, number x, number y) {                     \
    a->x = x;                                                        \
    a->y = y;                                                        \
  }                                                                  \
  void name##_copy(name* a, name* b) {                               \
    a->x = b->x;                                                     \
    a->y = b->y;                                                     \
  }                                                                  \
  void name##_0(name* a) {                                           \
    a->x = 0;                                                        \
    a->y = 0;                                                        \
  }                                                                  \
  void name##_1(name* a) {                                           \
    a->x = 1;                                                        \
    a->y = 1;                                                        \
  }                                                                  \
  /* Factories */                                                    \
  name name##_new(number x, number y) {                              \
    return (name){ .x = x, .y = y };                                 \
  }                                                                  \
  name name##_new_0() {                                              \
    return (name){ .x = 0, .y = 0 };                                 \
  }                                                                  \
  name name##_new_1() {                                              \
    return (name){ .x = 1, .y = 1 };                                 \
  }                                                                  \
  name name##_new_right() {                                          \
    return (name){ .x = 1, .y = 0 };                                 \
  }                                                                  \
  name name##_new_left() {                                           \
    return (name){ .x = -1, .y = 0 };                                \
  }                                                                  \
  name name##_new_up() {                                             \
    return (name){ .x = 0, .y = 1 };                                 \
  }                                                                  \
  name name##_new_down() {                                           \
    return (name){ .x = 0, .y = -1 };                                \
  }                                                                  \
  /* Operations */                                                   \
  void name##_neg(name* out, name* a) {                              \
    out->x = -a->x;                                                  \
    out->y = -a->y;                                                  \
  }                                                                  \
  void name##_add(name* out, name* a, name* b) {                     \
    out->x = a->x + b->x;                                            \
    out->y = a->y + b->y;                                            \
  }                                                                  \
  void name##_sub(name* out, name* a, name* b) {                     \
    out->x = a->x - b->x;                                            \
    out->y = a->y - b->y;                                            \
  }                                                                  \
  void name##_mul(name* out, name* a, name* b) {                     \
    out->x = a->x * b->x;                                            \
    out->y = a->y * b->y;                                            \
  }                                                                  \
  void name##_mul_n(name* out, name* a, number n) {                  \
    out->x = a->x * n;                                               \
    out->y = a->y * n;                                               \
  }                                                                  \
  void name##_div(name* out, name* a, name* b) {                     \
    out->x = a->x / b->x;                                            \
    out->y = a->y / b->y;                                            \
  }                                                                  \
  void name##_div_n(name* out, name* a, number n) {                  \
    out->x = a->x / n;                                               \
    out->y = a->y / n;                                               \
  }                                                                  \
  void name##_rotate(name* out, name* a, number angle) {             \
    number cz = cosFunc(angle);                                      \
    number sz = sinFunc(angle);                                      \
    number outX = a->x * cz - a->y * sz;                             \
    number outY = a->y * cz + a->x * sz;                             \
    out->x = outX;                                                   \
    out->y = outY;                                                   \
  }                                                                  \
  bool name##_equal(name* a, name* b) {                              \
    return a->x == b->x && a->y == b->y;                             \
  }                                                                  \
  bool name##_equal_e(name* a, name* b, number e) {                  \
    return absFunc(a->x - b->x) < e && absFunc(a->y - b->y) < e;     \
  }                                                                  \
  number name##_dot(name* a, name* b) {                              \
    return a->x * b->x + a->y * b->y;                                \
  }                                                                  \
  number name##_cross(name* a, name* b) {                            \
    return a->x * b->y - a->y * b->x;                                \
  }

#endif
