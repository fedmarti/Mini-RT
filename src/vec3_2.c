/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 23:12:13 by fedmarti          #+#    #+#             */
/*   Updated: 2024/04/15 00:50:48 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry_3d.h"
#include "libft.h"

t_vec3	vec3_scale(t_vec3 v, float scalar)
{
	return ((t_vec3){v.x * scalar, v.y * scalar, v.z * scalar});
}

t_vec3	vec3_invert(t_vec3 v)
{
	return ((t_vec3){-v.x, -v.y, -v.z});
}

//applies zyx multiplication matrices to vector vec
t_vec3	euler_rotate_zyx(t_vec3	vec, t_radians a, t_radians b, t_radians c)
{
	t_vec3	new_v;
	float	mat[3][3];

	mat[0][0] = (cosf(a) * cosf(b));
	mat[0][1] = ((cosf(a) * sinf(b) * sinf(c)) - (sinf(a) * cosf(c)));
	mat[0][2] = ((cosf(a) * sinf(b) * cosf(c)) + (sinf(a) * sinf(c)));
	mat[1][0] = (sinf(a) * cosf(b));
	mat[1][1] = ((sinf(a) * sinf(b) * sinf(c)) + (cosf(a) * cosf(c)));
	mat[1][2] = ((sinf(a) * sinf(b) * cosf(c)) - (cosf(a) * sinf(c)));
	mat[2][0] = -sinf(b);
	mat[2][1] = (cosf(b) * sinf(c));
	mat[2][2] = (cosf(b) * cosf(c));
	new_v.x = mat[0][0] * vec.x + mat[0][1] * vec.y + mat[0][2] * vec.z;
	new_v.y = mat[1][0] * vec.x + mat[1][1] * vec.y + mat[1][2] * vec.z;
	new_v.z = mat[2][0] * vec.x + mat[2][1] * vec.y + mat[2][2] * vec.z;
	return (new_v);
}

void	get_spherical_coordinates(t_radians *theta, t_radians *phi, t_vec3 v)
{
	float	radius;

	radius = vec3_length(v);
	*theta = acosf(v.y / radius);
	if (!v.x && !v.z)
	{
		*phi = 0;
		printf("theta: %f, phi: %f\n", *theta, *phi);
		return ;
	}
	*phi = ft_sign_d(v.z) * acosf(v.x / sqrt(v.x * v.x + v.z * v.z));
	printf("theta: %f, phi: %f\n", *theta, *phi);
}

t_vec3	vec3_from_sp(t_radians theta, t_radians phi, float len)
{
	t_vec3	v;

	v.x = len * sinf(theta) * cosf(phi);
	v.y = len * cosf(theta);
	v.z = len * sinf(theta) * sinf(phi);
	return (v);
}
