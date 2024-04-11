/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shhuang <dsheng1993@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 23:59:24 by fedmarti          #+#    #+#             */
/*   Updated: 2024/04/11 10:11:14 by shhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>
# include <fcntl.h>
# include <png.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"
# include "mlx.h"
# include "objects.h"
# include "geometry_3d.h"
# include "keys.h"
# include "calc.h"
# include "window.h"
# include "viewport.h"
# include "screen_coord.h"
# include "mouse.h"

void	free_scene(t_scene *scene);

# define RAY_LENGTH 1000.0F
# define WIN_NAME_LEN 30
#define MAXPITCH M_PI / 2 - 0.1
#define MINPITCH -M_PI / 2 + 0.1

#endif