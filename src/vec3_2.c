/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 23:12:13 by fedmarti          #+#    #+#             */
/*   Updated: 2024/04/05 22:12:48 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry_3d.h"

t_vec3	vec3_scale(t_vec3 v, float scalar)
{
	return ((t_vec3){v.x * scalar, v.y * scalar, v.z * scalar});
}

t_vec3	vec3_invert(t_vec3 v)
{
	return ((t_vec3){-v.x, -v.y, -v.z});
}
