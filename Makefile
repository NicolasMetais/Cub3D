NAME = cub3D
LIB = lib/libft/libft.a
MLX = lib/minilibx-linux/libmlx.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -Ilib/libft/include -Ilib/minilibx-linux -Iinclude -g3 -O3
SRCS =	src/main.c \
		src/utils/copy_img.c \
		src/utils/extension.c \
		src/utils/power_of_two.c \
		src/utils/empty_line.c \
		src/utils/cleanup_split.c \
		src/utils/sprite_udpate.c \
		src/utils/transparency.c \
		src/parsing/map_extract.c \
		src/parsing/parse_main.c \
		src/parsing/textures_colors.c \
		src/parsing/flag_position.c \
		src/parsing/textures_content.c \
		src/parsing/parse_map.c \
		src/parsing/flood_fill.c \
		src/game/main_game.c \
		src/game/routine.c \
		src/game/maps_names.c \
		src/game/destroy_img.c \
		src/game/events/destroy.c \
		src/game/events/keyboard/keypress_maps.c \
		src/game/events/keyboard/keypress.c \
		src/game/events/mouse/mouse_over.c \
		src/game/events/mouse/option_menu_over.c \
		src/game/events/mouse/mouse_release.c \
		src/game/events/mouse/mouse_click.c \
		src/game/menu/render_menu.c \
		src/game/menu/slider.c \
		src/game/menu/loaded_map.c \
		src/game/menu/render_options_menu.c \
		src/game/menu/render_maps_menu.c \
		src/game/menu/start_menu.c \
		src/game/char_setup/init_char_nodes.c \
		src/game/char_setup/build_words.c \
		src/game/char_setup/build_words_utils.c \
		src/game/image_loader.c \
		src/game/config_parse.c \
		src/game/hashmap/hashmap.c \
		src/game/hashmap/hashmap_del.c \
		src/utils/cleanup_game.c \

OBJ_DIR = obj

OBJS = $(patsubst %.c,%.o,$(SRCS))
OBJS := $(patsubst src/%, $(OBJ_DIR)/src/%, $(OBJS))

all: $(NAME)

$(NAME): $(OBJS) $(LIB) $(MLX)
	$(CC) $(OBJS) $(LIB) $(MLX) -lX11 -lXext -lm -o $(NAME)

$(LIB):
	$(MAKE) -C lib/libft

$(MLX):
	$(MAKE) -C lib/minilibx-linux

$(OBJ_DIR)/src/%.o: src/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

-include $(OBJS:.o=.d)

f: re
	$(CC) $(OBJS) $(LIB) $(MLX) -lX11 -lXext -lm -o $(NAME) -fsanitize=address

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) clean -C lib/libft
	$(MAKE) clean -C lib/minilibx-linux

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
