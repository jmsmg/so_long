/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggoc <seonggoc@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 10:57:40 by seonggoc          #+#    #+#             */
/*   Updated: 2023/08/30 11:45:33 by seonggoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_get_img_ptr(t_info *info, void *mlx, int *img_w, int *img_l)
{
	info->space = mlx_xpm_file_to_image(mlx, "./img/s.xpm", img_w, img_l);
	info->wall = mlx_xpm_file_to_image(mlx, "./img/w.xpm", img_w, img_l);
	info->collect = mlx_xpm_file_to_image(mlx, "./img/c.xpm", img_w, img_l);
	info->exit = mlx_xpm_file_to_image(mlx, "./img/e.xpm", img_w, img_l);
	info->player = mlx_xpm_file_to_image(mlx, "./img/p.xpm", img_w, img_l);
}

void	ft_init_map(t_info *info)
{
	int	width;
	int	length;

	info->move = 0;
	width = info->width * 64;
	length = info->length * 64;
	info->mlx = mlx_init();
	info->win = mlx_new_window(info->mlx, width, length, "so_long");
	ft_get_img_ptr(info, info->mlx, &info->img_wid, &info->img_len);
	mlx_put_image_to_window(info->mlx, info->win, info->space, 0, 0);
	mlx_loop(info->mlx);
}
