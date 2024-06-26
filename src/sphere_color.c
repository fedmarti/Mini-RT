/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 21:37:10 by fedmarti          #+#    #+#             */
/*   Updated: 2024/04/05 21:37:13 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3	sphere_hit_norm(t_sphere *sphere, t_vec3 hit_point)
{
	return (vec3_normalize(vec3_substract(hit_point, \
	(t_vec3){sphere->x, sphere->y, sphere->z})));
}
