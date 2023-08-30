/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggoc <seonggoc@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 17:48:07 by seonggoc          #+#    #+#             */
/*   Updated: 2023/08/30 11:20:44 by seonggoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_vali_char(char c)
{
	if (c == '0' || c == '1' || c == 'C' || c == 'E' || c == 'P')
	{
		return (TRUE);
	}
	return (FALSE);
}

void	ft_check_char(t_info *info)
{
	int			i;
	t_char_cnt	char_cnt;

	i = 0;
	char_cnt = (t_char_cnt){.c = 0, .e = 0, .p = 0};
	while ((info->map)[i])
	{
		if (!ft_check_vali_char((info->map)[i]))
			ft_error(CHAR_ERR);
		if (info->map[i] == 'C')
			char_cnt.c += 1;
		else if (info->map[i] == 'E')
			char_cnt.e += 1;
		else if (info->map[i] == 'P')
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

int	ft_check_rectangle(t_info *info)
{
	if (info->width * info->length != (int)ft_strlen(info->map))
	{
		return (FALSE);
	}
	return (TRUE);
}

void	ft_check_map(t_info *info)
{
	if (!ft_check_rectangle(info))
		ft_error(RECTAGLE_ERR);
	if (!ft_check_wall(info))
		ft_error(WALL_FAIL);
	ft_check_char(info);
}
