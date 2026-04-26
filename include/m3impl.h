#ifndef M3IMPL_HEADER
#define M3IMPL_HEADER

#define m3_header(name, type, v2type, v3type)                                   \
  typedef union {                                                               \
    struct {                                                                    \
      type a00, a10, a20;                                                       \
      type a01, a11, a21;                                                       \
      type a02, a12, a22;                                                       \
    };                                                                          \
    v3type column[3];                                                           \
    type index[3][3];                                                           \
    type raw[9];                                                                \
  } name;                                                                       \
  name name##_new(                                                              \
    type a00, type a01, type a02,                                               \
    type a10, type a11, type a12,                                               \
    type a20, type a21, type a22);                                              \
  void name##_set(                                                              \
    name* out,                                                                  \
    type a00, type a01, type a02,                                               \
    type a10, type a11, type a12,                                               \
    type a20, type a21, type a22);                                              \
  void name##_copy(name* out, name* a);                                         \
  void name##_identity(name* out);                                              \
  void name##_0(name* out);                                                     \
  void name##_zero(name* out);                                                  \
  void name##_1(name* out);                                                     \
  void name##_one(name* out);                                                   \
  void name##_add(name* out, name* a, name* b);                                 \
  void name##_add1(name* out, name* a, type n);                                 \
  void name##_sub(name* out, name* a, name* b);                                 \
  void name##_sub1(name* out, name* a, type n);                                 \
  void name##_div(name* out, name* a, name* b);                                 \
  void name##_div1(name* out, name* a, type n);                                 \
  void name##_mulc(name* out, name* a, name* b);                                \
  void name##_mulc1(name* out, name* a, type n);                                \
  void name##_mul(name* out, name* a, name* b);                                 \
  void name##_mul1(name* out, name* a, type n);                                 \
  void name##_premul(name* out, name* a, name* b);                              \
  type name##_det(name* a);                                                     \
  void name##_trans(name* out, name* a);                                        \
  void name##_inv(name* out, name* a);                                          \
  void name##_compose(name* out, v2type* position, type angle, v2type* scale);  \
  void name##_decompose(name* a, v2type* position, type* angle, v2type* scale); \
  void name##_apply(name* a, v2type* out);

