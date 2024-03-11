#include "minirt.h"

t_hit hit_shape(t_shape	*obj, t_camera *camera, t_cyl_utils *data, t_vec3 *raydir)
{
	t_hit	rayhit;
	
	rayhit = (t_hit){0};
	if (obj->type == Sphere)
	{
		rayhit.t = hit_sphere(&obj->shape.sphere, (t_vec3){camera->x, camera->y, camera->z}, raydir);
	}
	else if (obj->type == Plane)
	{
		rayhit.t = hit_plane(&obj->shape.plane, (t_vec3){camera->x, camera->y, camera->z}, raydir);
	}
	else if (obj->type == Cylinder)
	{
		rayhit.t = hit_cyl(&obj->shape.cylinder, (t_vec3){camera->x, camera->y, camera->z}, raydir, data);
	}
	if (rayhit.t > 0 && rayhit.t < RAY_LENGTH)
	{
		rayhit.target = &obj->shape;
		rayhit.type = obj->type;
	}
	else
		rayhit.type = Void_shape;
	return(rayhit);
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

void init_color_utils(float *tmp_closest, unsigned int *i, int *closest_shape, void **actual_shape)
{
	tmp_closest[0] = INFINITY;
	tmp_closest[1] = INFINITY;
	*i = -1;
	*closest_shape = -1;
	*actual_shape = NULL;
}

int ambient_color(unsigned int color, float ratio)
{
	return ((unsigned int)(((color >> 16) & 0xFF) * ratio) << 16) | ((unsigned int)(((color >> 8) & 0xFF) * ratio) << 8) | ((unsigned int)((color & 0xFF) * ratio));
}

int get_color(t_vec3 raydir, t_scene *scene)
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
	if (rayhit.type == Cylinder)
		return(calculate_cylinder_c(rayhit.target, &data, scene, raydir));
	else if (rayhit.type == Plane)
		return(calculate_plane_color(rayhit.target, scene, raydir, rayhit.t));
	else if (rayhit.type == Sphere)
		return(calculate_sphere_color(rayhit.target, scene, raydir, rayhit.t));
	return(ambient_color(scene->ambient.color, scene->ambient.ratio));
}