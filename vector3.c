#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "vector3.h"

// arithmetic operations
INLINE_MODE vector3* vector3_add(vector3 *dest, const vector3 *v1, const vector3 *v2)
{
	dest->x = v1->x + v2->x;
	dest->y = v1->y + v2->y;
	dest->z = v1->z + v2->z;
	return dest;
}

INLINE_MODE vector3* vector3_subtract(vector3 *dest, const vector3 *minuend, const vector3 *subtrahend)
{
	dest->x = minuend->x - subtrahend->x;
	dest->y = minuend->y - subtrahend->y;
	dest->z = minuend->z - subtrahend->z;
	return dest;
}

INLINE_MODE vector3* vector3_multiply(vector3 *dest, const vector3 *v, const v3float n)
{
	dest->x = v->x * n;
	dest->y = v->y * n;
	dest->z = v->z * n;
	return dest;
}

INLINE_MODE vector3* vector3_divide(vector3 *dest, const vector3 *v,const  v3float n)
{
	dest->x = v->x / n;
	dest->y = v->y / n;
	dest->z = v->z / n;
	return dest;
}

INLINE_MODE vector3 *vector3_scalar_add(vector3 *dest, const vector3 *v, const v3float s)
{
	dest->x = v->x + s;
	dest->y = v->y + s;
	dest->z = v->z + s;
	return dest;
}

INLINE_MODE vector3 *vector3_scalar_sub(vector3 *dest, const vector3 *v, const v3float s)
{
	dest->x = v->x - s;
	dest->y = v->y - s;
	dest->z = v->z - s;
	return dest;
}

INLINE_MODE v3float vector3_dot(const vector3 *a, const vector3 *b)
{
	return a->x*b->x + a->y*b->y + a->z*b->z;
}

INLINE_MODE vector3* vector3_cross(vector3 *dest, const vector3 *a, const vector3 *b)
{
	dest->x = a->y*b->z - a->z*b->y;
	dest->y = a->z*b->x - a->x*b->z;
	dest->z = a->x*b->y - a->y*b->x;
	
	return dest;
}

// vector3 unit operations
INLINE_MODE v3float vector3_length(const vector3 *a)
{
	return sqrt(a->x*a->x + a->y*a->y + a->z*a->z);
}

INLINE_MODE vector3* vector3_normalize(vector3 *a)
{
	v3float normalizeLength;
	normalizeLength = vector3_length(a);
	
	if(normalizeLength <= EPSILON)
	{
		printf("cannot normalize degenerate vector3\n");
		return a;
	}
	
	vector3_divide(a, a, normalizeLength);
	return a;
}

INLINE_MODE vector3* vector3_invert(vector3 *dest, const vector3 *v)
{
	dest->x = -v->x;
	dest->y = -v->y;
	dest->z = -v->z;
	return dest;
}

INLINE_MODE void vector3_print(const vector3 *v)
{
	printf("%.2f %.2f %.2f\n", v->x, v->y, v->z);
}

// vector3 creation
INLINE_MODE vector3* vector3_copy(vector3 *dest, const vector3 *source)
{
	dest->x = source->x;
	dest->y = source->y;
	dest->z = source->z;
	return dest;
}

INLINE_MODE vector3* vector3_random(vector3 *v)
{
	do {
		v->x = (double)rand()/RAND_MAX*2-1;
		v->y = (double)rand()/RAND_MAX*2-1;
		v->z = (double)rand()/RAND_MAX*2-1;
	} while (v->x*v->x + v->y*v->y + v->z*v->z > 1.0);
	return v;
}

INLINE_MODE vector3* vector3_make3f(vector3 *v, const v3float x, const v3float y, const v3float z)
{
	v->x = x;
	v->y = y;
	v->z = z;
	return v;
}

INLINE_MODE vector3* vector3_make2v(vector3 *v, const vector3 *to, const vector3 *from)
{
	v->x = to->x - from->x;
	v->y = to->y - from->y;
	v->z = to->z - from->z;
	return v;
}

// vector3 combination operations
INLINE_MODE v3float vector3_distance(const vector3 *a, const vector3 *b)
{
	return sqrt( pow(a->x - b->x, 2) + pow(a->y - b->y, 2) + 
				pow(a->z - b->z, 2));
}

INLINE_MODE double vector3_distancesq(vector3 *a, vector3 *b)
{
	return pow(a->x - b->x, 2) + pow(a->y - b->y, 2) + 
				pow(a->z - b->z, 2);
}

INLINE_MODE v3float vector3_angle(const vector3 *a, const vector3 *b) 
{
	return acos(vector3_dot(a,b) / vector3_length(a) / vector3_length(b));
}

INLINE_MODE vector3* vector3_reflect(vector3 *dest, const vector3 *incoming, const vector3 *normal)
{
	v3float dp;
	dp = 2*vector3_dot(normal, incoming);

	dest->x = incoming->x - dp*normal->x;
	dest->y = incoming->y - dp*normal->y;
	dest->z = incoming->z - dp*normal->z;
	
	return dest;
}