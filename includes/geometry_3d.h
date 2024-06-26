/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry_3d.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 22:55:41 by fedmarti          #+#    #+#             */
/*   Updated: 2024/04/14 23:55:21 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GEOMETRY_3D_H
# define GEOMETRY_3D_H

# include "objects.h"
# include <math.h>

typedef struct s_ray_hit
{
	float				t;
	t_shape				*target;
	enum e_shape_type	type;
}	t_hit;

typedef struct s_ray
{
	t_vec3			origin;
	t_vec3			dir;
	float			t;
}	t_ray;

t_vec3	vec3_normalize(t_vec3 v);
float	vec3_length(t_vec3 v);
t_vec3	vec3_add(t_vec3 v1, t_vec3 v2);
t_vec3	vec3_scale(t_vec3 v, float scalar);
t_vec3	vec3_rotate(t_vec3	v, t_radians x, t_radians y, t_radians z);
t_vec3	vec3_substract(t_vec3 v1, t_vec3 v2);
t_vec3	euler_rotate_zyx(t_vec3	v, \
t_radians yaw, t_radians pitch, t_radians roll);
void	get_spherical_coordinates(t_radians *theta, t_radians *phi, t_vec3 v);
t_vec3	vec3_from_sp(t_radians theta, t_radians phi, float len);

#endif