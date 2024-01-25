/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_shapes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 12:25:56 by fedmarti          #+#    #+#             */
/*   Updated: 2024/01/24 13:04:32 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_parsing.h"

//nt ns nt

t_sphere	sphere_init(t_list *tokens)
{
	t_sphere	sphere;

	parse_triplet((t_trip_interface){&sphere.x, &sphere.y, &sphere.z}, tokens);
	sphere.diameter = ft_atof(((t_token *)tokens->next->content)->str);
	sphere.color = parse_color(tokens->next->next);
	return (sphere);
}

//nt nt nt

t_plane	plane_init(t_list *tokens)
{
	t_plane				plane;
	t_trip_interface	interface;

	interface = (t_trip_interface){&plane.x, &plane.y, &plane.z};
	parse_triplet(interface, tokens);
	interface.x = &plane.normal_x;
	interface.y = &plane.normal_y;
	interface.z = &plane.normal_z;
	parse_triplet(interface, tokens->next);
	plane.color = parse_color(tokens->next->next);
	return (plane);
}

//nt nt ns ns nt

t_cylinder	cylinder_init(t_list *tokens)
{
	t_cylinder			cylinder;
	t_trip_interface	interface;

	interface = (t_trip_interface){&cylinder.x, &cylinder.y, &cylinder.z};
	parse_triplet(interface, tokens);
	interface = (t_trip_interface){&cylinder.normal_x, &cylinder.normal_y, \
	&cylinder.normal_z};
	parse_triplet(interface, tokens->next);
	cylinder.diameter = ft_atof(((t_token *)tokens->next->next->content)->str);
	tokens = tokens->next->next->next;
	cylinder.height = ft_atof(((t_token *)tokens->content)->str);
	cylinder.color = parse_color(tokens->next);
	return (cylinder);
}

t_shape	shape_init(t_list *tokens)
{
	t_shape	shape;
	char	*str;

	str = ((t_token *)tokens->content)->str;
	if (!ft_strncmp(str, SPHERE, ft_strlen(SPHERE) + 1))
	{
		shape.shape.sphere = sphere_init(tokens->next);
		shape.type = Sphere;
	}
	else if (!ft_strncmp(str, PLANE, ft_strlen(PLANE) + 1))
	{
		shape.shape.plane = plane_init(tokens->next);
		shape.type = Plane;
	}
	else if (!ft_strncmp(str, CYLINDER, ft_strlen(CYLINDER) + 1))
	{
		shape.shape.cylinder = cylinder_init(tokens->next);
		shape.type = Cylinder;
	}
	return (shape);
}
