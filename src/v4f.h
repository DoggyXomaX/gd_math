#ifndef V4F_HEADER
#define V4F_HEADER

#include "v4impl.h"
#include "v2f.h"
#include "v3f.h"

v4_header(v4f, v3f, v2f, float);

#endif
/* =============================== */
#ifdef V4F_SOURCE

v4_source(v4f, float, sqrtf);

#undef V4F_SOURCE
#endif
