#ifndef M4IMPL_HEADER
#define M4IMPL_HEADER

#define m4_header(name, type, v4type, v3type)                                          \
  typedef union {                                                                      \
    struct {                                                                           \
      type a00, a10, a20, a30;                                                         \
      type a01, a11, a21, a31;                                                         \
      type a02, a12, a22, a32;                                                         \
      type a03, a13, a23, a33;                                                         \
    };                                                                                 \
    v4type column[4];                                                                  \
    type index[4][4];                                                                  \
    type raw[16];                                                                      \
  } name;                                                                              \
  name name##_new(                                                                     \
    type a00, type a01, type a02, type a03,                                            \
    type a10, type a11, type a12, type a13,                                            \
    type a20, type a21, type a22, type a23,                                            \
    type a30, type a31, type a32, type a33);                                           \
  void name##_set(                                                                     \
    name* out,                                                                         \
    type a00, type a01, type a02, type a03,                                            \
    type a10, type a11, type a12, type a13,                                            \
    type a20, type a21, type a22, type a23,                                            \
    type a30, type a31, type a32, type a33);                                           \
  void name##_copy(name* out, name* a);                                                \
  void name##_identity(name* out);                                                     \
  void name##_0(name* out);                                                            \
  void name##_zero(name* out);                                                         \
  void name##_1(name* out);                                                            \
  void name##_one(name* out);                                                          \
  void name##_add(name* out, name* a, name* b);                                        \
  void name##_add1(name* out, name* a, type n);                                        \
  void name##_sub(name* out, name* a, name* b);                                        \
  void name##_sub1(name* out, name* a, type n);                                        \
  void name##_div(name* out, name* a, name* b);                                        \
  void name##_div1(name* out, name* a, type n);                                        \
  void name##_mulc(name* out, name* a, name* b);                                       \
  void name##_mulc1(name* out, name* a, type n);                                       \
  void name##_mul(name* out, name* a, name* b);                                        \
  void name##_mul1(name* out, name* a, type n);                                        \
  void name##_premul(name* out, name* a, name* b);                                     \
  type name##_det(name* a);                                                            \
  void name##_inv(name* out, name* a);                                                 \
  void name##_compose(name* out, v3type* position, v4type* quaternion, v3type* scale); \
  void name##_decompose(name* a, v3type* position, v4type* quaternion, v3type* scale); \
  void name##_apply(name* a, v3type* v);

