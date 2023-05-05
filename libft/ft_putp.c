/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstockma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 14:22:01 by vstockma          #+#    #+#             */
/*   Updated: 2022/10/19 14:22:02 by vstockma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putptr(long unsigned int i)
{
	char	*arr;

	arr = "0123456789abcdef";
	if (i >= 16)
	{
		ft_putptr(i / 16);
		ft_putptr(i % 16);
	}
	else
		ft_putchar(arr[i]);
}

int	ft_putp(va_list args)
{
	int					len;
	long unsigned int	ptr;

	ptr = va_arg(args, long unsigned int);
	len = 0;
	if (ptr == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	if (ptr != 0)
	{
		write(1, "0x", 2);
		len = 2;
	}
	ft_putptr(ptr);
	if (ptr == 0)
		len++;
	while (ptr > 0)
	{
		ptr = ptr / 16;
		len++;
	}
	return (len);
}
