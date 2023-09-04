/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggoc <seonggoc@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 23:29:38 by seonggoc          #+#    #+#             */
/*   Updated: 2023/04/03 19:35:35 by seonggoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		return (write(STDOUT_FILENO, "(null)", 6));
	}
	while (str[i])
	{
		if (ft_putchar(str[i]) == -1)
		{
			return (-1);
		}
		i++;
	}
	return (i);
}
