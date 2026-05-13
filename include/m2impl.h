#ifndef M2IMPL_HEADER
#define M2IMPL_HEADER

#include <stdbool.h>

#define m2_header(name, v2name, number)                                                    \
  typedef union {                                                                          \
    struct {                                                                               \
      number a00, a10;                                                                     \
      number a01, a11;                                                                     \
    };                                                                                     \
    struct {                                                                               \
      number m11, m01;                                                                     \
      number m10, m00;                                                                     \
    };                                                                                     \
    v2name column[2];                                                                      \
    number index[2][2];                                                                    \
    number raw[4];                                                                         \
  } name;                                                                                  \
  /* Getters */                                                                            \
  number name##_det(name* a);                                                              \
  /* Setters */                                                                            \
  void name##_set(name* out, number a00, number a01, number a10, number a11);              \
  void name##_copy(name* out, name* a);                                                    \
  void name##_0(name* out);                                                                \
  void name##_1(name* out);                                                                \
  void name##_identity(name* out);                                                         \
  /* Factories */                                                                          \
  name name##_new(number a00, number a01, number a10, number a11);                         \
  name name##_new_0();                                                                     \
  name name##_new_1();                                                                     \
  name name##_new_identity();                                                              \
  /* Operations */                                                                         \
  void name##_add(name* out, name* a, name* b);                                            \
  void name##_add_n(name* out, name* a, number n);                                         \
  void name##_sub(name* out, name* a, name* b);                                            \
  void name##_sub_n(name* out, name* a, number n);                                         \
  void name##_div(name* out, name* a, name* b);                                            \
  void name##_div_n(name* out, name* a, number n);                                         \
  void name##_mul(name* out, name* a, name* b);                                            \
  void name##_mul_n(name* out, name* a, number n);                                         \
  void name##_premul(name* out, name* a, name* b);                                         \
  void name##_trans(name* out, name* a);                                                   \
  void name##_inv(name* out, name* a);                                                     \
  bool name##_equal(name* a, name* b);                                                     \
  bool name##_equal_e(name* a, name* b, number e);                                         \
  bool name##_equal_s(name* a, number a00, number a01, number a10, number a11);            \
  bool name##_equal_se(name* a, number a00, number a01, number a10, number a11, number e); \
  bool name##_equal_n(name* a, number n);                                                  \
  bool name##_equal_ne(name* a, number n, number e);

