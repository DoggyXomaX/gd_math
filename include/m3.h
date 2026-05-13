#ifndef M3_HEADER
#define M3_HEADER

#include "m3impl.h"
#include "v2.h"
#include "v3.h"

m3_header(m3, v3, v2, double);

#endif
/* =============================== */
#ifdef M3_SOURCE

#include <math.h>

m3_source(m3, v2, double, fabs, cos, sin, sqrt, atan2);

#undef M3_SOURCE
#endif
