/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 21:32:07 by fedmarti          #+#    #+#             */
/*   Updated: 2024/04/05 21:32:13 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CALC_H
# define CALC_H

# include "minirt.h"

enum e_cyl_hit
{
	Outside_Surface,
	Inside_Surface,
	Base_Top,
	Base_Bottom,
	Missed
};

typedef struct s_cyl_utils
{
	float			dot_dir_axis;
	float			dot_oc_axis;
	t_vec3			oc_perpend;
	t_vec3			dir_perpend;
}	t_cyl_utils;

#endif