#define m2_source(name, number, absFunc)                                                    \
  /* Getters */                                                                             \
  number name##_det(name* a) {                                                              \
    return a->a00 * a->a11 - a->a01 * a->a10;                                               \
  }                                                                                         \
  /* Setters */                                                                             \
  void name##_set(name* out, number a00, number a01, number a10, number a11) {              \
    out->a00 = a00;                                                                         \
    out->a10 = a10;                                                                         \
    out->a01 = a01;                                                                         \
    out->a11 = a11;                                                                         \
  }                                                                                         \
  void name##_copy(name* out, name* a) {                                                    \
    for (int i = 0; i < 4; i++) {                                                           \
      out->raw[i] = a->raw[i];                                                              \
    }                                                                                       \
  }                                                                                         \
  void name##_0(name* out) {                                                                \
    for (int i = 0; i < 4; i++) {                                                           \
      out->raw[i] = 0;                                                                      \
    }                                                                                       \
  }                                                                                         \
  void name##_1(name* out) {                                                                \
    for (int i = 0; i < 4; i++) {                                                           \
      out->raw[i] = 1;                                                                      \
    }                                                                                       \
  }                                                                                         \
  void name##_identity(name* out) {                                                         \
    name##_set(                                                                             \
      out,                                                                                  \
      1, 0,                                                                                 \
      0, 1);                                                                                \
  }                                                                                         \
  /* Factories */                                                                           \
  name name##_new(number a00, number a01, number a10, number a11) {                         \
    return (name){ .a00 = a00, .a01 = a01, .a10 = a10, .a11 = a11 };                        \
  }                                                                                         \
  name name##_new_0() {                                                                     \
    return name##_new(0, 0, 0, 0);                                                          \
  }                                                                                         \
  name name##_new_1() {                                                                     \
    return name##_new(1, 1, 1, 1);                                                          \
  }                                                                                         \
  name name##_new_identity() {                                                              \
    return name##_new(                                                                      \
      1, 0,                                                                                 \
      0, 1);                                                                                \
  }                                                                                         \
  /* Operators */                                                                           \
  void name##_add(name* out, name* a, name* b) {                                            \
    for (int i = 0; i < 4; i++) {                                                           \
      out->raw[i] = a->raw[i] + b->raw[i];                                                  \
    }                                                                                       \
  }                                                                                         \
  void name##_add_n(name* out, name* a, number n) {                                         \
    for (int i = 0; i < 4; i++) {                                                           \
      out->raw[i] = a->raw[i] + n;                                                          \
    }                                                                                       \
  }                                                                                         \
  void name##_sub(name* out, name* a, name* b) {                                            \
    for (int i = 0; i < 4; i++) {                                                           \
      out->raw[i] = a->raw[i] - b->raw[i];                                                  \
    }                                                                                       \
  }                                                                                         \
  void name##_sub_n(name* out, name* a, number n) {                                         \
    for (int i = 0; i < 4; i++) {                                                           \
      out->raw[i] = a->raw[i] - n;                                                          \
    }                                                                                       \
  }                                                                                         \
  void name##_div(name* out, name* a, name* b) {                                            \
    for (int i = 0; i < 4; i++) {                                                           \
      out->raw[i] = a->raw[i] / b->raw[i];                                                  \
    }                                                                                       \
  }                                                                                         \
  void name##_div_n(name* out, name* a, number n) {                                         \
    for (int i = 0; i < 4; i++) {                                                           \
      out->raw[i] = a->raw[i] / n;                                                          \
    }                                                                                       \
  }                                                                                         \
  void name##_mul(name* out, name* a, name* b) {                                            \
    number a00 = a->a00 * b->a00 + a->a01 * b->a10;                                         \
    number a10 = a->a10 * b->a00 + a->a11 * b->a10;                                         \
    number a01 = a->a00 * b->a01 + a->a01 * b->a11;                                         \
    number a11 = a->a10 * b->a01 + a->a11 * b->a11;                                         \
    out->a00 = a00;                                                                         \
    out->a10 = a10;                                                                         \
    out->a01 = a01;                                                                         \
    out->a11 = a11;                                                                         \
  }                                                                                         \
  void name##_mul_n(name* out, name* a, number n) {                                         \
    out->a00 = a->a00 * n;                                                                  \
    out->a10 = a->a10 * n;                                                                  \
    out->a01 = a->a01 * n;                                                                  \
    out->a11 = a->a11 * n;                                                                  \
  }                                                                                         \
  void name##_premul(name* out, name* a, name* b) {                                         \
    name##_mul(out, b, a);                                                                  \
  }                                                                                         \
  void name##_trans(name* out, name* a) {                                                   \
    number a00 = a->a00;                                                                    \
    number a10 = a->a01;                                                                    \
    number a01 = a->a10;                                                                    \
    number a11 = a->a11;                                                                    \
    out->a00 = a00;                                                                         \
    out->a10 = a10;                                                                         \
    out->a01 = a01;                                                                         \
    out->a11 = a11;                                                                         \
  }                                                                                         \
  void name##_inv(name* out, name* a) {                                                     \
    number det = name##_det(a);                                                             \
    if (det == (number)0) {                                                                 \
      return;                                                                               \
    }                                                                                       \
    number invDet = (number)(1) / det;                                                      \
    number a00 = a->a11 * invDet;                                                           \
    number a10 = -a->a10 * invDet;                                                          \
    number a01 = -a->a01 * invDet;                                                          \
    number a11 = a->a00 * invDet;                                                           \
    out->a00 = a00;                                                                         \
    out->a10 = a10;                                                                         \
    out->a01 = a01;                                                                         \
    out->a11 = a11;                                                                         \
  }                                                                                         \
  bool name##_equal(name* a, name* b) {                                                     \
    for (int i = 0; i < 4; i++) {                                                           \
      if (a->raw[i] != b->raw[i]) {                                                         \
        return false;                                                                       \
      }                                                                                     \
    }                                                                                       \
    return true;                                                                            \
  }                                                                                         \
  bool name##_equal_e(name* a, name* b, number e) {                                         \
    for (int i = 0; i < 4; i++) {                                                           \
      if (absFunc(a->raw[i] - b->raw[i]) >= e) {                                            \
        return false;                                                                       \
      }                                                                                     \
    }                                                                                       \
    return true;                                                                            \
  }                                                                                         \
  bool name##_equal_s(name* a, number a00, number a01, number a10, number a11) {            \
    return (                                                                                \
      a->a00 == a00 &&                                                                      \
      a->a01 == a01 &&                                                                      \
      a->a10 == a10 &&                                                                      \
      a->a11 == a11);                                                                       \
  }                                                                                         \
  bool name##_equal_se(name* a, number a00, number a01, number a10, number a11, number e) { \
    return (                                                                                \
      absFunc(a->a00 - a00) < e &&                                                          \
      absFunc(a->a01 - a01) < e &&                                                          \
      absFunc(a->a10 - a10) < e &&                                                          \
      absFunc(a->a11 - a11) < e);                                                           \
  }                                                                                         \
  bool name##_equal_n(name* a, number n) {                                                  \
    return (                                                                                \
      a->a00 == n && a->a01 == n &&                                                         \
      a->a10 == n && a->a11 == n);                                                          \
  }                                                                                         \
  bool name##_equal_ne(name* a, number n, number e) {                                       \
    return (                                                                                \
      absFunc(a->a00 - n) < e &&                                                            \
      absFunc(a->a01 - n) < e &&                                                            \
      absFunc(a->a10 - n) < e &&                                                            \
      absFunc(a->a11 - n) < e);                                                             \
  }

#endif
