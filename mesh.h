/* Keep these headers */
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <tice.h>
#include <debug.h>

/* Standard headers - it's recommended to leave them included */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <lib/ce/keypadc.h>
#include <lib/ce/graphc.h>
#include <lib/ce/fileioc.h>

#include <Vector3.h>

typedef struct Mesh
{
	String Name;
	vector3[] Verticies;
	vector3 position;
	vector3 rotation;
} Mesh;

Mesh* Mesh_create(const char* name, uint8_t verticesCount);
