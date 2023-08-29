
#ifndef SO_LONG_H
# include "./mlx/minilibx-linux/mlx.h"
# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# include <stdio.h>

# define SO_LONG_H
# define KEY_ESC 53
# define KEY_W 13
# define KEY_S 1
# define KEY_A 0
# define KEY_D 2
# define MALLOC_FAIL 1

typedef struct s_coordinate
{
	int	x;
	int	y;
}	t_coordinate;

typedef struct s_info
{
	void		*mlx_ptr;
	void		*win_ptr;
	char		*map;
	int			img_width;
	int			img_height;
}	t_info;

int	ft_error(int flag);

int	ft_check_validation(int argc, char **argv, t_info *info);
int	ft_check_file_format(int argc, char *map_name);
void	ft_get_map(char *file, t_info *info);
char	*get_next_line(int fd);
#endif
