/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstockma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 17:01:16 by vstockma          #+#    #+#             */
/*   Updated: 2022/10/03 17:01:17 by vstockma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	lend;
	size_t	lens;

	j = 0;
	if (!dest && size == 0)
		return (0);
	lend = (size_t) ft_strlen(dest);
	lens = (size_t) ft_strlen(src);
	if (size <= lend)
		return (size + lens);
	i = lend;
	while (src[j] && i + 1 < size)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (ft_strlen(dest) + ft_strlen(&src[j]));
}
