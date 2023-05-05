/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstockma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 11:45:19 by vstockma          #+#    #+#             */
/*   Updated: 2022/10/04 11:45:20 by vstockma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*desti;
	char	*srci;

	desti = (char *) dest;
	srci = (char *) src;
	i = 0;
	if (!dest && !src)
		return (NULL);
	while (i < n)
	{
		desti[i] = srci[i];
		i++;
	}
	return (dest);
}
