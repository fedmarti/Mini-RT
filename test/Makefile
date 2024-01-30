ROTATION=rot_test

BUILD=./build/

GLM_DIR=./cglm/

GML=$(GLM_DIR)build/libcglm.so

GLM_HEADERS=$(GLM_DIR)include/cglm

ROTATION_SRC=rotate_vec.c

ROTATION_OBJ:=$(BUILD)$(ROTATION_SRC:%.c=%.o) ../build/vec3.o

CC=cc

CFLAGS=-Wall -Wextra -Werror -g

all: $(ROTATION)

../build/%.o: ../src/%.c
	make -C .. $(patsubst ../%,%,$@)

$(ROTATION): $(ROTATION_OBJ) $(GML)
	$(CC) $(CFLAGS) -o $@ $^ -lm -I../includes -I$(GLM_HEADERS)

$(BUILD)%.o:%.c $(BUILD)
	$(CC) $(CFLAGS) -o $@ -c $<

$(BUILD):
	mkdir $@

clean:
	rm -f $(BUILD)/*.o

fclean: clean
	rm -f $(ROTATION)

.PHONY: clean fclean all