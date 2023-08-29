/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggoc <seonggoc@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 17:48:07 by seonggoc          #+#    #+#             */
/*   Updated: 2023/08/30 08:18:06 by seonggoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_rectangle(t_info *info)
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

int	ft_check_map(t_info *info)
{
	if (!ft_check_rectangle(info))
	{
		ft_error(RECTANGLE_FAIL);
	}
	return (1);
}
