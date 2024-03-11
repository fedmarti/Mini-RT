/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cyl_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shhuang <dsheng1993@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 21:40:44 by shhuang           #+#    #+#             */
/*   Updated: 2024/03/11 21:49:12 by shhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	calculate_cylinder_c(t_cylinder *c, t_cyl_utils *d, t_scene *s, t_vec3 rd)
{
	t_vec3	hit_point;
	t_vec3	norm;

	if (d->flag == Inside_Surface)
		return (c->color);
	hit_point = vec3_add((t_vec3){s->camera.x, s->camera.y, s->camera.z},
			vec3_scale(rd, d->min_t));
	if (d->flag == Base)
	{
		if (d->base_is_top)
			norm = vec3_normalize((t_vec3){c->normal_x,
					c->normal_y,
					c->normal_z});
		else
			norm = vec3_normalize(vec3_invert((t_vec3){c->normal_x,
						c->normal_y,
						c->normal_z}));
	}
	else
		norm = vec3_normalize(vec3_substract(hit_point,
					(t_vec3){c->x, c->y, c->z}));
	return (loop_light(s, hit_point, norm, c->color));
}
