#include "../include/v4.h"
#include "test.h"

#include <math.h>

void test_v4() {
  testName("v4");

  v4 a, b, c;

  a = v4_new(2, 3, 4, 5);
  test(a.x == 2 && a.y == 3 && a.z == 4 && a.w == 5, "v4_new");

  a = v4_0();
  test(a.x == 0 && a.y == 0 && a.z == 0 && a.w == 0, "v4_0");

  a = v4_zero();
  test(a.x == 0 && a.y == 0 && a.z == 0 && a.w == 0, "v4_zero");

  a = v4_1();
  test(a.x == 1 && a.y == 1 && a.z == 1 && a.w == 1, "v4_1");

  a = v4_one();
  test(a.x == 1 && a.y == 1 && a.z == 1 && a.w == 1, "v4_one");

  a = v4_new(2, 3, 4, 5);
  c = v4_neg(a);
  test(c.x == -2 && c.y == -3 && c.z == -4 && c.w == -5, "v4_neg");

  a = v4_new(2, 3, 4, 5);
  b = v4_new(6, 7, 8, 9);
  c = v4_add(a, b);
  test(c.x == 8 && c.y == 10 && c.z == 12 && c.w == 14, "v4_add");

  a = v4_new(2, 3, 4, 5);
  c = v4_add1(a, 6);
  test(c.x == 8 && c.y == 9 && c.z == 10 && c.w == 11, "v4_add1");

  a = v4_new(6, 7, 8, 9);
  b = v4_new(2, 3, 4, 5);
  c = v4_sub(a, b);
  test(c.x == 4 && c.y == 4 && c.z == 4 && c.w == 4, "v4_sub");

  a = v4_new(6, 7, 8, 9);
  c = v4_sub1(a, 2);
  test(c.x == 4 && c.y == 5 && c.z == 6 && c.w == 7, "v4_sub1");

  a = v4_new(2, 3, 4, 5);
  b = v4_new(6, 7, 8, 9);
  c = v4_mul(a, b);
  test(c.x == 12 && c.y == 21 && c.z == 32 && c.w == 45, "v4_mul");

  a = v4_new(2, 3, 4, 5);
  c = v4_mul1(a, 6);
  test(c.x == 12 && c.y == 18 && c.z == 24 && c.w == 30, "v4_mul1");

  a = v4_new(12, 21, 32, 45);
  b = v4_new(6, 7, 8, 9);
  c = v4_div(a, b);
  test(c.x == 2 && c.y == 3 && c.z == 4 && c.w == 5, "v4_div");

  a = v4_new(12, 18, 24, 30);
  c = v4_div1(a, 6);
  test(c.x == 2 && c.y == 3 && c.z == 4 && c.w == 5, "v4_div1");

  a = v4_new(2, 3, 4, 5);
  test(v4_slen(a) == 54, "v4_slen");

  a = v4_new(2, 3, 4, 5);
  test(fabs(v4_len(a) - sqrt(54)) < 0.000001, "v4_len");

  a = v4_new(2, 3, 4, 5);
  b = v4_new(6, 7, 8, 9);
  test(v4_dot(a, b) == 110, "v4_dot");
}
