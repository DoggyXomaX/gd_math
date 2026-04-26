#ifndef V3IMPL_HEADER
#define V3IMPL_HEADER

#define v3_header(name, name2, type)       \
  typedef union {                          \
    struct {                               \
      union {                              \
        name2 xy;                          \
        struct {                           \
          type x, y;                       \
        };                                 \
      };                                   \
      type z;                              \
    };                                     \
    struct {                               \
      type _unused1;                       \
      name2 yz;                            \
    };                                     \
    struct {                               \
      type u, v, w;                        \
    };                                     \
    struct {                               \
      type r, g, b;                        \
    };                                     \
    struct {                               \
      type width, height, length;          \
    };                                     \
    type raw[3];                           \
  } name;                                  \
  name name##_new(type x, type y, type z); \
  name name##_0();                         \
  name name##_1();                         \
  name name##_right();                     \
  name name##_left();                      \
  name name##_up();                        \
  name name##_down();                      \
  name name##_front();                     \
  name name##_back();                      \
  name name##_neg(name a);                 \
  name name##_add(name a, name b);         \
  name name##_add1(name a, type n);        \
  name name##_sub(name a, name b);         \
  name name##_sub1(name a, type n);        \
  name name##_mul(name a, name b);         \
  name name##_mul1(name a, type n);        \
  name name##_div(name a, name b);         \
  name name##_div1(name a, type n);        \
  type name##_slen(name a);                \
  type name##_len(name a);                 \
  type name##_dot(name a, name b);         \
  name name##_cross(name a, name b);

#define v3_source(name, type, sqrt_provider)                 \
  name name##_new(type x, type y, type z) {                  \
    return (name){ x, y, z };                                \
  }                                                          \
  name name##_0() {                                          \
    return (name){ 0, 0, 0 };                                \
  }                                                          \
  name name##_1() {                                          \
    return (name){ 1, 1, 1 };                                \
  }                                                          \
  name name##_right() {                                      \
    return (name){ 1, 0, 0 };                                \
  }                                                          \
  name name##_left() {                                       \
    return (name){ -1, 0, 0 };                               \
  }                                                          \
  name name##_up() {                                         \
    return (name){ 0, 1, 0 };                                \
  }                                                          \
  name name##_down() {                                       \
    return (name){ 0, -1, 0 };                               \
  }                                                          \
  name name##_front() {                                      \
    return (name){ 0, 0, 1 };                                \
  }                                                          \
  name name##_back() {                                       \
    return (name){ 0, 0, -1 };                               \
  }                                                          \
  name name##_neg(name a) {                                  \
    return (name){ -a.x, -a.y, -a.z };                       \
  }                                                          \
  name name##_add(name a, name b) {                          \
    return (name){ a.x + b.x, a.y + b.y, a.z + b.z };        \
  }                                                          \
  name name##_add1(name a, type n) {                         \
    return (name){ a.x + n, a.y + n, a.z + n };              \
  }                                                          \
  name name##_sub(name a, name b) {                          \
    return (name){ a.x - b.x, a.y - b.y, a.z - b.z };        \
  }                                                          \
  name name##_sub1(name a, type n) {                         \
    return (name){ a.x - n, a.y - n, a.z - n };              \
  }                                                          \
  name name##_mul(name a, name b) {                          \
    return (name){ a.x * b.x, a.y * b.y, a.z * b.z };        \
  }                                                          \
  name name##_mul1(name a, type n) {                         \
    return (name){ a.x * n, a.y * n, a.z * n };              \
  }                                                          \
  name name##_div(name a, name b) {                          \
    return (name){ a.x / b.x, a.y / b.y, a.z / b.z };        \
  }                                                          \
  name name##_div1(name a, type n) {                         \
    return (name){ a.x / n, a.y / n, a.z / n };              \
  }                                                          \
  type name##_slen(name a) {                                 \
    return a.x * a.x + a.y * a.y + a.z * a.z;                \
  }                                                          \
  type name##_len(name a) {                                  \
    return sqrt_provider(a.x * a.x + a.y * a.y + a.z * a.z); \
  }                                                          \
  type name##_dot(name a, name b) {                          \
    return a.x * b.x + a.y * b.y + a.z * b.z;                \
  }                                                          \
  name name##_cross(name a, name b) {                        \
    return (name){                                           \
      a.y * b.z - a.z * b.y,                                 \
      a.z * b.x - a.x * b.z,                                 \
      a.x * b.y - a.y * b.x                                  \
    };                                                       \
  }

#endif
