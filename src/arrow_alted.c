#include "minirt.h"

void alt_left_on(void *general)
{
	t_general g;

	g = *(t_general *)general;
	float rotate_speed = 0.005;
	g.scene->camera.dir_y+= rotate_speed;
}
void alt_up_on(void *general)
{
	t_general g;

	g = *(t_general *)general;
	float rotate_speed = 0.005;
	g.scene->camera.dir_x-= rotate_speed;
}
void alt_right_on(void *general)
{
	t_general g;

	g = *(t_general *)general;
	float rotate_speed = 0.005;
	g.scene->camera.dir_y-= rotate_speed;
}
void alt_down_on(void *general)
{
	t_general g;

	g = *(t_general *)general;
	float rotate_speed = 0.005;
	g.scene->camera.dir_x+= rotate_speed;
}