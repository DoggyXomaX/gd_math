#ifndef V3_HEADER
#define V3_HEADER

#include "v3impl.h"
#include "v2.h"

v3_header(v3, v2, double);

#endif
/* =============================== */
#ifdef V3_SOURCE

#include "math.h"

v3_source(v3, double, sqrt);

#undef V3_SOURCE
#endif
