#include "minirt.h"

int get_color(t_vec3 raydir, t_scene *scene)
{
	float closest_t = INFINITY;
	float tmp_t = INFINITY;
	int color = 0x000000;
	unsigned int i = 0;
	int 	closest_shape;
	void *actual_shape;
	t_cyl_utils data;

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
			if(scene->shapes[i].type == Plane)
			{
				actual_shape = (void *)&scene->shapes[i].shape.plane;
				closest_shape = Plane;
			}
			else if(scene->shapes[i].type ==  Sphere)
			{
				actual_shape = (void *)&scene->shapes[i].shape.sphere;
				closest_shape = Sphere;
			}
			else if(scene->shapes[i].type == Cylinder)
			{
				actual_shape = (void *)&scene->shapes[i].shape.cylinder;
				closest_shape = Cylinder;
			}
		}
		i++;
	}
	if(closest_shape == Cylinder)
	{
		color = calculate_cylinder_color(*((t_cylinder *)actual_shape), &data, scene);
		closest_shape = -1;
	}
	else if(closest_shape == Plane)
	{
		color = calculate_plane_color(*((t_plane *)actual_shape), scene);
		closest_shape = -1;
	}
	else if(closest_shape == Sphere)
	{
		color = calculate_sphere_color(*((t_sphere *)actual_shape), scene);
		closest_shape = -1;
	}
	return color;
}