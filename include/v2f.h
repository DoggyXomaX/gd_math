#ifndef V2F_HEADER
#define V2F_HEADER

#include "v2impl.h"

v2_header(v2f, float);

#endif
/* =============================== */
#ifdef V2F_SOURCE

#include <math.h>

v2_source(v2f, float, sqrtf);

#undef V2F_SOURCE
#endif
