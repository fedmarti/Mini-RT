/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cyl_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 21:40:44 by shhuang           #+#    #+#             */
/*   Updated: 2024/04/15 03:07:05 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"


//returns the normal vector of the ray hit on a cylinder
//different calculations are performed depending on the flag
//which specifies the section in which the cylinder was hit
t_vec3	cylinder_hit_norm(t_cylinder *cyl, enum e_cyl_hit flag, t_vec3 ht_point)
{
	t_vec3	norm;

	if (flag == Inside_Surface || flag == Outside_Surface)
	{
		norm = vec3_normalize(vec3_substract(ht_point, \
		(t_vec3){cyl->x, cyl->y, cyl->z}));
		if (flag == Inside_Surface)
			return (vec3_invert(norm));
		return (norm);
	}
	if (flag == Base_Top)
		return (cyl->normal);
	else if (flag == Base_Bottom)
		return (vec3_invert(cyl->normal));
	return ((t_vec3){0});
}