#define m4_source(name, type, v4type, v3type, sqrtFunc)                                 \
  name name##_new(                                                                      \
    type a00, type a01, type a02, type a03,                                             \
    type a10, type a11, type a12, type a13,                                             \
    type a20, type a21, type a22, type a23,                                             \
    type a30, type a31, type a32, type a33) {                                           \
    return (name){                                                                      \
      a00,                                                                              \
      a10,                                                                              \
      a20,                                                                              \
      a30,                                                                              \
      a01,                                                                              \
      a11,                                                                              \
      a21,                                                                              \
      a31,                                                                              \
      a02,                                                                              \
      a12,                                                                              \
      a22,                                                                              \
      a32,                                                                              \
      a03,                                                                              \
      a13,                                                                              \
      a23,                                                                              \
      a33,                                                                              \
    };                                                                                  \
  }                                                                                     \
  void name##_set(                                                                      \
    name* out,                                                                          \
    type a00, type a01, type a02, type a03,                                             \
    type a10, type a11, type a12, type a13,                                             \
    type a20, type a21, type a22, type a23,                                             \
    type a30, type a31, type a32, type a33) {                                           \
    out->a00 = a00;                                                                     \
    out->a10 = a10;                                                                     \
    out->a20 = a20;                                                                     \
    out->a30 = a30;                                                                     \
    out->a01 = a01;                                                                     \
    out->a11 = a11;                                                                     \
    out->a21 = a21;                                                                     \
    out->a31 = a31;                                                                     \
    out->a02 = a02;                                                                     \
    out->a12 = a12;                                                                     \
    out->a22 = a22;                                                                     \
    out->a32 = a32;                                                                     \
    out->a03 = a03;                                                                     \
    out->a13 = a13;                                                                     \
    out->a23 = a23;                                                                     \
    out->a33 = a33;                                                                     \
  }                                                                                     \
  void name##_copy(name* out, name* a) {                                                \
    for (int i = 0; i < 16; i++) {                                                      \
      out->raw[i] = a->raw[i];                                                          \
    }                                                                                   \
  }                                                                                     \
  void name##_identity(name* out) {                                                     \
    name##_set(                                                                         \
      out,                                                                              \
      1, 0, 0, 0,                                                                       \
      0, 1, 0, 0,                                                                       \
      0, 0, 1, 0,                                                                       \
      0, 0, 0, 1);                                                                      \
  }                                                                                     \
  void name##_0(name* out) {                                                            \
    for (int i = 0; i < 16; i++) {                                                      \
      out->raw[i] = 0;                                                                  \
    }                                                                                   \
  }                                                                                     \
  void name##_zero(name* out) {                                                         \
    name##_0(out);                                                                      \
  }                                                                                     \
  void name##_1(name* out) {                                                            \
    for (int i = 0; i < 16; i++) {                                                      \
      out->raw[i] = 1;                                                                  \
    }                                                                                   \
  }                                                                                     \
  void name##_one(name* out) {                                                          \
    name##_1(out);                                                                      \
  }                                                                                     \
  void name##_add(name* out, name* a, name* b) {                                        \
    for (int i = 0; i < 16; i++) {                                                      \
      out->raw[i] = a->raw[i] + b->raw[i];                                              \
    }                                                                                   \
  }                                                                                     \
  void name##_add1(name* out, name* a, type n) {                                        \
    for (int i = 0; i < 16; i++) {                                                      \
      out->raw[i] = a->raw[i] + n;                                                      \
    }                                                                                   \
  }                                                                                     \
  void name##_sub(name* out, name* a, name* b) {                                        \
    for (int i = 0; i < 16; i++) {                                                      \
      out->raw[i] = a->raw[i] - b->raw[i];                                              \
    }                                                                                   \
  }                                                                                     \
  void name##_sub1(name* out, name* a, type n) {                                        \
    for (int i = 0; i < 16; i++) {                                                      \
      out->raw[i] = a->raw[i] - n;                                                      \
    }                                                                                   \
  }                                                                                     \
  void name##_div(name* out, name* a, name* b) {                                        \
    for (int i = 0; i < 16; i++) {                                                      \
      out->raw[i] = a->raw[i] / b->raw[i];                                              \
    }                                                                                   \
  }                                                                                     \
  void name##_div1(name* out, name* a, type n) {                                        \
    for (int i = 0; i < 16; i++) {                                                      \
      out->raw[i] = a->raw[i] / n;                                                      \
    }                                                                                   \
  }                                                                                     \
  void name##_mulc(name* out, name* a, name* b) {                                       \
    for (int i = 0; i < 16; i++) {                                                      \
      out->raw[i] = a->raw[i] * b->raw[i];                                              \
    }                                                                                   \
  }                                                                                     \
  void name##_mulc1(name* out, name* a, type n) {                                       \
    for (int i = 0; i < 16; i++) {                                                      \
      out->raw[i] = a->raw[i] * n;                                                      \
    }                                                                                   \
  }                                                                                     \
  void name##_mul(name* out, name* a, name* b) {                                        \
    type a00 = a->a00 * b->a00 + a->a01 * b->a10 + a->a02 * b->a20 + a->a03 * b->a30;   \
    type a10 = a->a10 * b->a00 + a->a11 * b->a10 + a->a12 * b->a20 + a->a13 * b->a30;   \
    type a20 = a->a20 * b->a00 + a->a21 * b->a10 + a->a22 * b->a20 + a->a23 * b->a30;   \
    type a30 = a->a30 * b->a00 + a->a31 * b->a10 + a->a32 * b->a20 + a->a33 * b->a30;   \
    type a01 = a->a00 * b->a01 + a->a01 * b->a11 + a->a02 * b->a21 + a->a03 * b->a31;   \
    type a11 = a->a10 * b->a01 + a->a11 * b->a11 + a->a12 * b->a21 + a->a13 * b->a31;   \
    type a21 = a->a20 * b->a01 + a->a21 * b->a11 + a->a22 * b->a21 + a->a23 * b->a31;   \
    type a31 = a->a30 * b->a01 + a->a31 * b->a11 + a->a32 * b->a21 + a->a33 * b->a31;   \
    type a02 = a->a00 * b->a02 + a->a01 * b->a12 + a->a02 * b->a22 + a->a03 * b->a32;   \
    type a12 = a->a10 * b->a02 + a->a11 * b->a12 + a->a12 * b->a22 + a->a13 * b->a32;   \
    type a22 = a->a20 * b->a02 + a->a21 * b->a12 + a->a22 * b->a22 + a->a23 * b->a32;   \
    type a32 = a->a30 * b->a02 + a->a31 * b->a12 + a->a32 * b->a22 + a->a33 * b->a32;   \
    type a03 = a->a00 * b->a03 + a->a01 * b->a13 + a->a02 * b->a23 + a->a03 * b->a33;   \
    type a13 = a->a10 * b->a03 + a->a11 * b->a13 + a->a12 * b->a23 + a->a13 * b->a33;   \
    type a23 = a->a20 * b->a03 + a->a21 * b->a13 + a->a22 * b->a23 + a->a23 * b->a33;   \
    type a33 = a->a30 * b->a03 + a->a31 * b->a13 + a->a32 * b->a23 + a->a33 * b->a33;   \
    out->a00 = a00;                                                                     \
    out->a10 = a10;                                                                     \
    out->a20 = a20;                                                                     \
    out->a30 = a30;                                                                     \
    out->a01 = a01;                                                                     \
    out->a11 = a11;                                                                     \
    out->a21 = a21;                                                                     \
    out->a31 = a31;                                                                     \
    out->a02 = a02;                                                                     \
    out->a12 = a12;                                                                     \
    out->a22 = a22;                                                                     \
    out->a32 = a32;                                                                     \
    out->a03 = a03;                                                                     \
    out->a13 = a13;                                                                     \
    out->a23 = a23;                                                                     \
    out->a33 = a33;                                                                     \
  }                                                                                     \
  void name##_mul1(name* out, name* a, type n) {                                        \
    out->a00 = a->a00 * n;                                                              \
    out->a10 = a->a10;                                                                  \
    out->a20 = a->a20;                                                                  \
    out->a30 = a->a30;                                                                  \
    out->a01 = a->a01;                                                                  \
    out->a11 = a->a11 * n;                                                              \
    out->a21 = a->a21;                                                                  \
    out->a31 = a->a31;                                                                  \
    out->a02 = a->a02;                                                                  \
    out->a12 = a->a12;                                                                  \
    out->a22 = a->a22 * n;                                                              \
    out->a32 = a->a32;                                                                  \
    out->a03 = a->a03;                                                                  \
    out->a13 = a->a13;                                                                  \
    out->a23 = a->a23;                                                                  \
    out->a33 = a->a33 * n;                                                              \
  }                                                                                     \
  void name##_premul(name* out, name* a, name* b) {                                     \
    name##_mul(out, b, a);                                                              \
  }                                                                                     \
  type name##_det(name* a) {                                                            \
    type a00 = a->a00 * a->a11 - a->a01 * a->a10;                                       \
    type a01 = a->a00 * a->a12 - a->a02 * a->a10;                                       \
    type a02 = a->a00 * a->a13 - a->a03 * a->a10;                                       \
    type a03 = a->a01 * a->a12 - a->a02 * a->a11;                                       \
    type a04 = a->a01 * a->a13 - a->a03 * a->a11;                                       \
    type a05 = a->a02 * a->a13 - a->a03 * a->a12;                                       \
    type a06 = a->a20 * a->a31 - a->a21 * a->a30;                                       \
    type a07 = a->a20 * a->a32 - a->a22 * a->a30;                                       \
    type a08 = a->a20 * a->a33 - a->a23 * a->a30;                                       \
    type a09 = a->a21 * a->a32 - a->a22 * a->a31;                                       \
    type a10 = a->a21 * a->a33 - a->a23 * a->a31;                                       \
    type a11 = a->a22 * a->a33 - a->a23 * a->a32;                                       \
    return a00 * a11 -                                                                  \
           a01 * a10 +                                                                  \
           a02 * a09 +                                                                  \
           a03 * a08 -                                                                  \
           a04 * a07 +                                                                  \
           a05 * a06;                                                                   \
  }                                                                                     \
  void name##_inv(name* out, name* a) {                                                 \
    type a00 = a->a00 * a->a11 - a->a01 * a->a10;                                       \
    type a01 = a->a00 * a->a12 - a->a02 * a->a10;                                       \
    type a02 = a->a00 * a->a13 - a->a03 * a->a10;                                       \
    type a03 = a->a01 * a->a12 - a->a02 * a->a11;                                       \
    type a04 = a->a01 * a->a13 - a->a03 * a->a11;                                       \
    type a05 = a->a02 * a->a13 - a->a03 * a->a12;                                       \
    type a06 = a->a20 * a->a31 - a->a21 * a->a30;                                       \
    type a07 = a->a20 * a->a32 - a->a22 * a->a30;                                       \
    type a08 = a->a20 * a->a33 - a->a23 * a->a30;                                       \
    type a09 = a->a21 * a->a32 - a->a22 * a->a31;                                       \
    type a10 = a->a21 * a->a33 - a->a23 * a->a31;                                       \
    type a11 = a->a22 * a->a33 - a->a23 * a->a32;                                       \
    type det =                                                                          \
      a00 * a11 -                                                                       \
      a01 * a10 +                                                                       \
      a02 * a09 +                                                                       \
      a03 * a08 -                                                                       \
      a04 * a07 +                                                                       \
      a05 * a06;                                                                        \
    if (det == 0) {                                                                     \
      return;                                                                           \
    }                                                                                   \
    type invDet = (type)1 / det;                                                        \
    type r00 = (a->a11 * a11 - a->a12 * a10 + a->a13 * a09) * invDet;                   \
    type r01 = -(a->a01 * a11 - a->a02 * a10 + a->a03 * a09) * invDet;                  \
    type r02 = (a->a31 * a05 - a->a32 * a04 + a->a33 * a03) * invDet;                   \
    type r03 = -(a->a21 * a05 - a->a22 * a04 + a->a23 * a03) * invDet;                  \
    type r10 = -(a->a10 * a11 - a->a12 * a08 + a->a13 * a07) * invDet;                  \
    type r11 = (a->a00 * a11 - a->a02 * a08 + a->a03 * a07) * invDet;                   \
    type r12 = -(a->a30 * a05 - a->a32 * a02 + a->a33 * a01) * invDet;                  \
    type r13 = (a->a20 * a05 - a->a22 * a02 + a->a23 * a01) * invDet;                   \
    type r20 = (a->a10 * a10 - a->a11 * a08 + a->a13 * a06) * invDet;                   \
    type r21 = -(a->a00 * a10 - a->a01 * a08 + a->a03 * a06) * invDet;                  \
    type r22 = (a->a30 * a04 - a->a31 * a02 + a->a33 * a00) * invDet;                   \
    type r23 = -(a->a20 * a04 - a->a21 * a02 + a->a23 * a00) * invDet;                  \
    type r30 = -(a->a10 * a09 - a->a11 * a07 + a->a12 * a06) * invDet;                  \
    type r31 = (a->a00 * a09 - a->a01 * a07 + a->a02 * a06) * invDet;                   \
    type r32 = -(a->a30 * a03 - a->a31 * a01 + a->a32 * a00) * invDet;                  \
    type r33 = (a->a20 * a03 - a->a21 * a01 + a->a22 * a00) * invDet;                   \
    out->a00 = r00;                                                                     \
    out->a10 = r10;                                                                     \
    out->a20 = r20;                                                                     \
    out->a30 = r30;                                                                     \
    out->a01 = r01;                                                                     \
    out->a11 = r11;                                                                     \
    out->a21 = r21;                                                                     \
    out->a31 = r31;                                                                     \
    out->a02 = r02;                                                                     \
    out->a12 = r12;                                                                     \
    out->a22 = r22;                                                                     \
    out->a32 = r32;                                                                     \
    out->a03 = r03;                                                                     \
    out->a13 = r13;                                                                     \
    out->a23 = r23;                                                                     \
    out->a33 = r33;                                                                     \
  }                                                                                     \
  void name##_compose(name* out, v3type* position, v4type* quaternion, v3type* scale) { \
    type x = quaternion->x;                                                             \
    type y = quaternion->y;                                                             \
    type z = quaternion->z;                                                             \
    type w = quaternion->w;                                                             \
    type sx = scale->x;                                                                 \
    type sy = scale->y;                                                                 \
    type sz = scale->z;                                                                 \
    type quatSlen = x * x + y * y + z * z + w * w;                                      \
    if (quatSlen != (type)0) {                                                          \
      type invLen = (type)1 / sqrtFunc(quatSlen);                                       \
      x *= invLen;                                                                      \
      y *= invLen;                                                                      \
      z *= invLen;                                                                      \
      w *= invLen;                                                                      \
    } else {                                                                            \
      x = (type)0;                                                                      \
      y = (type)0;                                                                      \
      z = (type)0;                                                                      \
      w = (type)1;                                                                      \
    }                                                                                   \
    type xx = x * x;                                                                    \
    type yy = y * y;                                                                    \
    type zz = z * z;                                                                    \
    type xy = x * y;                                                                    \
    type xz = x * z;                                                                    \
    type yz = y * z;                                                                    \
    type wx = w * x;                                                                    \
    type wy = w * y;                                                                    \
    type wz = w * z;                                                                    \
    type a00 = (type)1 - (type)2 * (yy + zz);                                           \
    type a10 = (type)2 * (xy + wz);                                                     \
    type a20 = (type)2 * (xz - wy);                                                     \
    type a01 = (type)2 * (xy - wz);                                                     \
    type a11 = (type)1 - (type)2 * (xx + zz);                                           \
    type a21 = (type)2 * (yz + wx);                                                     \
    type a02 = (type)2 * (xz + wy);                                                     \
    type a12 = (type)2 * (yz - wx);                                                     \
    type a22 = (type)1 - (type)2 * (xx + yy);                                           \
    out->a00 = a00 * sx;                                                                \
    out->a10 = a10 * sx;                                                                \
    out->a20 = a20 * sx;                                                                \
    out->a30 = (type)0;                                                                 \
    out->a01 = a01 * sy;                                                                \
    out->a11 = a11 * sy;                                                                \
    out->a21 = a21 * sy;                                                                \
    out->a31 = (type)0;                                                                 \
    out->a02 = a02 * sz;                                                                \
    out->a12 = a12 * sz;                                                                \
    out->a22 = a22 * sz;                                                                \
    out->a32 = (type)0;                                                                 \
    out->a03 = position->x;                                                             \
    out->a13 = position->y;                                                             \
    out->a23 = position->z;                                                             \
    out->a33 = (type)1;                                                                 \
  }                                                                                     \
  void name##_decompose(name* a, v3type* position, v4type* quaternion, v3type* scale) { \
    position->x = a->a03;                                                               \
    position->y = a->a13;                                                               \
    position->z = a->a23;                                                               \
    type sx = sqrtFunc(a->a00 * a->a00 + a->a10 * a->a10 + a->a20 * a->a20);            \
    type sy = sqrtFunc(a->a01 * a->a01 + a->a11 * a->a11 + a->a21 * a->a21);            \
    type sz = sqrtFunc(a->a02 * a->a02 + a->a12 * a->a12 + a->a22 * a->a22);            \
    if (sx == 0 || sy == 0 || sz == 0) {                                                \
      return;                                                                           \
    }                                                                                   \
    type det3 =                                                                         \
      a->a00 * (a->a11 * a->a22 - a->a12 * a->a21) -                                    \
      a->a01 * (a->a10 * a->a22 - a->a12 * a->a20) +                                    \
      a->a02 * (a->a10 * a->a21 - a->a11 * a->a20);                                     \
    if (det3 < (type)0) {                                                               \
      sz = -sz;                                                                         \
    }                                                                                   \
    scale->x = sx;                                                                      \
    scale->y = sy;                                                                      \
    scale->z = sz;                                                                      \
    type a00 = a->a00 / sx;                                                             \
    type a10 = a->a10 / sx;                                                             \
    type a20 = a->a20 / sx;                                                             \
    type a01 = a->a01 / sy;                                                             \
    type a11 = a->a11 / sy;                                                             \
    type a21 = a->a21 / sy;                                                             \
    type a02 = a->a02 / sz;                                                             \
    type a12 = a->a12 / sz;                                                             \
    type a22 = a->a22 / sz;                                                             \
    type trace = a00 + a11 + a22;                                                       \
    if (trace > (type)0) {                                                              \
      type s = sqrtFunc(trace + (type)1) * (type)2;                                     \
      quaternion->w = s / (type)4;                                                      \
      quaternion->x = (a21 - a12) / s;                                                  \
      quaternion->y = (a02 - a20) / s;                                                  \
      quaternion->z = (a10 - a01) / s;                                                  \
    } else if (a00 > a11 && a00 > a22) {                                                \
      type s = sqrtFunc((type)1 + a00 - a11 - a22) * (type)2;                           \
      quaternion->w = (a21 - a12) / s;                                                  \
      quaternion->x = s / (type)4;                                                      \
      quaternion->y = (a01 + a10) / s;                                                  \
      quaternion->z = (a02 + a20) / s;                                                  \
    } else if (a11 > a22) {                                                             \
      type s = sqrtFunc((type)1 + a11 - a00 - a22) * (type)2;                           \
      quaternion->w = (a02 - a20) / s;                                                  \
      quaternion->x = (a01 + a10) / s;                                                  \
      quaternion->y = s / (type)4;                                                      \
      quaternion->z = (a12 + a21) / s;                                                  \
    } else {                                                                            \
      type s = sqrtFunc((type)1 + a22 - a00 - a11) * (type)2;                           \
      quaternion->w = (a10 - a01) / s;                                                  \
      quaternion->x = (a02 + a20) / s;                                                  \
      quaternion->y = (a12 + a21) / s;                                                  \
      quaternion->z = s / (type)4;                                                      \
    }                                                                                   \
    type qx = quaternion->x;                                                            \
    type qy = quaternion->y;                                                            \
    type qz = quaternion->z;                                                            \
    type qw = quaternion->w;                                                            \
    type quatSlen = qx * qx + qy * qy + qz * qz + qw * qw;                              \
    if (quatSlen > (type)0) {                                                           \
      type invLen = (type)1 / sqrtFunc(quatSlen);                                       \
      quaternion->x *= invLen;                                                          \
      quaternion->y *= invLen;                                                          \
      quaternion->z *= invLen;                                                          \
      quaternion->w *= invLen;                                                          \
    } else {                                                                            \
      quaternion->x = (type)0;                                                          \
      quaternion->y = (type)0;                                                          \
      quaternion->z = (type)0;                                                          \
      quaternion->w = (type)1;                                                          \
    }                                                                                   \
  }                                                                                     \
  void name##_apply(name* a, v3type* v) {                                               \
    type x = v->x;                                                                      \
    type y = v->y;                                                                      \
    type z = v->z;                                                                      \
    type w = a->a30 * x + a->a31 * y + a->a32 * z + a->a33;                             \
    if (w == (type)0) {                                                                 \
      return;                                                                           \
    }                                                                                   \
    type invW = (type)1 / w;                                                            \
    v->x = (a->a00 * x + a->a01 * y + a->a02 * z + a->a03) * invW;                      \
    v->y = (a->a10 * x + a->a11 * y + a->a12 * z + a->a13) * invW;                      \
    v->z = (a->a20 * x + a->a21 * y + a->a22 * z + a->a23) * invW;                      \
  }

#endif
