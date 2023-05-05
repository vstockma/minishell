/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstockma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:01:17 by vstockma          #+#    #+#             */
/*   Updated: 2022/10/03 16:01:18 by vstockma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t			i;
	unsigned int	lens;
	char			*source;

	source = (char *) src;
	lens = ft_strlen(source);
	i = 0;
	if (size == 0)
		return (lens);
	while (source[i] && i < size - 1)
	{
		dest[i] = source[i];
		i++;
	}
	dest[i] = '\0';
	return (lens);
}
