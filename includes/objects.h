/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <fedmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 22:11:57 by fedmarti          #+#    #+#             */
/*   Updated: 2024/04/11 21:10:42 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H
# define NOBJECTTYPES 6

typedef struct s_vector3d
{
	float	x;
	float	y;
	float	z;
}	t_vec3;

enum e_shape_type
{
	Void_shape,
	Plane,
	Sphere,
	Cylinder,
	Line,
	Light
};

typedef struct s_plane
{
	float			x;
	float			y;
	float			z;
	t_vec3			normal;
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
	t_vec3			normal;
	float			diameter;
	float			height;
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
	t_vec3	dir;
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
}	t_scene;

int		get_shape_color(t_shape *shape);
t_vec3	get_shape_position(t_shape *shape);
// if any of the double pointers are not null they will be set to the pointers 
//of the shape structure
void	pointer_to_position(t_shape	*shape, float **x, float **y, float **z);

#endif