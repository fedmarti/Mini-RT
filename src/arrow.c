#include "minirt.h"
#define STEPS 1

void move_obj(float *val, enum plus_minus sign)
{
	*val += sign;
}

void left_on(void *general)
{
	t_general *g;

	g = (t_general *)general;
	if(g->selected == NULL)
	{
		g->scene->camera.x -= cos(g->scene->camera.y) * STEPS;
		g->scene->camera.z -= sin(g->scene->camera.y) * STEPS;
	}
	else
		move_obj(((float *)g->selected + 0), Minus);
}

void up_on(void *general)
{
	t_general *g;
	g = (t_general *)general;
	if(g->selected == NULL)
	{
		g->scene->camera.x -= sin(g->scene->camera.y) * STEPS;
		g->scene->camera.z += cos(g->scene->camera.y) * STEPS;
	}
	else
		move_obj(((float *)g->selected + 1), Plus);
}

void right_on(void *general)
{
	t_general *g;

	g = (t_general *)general;
	if(g->selected == NULL)
	{
		g->scene->camera.x += cos(g->scene->camera.y) * STEPS;
		g->scene->camera.z += sin(g->scene->camera.y) * STEPS;
	}
	else
		move_obj(((float *)g->selected + 0), Plus);
}

void down_on(void *general)
{
	t_general *g;

	g = (t_general *)general;
	if(g->selected == NULL)
	{
		g->scene->camera.x += sin(g->scene->camera.y) * STEPS;
		g->scene->camera.z -= cos(g->scene->camera.y) * STEPS;
		}
	else
		move_obj(((float *)g->selected + 1), Minus);
}