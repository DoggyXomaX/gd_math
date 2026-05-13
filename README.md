# GameDev math

## Description
Custom header-only GameDev math library for study purposes.

## Classes
Available: v2, v2f, v3, v3f, v4, v4f, m2, m2f, m3, m3f, m4, m4f

Usage:
```c
#define <CLASS>_SOURCE
#include "<class>.h"
```

Example:
```c
#define V3_SOURCE
#include "v3f.h"
```

## Values/Getters
### v2
```c
double x, y;
double u, v;
double width, height;
double raw[2];
```
### v3
```c
double x, y, z;
double u, v, w;
double r, g, b;
double width, height, length;
double raw[3];
v2 xy, yz;
```
### v4
```c
double x, y, z, w;
double r, g, b, a;
double raw[4];
v3 xyz, yzw;
v3 rgb;
v2 xy, yz, zw;
```
### m2
```c
double a00, a10, a01, a11;
double m00, m01, m10, m11; // Sub matrices 1x1
v2 column[2];
double index[2][2];
double raw[4];
```
### m3
```c
double a00, a10, a20, a01, a11, a21, a02, a12, a22;
struct { double a00, a10, a01, a11 } m00, m01, m02, m10, m11, m12, m20, m21, m22; // Sub matrices 2x2
v3 column[3];
double index[3][3];
double raw[9];
```
### m4
```c
double a00, a10, a20, a30, a01, a11, a21, a31, a02, a12, a22, a32, a03, a13, a23, a33;
struct { double a00, a10, a20, a01, a11, a21, a02, a12, a22 } m00, m01, m02, m03, m10, m11, m12, m13, m20, m21, m22, m23, m30, m31, m32, m33; // Sub matrices 3x3
v4 column[4];
double index[4][4];
double raw[16];
```

