NAME = so_long

SRC = src/

SRC_FILES = $(wildcard src/*.c) \
      $(wildcard src/core/*.c) \
      $(wildcard src/parsing/*.c) \
      $(wildcard src/validation/*.c) \
      $(wildcard src/render/*.c) \
      $(wildcard src/game/*.c)

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
CFLAGS = -g -Wall -Wextra -Werror -Iincludes -I$(MLX42)/include/MLX42


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