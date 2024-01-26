#ifndef WINDOW_H
#define WINDOW_H


#include "minirt.h"
//KEYPRESS MACRO
# define WIN_WIDTH 720.0f
# define WIN_HEIGHT 480.0f

typedef struct s_window
{
	void	*init_ptr;
	void	*window;
	float	aspectratio;
	char	win_name[30];
} t_window;

typedef struct s_general_info
{
	bool help_info;
	enum on_hold special_key;
	enum arrow arrow;
	t_window program;
	void (*handlers[4])(void *general);
} t_general;

t_window *load_window(t_window *main_window, char *title, t_general *general);
int close_x(t_general *general);
int handle_keyrelease (int releasedKey, t_general *general);
int handle_keypress(int pressedKey, t_general *general);
void left_on(void *general);
void up_on(void *general);
void right_on(void *general);
void down_on(void *general);


#endif