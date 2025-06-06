NAME = cub3D
LIB = lib/libft/libft.a
MLX = lib/minilibx-linux/libmlx.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -Ilib/libft/include -Ilib/minilibx-linux -Iinclude -g3 -O3
SRCS =	$(MAIN)$(EVENTS)$(IMG)$(MENU)$(HUD)$(UTILS)$(PARSING)$(GAME)$(WEAPONS)

MAIN =	src/main.c \
		src/game/main_game.c \
		src/game/routine.c \
		src/game/maps_names.c \
		src/game/game_init.c \

EVENTS = 	src/game/events/destroy.c \
			src/game/events/keyboard/keypress_maps.c \
			src/game/events/keyboard/keypress_game.c \
			src/game/events/keyboard/keypress.c \
			src/game/events/keyboard/keyrelease.c \
			src/game/events/mouse/mouse_over.c \
			src/game/events/mouse/option_menu_over.c \
			src/game/events/mouse/mouse_release.c \
			src/game/events/mouse/mouse_click.c \
			src/game/events/mouse/mouse_click_game.c \

IMG = 	src/game/image_loader.c \
		src/game/hashmap/hashmap.c \
		src/game/hashmap/hashmap_del.c \
		src/game/config_parse.c \
		src/game/destroy_img.c \
		src/game/load_assets.c \

MENU =	src/game/menu/render_menu.c \
		src/game/menu/slider.c \
		src/game/menu/loaded_map.c \
		src/game/menu/render_options_menu.c \
		src/game/menu/render_maps_menu.c \
		src/game/menu/start_menu.c \
		src/game/char_setup/init_char_nodes.c \
		src/game/char_setup/build_words.c \
		src/game/char_setup/build_words_utils.c \

HUD	=	src/game/hud/render_hud.c \
		src/game/hud/head_hud.c \
		src/game/hud/numbers_hud.c \
		src/game/hud/ammo_hud.c \
		src/game/hud/weapon_menu_hud.c \
		src/game/hud/head_init.c \
		src/game/hud/draw_numbers.c \

WEAPONS	=	src/game/weapons/render_weapons.c \
			src/game/weapons/weapons_init.c \
			src/game/weapons/weapons_fired.c \
			src/game/weapons/weapons_animations.c \
			src/game/weapons/render_impacts.c \
			src/game/weapons/weapons_mecanics.c \
			src/game/weapons/offsets_animations.c \
			src/game/weapons/weapons_projectiles.c \
			src/game/weapons/render_projectiles.c \
			src/game/weapons/hit_detections.c \

UTILS =	src/utils/copy_img.c \
		src/utils/extension.c \
		src/utils/power_of_two.c \
		src/utils/empty_line.c \
		src/utils/cleanup_split.c \
		src/utils/sprite_udpate.c \
		src/utils/transparency.c \
		src/utils/cleanup_game.c \
		src/utils/load_buffer.c \

PARSING =	src/parsing/map_extract.c \
			src/parsing/data_manager.c \
			src/parsing/parse_main.c \
			src/parsing/textures_colors.c \
			src/parsing/flag_position.c \
			src/parsing/textures_content.c \
			src/parsing/parse_map.c \
			src/parsing/flood_fill.c \

GAME =	src/game/play/main_play.c \
		src/game/play/main_play_utils.c \
		src/game/play/print_back_and_player.c \
		src/game/play/player_moves.c \
		src/game/play/minimap.c \


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
