#include "../include/v3.h"
#include "test.h"

void test_v3() {
  testName("v3");

  v3 a, b, c;

  a = v3_0();
  b = v3_zero();
  test(a.x == 0 && a.y == 0 && a.z == 0 && b.x == 0 && b.y == 0 && b.z == 0, "v3_0/v3_zero");

  a = v3_1();
  b = v3_one();
  test(a.x == 1 && a.y == 1 && a.z == 1 && b.x == 1 && b.y == 1 && b.z == 1, "v3_1/v3_one");

  a = v3_right();
  test(a.x == 1 && a.y == 0 && a.z == 0, "v3_right");

  a = v3_left();
  test(a.x == -1 && a.y == 0 && a.z == 0, "v3_left");

  a = v3_up();
  test(a.x == 0 && a.y == 1 && a.z == 0, "v3_up");

  a = v3_down();
  test(a.x == 0 && a.y == -1 && a.z == 0, "v3_down");

  a = v3_front();
  test(a.x == 0 && a.y == 0 && a.z == 1, "v3_front");

  a = v3_back();
  test(a.x == 0 && a.y == 0 && a.z == -1, "v3_back");

  a = v3_new(2, 3, 4);
  c = v3_neg(a);
  test(c.x == -2 && c.y == -3 && c.z == -4, "v3_neg");

  a = v3_new(2, 3, 4);
  b = v3_new(5, 6, 7);
  c = v3_add(a, b);
  test(c.x == 7 && c.y == 9 && c.z == 11, "v3_add");

  a = v3_new(2, 3, 4);
  c = v3_add1(a, 5);
  test(c.x == 7 && c.y == 8 && c.z == 9, "v3_add1");

  a = v3_new(5, 6, 7);
  b = v3_new(2, 3, 4);
  c = v3_sub(a, b);
  test(c.x == 3 && c.y == 3 && c.z == 3, "v3_sub");

  a = v3_new(5, 6, 7);
  c = v3_sub1(a, 2);
  test(c.x == 3 && c.y == 4 && c.z == 5, "v3_sub1");

  a = v3_new(2, 3, 4);
  b = v3_new(5, 6, 7);
  c = v3_mul(a, b);
  test(c.x == 10 && c.y == 18 && c.z == 28, "v3_mul");

  a = v3_new(2, 3, 4);
  c = v3_mul1(a, 5);
  test(c.x == 10 && c.y == 15 && c.z == 20, "v3_mul1");

  a = v3_new(10, 18, 28);
  b = v3_new(5, 6, 7);
  c = v3_div(a, b);
  test(c.x == 2 && c.y == 3 && c.z == 4, "v3_div");

  a = v3_new(10, 15, 20);
  c = v3_div1(a, 5);
  test(c.x == 2 && c.y == 3 && c.z == 4, "v3_div1");

  a = v3_new(3, 4, 12);
  test(v3_slen(a) == 169, "v3_slen");

  a = v3_new(3, 4, 12);
  test(v3_len(a) == 13, "v3_len");

  a = v3_new(2, 3, 4);
  b = v3_new(5, 6, 7);
  test(v3_dot(a, b) == 56, "v3_dot");

  a = v3_new(2, 3, 4);
  b = v3_new(5, 6, 7);
  c = v3_cross(a, b);
  test(c.x == -3 && c.y == 6 && c.z == -3, "v3_cross");
}
