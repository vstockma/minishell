/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstockma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 14:37:34 by vstockma          #+#    #+#             */
/*   Updated: 2022/10/07 14:37:38 by vstockma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_cat(char *str, const char *s1, const char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		size;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen((char *) s1) + ft_strlen((char *) s2);
	str = malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	ft_cat(str, s1, s2);
	str[size] = 0;
	return (str);
}
