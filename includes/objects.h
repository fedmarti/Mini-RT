/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shhuang <dsheng1993@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 22:11:57 by fedmarti          #+#    #+#             */
/*   Updated: 2024/02/25 07:37:55 by shhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H
# define NOBJECTTYPES 6

enum e_shape_type
{
	Plane,
	Sphere,
	Cylinder,
	Line
};

typedef struct s_plane
{
	float			x;
	float			y;
	float			z;
	float			normal_x;
	float			normal_y;
	float			normal_z;
	unsigned int	color;
}	t_plane;

typedef struct s_sphere
{
	float			x;
	float			y;
	float			z;
	float			diameter;
	unsigned int	color;
}	t_sphere;

typedef struct s_cylinder
{
	float			x;
	float			y;
	float			z;
	float			normal_x;
	float			normal_y;
	float			normal_z;
	float			height;
	float			diameter;
	unsigned int	color;
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

// typedef  struct s_image	t_image;

typedef struct s_ambient_lighting
{
	float			ratio;
	unsigned int	color;
}	t_lighting;

typedef struct s_light_point
{
	float			x;
	float			y;
	float			z;
	float			brightness;
	unsigned int	color;
}	t_light;

typedef struct s_camera
{
	float	x;
	float	y;
	float	z;
	float	dir_x;
	float	dir_y;
	float	dir_z;
	float	fov_degrees;

}	t_camera;

typedef struct s_scene
{
	t_lighting		ambient;
	t_camera		camera;
	t_shape			*shapes;
	unsigned short	shape_n;
	t_light			*lights;
	unsigned short	light_n;
	// t_image			render;
}	t_scene;

#endif