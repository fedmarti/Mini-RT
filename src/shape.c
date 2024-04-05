/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 23:19:33 by fedmarti          #+#    #+#             */
/*   Updated: 2024/04/05 01:27:38 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"
#include "geometry_3d.h"
#include "libft.h"

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


static void	inteface_coordinates(t_shape *shape, float *coordinates[3])
{
	if (shape->type == Cylinder)
	{
		coordinates[0] = &shape->shape.cylinder.x;
		coordinates[1] = &shape->shape.cylinder.y;
		coordinates[2] = &shape->shape.cylinder.z;
	}
	else if (shape->type == Sphere)
	{
		coordinates[0] = &shape->shape.sphere.x;
		coordinates[1] = &shape->shape.sphere.y;
		coordinates[2] = &shape->shape.sphere.z;
	}
	else if (shape->type == Plane)
	{
		coordinates[0] = &shape->shape.plane.x;
		coordinates[1] = &shape->shape.plane.y;
		coordinates[2] = &shape->shape.plane.z;
	}
	else
		ft_bzero(coordinates, sizeof(float *[3]));
}


void	pointer_to_position(t_shape	*shape, float **x, float **y, float **z)
{
	float	*coordinates[3];

	inteface_coordinates(shape, coordinates);
	if (x)
	{
		*x = coordinates[0];
	}
	if (y)
	{
		*y = coordinates[1];
	}
	if (z)
	{
		*z = coordinates[2];
	}
}
