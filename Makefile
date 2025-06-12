NAME = cub3D
NAME_BONUS = cub3D_bonus
LIB = lib/libft/libft.a
MLX = lib/minilibx-linux/libmlx.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -Ilib/libft/include -Ilib/minilibx-linux -Iinclude -g3 -O3
SRCS =	$(MAIN)$(EVENTS)$(IMG)$(MENU)$(HUD)$(UTILS)$(PARSING)$(GAME)$(WEAPONS)
SRCS_BONUS =	$(MAIN_BONUS)$(EVENTS_BONUS)$(IMG_BONUS)$(MENU_BONUS)$(HUD_BONUS)$(UTILS_BONUS)$(PARSING_BONUS)$(GAME_BONUS)$(WEAPONS_BONUS)

MAIN =	src/mandatory/main.c \
		src/mandatory/game/main_game.c \
		src/mandatory/game/routine.c \
		src/mandatory/game/maps_names.c \
		src/mandatory/game/game_init.c \
		src/mandatory/game/weapons_init.c \

EVENTS = 	src/mandatory/game/events/destroy.c \
			src/mandatory/game/events/keyboard/keypress_maps.c \
			src/mandatory/game/events/keyboard/keypress_game.c \
			src/mandatory/game/events/keyboard/keypress.c \
			src/mandatory/game/events/keyboard/keyrelease.c \
			src/mandatory/game/events/mouse/mouse_over.c \
			src/mandatory/game/events/mouse/option_menu_over.c \
			src/mandatory/game/events/mouse/mouse_release.c \
			src/mandatory/game/events/mouse/mouse_click.c \
			src/mandatory/game/events/mouse/mouse_click_game.c \

IMG = 	src/mandatory/game/image_loader.c \
		src/mandatory/game/hashmap/hashmap.c \
		src/mandatory/game/hashmap/hashmap_del.c \
		src/mandatory/game/config_parse.c \
		src/mandatory/game/destroy_img.c \
		src/mandatory/game/load_assets.c \

MENU =	src/mandatory/game/menu/render_menu.c \
		src/mandatory/game/menu/slider.c \
		src/mandatory/game/menu/loaded_map.c \
		src/mandatory/game/menu/render_options_menu.c \
		src/mandatory/game/menu/render_maps_menu.c \
		src/mandatory/game/menu/start_menu.c \
		src/mandatory/game/char_setup/init_char_nodes.c \
		src/mandatory/game/char_setup/build_words.c \
		src/mandatory/game/char_setup/build_words_utils.c \

HUD	=	src/mandatory/game/hud/render_hud.c \
		src/mandatory/game/hud/head_hud.c \
		src/mandatory/game/hud/numbers_hud.c \
		src/mandatory/game/hud/ammo_hud.c \
		src/mandatory/game/hud/weapon_menu_hud.c \
		src/mandatory/game/hud/head_init.c \

WEAPONS	=	src/mandatory/game/weapons/render_weapons.c \


UTILS =	src/mandatory/utils/copy_img.c \
		src/mandatory/utils/extension.c \
		src/mandatory/utils/power_of_two.c \
		src/mandatory/utils/empty_line.c \
		src/mandatory/utils/cleanup_split.c \
		src/mandatory/utils/sprite_udpate.c \
		src/mandatory/utils/transparency.c \
		src/mandatory/utils/cleanup_game.c \

PARSING =	src/mandatory/parsing/map_extract.c \
			src/mandatory/parsing/data_manager.c \
			src/mandatory/parsing/parse_main.c \
			src/mandatory/parsing/textures_colors.c \
			src/mandatory/parsing/flag_position.c \
			src/mandatory/parsing/textures_content.c \
			src/mandatory/parsing/parse_map.c \
			src/mandatory/parsing/flood_fill.c \

GAME =	src/mandatory/game/play/main_play.c \
		src/mandatory/game/play/main_play_utils.c \
		src/mandatory/game/play/print_back.c \
		src/mandatory/game/play/print_player.c \
		src/mandatory/game/play/player_moves.c \
		src/mandatory/game/play/player_moves_utils.c \
		src/mandatory/game/play/minimap.c \
		src/mandatory/game/play/minimap_utils.c \
		src/mandatory/game/play/print_3d.c \
		src/mandatory/game/play/print_3d_utils.c \
		src/mandatory/game/play/raycast.c \
		src/mandatory/game/play/raycast_utils.c \

MAIN_BONUS =	src/main.c \
		src/game/main_game.c \
		src/game/routine.c \
		src/game/maps_names.c \
		src/game/game_init.c \

