/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstockma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:16:03 by vstockma          #+#    #+#             */
/*   Updated: 2022/10/05 16:16:05 by vstockma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_putsubstr(char *str, const char *s, size_t len, size_t start)
{
	size_t	i;

	i = 0;
	while (s[start] && i < len)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = 0;
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_str;
	size_t	newlen;

	if (!s)
		return (NULL);
	if (start > (unsigned int) ft_strlen(s))
	{
		sub_str = malloc(sizeof(char) * 1);
		if (!sub_str)
			return (NULL);
		sub_str[0] = 0;
		return (sub_str);
	}
	newlen = (size_t) ft_strlen(s) - start;
	if (len > (unsigned int) ft_strlen(s) - start)
		sub_str = malloc(sizeof(char) * (newlen + 1));
	else
		sub_str = malloc(sizeof(char) * (len + 1));
	if (!sub_str)
		return (NULL);
	return (ft_putsubstr(sub_str, s, len, start));
}
