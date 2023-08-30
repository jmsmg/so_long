
#ifndef SO_LONG_H
# define SO_LONG_H
# include "./mlx/minilibx-linux/mlx.h"
# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# include <stdio.h>

# define TRUE 1
# define FALSE 0
# define KEY_ESC 53
# define KEY_W 13
# define KEY_S 1
# define KEY_A 0
# define KEY_D 2

# define MALLOC_FAIL 1
# define RECTAGLE_ERR 2
# define WALL_FAIL 3
# define INCORRECT_ARGC 4
# define FILE_FORMAT_ERROR 5
# define CHAR_ERR 6
# define PLAYER_ERR 7
# define EXIT_ERR 8
# define COLLECT_ERR 9

typedef struct s_coordinate
{
	int	x;
	int	y;
}	t_coordinate;

typedef struct s_char_cnt
{
	int	c;
	int	e;
	int	p;
}	t_char_cnt;


typedef struct s_info
{
	char	*map;
	int		width;
	int		length;
	void	*mlx;
	void	*win;
	int		img_wid;
	int		img_len;
	void	*space;
	void	*wall;
	void	*collect;
	void	*exit;
	void	*player;
	int		move;
}	t_info;

int	ft_error(int flag);

void	ft_check_arg(int argc, char **argv);
int		ft_check_file_format(char *map_name);

void	ft_get_map(char *file, t_info *info);
char	*get_next_line(int fd);
char	*ft_delete_newline(char *tmp, t_info *info);

void	ft_check_map(t_info *info);
int		ft_check_wall(t_info *info);

void	ft_set_info(t_info *info);
#endif
