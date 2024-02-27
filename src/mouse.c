#include "minirt.h"

t_vec3 get_raydir(int x, int y, t_general* g)
{
	t_vec3 actual_raydir;
	float view_x;
	float view_y;

	view_x = (x - g->viewport.image_width /  2.0) * (g->viewport.viewport_width / g->viewport.image_width);
    view_y = -(y - g->viewport.image_height / 2.0) * (g->viewport.viewport_height / g->viewport.image_height);
	actual_raydir = (t_vec3){view_x, view_y, 1.0};
	rotate_raydir(&actual_raydir, (t_vec3){g->scene->camera.dir_x, g->scene->camera.dir_y, g->scene->camera.dir_z});
	return(actual_raydir);
}

void *select_item(t_vec3 raydir, t_scene *scene, t_general *g)
{
	unsigned int i; 
	t_cyl_utils data;
	t_hit	rayhit;
	t_hit	temp_hit;
	
	rayhit = (t_hit){INFINITY, NULL, Void_shape};
	i = -1;
	while (++i < scene->shape_n)
	{
		temp_hit = hit_shape(&scene->shapes[i], &scene->camera, &data, &raydir);
		if (temp_hit.type != Void_shape && temp_hit.t < rayhit.t)
			rayhit = temp_hit;
	}
	g->selected_type = rayhit.type;
	return(rayhit.target);
}

int on_click_event(int button, int x, int y, t_general *g)
{
	printf("x: %d ,y: %d\n", x, y);
	if(button == CLK_LEFT)
	{
		g->selected = select_item(get_raydir(x, y, g), g->scene, g);
		if(g->selected_type == Plane)
		{
			printf("Plane\n");
		}
		if(g->selected_type == Sphere)
		{
			printf("Sphere\n");
		}
		if(g->selected_type == Cylinder)
		{
			printf("Cilinder\n");
		}
    }
	return(0);
}
