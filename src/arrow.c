#include "minirt.h"

void left_on(void *general)
{
	(void)general;
	printf("arrow left!\n");
}
void up_on(void *general)
{
	(void)general;
	static int i=0;
	printf("arrow up! %d\n", i++);
}

void right_on(void *general)
{
	(void)general;
	printf("arrow right!\n");
}

void down_on(void *general)
{
	(void)general;
	printf("arrow down!\n");
}