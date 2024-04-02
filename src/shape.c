/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <fedmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 23:19:33 by fedmarti          #+#    #+#             */
/*   Updated: 2024/04/02 23:02:17 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"
#include "geometry_3d.h"

//returns the color of the shape (for quick access)
int	get_shape_color(t_shape *shape)
{
	if (shape->type == Cylinder)
		return (shape->shape.cylinder.color);
	else if (shape->type == Sphere)
		return (shape->shape.sphere.color);
	else if (shape->type == Plane)
		return (shape->shape.plane.color);
	return (0);
}

//copies xyz position of any shape into vec3 v
t_vec3	get_shape_position(t_shape *shape)
{
	t_vec3	v;

	if (shape->type == Cylinder)
	{
		v.x = shape->shape.cylinder.x;
		v.y = shape->shape.cylinder.y;
		v.z = shape->shape.cylinder.z;
	}
	else if (shape->type == Sphere)
	{
		v.x = shape->shape.sphere.x;
		v.y = shape->shape.sphere.y;
		v.z = shape->shape.sphere.z;
	}
	else if (shape->type == Plane)
	{
		v.x = shape->shape.plane.x;
		v.y = shape->shape.plane.y;
		v.z = shape->shape.plane.z;
	}
	else
		return ((t_vec3){0});
	return (v);
}
