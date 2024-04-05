/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 23:02:47 by fedmarti          #+#    #+#             */
/*   Updated: 2024/04/05 21:06:02 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3	calculate_lighting(t_vec3 hit_point, t_vec3 normal, \
t_vec3 base_col, t_light light)
{
	t_vec3	light_dir;
	float	diff;

	light_dir = vec3_normalize(vec3_substract((t_vec3) \
	{light.x, light.y, light.z}, hit_point));
	diff = fmax(dot(normal, light_dir), 0.0);
	return ((t_vec3) \
	{base_col.x * light.brightness * diff \
		* (float)(*((unsigned char *)&light.color + 2)) / 255.0f,
		base_col.y * light.brightness * diff \
		* (float)(*((unsigned char *)&light.color + 1)) / 255.0f,
		base_col.z * light.brightness * diff \
		* (float)(*((unsigned char *)&light.color + 0)) / 255.0f});
}

t_vec3	int_to_vec3(int color)
{
	return ((t_vec3){
		((color >> 16) & 0xFF) / 255.0f,
		((color >> 8) & 0xFF) / 255.0f,
		(color & 0xFF) / 255.0f
	});
}

bool	is_light_obstructed(t_light *light, t_scene *scene, \
t_shape *object, t_vec3 hit_point)
{
	t_hit	closest;
	t_ray	ray;

	ray.dir = vec3_normalize \
	(vec3_substract(hit_point, (t_vec3){light->x, light->y, light->z}));
	ray.origin = (t_vec3){light->x, light->y, light->z};
	closest = closest_hit(scene, &ray, NULL);
	return (closest.target != object);
}

int	loop_light(t_scene *scene, t_vec3 hit_point, t_vec3 norm, t_shape *shape)
{
	float	rgb[3];
	t_vec3	base_color;
	t_vec3	temp;
	int		i;
	int		full_color;

	i = -1;
	base_color = int_to_vec3(get_shape_color(shape));
	rgb[0] = base_color.x;
	rgb[1] = base_color.y;
	rgb[2] = base_color.z;
	while (++i < scene->light_n)
	{
		if (is_light_obstructed(&scene->lights[i], scene, shape, hit_point))
			continue ;
		temp = \
		calculate_lighting(hit_point, norm, base_color, scene->lights[i]);
		rgb[0] += temp.x;
		rgb[1] += temp.y;
		rgb[2] += temp.z;
	}
	full_color = (int)fmin(rgb[2] * 255.0f, 255.0f);
	full_color |= (int)fmin(rgb[1] * 255.0f, 255.0f) << 8;
	full_color |= (int)fmin(rgb[0] * 255.0f, 255.0f) << 16;
	return (full_color);
}
