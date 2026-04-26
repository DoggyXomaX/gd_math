#ifndef M4F_HEADER
#define M4F_HEADER

#include "m4impl.h"
#include "v4f.h"
#include "v3f.h"

m4_header(m4f, float, v4f, v3f);

#endif
/* =============================== */
#ifdef M4F_SOURCE

#include <math.h>

m4_source(m4f, float, v4f, v3f, sqrtf);

#undef M4F_SOURCE
#endif
