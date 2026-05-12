#include "v3.h"
#include "test.h"

void test_v3() {
  testName("v3");

  const double pi = 3.14159265358979323846;
  const double e = 0.0000001;

  v3 a, b, c;

  a = v3_new_0();
  v3_0(&b);
  test(
    a.x == 0 && a.y == 0 && a.z == 0 &&
      b.x == 0 && b.y == 0 && b.z == 0,
    "v3_new_0/v3_0");

  a = v3_new_1();
  v3_1(&b);
  test(
    a.x == 1 && a.y == 1 && a.z == 1 &&
      b.x == 1 && b.y == 1 && b.z == 1,
    "v3_new_1/v3_1");

  v3_set(&a, 1, 2, 3);
  test(a.x == 1 && a.y == 2 && a.z == 3, "v3_set");

  a = v3_new(1, 2, 3);
  v3_copy(&b, &a);
  test(b.x == 1 && b.y == 2 && b.z == 3, "v3_copy");

  a = v3_new_right();
  test(a.x == 1 && a.y == 0 && a.z == 0, "v3_new_right");

  a = v3_new_left();
  test(a.x == -1 && a.y == 0 && a.z == 0, "v3_new_left");

  a = v3_new_up();
  test(a.x == 0 && a.y == 1 && a.z == 0, "v3_new_up");

  a = v3_new_down();
  test(a.x == 0 && a.y == -1 && a.z == 0, "v3_new_down");

  a = v3_new_front();
  test(a.x == 0 && a.y == 0 && a.z == 1, "v3_new_front");

  a = v3_new_back();
  test(a.x == 0 && a.y == 0 && a.z == -1, "v3_new_back");

  a = v3_new(2, 3, 4);
  v3_neg(&c, &a);
  test(c.x == -2 && c.y == -3 && c.z == -4, "v3_neg");

  a = v3_new(2, 3, 4);
  b = v3_new(5, 6, 7);
  v3_add(&c, &a, &b);
  test(c.x == 7 && c.y == 9 && c.z == 11, "v3_add");

  a = v3_new(2, 3, 4);
  v3_add_n(&c, &a, 5);
  test(c.x == 7 && c.y == 8 && c.z == 9, "v3_add_n");

  a = v3_new(5, 6, 7);
  b = v3_new(2, 3, 4);
  v3_sub(&c, &a, &b);
  test(c.x == 3 && c.y == 3 && c.z == 3, "v3_sub");

  a = v3_new(5, 6, 7);
  v3_sub_n(&c, &a, 2);
  test(c.x == 3 && c.y == 4 && c.z == 5, "v3_sub_n");

  a = v3_new(2, 3, 4);
  b = v3_new(5, 6, 7);
  v3_mul(&c, &a, &b);
  test(c.x == 10 && c.y == 18 && c.z == 28, "v3_mul");

  a = v3_new(2, 3, 4);
  v3_mul_n(&c, &a, 5);
  test(c.x == 10 && c.y == 15 && c.z == 20, "v3_mul_n");

  a = v3_new(10, 18, 28);
  b = v3_new(5, 6, 7);
  v3_div(&c, &a, &b);
  test(c.x == 2 && c.y == 3 && c.z == 4, "v3_div");

  a = v3_new(10, 15, 20);
  v3_div_n(&c, &a, 5);
  test(c.x == 2 && c.y == 3 && c.z == 4, "v3_div_n");

  a = v3_new(3, 4, 12);
  test(v3_slen(&a) == 169, "v3_slen");

  a = v3_new(3, 4, 12);
  test(v3_len(&a) == 13, "v3_len");

  a = v3_new(2, 3, 4);
  b = v3_new(2, 3, 4);
  test(v3_equal(&a, &b), "v3_equal");

  a = v3_new(1.01, 2, 3);
  b = v3_new(0.99, 2, 3);
  test(
    v3_equal_e(&a, &b, 0.1) &&
      !v3_equal_e(&a, &b, 0) &&
      !v3_equal_e(&a, &b, 0.02) &&
      v3_equal_e(&a, &b, 0.02000001),
    "v3_equal_e");

  a = v3_new(2, 3, 4);
  b = v3_new(5, 6, 7);
  test(v3_dot(&a, &b) == 56, "v3_dot");

  a = v3_new(2, 3, 4);
  b = v3_new(5, 6, 7);
  v3_cross(&c, &a, &b);
  test(c.x == -3 && c.y == 6 && c.z == -3, "v3_cross");

  a = v3_new(0, 1, 0);
  b = v3_new(0, 0, 1);
  v3_rotx(&c, &a, pi / 2);
  test(v3_equal_e(&c, &b, e), "v3_rotx");

  a = v3_new(0, 0, 1);
  b = v3_new(1, 0, 0);
  v3_roty(&c, &a, pi / 2);
  test(v3_equal_e(&c, &b, e), "v3_roty");

  a = v3_new(1, 0, 0);
  b = v3_new(0, 1, 0);
  v3_rotz(&c, &a, pi / 2);
  test(v3_equal_e(&c, &b, e), "v3_rotz");

  a = v3_new(0, 1, 0);
  b = v3_new(0, 0, 1);
  v3 rot = v3_new(pi / 2, 0, 0);
  v3_rot(&c, &a, &rot, "xyz");
  test(v3_equal_e(&c, &b, e), "v3_rot");
}
