#ifndef M4IMPL_HEADER
#define M4IMPL_HEADER

#include <stdbool.h>

#define m4_header(name, v4name, v3name, number)                                        \
  typedef union {                                                                      \
    struct {                                                                           \
      number a00, a10, a20, a30;                                                       \
      number a01, a11, a21, a31;                                                       \
      number a02, a12, a22, a32;                                                       \
      number a03, a13, a23, a33;                                                       \
    };                                                                                 \
    struct {                                                                           \
      number __0, __1, __2, __3;                                                       \
      number __4, a00, a10, a20;                                                       \
      number __5, a01, a11, a21;                                                       \
      number __6, a02, a12, a22;                                                       \
    } m00;                                                                             \
    struct {                                                                           \
      number __0, a00, a10, a20;                                                       \
      number __1, __2, __3, __4;                                                       \
      number __5, a01, a11, a21;                                                       \
      number __6, a02, a12, a22;                                                       \
    } m01;                                                                             \
    struct {                                                                           \
      number __0, a00, a10, a20;                                                       \
      number __1, a01, a11, a21;                                                       \
      number __2, __3, __4, __5;                                                       \
      number __6, a02, a12, a22;                                                       \
    } m02;                                                                             \
    struct {                                                                           \
      number __0, a00, a10, a20;                                                       \
      number __1, a01, a11, a21;                                                       \
      number __2, a02, a12, a22;                                                       \
      number __3, __4, __5, __6;                                                       \
    } m03;                                                                             \
    struct {                                                                           \
      number __0, __1, __2, __3;                                                       \
      number a00, __4, a10, a20;                                                       \
      number a01, __5, a11, a21;                                                       \
      number a02, __6, a12, a22;                                                       \
    } m10;                                                                             \
    struct {                                                                           \
      number a00, __0, a10, a20;                                                       \
      number __1, __2, __3, __4;                                                       \
      number a01, __5, a11, a21;                                                       \
      number a02, __6, a12, a22;                                                       \
    } m11;                                                                             \
    struct {                                                                           \
      number a00, __0, a10, a20;                                                       \
      number a01, __1, a11, a21;                                                       \
      number __2, __3, __4, __5;                                                       \
      number a02, __6, a12, a22;                                                       \
    } m12;                                                                             \
    struct {                                                                           \
      number a00, __0, a10, a20;                                                       \
      number a01, __1, a11, a21;                                                       \
      number a02, __2, a12, a22;                                                       \
      number __3, __4, __5, __6;                                                       \
    } m13;                                                                             \
    struct {                                                                           \
      number __0, __1, __2, __3;                                                       \
      number a00, a10, __4, a20;                                                       \
      number a01, a11, __5, a21;                                                       \
      number a02, a12, __6, a22;                                                       \
    } m20;                                                                             \
    struct {                                                                           \
      number a00, a10, __0, a20;                                                       \
      number __1, __2, __3, __4;                                                       \
      number a01, a11, __5, a21;                                                       \
      number a02, a12, __6, a22;                                                       \
    } m21;                                                                             \
    struct {                                                                           \
      number a00, a10, __0, a20;                                                       \
      number a01, a11, __1, a21;                                                       \
      number __2, __3, __4, __5;                                                       \
      number a02, a12, __6, a22;                                                       \
    } m22;                                                                             \
    struct {                                                                           \
      number a00, a10, __0, a20;                                                       \
      number a01, a11, __1, a21;                                                       \
      number a02, a12, __2, a22;                                                       \
      number __3, __4, __5, __6;                                                       \
    } m23;                                                                             \
    struct {                                                                           \
      number __0, __1, __2, __3;                                                       \
      number a00, a10, a20, __4;                                                       \
      number a01, a11, a21, __5;                                                       \
      number a02, a12, a22, __6;                                                       \
    } m30;                                                                             \
    struct {                                                                           \
      number a00, a10, a20, __0;                                                       \
      number __1, __2, __3, __4;                                                       \
      number a01, a11, a21, __5;                                                       \
      number a02, a12, a22, __6;                                                       \
    } m31;                                                                             \
    struct {                                                                           \
      number a00, a10, a20, __0;                                                       \
      number a01, a11, a21, __1;                                                       \
      number __2, __3, __4, __5;                                                       \
      number a02, a12, a22, __6;                                                       \
    } m32;                                                                             \
    struct {                                                                           \
      number a00, a10, a20, __0;                                                       \
      number a01, a11, a21, __1;                                                       \
      number a02, a12, a22, __2;                                                       \
      number __3, __4, __5, __6;                                                       \
    } m33;                                                                             \
    v4name column[4];                                                                  \
    number index[4][4];                                                                \
    number raw[16];                                                                    \
  } name;                                                                              \
  /* Getters */                                                                        \
  number name##_det(name* a);                                                          \
  /* Setters */                                                                        \
  void name##_set(                                                                     \
    name* out,                                                                         \
    number a00, number a01, number a02, number a03,                                    \
    number a10, number a11, number a12, number a13,                                    \
    number a20, number a21, number a22, number a23,                                    \
    number a30, number a31, number a32, number a33);                                   \
  void name##_copy(name* out, name* a);                                                \
  void name##_0(name* out);                                                            \
  void name##_1(name* out);                                                            \
  void name##_identity(name* out);                                                     \
  void name##_move(name* out, number x, number y, number z);                           \
  void name##_rotx(name* out, number angle);                                           \
  void name##_roty(name* out, number angle);                                           \
  void name##_rotz(name* out, number angle);                                           \
  void name##_scale(name* out, number x, number y, number z);                          \
  void name##_project(name* out, number fov, number aspect, number near, number far);  \
  /* Factories */                                                                      \
  name name##_new(                                                                     \
    number a00, number a01, number a02, number a03,                                    \
    number a10, number a11, number a12, number a13,                                    \
    number a20, number a21, number a22, number a23,                                    \
    number a30, number a31, number a32, number a33);                                   \
  name name##_new_0();                                                                 \
  name name##_new_1();                                                                 \
  name name##_new_identity();                                                          \
  name name##_new_move(number x, number y, number z);                                  \
  name name##_new_rotx(number angle);                                                  \
  name name##_new_roty(number angle);                                                  \
  name name##_new_rotz(number angle);                                                  \
  name name##_new_rot(v3name* euler, const char order[3]);                             \
  name name##_new_rot_n(number x, number y, number z, const char order[3]);            \
  name name##_new_scale(number x, number y, number z);                                 \
  name name##_new_project(number fov, number aspect, number near, number far);         \
  /* Operations */                                                                     \
  void name##_add(name* out, name* a, name* b);                                        \
  void name##_add_n(name* out, name* a, number n);                                     \
  void name##_sub(name* out, name* a, name* b);                                        \
  void name##_sub_n(name* out, name* a, number n);                                     \
  void name##_div(name* out, name* a, name* b);                                        \
  void name##_div_n(name* out, name* a, number n);                                     \
  void name##_mul(name* out, name* a, name* b);                                        \
  void name##_mul_n(name* out, name* a, number n);                                     \
  void name##_premul(name* out, name* a, name* b);                                     \
  void name##_inv(name* out, name* a);                                                 \
  void name##_compose(name* out, v3name* position, v4name* quaternion, v3name* scale); \
  void name##_decompose(name* a, v3name* position, v4name* quaternion, v3name* scale); \
  void name##_apply(name* a, v3name* v);                                               \
  bool name##_equal(name* a, name* b);                                                 \
  bool name##_equal_e(name* a, name* b, number e);                                     \
  bool name##_equal_s(                                                                 \
    name* a,                                                                           \
    number a00, number a01, number a02, number a03,                                    \
    number a10, number a11, number a12, number a13,                                    \
    number a20, number a21, number a22, number a23,                                    \
    number a30, number a31, number a32, number a33);                                   \
  bool name##_equal_se(                                                                \
    name* a,                                                                           \
    number a00, number a01, number a02, number a03,                                    \
    number a10, number a11, number a12, number a13,                                    \
    number a20, number a21, number a22, number a23,                                    \
    number a30, number a31, number a32, number a33, number e);                         \
  bool name##_equal_n(name* a, number n);                                              \
  bool name##_equal_ne(name* a, number n, number e);

