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

enum on_hold
{
	Null = 0,
	Shift,
	Alt
};

enum arrow
{
	Null_arrow = 0,
	Left = 65361,
	Up,
	Right,
	Down
};

void left_on();
void up_on();
void right_on();
void down_on();

extern void (*handlers[])(void);

#endif
