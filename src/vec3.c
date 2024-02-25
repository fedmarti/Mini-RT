/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shhuang <dsheng1993@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 23:12:13 by fedmarti          #+#    #+#             */
/*   Updated: 2024/02/24 05:32:08 by shhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry_3d.h"

t_vec3	vec3_normalize(t_vec3 v)
{
	const float	len = (float)sqrt(pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2));

	return ((t_vec3){v.x / len, v.y / len, v.z / len});
}

float	vec3_length(t_vec3 v)
{
	return ((float)sqrt(pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2)));
}

t_vec3	vec3_substract(t_vec3 v1, t_vec3 v2)
{
	return ((t_vec3){v1.x - v2.x, v1.y - v2.y, v1.z - v2.z});
}

t_vec3	vec3_multiply(t_vec3 v1, t_vec3 v2)
{
	return ((t_vec3){v1.x * v2.x, v1.y * v2.y, v1.z * v2.z});
}

t_vec3	vec3_add(t_vec3 v1, t_vec3 v2)
{
	return ((t_vec3){v1.x + v2.x, v1.y + v2.y, v1.z + v2.z});
}

t_vec3	vec3_scale(t_vec3 v, float scalar)
{
	return ((t_vec3){v.x * scalar, v.y * scalar, v.z * scalar});
}

t_vec3	vec3_rotate(t_vec3 vec, t_radians x, t_radians y, t_radians z)
{
	t_vec3	new;
	t_vec3	cos;
	t_vec3	sin;

	cos = (t_vec3){cosf(x), cosf(y), cosf(z)};
	sin = (t_vec3){sinf(x), sinf(y), sinf(z)};
	new.x = vec.x * (cos.x * cos.y) + vec.y * (cos.x * sin.y * sin.z - \
	(sin.x * cos.z)) + vec.z * (cos.x * sin.y * cos.z + sin.x * sin.z);
	new.y = vec.x * (sin.x * cos.y) + vec.y * (sin.x * sin.y * sin.z \
	+ cos.x * cos.z) + vec.z * (sin.x * sin.y * cos.z - (cos.x * sin.z));
	new.z = vec.x * (-1 * (sin.y)) + vec.y * (cos.y * sin.z) + vec.z \
	* (cos.y * cos.z);
	return (new);
}
