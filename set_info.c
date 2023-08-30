/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggoc <seonggoc@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 10:57:40 by seonggoc          #+#    #+#             */
/*   Updated: 2023/08/30 12:22:22 by seonggoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_get_img_ptr(t_info *info, void *mlx, int *img_w, int *img_l)
{
	info->space = mlx_xpm_file_to_image(mlx, "./img/s.xpm", img_w, img_l);
	if (!(info->space))
		ft_error(MALLOC_FAIL);
	info->wall = mlx_xpm_file_to_image(mlx, "./img/w.xpm", img_w, img_l);
	if (!(info->wall))
		ft_error(MALLOC_FAIL);
	info->collect = mlx_xpm_file_to_image(mlx, "./img/c.xpm", img_w, img_l);
	if (!(info->collect))
		ft_error(MALLOC_FAIL);
	info->exit = mlx_xpm_file_to_image(mlx, "./img/e.xpm", img_w, img_l);
	if (!(info->exit))
		ft_error(MALLOC_FAIL);
	info->player = mlx_xpm_file_to_image(mlx, "./img/p.xpm", img_w, img_l);
	if (!(info->player))
		ft_error(MALLOC_FAIL);
}

void	ft_set_info(t_info *info)
{
	int	width;
	int	length;

	info->move = 0;
	width = info->width * 64;
	length = info->length * 64;
	info->mlx = mlx_init();
	if (!(info->mlx))
		ft_error(MALLOC_FAIL);
	info->win = mlx_new_window(info->mlx, width, length, "so_long");
	ft_get_img_ptr(info, info->mlx, &info->img_wid, &info->img_len);
}
