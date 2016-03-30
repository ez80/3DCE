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

//We used a Vector3 Library found online @ http://kixor.net/dev/vector3/
#include <Vector3.h>

//Include our different objects for the scene
#include <camera.c>
#include <mesh.c>

void gameLoop(void);

/* Other available headers */
// stdarg.h, setjmp.h, assert.h, ctype.h, float.h, iso646.h, limits.h, errno.h

void main() {
	gc_InitGraph();
	gc_DrawBuffer();
	gameLoop();
	gc_CloseGraph();
	pgrm_CleanUp();
}
void gameLoop() {
	bool exit = false;
	unsigned char key;
	while (exit == false) {
		key = kb_ScanGroup(kb_group_6);
		if (key & kb_Clear) {
			exit = true;
		}
	}
}