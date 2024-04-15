/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 13:59:31 by shhuang           #+#    #+#             */
/*   Updated: 2024/04/15 02:08:27 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	get_cyl_magnitude(t_vec3 dir_perpend, t_vec3 oc_perpend, \
t_cylinder *cyl, float t[2])
{
	float	a;
	float	b;
	float	c;
	float	discriminant;
	float	sqrt_discr;

	a = dot(dir_perpend, dir_perpend);
	b = 2.0 * dot(oc_perpend, dir_perpend);
	c = dot(oc_perpend, oc_perpend) - (cyl->diameter / 2) * (cyl->diameter / 2);
	discriminant = b * b - 4 * a * c;
	if (discriminant < 0)
	{
		return (0);
	}
	sqrt_discr = sqrt(discriminant);
	t[0] = (-b - sqrt_discr) / (2 * a);
	t[1] = (-b + sqrt_discr) / (2 * a);
	return (1);
}

int	calculate_base(t_cylinder *cyl, enum e_cyl_hit *flag, \
t_ray *ray, float t_base[2])
{
	int		i;
	bool	hit;

	hit = (ray->t != INFINITY);
	i = -1;
	while (++i < 2)
	{
		if (t_base[i] > 0 && t_base[i] < ray->t)
		{
			if (distance(vec3_add((t_vec3){cyl->x, cyl->y, cyl->z},
					vec3_scale(vec3_normalize(cyl->normal), cyl->height * i)),
				point_at_parameter(ray->origin, ray->dir,
					t_base[i])) <= (cyl->diameter / 2))
			{
				ray->t = t_base[i];
				hit = true;
				if (flag && i == 0)
					*flag = Base_Bottom;
				else if (flag)
					*flag = Base_Top;
			}
		}
	}
	return (hit);
}

float	get_t(t_cyl_utils *data, t_cylinder *cyl, float t[2], \
enum e_cyl_hit *flag)
{
	float	coord_axis_cyl_t0;
	float	coord_axis_cyl_t1;
	float	min_t;

	min_t = INFINITY;
	coord_axis_cyl_t0 = data->dot_oc_axis + t[0] * data->dot_dir_axis;
	coord_axis_cyl_t1 = data->dot_oc_axis + t[1] * data->dot_dir_axis;
	if (t[0] > 0 && coord_axis_cyl_t0 >= 0
		&& coord_axis_cyl_t0 <= cyl->height && t[0] < min_t)
	{
		min_t = t[0];
		if (flag)
			*flag = Outside_Surface;
	}
	if (t[1] > 0 && coord_axis_cyl_t1 >= 0
		&& coord_axis_cyl_t1 <= cyl->height && t[1] < min_t)
	{
		min_t = t[1];
		if (flag)
			*flag = Inside_Surface;
	}
	return (min_t);
}

t_cyl_utils	cyl_data_init(t_cylinder *cyl, t_ray *ray)
{
	t_vec3		oc;
	t_cyl_utils	data;
	t_vec3		normalized_to_axis;

	normalized_to_axis = vec3_normalize(cyl->normal);
	data = (t_cyl_utils){0};
	oc = vec3_substract(ray->origin, (t_vec3){cyl->x, cyl->y, cyl->z});
	data.dot_dir_axis = dot(ray->dir, normalized_to_axis);
	data.dot_oc_axis = dot(oc, normalized_to_axis);
	data.oc_perpend = \
	vec3_substract(oc, vec3_scale(normalized_to_axis, data.dot_oc_axis));
	data.dir_perpend = \
	vec3_substract(ray->dir, vec3_scale(normalized_to_axis, data.dot_dir_axis));
	return (data);
}

float	hit_cyl(t_cylinder *cyl, t_ray *ray, enum e_cyl_hit *flag)
{
	t_cyl_utils	data;
	float		t[2];
	float		t_base[2];

	data = cyl_data_init(cyl, ray);
	t[0] = INFINITY;
	t[1] = INFINITY;
	t_base[0] = (data.dot_oc_axis) / data.dot_dir_axis * -1;
	t_base[1] = ((cyl->height - data.dot_oc_axis) / data.dot_dir_axis);
	if (flag)
		*flag = Missed;
	if (!get_cyl_magnitude(data.dir_perpend, data.oc_perpend, cyl, t))
		return (0);
	ray->t = get_t(&data, cyl, t, flag);
	if (calculate_base(cyl, flag, ray, t_base))
		return (ray->t);
	return (0);
}
