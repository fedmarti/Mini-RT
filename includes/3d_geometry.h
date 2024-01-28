/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d_geometry.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 22:55:41 by fedmarti          #+#    #+#             */
/*   Updated: 2024/01/28 23:02:33 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef 3D_GEOMETRY_H
# define 3D_GEOMETRY_H

#include "objects.h"

typedef struct s_vector3d
{
	float	x;
	float	y;
	float	z;
}	t_vec3;

typedef	struct s_ray_hit 
{
	float	x;
	float	y;
	float	z;
	t_shape	*shape;
}	t_hit;

#endif