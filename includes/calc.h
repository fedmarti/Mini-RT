#ifndef CALC_H
#define CALC_H

#include "minirt.h"

enum e_cyl_hit
{
	Outside_Surface,
	Inside_Surface,
	Base
};

typedef struct s_cyl_utils
{
	t_vec3			oc;
	t_vec3			raydir;
	t_vec3			origin;
	t_vec3			axis_normalize;
	float			dot_dir_axis;
	float			dot_oc_axis;
	float			min_t;
	enum e_cyl_hit	flag;
	float			t[2];
	bool			hit;
	bool			base_is_top;
} t_cyl_utils;

#endif