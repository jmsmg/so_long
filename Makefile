CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = so_long
OBJS = $(SRCS:.c=.o)
LIBFT_PATH = libft
MLX = -L./mlx -lmlx -framework OpenGL -framework AppKit
SRCS = so_long.c check_arg.c get_map.c check_map.c set_info.c play_game.c \
	move.c ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c

%.o: %.c
	$(CC) $(CFLAGS) -I $(LIBFT_PATH) -o $@ -c $<

$(NAME): $(OBJS)
	cd libft && make
	cd ft_printf && make
	cd mlx && make
	$(CC) $(CFLAGS) $(MLX) $(OBJS) $(LIBFT_PATH)/libft.a mlx/libmlx.a \
	ft_printf/libftprintf.a -o $(NAME)

all : $(NAME)

clean :
	cd libft && make clean
	cd ft_printf && make clean
	cd mlx && make clean
	rm -f $(OBJS)

fclean : clean
	cd libft && make fclean
	cd ft_printf && make fclean
	cd mlx && make clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
