/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_map.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 00:48:46 by fedmarti          #+#    #+#             */
/*   Updated: 2024/02/20 00:53:45 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_MAP_H
# define INPUT_MAP_H

# include <stdbool.h>

typedef struct s_input_map
{
	bool	up;
	bool	down;
	bool	right;
	bool	left;
	bool	shift;
	bool	ctrl_left;
//	... da espandere o ristrutturare
}	t_input;

/*
dentro la funzione di mlx_loop_hook:
{
	t_input this_frame_input; faranno parte di general
	t_input last_frame_input;

	if (this_frame_input != last_frame_input)
	{
		rerender;
	}
}
*/

#endif