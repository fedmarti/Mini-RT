NAME=miniRT

SRC=main.c \
	window.c \
	new_token.c \
	scene.c \
	parsing.c \
	tokenizer.c \

MLX=./minilibx-linux/libmlx.a

LIBFT=./libft/libft.a

SRC_PATH=src/

OBJ_PATH=build/

OBJ=$(addprefix $(OBJ_PATH), $(SRC:%.c=%.o))

DEBUG_PREFIX=DB

DEBUG_OBJ=$(addprefix $(OBJ_PATH)$(DEBUG_PREFIX), $(SRC:%.c=%.o))

CC=cc

##
#removes the directory part of the argument and then removes lib- -.a from it
strip_archive = $(patsubst lib%.a,%,$(notdir $1))

##
#defines libraries that need to be linked at compile time
LIBRARIES = $(LIBFT) $(MLX) -lm -lXext -lX11

LINKS = $(addprefix -L, $(dir $(LIBFT) $(MLX))) $(LIBRARIES)

##
#flags with path for the headers
INCLUDES=-I./includes -I$(dir $(LIBFT)) -I$(dir $(MLX))

#CFLAGS=-Wall -Wextra -Werror commentato per ora

all: $(NAME)

##compiles the project
$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LINKS)

##compiles the project with debug info
debug: $(DEBUG_OBJ) $(LIBFT)
	$(CC) -o $(NAME) $^ $(LINKS)

#makes build dir
$(OBJ_PATH):
	mkdir $(OBJ_PATH)

##compiles debug object files in the build directory, creates the directory if needed
$(OBJ_PATH)$(DEBUG_PREFIX)%.o: $(SRC_PATH)%.c $(OBJ_PATH)
	$(CC) $(CFLAGS) -g -c $< -o $@ $(INCLUDES)

##compiles object files in the build directory, creates the directory if needed
$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(OBJ_PATH)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

##makes libft
$(LIBFT):
	make -C $(dir $(LIBFT))

##removes all object files
clean:
	rm -f $(OBJ_PATH)*.o

#also removes binary
fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY:	clean fclean re all debug