#define m3_source(name, type, v2type, cosFunc, sinFunc, sqrtFunc, atan2Func)     \
  name name##_new(                                                               \
    type a00, type a01, type a02,                                                \
    type a10, type a11, type a12,                                                \
    type a20, type a21, type a22) {                                              \
    return (name){ a00, a10, a20, a01, a11, a21, a02, a12, a22 };                \
  }                                                                              \
  void name##_set(                                                               \
    name* out,                                                                   \
    type a00, type a01, type a02,                                                \
    type a10, type a11, type a12,                                                \
    type a20, type a21, type a22) {                                              \
    out->a00 = a00;                                                              \
    out->a10 = a10;                                                              \
    out->a20 = a20;                                                              \
    out->a01 = a01;                                                              \
    out->a11 = a11;                                                              \
    out->a21 = a21;                                                              \
    out->a02 = a02;                                                              \
    out->a12 = a12;                                                              \
    out->a22 = a22;                                                              \
  }                                                                              \
  void name##_copy(name* out, name* a) {                                         \
    for (int i = 0; i < 9; i++) {                                                \
      out->raw[i] = a->raw[i];                                                   \
    }                                                                            \
  }                                                                              \
  void name##_identity(name* out) {                                              \
    name##_set(                                                                  \
      out,                                                                       \
      1, 0, 0,                                                                   \
      0, 1, 0,                                                                   \
      0, 0, 1);                                                                  \
  }                                                                              \
  void name##_0(name* out) {                                                     \
    for (int i = 0; i < 9; i++) {                                                \
      out->raw[i] = 0;                                                           \
    }                                                                            \
  }                                                                              \
  void name##_zero(name* out) {                                                  \
    name##_0(out);                                                               \
  }                                                                              \
  void name##_1(name* out) {                                                     \
    for (int i = 0; i < 9; i++) {                                                \
      out->raw[i] = 1;                                                           \
    }                                                                            \
  }                                                                              \
  void name##_one(name* out) {                                                   \
    name##_1(out);                                                               \
  }                                                                              \
  void name##_add(name* out, name* a, name* b) {                                 \
    for (int i = 0; i < 9; i++) {                                                \
      out->raw[i] = a->raw[i] + b->raw[i];                                       \
    }                                                                            \
  }                                                                              \
  void name##_add1(name* out, name* a, type n) {                                 \
    for (int i = 0; i < 9; i++) {                                                \
      out->raw[i] = a->raw[i] + n;                                               \
    }                                                                            \
  }                                                                              \
  void name##_sub(name* out, name* a, name* b) {                                 \
    for (int i = 0; i < 9; i++) {                                                \
      out->raw[i] = a->raw[i] - b->raw[i];                                       \
    }                                                                            \
  }                                                                              \
  void name##_sub1(name* out, name* a, type n) {                                 \
    for (int i = 0; i < 9; i++) {                                                \
      out->raw[i] = a->raw[i] - n;                                               \
    }                                                                            \
  }                                                                              \
  void name##_div(name* out, name* a, name* b) {                                 \
    for (int i = 0; i < 9; i++) {                                                \
      out->raw[i] = a->raw[i] / b->raw[i];                                       \
    }                                                                            \
  }                                                                              \
  void name##_div1(name* out, name* a, type n) {                                 \
    for (int i = 0; i < 9; i++) {                                                \
      out->raw[i] = a->raw[i] / n;                                               \
    }                                                                            \
  }                                                                              \
  void name##_mulc(name* out, name* a, name* b) {                                \
    for (int i = 0; i < 9; i++) {                                                \
      out->raw[i] = a->raw[i] * b->raw[i];                                       \
    }                                                                            \
  }                                                                              \
  void name##_mulc1(name* out, name* a, type n) {                                \
    for (int i = 0; i < 9; i++) {                                                \
      out->raw[i] = a->raw[i] * n;                                               \
    }                                                                            \
  }                                                                              \
  void name##_mul(name* out, name* a, name* b) {                                 \
    type a00 = a->a00 * b->a00 + a->a01 * b->a10 + a->a02 * b->a20;              \
    type a10 = a->a10 * b->a00 + a->a11 * b->a10 + a->a12 * b->a20;              \
    type a20 = a->a20 * b->a00 + a->a21 * b->a10 + a->a22 * b->a20;              \
    type a01 = a->a00 * b->a01 + a->a01 * b->a11 + a->a02 * b->a21;              \
    type a11 = a->a10 * b->a01 + a->a11 * b->a11 + a->a12 * b->a21;              \
    type a21 = a->a20 * b->a01 + a->a21 * b->a11 + a->a22 * b->a21;              \
    type a02 = a->a00 * b->a02 + a->a01 * b->a12 + a->a02 * b->a22;              \
    type a12 = a->a10 * b->a02 + a->a11 * b->a12 + a->a12 * b->a22;              \
    type a22 = a->a20 * b->a02 + a->a21 * b->a12 + a->a22 * b->a22;              \
    out->a00 = a00;                                                              \
    out->a10 = a10;                                                              \
    out->a20 = a20;                                                              \
    out->a01 = a01;                                                              \
    out->a11 = a11;                                                              \
    out->a21 = a21;                                                              \
    out->a02 = a02;                                                              \
    out->a12 = a12;                                                              \
    out->a22 = a22;                                                              \
  }                                                                              \
  void name##_mul1(name* out, name* a, type n) {                                 \
    out->a00 = a->a00 * n;                                                       \
    out->a10 = a->a10;                                                           \
    out->a20 = a->a20;                                                           \
    out->a01 = a->a01;                                                           \
    out->a11 = a->a11 * n;                                                       \
    out->a21 = a->a21;                                                           \
    out->a02 = a->a02;                                                           \
    out->a12 = a->a12;                                                           \
    out->a22 = a->a22 * n;                                                       \
  }                                                                              \
  void name##_premul(name* out, name* a, name* b) {                              \
    name##_mul(out, b, a);                                                       \
  }                                                                              \
  type name##_det(name* a) {                                                     \
    return (                                                                     \
      a->a00 * (a->a11 * a->a22 - a->a12 * a->a21) -                             \
      a->a01 * (a->a10 * a->a22 - a->a12 * a->a20) +                             \
      a->a02 * (a->a10 * a->a21 - a->a11 * a->a20));                             \
  }                                                                              \
  void name##_trans(name* out, name* a) {                                        \
    type a00 = a->a00;                                                           \
    type a10 = a->a01;                                                           \
    type a20 = a->a02;                                                           \
    type a01 = a->a10;                                                           \
    type a11 = a->a11;                                                           \
    type a21 = a->a12;                                                           \
    type a02 = a->a20;                                                           \
    type a12 = a->a21;                                                           \
    type a22 = a->a22;                                                           \
    out->a00 = a00;                                                              \
    out->a10 = a10;                                                              \
    out->a20 = a20;                                                              \
    out->a01 = a01;                                                              \
    out->a11 = a11;                                                              \
    out->a21 = a21;                                                              \
    out->a02 = a02;                                                              \
    out->a12 = a12;                                                              \
    out->a22 = a22;                                                              \
  }                                                                              \
  void name##_inv(name* out, name* a) {                                          \
    type c00 = +(a->a11 * a->a22 - a->a12 * a->a21);                             \
    type c01 = -(a->a10 * a->a22 - a->a12 * a->a20);                             \
    type c02 = +(a->a10 * a->a21 - a->a11 * a->a20);                             \
    type c10 = -(a->a01 * a->a22 - a->a02 * a->a21);                             \
    type c11 = +(a->a00 * a->a22 - a->a02 * a->a20);                             \
    type c12 = -(a->a00 * a->a21 - a->a01 * a->a20);                             \
    type c20 = +(a->a01 * a->a12 - a->a02 * a->a11);                             \
    type c21 = -(a->a00 * a->a12 - a->a02 * a->a10);                             \
    type c22 = +(a->a00 * a->a11 - a->a01 * a->a10);                             \
    type det = a->a00 * c00 + a->a01 * c01 + a->a02 * c02;                       \
    if (det == (type)0) {                                                        \
      return;                                                                    \
    }                                                                            \
    type invDet = (type)1 / det;                                                 \
    out->a00 = c00 * invDet;                                                     \
    out->a10 = c01 * invDet;                                                     \
    out->a20 = c02 * invDet;                                                     \
    out->a01 = c10 * invDet;                                                     \
    out->a11 = c11 * invDet;                                                     \
    out->a21 = c12 * invDet;                                                     \
    out->a02 = c20 * invDet;                                                     \
    out->a12 = c21 * invDet;                                                     \
    out->a22 = c22 * invDet;                                                     \
  }                                                                              \
  /* | scale.x * cosz | -scale.y * sinz | position.x | */                        \
  /* | scale.x * sinz |  scale.y * cosz | position.y | */                        \
  /* | 0              | 0               | 1          | */                        \
  void name##_compose(name* out, v2type* position, type angle, v2type* scale) {  \
    type cosz = cosFunc(angle);                                                  \
    type sinz = sinFunc(angle);                                                  \
    out->a00 = scale->x * cosz;                                                  \
    out->a10 = scale->x * sinz;                                                  \
    out->a20 = (type)0;                                                          \
    out->a01 = -scale->y * sinz;                                                 \
    out->a11 = scale->y * cosz;                                                  \
    out->a21 = (type)0;                                                          \
    out->a02 = position->x;                                                      \
    out->a12 = position->y;                                                      \
    out->a22 = (type)1;                                                          \
  }                                                                              \
  void name##_decompose(name* a, v2type* position, type* angle, v2type* scale) { \
    type sx = sqrtFunc(a->a00 * a->a00 + a->a10 * a->a10);                       \
    type sy = sqrtFunc(a->a01 * a->a01 + a->a11 * a->a11);                       \
    if (sx == 0 || sy == 0) {                                                    \
      return;                                                                    \
    }                                                                            \
    position->x = a->a02;                                                        \
    position->y = a->a12;                                                        \
    scale->x = sx;                                                               \
    scale->y = sy;                                                               \
    *angle = atan2Func(a->a10, a->a00);                                          \
  }                                                                              \
  void name##_apply(name* a, v2type* out) {                                      \
    type x = a->a00 * out->x + a->a01 * out->y + a->a02;                         \
    type y = a->a10 * out->x + a->a11 * out->y + a->a12;                         \
    out->x = x;                                                                  \
    out->y = y;                                                                  \
  }

#endif
