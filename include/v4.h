#ifndef V4_HEADER
#define V4_HEADER

#include "v4impl.h"
#include "v3.h"
#include "v2.h"

v4_header(v4, v3, v2, double);

#endif
/* =============================== */
#ifdef V4_SOURCE

#include "math.h"

v4_source(v4, double, sqrt);

#undef V4_SOURCE
#endif
