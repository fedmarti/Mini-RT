/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewport.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 22:11:04 by fedmarti          #+#    #+#             */
/*   Updated: 2024/04/05 22:11:46 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "window.h"
#include <math.h>

void	init_viewport(t_general *general, t_camera *camera)
{
	t_viewport	*v;

	v = &general->viewport;
	v->aspect_ratio = (float)WIN_WIDTH / (float)WIN_HEIGHT;
	v->image_width = WIN_WIDTH;
	v->image_height = WIN_HEIGHT;
	if (v->image_height < 1)
		v->image_height = 1;
	v->viewport_height = 2.0 * tan(camera->fov_degrees * M_PI / 360.0);
	v->viewport_width = v->viewport_height * v->aspect_ratio;
}