EVENTS_BONUS = 	src/game/events/destroy.c \
			src/game/events/keyboard/keypress_maps.c \
			src/game/events/keyboard/keypress_game.c \
			src/game/events/keyboard/keypress.c \
			src/game/events/keyboard/keyrelease.c \
			src/game/events/keyboard/keypress_pause.c \
			src/game/events/keyboard/keypress_pause_options.c \
			src/game/events/mouse/mouse_over.c \
			src/game/events/mouse/option_menu_over.c \
			src/game/events/mouse/pause_options_hover.c \
			src/game/events/mouse/mouse_release.c \
			src/game/events/mouse/mouse_click.c \
			src/game/events/mouse/mouse_click_game.c \


IMG = 	src/game/image_loader.c \

IMG_BONUS = 	src/game/image_loader.c \
		src/game/hashmap/hashmap.c \
		src/game/hashmap/hashmap_del.c \
		src/game/config_parse.c \
		src/game/destroy_img.c \
		src/game/load_assets.c \

MENU_BONUS =	src/game/menu/render_menu.c \
		src/game/menu/slider.c \
		src/game/menu/loaded_map.c \
		src/game/menu/render_options_menu.c \
		src/game/menu/render_maps_menu.c \
		src/game/menu/start_menu.c \
		src/game/char_setup/init_char_nodes.c \
		src/game/char_setup/build_words.c \
		src/game/char_setup/build_words_utils.c \
		src/game/menu/render_pause_menu.c \
		src/game/menu/render_pause_options.c \

HUD_BONUS	=	src/game/hud/render_hud.c \
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
WEAPONS_BONUS	=	src/game/weapons/render_weapons.c \


UTILS_BONUS =	src/utils/copy_img.c \
		src/utils/extension.c \
		src/utils/power_of_two.c \
		src/utils/empty_line.c \
		src/utils/cleanup_split.c \
		src/utils/sprite_udpate.c \
		src/utils/transparency.c \
		src/utils/cleanup_game.c \
		src/utils/load_buffer.c \

PARSING_BONUS =	src/parsing/map_extract.c \
			src/parsing/data_manager.c \
			src/parsing/parse_main.c \
			src/parsing/textures_colors.c \
			src/parsing/flag_position.c \
			src/parsing/textures_content.c \
			src/parsing/parse_map.c \
			src/parsing/flood_fill.c \

GAME_BONUS =	src/game/play/main_play.c \
		src/game/play/main_play_utils.c \
		src/game/play/print_back.c \
		src/game/play/print_player.c \
		src/game/play/player_moves.c \
		src/game/play/player_moves_utils.c \
		src/game/play/minimap.c \
		src/game/play/minimap_utils.c \
		src/game/play/print_3d.c \
		src/game/play/print_3d_utils.c \
		src/game/play/raycast.c \
		src/game/play/raycast_utils.c \

OBJ_DIR = obj
OBJ_DIR_BONUS = obj_bonus

OBJS = $(patsubst %.c,%.o,$(SRCS))
OBJS := $(patsubst src/%, $(OBJ_DIR)/src/%, $(OBJS))
OBJS_BONUS = $(patsubst %.c,%.o,$(SRCS_BONUS))
OBJS_BONUS := $(patsubst src/%, $(OBJ_DIR_BONUS)/src/%, $(OBJS_BONUS))

all: $(NAME)

$(NAME): $(OBJS) $(LIB) $(MLX)
	$(CC) $(OBJS) $(LIB) $(MLX) -lX11 -lXext -lm -o $(NAME)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_BONUS) $(LIB) $(MLX)
	$(CC) $(OBJS_BONUS) $(LIB) $(MLX) -lX11 -lXext -lm -o $(NAME_BONUS)

$(LIB):
	$(MAKE) -C lib/libft

$(MLX):
	$(MAKE) -C lib/minilibx-linux

$(OBJ_DIR)/src/%.o: src/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

$(OBJ_DIR_BONUS)/src/%.o: src/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

-include $(OBJS:.o=.d)

f: re
	$(CC) $(OBJS) $(LIB) $(MLX) -lX11 -lXext -lm -o $(NAME) -fsanitize=address

clean:
	rm -rf $(OBJ_DIR)
	rm -rf $(OBJ_DIR_BONUS)
	$(MAKE) clean -C lib/libft
	$(MAKE) clean -C lib/minilibx-linux

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_BONUS)

re: fclean all

.PHONY: all clean fclean re bonus
