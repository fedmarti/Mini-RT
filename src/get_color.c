/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 21:59:38 by shhuang           #+#    #+#             */
/*   Updated: 2024/04/04 20:46:38 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"


t_hit	hit_shape(t_shape *obj, t_ray *ray, enum e_cyl_hit *flag)
{
	t_hit	rayhit;

	rayhit = (t_hit){0};
	if (obj->type == Sphere)
	{
		rayhit.t = hit_sphere(&obj->shape.sphere, ray);
	}
	else if (obj->type == Plane)
	{
		rayhit.t = hit_plane(&obj->shape.plane, ray);
	}
	else if (obj->type == Cylinder)
	{
		rayhit.t = hit_cyl(&obj->shape.cylinder, ray, flag);
	}
	if (rayhit.t > 0 && rayhit.t < RAY_LENGTH)
	{
		rayhit.target = obj;
		rayhit.type = obj->type;
	}
	else
		rayhit.type = Void_shape;
	return (rayhit);
}

t_hit	closest_hit(t_scene	*scene, t_ray *ray, enum e_cyl_hit *flag)
{
	unsigned short	i;
	t_hit			temp_hit;
	t_hit			rayhit;

	rayhit = (t_hit){INFINITY, NULL, Void_shape};
	i = 0;
	while (i < scene->shape_n)
	{
		temp_hit = hit_shape(&scene->shapes[i], ray, flag);
		if (temp_hit.type != Void_shape && temp_hit.t < rayhit.t)
			rayhit = temp_hit;
		i++;
	}
	return (rayhit);
}

int	point_and_type(float *tmp_closest, t_scene *scene, void **actual_shape,
		unsigned int i)
{
	tmp_closest[1] = tmp_closest[0];
	if (scene->shapes[i].type == Plane)
		*actual_shape = &scene->shapes[i].shape.plane;
	else if (scene->shapes[i].type == Sphere)
		*actual_shape = &scene->shapes[i].shape.sphere;
	else if (scene->shapes[i].type == Cylinder)
		*actual_shape = &scene->shapes[i].shape.cylinder;
	return (scene->shapes[i].type);
}

void	init_color_utils(float *tmp_closest, unsigned int *i,
			int *closest_shape, void **actual_shape)
{
	tmp_closest[0] = INFINITY;
	tmp_closest[1] = INFINITY;
	*i = -1;
	*closest_shape = -1;
	*actual_shape = NULL;
}

int	ambient_color(unsigned int color, float ratio)
{
	return (((unsigned int)(((color >> 16) & 0xFF) * ratio) << 16)
	| ((unsigned int)(((color >> 8) & 0xFF) * ratio) << 8)
	| ((unsigned int)((color & 0xFF) * ratio)));
}

int	get_color(t_vec3 raydir, t_scene *scene)
{
	t_hit			rayhit;
	t_vec3			hit_point;
	enum e_cyl_hit	flag;
	t_ray			ray;
	t_vec3			hit_normal;

	ray.origin = (t_vec3){scene->camera.x, scene->camera.y, scene->camera.z};
	ray.dir = raydir;
	rayhit = closest_hit(scene, &ray, &flag);
	if (rayhit.type == Void_shape)
		return (ambient_color(scene->ambient.color, scene->ambient.ratio));
	hit_point = vec3_add(ray.origin, vec3_scale(ray.dir, rayhit.t));
	if (rayhit.type == Cylinder)
		hit_normal = cylinder_hit_norm(&rayhit.target->shape.cylinder, \
		flag, hit_point);
	else if (rayhit.type == Plane)
		hit_normal = plane_hit_norm(&rayhit.target->shape.plane, hit_point);
	else if (rayhit.type == Sphere)
		hit_normal = sphere_hit_norm(&rayhit.target->shape.sphere, hit_point);
	else
		return (0);
	return (loop_light(scene, hit_point, hit_normal, rayhit.target));
}

