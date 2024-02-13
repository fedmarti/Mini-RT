#ifndef WINDOW_H
#define WINDOW_H


#include "minirt.h"
#include "viewport.h"
//KEYPRESS MACRO
# define ASPECT_RATIO 4.0/3.0
# define WIN_WIDTH 720.0f
# define WIN_HEIGHT 480.0f


typedef struct s_window
{
	void	*init_ptr;
	void	*win_ptr;
	int 	*img_ptr;
	int		*img_data;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	float	aspectratio;
	char	win_name[30];
} t_window;

typedef struct s_general_info
{
	bool help_info;
	enum e_on_hold special_key;
	t_window window;
	int count;
	void (*handlers[12])(void *general);
	t_viewport viewport;
} t_general;

t_window *load_window(t_window *main_window, char *title, t_general *general);
int close_x(t_general *general);
int handle_keyrelease (int releasedKey, t_general *general);
int handle_keypress(int pressedKey, t_general *general);


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
void render(t_general* general, t_scene *scene);
#endif