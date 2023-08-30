/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggoc <seonggoc@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:21:17 by seonggoc          #+#    #+#             */
/*   Updated: 2023/08/30 17:00:42 by seonggoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_delete_newline(char *tmp, t_info *info)
{
	int	i;
	int	size;
	int	nl;

	i = 0;
	nl = 0;
	size = 0;
	while (tmp[size])
	{
		if (tmp[size] == '\n')
			nl++;
		size++;
	}
	info->map = (char *)malloc((info->length * info->width) + 1);
	if (!info->map)
		ft_error(MALLOC_FAIL);
	nl = 0;
	while (i < info->length * info->width)
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
		ft_error(MALLOC_FAIL);
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
	info->map = ft_delete_newline(tmp, info);
}
