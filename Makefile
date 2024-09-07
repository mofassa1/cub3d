SRC = main.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c parsing/parsing.c parsing/reading_texture.c \
		parsing/map_parsing.c parsing/map_rules.c parsing/parsing_tools.c parsing/parsing_tools_two.c parsing/map_parsing_tools.c \
		raycasting/initializer.c raycasting/raycasting.c raycasting/mlxes.c parsing/texture_init.c parsing/doors_check.c \
		parsing/color_parsing.c parsing/animation.c parsing/torch_texture_innit.c parsing/texture_get_addr.c parsing/frames.c \
		parsing/frames_1.c hooks/key_hook.c hooks/mouse_hook.c hooks/wall_collision.c \
		raycasting/textures.c raycasting/PlayerHelpers.c raycasting/minimap.c raycasting/intersection.c raycasting/drowers.c raycasting/directionsAndWalls.c \
		raycasting/comparaison.c \



OBJ = $(SRC:.c=.o)

LIBFT= libft/libft.a

FLAGS = -Wall -Wextra -Werror

MLX_FLAGS = -lXext -lX11 -lm -lmlx 

NAME = cub3D

all: $(NAME) $(LIBFT)

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@
	@echo "Compiled" $< "successfully"

$(NAME): $(OBJ) $(LIBFT)
	@$(CC) $(OBJ) $(LIBFT) $(MLX_FLAGS) -o $(NAME) #-fsanitize=address
	@echo "cub compiled"


$(LIBFT):
	make all -C ./libft
	@echo "Libft compiled"

clean:
	@rm -rf $(OBJ)
	@make clean -C ./libft
	@echo "Objects removed"

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C ./libft
	@echo "cub removed"

re: fclean all
	@echo "cub recompiled"