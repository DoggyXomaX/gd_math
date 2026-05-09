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
struct { double a00, a10, a20, a01, a11, a21, a02, a12, a22 } m00, m01, m02, m10, m11, m12, m20, m21, m22; // Sub matrices 3x3
v4 column[4];
double index[4][4];
double raw[16];
```

## Methods
### v2
```c
v2 v2_new(double x, double y);
v2 v2_0();
v2 v2_zero();
v2 v2_1();
v2 v2_one();
v2 v2_neg(v2 a);
bool v2_equal(v2 a, v2 b);
bool v2_equale(v2 a, v2 b, double e);
v2 v2_add(v2 a, v2 b);
v2 v2_sub(v2 a, v2 b);
v2 v2_mul(v2 a, v2 b);
v2 v2_mul1(v2 a, double n);
v2 v2_div(v2 a, v2 b);
v2 v2_div1(v2 a, double n);
double v2_slen(v2 a);
double v2_len(v2 a);
double v2_dot(v2 a, v2 b);
double v2_cross(v2 a, v2 b);
```
### v3
```c
v3 v3_new(double x, double y, double z);
v3 v3_0();
v3 v3_zero();
v3 v3_1();
v3 v3_one();
v3 v3_right();
v3 v3_left();
v3 v3_up();
v3 v3_down();
v3 v3_front();
v3 v3_back();
v3 v3_neg(v3 a);
v3 v3_add(v3 a, v3 b);
v3 v3_add1(v3 a, double n);
v3 v3_sub(v3 a, v3 b);
v3 v3_sub1(v3 a, double n);
v3 v3_mul(v3 a, v3 b);
v3 v3_mul1(v3 a, double n);
v3 v3_div(v3 a, v3 b);
v3 v3_div1(v3 a, double n);
double v3_slen(v3 a);
double v3_len(v3 a);
double v3_dot(v3 a, v3 b);
v3 v3_cross(v3 a, v3 b);
```
### v4
```c
v4 v4_new(double x, double y, double z, double w);
v4 v4_0();
v4 v4_zero();
v4 v4_1();
v4 v4_one();
v4 v4_neg();
v4 v4_add(v4 a, v4 b);
v4 v4_add1(v4 a, double n);
v4 v4_sub(v4 a, v4 b);
v4 v4_sub1(v4 a, double n);
v4 v4_mul(v4 a, v4 b);
v4 v4_mul1(v4 a, double n);
v4 v4_div(v4 a, v4 b);
v4 v4_div1(v4 a, double n);
double v4_slen(v4 a);
double v4_len(v4 a);
double v4_dot(v4 a, v4 b);
```
### m2
```c
m2 m2_new(double a00, double a01, double a10, double a11);
void m2_set(m2* out, double a00, double a01, double a10, double a11);
void m2_copy(m2* out, m2* a);
void m2_identity(m2* out);
void m2_0(m2* out);
void m2_zero(m2* out);
void m2_1(m2* out);
void m2_one(m2* out);
void m2_add(m2* out, m2* a, m2* b);
void m2_add1(m2* out, m2* a, double n);
void m2_sub(m2* out, m2* a, m2* b);
void m2_sub1(m2* out, m2* a, double n);
void m2_div(m2* out, m2* a, m2* b);
void m2_div1(m2* out, m2* a, double n);
void m2_mulc(m2* out, m2* a, m2* b);
void m2_mulc1(m2* out, m2* a, double n);
void m2_mul(m2* out, m2* a, m2* b);
void m2_mul1(m2* out, m2* a, double n);
void m2_premul(m2* out, m2* a, m2* b);
void m2_trans(m2* out, m2* a);
void m2_inv(m2* out, m2* a);
double m2_det(m2* a);
int m2_equal(m2* a, m2* b);
int m2_equalc(m2* a, m2 a00, m2 a01, m2 a10, m2 a11);
int m2_equal1(m2* a, double n);
```
### m3
```c
m3 m3_new(
  double a00, double a01, double a02,
  double a10, double a11, double a12,
  double a20, double a21, double a22);
void m3_set(
  m3* out,
  double a00, double a01, double a02,
  double a10, double a11, double a12,
  double a20, double a21, double a22);
void m3_copy(m3* out, m3* a);
void m3_identity(m3* out);
void m3_0(m3* out);
void m3_zero(m3* out);
void m3_1(m3* out);
void m3_one(m3* out);
void m3_add(m3* out, m3* a, m3* b);
void m3_add1(m3* out, m3* a, double n);
void m3_sub(m3* out, m3* a, m3* b);
void m3_sub1(m3* out, m3* a, double n);
void m3_div(m3* out, m3* a, m3* b);
void m3_div1(m3* out, m3* a, double n);
void m3_mulc(m3* out, m3* a, m3* b);
void m3_mulc1(m3* out, m3* a, double n);
void m3_mul(m3* out, m3* a, m3* b);
void m3_mul1(m3* out, m3* a, double n);
void m3_premul(m3* out, m3* a, m3* b);
double m3_det(m3* a);
void m3_trans(m3* out, m3* a);
void m3_inv(m3* out, m3* a);
void m3_compose(m3* out, v2* position, double angle, v2* scale);
void m3_decompose(m3* a, v2* position, double* angle, v2* scale);
void m3_apply(m3* a, v2* out);
int m3_equal(name* a, name* b);
int m3_equalc(m3* a,
  double a00, double a01, double a02,
  double a10, double a11, double a12,
  double a20, double a21, double a22);
int m3_equal1(m3* a, double n);
```
### m4
```c
m4 m4_new(
  double a00, double a01, double a02, double a03,
  double a10, double a11, double a12, double a13,
  double a20, double a21, double a22, double a23,
  double a30, double a31, double a32, double a33);
void m4_set(
  m4* out,
  double a00, double a01, double a02, double a03,
  double a10, double a11, double a12, double a13,
  double a20, double a21, double a22, double a23,
  double a30, double a31, double a32, double a33);
void m4_copy(m4* out, m4* a);
void m4_identity(m4* out);
void m4_0(m4* out);
void m4_zero(m4* out);
void m4_1(m4* out);
void m4_one(m4* out);
void m4_add(m4* out, m4* a, m4* b);
void m4_add1(m4* out, m4* a, double n);
void m4_sub(m4* out, m4* a, m4* b);
void m4_sub1(m4* out, m4* a, double n);
void m4_div(m4* out, m4* a, m4* b);
void m4_div1(m4* out, m4* a, double n);
void m4_mulc(m4* out, m4* a, m4* b);
void m4_mulc1(m4* out, m4* a, double n);
void m4_mul(m4* out, m4* a, m4* b);
void m4_mul1(m4* out, m4* a, double n);
void m4_premul(m4* out, m4* a, m4* b);
double m4_det(m4* a);
void m4_inv(m4* out, m4* a);
void m4_compose(m4* out, v3* position, v4* quaternion, v3* scale);
void m4_decompose(m4* a, v3* position, v4* quaternion, v3* scale);
void m4_apply(m4* a, v3* v)
int m4_equal(m4* a, m4* b);
int m4_equalc(m4* a,
  double a00, double a01, double a02, double a03,
  double a10, double a11, double a12, double a13,
  double a20, double a21, double a22, double a23,
  double a30, double a31, double a32, double a33);
int m4_equal1(m4* a, double n);
```
