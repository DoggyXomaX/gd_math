#ifndef M3IMPL_HEADER
#define M3IMPL_HEADER

#include <stdbool.h>

#define m3_header(name, v3name, v2name, number)                                   \
  typedef union {                                                                 \
    struct {                                                                      \
      number a00, a10, a20;                                                       \
      number a01, a11, a21;                                                       \
      number a02, a12, a22;                                                       \
    };                                                                            \
    struct {                                                                      \
      number __0, __1, __2;                                                       \
      number __3, a00, a10;                                                       \
      number __4, a01, a11;                                                       \
    } m00;                                                                        \
    struct {                                                                      \
      number __0, a00, a10;                                                       \
      number __1, __2, __3;                                                       \
      number __4, a01, a11;                                                       \
    } m01;                                                                        \
    struct {                                                                      \
      number __0, a00, a10;                                                       \
      number __1, a01, a11;                                                       \
      number __2, __3, __4;                                                       \
    } m02;                                                                        \
    struct {                                                                      \
      number __0, __1, __2;                                                       \
      number a00, __3, a10;                                                       \
      number a01, __4, a11;                                                       \
    } m10;                                                                        \
    struct {                                                                      \
      number a00, __0, a10;                                                       \
      number __1, __2, __3;                                                       \
      number a01, __4, a11;                                                       \
    } m11;                                                                        \
    struct {                                                                      \
      number a00, __0, a10;                                                       \
      number a01, __1, a11;                                                       \
      number __2, __3, __4;                                                       \
    } m12;                                                                        \
    struct {                                                                      \
      number __0, __1, __2;                                                       \
      number a00, a10, __3;                                                       \
      number a01, a11, __4;                                                       \
    } m20;                                                                        \
    struct {                                                                      \
      number a00, a10, __0;                                                       \
      number __1, __2, __3;                                                       \
      number a01, a11, __4;                                                       \
    } m21;                                                                        \
    struct {                                                                      \
      number a00, a10, __0;                                                       \
      number a01, a11, __1;                                                       \
      number __2, __3, __4;                                                       \
    } m22;                                                                        \
    v3name column[3];                                                             \
    number index[3][3];                                                           \
    number raw[9];                                                                \
  } name;                                                                         \
  /* Getters */                                                                   \
  number name##_det(name* a);                                                     \
  /* Setters */                                                                   \
  void name##_set(                                                                \
    name* out,                                                                    \
    number a00, number a01, number a02,                                           \
    number a10, number a11, number a12,                                           \
    number a20, number a21, number a22);                                          \
  void name##_copy(name* out, name* a);                                           \
  void name##_0(name* out);                                                       \
  void name##_1(name* out);                                                       \
  void name##_identity(name* out);                                                \
  void name##_move(name* out, number x, number y);                                \
  void name##_rotate(name* out, number angle);                                    \
  void name##_scale(name* out, number x, number y);                               \
  /* Factories */                                                                 \
  name name##_new(                                                                \
    number a00, number a01, number a02,                                           \
    number a10, number a11, number a12,                                           \
    number a20, number a21, number a22);                                          \
  name name##_new_0();                                                            \
  name name##_new_1();                                                            \
  name name##_new_identity();                                                     \
  name name##_new_move(number x, number y);                                       \
  name name##_new_rotate(number angle);                                           \
  name name##_new_scale(number x, number y);                                      \
  /* Operations */                                                                \
  void name##_add(name* out, name* a, name* b);                                   \
  void name##_add_n(name* out, name* a, number n);                                \
  void name##_sub(name* out, name* a, name* b);                                   \
  void name##_sub_n(name* out, name* a, number n);                                \
  void name##_div(name* out, name* a, name* b);                                   \
  void name##_div_n(name* out, name* a, number n);                                \
  void name##_mul(name* out, name* a, name* b);                                   \
  void name##_mul_n(name* out, name* a, number n);                                \
  void name##_premul(name* out, name* a, name* b);                                \
  void name##_trans(name* out, name* a);                                          \
  void name##_inv(name* out, name* a);                                            \
  void name##_compose(name* out, v2name* position, number angle, v2name* scale);  \
  void name##_decompose(name* a, v2name* position, number* angle, v2name* scale); \
  void name##_apply(name* a, v2name* out);                                        \
  bool name##_equal(name* a, name* b);                                            \
  bool name##_equal_e(name* a, name* b, number e);                                \
  bool name##_equal_s(                                                            \
    name* a,                                                                      \
    number a00, number a01, number a02,                                           \
    number a10, number a11, number a12,                                           \
    number a20, number a21, number a22);                                          \
  bool name##_equal_se(                                                           \
    name* a,                                                                      \
    number a00, number a01, number a02,                                           \
    number a10, number a11, number a12,                                           \
    number a20, number a21, number a22, number e);                                \
  bool name##_equal_n(name* a, number n);                                         \
  bool name##_equal_ne(name* a, number n, number e);

