#include "minirt.h"

int get_color(t_vec3 raydir, t_scene *scene)
{
	float closest_t = INFINITY;
	float tmp_t = INFINITY;
	int color = 0x000000;
	unsigned int i = 0;
	int 	closest_shape;
	t_cyl_utils data;
	void *actual_shape;

	while (i < scene->shape_n)
	{
		if (scene->shapes[i].type == Sphere)
			tmp_t = hit_sphere(scene->shapes[i].shape.sphere, raydir, (t_vec3){scene->camera.x, scene->camera.y, scene->camera.z});
		else if (scene->shapes[i].type == Plane)
			tmp_t = intersect_plane(scene->shapes[i].shape.plane, (t_vec3){scene->camera.x, scene->camera.y, scene->camera.z}, raydir);
		else if (scene->shapes[i].type == Cylinder)
			tmp_t = hit_cyl(scene->shapes[i].shape.cylinder, (t_vec3){scene->camera.x, scene->camera.y, scene->camera.z}, raydir, &data);
		if (tmp_t > 0 && tmp_t < closest_t)
		{
			closest_t = tmp_t;
			switch (scene->shapes[i].type)
			{
			case Plane:
				actual_shape = (void *)&scene->shapes[i].shape.plane;
				closest_shape = Plane;
				color = scene->shapes[i].shape.plane.color;
				break;
			case Sphere:
				actual_shape = (void *)&scene->shapes[i].shape.sphere;
				closest_shape = Sphere;
				color = scene->shapes[i].shape.sphere.color;
				break;
			case Cylinder:
				actual_shape = (void *)&scene->shapes[i].shape.cylinder;
				closest_shape = Cylinder;
				color = scene->shapes[i].shape.cylinder.color;
				break;
			default:
				break;
			}
		}
		i++;
	}
	if(closest_shape == Cylinder)
	{
		color = calculate_cylinder_color(*((t_cylinder *)actual_shape), &data, color);
		closest_shape = -1;
	}
	else if(closest_shape == Plane)
	{
		color = color;
		closest_shape = -1;
	}
	else if(closest_shape == Sphere)
	{
		color = color;
		closest_shape = -1;
	}
	return color;
}