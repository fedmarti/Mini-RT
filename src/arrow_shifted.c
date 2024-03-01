#include "minirt.h"

void shift_left_on(void *general)
{
	t_general *g = general;

	int diameter_point_pos;

	diameter_point_pos = 3;
	if(g->selected == NULL || g->selected_type == Plane)
		g->scene->camera.x--;
	else
	{
		if(g->selected_type == Cylinder)
			diameter_point_pos+=3;
		*((float *)g->selected + diameter_point_pos) -= 1;
		if(*((float *)g->selected + diameter_point_pos) < 0)
			*((float *)g->selected + diameter_point_pos) = 0.01;
	}
}
void shift_up_on(void *general)
{
	t_general *g = general;
	
	if(g->selected == NULL || g->selected_type == Plane)
		g->scene->camera.y++;
	else if(g->selected_type == Cylinder)
	{
		*((float *)g->selected + 7) += 1;
		if(*((float *)g->selected + 7) < 0)
			*((float *)g->selected + 7) = 0.01;
	}
}
void shift_right_on(void *general)
{
	t_general *g = general;
	int diameter_point_pos;

	diameter_point_pos = 3;
	if(g->selected == NULL || g->selected_type == Plane)
		g->scene->camera.x++;
	else
	{
		if(g->selected_type == Cylinder)
			diameter_point_pos+=3;
		*((float *)g->selected + diameter_point_pos) += 1;
		if(*((float *)g->selected + diameter_point_pos) < 0)
			*((float *)g->selected + diameter_point_pos) = 0.01;
	}
}
void shift_down_on(void *general)
{
	t_general *g = general;
	
	if(g->selected == NULL || g->selected_type == Plane)
		g->scene->camera.y--;
	else if(g->selected_type == Cylinder)
	{
		*((float *)g->selected + 7) += 0;
		if(*((float *)g->selected + 7) < 0)
			*((float *)g->selected + 7) = 0.01;
	}
}