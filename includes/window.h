#ifndef WINDOW_H
#define WINDOW_H

//KEYPRESS MACRO
# define WIN_WIDTH 720.0f
# define WIN_HEIGHT 480.0f

typedef struct s_window
{
	void	*init_ptr;
	void	*window;
	float	aspectratio;
} t_window;

typedef struct s_general_info
{
	t_mouse mouse;
	enum on_hold on_hold;
	t_window program;
	bool help_info;
} t_general;

t_window *load_window(t_window *main_window, char *title, t_general *general);
int close_x();
int handle_keyrelease (int releasedKey, t_general *general);
int handle_keypress(int pressedKey, t_general *general);


#endif