#include "../include/m3.h"
#include "test.h"

void test_m3() {
  testName("m3");

  m3 a, b, c;
  v2 position, scale, point;
  double angle;

  a = m3_new(1, 2, 3, 4, 5, 6, 7, 8, 9);
  test(
    a.raw[0] == 1 && a.raw[1] == 4 && a.raw[2] == 7 &&
      a.raw[3] == 2 && a.raw[4] == 5 && a.raw[5] == 8 &&
      a.raw[6] == 3 && a.raw[7] == 6 && a.raw[8] == 9,
    "m3.raw");
  test(
    a.index[0][0] == 1 && a.index[0][1] == 4 && a.index[0][2] == 7 &&
      a.index[1][0] == 2 && a.index[1][1] == 5 && a.index[1][2] == 8 &&
      a.index[2][0] == 3 && a.index[2][1] == 6 && a.index[2][2] == 9,
    "m3.index");
  test(
    a.a00 == 1 && a.a01 == 2 && a.a02 == 3 &&
      a.a10 == 4 && a.a11 == 5 && a.a12 == 6 &&
      a.a20 == 7 && a.a21 == 8 && a.a22 == 9,
    "m3.a*");
  test(
    a.m00.a00 == 5 && a.m00.a01 == 6 &&
      a.m00.a10 == 8 && a.m00.a11 == 9 &&
      a.m01.a00 == 4 && a.m01.a01 == 6 &&
      a.m01.a10 == 7 && a.m01.a11 == 9 &&
      a.m02.a00 == 4 && a.m02.a01 == 5 &&
      a.m02.a10 == 7 && a.m02.a11 == 8 &&

      a.m10.a00 == 2 && a.m10.a01 == 3 &&
      a.m10.a10 == 8 && a.m10.a11 == 9 &&
      a.m11.a00 == 1 && a.m11.a01 == 3 &&
      a.m11.a10 == 7 && a.m11.a11 == 9 &&
      a.m12.a00 == 1 && a.m12.a01 == 2 &&
      a.m12.a10 == 7 && a.m12.a11 == 8 &&

      a.m20.a00 == 2 && a.m20.a01 == 3 &&
      a.m20.a10 == 5 && a.m20.a11 == 6 &&
      a.m21.a00 == 1 && a.m21.a01 == 3 &&
      a.m21.a10 == 4 && a.m21.a11 == 6 &&
      a.m22.a00 == 1 && a.m22.a01 == 2 &&
      a.m22.a10 == 4 && a.m22.a11 == 5,

    "m3.m*");

  test(a.column[0].raw[0] == 1 && a.column[0].raw[1] == 4 && a.column[0].raw[2] == 7 &&
         a.column[1].raw[0] == 2 && a.column[1].raw[1] == 5 && a.column[1].raw[2] == 8 &&
         a.column[2].raw[0] == 3 && a.column[2].raw[1] == 6 && a.column[2].raw[2] == 9,
       "m3.column");

  m3_set(
    &a,
    9, 8, 7,
    6, 5, 4,
    3, 2, 1);
  test(m3_equalc(&a, 9, 8, 7, 6, 5, 4, 3, 2, 1), "m3_set");

  m3_copy(&b, &a);
  test(m3_equalc(&b, 9, 8, 7, 6, 5, 4, 3, 2, 1), "m3_copy");

  m3_0(&a);
  m3_zero(&b);
  test(m3_equal1(&a, 0) && m3_equal1(&b, 0), "m3_0/m3_zero");

  m3_1(&a);
  m3_one(&b);
  test(m3_equal1(&a, 1) && m3_equal1(&b, 1), "m3_1/m3_one");

  m3_identity(&a);
  test(m3_equalc(
         &a,
         1, 0, 0,
         0, 1, 0,
         0, 0, 1),
       "m3_identity");

  m3_set(&a, 1, 2, 3, 4, 5, 6, 7, 8, 9);
  m3_set(&b, 2, 3, 4, 5, 6, 7, 8, 9, 10);
  m3_add(&c, &a, &b);
  test(m3_equalc(&c, 3, 5, 7, 9, 11, 13, 15, 17, 19), "m3_add");

  m3_add1(&c, &c, 4);
  test(m3_equalc(&c, 7, 9, 11, 13, 15, 17, 19, 21, 23), "m3_add1");

  m3_set(&a, 1, 2, 3, 4, 5, 6, 7, 8, 9);
  m3_set(&b, 2, 3, 4, 5, 6, 7, 8, 9, 10);

  m3_sub(&c, &b, &a);
  test(m3_equal1(&c, 1), "m3_sub");

  m3_sub1(&c, &c, 1);
  test(m3_equal1(&c, 0), "m3_sub1");

  m3_set(
    &a,
    8, 18, 32,
    50, 72, 98,
    128, 162, 200);
  m3_set(
    &b,
    2, 3, 4,
    5, 6, 7,
    8, 9, 10);

  m3_div(&c, &a, &b);
  test(m3_equalc(
         &c,
         4, 6, 8,
         10, 12, 14,
         16, 18, 20),
       "m3_div");

  m3_div1(&c, &c, 2);
  test(m3_equalc(
         &c,
         2, 3, 4,
         5, 6, 7,
         8, 9, 10),
       "m3_div1");

  m3_set(&a, 1, 2, 3, 4, 5, 6, 7, 8, 9);
  m3_set(&b, 2, 3, 4, 5, 6, 7, 8, 9, 10);

  m3_mulc(&c, &a, &b);
  test(m3_equalc(
         &c,
         2, 6, 12,
         20, 30, 42,
         56, 72, 90),
       "m3_mulc");

  m3_mulc1(&c, &a, 2);
  test(m3_equalc(
         &c,
         2, 4, 6,
         8, 10, 12,
         14, 16, 18),
       "m3_mulc1");

  m3_mul(&c, &a, &b);
  test(m3_equalc(
         &c,
         36, 42, 48,
         81, 96, 111,
         126, 150, 174),
       "m3_mul");

  m3_mul1(&c, &a, 2);
  test(m3_equalc(
         &c,
         2, 2, 3,
         4, 10, 6,
         7, 8, 18),
       "m3_mul1");

  m3_premul(&c, &a, &b);
  test(m3_equalc(
         &c,
         42, 51, 60,
         78, 96, 114,
         114, 141, 168),
       "m3_premul");

  m3_set(
    &a,
    1, 2, 3,
    0, 1, 4,
    5, 6, 0);
  test(m3_det(&a) == 1, "m3_det");

  m3_set(&a, 1, 2, 3, 4, 5, 6, 7, 8, 9);
  m3_trans(&c, &a);
  test(m3_equalc(
         &c,
         1, 4, 7,
         2, 5, 8,
         3, 6, 9),
       "m3_trans");

  m3_set(
    &a,
    1, 2, 3,
    0, 1, 4,
    5, 6, 0);
  m3_inv(&c, &a);
  test(m3_equalc(
         &c,
         -24, 18, 5,
         20, -15, -4,
         -5, 4, 1),
       "m3_inv");

  position = v2_new(10, 20);
  scale = v2_new(2, 3);

  m3_compose(&a, &position, 0, &scale);
  test(m3_equalc(
         &a,
         2, 0, 10,
         0, 3, 20,
         0, 0, 1),
       "m3_compose");

  position = v2_new_0();
  scale = v2_new_0();
  angle = 1;

  m3_decompose(&a, &position, &angle, &scale);
  test(
    position.x == 10 && position.y == 20 &&
      angle == 0 &&
      scale.x == 2 && scale.y == 3,
    "m3_decompose");

  point.x = 4;
  point.y = 5;

  m3_apply(&a, &point);
  test(point.x == 18 && point.y == 35, "m3_apply");
}
