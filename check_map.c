/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggoc <seonggoc@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 17:48:07 by seonggoc          #+#    #+#             */
/*   Updated: 2023/08/29 17:55:44 by seonggoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_rectangle(t_info *info)
{
	int	i;
	int line;

	i = 0;
	line = 0;
	while ((info->map)[line] != '\0' || info->map[line] != '\n')
	{
		line++;
	}
	while ((info->map)[i] != '\0')
	{
		if (i < line && (info->map)[i] != '1')
		{
			ft_error
		}
		i++;
	}
}
int	ft_check_map(t_info *info)
{
	if (ft_check_rectangle(info))
	{

	}
}
