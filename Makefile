NAME	=	cub3D

CC		=	cc
CFLAGS	=	-Wall -Werror -Wextra -Imlx -g -fsanitize=address
LIBS	=	-L $(LIBFT) -lft -L $(MLX) -lmlx -lXext -lX11
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
			$(FILES)/map_parser.c

OBJ		=	$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
			@make -C $(LIBFT)
			@make -C $(MLX)
			@$(CC) $(CFLAGS) $(SRC) -o $@ $(LIBS)

clean:
			@make clean -C $(LIBFT)
			@make clean -C $(MLX)
			@$(RM) $(OBJ)

fclean:		clean
			@make fclean -C $(LIBFT)
			@$(RM) $(NAME)

re:			fclean all
			valgrind $(VAL) ./$(NAME)

.PHONY:		all clean fclean re