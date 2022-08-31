
SRCS	= 	${addprefix src/, main.c leave.c raycasting.c display_background.c img.c coord_tools.c init.c move.c ray_impact.c frame.c}
SRCS	+= 	${addprefix src/parsing/, parser.c map.c map_check.c}
SRCS	+= 	${addprefix src/debug/, put_struct.c render_fdf.c minimap.c}

OBJS		=	${SRCS:.c=.o}
NAME		= 	cub3D
AR			=	ar rcs
GCC			=	gcc
RM			= 	rm -f
CFLAGS		=	-Wall -Wextra -Werror -g -fsanitize=address
MLX_PATH	=	./mlx/
LBFT_PATH	=	./libft/
FRAMLIBS	=	-L ${LBFT_PATH} -lft -L ${MLX_PATH} -lmlx -framework OpenGL -framework AppKit

all:		$(NAME)

.c.o:
			$(GCC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME):	$(OBJS)
			@$(MAKE) -C $(LBFT_PATH)
			@$(MAKE) -C $(MLX_PATH)
			$(GCC) $(OBJS) $(CFLAGS) -I ${MLX_PATH} -I ${LBFT_PATH} -o $(NAME) $(FRAMLIBS)

test:		$(OBJS)
			@$(MAKE) -C $(LBFT_PATH)
			@$(MAKE) -C $(MLX_PATH)
			$(GCC) $(OBJS) -I ${MLX_PATH} -I ${LBFT_PATH} -o $(NAME) $(FRAMLIBS)

clean:
			${RM} ${OBJS}
			@$(MAKE) -C $(LBFT_PATH) clean
			@$(MAKE) -C $(MLX_PATH) clean

fclean:		clean
			${RM} ${NAME}
			@$(MAKE) -C $(LBFT_PATH) fclean

re:			fclean all

.PHONY:		all clean fclean re

