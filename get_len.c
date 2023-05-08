/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_len.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstockma <vstockma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 14:12:43 by valentin          #+#    #+#             */
/*   Updated: 2023/05/08 15:42:55 by vstockma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_get_len_if_space(t_mini *mini, char *str)
{
	int	j;
	int	i;

	i = mini->i;
	j = 0;
	while (str[i] && (str[i] != ' '))
	{
		if (str[i] == ' ')
			break ;
		j++;
		i++;
	}
	return (j);
}

int	ft_get_len_if_semi(t_mini *mini, char *str)
{
	int	j;
	int	i;

	i = mini->i;
	j = 1;
	i++;
	while (str[i])
	{
		if (str[i] == '\'')
		{
			j++;
			break ;
		}
		j++;
		i++;
	}
	return (j);
}

int	ft_get_len_if_double(t_mini *mini, char *str)
{
	int	j;
	int	i;

	i = mini->i;
	j = 1;
	i++;
	while (str[i])
	{
		if (str[i] == '"')
		{
			j++;
			break ;
		}
		j++;
		i++;
	}
	return (j);
}

void	ft_look_for_pair(t_mini *mini)
{
	char	pair_char;
	int		i;

	i = mini->i;
	pair_char = mini->input[i];
	i++;
	while (mini->input[i])
	{
		if (mini->input[i] == pair_char)
		{
			mini->flag = 1;
			break ;
		}
		i++;
	}
}
