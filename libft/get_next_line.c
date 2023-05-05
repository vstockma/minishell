/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstockma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:27:38 by vstockma          #+#    #+#             */
/*   Updated: 2022/12/07 12:30:32 by vstockma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_new_read(char *store_buf)
{
	size_t	len;
	size_t	i;
	char	*tmp;

	len = 0;
	i = 0;
	while (store_buf[i] != '\n' && store_buf[i] != '\0')
		i++;
	if (!store_buf[i])
	{
		free(store_buf);
		return (NULL);
	}
	tmp = malloc (sizeof(char) * (ft_strlen_gnl(store_buf) - i));
	if (tmp == NULL)
	{
		free (store_buf);
		return (NULL);
	}
	i++;
	while (store_buf[i] != '\0')
		tmp[len++] = store_buf[i++];
	tmp[len] = '\0';
	free(store_buf);
	return (tmp);
}

char	*ft_read_from_file(int fd, char *store_buf)
{
	int		read_len;
	char	*buf;

	buf = malloc (sizeof(char) * BUFFER_SIZE + 1);
	if (buf == NULL)
		return (NULL);
	read_len = 1;
	while (read_len != 0 && ft_strchr_gnl(store_buf, '\n') == 0)
	{
		read_len = read(fd, buf, BUFFER_SIZE);
		if (read_len == -1)
		{
			free (buf);
			free (store_buf);
			return (NULL);
		}
		buf[read_len] = '\0';
		store_buf = ft_strjoin_gnl(store_buf, buf);
	}
	free (buf);
	return (store_buf);
}

char	*ft_get_line(char *store_buf)
{
	char	*new;
	int		i;

	i = 0;
	if (store_buf[i] == '\0')
		return (NULL);
	while (store_buf[i] != '\n' && store_buf[i] != '\0')
		i++;
	new = malloc (sizeof(char) * (i + 2));
	if (new == NULL)
		return (NULL);
	i = 0;
	while (store_buf[i] != '\n' && store_buf[i] != '\0')
	{
		new[i] = store_buf[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*store_buf;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(store_buf);
		store_buf = NULL;
		return (NULL);
	}
	store_buf = ft_read_from_file(fd, store_buf);
	if (store_buf == NULL)
	{
		free(store_buf);
		store_buf = NULL;
		return (NULL);
	}
	line = ft_get_line(store_buf);
	if (store_buf == NULL)
		return (line);
	store_buf = ft_new_read(store_buf);
	return (line);
}
