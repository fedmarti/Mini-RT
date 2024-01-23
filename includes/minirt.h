/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shhuang <dsheng1993@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 23:59:24 by fedmarti          #+#    #+#             */
/*   Updated: 2024/01/23 18:05:42 by shhuang          ###   ########.fr       */
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
# include <stdlib.h>
# include <unistd.h>
# include "../minilibx-linux/mlx.h"
# include "shapes.h"
# include "scene.h"
# include "window.h"
# include "mouse.h"

# define WIN_WIDTH 720.0f
# define WIN_HEIGHT 480.0f
# define RAY_LENGTH 1000.0F

#endif