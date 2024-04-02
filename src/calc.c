/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <fedmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 21:39:12 by shhuang           #+#    #+#             */
/*   Updated: 2024/04/02 23:59:02 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

float	dot(t_vec3 u, t_vec3 v)
{
	return (u.x * v.x + u.y * v.y + u.z * v.z);
}

t_vec3	point_at_parameter(t_vec3 origin, t_vec3 raydirection, float t)
{
	return ((t_vec3){origin.x + t * raydirection.x, origin.y \
	+ t * raydirection.y, origin.z + t * raydirection.z});
}

float	distance(t_vec3 a, t_vec3 b)
{
	return (sqrt(dot(vec3_substract(a, b), vec3_substract(a, b))));
}
