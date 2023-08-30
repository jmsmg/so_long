/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggoc <seonggoc@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 10:46:46 by seonggoc          #+#    #+#             */
/*   Updated: 2023/08/30 10:36:28 by seonggoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_error(int flag)
{
	if (flag == MALLOC_FAIL)
		write(1, "malloc fail error\n", 18);
	else if (flag == WALL_FAIL)
		write(1, "Map must be surrounded by walls\n", 32);
	else if (flag == INCORRECT_ARGC)
		write(1, "Incorrect number of arguments, it's not 2\n", 42);
	else if (flag == FILE_FORMAT_ERROR)
		write(1, "The file format is incorrect.\n", 30);
	else if (flag == RECTAGLE_ERR)
		write(1, "Is not Rectangle\n", 17);
	else if (flag == CHAR_ERR)
		write(1, "Incorrect character\n", 20);
	else if (flag == PLAYER_ERR)
		write(1, "player error\n");
	else if (flag == EXIT_ERR)
		write(1, "exit error\n");
	else if (flag == COLLECT_ERR)
		write(1, "collect error\n");
	exit(1);
}

int	deal_key(int key, t_coordinate *coordinate)
{
	if (key == KEY_W)
	{
		coordinate->y += 1;
	}
	else if (key == KEY_S)
	{
		coordinate->y -= 1;
	}
	else if (key == KEY_A)
	{
		coordinate->x -= 1;
	}
	else if (key == KEY_D)
	{
		coordinate->x += 1;
	}
	else if (key == KEY_ESC)
	{
		exit(0);
	}
	return (0);
}

void	init_coordinate(t_coordinate	*coordinate)
{
	coordinate->x = 3;
	coordinate->y = 4;
}

int	main(int argc, char *argv[])
{
	t_info			*info;

	info = malloc(sizeof(t_info));
	if (!info)
		ft_error(MALLOC_FAIL);
	ft_check_arg(argc, argv);
	ft_get_map(argv[1], info);
	ft_check_map(info);

	info->mlx_ptr = mlx_init();
	if (!(info->mlx_ptr))
		return (1);
	info->win_ptr = mlx_new_window(info->mlx_ptr, 500, 500, "so_long");
	// mlx_hook(info->win_ptr, deal_key, 0, &deal_key, coordinate);
	// img = mlx_xpm_file_to_image(info->mlx_ptr, "./img/space.xpm", &(info->img_width), &(info->img_height));
	// mlx_put_image_to_window(mlx_ptr, win_ptr, img, 0, 0);


	// mlx_loop(info->mlx_ptr);
	return (0);
}
