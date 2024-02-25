/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shhuang <dsheng1993@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 13:59:31 by shhuang           #+#    #+#             */
/*   Updated: 2024/02/25 14:05:50 by shhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3	get_perpendicular_oc(t_cyl_utils *data)
{
	data->dot_oc_axis = dot(data->oc, data->axis_normalize);
	return ((t_vec3)vec3_substract(data->oc, vec3_scale(data->axis_normalize,
				data->dot_oc_axis)));
}

t_vec3	get_perpendicular_dir(t_cyl_utils *data)
{
	data->dot_dir_axis = dot(data->raydir, data->axis_normalize);
	return ((t_vec3)vec3_substract(data->raydir,
			vec3_scale(data->axis_normalize, data->dot_dir_axis)));
}

int	get_cyl_magnitude(t_vec3 dir_perpend, t_vec3 oc_perpend, t_cylinder cyl,
		t_cyl_utils *data)
{
	float	a;
	float	b;
	float	c;
	float	discriminant;
	float	sqrt_discr;

	a = dot(dir_perpend, dir_perpend);
	b = 2.0 * dot(oc_perpend, dir_perpend);
	c = dot(oc_perpend, oc_perpend) - (cyl.diameter / 2) * (cyl.diameter / 2);
	discriminant = b * b - 4 * a * c;
	if (discriminant < 0)
	{
		return (0);
	}
	sqrt_discr = sqrt(discriminant);
	data->t[0] = (-b - sqrt_discr) / (2 * a);
	data->t[1] = (-b + sqrt_discr) / (2 * a);
	return (1);
}

float	get_t(t_cyl_utils *data, t_cylinder cyl)
{
	float	coord_axis_cyl_t0;
	float	coord_axis_cyl_t1;

	coord_axis_cyl_t0 = data->dot_oc_axis + data->t[0] * data->dot_dir_axis;
	coord_axis_cyl_t1 = data->dot_oc_axis + data->t[1] * data->dot_dir_axis;
	if (data->t[0] > 0 && coord_axis_cyl_t0 >= 0
		&& coord_axis_cyl_t0 <= cyl.height && data->t[0] < data->min_t)
	{
		data->min_t = data->t[0];
		data->flag = 1;
		data->hit = true;
	}
	if (data->t[1] > 0 && coord_axis_cyl_t1 >= 0
		&& coord_axis_cyl_t1 <= cyl.height && data->t[1] < data->min_t)
	{
		data->min_t = data->t[1];
		data->flag = 2;
		data->hit = true;
	}
	return (data->min_t);
}

void	init_data_basic(t_cyl_utils *data, t_vec3 *origin, t_vec3 *raydir,
		t_cylinder cyl)
{
	*data = (t_cyl_utils){0};
	data->origin = *origin;
	data->raydir = *raydir;
	data->oc = vec3_substract(data->origin, (t_vec3){cyl.x, cyl.y, cyl.z});
	data->min_t = INFINITY;
	data->axis_normalize = vec3_normalize((t_vec3){cyl.normal_x, cyl.normal_y,
			cyl.normal_z});
}

int	calculate_base(t_cylinder cyl, t_cyl_utils *data)
{
	int		i;
	float	t_base;

	i = -1;
	while (++i < 2)
	{
		t_base = ((cyl.height * i - data->dot_oc_axis) / data->dot_dir_axis);
		if (t_base > 0 && t_base < data->min_t)
		{
			if (distance(vec3_add((t_vec3){cyl.x, cyl.y, cyl.z},
					vec3_scale(data->axis_normalize, cyl.height * i)),
				point_at_parameter(data->origin, data->raydir,
					t_base)) <= (cyl.diameter / 2))
			{
				data->min_t = t_base;
				data->hit = true;
				data->flag = 3;
			}
		}
	}
	return (data->hit);
}


float	hit_cyl(t_cylinder cyl, t_vec3 origin, t_vec3 raydir, t_cyl_utils *data)
{
	t_vec3	oc_perpend;
	t_vec3	dir_perpend;
	cyl.diameter = 80.1;
	cyl.height = 402.0;
	cyl.normal_x = 0.5;
	cyl.normal_y = 1.0;
	cyl.normal_z = 1.0;
	cyl.x = 400.0;
	cyl.y = 10.0;
	cyl.z = 60.6;

	init_data_basic(data, &origin, &raydir, cyl);
	oc_perpend = get_perpendicular_oc(data);
	dir_perpend = get_perpendicular_dir(data);
	if (!get_cyl_magnitude(dir_perpend, oc_perpend, cyl, data))
		return (0);
	data->min_t = get_t(data, cyl);
	data->hit = calculate_base(cyl, data);
	if (data->hit)
		return (data->min_t);
	return (0);
}