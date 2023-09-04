/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggoc <seonggoc@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 10:59:29 by seonggoc          #+#    #+#             */
/*   Updated: 2023/04/03 19:34:38 by seonggoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	ft_putchar(char c);
int	ft_putnbr_hexa(size_t nbr, const char *format);
int	ft_putnbr_unsign(unsigned int n);
int	ft_putnbr_sign(int nb);
int	ft_putstr(char *str);
#endif
