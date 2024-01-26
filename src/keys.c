/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <fedmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 18:17:47 by fedmarti          #+#    #+#             */
/*   Updated: 2024/01/26 18:17:48 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minirt.h"
#include <mlx_int.h>

int handle_keypress(int pressedKey, t_general *general)
{
	if(general->arrow == (enum arrow)pressedKey)
		return(0);
	if(pressedKey == SPACE)
	{
		if(general->help_info == false)
			general->help_info = true;
		else
			general->help_info = false;
		return(0);
	}
	else if (pressedKey == ESC)
		close_x(general);
	else if(pressedKey == ALT_KEY)
		general->special_key = Alt;
	else if(pressedKey == SHIFT_LEFT_KEY)
		general->special_key = Shift;
	if(pressedKey >= LEFT && pressedKey <= DOWN)
	{
		XAutoRepeatOff(((t_xvar *)(general->program.init_ptr))->display);
		// mlx_do_key_autorepeatoff(general->program.init_ptr);
		general->arrow = pressedKey;
	}
	return(0);
}


int handle_keyrelease (int releasedKey, t_general *general)
{
	if(releasedKey == ALT_KEY && general->special_key == Alt)
		general->special_key = Null;
	else if(releasedKey == SHIFT_LEFT_KEY && general->special_key == Shift)
		general->special_key = Null;
	else if(general->arrow == (enum arrow)releasedKey)
	{
		general->arrow = Null_arrow;
		XAutoRepeatOn(((t_xvar *)(general->program.init_ptr))->display);
		printf("RELEASED!! LIBERO\n");
	}
	return(0);
}