## Methods
### v2
```c
/* Getters */
v2 v2_slen(v2* a);
v2 v2_len(v2* a);
/* Setters */
void v2_set(v2* out, double x, double y);
void v2_copy(v2* out, v2* b);
void v2_0(v2* out);
void v2_1(v2* out);
/* Factories */
v2 v2_new(double x, double y);
v2 v2_new_0();
v2 v2_new_1();
v2 v2_new_right();
v2 v2_new_left();
v2 v2_new_up();
v2 v2_new_down();
/* Operations */
void v2_neg(v2* out, v2* a);
void v2_add(v2* out, v2* a, v2* b);
void v2_sub(v2* out, v2* a, v2* b);
void v2_mul(v2* out, v2* a, v2* b);
void v2_mul_n(v2* out, v2* a, double n);
void v2_div(v2* out, v2* a, v2* b);
void v2_div_n(v2* out, v2* a, double n);
void v2_rotate(v2* out, v2* a, double angle);
bool v2_equal(v2* a, v2* b);
bool v2_equal_e(v2* a, v2* b, double e);
double v2_dot(v2* a, v2* b);
double v2_cross(v2* a, v2* b);
```
### v3
```c
/* Getters */
double v3_slen(v3* a);
double v3_len(v3* a);
/* Setters */
void v3_set(v3* out, double x, double y, double z);
void v3_copy(v3* out, v3* a);
void v3_0(v3* out);
void v3_1(v3* out);
/* Factories */
v3 v3_new(double x, double y, double z);
v3 v3_new_0();
v3 v3_new_1();
v3 v3_new_right();
v3 v3_new_left();
v3 v3_new_up();
v3 v3_new_down();
v3 v3_new_front();
v3 v3_new_back();
/* Operations */
void v3_neg(v3* out, v3* a);
void v3_add(v3* out, v3* a, v3* b);
void v3_add_n(v3* out, v3* a, double n);
void v3_sub(v3* out, v3* a, v3* b);
void v3_sub_n(v3* out, v3* a, double n);
void v3_mul(v3* out, v3* a, v3* b);
void v3_mul_n(v3* out, v3* a, double n);
void v3_div(v3* out, v3* a, v3* b);
void v3_div_n(v3* out, v3* a, double n);
void v3_rotx(v3* out, v3* a, double angle);
void v3_roty(v3* out, v3* a, double angle);
void v3_rotz(v3* out, v3* a, double angle);
void v3_rot(v3* out, v3* a, v3* rot, const char order[3]);
bool v3_equal(v3* a, v3* b);
bool v3_equal_e(v3* a, v3* b, double e);
void v3_cross(v3* out, v3* a, v3* b);
double v3_dot(v3* a, v3* b);
```
### v4
```c
/* Getters */
double v4_slen(v4* a);
double v4_len(v4* a);
/* Setters */
void v4_set(v4* out, double x, double y, double z, double w);
void v4_copy(v4* out, v4* b);
void v4_0(v4* out);
void v4_1(v4* out);
void v4_euler(v4* out, v3* euler);
/* Factories */
v4 v4_new(double x, double y, double z, double w);
v4 v4_new_0();
v4 v4_new_1();
v4 v4_new_identity();
v4 v4_new_euler(double pitch, double roll, double yaw);
/* Operations */
void v4_neg(v4* out, v4* a);
void v4_add(v4* out, v4* a, v4* b);
void v4_add_n(v4* out, v4* a, double n);
void v4_sub(v4* out, v4* a, v4* b);
void v4_sub_n(v4* out, v4* a, double n);
void v4_mul(v4* out, v4* a, v4* b);
void v4_mul_n(v4* out, v4* a, double n);
void v4_div(v4* out, v4* a, v4* b);
void v4_div_n(v4* out, v4* a, double n);
double v4_dot(v4* a, v4* b);
bool v4_equal(v4* a, v4* b);
bool v4_equal_e(v4* a, v4* b, double e);
```
### m2
```c
/* Getters */
double m2_det(m2* a);
/* Setters */
void m2_set(m2* out, double a00, double a01, double a10, double a11);
void m2_copy(m2* out, m2* a);
void m2_0(m2* out);
void m2_1(m2* out);
void m2_identity(m2* out);
/* Factories */
m2 m2_new(double a00, double a01, double a10, double a11);
m2 m2_new_0();
m2 m2_new_1();
m2 m2_new_identity();
/* Operations */
void m2_add(m2* out, m2* a, m2* b);
void m2_add_n(m2* out, m2* a, double n);
void m2_sub(m2* out, m2* a, m2* b);
void m2_sub_n(m2* out, m2* a, double n);
void m2_div(m2* out, m2* a, m2* b);
void m2_div_n(m2* out, m2* a, double n);
void m2_mul(m2* out, m2* a, m2* b);
void m2_mul_n(m2* out, m2* a, double n);
void m2_premul(m2* out, m2* a, m2* b);
void m2_trans(m2* out, m2* a);
void m2_inv(m2* out, m2* a);
bool m2_equal(m2* a, m2* b);
bool m2_equal_e(m2* a, m2* b, double e);
bool m2_equal_s(m2* a, double a00, double a01, double a10, double a11);
bool m2_equal_se(m2* a, double a00, double a01, double a10, double a11, double e);
bool m2_equal_n(m2* a, double n);
bool m2_equal_ne(m2* a, double n, double e);
```
### m3
```c
/* Getters */
double m3_det(m3* a);
/* Setters */
void m3_set(
  m3* out,
  double a00, double a01, double a02,
  double a10, double a11, double a12,
  double a20, double a21, double a22);
void m3_copy(m3* out, m3* a);
void m3_0(m3* out);
void m3_1(m3* out);
void m3_identity(m3* out);
void m3_move(m3* out, double x, double y);
void m3_rotate(m3* out, double angle);
void m3_scale(m3* out, double x, double y);
/* Factories */
m3 m3_new(
  double a00, double a01, double a02,
  double a10, double a11, double a12,
  double a20, double a21, double a22);
m3 m3_new_0();
m3 m3_new_1();
m3 m3_new_identity();
m3 m3_new_move(double x, double y);
m3 m3_new_rotate(double angle);
m3 m3_new_scale(double x, double y);
/* Operations */
void m3_add(m3* out, m3* a, m3* b);
void m3_add_n(m3* out, m3* a, double n);
void m3_sub(m3* out, m3* a, m3* b);
void m3_sub_n(m3* out, m3* a, double n);
void m3_div(m3* out, m3* a, m3* b);
void m3_div_n(m3* out, m3* a, double n);
void m3_mul(m3* out, m3* a, m3* b);
void m3_mul_n(m3* out, m3* a, double n);
void m3_premul(m3* out, m3* a, m3* b);
void m3_trans(m3* out, m3* a);
void m3_inv(m3* out, m3* a);
void m3_compose(m3* out, v2* position, double angle, v2* scale);
void m3_decompose(m3* a, v2* position, double* angle, v2* scale)
void m3_apply(m3* a, v2* out);
bool m3_equal(m3* a, m3* b);
bool m3_equal_e(m3* a, m3* b, double e);
bool m3_equal_s(
  m3* a,
  double a00, double a01, double a02,
  double a10, double a11, double a12,
  double a20, double a21, double a22);
bool m3_equal_se(
  m3* a,
  double a00, double a01, double a02,
  double a10, double a11, double a12,
  double a20, double a21, double a22, double e);
bool m3_equal_n(m3* a, double n);
bool m3_equal_ne(m3* a, double n, double e);
```
### m4
```c
/* Getters */
double m4_det(m4* a);
/* Setters */
void m4_set(
  m4* out,
  double a00, double a01, double a02, double a03,
  double a10, double a11, double a12, double a13,
  double a20, double a21, double a22, double a23,
  double a30, double a31, double a32, double a33);
void m4_copy(m4* out, m4* a);
void m4_0(m4* out);
void m4_1(m4* out);
void m4_identity(m4* out);
void m4_move(m4* out, double x, double y, double z);
void m4_rotx(m4* out, double angle);
void m4_roty(m4* out, double angle);
void m4_rotz(m4* out, double angle);
void m4_scale(m4* out, double x, double y, double z);
void m4_project(m4* out, double fov, double aspect, double near, double far);
/* Factories */
m4 m4_new(
  double a00, double a01, double a02, double a03,
  double a10, double a11, double a12, double a13,
  double a20, double a21, double a22, double a23,
  double a30, double a31, double a32, double a33);
m4 m4_new_0();
m4 m4_new_1();
m4 m4_new_identity();
m4 m4_new_move(double x, double y, double z);
m4 m4_new_rotx(double angle);
m4 m4_new_roty(double angle);
m4 m4_new_rotz(double angle);
m4 m4_new_rot(v3* euler, const char order[3]);
m4 m4_new_rot_n(double x, double y, double z, const char order[3]);
m4 m4_new_scale(double x, double y, double z);
m4 m4_new_project(double fov, double aspect, double near, double far);
/* Operations */
void m4_add(m4* out, m4* a, m4* b);
void m4_add_n(m4* out, m4* a, double n);
void m4_sub(m4* out, m4* a, m4* b);
void m4_sub_n(m4* out, m4* a, double n);
void m4_div(m4* out, m4* a, m4* b);
void m4_div_n(m4* out, m4* a, double n);
void m4_mul(m4* out, m4* a, m4* b);
void m4_mul_n(m4* out, m4* a, double n);
void m4_premul(m4* out, m4* a, m4* b);
void m4_inv(m4* out, m4* a);
void m4_compose(m4* out, v3* position, v4* quaternion, v3* scale)
void m4_decompose(m4* a, v3* position, v4* quaternion, v3* scale)
void m4_apply(m4* a, v3* v);
bool m4_equal(m4* a, m4* b);
bool m4_equal_e(m4* a, m4* b, double e);
bool m4_equal_s(
  m4* a,
  double a00, double a01, double a02, double a03,
  double a10, double a11, double a12, double a13,
  double a20, double a21, double a22, double a23,
  double a30, double a31, double a32, double a33);
bool m4_equal_se(
  m4* a,
  double a00, double a01, double a02, double a03,
  double a10, double a11, double a12, double a13,
  double a20, double a21, double a22, double a23,
  double a30, double a31, double a32, double a33, double e);
bool m4_equal_n(m4* a, double n);
bool m4_equal_ne(m4* a, double n, double e);
```
