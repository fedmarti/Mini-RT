#include "minirt.h"
#define STEPS 1

void left_on(void *general)
{
	t_general *g;

	g = (t_general *)general;
	g->scene->camera.x -= cos(g->scene->camera.y) * STEPS;
	g->scene->camera.z -= sin(g->scene->camera.y) * STEPS;
}
void up_on(void *general)
{
	t_general *g;

	g = (t_general *)general;
	g->scene->camera.x -= sin(g->scene->camera.y) * STEPS;
	g->scene->camera.z += cos(g->scene->camera.y) * STEPS;
}

void right_on(void *general)
{
	t_general *g;

	g = (t_general *)general;
	g->scene->camera.x += cos(g->scene->camera.y) * STEPS;
	g->scene->camera.z += sin(g->scene->camera.y) * STEPS;
}

void down_on(void *general)
{
	t_general *g;

	g = (t_general *)general;
	g->scene->camera.x += sin(g->scene->camera.y) * STEPS;
	g->scene->camera.z -= cos(g->scene->camera.y) * STEPS;
}