#define m3_source(name, v2name, number, absFunc, cosFunc, sinFunc, sqrtFunc, atan2Func)      \
  /* Getters */                                                                              \
  number name##_det(name* a) {                                                               \
    return (                                                                                 \
      a->a00 * (a->a11 * a->a22 - a->a12 * a->a21) -                                         \
      a->a01 * (a->a10 * a->a22 - a->a12 * a->a20) +                                         \
      a->a02 * (a->a10 * a->a21 - a->a11 * a->a20));                                         \
  }                                                                                          \
  /* Setters */                                                                              \
  void name##_set(                                                                           \
    name* out,                                                                               \
    number a00, number a01, number a02,                                                      \
    number a10, number a11, number a12,                                                      \
    number a20, number a21, number a22) {                                                    \
    out->a00 = a00;                                                                          \
    out->a01 = a01;                                                                          \
    out->a02 = a02;                                                                          \
    out->a10 = a10;                                                                          \
    out->a11 = a11;                                                                          \
    out->a12 = a12;                                                                          \
    out->a20 = a20;                                                                          \
    out->a21 = a21;                                                                          \
    out->a22 = a22;                                                                          \
  }                                                                                          \
  void name##_copy(name* out, name* a) {                                                     \
    for (int i = 0; i < 9; i++) {                                                            \
      out->raw[i] = a->raw[i];                                                               \
    }                                                                                        \
  }                                                                                          \
  void name##_0(name* out) {                                                                 \
    for (int i = 0; i < 9; i++) {                                                            \
      out->raw[i] = 0;                                                                       \
    }                                                                                        \
  }                                                                                          \
  void name##_1(name* out) {                                                                 \
    for (int i = 0; i < 9; i++) {                                                            \
      out->raw[i] = 1;                                                                       \
    }                                                                                        \
  }                                                                                          \
  void name##_identity(name* out) {                                                          \
    name##_set(                                                                              \
      out,                                                                                   \
      1, 0, 0,                                                                               \
      0, 1, 0,                                                                               \
      0, 0, 1);                                                                              \
  }                                                                                          \
  void name##_move(name* out, number x, number y) {                                          \
    return name##_set(                                                                       \
      out,                                                                                   \
      1, 0, x,                                                                               \
      0, 1, y,                                                                               \
      0, 0, 1);                                                                              \
  }                                                                                          \
  void name##_rotate(name* out, number angle) {                                              \
    number cz = cosFunc(angle);                                                              \
    number sz = sinFunc(angle);                                                              \
    return name##_set(                                                                       \
      out,                                                                                   \
      cz, -sz, 0,                                                                            \
      sz, cz, 0,                                                                             \
      0, 0, 1);                                                                              \
  }                                                                                          \
  void name##_scale(name* out, number x, number y) {                                         \
    return name##_set(                                                                       \
      out,                                                                                   \
      x, 0, 0,                                                                               \
      0, y, 0,                                                                               \
      0, 0, 1);                                                                              \
  }                                                                                          \
  /* Factories */                                                                            \
  name name##_new(                                                                           \
    number a00, number a01, number a02,                                                      \
    number a10, number a11, number a12,                                                      \
    number a20, number a21, number a22) {                                                    \
    return (name){                                                                           \
      .a00 = a00,                                                                            \
      .a01 = a01,                                                                            \
      .a02 = a02,                                                                            \
      .a10 = a10,                                                                            \
      .a11 = a11,                                                                            \
      .a12 = a12,                                                                            \
      .a20 = a20,                                                                            \
      .a21 = a21,                                                                            \
      .a22 = a22                                                                             \
    };                                                                                       \
  }                                                                                          \
  name name##_new_0() {                                                                      \
    return name##_new(0, 0, 0, 0, 0, 0, 0, 0, 0);                                            \
  }                                                                                          \
  name name##_new_1() {                                                                      \
    return name##_new(1, 1, 1, 1, 1, 1, 1, 1, 1);                                            \
  }                                                                                          \
  name name##_new_identity() {                                                               \
    return name##_new(                                                                       \
      1, 0, 0,                                                                               \
      0, 1, 0,                                                                               \
      0, 0, 1);                                                                              \
  }                                                                                          \
  name name##_new_move(number x, number y) {                                                 \
    return name##_new(                                                                       \
      1, 0, x,                                                                               \
      0, 1, y,                                                                               \
      0, 0, 1);                                                                              \
  }                                                                                          \
  name name##_new_rotate(number angle) {                                                     \
    number cz = cosFunc(angle);                                                              \
    number sz = sinFunc(angle);                                                              \
    return name##_new(                                                                       \
      cz, -sz, 0,                                                                            \
      sz, cz, 0,                                                                             \
      0, 0, 1);                                                                              \
  }                                                                                          \
  name name##_new_scale(number x, number y) {                                                \
    return name##_new(                                                                       \
      x, 0, 0,                                                                               \
      0, y, 0,                                                                               \
      0, 0, 1);                                                                              \
  }                                                                                          \
  /* Operations */                                                                           \
  void name##_add(name* out, name* a, name* b) {                                             \
    for (int i = 0; i < 9; i++) {                                                            \
      out->raw[i] = a->raw[i] + b->raw[i];                                                   \
    }                                                                                        \
  }                                                                                          \
  void name##_add_n(name* out, name* a, number n) {                                          \
    for (int i = 0; i < 9; i++) {                                                            \
      out->raw[i] = a->raw[i] + n;                                                           \
    }                                                                                        \
  }                                                                                          \
  void name##_sub(name* out, name* a, name* b) {                                             \
    for (int i = 0; i < 9; i++) {                                                            \
      out->raw[i] = a->raw[i] - b->raw[i];                                                   \
    }                                                                                        \
  }                                                                                          \
  void name##_sub_n(name* out, name* a, number n) {                                          \
    for (int i = 0; i < 9; i++) {                                                            \
      out->raw[i] = a->raw[i] - n;                                                           \
    }                                                                                        \
  }                                                                                          \
  void name##_div(name* out, name* a, name* b) {                                             \
    for (int i = 0; i < 9; i++) {                                                            \
      out->raw[i] = a->raw[i] / b->raw[i];                                                   \
    }                                                                                        \
  }                                                                                          \
  void name##_div_n(name* out, name* a, number n) {                                          \
    for (int i = 0; i < 9; i++) {                                                            \
      out->raw[i] = a->raw[i] / n;                                                           \
    }                                                                                        \
  }                                                                                          \
  void name##_mul(name* out, name* a, name* b) {                                             \
    number a00 = a->a00 * b->a00 + a->a01 * b->a10 + a->a02 * b->a20;                        \
    number a10 = a->a10 * b->a00 + a->a11 * b->a10 + a->a12 * b->a20;                        \
    number a20 = a->a20 * b->a00 + a->a21 * b->a10 + a->a22 * b->a20;                        \
    number a01 = a->a00 * b->a01 + a->a01 * b->a11 + a->a02 * b->a21;                        \
    number a11 = a->a10 * b->a01 + a->a11 * b->a11 + a->a12 * b->a21;                        \
    number a21 = a->a20 * b->a01 + a->a21 * b->a11 + a->a22 * b->a21;                        \
    number a02 = a->a00 * b->a02 + a->a01 * b->a12 + a->a02 * b->a22;                        \
    number a12 = a->a10 * b->a02 + a->a11 * b->a12 + a->a12 * b->a22;                        \
    number a22 = a->a20 * b->a02 + a->a21 * b->a12 + a->a22 * b->a22;                        \
    out->a00 = a00;                                                                          \
    out->a10 = a10;                                                                          \
    out->a20 = a20;                                                                          \
    out->a01 = a01;                                                                          \
    out->a11 = a11;                                                                          \
    out->a21 = a21;                                                                          \
    out->a02 = a02;                                                                          \
    out->a12 = a12;                                                                          \
    out->a22 = a22;                                                                          \
  }                                                                                          \
  void name##_mul_n(name* out, name* a, number n) {                                          \
    out->a00 = a->a00 * n;                                                                   \
    out->a10 = a->a10 * n;                                                                   \
    out->a20 = a->a20 * n;                                                                   \
    out->a01 = a->a01 * n;                                                                   \
    out->a11 = a->a11 * n;                                                                   \
    out->a21 = a->a21 * n;                                                                   \
    out->a02 = a->a02 * n;                                                                   \
    out->a12 = a->a12 * n;                                                                   \
    out->a22 = a->a22 * n;                                                                   \
  }                                                                                          \
  void name##_premul(name* out, name* a, name* b) {                                          \
    name##_mul(out, b, a);                                                                   \
  }                                                                                          \
  void name##_trans(name* out, name* a) {                                                    \
    number a00 = a->a00;                                                                     \
    number a10 = a->a01;                                                                     \
    number a20 = a->a02;                                                                     \
    number a01 = a->a10;                                                                     \
    number a11 = a->a11;                                                                     \
    number a21 = a->a12;                                                                     \
    number a02 = a->a20;                                                                     \
    number a12 = a->a21;                                                                     \
    number a22 = a->a22;                                                                     \
    out->a00 = a00;                                                                          \
    out->a10 = a10;                                                                          \
    out->a20 = a20;                                                                          \
    out->a01 = a01;                                                                          \
    out->a11 = a11;                                                                          \
    out->a21 = a21;                                                                          \
    out->a02 = a02;                                                                          \
    out->a12 = a12;                                                                          \
    out->a22 = a22;                                                                          \
  }                                                                                          \
  void name##_inv(name* out, name* a) {                                                      \
    number c00 = +(a->a11 * a->a22 - a->a12 * a->a21);                                       \
    number c01 = -(a->a10 * a->a22 - a->a12 * a->a20);                                       \
    number c02 = +(a->a10 * a->a21 - a->a11 * a->a20);                                       \
    number c10 = -(a->a01 * a->a22 - a->a02 * a->a21);                                       \
    number c11 = +(a->a00 * a->a22 - a->a02 * a->a20);                                       \
    number c12 = -(a->a00 * a->a21 - a->a01 * a->a20);                                       \
    number c20 = +(a->a01 * a->a12 - a->a02 * a->a11);                                       \
    number c21 = -(a->a00 * a->a12 - a->a02 * a->a10);                                       \
    number c22 = +(a->a00 * a->a11 - a->a01 * a->a10);                                       \
    number det = a->a00 * c00 + a->a01 * c01 + a->a02 * c02;                                 \
    if (det == (number)0) {                                                                  \
      return;                                                                                \
    }                                                                                        \
    number invDet = (number)1 / det;                                                         \
    out->a00 = c00 * invDet;                                                                 \
    out->a10 = c01 * invDet;                                                                 \
    out->a20 = c02 * invDet;                                                                 \
    out->a01 = c10 * invDet;                                                                 \
    out->a11 = c11 * invDet;                                                                 \
    out->a21 = c12 * invDet;                                                                 \
    out->a02 = c20 * invDet;                                                                 \
    out->a12 = c21 * invDet;                                                                 \
    out->a22 = c22 * invDet;                                                                 \
  }                                                                                          \
  /* | scale.x * cosz | -scale.y * sinz | position.x | */                                    \
  /* | scale.x * sinz |  scale.y * cosz | position.y | */                                    \
  /* | 0              | 0               | 1          | */                                    \
  void name##_compose(name* out, v2name* position, number angle, v2name* scale) {            \
    number cosz = cosFunc(angle);                                                            \
    number sinz = sinFunc(angle);                                                            \
    out->a00 = scale->x * cosz;                                                              \
    out->a10 = scale->x * sinz;                                                              \
    out->a20 = (number)0;                                                                    \
    out->a01 = -scale->y * sinz;                                                             \
    out->a11 = scale->y * cosz;                                                              \
    out->a21 = (number)0;                                                                    \
    out->a02 = position->x;                                                                  \
    out->a12 = position->y;                                                                  \
    out->a22 = (number)1;                                                                    \
  }                                                                                          \
  void name##_decompose(name* a, v2name* position, number* angle, v2name* scale) {           \
    number sx = sqrtFunc(a->a00 * a->a00 + a->a10 * a->a10);                                 \
    number sy = sqrtFunc(a->a01 * a->a01 + a->a11 * a->a11);                                 \
    if (sx == 0 || sy == 0) {                                                                \
      return;                                                                                \
    }                                                                                        \
    position->x = a->a02;                                                                    \
    position->y = a->a12;                                                                    \
    scale->x = sx;                                                                           \
    scale->y = sy;                                                                           \
    *angle = atan2Func(a->a10, a->a00);                                                      \
  }                                                                                          \
  void name##_apply(name* a, v2name* out) {                                                  \
    number x = a->a00 * out->x + a->a01 * out->y + a->a02;                                   \
    number y = a->a10 * out->x + a->a11 * out->y + a->a12;                                   \
    out->x = x;                                                                              \
    out->y = y;                                                                              \
  }                                                                                          \
  bool name##_equal(name* a, name* b) {                                                      \
    for (int i = 0; i < 9; i++) {                                                            \
      if (a->raw[i] != b->raw[i]) {                                                          \
        return false;                                                                        \
      }                                                                                      \
    }                                                                                        \
    return true;                                                                             \
  }                                                                                          \
  bool name##_equal_e(name* a, name* b, number e) {                                          \
    for (int i = 0; i < 9; i++) {                                                            \
      if (absFunc(a->raw[i] - b->raw[i]) >= e) {                                             \
        return false;                                                                        \
      }                                                                                      \
    }                                                                                        \
    return true;                                                                             \
  }                                                                                          \
  bool name##_equal_s(                                                                       \
    name* a,                                                                                 \
    number a00, number a01, number a02,                                                      \
    number a10, number a11, number a12,                                                      \
    number a20, number a21, number a22) {                                                    \
    return (                                                                                 \
      a->a00 == a00 && a->a01 == a01 && a->a02 == a02 &&                                     \
      a->a10 == a10 && a->a11 == a11 && a->a12 == a12 &&                                     \
      a->a20 == a20 && a->a21 == a21 && a->a22 == a22);                                      \
  }                                                                                          \
  bool name##_equal_se(                                                                      \
    name* a,                                                                                 \
    number a00, number a01, number a02,                                                      \
    number a10, number a11, number a12,                                                      \
    number a20, number a21, number a22, number e) {                                          \
    return (                                                                                 \
      absFunc(a->a00 - a00) < e && absFunc(a->a01 - a01) < e && absFunc(a->a02 - a02) < e && \
      absFunc(a->a10 - a10) < e && absFunc(a->a11 - a11) < e && absFunc(a->a12 - a12) < e && \
      absFunc(a->a20 - a20) < e && absFunc(a->a21 - a21) < e && absFunc(a->a22 - a22) < e);  \
  }                                                                                          \
  bool name##_equal_n(name* a, number n) {                                                   \
    for (int i = 0; i < 9; i++) {                                                            \
      if (a->raw[i] != n) {                                                                  \
        return false;                                                                        \
      }                                                                                      \
    }                                                                                        \
    return true;                                                                             \
  }                                                                                          \
  bool name##_equal_ne(name* a, number n, number e) {                                        \
    for (int i = 0; i < 9; i++) {                                                            \
      if (absFunc(a->raw[i] - n) >= e) {                                                     \
        return false;                                                                        \
      }                                                                                      \
    }                                                                                        \
    return true;                                                                             \
  }

#endif
