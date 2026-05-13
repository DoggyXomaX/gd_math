#include "m3.h"
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
  test(m3_equal_s(&a, 9, 8, 7, 6, 5, 4, 3, 2, 1), "m3_set");

  m3_copy(&b, &a);
  test(m3_equal_s(&b, 9, 8, 7, 6, 5, 4, 3, 2, 1), "m3_copy");

  m3_0(&a);
  test(m3_equal_n(&a, 0), "m3_0");

  m3_1(&a);
  test(m3_equal_n(&a, 1), "m3_1");

  m3_identity(&a);
  test(m3_equal_s(
         &a,
         1, 0, 0,
         0, 1, 0,
         0, 0, 1),
       "m3_identity");

  a = m3_new_0();
  test(m3_equal_n(&a, 0), "m3_new_0");

  a = m3_new_1();
  test(m3_equal_n(&a, 1), "m3_new_1");

  a = m3_new_identity();
  test(m3_equal_s(
         &a,
         1, 0, 0,
         0, 1, 0,
         0, 0, 1),
       "m3_new_identity");

  a = m3_new_move(10, 20);
  test(m3_equal_s(
         &a,
         1, 0, 10,
         0, 1, 20,
         0, 0, 1),
       "m3_new_move");

  a = m3_new_rotate(0);
  test(m3_equal_s(
         &a,
         1, 0, 0,
         0, 1, 0,
         0, 0, 1),
       "m3_new_rotate");

  a = m3_new_scale(2, 3);
  test(m3_equal_s(
         &a,
         2, 0, 0,
         0, 3, 0,
         0, 0, 1),
       "m3_new_scale");

  m3_move(&a, 10, 20);
  test(m3_equal_s(
         &a,
         1, 0, 10,
         0, 1, 20,
         0, 0, 1),
       "m3_move");

  m3_rotate(&a, 0);
  test(m3_equal_s(
         &a,
         1, 0, 0,
         0, 1, 0,
         0, 0, 1),
       "m3_rotate");

  m3_scale(&a, 2, 3);
  test(m3_equal_s(
         &a,
         2, 0, 0,
         0, 3, 0,
         0, 0, 1),
       "m3_scale");

  m3_set(&a, 1, 2, 3, 4, 5, 6, 7, 8, 9);
  m3_set(&b, 2, 3, 4, 5, 6, 7, 8, 9, 10);
  m3_add(&c, &a, &b);
  test(m3_equal_s(&c, 3, 5, 7, 9, 11, 13, 15, 17, 19), "m3_add");

  m3_add_n(&c, &c, 4);
  test(m3_equal_s(&c, 7, 9, 11, 13, 15, 17, 19, 21, 23), "m3_add_n");

  m3_set(&a, 1, 2, 3, 4, 5, 6, 7, 8, 9);
  m3_set(&b, 2, 3, 4, 5, 6, 7, 8, 9, 10);

  m3_sub(&c, &b, &a);
  test(m3_equal_n(&c, 1), "m3_sub");

  m3_sub_n(&c, &c, 1);
  test(m3_equal_n(&c, 0), "m3_sub_n");

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
  test(m3_equal_s(
         &c,
         4, 6, 8,
         10, 12, 14,
         16, 18, 20),
       "m3_div");

  m3_div_n(&c, &c, 2);
  test(m3_equal_s(
         &c,
         2, 3, 4,
         5, 6, 7,
         8, 9, 10),
       "m3_div_n");

  m3_set(&a, 1, 2, 3, 4, 5, 6, 7, 8, 9);
  m3_set(&b, 2, 3, 4, 5, 6, 7, 8, 9, 10);

  m3_mul(&c, &a, &b);
  test(m3_equal_s(
         &c,
         36, 42, 48,
         81, 96, 111,
         126, 150, 174),
       "m3_mul");

  m3_mul_n(&c, &a, 2);
  test(m3_equal_s(
         &c,
         2, 4, 6,
         8, 10, 12,
         14, 16, 18),
       "m3_mul_n");

  m3_premul(&c, &a, &b);
  test(m3_equal_s(
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
  test(m3_equal_s(
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
  test(m3_equal_s(
         &c,
         -24, 18, 5,
         20, -15, -4,
         -5, 4, 1),
       "m3_inv");

  position = v2_new(10, 20);
  scale = v2_new(2, 3);

  m3_compose(&a, &position, 0, &scale);
  test(m3_equal_s(
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

  point = v2_new(4, 5);

  m3_apply(&a, &point);
  test(point.x == 18 && point.y == 35, "m3_apply");

  m3_set(&a, 1, 2, 3, 4, 5, 6, 7, 8, 9);
  b = m3_new(1, 2, 3, 4, 5, 6, 7, 8, 9);
  test(m3_equal(&a, &b), "m3_equal");

  b = m3_new(
    1.001, 2.001, 3.001,
    4.001, 5.001, 6.001,
    7.001, 8.001, 9.001);
  test(m3_equal_e(&a, &b, 0.01), "m3_equal_e");

  test(m3_equal_s(
         &a,
         1, 2, 3,
         4, 5, 6,
         7, 8, 9),
       "m3_equal_s");

  test(m3_equal_se(
         &a,
         1.001, 2.001, 3.001,
         4.001, 5.001, 6.001,
         7.001, 8.001, 9.001,
         0.01),
       "m3_equal_se");

  m3_1(&a);
  test(m3_equal_n(&a, 1), "m3_equal_n");

  a = m3_new(
    1.001, 1.001, 1.001,
    1.001, 1.001, 1.001,
    1.001, 1.001, 1.001);
  test(m3_equal_ne(&a, 1, 0.01), "m3_equal_ne");
}
