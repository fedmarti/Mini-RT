/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 23:12:13 by fedmarti          #+#    #+#             */
/*   Updated: 2024/01/30 00:17:14 by fedmarti         ###   ########.fr       */
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
	t_vec3	new;

	new.x = vec.x * (cos(x) * cos(y)) + vec.y * (cos(x) * sin(y) * sin(z) - \
	(sin(x) * cos(z))) + vec.z * (cos(x) * sin(y) * cos(z) + sin(x) * sin(z));
	new.y = vec.x * (sin(x) * cos(y)) + vec.y * (sin(x) * sin(y) * sin(z) \
	+ cos(x) * cos(z)) + vec.z * (sin(x) * sin(y) * cos(z) - (cos(x) * sin(z)));
	new.z = vec.x * (-1 * (sin(y))) + vec.y * (cos(y) * sin(z)) + vec.z \
	* (cos(y) * cos(z));
	return (new);
}

// #include <stdio.h>

// int main(void)
// {
// 	t_vec3	vector = {0, 0, 1};
// 	t_radians	rot_x, rot_y, rot_z;

// 	printf("vector: [%f, %f, %f]\n", vector.x, vector.y, vector.z);
// 	printf("x angle:\n");
// 	scanf("%f", &rot_x);
// 	printf("y angle:\n");
// 	scanf("%f", &rot_y);
// 	printf("z angle:\n");
// 	scanf("%f", &rot_z);
// 	vector = vec3_rotate(vector, rot_x, rot_y, rot_z);
// 	printf("vector: [%f, %f, %f]\n", vector.x, vector.y, vector.z);
// }