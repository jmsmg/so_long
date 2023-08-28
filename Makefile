CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = so_long
HEADER = so_long.h
LIBFT = libft/libft.a
LIBFT_DIR = libft/
CLIB = -L./mlx/minilibx-linux -lmlx -framework OpenGL -framework AppKit
SRCS = so_long.c
OBJS = $(SRCS:.c=.o)

all:
	make $(NAME)

$(NAME) : $(LIBFT) $(OBJS)
	cp $(LIBFT) "./"
	$(CC) $(CFLAGS) $(CLIB) -o $(NAME) $(OBJS) libft.a

$(LIBFT) :
	make -C $(LIBFT_DIR) all

.c.o:
	$(CC) $(CFLAGS) -Imlx -c $< -o $@
clean:
	make -C $(LIBFT_DIR) clean
	rm -rf libft.a
	rm -rf $(OBJS)
fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -rf $(NAME)
re:
	make fclean
	make all

.PHONY: all clean fclean re
