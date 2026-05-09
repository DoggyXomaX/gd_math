#include "../include/m2.h"
#include "test.h"

#include <math.h>

void test_m2() {
  testName("m2");

  m2 a, b, c;

  a = m2_new(1, 2, 3, 4);
  test(a.raw[0] == 1 && a.raw[1] == 3 && a.raw[2] == 2 && a.raw[3] == 4, "m2.raw");
  test(a.index[0][0] == 1 && a.index[0][1] == 3 && a.index[1][0] == 2 && a.index[1][1] == 4, "m2.index");
  test(a.a00 == 1 && a.a01 == 2 && a.a10 == 3 && a.a11 == 4, "m2.a*");
  test(a.m00 == a.a11 && a.m01 == a.a10 && a.m10 == a.a01 && a.m11 == a.a00, "m2.m*");
  test(a.column[0].raw[0] == 1 && a.column[0].raw[1] == 3 && a.column[1].raw[0] == 2 && a.column[1].raw[1] == 4, "m2.column");

  m2_0(&a);
  m2_zero(&b);
  test(m2_equal1(&a, 0) && m2_equal1(&b, 0), "m2_0/m2_zero");

  m2_1(&a);
  m2_one(&b);
  test(m2_equal1(&a, 1) && m2_equal1(&b, 1), "m2_1/m2_one");

  m2_set(&a, 4, 5, 6, 7);
  test(m2_equalc(&a, 4, 5, 6, 7), "m2_set");

  m2_copy(&b, &a);
  test(m2_equal(&b, &a), "m2_copy");

  m2_identity(&a);
  test(m2_equalc(&a, 1, 0, 0, 1), "m2_identity");

  a = m2_new(1, 2, 3, 4);
  b = m2_new(5, 6, 7, 8);
  m2_add(&c, &a, &b);
  test(m2_equalc(&c, 6, 8, 10, 12), "m2_add");

  a = m2_new(1, 2, 3, 4);
  m2_add1(&c, &a, 10);
  test(m2_equalc(&c, 11, 12, 13, 14), "m2_add1");

  a = m2_new(1, 2, 3, 4);
  b = m2_new(5, 6, 7, 8);
  m2_sub(&c, &a, &b);
  test(m2_equalc(&c, -4, -4, -4, -4), "m2_sub");

  a = m2_new(1, 2, 3, 4);
  m2_sub1(&c, &a, 10);
  test(m2_equalc(&c, -9, -8, -7, -6), "m2_sub1");

  a = m2_new(1, 2, 3, 4);
  b = m2_new(5, 6, 7, 8);
  m2_div(&c, &a, &b);
  test(
    fabs(c.a00 - 1.0 / 5.0) < 0.000001 &&
      fabs(c.a01 - 2.0 / 6.0) < 0.000001 &&
      fabs(c.a10 - 3.0 / 7.0) < 0.000001 &&
      fabs(c.a11 - 4.0 / 8.0) < 0.000001,
    "m2_div");

  a = m2_new(1, 2, 3, 4);
  m2_div1(&c, &a, 2);
  test(m2_equalc(&c, 0.5, 1, 1.5, 2), "m2_div1");

  a = m2_new(1, 2, 3, 4);
  b = m2_new(5, 6, 7, 8);
  m2_mulc(&c, &a, &b);
  test(m2_equalc(&c, 5, 12, 21, 32), "m2_mulc");

  a = m2_new(1, 2, 3, 4);
  m2_mulc1(&c, &a, 2);
  test(m2_equalc(&c, 2, 4, 6, 8), "m2_mulc1");

  a = m2_new(1, 2, 3, 4);
  b = m2_new(5, 6, 7, 8);
  m2_mul(&c, &a, &b);
  test(m2_equalc(&c, 19, 22, 43, 50), "m2_mul");

  a = m2_new(1, 2, 3, 4);
  m2_mul1(&c, &a, 2);
  test(m2_equalc(&c, 2, 2, 3, 8), "m2_mul1");

  a = m2_new(1, 2, 3, 4);
  b = m2_new(5, 6, 7, 8);
  m2_premul(&c, &a, &b);
  test(m2_equalc(&c, 23, 34, 31, 46), "m2_premul");

  a = m2_new(1, 2, 3, 4);
  m2_trans(&c, &a);
  test(m2_equalc(&c, 1, 3, 2, 4), "m2_trans");

  a = m2_new(1, 2, 3, 4);
  m2_inv(&c, &a);
  test(
    fabs(c.a00 - -2.0) < 0.000001 &&
      fabs(c.a01 - 1.0) < 0.000001 &&
      fabs(c.a10 - 1.5) < 0.000001 &&
      fabs(c.a11 - -0.5) < 0.000001,
    "m2_inv");

  a = m2_new(1, 2, 3, 4);
  test(m2_det(&a) == -2, "m2_det");
}
