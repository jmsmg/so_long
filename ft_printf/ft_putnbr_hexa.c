/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggoc <seonggoc@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:16:08 by seonggoc          #+#    #+#             */
/*   Updated: 2023/04/03 19:35:24 by seonggoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_rec_put_nbr(size_t nbr, char *base, int *i)
{
	if (*i != -1)
	{
		*i += 1;
	}
	if (nbr < 16)
	{
		if (ft_putchar(base[nbr]) == -1)
		{
			*i = -1;
		}
	}
	else
	{
		ft_rec_put_nbr(nbr / 16, base, i);
		if (*i == -1)
		{
			return (-1);
		}
		ft_putchar(base[nbr % 16]);
	}
	return (*i);
}

int	ft_putnbr_hexa(size_t nbr, const char *format)
{
	int		i;

	i = 0;
	if (*format == 'X')
	{
		return (ft_rec_put_nbr((unsigned int)nbr, "0123456789ABCDEF", &i));
	}
	else if (*format == 'x')
	{
		return (ft_rec_put_nbr((unsigned int)nbr, "0123456789abcdef", &i));
	}
	else
	{
		if (write(1, "0x", 2) == -1)
		{
			return (-1);
		}
		i += 2;
		return (ft_rec_put_nbr(nbr, "0123456789abcdef", &i));
	}
}
