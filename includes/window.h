#ifndef WINDOW_H
#define WINDOW_H

#include "minirt.h"
#include "viewport.h"
# define WIN_WIDTH 480.0f
# define WIN_HEIGHT 260.0f


typedef struct s_window
{
	void	*init_ptr;
	void	*window;
	void	*img_ptr;
	int		*img_data;
	float	aspectratio;
	int 	bits_per_pixel;
	int 	size_line;
	int 	endian;
	char	win_name[30];
} t_window;

typedef struct s_general_info
{
	bool help_info;
	enum e_on_hold special_key;
	t_window program;
	int count;
	void (*handlers[12])(void *general);
	t_viewport viewport;
	t_scene *scene;
	void	*selected;
	int		selected_type;
} t_general;

enum plus_minus
{
	Plus = +1,
	Minus = -1
};

t_window *load_window(t_window *main_window, char *title, t_general *general);
int close_x(t_general *general);
int handle_keyrelease (int releasedKey, t_general *general);
int handle_keypress(int pressedKey, t_general *general);
int render_loop(t_general *general);


void left_on(void *general);
void up_on(void *general);
void right_on(void *general);
void down_on(void *general);

void alt_left_on(void *general);
void alt_up_on(void *general);
void alt_right_on(void *general);
void alt_down_on(void *general);

void shift_left_on(void *general);
void shift_up_on(void *general);
void shift_right_on(void *general);
void shift_down_on(void *general);

void init_viewport(t_general *general, t_camera *camera);
int get_color(t_vec3 raydir, t_scene *scene);
float dot(t_vec3 u, t_vec3 v);
t_vec3	point_at_parameter(t_vec3 origin, t_vec3 raydirection, float t);
float	distance(t_vec3 a, t_vec3 b);
void apply_ambient(t_scene *scene);
t_vec3	get_perpendicular_oc(t_cyl_utils *data);
t_vec3	get_perpendicular_dir(t_cyl_utils *data);
float hit_cyl(t_cylinder *cyl, t_vec3 origin, t_vec3 *raydir, t_cyl_utils *data);
float hit_sphere(t_sphere *sphere, t_vec3 origin, t_vec3 *raydir);
float hit_plane(t_plane *plane, t_vec3 origin, t_vec3 *raydir);
int calculate_cylinder_c(t_cylinder *cyl, t_cyl_utils *data, t_scene *scene, t_vec3 raydir);
int calculate_sphere_color(t_sphere *sphere, t_scene *scene, t_vec3 raydir, float t);
int calculate_plane_color(t_plane *plane, t_scene *scene, t_vec3 raydir, float t);
t_vec3 calculate_lighting(t_vec3 hit_point, t_vec3 normal, t_vec3 base_col, t_light light);
int loop_light(t_scene *scene, t_vec3 hit_point, t_vec3 norm, int base_col);
int apply_ambient_light(int color, float intensity, unsigned int ambientColor);
t_hit hit_shape(t_shape	*obj, t_camera *camera, t_cyl_utils *data, t_vec3 *raydir);
void rotate_raydir(t_vec3 *raydir, t_vec3 camera);
t_vec3	vec3_invert(t_vec3 v);
void move_obj(float *val, enum plus_minus sign);
#endif