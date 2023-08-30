/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggoc <seonggoc@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:19:06 by seonggoc          #+#    #+#             */
/*   Updated: 2023/08/30 18:04:58 by seonggoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
