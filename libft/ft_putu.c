/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstockma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 14:22:17 by vstockma          #+#    #+#             */
/*   Updated: 2022/10/19 14:22:19 by vstockma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putunsigned(unsigned int i)
{
	if (i > 9)
	{
		ft_putunsigned(i / 10);
		ft_putunsigned(i % 10);
	}
	else
		ft_putchar(i + '0');
}

int	ft_putu(va_list args)
{
	int				len;
	unsigned int	i;

	i = va_arg(args, unsigned int);
	len = 0;
	ft_putunsigned(i);
	if (i == 0)
		len++;
	while (i > 0)
	{
		i = i / 10;
		len++;
	}
	return (len);
}
