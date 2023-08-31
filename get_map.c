/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggoc <seonggoc@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:21:17 by seonggoc          #+#    #+#             */
/*   Updated: 2023/08/31 21:26:15 by seonggoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_delete_newline(char *tmp, int i, int nl, t_info *info)
{
	int	size;

	size = 0;
	while (tmp[size])
	{
		if (tmp[size] == '\n')
			nl++;
		size++;
	}
	info->map = (char *)malloc((size - nl) + 1);
	if (!info->map)
		ft_error(MALLOC_FAIL);
	size = size - nl;
	nl = 0;
	while (i < size)
	{
		if (tmp[i + nl] == '\n')
			nl++;
		(info->map)[i] = tmp[i + nl];
		i++;
	}
	(info->map)[i] = '\0';
	free(tmp);
	return (info->map);
}

void	ft_get_map(char *file, t_info *info)
{
	int		fd;
	char	*line;
	char	*tmp;

	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
		ft_error(OPEN_FAIL);
	tmp = ft_strdup(line);
	info->width = ft_strlen(line) - 1;
	info->length = 1;
	if (!(tmp))
		ft_error(MALLOC_FAIL);
	while (line)
	{
		free(line);
		line = NULL;
		line = get_next_line(fd);
		if (!line)
			break ;
		tmp = ft_strjoin(tmp, line);
		info->length += 1;
	}
	info->map = ft_delete_newline(tmp, 0, 0, info);
}
