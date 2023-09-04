/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggoc <seonggoc@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 11:44:03 by seonggoc          #+#    #+#             */
/*   Updated: 2023/09/04 14:46:37 by seonggoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move_w(t_info *info, char *map, int x, int y)
{
	int	p;
	int	target;

	p = x + y * info->width;
	target = x + (y - 1) * info->width;
	if (map[target] == '1' || (map[target] == 'E' && info->c_cnt != 0))
	{
		return ;
	}
	if (map[target] == 'C')
	{
		info->c_cnt--;
	}
	info->y--;
	info->map[target] = 'P';
	info->map[p] = '0';
	ft_printf("%d\n", ++info->move);
	ft_draw_map(info, info->mlx, info->win);
}

void	ft_move_s(t_info *info, char *map, int x, int y)
{
	int p;
	int target;

	p = x + (y * info->width);
	target = x + ((y + 1) * info->width);
	if (map[target] == '1' || (map[target] == 'E' && info->c_cnt != 0))
	{
		return ;
	}
	if (map[target] == 'C')
	{
		info->c_cnt--;
	}
	info->y++;
	info->map[target] = 'P';
	info->map[p] = '0';
	ft_printf("%d\n", ++info->move);
	ft_draw_map(info, info->mlx, info->win);
}

void	ft_move_d(t_info *info, char *map, int x, int y)
{
	int	p;
	int	target;

	p = x + (y * info->width);
	target = x + (y * info->width)+ 1;
	if (map[target] == '1' || (map[target] == 'E' && info->c_cnt != 0))
	{
		return ;
	}
	if (map[target] == 'C')
	{
		info->c_cnt--;
	}
	info->x++;
	info->map[target] = 'P';
	info->map[p] = '0';
	ft_printf("%d\n", ++info->move);
	ft_draw_map(info, info->mlx, info->win);
}

void	ft_move_a(t_info *info, char *map, int x, int y)
{
	int	p;
	int	target;

	p = x + (y * info->width);
	target = x + (y * info->width) - 1;
	if (map[target] == '1' || (map[target] == 'E' && info->c_cnt != 0))
	{
		return ;
	}
	if (map[target] == 'C')
	{
		info->c_cnt--;
	}
	info->x--;
	info->map[target] = 'P';
	info->map[p] = '0';
	ft_printf("%d\n", ++info->move);
	ft_draw_map(info, info->mlx, info->win);
}
