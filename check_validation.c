/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggoc <seonggoc@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 15:19:31 by seonggoc          #+#    #+#             */
/*   Updated: 2023/08/29 19:31:12 by seonggoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_file_format(int argc, char *map_name)
{
	int	size;

	if (argc != 2)
	{
		return (1);
	}
	size = ft_strlen(map_name);
	if (size <= 5)
	{
		return (1);
	}
	if (!(map_name[size - 1] == 'r'
			&& map_name[size - 2] == 'e'
			&& map_name[size - 3] == 'b'
			&& map_name[size - 4] == '.'))
	{
		return (1);
	}
	return (0);
}

int	ft_check_validation(int argc, char **argv, t_info *info)
{
	if (ft_check_file_format(argc, argv[1]))
	{
		return (1);
	}
	ft_get_map(argv[1], info);
	ft_check_map(info); // 안됨
	return (0);
}
