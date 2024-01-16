/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <fedmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 22:11:57 by fedmarti          #+#    #+#             */
/*   Updated: 2024/01/15 22:23:50 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAPES_H
# define SHAPES_H

enum e_shape_type
{
	Plane,
	Sphere,
	Cylinder,
	Line
};

typedef struct s_plane
{
	float	x;
	float	y;
	float	z;
	float	normal_x;
	float	normal_y;
	float	normal_z;
	int		color;
}	t_plane;

typedef struct s_sphere
{
	float	x;
	float	y;
	float	z;
	float	diameter;
	int		color;
}	t_sphere;

typedef struct s_cylinder
{
	float	x;
	float	y;
	float	z;
	float	normal_x;
	float	normal_y;
	float	normal_z;
	float	height;
	float	diameter;
	int		color;
}	t_cylinder;


union u_shape
{
	t_plane		plane;
	t_sphere	sphere;
	t_cylinder	cylinder;
};

typedef struct s_shape
{
	enum e_shape_type	type;
	union u_shape		shape;
}	t_shape;

#endif