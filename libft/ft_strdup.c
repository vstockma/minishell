/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstockma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 17:06:56 by vstockma          #+#    #+#             */
/*   Updated: 2022/10/03 17:07:01 by vstockma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*ptr;
	int		i;
	char	*source;

	i = 0;
	source = (char *) src;
	ptr = malloc((sizeof(char) * ft_strlen(source) + 1));
	if (!ptr)
		return (NULL);
	while (source[i])
	{
		ptr[i] = source[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
