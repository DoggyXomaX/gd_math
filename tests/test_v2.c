#include "v2.h"
#include "test.h"

void test_v2() {
  testName("v2");

  v2 a, b, c;

  a = v2_new(3, 4);
  test(v2_slen(&a) == 25, "v2_slen");

  a = v2_new(3, 4);
  test(v2_len(&a) == 5, "v2_len");

  a = v2_new_0();
  v2_0(&b);
  test(a.x == 0 && a.y == 0 && b.x == 0 && b.y == 0, "v2_new_0/v2_0");

  a = v2_new_1();
  v2_1(&b);
  test(a.x == 1 && a.y == 1 && b.x == 1 && b.y == 1, "v2_new_1/v2_1");

  a = v2_new_right();
  test(a.x == 1 && a.y == 0, "v2_new_right");

  a = v2_new_left();
  test(a.x == -1 && a.y == 0, "v2_new_left");

  a = v2_new_up();
  test(a.x == 0 && a.y == 1, "v2_new_up");

  a = v2_new_down();
  test(a.x == 0 && a.y == -1, "v2_new_down");

  v2_set(&a, 1, 2);
  test(a.x == 1 && a.y == 2, "v2_set");

  a = v2_new(1, 2);
  v2_copy(&b, &a);
  test(b.x == 1 && b.y == 2, "v2_copy");

  a = v2_new(1, 2);
  b = v2_new(3, 4);
  v2_add(&c, &a, &b);
  test(c.x == 4 && c.y == 6, "v2_add");

  a = v2_new(5, 6);
  b = v2_new(7, 8);
  v2_sub(&c, &a, &b);
  test(c.x == -2 && c.y == -2, "v2_sub");

  v2_neg(&c, &a);
  test(c.x == -5 && c.y == -6, "v2_neg");

  a = v2_new(1, 2);
  b = v2_new(1, 2);
  test(v2_equal(&a, &b), "v2_equal");

  a = v2_new(1.01, 2);
  b = v2_new(0.99, 2);
  test(
    v2_equal_e(&a, &b, 0.1) &&
      !v2_equal_e(&a, &b, 0) &&
      !v2_equal_e(&a, &b, 0.02) &&
      v2_equal_e(&a, &b, 0.02000001),
    "v2_equal_e");

  a = v2_new(2, 3);
  b = v2_new(4, 5);
  v2_mul(&c, &a, &b);
  test(c.x == 8 && c.y == 15, "v2_mul");

  a = v2_new(2, 3);
  v2_mul_n(&c, &a, 4);
  test(c.x == 8 && c.y == 12, "v2_mul_n");

  a = v2_new(8, 15);
  b = v2_new(4, 5);
  v2_div(&c, &a, &b);
  test(c.x == 2 && c.y == 3, "v2_div");

  a = v2_new(8, 15);
  v2_div_n(&c, &a, 2);
  test(c.x == 4 && c.y == 7.5, "v2_div_n");

  a = v2_new(2, 3);
  b = v2_new(4, 5);
  test(v2_dot(&a, &b) == 23, "v2_dot");

  a = v2_new(2, 3);
  b = v2_new(4, 5);
  test(v2_cross(&a, &b) == -2, "v2_cross");
}
