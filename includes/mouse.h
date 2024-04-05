/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 21:33:11 by fedmarti          #+#    #+#             */
/*   Updated: 2024/04/05 21:33:22 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOUSE_H
# define MOUSE_H

# define CLK_LEFT 1
# define CLK_RIGHT 3

typedef struct s_mouse
{
	float	mouse_x;
	float	mouse_y;
}	t_mouse;

int	on_click_event(int button, int x, int y, t_general *g);
#endif
