/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry_3d.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 22:55:41 by fedmarti          #+#    #+#             */
/*   Updated: 2024/01/28 23:20:26 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GEOMETRY_3D_H
# define GEOMETRY_3D_H

# include "objects.h"
# include <math.h>

typedef struct s_vector3d
{
	float	x;
	float	y;
	float	z;
}	t_vec3;

typedef struct s_ray_hit
{
	float	x;
	float	y;
	float	z;
	t_shape	*shape;
}	t_hit;



#endif