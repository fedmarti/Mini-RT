/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 23:12:13 by fedmarti          #+#    #+#             */
/*   Updated: 2024/01/28 23:21:25 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry_3d.h"

t_vec3	normalize(t_vec3 v)
{
	const float	len = (float)sqrt(pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2));

	return ((t_vec3){v.x / len, v.y / len, v.z / len});
}

float	length(t_vec3 v)
{
	return ((float)sqrt(pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2)));
}
