/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstockma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 14:22:25 by vstockma          #+#    #+#             */
/*   Updated: 2022/10/19 14:22:25 by vstockma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_puthexlow(unsigned int i)
{
	char	*arr;

	arr = "0123456789abcdef";
	if (i >= 16)
	{
		ft_puthexlow(i / 16);
		ft_puthexlow(i % 16);
	}
	else
		ft_putchar(arr[i]);
}

int	ft_putxlower(va_list args)
{
	int				len;
	unsigned int	i;

	len = 0;
	i = va_arg(args, unsigned int);
	ft_puthexlow(i);
	if (i == 0)
		len++;
	while (i > 0)
	{
		i = i / 16;
		len++;
	}
	return (len);
}
