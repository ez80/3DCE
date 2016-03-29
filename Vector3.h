
#ifndef __VECTOR3
#define __VECTOR3
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// inlining can be adjusted here
// #define INLINE_MODE inline
#define INLINE_MODE

// floating point unit can be changed here
#define v3float float
// #define v3float double

// set an epsilon if not set
#ifndef EPSILON
#define EPSILON 0.001f
#endif

typedef struct {
	v3float x;
	v3float y;
	v3float z;
} vector3;

// arithmetic operations
INLINE_MODE vector3* vector3_add(vector3 *dest, const vector3 *v1, const vector3 *v2);
INLINE_MODE vector3* vector3_subtract(vector3 *dest, const vector3 *minuend, const vector3 *subtrahend);
INLINE_MODE vector3* vector3_multiply(vector3 *dest, const vector3 *v, const v3float n);
INLINE_MODE vector3* vector3_divide(vector3 *dest, const vector3 *v, const v3float n);
INLINE_MODE vector3 *vector3_scalar_add(vector3 *dest, const vector3 *v, const v3float s);
INLINE_MODE vector3 *vector3_scalar_sub(vector3 *dest, const vector3 *v, const v3float s);
INLINE_MODE v3float vector3_dot(const vector3 *a, const vector3 *b);
INLINE_MODE vector3* vector3_cross(vector3 *dest, const vector3 *a, const vector3 *b);

// unit operations
INLINE_MODE v3float vector3_length(const vector3 *a);
INLINE_MODE vector3* vector3_normalize(vector3 *a);
INLINE_MODE vector3* vector3_invert(vector3 *dest, const vector3 *v);
INLINE_MODE void vector3_print(const vector3 *v);

// creation
INLINE_MODE vector3* vector3_copy(vector3 *dest, const vector3 *source);
INLINE_MODE vector3* vector3_random(vector3 *v);
INLINE_MODE vector3* vector3_make3f(vector3 *v, const v3float x, const v3float y, const v3float z);
INLINE_MODE vector3* vector3_make2v(vector3 *v, const vector3 *to, const vector3 *from);

// combination operations
INLINE_MODE v3float vector3_distance(const vector3 *a, const vector3 *b);
INLINE_MODE double vector3_distancesq(vector3 *a, vector3 *b);
INLINE_MODE v3float vector3_angle(const vector3 *a, const vector3 *b);
INLINE_MODE vector3* vector3_reflect(vector3 *dest, const vector3 *incoming, const vector3 *normal);

#endif