#include "minirt.h"

void shift_left_on(void *general)
{
	(void)general;
}
void shift_up_on(void *general)
{
	t_general *g = general;
	g->scene->camera.y++;
}
void shift_right_on(void *general)
{
	(void)general;
}
void shift_down_on(void *general)
{
	t_general *g = general;
	g->scene->camera.y--;
}