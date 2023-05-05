/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstockma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 10:57:36 by vstockma          #+#    #+#             */
/*   Updated: 2022/10/05 10:57:37 by vstockma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*str;

	if (nmemb > 4294967295 || size > 4294967295)
		return (0);
	str = (void *) malloc(nmemb * size);
	if (!str)
		return (NULL);
	ft_bzero(str, nmemb * size);
	return (str);
}
