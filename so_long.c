/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggoc <seonggoc@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 10:46:46 by seonggoc          #+#    #+#             */
/*   Updated: 2023/08/29 19:16:23 by seonggoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_error(int flag)
{
	if (flag == MALLOC_FAIL)
		write(1, "malloc fail error\n", 18);
	else if (flag == RECTANGLE_FAIL)
	{
		write(1, "Map must be rectangular.\n", 25);
	}

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
	// t_coordinate	*coordinate;

	info = malloc(sizeof(t_info));
	if (!info)
		ft_error(MALLOC_FAIL);
	if (ft_check_validation(argc, argv, info))
		return (1);
	// init_coordinate(coordinate);
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
