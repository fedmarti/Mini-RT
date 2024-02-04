/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry_3d.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shhuang <dsheng1993@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 22:55:41 by fedmarti          #+#    #+#             */
/*   Updated: 2024/02/04 02:34:08 by shhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GEOMETRY_3D_H
# define GEOMETRY_3D_H

# include "objects.h"
# include <math.h>

typedef struct s_vector3d
{
	float	x;
	float	y;
	float	z;
}	t_vec3;

typedef struct s_ray_hit
{
	float	x;
	float	y;
	float	z;
	t_shape	*shape;
}	t_hit;

typedef float	t_radians;
typedef float	t_degrees;

t_vec3	vec3_normalize(t_vec3 v);
float	vec3_length(t_vec3 v);
t_vec3	vec3_add(t_vec3 v1, t_vec3 v2);
t_vec3	vec3_scale(t_vec3 v, float scalar);
t_vec3	vec3_rotate(t_vec3	v, t_radians x, t_radians y, t_radians z);
t_vec3	vec3_substract(t_vec3 v1, t_vec3 v2);
#endif