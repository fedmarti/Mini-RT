NAME=mini-rt

SRC=test.c

SRC_PATH=src/

OBJ_PATH=build/

OBJ=$(addprefix $(OBJ_PATH), $(SRC:%.c=%.o))

DEBUG_PREFIX=DB

DEBUG_OBJ=$(addprefix $(OBJ_PATH)$(DEBUG_PREFIX), $(SRC:%.c=%.o))

CC=cc

CFLAGS=-Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $^

debug: $(DEBUG_OBJ)
	$(CC) -o $(NAME) $^

$(OBJ_PATH):
	mkdir $(OBJ_PATH)

$(OBJ_PATH)$(DEBUG_PREFIX)%.o: $(SRC_PATH)%.c $(OBJ_PATH)
	$(CC) $(CFLAGS) -g -c $< -o $@

$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(OBJ_PATH)
	$(CC) $(CFLAGS) -c $< -o $@ 

clean:
	rm -f $(OBJ_PATH)*.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY:	clean fclean re all debug