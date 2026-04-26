# GameDev math

## Description
Custom header-only GameDev math library for study purposes.

## Classes
Available: v2, v2f, v3, v3f, v4, v4f

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

## Notation in README
> **type** - represents math class
>
> **typeN** (**type3**, ...) - represents math class dimension (Example: type3, type2)
>
> **number** - represents class number type
>
> Example with v3f class:
> ```c
> type add1(type a, number n);
> ```
> will be
> ```c
> v3f v3f_add1(v3f a, float n);
> ```

## Values/Getters
### v2
```c
number x, y;
number u, v;
number width, height;
number raw[2]; // v.raw[0], v.raw[1]
```
### v3
```c
number x, y, z;
number u, v, w;
number r, g, b;
number width, height, length;
number raw[3]; // v.raw[0], v.raw[1], v.raw[2]
type2 xy, yz;
```
### v4
```c
number x, y, z, w;
number r, g, b, a;
number raw[4]; // v.raw[0], v.raw[1], v.raw[2], v.raw[3]
type3 xyz, yzw;
type3 rgb;
type2 xy, yz, zw;
```
### m2
```c
number a00, a10, a01, a11;
type2 column[2];
number index[2][2];
number raw[4];
```
### m3
```c
number a00, a10, a20, a01, a11, a21, a02, a12, a22;
type3 column[3];
number index[3][3];
number raw[9];
```
### m4
```c
number a00, a10, a20, a30, a01, a11, a21, a31, a02, a12, a22, a32, a03, a13, a23, a33;
type4 column[4];
number index[4][4];
number raw[16];
```

## Methods
### v2
```c
type new(number x, number y);
type 0();
type zero();
type 1();
type one();
type neg(type a);
bool equal(type a, type b);
bool equale(type a, type b, number e);
type add(type a, type b);
type sub(type a, type b);
type mul(type a, type b);
type mul1(type a, number n);
type div(type a, type b);
type div1(type a, number n);
number slen(type a);
number len(type a);
number dot(type a, type b);
number cross(type a, type b);
```
### v3
```c
type new(number x, number y, number z);
type 0();
type zero();
type 1();
type one();
type right();
type left();
type up();
type down();
type front();
type back();
type neg(type a);
type add(type a, type b);
type add1(type a, number n);
type sub(type a, type b);
type sub1(type a, number n);
type mul(type a, type b);
type mul1(type a, number n);
type div(type a, type b);
type div1(type a, number n);
number slen(type a);
number len(type a);
number dot(type a, type b);
type cross(type a, type b);
```
### v4
```c
type new(number x, number y, number z, number w);
type 0();
type zero();
type 1();
type one();
type neg();
type add(type a, type b);
type add1(type a, number n);
type sub(type a, type b);
type sub1(type a, number n);
type mul(type a, type b);
type mul1(type a, number n);
type div(type a, type b);
type div1(type a, number n);
number slen(type a);
number len(type a);
number dot(type a, type b);
```
### m2
```c
type new(number a00, number a01, number a10, number a11);
void set(type* out, number a00, number a01, number a10, number a11);
void copy(type* out, type* a);
void identity(type* out);
void 0(type* out);
void zero(type* out);
void 1(type* out);
void one(type* out);
void add(type* out, type* a, type* b);
void add1(type* out, type* a, number n);
void sub(type* out, type* a, type* b);
void sub1(type* out, type* a, number n);
void div(type* out, type* a, type* b);
void div1(type* out, type* a, number n);
void mulc(type* out, type* a, type* b);
void mulc1(type* out, type* a, number n);
void mul(type* out, type* a, type* b);
void mul1(type* out, type* a, number n);
void premul(type* out, type* a, type* b);
void trans(type* out, type* a);
void inv(type* out, type* a);
number det(type* a);
```
### m3
```c
type new(
  number a00, number a01, number a02,
  number a10, number a11, number a12,
  number a20, number a21, number a22);
void set(
  type* out,
  number a00, number a01, number a02,
  number a10, number a11, number a12,
  number a20, number a21, number a22);
void copy(type* out, type* a);
void identity(type* out);
void 0(type* out);
void zero(type* out);
void 1(type* out);
void one(type* out);
void add(type* out, type* a, type* b);
void add1(type* out, type* a, number n);
void sub(type* out, type* a, type* b);
void sub1(type* out, type* a, number n);
void div(type* out, type* a, type* b);
void div1(type* out, type* a, number n);
void mulc(type* out, type* a, type* b);
void mulc1(type* out, type* a, number n);
void mul(type* out, type* a, type* b);
void mul1(type* out, type* a, number n);
void premul(type* out, type* a, type* b);
number det(type* a);
void trans(type* out, type* a);
void inv(type* out, type* a);
void compose(type* out, type2* position, number angle, type2* scale);
void decompose(type* a, type2* position, number* angle, type2* scale);
void apply(type* a, type2* out);
```
### m4
```c
type new(
  number a00, number a01, number a02, number a03,
  number a10, number a11, number a12, number a13,
  number a20, number a21, number a22, number a23,
  number a30, number a31, number a32, number a33);
void set(
  type* out,
  number a00, number a01, number a02, number a03,
  number a10, number a11, number a12, number a13,
  number a20, number a21, number a22, number a23,
  number a30, number a31, number a32, number a33);
void copy(type* out, type* a);
void identity(type* out);
void 0(type* out);
void zero(type* out);
void 1(type* out);
void one(type* out);
void add(type* out, type* a, type* b);
void add1(type* out, type* a, number n);
void sub(type* out, type* a, type* b);
void sub1(type* out, type* a, number n);
void div(type* out, type* a, type* b);
void div1(type* out, type* a, number n);
void mulc(type* out, type* a, type* b);
void mulc1(type* out, type* a, number n);
void mul(type* out, type* a, type* b);
void mul1(type* out, type* a, number n);
void premul(type* out, type* a, type* b);
number det(type* a);
void inv(type* out, type* a);
void compose(type* out, type3* position, type4* quaternion, type3* scale);
void decompose(type* a, type3* position, type4* quaternion, type3* scale);
void apply(type* a, type3* v);
```
