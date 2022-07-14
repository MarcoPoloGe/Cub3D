SRCS	= 	${addprefix src/, main.c leave.c}	\

OBJS		=	${SRCS:.c=.o}
NAME		= 	cub3D
AR			=	ar rcs
GCC			=	gcc
RM			= 	rm -f
CFLAGS		=	-Wall -Wextra -Werror
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

clean:
			${RM} ${OBJS}
			@$(MAKE) -C $(LBFT_PATH) clean
			@$(MAKE) -C $(MLX_PATH) clean

fclean:		clean
			${RM} ${NAME}
			@$(MAKE) -C $(LBFT_PATH) fclean

re:			fclean all

.PHONY:		all clean fclean re

