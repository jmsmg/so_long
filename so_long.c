/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggoc <seonggoc@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 10:46:46 by seonggoc          #+#    #+#             */
/*   Updated: 2023/08/24 12:01:06 by seonggoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
/*
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
	else
	{
		return (0);
	}
}
*/
int	main(void)
{
	void			*mlx_ptr;
	void			*win_ptr;
	void *img;
	void *img2;
	void *img3;
	void *img4;
	void *img5;
	int img_width;
	int img_height;
	// t_coordinate	*coordinate;

	mlx_ptr = mlx_init();
	if (!mlx_ptr)
		return (1);

	// coordinate->x = 3;
	// coordinate->y = 4;

	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "so_long");
	img = mlx_xpm_file_to_image(mlx_ptr, "./img/space.xpm", &img_width, &img_height);
	img2 = mlx_xpm_file_to_image(mlx_ptr, "./img/wall.xpm", &img_width, &img_height);
	img3 = mlx_xpm_file_to_image(mlx_ptr, "./img/char.xpm", &img_width, &img_height);
	img4 = mlx_xpm_file_to_image(mlx_ptr, "./img/player.xpm", &img_width, &img_height);
	img5 = mlx_xpm_file_to_image(mlx_ptr, "./img/exit.xpm", &img_width, &img_height);
	mlx_put_image_to_window(mlx_ptr, win_ptr, img, 0, 0);
	mlx_put_image_to_window(mlx_ptr, win_ptr, img2, 64, 0);
	mlx_put_image_to_window(mlx_ptr, win_ptr, img3, 128, 0);
	mlx_put_image_to_window(mlx_ptr, win_ptr, img4, 192, 64);
	mlx_put_image_to_window(mlx_ptr, win_ptr, img5, 0, 64);

	// mlx_hook(win_ptr, deal_key, 0, &deal_key, coordinate);

	mlx_loop(mlx_ptr);
	return (0);
}
