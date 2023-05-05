/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putX.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstockma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 14:22:29 by vstockma          #+#    #+#             */
/*   Updated: 2022/10/19 14:22:30 by vstockma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_puthexup(unsigned int i)
{
	char	*arr;

	arr = "0123456789ABCDEF";
	if (i >= 16)
	{
		ft_puthexup(i / 16);
		ft_puthexup(i % 16);
	}
	else
		ft_putchar(arr[i]);
}

int	ft_putxupper(va_list args)
{
	int				len;
	unsigned int	i;

	len = 0;
	i = va_arg(args, unsigned int);
	ft_puthexup(i);
	if (i == 0)
		len++;
	while (i > 0)
	{
		i = i / 16;
		len++;
	}
	return (len);
}
