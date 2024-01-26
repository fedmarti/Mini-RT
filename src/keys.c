/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shhuang <dsheng1993@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 18:17:47 by fedmarti          #+#    #+#             */
/*   Updated: 2024/01/27 00:17:32 by shhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <mlx_int.h>

int handle_keypress(int pressedKey, t_general *general)
{
	int eval;
	eval = 0;
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
		general->arrow = pressedKey;
		eval = general->arrow;
		if(general->special_key == Alt)
			eval += 8;
		else if(general->special_key == Shift)
			eval += 4;
		(*general->handlers[eval - 65361])(general);
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
		printf("Rilascio..\n\nRENDERING\n\n");
	}
	return(0);
}