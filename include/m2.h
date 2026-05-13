#ifndef M2_HEADER
#define M2_HEADER

#include "m2impl.h"
#include "v2.h"

m2_header(m2, v2, double);

#endif
/* =============================== */
#ifdef M2_SOURCE

m2_source(m2, double, fabs);

#undef M2_SOURCE
#endif
