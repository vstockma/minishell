/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstockma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 08:37:07 by vstockma          #+#    #+#             */
/*   Updated: 2022/10/04 08:37:11 by vstockma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	strlen;
	char	*hay;
	char	*needle;

	i = 0;
	hay = (char *)big;
	needle = (char *)little;
	strlen = ft_strlen(needle);
	if (strlen == 0 || big == needle)
		return (hay);
	if (len == 0)
		return (NULL);
	while (hay[i] && i < len)
	{
		j = 0;
		while (hay[i + j] && needle[j] && hay[i + j] == needle[j]
			&& i + j < len)
			j++;
		if (j == strlen)
			return (hay + i);
		i++;
	}
	return (0);
}
