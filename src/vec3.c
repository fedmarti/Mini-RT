/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 23:12:13 by fedmarti          #+#    #+#             */
/*   Updated: 2024/01/28 23:35:35 by fedmarti         ###   ########.fr       */
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
	//rcoddio so troppo stanco per sta roba, la faccio domani	
}