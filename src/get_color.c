#include "minirt.h"

float get_actual_t(t_scene *scene, unsigned int i, t_cyl_utils *data, t_vec3 raydir)
{
	if (scene->shapes[i].type == Sphere)
			return(hit_sphere(scene->shapes[i].shape.sphere, raydir, (t_vec3){scene->camera.x, scene->camera.y, scene->camera.z}));
		else if (scene->shapes[i].type == Plane)
			return(intersect_plane(scene->shapes[i].shape.plane, (t_vec3){scene->camera.x, scene->camera.y, scene->camera.z}, raydir));
		else if (scene->shapes[i].type == Cylinder)
			return(hit_cyl(scene->shapes[i].shape.cylinder, (t_vec3){scene->camera.x, scene->camera.y, scene->camera.z}, raydir, data));
		return(0);
}

int point_and_type(float *tmp_closest, t_scene *scene, void **actual_shape, unsigned int i)
{
	tmp_closest[1] = tmp_closest[0];
	if(scene->shapes[i].type == Plane)
		*actual_shape = &scene->shapes[i].shape.plane;
	else if(scene->shapes[i].type ==  Sphere)
		*actual_shape = &scene->shapes[i].shape.sphere;
	else if(scene->shapes[i].type == Cylinder)
		*actual_shape = &scene->shapes[i].shape.cylinder;
	return(scene->shapes[i].type);
}

int get_shape_light_color(int *closest_shape, void *actual_shape, t_scene* scene, t_cyl_utils *data)
{
	if (*closest_shape == Cylinder)
	{
		*closest_shape = -1;
		return calculate_cylinder_color(*((t_cylinder *)actual_shape), data, scene);
	}
	else if (*closest_shape == Plane)
	{
		*closest_shape = -1;
		return calculate_plane_color(*((t_plane *)actual_shape), scene);
	}
	else if (*closest_shape == Sphere)
	{
		*closest_shape = -1;
		return calculate_sphere_color(*((t_sphere *)actual_shape), scene);
	}
	return 0x000000;
}

void init_color_utils(float *tmp_closest, unsigned int *i, int *closest_shape, void **actual_shape)
{
	tmp_closest[0] = INFINITY;
	tmp_closest[1] = INFINITY;
	*i = -1;
	*closest_shape = -1;
	*actual_shape = NULL;
}

int get_color(t_vec3 raydir, t_scene *scene)
{
	float tmp_closest[2];
	int color;
	unsigned int i; 
	int 	closest_shape;
	void *actual_shape; 
	t_cyl_utils data;
	
	init_color_utils(tmp_closest, &i, &closest_shape, &actual_shape);
	while (++i < scene->shape_n)
	{
		tmp_closest[0] = get_actual_t(scene, i, &data, raydir);
		if (tmp_closest[0] > 0 && tmp_closest[0] < tmp_closest[1])
			closest_shape = point_and_type(tmp_closest, scene, &actual_shape, i);
	}
	color = get_shape_light_color(&closest_shape, actual_shape, scene, &data);
	return color;
}