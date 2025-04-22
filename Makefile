NAME = cub3D
LIB = lib/libft/libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -Ilib/libft/include -Iinclude -g3
SRCS =	src/main.c \
		src/parsing/extract.c \
		src/parsing/checker.c \
		src/parsing/parse.c \

OBJ_DIR = obj

OBJS = $(patsubst %.c,%.o,$(SRCS))
OBJS := $(patsubst src/%, $(OBJ_DIR)/src/%, $(OBJS))

all: $(NAME)

$(NAME): $(OBJS) $(LIB)
	$(CC) $(OBJS) $(LIB) -lreadline -o $(NAME)

$(LIB):
	$(MAKE) -C lib/libft

$(OBJ_DIR)/src/%.o: src/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

-include $(OBJS:.o=.d)

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) clean -C lib/libft

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C  lib/libft

re: fclean all

.PHONY: all clean fclean re bonus
