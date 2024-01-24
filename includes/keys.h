#ifndef KEYS_H
#define KEYS_H

#define ESC 65307

#define UP 65362
#define DOWN 65364
#define LEFT 65361
#define RIGHT 65363
#define SPACE 32
#define SHIFT_LEFT_KEY 65505
#define ALT_KEY 65513



typedef struct s_keys 
{
	bool ctrl;
	bool shift;
	bool arr_up;
	bool arr_down;
	bool arr_left;
	bool arr_right;
	bool help_info;
	unsigned int count_pressed;
} t_keys;

int handle_keyrelease (int releasedKey, t_keys *status);
int handle_keypress(int pressedKey, t_keys *status);

#endif