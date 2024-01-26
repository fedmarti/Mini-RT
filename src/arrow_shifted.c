#include "minirt.h"

void shift_left_on(void *general)
{
	(void)general;
	printf("SHift left!\n");
}
void shift_up_on(void *general)
{
	(void)general;
	static int i=0;
	printf("SHift up! %d\n", i++);
}
void shift_right_on(void *general)
{
	(void)general;
	printf("SHift right!\n");
}
void shift_down_on(void *general)
{
	(void)general;
	printf("SHift down!\n");
}