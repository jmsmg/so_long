/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggoc <seonggoc@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 17:48:07 by seonggoc          #+#    #+#             */
/*   Updated: 2023/08/29 20:13:37 by seonggoc         ###   ########.fr       */
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
			ft_error(RECTANGLE_FAIL);
		}
		else if (i != 0 && (info->width % i == 0 || info->width % i == 1)
			&& (info->map)[i] != '1')
		{
			ft_error(RECTANGLE_FAIL);
		}
		else if (info->width * info->length <= i && (info->map)[i] != '1')
		{
			ft_error(RECTANGLE_FAIL);
		}
		exit(0);
		i++;
	}
	return (1);
}

int	ft_check_map(t_info *info)
{
	if (ft_check_rectangle(info))
	{
		exit(0);
	}
	return (1);
}
