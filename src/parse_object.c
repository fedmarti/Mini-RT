/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_object.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <fedmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 00:44:40 by fedmarti          #+#    #+#             */
/*   Updated: 2024/02/27 20:50:21 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_parsing.h"
#include <math.h>

void	parse_triplet(t_trip_interface interface, t_list *token)
{
	char	*str;

	str = ((t_token *)token->content)->str;
	*interface.x = ft_atof(str);
	while (*str && *str != ',')
		str++;
	str += (*str == ',');
	*interface.y = ft_atof(str);
	while (*str && *str != ',')
		str++;
	str += (*str == ',');
	*interface.z = ft_atof(str);
}

unsigned int	parse_color(t_list *token)
{
	float			red;		
	float			green;		
	float			blue;
	unsigned int	color;

	parse_triplet((t_trip_interface){&red, &green, &blue}, token);
	red = ft_clamp((int)red, 0, 255);
	green = ft_clamp((int)green, 0, 255);
	blue = ft_clamp((int)blue, 0, 255);
	color = 0 | ((int)red << 16 | (int)green << 8 | (int)blue);
	return (color);
}

t_light	light_init(t_list *tokens)
{
	t_light	light;

	parse_triplet((t_trip_interface){&light.x, &light.y, &light.z}, tokens);
	light.brightness = ft_atof(((t_token *)tokens->next->content)->str);
	light.color = parse_color(tokens->next->next);
	return (light);
}

//nt nt ns
t_camera	camera_init(t_list *tokens)
{
	t_camera			camera;
	t_trip_interface	interface;
	float				len;

	interface.x = &camera.x;
	interface.y = &camera.y;
	interface.z = &camera.z;
	parse_triplet(interface, tokens);
	interface.x = &camera.dir_x;
	interface.y = &camera.dir_y;
	interface.z = &camera.dir_z;
	parse_triplet(interface, tokens->next);
	len = sqrt((camera.dir_x * camera.dir_x) + (camera.dir_y \
	* camera.dir_y) + (camera.dir_z * camera.dir_z));
	camera.dir_x /= len;
	camera.dir_y /= len;
	camera.dir_z /= len;
	camera.fov_degrees = ft_atof(((t_token *)tokens->next->next->content)->str);
	return (camera);
}

//ns nt

t_lighting	ambient_init(t_list *tokens)
{
	t_lighting	ambient;

	ambient.ratio = ft_atof(((t_token *)tokens->content)->str);
	ambient.color = parse_color(tokens->next);
	return (ambient);
}
