/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstockma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 12:26:39 by vstockma          #+#    #+#             */
/*   Updated: 2022/10/07 12:26:40 by vstockma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(long n)
{
	int	strlen;

	strlen = 0;
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

static char	*ft_str(char *str, long num, int i)
{
	if (num == 0)
	{
		str[0] = '0';
		return (str);
	}
	if (num < 0)
	{
		num = -num;
		str[0] = '-';
	}
	while (num > 0)
	{
		str[i] = 48 + (num % 10);
		num = num / 10;
		i--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	long	num;

	num = n;
	i = ft_len(num);
	str = malloc((i + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[i--] = '\0';
	ft_str(str, num, i);
	return (str);
}

/*int	main()
{
	printf("%s", ft_itoa(-0));
	return (0); 

}*/
