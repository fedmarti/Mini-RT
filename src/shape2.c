/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 00:07:53 by fedmarti          #+#    #+#             */
/*   Updated: 2024/04/15 00:45:05 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry_3d.h"
#include "libft.h"

static void	interface_data(t_shape *shape, \
			t_vec3 **normal, t_radians *angles[2])
{
	if (shape->type == Cylinder)
	{
		*normal = &shape->shape.cylinder.normal;
		angles[0] = &shape->shape.cylinder.theta;
		angles[1] = &shape->shape.cylinder.phi;
	}
	else if (shape->type == Plane)
	{
		*normal = &shape->shape.plane.normal;
		angles[0] = &shape->shape.plane.theta;
		angles[1] = &shape->shape.plane.phi;
	}
	else
	{
		*normal = NULL;
		ft_bzero(angles, sizeof(t_radians *[2]));
	}
}

void	pointer_to_orientation(t_shape *shape, \
		t_vec3 **normal, t_radians **theta, t_radians **phi)
{
	t_vec3		*n;
	t_radians	*angles[2];

	interface_data(shape, &n, angles);
	if (normal)
		*normal = n;
	if (theta)
		*theta = angles[0];
	if (phi)
		*phi = angles[1];
}
