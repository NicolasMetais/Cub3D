NAME = cub3D
LIB = lib/libft/libft.a
MLX = lib/minilibx-linux/libmlx.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -Ilib/libft/include -Ilib/minilibx-linux -Iinclude -g3
SRCS =	src/main.c \
		src/utils/extension.c \
		src/utils/empty_line.c \
		src/parsing/map_extract.c \
		src/parsing/parse_main.c \
		src/parsing/textures_colors.c \
		src/parsing/flag_position.c \
		src/parsing/textures_content.c \
		src/parsing/parse_map.c \
		src/parsing/flood_fill.c \
		src/game/main_game.c \
		src/game/routine.c \
		src/game/events/destroy.c \
		src/game/events/keypress.c \

OBJ_DIR = obj

OBJS = $(patsubst %.c,%.o,$(SRCS))
OBJS := $(patsubst src/%, $(OBJ_DIR)/src/%, $(OBJS))

all: $(NAME)

$(NAME): $(OBJS) $(LIB)
	$(CC) $(OBJS) $(LIB) $(MLX) -lX11 -lXext -o $(NAME)

$(LIB):
	$(MAKE) -C lib/libft

$(OBJ_DIR)/src/%.o: src/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

-include $(OBJS:.o=.d)

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) clean -C lib/libft
	$(MAKE) clean -C ./minilibx-linux/

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C  lib/libft

re: fclean all

.PHONY: all clean fclean re bonus
