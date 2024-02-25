/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shhuang <dsheng1993@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 23:59:24 by fedmarti          #+#    #+#             */
/*   Updated: 2024/02/25 11:33:19 by shhuang          ###   ########.fr       */
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
# include "mouse.h"
# include "keys.h"
# include "calc.h"
# include "window.h"
# include "viewport.h"
# include "screen_coord.h"

void	free_scene(t_scene *scene);

# define RAY_LENGTH 1000.0F

#endif