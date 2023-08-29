/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggoc <seonggoc@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:21:17 by seonggoc          #+#    #+#             */
/*   Updated: 2023/08/29 17:37:24 by seonggoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_get_map(char *file, t_info *info)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
		ft_error(MALLOC_FAIL);
	info->map = ft_strdup(line);
	if (!(info->map))
		ft_error(MALLOC_FAIL);
	while(line)
	{
		free(line);
		line = NULL;
		line = get_next_line(fd);
		if (!line)
			break ;
		info->map = ft_strjoin(info->map, line);
	}
}
