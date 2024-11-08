/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggoc <seonggoc@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 12:40:08 by seonggoc          #+#    #+#             */
/*   Updated: 2023/03/15 14:37:11 by seonggoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isalpha(int c)
{
	if ('A' <= c && c <= 'Z')
	{
		return (1);
	}
	else if ('a' <= c && c <= 'z')
	{
		return (1);
	}
	return (0);
}
