/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstockma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 14:22:10 by vstockma          #+#    #+#             */
/*   Updated: 2022/10/19 14:22:11 by vstockma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putint(int nb)
{
	if (nb == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		ft_putint(147483648);
	}
	else if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
		ft_putint(nb);
	}
	else if (nb > 9)
	{
		ft_putint(nb / 10);
		ft_putint(nb % 10);
	}
	else
		ft_putchar(nb + '0');
}

static int	ft_len(int n)
{
	int	strlen;

	strlen = 0;
	if (n == -2147483648)
	{
		strlen = 11;
		return (strlen);
	}
	if (n < 0)
	{
		n = -n;
		strlen++;
	}
	if (n == 0)
		strlen++;
	while (n > 0)
	{
		n = n / 10;
		strlen++;
	}
	return (strlen);
}

int	ft_putdi(va_list args)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	i = va_arg(args, int);
	ft_putint(i);
	len = ft_len(i);
	return (len);
}
