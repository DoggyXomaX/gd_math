#ifndef V3F_HEADER
#define V3F_HEADER

#include "v3impl.h"
#include "v2f.h"

v3_header(v3f, v2f, float);

#endif
/* =============================== */
#ifdef V3F_SOURCE

#include "math.h"

v3_source(v3f, float, sqrtf);

#undef V3F_SOURCE
#endif
