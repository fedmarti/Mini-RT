/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 23:59:24 by fedmarti          #+#    #+#             */
/*   Updated: 2024/04/14 20:49:48 by fedmarti         ###   ########.fr       */
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
# define MAXPITCH 1.470796327
# define MINPITCH -1.470796327
# define ROTATE_SPEED 0.03f
# define MAX_SHAPE_SIZE 1000.0f

#endif