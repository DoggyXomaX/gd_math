#include "v4.h"
#include "test.h"

#include <math.h>
#include <stdbool.h>

void test_v4() {
  testName("v4");

  v4 a, b, c, expected;
  v3 euler;

  a = v4_new(2, 3, 4, 5);
  expected = v4_new(2, 3, 4, 5);
  test(v4_equal(&a, &expected), "v4_new");

  v4_set(&a, 6, 7, 8, 9);
  expected = v4_new(6, 7, 8, 9);
  test(v4_equal(&a, &expected), "v4_set");

  v4_copy(&c, &a);
  expected = v4_new(6, 7, 8, 9);
  test(v4_equal(&c, &expected), "v4_copy");

  v4_0(&a);
  expected = v4_new(0, 0, 0, 0);
  test(v4_equal(&a, &expected), "v4_0");

  a = v4_new_0();
  expected = v4_new(0, 0, 0, 0);
  test(v4_equal(&a, &expected), "v4_new_0");

  v4_1(&a);
  expected = v4_new(1, 1, 1, 1);
  test(v4_equal(&a, &expected), "v4_1");

  a = v4_new_1();
  expected = v4_new(1, 1, 1, 1);
  test(v4_equal(&a, &expected), "v4_new_1");

  a = v4_new_identity();
  expected = v4_new(0, 0, 0, 1);
  test(v4_equal(&a, &expected), "v4_new_identity");

  euler.x = 0;
  euler.y = 0;
  euler.z = 0;

  v4_euler(&a, &euler);
  expected = v4_new(0, 0, 0, 1);
  test(v4_equal_e(&a, &expected, 0.000001), "v4_euler identity");

  a = v4_new_euler(0, 0, 0);
  expected = v4_new(0, 0, 0, 1);
  test(v4_equal_e(&a, &expected, 0.000001), "v4_new_euler identity");

  euler.x = acos(-1.0) * 0.5;
  euler.y = 0;
  euler.z = 0;

  v4_euler(&a, &euler);
  expected = v4_new(sqrt(0.5), 0, 0, sqrt(0.5));
  test(v4_equal_e(&a, &expected, 0.000001), "v4_euler x");

  a = v4_new_euler(acos(-1.0) * 0.5, 0, 0);
  expected = v4_new(sqrt(0.5), 0, 0, sqrt(0.5));
  test(v4_equal_e(&a, &expected, 0.000001), "v4_new_euler x");

  a = v4_new(2, 3, 4, 5);
  v4_neg(&c, &a);
  expected = v4_new(-2, -3, -4, -5);
  test(v4_equal(&c, &expected), "v4_neg");

  a = v4_new(2, 3, 4, 5);
  b = v4_new(6, 7, 8, 9);
  v4_add(&c, &a, &b);
  expected = v4_new(8, 10, 12, 14);
  test(v4_equal(&c, &expected), "v4_add");

  a = v4_new(2, 3, 4, 5);
  v4_add_n(&c, &a, 6);
  expected = v4_new(8, 9, 10, 11);
  test(v4_equal(&c, &expected), "v4_add_n");

  a = v4_new(6, 7, 8, 9);
  b = v4_new(2, 3, 4, 5);
  v4_sub(&c, &a, &b);
  expected = v4_new(4, 4, 4, 4);
  test(v4_equal(&c, &expected), "v4_sub");

  a = v4_new(6, 7, 8, 9);
  v4_sub_n(&c, &a, 2);
  expected = v4_new(4, 5, 6, 7);
  test(v4_equal(&c, &expected), "v4_sub_n");

  a = v4_new(2, 3, 4, 5);
  b = v4_new(6, 7, 8, 9);
  v4_mul(&c, &a, &b);
  expected = v4_new(12, 21, 32, 45);
  test(v4_equal(&c, &expected), "v4_mul");

  a = v4_new(2, 3, 4, 5);
  v4_mul_n(&c, &a, 6);
  expected = v4_new(12, 18, 24, 30);
  test(v4_equal(&c, &expected), "v4_mul_n");

  a = v4_new(12, 21, 32, 45);
  b = v4_new(6, 7, 8, 9);
  v4_div(&c, &a, &b);
  expected = v4_new(2, 3, 4, 5);
  test(v4_equal(&c, &expected), "v4_div");

  a = v4_new(12, 18, 24, 30);
  v4_div_n(&c, &a, 6);
  expected = v4_new(2, 3, 4, 5);
  test(v4_equal(&c, &expected), "v4_div_n");

  a = v4_new(2, 3, 4, 5);
  test(v4_slen(&a) == 54, "v4_slen");

  a = v4_new(2, 3, 4, 5);
  test(fabs(v4_len(&a) - sqrt(54)) < 0.000001, "v4_len");

  a = v4_new(2, 3, 4, 5);
  b = v4_new(6, 7, 8, 9);
  test(v4_dot(&a, &b) == 110, "v4_dot");

  a = v4_new(2, 3, 4, 5);
  b = v4_new(2, 3, 4, 5);
  test(v4_equal(&a, &b), "v4_equal true");

  b = v4_new(2, 3, 4, 6);
  test(!v4_equal(&a, &b), "v4_equal false");

  a = v4_new(2, 3, 4, 5);
  b = v4_new(2.000001, 3.000001, 4.000001, 5.000001);
  test(v4_equal_e(&a, &b, 0.00001), "v4_equal_e true");

  b = v4_new(2.01, 3, 4, 5);
  test(!v4_equal_e(&a, &b, 0.00001), "v4_equal_e false");
}
