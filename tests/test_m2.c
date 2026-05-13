#include "m2.h"
#include "test.h"

void test_m2() {
  testName("m2");

  m2 a, b, c, expected;

  a = m2_new(1, 2, 3, 4);
  test(a.raw[0] == 1 && a.raw[1] == 3 && a.raw[2] == 2 && a.raw[3] == 4, "m2.raw");
  test(a.index[0][0] == 1 && a.index[0][1] == 3 && a.index[1][0] == 2 && a.index[1][1] == 4, "m2.index");
  test(a.a00 == 1 && a.a01 == 2 && a.a10 == 3 && a.a11 == 4, "m2.a*");
  test(a.m00 == a.a11 && a.m01 == a.a10 && a.m10 == a.a01 && a.m11 == a.a00, "m2.m*");
  test(a.column[0].raw[0] == 1 && a.column[0].raw[1] == 3 && a.column[1].raw[0] == 2 && a.column[1].raw[1] == 4, "m2.column");

  a = m2_new(1, 2, 3, 4);
  expected = m2_new(1, 2, 3, 4);
  test(m2_equal(&a, &expected), "m2_new");

  m2_set(&a, 4, 5, 6, 7);
  expected = m2_new(4, 5, 6, 7);
  test(m2_equal(&a, &expected), "m2_set");

  m2_copy(&b, &a);
  test(m2_equal(&b, &a), "m2_copy");

  m2_0(&a);
  test(m2_equal_n(&a, 0), "m2_0");

  a = m2_new_0();
  test(m2_equal_n(&a, 0), "m2_new_0");

  m2_1(&a);
  test(m2_equal_n(&a, 1), "m2_1");

  a = m2_new_1();
  test(m2_equal_n(&a, 1), "m2_new_1");

  m2_identity(&a);
  test(m2_equal_s(&a, 1, 0, 0, 1), "m2_identity");

  a = m2_new_identity();
  test(m2_equal_s(&a, 1, 0, 0, 1), "m2_new_identity");

  a = m2_new(1, 2, 3, 4);
  b = m2_new(5, 6, 7, 8);
  m2_add(&c, &a, &b);
  test(m2_equal_s(&c, 6, 8, 10, 12), "m2_add");

  a = m2_new(1, 2, 3, 4);
  m2_add_n(&c, &a, 10);
  test(m2_equal_s(&c, 11, 12, 13, 14), "m2_add_n");

  a = m2_new(1, 2, 3, 4);
  b = m2_new(5, 6, 7, 8);
  m2_sub(&c, &a, &b);
  test(m2_equal_s(&c, -4, -4, -4, -4), "m2_sub");

  a = m2_new(1, 2, 3, 4);
  m2_sub_n(&c, &a, 10);
  test(m2_equal_s(&c, -9, -8, -7, -6), "m2_sub_n");

  a = m2_new(1, 2, 3, 4);
  b = m2_new(5, 6, 7, 8);
  m2_div(&c, &a, &b);
  test(m2_equal_se(&c, 1.0 / 5.0, 2.0 / 6.0, 3.0 / 7.0, 4.0 / 8.0, 0.000001), "m2_div");

  a = m2_new(1, 2, 3, 4);
  m2_div_n(&c, &a, 2);
  test(m2_equal_s(&c, 0.5, 1, 1.5, 2), "m2_div_n");

  a = m2_new(1, 2, 3, 4);
  b = m2_new(5, 6, 7, 8);
  m2_mul(&c, &a, &b);
  test(m2_equal_s(&c, 19, 22, 43, 50), "m2_mul");

  a = m2_new(1, 2, 3, 4);
  m2_mul_n(&c, &a, 2);
  test(m2_equal_s(&c, 2, 4, 6, 8), "m2_mul_n");

  a = m2_new(1, 2, 3, 4);
  b = m2_new(5, 6, 7, 8);
  m2_premul(&c, &a, &b);
  test(m2_equal_s(&c, 23, 34, 31, 46), "m2_premul");

  a = m2_new(1, 2, 3, 4);
  m2_trans(&c, &a);
  test(m2_equal_s(&c, 1, 3, 2, 4), "m2_trans");

  a = m2_new(1, 2, 3, 4);
  m2_inv(&c, &a);
  test(m2_equal_se(&c, -2, 1, 1.5, -0.5, 0.000001), "m2_inv");

  a = m2_new(1, 2, 3, 4);
  test(m2_det(&a) == -2, "m2_det");

  a = m2_new(1, 2, 3, 4);
  b = m2_new(1, 2, 3, 4);
  test(m2_equal(&a, &b), "m2_equal true");

  b = m2_new(1, 2, 3, 5);
  test(!m2_equal(&a, &b), "m2_equal false");

  a = m2_new(1, 2, 3, 4);
  b = m2_new(1.000001, 2.000001, 3.000001, 4.000001);
  test(m2_equal_e(&a, &b, 0.00001), "m2_equal_e true");

  b = m2_new(1.01, 2, 3, 4);
  test(!m2_equal_e(&a, &b, 0.00001), "m2_equal_e false");

  a = m2_new(1, 2, 3, 4);
  test(m2_equal_s(&a, 1, 2, 3, 4), "m2_equal_s true");
  test(!m2_equal_s(&a, 1, 2, 3, 5), "m2_equal_s false");

  a = m2_new(1, 2, 3, 4);
  test(m2_equal_se(&a, 1.000001, 2.000001, 3.000001, 4.000001, 0.00001), "m2_equal_se true");
  test(!m2_equal_se(&a, 1.01, 2, 3, 4, 0.00001), "m2_equal_se false");

  a = m2_new(7, 7, 7, 7);
  test(m2_equal_n(&a, 7), "m2_equal_n true");

  a = m2_new(7, 7, 7, 8);
  test(!m2_equal_n(&a, 7), "m2_equal_n false");

  a = m2_new(7.000001, 7.000001, 7.000001, 7.000001);
  test(m2_equal_ne(&a, 7, 0.00001), "m2_equal_ne true");

  a = m2_new(7.01, 7, 7, 7);
  test(!m2_equal_ne(&a, 7, 0.00001), "m2_equal_ne false");
}
