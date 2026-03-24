NAME = so_long

SRC = src/

SRC_FILES = $(SRC)main.c \
	$(SRC)core/close.c \
	$(SRC)core/error.c \
	$(SRC)core/free_game.c \
	$(SRC)core/init_game.c \
	$(SRC)core/init_mlx.c \
	$(SRC)parsing/parse_map.c \
	$(SRC)parsing/parse_utils.c \
	$(SRC)parsing/read_map.c \
	$(SRC)validation/flood_fill.c \
	$(SRC)validation/validate_chars.c \
	$(SRC)validation/validate_map.c \
	$(SRC)validation/validate_path.c \
	$(SRC)validation/validate_shape.c \
	$(SRC)render/animate.c \
	$(SRC)render/destroy_images.c \
	$(SRC)render/draw_animation_layer.c \
	$(SRC)render/draw_background.c \
	$(SRC)render/draw_interactive_layer.c \
	$(SRC)render/draw_map.c \
	$(SRC)render/draw_tools.c \
	$(SRC)render/end_animation.c \
	$(SRC)render/end_text.c \
	$(SRC)render/init_frames.c \
	$(SRC)render/init_render.c \
	$(SRC)render/load_assets.c \
	$(SRC)render/load_brazier_asset.c \
	$(SRC)render/load_flame_asset.c \
	$(SRC)render/redraw.c \
	$(SRC)render/redraw_interactive_frame.c \
	$(SRC)render/render_animation.c \
	$(SRC)render/update_moves_text.c \
	$(SRC)game/collect_utils.c \
	$(SRC)game/finish_game.c \
	$(SRC)game/input.c \
	$(SRC)game/move_player.c \
	$(SRC)game/move_utils.c \
	$(SRC)tools/array_tools.c \
	$(SRC)tools/checker.c \
	$(SRC)tools/free_arrays.c \
	$(SRC)tools/iterators.c \
	$(SRC)tools/random_range.c \
	$(SRC)generate/allocate_animation_layer.c \
	$(SRC)generate/allocate_interactive_layer.c \
	$(SRC)generate/fill_animation_layer.c \
	$(SRC)generate/fill_interactive_layer.c \
	$(SRC)generate/generate_animation_layer.c \
	$(SRC)generate/generate_floor.c \
	$(SRC)generate/generate_interactive_layer.c \
	$(SRC)generate/generate_walls.c \
	$(SRC)generate/map_generator.c

SRC_OBJS = $(SRC_FILES:.c=.o)


##Libriaries

#Libft
DLIBFT = libft
LIBFT = $(DLIBFT)/libft.a
FT = ft

#MLX42
MLX42 = mlx42
BUILD_DIR = $(MLX42)/build
MLX42LIB = $(BUILD_DIR)/libmlx42.a

CC = cc
# CFLAGS = -g -Wall -Wextra -Werror -Iincludes -I$(MLX42)/include/MLX42 -fsanitize=address
CFLAGS = -Wall -Wextra -Werror -Iincludes -I$(MLX42)/include/MLX42

EXT_LIBS = -ldl -lglfw -pthread -lm


all: $(NAME)

bonus: $(NAME)

$(NAME): $(MLX42LIB) $(SRC_OBJS) $(LIBFT)
	cc $(CFLAGS) $^ -o $@ -L$(DLIBFT) -l$(FT) -L$(BUILD_DIR) -lmlx42 $(EXT_LIBS)

$(LIBFT) :
	make -C $(DLIBFT) all

$(MLX42LIB):
	if [ ! -d $(MLX42) ]; then \
		git clone https://github.com/codam-coding-college/MLX42.git $(MLX42); \
	fi
	if [ ! -f $(BUILD_DIR)/libmlx42.a ]; then \
		cmake $(MLX42) -B $(BUILD_DIR) && \
		cmake --build $(BUILD_DIR) -j4; \
	fi

re : fclean all

fclean : clean
	rm -f $(NAME)
	make -C $(DLIBFT) fclean
	rm -rf $(MLX42)

clean : 
	rm -f $(SRC_OBJS)
	make -C $(DLIBFT) clean

.PHONY: all clean fclean re bonus #debug debug_bonus
