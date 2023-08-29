CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
NAME = so_long
OBJS = $(SRCS:.c=.o)
LIBFT_PATH = libft
MLX = -L./mlx/minilibx-linux -lmlx -framework OpenGL -framework AppKit
SRCS = so_long.c check_validation.c get_info.c \
	./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c

%.o: %.c
	$(CC) $(CFLAGS) -I $(LIBFT_PATH) -o $@ -c $<

$(NAME): $(OBJS)
	cd libft && make
	$(CC) $(CFLAGS) $(MLX) $(OBJS) $(LIBFT_PATH)/libft.a -o $(NAME)

all : $(NAME)

clean :
	cd libft && make clean
	rm -f $(OBJS)

fclean : clean
	cd libft && make fclean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
