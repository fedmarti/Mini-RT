#include "minirt.h"

void left_on(void *general)
{
	t_general *g = general;
	g->scene->camera.x--;
	printf("arrow left!\n");
}
void up_on(void *general)
{
	t_general *g = general;
	g->scene->camera.y++;
}

void right_on(void *general)
{
	t_general *g = general;
	g->scene->camera.x++;
	printf("arrow right!\n");
}

void down_on(void *general)
{
	t_general *g = general;
	g->scene->camera.y--;
	(void)general;
	printf("arrow down!\n");
}