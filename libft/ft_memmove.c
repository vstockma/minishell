/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstockma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:24:43 by vstockma          #+#    #+#             */
/*   Updated: 2022/10/04 15:24:44 by vstockma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*desti;
	char	*srci;

	desti = (char *) dest;
	srci = (char *) src;
	if (!dest && !src)
		return (NULL);
	i = 0;
	if (desti > srci)
	{
		while (n--)
			desti[n] = srci[n];
	}
	else
	{
		while (n--)
		{
			desti[i] = srci[i];
			i++;
		}
	}
	return (desti);
}
