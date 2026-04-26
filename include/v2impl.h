#ifndef V2IMPL_HEADER
#define V2IMPL_HEADER

#define v2_header(name, type)                 \
  typedef union {                             \
    struct {                                  \
      type x, y;                              \
    };                                        \
    struct {                                  \
      type u, v;                              \
    };                                        \
    struct {                                  \
      type width, height;                     \
    };                                        \
    type raw[2];                              \
  } name;                                     \
  name name##_new(type x, type y);            \
  name name##_0();                            \
  name name##_1();                            \
  name name##_neg(name a);                    \
  bool name##_equal(name a, name b);          \
  bool name##_equale(name a, name b, type e); \
  name name##_add(name a, name b);            \
  name name##_sub(name a, name b);            \
  name name##_mul(name a, name b);            \
  name name##_mul1(name a, type n);           \
  name name##_div(name a, name b);            \
  name name##_div1(name a, type n);           \
  type name##_slen(name a);                   \
  type name##_len(name a);                    \
  type name##_dot(name a, name b);            \
  type name##_cross(name a, name b);

#define v2_source(name, type, sqrt_provider)           \
  name name##_new(type x, type y) {                    \
    return (name){ x, y };                             \
  }                                                    \
  name name##_0() {                                    \
    return (name){ 0, 0 };                             \
  }                                                    \
  name name##_1() {                                    \
    return (name){ 1, 1 };                             \
  }                                                    \
  name name##_neg(name a) {                            \
    return (name){ -a.x, -a.y };                       \
  }                                                    \
  bool name##_equal(name a, name b) {                  \
    return a.x == b.x && a.y == b.y;                   \
  }                                                    \
  bool name##_equale(name a, name b, type e) {         \
    return (a.x > b.x ? a.x - b.x : b.x - a.x) <= e && \
           (a.y > b.y ? a.y - b.y : b.y - a.y) <= e;   \
  }                                                    \
  name name##_add(name a, name b) {                    \
    return (name){ a.x + b.x, a.y + b.y };             \
  }                                                    \
  name name##_add1(name a, type n) {                   \
    return (name){ a.x + n, a.y + n };                 \
  }                                                    \
  name name##_sub(name a, name b) {                    \
    return (name){ a.x - b.x, a.y - b.y };             \
  }                                                    \
  name name##_sub1(name a, type n) {                   \
    return (name){ a.x - n, a.y - n };                 \
  }                                                    \
  name name##_mul(name a, name b) {                    \
    return (name){ a.x * b.x, a.y * b.y };             \
  }                                                    \
  name name##_mul1(name a, type n) {                   \
    return (name){ a.x * n, a.y * n };                 \
  }                                                    \
  name name##_div(name a, name b) {                    \
    return (name){ a.x / b.x, a.y / b.y };             \
  }                                                    \
  name name##_div1(name a, type n) {                   \
    return (name){ a.x / n, a.y / n };                 \
  }                                                    \
  type name##_slen(name a) {                           \
    return a.x * a.x + a.y * a.y;                      \
  }                                                    \
  type name##_len(name a) {                            \
    return sqrt_provider(a.x * a.x + a.y * a.y);       \
  }                                                    \
  type name##_dot(name a, name b) {                    \
    return a.x * b.x + a.y * b.y;                      \
  }                                                    \
  type name##_cross(name a, name b) {                  \
    return a.x * b.y - a.y * b.x;                      \
  }

#endif
