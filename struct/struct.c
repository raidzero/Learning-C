#include <stdio.h>

int main() {
	typedef struct {
		int x;
		int y;
		int z;
	} s;
	
	s coords = { .x=1, .y=2, .z=3 };
	
	printf("X: %i \n", coords.x);
	printf("Y: %i \n", coords.y);
	printf("Z: %u \n", coords.z);
	return 0;
}