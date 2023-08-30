/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggoc <seonggoc@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 10:46:46 by seonggoc          #+#    #+#             */
/*   Updated: 2023/08/30 17:23:42 by seonggoc         ###   ########.fr       */
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
		write(1, "player error\n", 13);
	else if (flag == EXIT_ERR)
		write(1, "exit error\n", 11);
	else if (flag == COLLECT_ERR)
		write(1, "collect error\n", 14);
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
	ft_set_info(info);
	ft_draw_map(info, info->mlx, info->win);
	mlx_loop(info->mlx);
	return (0);
}
