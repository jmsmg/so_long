/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggoc <seonggoc@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 10:55:31 by seonggoc          #+#    #+#             */
/*   Updated: 2023/04/03 19:34:15 by seonggoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_check_format(va_list ap, const char *format)
{
	if (*format == 'c')
		return (ft_putchar((char)va_arg(ap, int)));
	else if (*format == 's')
		return (ft_putstr(va_arg(ap, void *)));
	else if (*format == 'p')
		return (ft_putnbr_hexa((size_t)va_arg(ap, void *), format));
	else if (*format == 'd' || *format == 'i')
		return (ft_putnbr_sign(va_arg(ap, int)));
	else if (*format == 'u')
		return (ft_putnbr_unsign(va_arg(ap, unsigned int)));
	else if (*format == 'x')
		return (ft_putnbr_hexa(va_arg(ap, unsigned int), format));
	else if (*format == 'X')
		return (ft_putnbr_hexa(va_arg(ap, unsigned int), format));
	else if (*format == '%')
		return (ft_putchar('%'));
	else
		return (-1);
}

int	ft_printf(const char *format, ...)
{
	int		sum;
	int		tmp;
	va_list	ap;

	sum = 0;
	va_start(ap, format);
	if (!format)
		return (-1);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			tmp = ft_check_format(ap, format);
		}
		else
			tmp = ft_putchar(*format);
		if (tmp == -1)
			return (-1);
		sum += tmp;
		format++;
	}
	va_end(ap);
	return (sum);
}
