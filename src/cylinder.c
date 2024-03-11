/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shhuang <dsheng1993@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 13:59:31 by shhuang           #+#    #+#             */
/*   Updated: 2024/03/11 21:58:00 by shhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	get_cyl_magnitude(t_vec3 dir_perpend, t_vec3 oc_perpend,
			t_cylinder *cyl, t_cyl_utils *data)
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
	data->t[0] = (-b - sqrt_discr) / (2 * a);
	data->t[1] = (-b + sqrt_discr) / (2 * a);
	return (1);
}

float	get_t(t_cyl_utils *data, t_cylinder *cyl)
{
	float	coord_axis_cyl_t0;
	float	coord_axis_cyl_t1;

	coord_axis_cyl_t0 = data->dot_oc_axis + data->t[0] * data->dot_dir_axis;
	coord_axis_cyl_t1 = data->dot_oc_axis + data->t[1] * data->dot_dir_axis;
	if (data->t[0] > 0 && coord_axis_cyl_t0 >= 0
		&& coord_axis_cyl_t0 <= cyl->height && data->t[0] < data->min_t)
	{
		data->min_t = data->t[0];
		data->flag = Outside_Surface;
		data->hit = true;
	}
	if (data->t[1] > 0 && coord_axis_cyl_t1 >= 0
		&& coord_axis_cyl_t1 <= cyl->height && data->t[1] < data->min_t)
	{
		data->min_t = data->t[1];
		data->flag = Inside_Surface;
		data->hit = true;
	}
	return (data->min_t);
}

void	init_data_basic(t_cyl_utils *data, t_vec3 *origin, t_vec3 *raydir,
					t_cylinder *cyl)
{
	*data = (t_cyl_utils){0};
	data->origin = *origin;
	data->raydir = *raydir;
	data->oc = vec3_substract(data->origin, (t_vec3){cyl->x, cyl->y, cyl->z});
	data->min_t = INFINITY;
	data->axis_normalize = vec3_normalize((t_vec3){cyl->normal_x,
			cyl->normal_y,
			cyl->normal_z});
}

int	calculate_base(t_cylinder *cyl, t_cyl_utils *data)
{
	int		i;
	float	t_base;

	i = -1;
	while (++i < 2)
	{
		t_base = ((cyl->height * i - data->dot_oc_axis) / data->dot_dir_axis);
		if (t_base > 0 && t_base < data->min_t)
		{
			if (distance(vec3_add((t_vec3){cyl->x, cyl->y, cyl->z},
					vec3_scale(data->axis_normalize, cyl->height * i)),
				point_at_parameter(data->origin, data->raydir, t_base))
						<= (cyl->diameter / 2))
			{
				data->min_t = t_base;
				data->hit = true;
				data->flag = Base;
				if (i == 0)
					data->base_is_top = true;
				else
					data->base_is_top = false;
			}
		}
	}
	return (data->hit);
}

float	hit_cyl(t_cylinder *cyl, t_vec3 origin, t_vec3 *raydir,
				t_cyl_utils *data)
{
	t_vec3	oc_perpend;
	t_vec3	dir_perpend;

	init_data_basic(data, &origin, raydir, cyl);
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
