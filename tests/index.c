#define V2_SOURCE
#include "test_v2.c"

#define V3_SOURCE
#include "test_v3.c"

#define V4_SOURCE
#include "test_v4.c"

#define M2_SOURCE
#include "test_m2.c"

#define M3_SOURCE
#include "test_m3.c"

#define M4_SOURCE
#include "test_m4.c"

#define TEST_SOURCE
#include "test.h"

int main() {
  test_v2();
  test_v3();
  test_v4();
  test_m2();
  test_m3();
  test_m4();

  return testStatus();
}
