/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 21:53:22 by fedmarti          #+#    #+#             */
/*   Updated: 2024/04/15 05:35:21 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3	plane_hit_norm(t_plane *plane, t_vec3 hit_point)
{
	(void)hit_point;
	return (plane->normal);
}
