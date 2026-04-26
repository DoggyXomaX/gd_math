#ifndef M4_HEADER
#define M4_HEADER

#include "m4impl.h"
#include "v4.h"
#include "v3.h"

m4_header(m4, double, v4, v3);

#endif
/* =============================== */
#ifdef M4_SOURCE

#include <math.h>

m4_source(m4, double, v4, v3, sqrt);

#undef M4_SOURCE
#endif
