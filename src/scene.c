/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shhuang <dsheng1993@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 20:26:38 by fedmarti          #+#    #+#             */
/*   Updated: 2024/02/23 09:03:34 by shhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"
#include "libft.h"
#include "rt_parsing.h"
#include "symbols.h"

void	free_scene(t_scene *scene)
{
	if (!scene)
		return ;
	if (scene->shapes)
		free(scene->shapes);
	if (scene->lights)
		free(scene->lights);
	free(scene);
}

void	count_lights_and_shapes(t_list *tokens, t_scene *scene)
{
	t_token	*temp;

	while (tokens)
	{
		temp = tokens->content;
		if (!ft_strncmp(temp->str, LIGHT, INT_MAX))
			scene->light_n++;
		else if (!ft_strncmp(temp->str, SPHERE, INT_MAX) \
		|| !ft_strncmp(temp->str, CYLINDER, INT_MAX) \
		|| !ft_strncmp(temp->str, PLANE, INT_MAX))
			scene->shape_n++;
		tokens = tokens->next;
	}
}

t_scene	*scene_allocate(t_list *tokens)
{
	t_scene	*scene;

	scene = ft_calloc(1, sizeof(*scene));
	if (!scene)
		return (NULL);
	count_lights_and_shapes(tokens, scene);
	if (scene->light_n)
	{
		scene->lights = malloc(sizeof(*scene->lights) * scene->light_n);
		if (!scene->lights)
		{
			free_scene(scene);
			return (NULL);
		}
	}
	if (scene->shape_n)
	{
		scene->shapes = malloc(sizeof(*scene->shapes) * scene->shape_n);
		if (!scene->shapes)
		{
			free_scene(scene);
			return (NULL);
		}
	}
	return (scene);
}

t_scene	*parse_tokens(t_list *tokens)
{
	t_scene	*scene;
	int		shape;
	int		light;

	scene = scene_allocate(tokens);
	if (!scene)
		return (NULL);
	shape = 0;
	light = 0;
	while (tokens)
	{
		if (!ft_strncmp(((t_token *)tokens->content)->str, CAMERA, INT_MAX))
			scene->camera = camera_init(tokens->next);
		else if (!ft_strncmp(((t_token *)tokens->content)->str, \
			AMBIENT_LIGTHING, INT_MAX))
			scene->ambient = ambient_init(tokens->next);
		else if (!ft_strncmp(((t_token *)tokens->content)->str, LIGHT, INT_MAX))
			scene->lights[light++] = light_init(tokens->next);
		else
			scene->shapes[shape++] = shape_init(tokens);
		tokens = tokens->next;
		while (tokens && ((t_token *)tokens->content)->type != ObjType)
			tokens = tokens->next;
	}
	return (scene);
}
