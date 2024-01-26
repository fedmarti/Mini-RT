/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <fedmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 22:26:34 by fedmarti          #+#    #+#             */
/*   Updated: 2024/01/26 18:03:03 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H
# include "shapes.h"

typedef	t_image;

typedef struct s_ambient_lighting
{
	float	ratio;
	int		color;
}	t_lighting;

typedef struct s_light_point
{
	float	x;
	float	y;
	float	z;
	float	normal_x;
	float	normal_y;
	float	normal_z;
	int		color;
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