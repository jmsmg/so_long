/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggoc <seonggoc@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 10:46:46 by seonggoc          #+#    #+#             */
/*   Updated: 2023/09/04 11:30:25 by seonggoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_error(int flag)
{
	if (flag == MALLOC_FAIL)
		write(1, "Error\nmalloc fail error\n", 24);
	else if (flag == OPEN_FAIL)
		write(1, "Error\nThe file could not be opened.\n", 36);
	else if (flag == WALL_FAIL)
		write(1, "Error\nMap must be surrounded by walls\n", 38);
	else if (flag == INCORRECT_ARGC)
		write(1, "Error\nIncorrect number of arguments, it's not 2\n", 48);
	else if (flag == FILE_FORMAT_ERROR)
		write(1, "Error\nThe file format is incorrect.\n", 36);
	else if (flag == RECTAGLE_ERR)
		write(1, "Error\nIs not Rectangle\n", 23);
	else if (flag == CHAR_ERR)
		write(1, "Error\nIncorrect character\n", 26);
	else if (flag == PLAYER_ERR)
		write(1, "Error\nplayer error\n", 19);
	else if (flag == EXIT_ERR)
		write(1, "Error\nexit error\n", 17);
	else if (flag == COLLECT_ERR)
		write(1, "Error\ncollect error\n", 20);
	else if (flag == ROUTE_ERR)
		write(1, "Error\nroute error\n", 18);
	exit(1);
}

int	deal_key(int key, t_info *info)
{
	if (key == KEY_W)
	{
		info->y += 1;
	}
	else if (key == KEY_S)
	{
		info->y -= 1;
	}
	else if (key == KEY_A)
	{
		info->x -= 1;
	}
	else if (key == KEY_D)
	{
		info->x += 1;
	}
	else if (key == KEY_ESC)
	{
		exit(0);
	}
	ft_printf("%d\n", ++info->move);
	return (0);
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
	ft_play_game(info);
	mlx_key_hook(info->win, &deal_key, info);
	mlx_loop(info->mlx);
	return (0);
}
