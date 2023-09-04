/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggoc <seonggoc@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:19:06 by seonggoc          #+#    #+#             */
/*   Updated: 2023/09/04 15:25:53 by seonggoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_game(void)
{
	exit(0);
	return (0);
}

int	deal_key(int key, t_info *info)
{
	if (key == KEY_W)
		ft_move_w(info, info->map, info->x, info->y);
	else if (key == KEY_S)
		ft_move_s(info, info->map, info->x, info->y);
	else if (key == KEY_A)
		ft_move_a(info, info->map, info->x, info->y);
	else if (key == KEY_D)
		ft_move_d(info, info->map, info->x, info->y);
	else if (key == KEY_ESC)
		close_game();
	return (0);
}

void	ft_draw_map(t_info *info, void *mlx, void *win)
{
	int		x;
	int		y;
	void	*c;

	y = 0;
	while (y < info->length)
	{
		x = 0;
		while (x < info->width)
		{
			if ((info->map)[x + (y * info->width)] == '0')
				c = info->space;
			else if ((info->map)[x + (y * info->width)] == '1')
				c = info->wall;
			else if ((info->map)[x + (y * info->width)] == 'C')
				c = info->collect;
			else if ((info->map)[x + (y * info->width)] == 'E')
				c = info->exit;
			else if ((info->map)[x + (y * info->width)] == 'P')
				c = info->player;
			mlx_put_image_to_window(mlx, win, c, x * 64, y * 64);
			x++;
		}
		y++;
	}
}

void	ft_play_game(t_info *info)
{
	ft_draw_map(info, info->mlx, info->win);
	mlx_key_hook(info->win, &deal_key, info);
	mlx_hook(info->win, BUTTON_X, 0, &close_game, info);
	mlx_loop(info->mlx);
}
