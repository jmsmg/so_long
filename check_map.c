/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggoc <seonggoc@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 17:48:07 by seonggoc          #+#    #+#             */
/*   Updated: 2023/08/31 21:01:47 by seonggoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_find_route(int x, int y, char *map, t_info *info)
{
	if (map[x + (y * info->width)] == '1' || map[x * (y * info->width)] == 'V')
		return ;
	if (map[(y * info->width)] == 'C')
		info->c_cnt++;
	if (map[(y * info->width)] == 'E')
		info->e_cnt++;
	map[x * (y * info->width)] = 'V';
	ft_find_route(x - 1, y, map, info);
	ft_find_route(x, y - 1, map, info);
	ft_find_route(x + 1, y, map, info);
	ft_find_route(x, y + 1, map, info);
}

void	ft_find_player(t_info *info)
{
	int	i;

	i = 0;
	while (info->map[i] != 'P')
	{
		i++;
	}
	info->x = i % info->width;
	info->y = i / info->width;
}

void	ft_check_char(t_info *info)
{
	int			i;
	char		c;
	t_char_cnt	char_cnt;

	i = 0;
	char_cnt = (t_char_cnt){.c = 0, .e = 0, .p = 0};
	while ((info->map)[i])
	{
		c = (info->map)[i];
		if (!(c == '0' || c == '1' || c == 'C' || c == 'E' || c == 'P'))
			ft_error(CHAR_ERR);
		if (c == 'C')
			char_cnt.c += 1;
		else if (c == 'E')
			char_cnt.e += 1;
		else if (c == 'P')
			char_cnt.p += 1;
		i++;
	}
	if (char_cnt.p != 1)
		ft_error(PLAYER_ERR);
	else if (char_cnt.e != 1)
		ft_error(EXIT_ERR);
	else if (char_cnt.c < 1)
		ft_error(COLLECT_ERR);
}

int	ft_check_wall(t_info *info)
{
	int	i;

	i = 0;
	while ((info->map)[i] != '\0')
	{
		if (i < info->width && (info->map)[i] != '1')
		{
			return (FALSE);
		}
		else if ((i % info->width == 0 || i % info->width == info->width - 1)
			&& (info->map)[i] != '1')
		{
			return (FALSE);
		}
		else if (info->width * (info->length - 1) <= i
			&& (info->map)[i] != '1')
		{
			return (FALSE);
		}
		i++;
	}
	return (TRUE);
}

void	ft_check_map(t_info *info)
{
	char	*map;

	info->c_cnt = 0;
	info->e_cnt = 0;
	map = ft_strdup(info->map);
	if (!map)
		ft_error(MALLOC_FAIL);
	if (info->width * info->length != (int)ft_strlen(info->map))
		ft_error(RECTAGLE_ERR);
	if (!ft_check_wall(info))
		ft_error(WALL_FAIL);
	ft_check_char(info);
	ft_find_player(info);
	ft_find_route(info->x, info->y, map, info);
	if (info->c_cnt == 0 || info->e_cnt == 0)
		ft_error(COLLECT_ERR);
	free(map);
}
