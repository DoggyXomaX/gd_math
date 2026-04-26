#ifndef M3F_HEADER
#define M3F_HEADER

#include "m3impl.h"
#include "v2f.h"
#include "v3f.h"

m3_header(m3f, float, v2f, v3f);

#endif
/* =============================== */
#ifdef M3F_SOURCE

#include <math.h>

m3_source(m3f, float, v2f, cosf, sinf, sqrtf, atan2f);

#undef M3F_SOURCE
#endif
