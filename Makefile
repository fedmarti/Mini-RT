NAME=miniRT

SRC= main.c \
mouse.c \
new_token.c \
new_token2.c \
parse_object.c \
parse_shapes.c \
parsing.c \
remove_comments.c \
scene.c \
tokenizer.c \
keys.c \
window.c \
arrow_alted.c \
arrow_shifted.c \
arrow.c \
viewport.c \
vec3.c \
vec3_2.c \
render_loop.c \
get_color.c \
calc.c \
cylinder.c \
cyl_color.c \
ambient_light.c \
sphere.c \
plane.c \
sphere_color.c \
plane_color.c \
light.c \
shape.c \
shape2.c \

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
LIBRARIES = $(LIBFT) $(MLX) m Xext X11

##
#defines the flags for each library
LINKS= $(filter-out -L./, $(addprefix -L, $(dir $(LIBRARIES)))) $(addprefix -l, $(call strip_archive, $(LIBRARIES)))

##
#flags with path for the headers
INCLUDES=-I./includes -I$(dir $(LIBFT)) -I$(dir $(MLX))

CFLAGS= -Wall -Wextra -Werror

all: $(NAME)

##compiles the project
$(NAME): $(OBJ) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LINKS)

##compiles the project with debug info
debug: $(DEBUG_OBJ) $(LIBFT)
	$(CC) -o $(NAME) $^ $(LINKS)

#makes build dir
$(OBJ_PATH):
	mkdir $(OBJ_PATH)

##compiles debug object files in the build directory, creates the directory if needed
$(OBJ_PATH)$(DEBUG_PREFIX)%.o: $(SRC_PATH)%.c
	$(CC) $(CFLAGS) -g -c $< -o $@ $(INCLUDES)

##compiles object files in the build directory, creates the directory if needed
$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

##makes libft
$(LIBFT):
	make -C $(dir $(LIBFT))

$(MLX):
	make -C $(dir $(MLX))

##removes all object files
clean:
	rm -f $(OBJ_PATH)*.o

#also removes binary
fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY:	clean fclean re all debug
