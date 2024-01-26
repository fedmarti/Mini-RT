#include "minirt.h"

void alt_left_on(void *general)
{
	(void)general;
	printf("Alt left!\n");
}
void alt_up_on(void *general)
{
	(void)general;
	static int i=0;
	printf("Alt up! %d\n", i++);
}
void alt_right_on(void *general)
{
	(void)general;
	printf("Alt right!\n");
}
void alt_down_on(void *general)
{
	(void)general;
	printf("Alt down!\n");
}