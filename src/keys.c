/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shhuang <dsheng1993@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 18:17:47 by fedmarti          #+#    #+#             */
/*   Updated: 2024/01/27 13:44:48 by shhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <mlx_int.h>

int handle_keypress(int pressedKey, t_general *general)
{
	if((unsigned int)pressedKey-65361 < 4)
	{
		(*general->handlers[pressedKey - general->special_key])(general);
		return(0);
	}
	if(pressedKey == SPACE)
	{
		if(general->help_info == false)
			general->help_info = true;
		else
			general->help_info = false;
		return(0);
	}
	else if(pressedKey == ALT_KEY)
		general->special_key = Alt;
	else if(pressedKey == SHIFT_LEFT_KEY)
		general->special_key = Shift;
	else if(pressedKey == ENTER)
		serious_render();
	else if (pressedKey == ESC)
		close_x(general);
	return(0);
}


int handle_keyrelease (int releasedKey, t_general *general)
{
	if(releasedKey == ALT_KEY && general->special_key == Alt)
		general->special_key = Null;
	else if(releasedKey == SHIFT_LEFT_KEY && general->special_key == Shift)
		general->special_key = Null;
	else if(releasedKey >= LEFT && releasedKey <= DOWN && general->count > AT_LEAST)
	{
		printf("Rilascio..\n\nRENDERING\n\n");
		general->count = 0;
	}
	return(0);
}