#ifndef V4IMPL_HEADER
#define V4IMPL_HEADER

#define v4_header(name, name3, name2, type)        \
  typedef union {                                  \
    union {                                        \
      name3 xyz;                                   \
      struct {                                     \
        type x, y, z;                              \
      };                                           \
      type w;                                      \
    };                                             \
    struct {                                       \
      type _unused0;                               \
      name3 yzw;                                   \
    };                                             \
    struct {                                       \
      name2 xy;                                    \
      type _unused1;                               \
      type _unused2;                               \
    };                                             \
    struct {                                       \
      type _unused3;                               \
      name2 yz;                                    \
      type _unused4;                               \
    };                                             \
    struct {                                       \
      type _unused5;                               \
      type _unused6;                               \
      name2 zw;                                    \
    };                                             \
    union {                                        \
      name3 rgb;                                   \
      struct {                                     \
        type r, g, b;                              \
      };                                           \
      type a;                                      \
    };                                             \
    type raw[4];                                   \
  } name;                                          \
  name name##_new(type x, type y, type z, type w); \
  name name##_0();                                 \
  name name##_1();                                 \
  name name##_neg();                               \
  name name##_add(name a, name b);                 \
  name name##_add1(name a, type n);                \
  name name##_sub(name a, name b);                 \
  name name##_sub1(name a, type n);                \
  name name##_mul(name a, name b);                 \
  name name##_mul1(name a, type n);                \
  name name##_div(name a, name b);                 \
  name name##_div1(name a, type n);                \
  type name##_slen(name a);                        \
  type name##_len(name a);                         \
  type name##_dot(name a, name b);

#define v4_source(name, type, sqrt_provider)                             \
  name name##_new(type x, type y, type z, type w) {                      \
    return (name){ x, y, z, w };                                         \
  }                                                                      \
  name name##_0() {                                                      \
    return (name){ 0, 0, 0, 0 };                                         \
  }                                                                      \
  name name##_1() {                                                      \
    return (name){ 1, 1, 1, 1 };                                         \
  }                                                                      \
  name name##_neg(name a) {                                              \
    return (name){ -a.x, -a.y, -a.z, -a.w };                             \
  }                                                                      \
  name name##_add(name a, name b) {                                      \
    return (name){ a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w };         \
  }                                                                      \
  name name##_add1(name a, type n) {                                     \
    return (name){ a.x + n, a.y + n, a.z + n, a.w + n };                 \
  }                                                                      \
  name name##_sub(name a, name b) {                                      \
    return (name){ a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w };         \
  }                                                                      \
  name name##_sub1(name a, type n) {                                     \
    return (name){ a.x - n, a.y - n, a.z - n, a.w - n };                 \
  }                                                                      \
  name name##_mul(name a, name b) {                                      \
    return (name){ a.x * b.x, a.y * b.y, a.z * b.z, a.w * b.w };         \
  }                                                                      \
  name name##_mul1(name a, type n) {                                     \
    return (name){ a.x * n, a.y * n, a.z * n, a.w * n };                 \
  }                                                                      \
  name name##_div(name a, name b) {                                      \
    return (name){ a.x / b.x, a.y / b.y, a.z / b.z, a.w / b.w };         \
  }                                                                      \
  name name##_div1(name a, type n) {                                     \
    return (name){ a.x / n, a.y / n, a.z / n, a.w / n };                 \
  }                                                                      \
  type name##_slen(name a) {                                             \
    return a.x * a.x + a.y * a.y + a.z * a.z + a.w * a.w;                \
  }                                                                      \
  type name##_len(name a) {                                              \
    return sqrt_provider(a.x * a.x + a.y * a.y + a.z * a.z + a.w * a.w); \
  }                                                                      \
  type name##_dot(name a, name b) {                                      \
    return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;                \
  }

#endif
