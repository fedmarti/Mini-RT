/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <fedmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 20:26:38 by fedmarti          #+#    #+#             */
/*   Updated: 2024/01/22 20:29:26 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

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