#define m4_source(name, v4name, v3name, number, absFunc, cosFunc, sinFunc, tanFunc, sqrtFunc)                             \
  /* Getters */                                                                                                           \
  number name##_det(name* a) {                                                                                            \
    number a00 = a->a00 * a->a11 - a->a01 * a->a10;                                                                       \
    number a01 = a->a00 * a->a12 - a->a02 * a->a10;                                                                       \
    number a02 = a->a00 * a->a13 - a->a03 * a->a10;                                                                       \
    number a03 = a->a01 * a->a12 - a->a02 * a->a11;                                                                       \
    number a04 = a->a01 * a->a13 - a->a03 * a->a11;                                                                       \
    number a05 = a->a02 * a->a13 - a->a03 * a->a12;                                                                       \
    number a06 = a->a20 * a->a31 - a->a21 * a->a30;                                                                       \
    number a07 = a->a20 * a->a32 - a->a22 * a->a30;                                                                       \
    number a08 = a->a20 * a->a33 - a->a23 * a->a30;                                                                       \
    number a09 = a->a21 * a->a32 - a->a22 * a->a31;                                                                       \
    number a10 = a->a21 * a->a33 - a->a23 * a->a31;                                                                       \
    number a11 = a->a22 * a->a33 - a->a23 * a->a32;                                                                       \
    return a00 * a11 -                                                                                                    \
           a01 * a10 +                                                                                                    \
           a02 * a09 +                                                                                                    \
           a03 * a08 -                                                                                                    \
           a04 * a07 +                                                                                                    \
           a05 * a06;                                                                                                     \
  }                                                                                                                       \
  /* Setters */                                                                                                           \
  void name##_set(                                                                                                        \
    name* out,                                                                                                            \
    number a00, number a01, number a02, number a03,                                                                       \
    number a10, number a11, number a12, number a13,                                                                       \
    number a20, number a21, number a22, number a23,                                                                       \
    number a30, number a31, number a32, number a33) {                                                                     \
    out->a00 = a00;                                                                                                       \
    out->a10 = a10;                                                                                                       \
    out->a20 = a20;                                                                                                       \
    out->a30 = a30;                                                                                                       \
    out->a01 = a01;                                                                                                       \
    out->a11 = a11;                                                                                                       \
    out->a21 = a21;                                                                                                       \
    out->a31 = a31;                                                                                                       \
    out->a02 = a02;                                                                                                       \
    out->a12 = a12;                                                                                                       \
    out->a22 = a22;                                                                                                       \
    out->a32 = a32;                                                                                                       \
    out->a03 = a03;                                                                                                       \
    out->a13 = a13;                                                                                                       \
    out->a23 = a23;                                                                                                       \
    out->a33 = a33;                                                                                                       \
  }                                                                                                                       \
  void name##_copy(name* out, name* a) {                                                                                  \
    for (int i = 0; i < 16; i++) {                                                                                        \
      out->raw[i] = a->raw[i];                                                                                            \
    }                                                                                                                     \
  }                                                                                                                       \
  void name##_0(name* out) {                                                                                              \
    for (int i = 0; i < 16; i++) {                                                                                        \
      out->raw[i] = 0;                                                                                                    \
    }                                                                                                                     \
  }                                                                                                                       \
  void name##_1(name* out) {                                                                                              \
    for (int i = 0; i < 16; i++) {                                                                                        \
      out->raw[i] = 1;                                                                                                    \
    }                                                                                                                     \
  }                                                                                                                       \
  void name##_identity(name* out) {                                                                                       \
    name##_set(                                                                                                           \
      out,                                                                                                                \
      1, 0, 0, 0,                                                                                                         \
      0, 1, 0, 0,                                                                                                         \
      0, 0, 1, 0,                                                                                                         \
      0, 0, 0, 1);                                                                                                        \
  }                                                                                                                       \
  void name##_move(name* out, number x, number y, number z) {                                                             \
    name##_set(                                                                                                           \
      out,                                                                                                                \
      1, 0, 0, x,                                                                                                         \
      0, 1, 0, y,                                                                                                         \
      0, 0, 1, z,                                                                                                         \
      0, 0, 0, 1);                                                                                                        \
  }                                                                                                                       \
  void name##_rotx(name* out, number angle) {                                                                             \
    number cx = cosFunc(angle);                                                                                           \
    number sx = sinFunc(angle);                                                                                           \
    name##_set(                                                                                                           \
      out,                                                                                                                \
      1, 0, 0, 0,                                                                                                         \
      0, cx, sx, 0,                                                                                                       \
      0, -sx, cx, 0,                                                                                                      \
      0, 0, 0, 1);                                                                                                        \
  }                                                                                                                       \
  void name##_roty(name* out, number angle) {                                                                             \
    number cy = cosFunc(angle);                                                                                           \
    number sy = sinFunc(angle);                                                                                           \
    name##_set(                                                                                                           \
      out,                                                                                                                \
      cy, 0, -sy, 0,                                                                                                      \
      0, 1, 0, 0,                                                                                                         \
      sy, 0, cy, 0,                                                                                                       \
      0, 0, 0, 1);                                                                                                        \
  }                                                                                                                       \
  void name##_rotz(name* out, number angle) {                                                                             \
    number cz = cosFunc(angle);                                                                                           \
    number sz = sinFunc(angle);                                                                                           \
    name##_set(                                                                                                           \
      out,                                                                                                                \
      cz, -sz, 0, 0,                                                                                                      \
      sz, cz, 0, 0,                                                                                                       \
      0, 0, 1, 0,                                                                                                         \
      0, 0, 0, 1);                                                                                                        \
  }                                                                                                                       \
  void name##_scale(name* out, number x, number y, number z) {                                                            \
    name##_set(                                                                                                           \
      out,                                                                                                                \
      x, 0, 0, 0,                                                                                                         \
      0, y, 0, 0,                                                                                                         \
      0, 0, z, 0,                                                                                                         \
      0, 0, 0, 1);                                                                                                        \
  }                                                                                                                       \
  void name##_project(name* out, number fov, number aspect, number near, number far) {                                    \
    number fovY = fov * (number)3.14159265358979323846 / (number)180;                                                     \
    number f = (number)1 / tanFunc(fovY * (number)0.5);                                                                   \
    name##_set(                                                                                                           \
      out,                                                                                                                \
      f / aspect, 0, 0, 0,                                                                                                \
      0, f, 0, 0,                                                                                                         \
      0, 0, (far + near) / (near - far), ((number)2 * far * near) / (near - far),                                         \
      0, 0, (number) - 1, 1);                                                                                             \
  }                                                                                                                       \
  /* Factories */                                                                                                         \
  name name##_new(                                                                                                        \
    number a00, number a01, number a02, number a03,                                                                       \
    number a10, number a11, number a12, number a13,                                                                       \
    number a20, number a21, number a22, number a23,                                                                       \
    number a30, number a31, number a32, number a33) {                                                                     \
    return (name){                                                                                                        \
      .a00 = a00,                                                                                                         \
      .a01 = a01,                                                                                                         \
      .a02 = a02,                                                                                                         \
      .a03 = a03,                                                                                                         \
      .a10 = a10,                                                                                                         \
      .a11 = a11,                                                                                                         \
      .a12 = a12,                                                                                                         \
      .a13 = a13,                                                                                                         \
      .a20 = a20,                                                                                                         \
      .a21 = a21,                                                                                                         \
      .a22 = a22,                                                                                                         \
      .a23 = a23,                                                                                                         \
      .a30 = a30,                                                                                                         \
      .a31 = a31,                                                                                                         \
      .a32 = a32,                                                                                                         \
      .a33 = a33,                                                                                                         \
    };                                                                                                                    \
  }                                                                                                                       \
  name name##_new_0() {                                                                                                   \
    return name##_new(                                                                                                    \
      0, 0, 0, 0,                                                                                                         \
      0, 0, 0, 0,                                                                                                         \
      0, 0, 0, 0,                                                                                                         \
      0, 0, 0, 0);                                                                                                        \
  }                                                                                                                       \
  name name##_new_1() {                                                                                                   \
    return name##_new(                                                                                                    \
      1, 1, 1, 1,                                                                                                         \
      1, 1, 1, 1,                                                                                                         \
      1, 1, 1, 1,                                                                                                         \
      1, 1, 1, 1);                                                                                                        \
  }                                                                                                                       \
  name name##_new_identity() {                                                                                            \
    return name##_new(                                                                                                    \
      1, 0, 0, 0,                                                                                                         \
      0, 1, 0, 0,                                                                                                         \
      0, 0, 1, 0,                                                                                                         \
      0, 0, 0, 1);                                                                                                        \
  }                                                                                                                       \
  name name##_new_move(number x, number y, number z) {                                                                    \
    return name##_new(                                                                                                    \
      1, 0, 0, x,                                                                                                         \
      0, 1, 0, y,                                                                                                         \
      0, 0, 1, z,                                                                                                         \
      0, 0, 0, 1);                                                                                                        \
  }                                                                                                                       \
  name name##_new_rotx(number angle) {                                                                                    \
    number cx = cosFunc(angle);                                                                                           \
    number sx = sinFunc(angle);                                                                                           \
    return name##_new(                                                                                                    \
      1, 0, 0, 0,                                                                                                         \
      0, cx, sx, 0,                                                                                                       \
      0, -sx, cx, 0,                                                                                                      \
      0, 0, 0, 1);                                                                                                        \
  }                                                                                                                       \
  name name##_new_roty(number angle) {                                                                                    \
    number cy = cosFunc(angle);                                                                                           \
    number sy = sinFunc(angle);                                                                                           \
    return name##_new(                                                                                                    \
      cy, 0, -sy, 0,                                                                                                      \
      0, 1, 0, 0,                                                                                                         \
      sy, 0, cy, 0,                                                                                                       \
      0, 0, 0, 1);                                                                                                        \
  }                                                                                                                       \
  name name##_new_rotz(number angle) {                                                                                    \
    number cz = cosFunc(angle);                                                                                           \
    number sz = sinFunc(angle);                                                                                           \
    return name##_new(                                                                                                    \
      cz, -sz, 0, 0,                                                                                                      \
      sz, cz, 0, 0,                                                                                                       \
      0, 0, 1, 0,                                                                                                         \
      0, 0, 0, 1);                                                                                                        \
  }                                                                                                                       \
  name name##_new_scale(number x, number y, number z) {                                                                   \
    return name##_new(                                                                                                    \
      x, 0, 0, 0,                                                                                                         \
      0, y, 0, 0,                                                                                                         \
      0, 0, z, 0,                                                                                                         \
      0, 0, 0, 1);                                                                                                        \
  }                                                                                                                       \
  name name##_new_project(number fov, number aspect, number near, number far) {                                           \
    number fovY = fov * (number)3.14159265358979323846 / (number)180;                                                     \
    number f = (number)1 / tanFunc(fovY * (number)0.5);                                                                   \
    return name##_new(                                                                                                    \
      f / aspect, 0, 0, 0,                                                                                                \
      0, f, 0, 0,                                                                                                         \
      0, 0, (far + near) / (near - far), ((number)2 * far * near) / (near - far),                                         \
      0, 0, (number) - 1, 1);                                                                                             \
  }                                                                                                                       \
  /* Operations */                                                                                                        \
  void name##_add(name* out, name* a, name* b) {                                                                          \
    for (int i = 0; i < 16; i++) {                                                                                        \
      out->raw[i] = a->raw[i] + b->raw[i];                                                                                \
    }                                                                                                                     \
  }                                                                                                                       \
  void name##_add_n(name* out, name* a, number n) {                                                                       \
    for (int i = 0; i < 16; i++) {                                                                                        \
      out->raw[i] = a->raw[i] + n;                                                                                        \
    }                                                                                                                     \
  }                                                                                                                       \
  void name##_sub(name* out, name* a, name* b) {                                                                          \
    for (int i = 0; i < 16; i++) {                                                                                        \
      out->raw[i] = a->raw[i] - b->raw[i];                                                                                \
    }                                                                                                                     \
  }                                                                                                                       \
  void name##_sub_n(name* out, name* a, number n) {                                                                       \
    for (int i = 0; i < 16; i++) {                                                                                        \
      out->raw[i] = a->raw[i] - n;                                                                                        \
    }                                                                                                                     \
  }                                                                                                                       \
  void name##_div(name* out, name* a, name* b) {                                                                          \
    for (int i = 0; i < 16; i++) {                                                                                        \
      out->raw[i] = a->raw[i] / b->raw[i];                                                                                \
    }                                                                                                                     \
  }                                                                                                                       \
  void name##_div_n(name* out, name* a, number n) {                                                                       \
    for (int i = 0; i < 16; i++) {                                                                                        \
      out->raw[i] = a->raw[i] / n;                                                                                        \
    }                                                                                                                     \
  }                                                                                                                       \
  void name##_mul(name* out, name* a, name* b) {                                                                          \
    number a00 = a->a00 * b->a00 + a->a01 * b->a10 + a->a02 * b->a20 + a->a03 * b->a30;                                   \
    number a10 = a->a10 * b->a00 + a->a11 * b->a10 + a->a12 * b->a20 + a->a13 * b->a30;                                   \
    number a20 = a->a20 * b->a00 + a->a21 * b->a10 + a->a22 * b->a20 + a->a23 * b->a30;                                   \
    number a30 = a->a30 * b->a00 + a->a31 * b->a10 + a->a32 * b->a20 + a->a33 * b->a30;                                   \
    number a01 = a->a00 * b->a01 + a->a01 * b->a11 + a->a02 * b->a21 + a->a03 * b->a31;                                   \
    number a11 = a->a10 * b->a01 + a->a11 * b->a11 + a->a12 * b->a21 + a->a13 * b->a31;                                   \
    number a21 = a->a20 * b->a01 + a->a21 * b->a11 + a->a22 * b->a21 + a->a23 * b->a31;                                   \
    number a31 = a->a30 * b->a01 + a->a31 * b->a11 + a->a32 * b->a21 + a->a33 * b->a31;                                   \
    number a02 = a->a00 * b->a02 + a->a01 * b->a12 + a->a02 * b->a22 + a->a03 * b->a32;                                   \
    number a12 = a->a10 * b->a02 + a->a11 * b->a12 + a->a12 * b->a22 + a->a13 * b->a32;                                   \
    number a22 = a->a20 * b->a02 + a->a21 * b->a12 + a->a22 * b->a22 + a->a23 * b->a32;                                   \
    number a32 = a->a30 * b->a02 + a->a31 * b->a12 + a->a32 * b->a22 + a->a33 * b->a32;                                   \
    number a03 = a->a00 * b->a03 + a->a01 * b->a13 + a->a02 * b->a23 + a->a03 * b->a33;                                   \
    number a13 = a->a10 * b->a03 + a->a11 * b->a13 + a->a12 * b->a23 + a->a13 * b->a33;                                   \
    number a23 = a->a20 * b->a03 + a->a21 * b->a13 + a->a22 * b->a23 + a->a23 * b->a33;                                   \
    number a33 = a->a30 * b->a03 + a->a31 * b->a13 + a->a32 * b->a23 + a->a33 * b->a33;                                   \
    out->a00 = a00;                                                                                                       \
    out->a10 = a10;                                                                                                       \
    out->a20 = a20;                                                                                                       \
    out->a30 = a30;                                                                                                       \
    out->a01 = a01;                                                                                                       \
    out->a11 = a11;                                                                                                       \
    out->a21 = a21;                                                                                                       \
    out->a31 = a31;                                                                                                       \
    out->a02 = a02;                                                                                                       \
    out->a12 = a12;                                                                                                       \
    out->a22 = a22;                                                                                                       \
    out->a32 = a32;                                                                                                       \
    out->a03 = a03;                                                                                                       \
    out->a13 = a13;                                                                                                       \
    out->a23 = a23;                                                                                                       \
    out->a33 = a33;                                                                                                       \
  }                                                                                                                       \
  void name##_mul_n(name* out, name* a, number n) {                                                                       \
    out->a00 = a->a00 * n;                                                                                                \
    out->a10 = a->a10 * n;                                                                                                \
    out->a20 = a->a20 * n;                                                                                                \
    out->a30 = a->a30 * n;                                                                                                \
    out->a01 = a->a01 * n;                                                                                                \
    out->a11 = a->a11 * n;                                                                                                \
    out->a21 = a->a21 * n;                                                                                                \
    out->a31 = a->a31 * n;                                                                                                \
    out->a02 = a->a02 * n;                                                                                                \
    out->a12 = a->a12 * n;                                                                                                \
    out->a22 = a->a22 * n;                                                                                                \
    out->a32 = a->a32 * n;                                                                                                \
    out->a03 = a->a03 * n;                                                                                                \
    out->a13 = a->a13 * n;                                                                                                \
    out->a23 = a->a23 * n;                                                                                                \
    out->a33 = a->a33 * n;                                                                                                \
  }                                                                                                                       \
  void name##_premul(name* out, name* a, name* b) {                                                                       \
    name##_mul(out, b, a);                                                                                                \
  }                                                                                                                       \
  void name##_inv(name* out, name* a) {                                                                                   \
    number a00 = a->a00 * a->a11 - a->a01 * a->a10;                                                                       \
    number a01 = a->a00 * a->a12 - a->a02 * a->a10;                                                                       \
    number a02 = a->a00 * a->a13 - a->a03 * a->a10;                                                                       \
    number a03 = a->a01 * a->a12 - a->a02 * a->a11;                                                                       \
    number a04 = a->a01 * a->a13 - a->a03 * a->a11;                                                                       \
    number a05 = a->a02 * a->a13 - a->a03 * a->a12;                                                                       \
    number a06 = a->a20 * a->a31 - a->a21 * a->a30;                                                                       \
    number a07 = a->a20 * a->a32 - a->a22 * a->a30;                                                                       \
    number a08 = a->a20 * a->a33 - a->a23 * a->a30;                                                                       \
    number a09 = a->a21 * a->a32 - a->a22 * a->a31;                                                                       \
    number a10 = a->a21 * a->a33 - a->a23 * a->a31;                                                                       \
    number a11 = a->a22 * a->a33 - a->a23 * a->a32;                                                                       \
    number det =                                                                                                          \
      a00 * a11 -                                                                                                         \
      a01 * a10 +                                                                                                         \
      a02 * a09 +                                                                                                         \
      a03 * a08 -                                                                                                         \
      a04 * a07 +                                                                                                         \
      a05 * a06;                                                                                                          \
    if (det == 0) {                                                                                                       \
      return;                                                                                                             \
    }                                                                                                                     \
    number invDet = (number)1 / det;                                                                                      \
    number r00 = (a->a11 * a11 - a->a12 * a10 + a->a13 * a09) * invDet;                                                   \
    number r01 = -(a->a01 * a11 - a->a02 * a10 + a->a03 * a09) * invDet;                                                  \
    number r02 = (a->a31 * a05 - a->a32 * a04 + a->a33 * a03) * invDet;                                                   \
    number r03 = -(a->a21 * a05 - a->a22 * a04 + a->a23 * a03) * invDet;                                                  \
    number r10 = -(a->a10 * a11 - a->a12 * a08 + a->a13 * a07) * invDet;                                                  \
    number r11 = (a->a00 * a11 - a->a02 * a08 + a->a03 * a07) * invDet;                                                   \
    number r12 = -(a->a30 * a05 - a->a32 * a02 + a->a33 * a01) * invDet;                                                  \
    number r13 = (a->a20 * a05 - a->a22 * a02 + a->a23 * a01) * invDet;                                                   \
    number r20 = (a->a10 * a10 - a->a11 * a08 + a->a13 * a06) * invDet;                                                   \
    number r21 = -(a->a00 * a10 - a->a01 * a08 + a->a03 * a06) * invDet;                                                  \
    number r22 = (a->a30 * a04 - a->a31 * a02 + a->a33 * a00) * invDet;                                                   \
    number r23 = -(a->a20 * a04 - a->a21 * a02 + a->a23 * a00) * invDet;                                                  \
    number r30 = -(a->a10 * a09 - a->a11 * a07 + a->a12 * a06) * invDet;                                                  \
    number r31 = (a->a00 * a09 - a->a01 * a07 + a->a02 * a06) * invDet;                                                   \
    number r32 = -(a->a30 * a03 - a->a31 * a01 + a->a32 * a00) * invDet;                                                  \
    number r33 = (a->a20 * a03 - a->a21 * a01 + a->a22 * a00) * invDet;                                                   \
    out->a00 = r00;                                                                                                       \
    out->a10 = r10;                                                                                                       \
    out->a20 = r20;                                                                                                       \
    out->a30 = r30;                                                                                                       \
    out->a01 = r01;                                                                                                       \
    out->a11 = r11;                                                                                                       \
    out->a21 = r21;                                                                                                       \
    out->a31 = r31;                                                                                                       \
    out->a02 = r02;                                                                                                       \
    out->a12 = r12;                                                                                                       \
    out->a22 = r22;                                                                                                       \
    out->a32 = r32;                                                                                                       \
    out->a03 = r03;                                                                                                       \
    out->a13 = r13;                                                                                                       \
    out->a23 = r23;                                                                                                       \
    out->a33 = r33;                                                                                                       \
  }                                                                                                                       \
  void name##_compose(name* out, v3name* position, v4name* quaternion, v3name* scale) {                                   \
    number x = quaternion->x;                                                                                             \
    number y = quaternion->y;                                                                                             \
    number z = quaternion->z;                                                                                             \
    number w = quaternion->w;                                                                                             \
    number sx = scale->x;                                                                                                 \
    number sy = scale->y;                                                                                                 \
    number sz = scale->z;                                                                                                 \
    number quatSlen = x * x + y * y + z * z + w * w;                                                                      \
    if (quatSlen != (number)0) {                                                                                          \
      number invLen = (number)1 / sqrtFunc(quatSlen);                                                                     \
      x *= invLen;                                                                                                        \
      y *= invLen;                                                                                                        \
      z *= invLen;                                                                                                        \
      w *= invLen;                                                                                                        \
    } else {                                                                                                              \
      x = (number)0;                                                                                                      \
      y = (number)0;                                                                                                      \
      z = (number)0;                                                                                                      \
      w = (number)1;                                                                                                      \
    }                                                                                                                     \
    number xx = x * x;                                                                                                    \
    number yy = y * y;                                                                                                    \
    number zz = z * z;                                                                                                    \
    number xy = x * y;                                                                                                    \
    number xz = x * z;                                                                                                    \
    number yz = y * z;                                                                                                    \
    number wx = w * x;                                                                                                    \
    number wy = w * y;                                                                                                    \
    number wz = w * z;                                                                                                    \
    number a00 = (number)1 - (number)2 * (yy + zz);                                                                       \
    number a10 = (number)2 * (xy + wz);                                                                                   \
    number a20 = (number)2 * (xz - wy);                                                                                   \
    number a01 = (number)2 * (xy - wz);                                                                                   \
    number a11 = (number)1 - (number)2 * (xx + zz);                                                                       \
    number a21 = (number)2 * (yz + wx);                                                                                   \
    number a02 = (number)2 * (xz + wy);                                                                                   \
    number a12 = (number)2 * (yz - wx);                                                                                   \
    number a22 = (number)1 - (number)2 * (xx + yy);                                                                       \
    out->a00 = a00 * sx;                                                                                                  \
    out->a10 = a10 * sx;                                                                                                  \
    out->a20 = a20 * sx;                                                                                                  \
    out->a30 = (number)0;                                                                                                 \
    out->a01 = a01 * sy;                                                                                                  \
    out->a11 = a11 * sy;                                                                                                  \
    out->a21 = a21 * sy;                                                                                                  \
    out->a31 = (number)0;                                                                                                 \
    out->a02 = a02 * sz;                                                                                                  \
    out->a12 = a12 * sz;                                                                                                  \
    out->a22 = a22 * sz;                                                                                                  \
    out->a32 = (number)0;                                                                                                 \
    out->a03 = position->x;                                                                                               \
    out->a13 = position->y;                                                                                               \
    out->a23 = position->z;                                                                                               \
    out->a33 = (number)1;                                                                                                 \
  }                                                                                                                       \
  void name##_decompose(name* a, v3name* position, v4name* quaternion, v3name* scale) {                                   \
    position->x = a->a03;                                                                                                 \
    position->y = a->a13;                                                                                                 \
    position->z = a->a23;                                                                                                 \
    number sx = sqrtFunc(a->a00 * a->a00 + a->a10 * a->a10 + a->a20 * a->a20);                                            \
    number sy = sqrtFunc(a->a01 * a->a01 + a->a11 * a->a11 + a->a21 * a->a21);                                            \
    number sz = sqrtFunc(a->a02 * a->a02 + a->a12 * a->a12 + a->a22 * a->a22);                                            \
    if (sx == 0 || sy == 0 || sz == 0) {                                                                                  \
      return;                                                                                                             \
    }                                                                                                                     \
    number det3 =                                                                                                         \
      a->a00 * (a->a11 * a->a22 - a->a12 * a->a21) -                                                                      \
      a->a01 * (a->a10 * a->a22 - a->a12 * a->a20) +                                                                      \
      a->a02 * (a->a10 * a->a21 - a->a11 * a->a20);                                                                       \
    if (det3 < (number)0) {                                                                                               \
      sz = -sz;                                                                                                           \
    }                                                                                                                     \
    scale->x = sx;                                                                                                        \
    scale->y = sy;                                                                                                        \
    scale->z = sz;                                                                                                        \
    number a00 = a->a00 / sx;                                                                                             \
    number a10 = a->a10 / sx;                                                                                             \
    number a20 = a->a20 / sx;                                                                                             \
    number a01 = a->a01 / sy;                                                                                             \
    number a11 = a->a11 / sy;                                                                                             \
    number a21 = a->a21 / sy;                                                                                             \
    number a02 = a->a02 / sz;                                                                                             \
    number a12 = a->a12 / sz;                                                                                             \
    number a22 = a->a22 / sz;                                                                                             \
    number trace = a00 + a11 + a22;                                                                                       \
    if (trace > (number)0) {                                                                                              \
      number s = sqrtFunc(trace + (number)1) * (number)2;                                                                 \
      quaternion->w = s / (number)4;                                                                                      \
      quaternion->x = (a21 - a12) / s;                                                                                    \
      quaternion->y = (a02 - a20) / s;                                                                                    \
      quaternion->z = (a10 - a01) / s;                                                                                    \
    } else if (a00 > a11 && a00 > a22) {                                                                                  \
      number s = sqrtFunc((number)1 + a00 - a11 - a22) * (number)2;                                                       \
      quaternion->w = (a21 - a12) / s;                                                                                    \
      quaternion->x = s / (number)4;                                                                                      \
      quaternion->y = (a01 + a10) / s;                                                                                    \
      quaternion->z = (a02 + a20) / s;                                                                                    \
    } else if (a11 > a22) {                                                                                               \
      number s = sqrtFunc((number)1 + a11 - a00 - a22) * (number)2;                                                       \
      quaternion->w = (a02 - a20) / s;                                                                                    \
      quaternion->x = (a01 + a10) / s;                                                                                    \
      quaternion->y = s / (number)4;                                                                                      \
      quaternion->z = (a12 + a21) / s;                                                                                    \
    } else {                                                                                                              \
      number s = sqrtFunc((number)1 + a22 - a00 - a11) * (number)2;                                                       \
      quaternion->w = (a10 - a01) / s;                                                                                    \
      quaternion->x = (a02 + a20) / s;                                                                                    \
      quaternion->y = (a12 + a21) / s;                                                                                    \
      quaternion->z = s / (number)4;                                                                                      \
    }                                                                                                                     \
    number qx = quaternion->x;                                                                                            \
    number qy = quaternion->y;                                                                                            \
    number qz = quaternion->z;                                                                                            \
    number qw = quaternion->w;                                                                                            \
    number quatSlen = qx * qx + qy * qy + qz * qz + qw * qw;                                                              \
    if (quatSlen > (number)0) {                                                                                           \
      number invLen = (number)1 / sqrtFunc(quatSlen);                                                                     \
      quaternion->x *= invLen;                                                                                            \
      quaternion->y *= invLen;                                                                                            \
      quaternion->z *= invLen;                                                                                            \
      quaternion->w *= invLen;                                                                                            \
    } else {                                                                                                              \
      quaternion->x = (number)0;                                                                                          \
      quaternion->y = (number)0;                                                                                          \
      quaternion->z = (number)0;                                                                                          \
      quaternion->w = (number)1;                                                                                          \
    }                                                                                                                     \
  }                                                                                                                       \
  void name##_apply(name* a, v3name* v) {                                                                                 \
    number x = v->x;                                                                                                      \
    number y = v->y;                                                                                                      \
    number z = v->z;                                                                                                      \
    number w = a->a30 * x + a->a31 * y + a->a32 * z + a->a33;                                                             \
    if (w == (number)0) {                                                                                                 \
      return;                                                                                                             \
    }                                                                                                                     \
    number invW = (number)1 / w;                                                                                          \
    v->x = (a->a00 * x + a->a01 * y + a->a02 * z + a->a03) * invW;                                                        \
    v->y = (a->a10 * x + a->a11 * y + a->a12 * z + a->a13) * invW;                                                        \
    v->z = (a->a20 * x + a->a21 * y + a->a22 * z + a->a23) * invW;                                                        \
  }                                                                                                                       \
  bool name##_equal(name* a, name* b) {                                                                                   \
    for (int i = 0; i < 16; i++) {                                                                                        \
      if (a->raw[i] != b->raw[i]) {                                                                                       \
        return false;                                                                                                     \
      }                                                                                                                   \
    }                                                                                                                     \
    return true;                                                                                                          \
  }                                                                                                                       \
  bool name##_equal_e(name* a, name* b, number e) {                                                                       \
    for (int i = 0; i < 16; i++) {                                                                                        \
      if (absFunc(a->raw[i] - b->raw[i]) >= e) {                                                                          \
        return false;                                                                                                     \
      }                                                                                                                   \
    }                                                                                                                     \
    return true;                                                                                                          \
  }                                                                                                                       \
  bool name##_equal_s(                                                                                                    \
    name* a,                                                                                                              \
    number a00, number a01, number a02, number a03,                                                                       \
    number a10, number a11, number a12, number a13,                                                                       \
    number a20, number a21, number a22, number a23,                                                                       \
    number a30, number a31, number a32, number a33) {                                                                     \
    return (                                                                                                              \
      a->a00 == a00 && a->a01 == a01 && a->a02 == a02 && a->a03 == a03 &&                                                 \
      a->a10 == a10 && a->a11 == a11 && a->a12 == a12 && a->a13 == a13 &&                                                 \
      a->a20 == a20 && a->a21 == a21 && a->a22 == a22 && a->a23 == a23 &&                                                 \
      a->a30 == a30 && a->a31 == a31 && a->a32 == a32 && a->a33 == a33);                                                  \
  }                                                                                                                       \
  bool name##_equal_se(                                                                                                   \
    name* a,                                                                                                              \
    number a00, number a01, number a02, number a03,                                                                       \
    number a10, number a11, number a12, number a13,                                                                       \
    number a20, number a21, number a22, number a23,                                                                       \
    number a30, number a31, number a32, number a33, number e) {                                                           \
    return (                                                                                                              \
      absFunc(a->a00 - a00) < e && absFunc(a->a01 - a01) < e && absFunc(a->a02 - a02) < e && absFunc(a->a03 - a03) < e && \
      absFunc(a->a10 - a10) < e && absFunc(a->a11 - a11) < e && absFunc(a->a12 - a12) < e && absFunc(a->a13 - a13) < e && \
      absFunc(a->a20 - a20) < e && absFunc(a->a21 - a21) < e && absFunc(a->a22 - a22) < e && absFunc(a->a23 - a23) < e && \
      absFunc(a->a30 - a30) < e && absFunc(a->a31 - a31) < e && absFunc(a->a32 - a32) < e && absFunc(a->a33 - a33) < e);  \
  }                                                                                                                       \
  bool name##_equal_n(name* a, number n) {                                                                                \
    for (int i = 0; i < 16; i++) {                                                                                        \
      if (a->raw[i] != n) {                                                                                               \
        return false;                                                                                                     \
      }                                                                                                                   \
    }                                                                                                                     \
    return true;                                                                                                          \
  }                                                                                                                       \
  bool name##_equal_ne(name* a, number n, number e) {                                                                     \
    for (int i = 0; i < 16; i++) {                                                                                        \
      if (absFunc(a->raw[i] - n) >= e) {                                                                                  \
        return false;                                                                                                     \
      }                                                                                                                   \
    }                                                                                                                     \
    return true;                                                                                                          \
  }

#endif
