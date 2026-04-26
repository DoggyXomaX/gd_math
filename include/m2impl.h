#ifndef M2IMPL_HEADER
#define M2IMPL_HEADER

#define m2_header(name, type, v2type)                                 \
  typedef union {                                                     \
    struct {                                                          \
      type a00, a10;                                                  \
      type a01, a11;                                                  \
    };                                                                \
    v2type column[2];                                                 \
    type index[2][2];                                                 \
    type raw[4];                                                      \
  } name;                                                             \
  name name##_new(type a00, type a01, type a10, type a11);            \
  void name##_set(name* out, type a00, type a01, type a10, type a11); \
  void name##_copy(name* out, name* a);                               \
  void name##_identity(name* out);                                    \
  void name##_0(name* out);                                           \
  void name##_zero(name* out);                                        \
  void name##_1(name* out);                                           \
  void name##_one(name* out);                                         \
  void name##_add(name* out, name* a, name* b);                       \
  void name##_add1(name* out, name* a, type n);                       \
  void name##_sub(name* out, name* a, name* b);                       \
  void name##_sub1(name* out, name* a, type n);                       \
  void name##_div(name* out, name* a, name* b);                       \
  void name##_div1(name* out, name* a, type n);                       \
  void name##_mulc(name* out, name* a, name* b);                      \
  void name##_mulc1(name* out, name* a, type n);                      \
  void name##_mul(name* out, name* a, name* b);                       \
  void name##_mul1(name* out, name* a, type n);                       \
  void name##_premul(name* out, name* a, name* b);                    \
  void name##_trans(name* out, name* a);                              \
  void name##_inv(name* out, name* a);                                \
  type name##_det(name* a);

#define m2_source(name, type)                                          \
  name name##_new(type a00, type a01, type a10, type a11) {            \
    return (name){ a00, a10, a01, a11 };                               \
  }                                                                    \
  void name##_set(name* out, type a00, type a01, type a10, type a11) { \
    out->a00 = a00;                                                    \
    out->a10 = a10;                                                    \
    out->a01 = a01;                                                    \
    out->a11 = a11;                                                    \
  }                                                                    \
  void name##_copy(name* out, name* a) {                               \
    for (int i = 0; i < 4; i++) {                                      \
      out->raw[i] = a->raw[i];                                         \
    }                                                                  \
  }                                                                    \
  void name##_identity(name* out) {                                    \
    name##_set(                                                        \
      out,                                                             \
      1, 0,                                                            \
      0, 1);                                                           \
  }                                                                    \
  void name##_0(name* out) {                                           \
    for (int i = 0; i < 4; i++) {                                      \
      out->raw[i] = 0;                                                 \
    }                                                                  \
  }                                                                    \
  void name##_zero(name* out) {                                        \
    name##_0(out);                                                     \
  }                                                                    \
  void name##_1(name* out) {                                           \
    for (int i = 0; i < 4; i++) {                                      \
      out->raw[i] = 0;                                                 \
    }                                                                  \
  }                                                                    \
  void name##_one(name* out) {                                         \
    name##_1(out);                                                     \
  }                                                                    \
  void name##_add(name* out, name* a, name* b) {                       \
    for (int i = 0; i < 4; i++) {                                      \
      out->raw[i] = a->raw[i] + b->raw[i];                             \
    }                                                                  \
  }                                                                    \
  void name##_add1(name* out, name* a, type n) {                       \
    for (int i = 0; i < 4; i++) {                                      \
      out->raw[i] = a->raw[i] + n;                                     \
    }                                                                  \
  }                                                                    \
  void name##_sub(name* out, name* a, name* b) {                       \
    for (int i = 0; i < 4; i++) {                                      \
      out->raw[i] = a->raw[i] - b->raw[i];                             \
    }                                                                  \
  }                                                                    \
  void name##_sub1(name* out, name* a, type n) {                       \
    for (int i = 0; i < 4; i++) {                                      \
      out->raw[i] = a->raw[i] - n;                                     \
    }                                                                  \
  }                                                                    \
  void name##_div(name* out, name* a, name* b) {                       \
    for (int i = 0; i < 4; i++) {                                      \
      out->raw[i] = a->raw[i] / b->raw[i];                             \
    }                                                                  \
  }                                                                    \
  void name##_div1(name* out, name* a, type n) {                       \
    for (int i = 0; i < 4; i++) {                                      \
      out->raw[i] = a->raw[i] / n;                                     \
    }                                                                  \
  }                                                                    \
  void name##_mulc(name* out, name* a, name* b) {                      \
    for (int i = 0; i < 4; i++) {                                      \
      out->raw[i] = a->raw[i] * b->raw[i];                             \
    }                                                                  \
  }                                                                    \
  void name##_mulc1(name* out, name* a, type n) {                      \
    for (int i = 0; i < 4; i++) {                                      \
      out->raw[i] = a->raw[i] * n;                                     \
    }                                                                  \
  }                                                                    \
  void name##_mul(name* out, name* a, name* b) {                       \
    type a00 = a->a00 * b->a00 + a->a01 * b->a10;                      \
    type a10 = a->a10 * b->a00 + a->a11 * b->a10;                      \
    type a01 = a->a00 * b->a01 + a->a01 * b->a11;                      \
    type a11 = a->a10 * b->a01 + a->a11 * b->a11;                      \
    out->a00 = a00;                                                    \
    out->a10 = a10;                                                    \
    out->a01 = a01;                                                    \
    out->a11 = a11;                                                    \
  }                                                                    \
  void name##_mul1(name* out, name* a, type n) {                       \
    out->a00 = a->a00 * n;                                             \
    out->a10 = a->a10;                                                 \
    out->a01 = a->a01;                                                 \
    out->a11 = a->a11 * n;                                             \
  }                                                                    \
  void name##_premul(name* out, name* a, name* b) {                    \
    name##_mul(out, b, a);                                             \
  }                                                                    \
  void name##_trans(name* out, name* a) {                              \
    type a00 = a->a00;                                                 \
    type a10 = a->a01;                                                 \
    type a01 = a->a10;                                                 \
    type a11 = a->a11;                                                 \
    out->a00 = a00;                                                    \
    out->a10 = a10;                                                    \
    out->a01 = a01;                                                    \
    out->a11 = a11;                                                    \
  }                                                                    \
  void name##_inv(name* out, name* a) {                                \
    type det = name##_det(a);                                          \
    if (det == (type)0) {                                              \
      return;                                                          \
    }                                                                  \
    type invDet = (type)(1) / det;                                     \
    type a00 = a->a11 * invDet;                                        \
    type a10 = -a->a10 * invDet;                                       \
    type a01 = -a->a01 * invDet;                                       \
    type a11 = a->a00 * invDet;                                        \
    out->a00 = a00;                                                    \
    out->a10 = a10;                                                    \
    out->a01 = a01;                                                    \
    out->a11 = a11;                                                    \
  }                                                                    \
  type name##_det(name* a) {                                           \
    return a->a00 * a->a11 - a->a01 * a->a10;                          \
  }

#endif
