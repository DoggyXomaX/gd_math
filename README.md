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

## Vector2
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

## Vector3
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

## Vector4
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
