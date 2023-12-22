NAME	=	cub3D

CC		=	cc
CFLAGS	=	-Wall -Werror -Wextra -Imlx -g -fsanitize=address
LIBS	=	-L $(MLX) -lmlx -lXext -lX11 -L $(LIBFT) -lft
RM		=	rm -rf

FILES	=	src
MLX		=	mlx
LIBFT	=	libft
SRC_DIR	=	src
INC_DIR	=	include
XCTOR	=	executor
VAL		=	--leak-check=full \
			--show-leak-kinds=all \
			--track-origins=yes \
			--verbose \
			--log-file=valgrind_log.txt \

SRC		=	cub3D.c \
			$(FILES)/parser/flood_fill.c \
			$(FILES)/parser/map_args.c \
			$(FILES)/parser/map_parser.c \
			$(FILES)/parser/parser_utils.c \
			$(FILES)/parser/rgb.c \
			$(FILES)/parser/textures.c \
			$(FILES)/raycaster/raycaster.c \
			$(FILES)/win/hooks.c \
			$(FILES)/win/imgs.c \
			$(FILES)/win/structs.c \
			$(FILES)/win/win.c \
			$(FILES)/general.c \
			$(FILES)/get_next_line_utils.c \
			$(FILES)/get_next_line.c \
			$(FILES)/utils.c

OBJ		=	$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
			@make -C $(MLX)
			@make -C $(LIBFT)
			@$(CC) $(CFLAGS) $(SRC) -o $@ $(LIBS)

clean:
			@make clean -C $(MLX)
			@make clean -C $(LIBFT)
			@$(RM) $(OBJ)

fclean:		clean
			@make fclean -C $(LIBFT)
			@$(RM) $(NAME)

re:			fclean all
			valgrind $(VAL) ./$(NAME)

.PHONY:		all clean fclean re