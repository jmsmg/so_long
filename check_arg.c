/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggoc <seonggoc@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 15:19:31 by seonggoc          #+#    #+#             */
/*   Updated: 2023/08/30 10:03:42 by seonggoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_file_format(char *map_name)
{
	int	size;

	size = ft_strlen(map_name);
	if (size < 5)
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

void	ft_check_arg(int argc, char **argv)
{
	if (argc != 2)
		ft_error(INCORRECT_ARGC);
	if (ft_check_file_format(argv[1]))
		ft_error(FILE_FORMAT_ERROR);
}
