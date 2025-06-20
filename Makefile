NAME = cub3D
NAME_BONUS = cub3D_bonus
LIB = lib/libft/libft.a
MLX = lib/minilibx-linux/libmlx.a
RAYLIB = lib/raylib-4.5.0_linux_amd64/lib/libraylib.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -Ilib/raylib-4.5.0_linux_amd64/include -Ilib/libft/include -Ilib/minilibx-linux -Iinclude -g3 -O3
SRCS =	$(MAIN)$(EVENTS)$(IMG)$(MENU)$(UTILS)$(PARSING)$(GAME)$(WEAPONS)
SRCS_BONUS =	$(MAIN_BONUS)$(EVENTS_BONUS)$(IMG_BONUS)$(MENU_BONUS)$(HUD_BONUS)$(UTILS_BONUS)$(PARSING)$(GAME_BONUS)$(WEAPONS_BONUS)$(MUSIC_BONUS)

MAIN =	src/mandatory/main.c \
		src/mandatory/main_game.c \
		src/mandatory/routine.c \
		src/mandatory/game_init.c \
		src/mandatory/image_loader.c \

MUSIC_BONUS =	src/bonus/musics/music_inits.c \
				src/bonus/musics/musics.c \

EVENTS =	src/mandatory/events/keyboard/keypress.c \
			src/mandatory/events/keyboard/keypress_game.c \
			src/mandatory/events/keyboard/keyrelease.c \
			src/mandatory/events/mouse/mouse_direction.c \
			src/mandatory/events/cross_handler.c \

IMG =	src/mandatory/destroy_img.c \


UTILS =	src/mandatory/utils/extension.c \
		src/mandatory/utils/power_of_two.c \
		src/mandatory/utils/empty_line.c \
		src/mandatory/utils/cleanup_split.c \
		src/mandatory/utils/load_img.c \
		src/mandatory/utils/cleanup_game.c \

PARSING =	src/parsing/map_extract.c \
			src/parsing/data_manager.c \
			src/parsing/parse_main.c \
			src/parsing/textures_colors.c \
			src/parsing/flag_position.c \
			src/parsing/realloc_map.c \
			src/parsing/textures_content.c \
			src/parsing/parse_map.c \
			src/parsing/flood_fill.c \

GAME =	src/mandatory/play/main_play.c \
		src/mandatory/play/main_play_utils.c \
		src/mandatory/play/print_back.c \
		src/mandatory/play/print_player.c \
		src/mandatory/play/player_moves.c \
		src/mandatory/play/player_moves_utils.c \
		src/mandatory/play/print_3d.c \
		src/mandatory/play/print_3d_utils.c \
		src/mandatory/play/raycast.c \
		src/mandatory/play/raycast_utils.c \

MAIN_BONUS =	src/main.c \
				src/bonus/main_game.c \
				src/bonus/routine.c \
				src/bonus/maps_names.c \
				src/bonus/game_init.c \

EVENTS_BONUS = 	src/bonus/events/destroy.c \
			src/bonus/events/keyboard/keypress_maps.c \
			src/bonus/events/keyboard/keypress_game.c \
			src/bonus/events/keyboard/keypress.c \
			src/bonus/events/keyboard/keyrelease.c \
			src/bonus/events/keyboard/keypress_pause.c \
			src/bonus/events/keyboard/keypress_pause_options.c \
			src/bonus/events/mouse/mouse_over.c \
			src/bonus/events/mouse/option_menu_over.c \
			src/bonus/events/mouse/pause_options_hover.c \
			src/bonus/events/mouse/mouse_release.c \
			src/bonus/events/mouse/mouse_click.c \
			src/bonus/events/mouse/mouse_click_game.c \
			src/bonus/events/cross_handler.c \

IMG_BONUS = 	src/bonus/image_loader.c \
		src/bonus/hashmap/hashmap.c \
		src/bonus/hashmap/hashmap_del.c \
		src/bonus/config_parse.c \
		src/bonus/destroy_img.c \
		src/bonus/load_assets.c \

MENU_BONUS =	src/bonus/menu/render_menu.c \
		src/bonus/menu/slider.c \
		src/bonus/menu/loaded_map.c \
		src/bonus/menu/render_options_menu.c \
		src/bonus/menu/render_maps_menu.c \
		src/bonus/menu/start_menu.c \
		src/bonus/char_setup/init_char_nodes.c \
		src/bonus/char_setup/build_words.c \
		src/bonus/char_setup/build_words_utils.c \
		src/bonus/menu/render_pause_menu.c \
		src/bonus/menu/render_pause_options.c \
		src/bonus/menu/slider_init.c \
		src/bonus/menu/small_slider.c \


HUD_BONUS	=	src/bonus/hud/render_hud.c \
		src/bonus/hud/head_hud.c \
		src/bonus/hud/numbers_hud.c \
		src/bonus/hud/ammo_hud.c \
		src/bonus/hud/weapon_menu_hud.c \
		src/bonus/hud/head_init.c \
		src/bonus/hud/draw_numbers.c \

WEAPONS_BONUS	=	src/bonus/weapons/render_weapons.c \
			src/bonus/weapons/weapons_init.c \
			src/bonus/weapons/weapons_init2.c \
			src/bonus/weapons/weapons_fired.c \
			src/bonus/weapons/weapons_animations.c \
			src/bonus/weapons/render_impacts.c \
			src/bonus/weapons/weapons_mecanics.c \
			src/bonus/weapons/offsets_animations.c \
			src/bonus/weapons/weapons_projectiles.c \
			src/bonus/weapons/render_projectiles.c \
			src/bonus/weapons/hit_detections.c \

UTILS_BONUS =	src/bonus/utils/copy_img.c \
				src/bonus/utils/extension.c \
				src/bonus/utils/power_of_two.c \
				src/bonus/utils/empty_line.c \
				src/bonus/utils/cleanup_split.c \
				src/bonus/utils/sprite_udpate.c \
				src/bonus/utils/transparency.c \
				src/bonus/utils/cleanup_game.c \
				src/bonus/utils/load_buffer.c \
				src/bonus/utils/ismoving.c \
				src/bonus/utils/name_generator.c \
				src/bonus/utils/transparency_scaled.c \
				src/bonus/utils/update_loaded_anim.c \

GAME_BONUS =	src/bonus/play/main_play.c \
				src/bonus/play/main_play_utils.c \
				src/bonus/play/print_back.c \
				src/bonus/play/print_player.c \
				src/bonus/play/player_moves.c \
				src/bonus/play/player_moves_utils.c \
				src/bonus/play/minimap.c \
				src/bonus/play/minimap_utils.c \
				src/bonus/play/print_3d.c \
				src/bonus/play/print_3d_utils.c \
				src/bonus/play/raycast.c \
				src/bonus/play/raycast_utils.c \

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
	$(CC) $(OBJS_BONUS) $(LIB) $(MLX) -lGL -lm -lpthread -ldl -lX11 -lXext $(RAYLIB) -o $(NAME_BONUS)

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

f: fclean bonus
	$(CC) $(OBJS_BONUS) $(LIB) $(MLX) -lX11 -lXext -lm -o $(NAME_BONUS) -fsanitize=address

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
