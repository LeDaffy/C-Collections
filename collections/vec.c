#include <collections/vec.h>

#define VEC_IMP

#define generic(name) name ## _ ## int
#define type int
#include <collections/vec_imp.c>
#undef generic
#undef type


#define generic(name) name ## _ ## double
#define type double
#include <collections/vec_imp.c>
#undef generic
#undef type


#define generic(name) name ## _ ## int_ptr
#define type int_ptr
#include <collections/vec_imp.c>
#undef generic
#undef type
