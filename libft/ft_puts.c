/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstockma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 14:21:53 by vstockma          #+#    #+#             */
/*   Updated: 2022/10/19 14:21:54 by vstockma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_puts(va_list args)
{
	int		i;
	int		len;
	char	*str;

	i = 0;
	len = 0;
	str = va_arg(args, char *);
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
		len++;
	}
	return (len);
}
