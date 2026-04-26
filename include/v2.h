#ifndef V2_HEADER
#define V2_HEADER

#include "v2impl.h"

v2_header(v2, double);

#endif
/* =============================== */
#ifdef V2_SOURCE

#include <math.h>

v2_source(v2, double, sqrt);

#undef V2_SOURCE
#endif
