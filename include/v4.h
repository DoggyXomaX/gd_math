#ifndef V4_HEADER
#define V4_HEADER

#include "v4impl.h"

v4_header(v4, double);

#endif
/* =============================== */
#ifdef V4_SOURCE

#include "math.h"

v4_source(v4, double, sqrt);

#undef V4_SOURCE
#endif
