/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstockma <vstockma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 12:47:54 by valentin          #+#    #+#             */
/*   Updated: 2023/05/08 16:16:08 by vstockma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_skip_spaces(t_mini *mini, char *str)
{
	while (str[mini->i] && str[mini->i] == ' ')
		mini->i++;
}

void	ft_put_in_args(t_mini *mini)
{
	int	j;

	j = 0;
	mini->args[mini->index] = malloc(sizeof(char) * (ft_get_len_if_space(mini,
					mini->input) + 1));
	while (mini->input[mini->i])
	{
		if (mini->input[mini->i] == ' ')
			break ;
		else if (mini->input[mini->i] == '\'' || mini->input[mini->i] == '"')
		{
			ft_look_for_pair(mini);
			if (mini->flag == 1)
			{
				mini->flag = 0;
				break ;
			}
		}
		mini->args[mini->index][j] = mini->input[mini->i];
		j++;
		mini->i++;
	}
	mini->args[mini->index][j] = '\0';
	mini->index++;
}

void	ft_if_semi(t_mini *mini)
{
	int	j;

	j = 0;
	mini->args[mini->index] = malloc(sizeof(char) * (ft_get_len_if_semi(mini,
					mini->input) + 1));
	if (!mini->args[mini->index])
	{
		free(mini->args[mini->index]);
		return ;
	}
	ft_look_for_pair(mini);
	while (mini->input[mini->i])
	{
		mini->args[mini->index][j] = mini->input[mini->i];
		j++;
		mini->i++;
		if (mini->input[mini->i] == '\'')
			break ;
		else if (mini->input[mini->i] == '"' && mini->flag == 0)
			break ;
	}
	ft_useless(mini, j, 2);
	mini->index++;
}

void	ft_if_double(t_mini *mini)
{
	int	j;

	j = 0;
	mini->args[mini->index] = malloc(sizeof(char) * (ft_get_len_if_double(mini,
					mini->input) + 1));
	if (!mini->args[mini->index])
	{
		free(mini->args[mini->index]);
		return ;
	}
	ft_look_for_pair(mini);
	while (mini->input[mini->i])
	{
		mini->args[mini->index][j] = mini->input[mini->i];
		j++;
		mini->i++;
		if (mini->input[mini->i] == '"')
			break ;
		else if (mini->input[mini->i] == '\'' && mini->flag == 0)
			break ;
	}
	ft_useless(mini, j, 1);
	mini->index++;
}

void	ft_useless(t_mini *mini, int j, int x)
{
	if (x == 1)
	{
		if (mini->flag == 1)
		{
			mini->flag = 0;
			mini->args[mini->index][j] = '"';
			mini->i++;
			j++;
		}
		mini->args[mini->index][j] = '\0';
	}
	else
	{
		if (mini->flag == 1)
		{
			mini->flag = 0;
			mini->args[mini->index][j] = '\'';
			j++;
			mini->i++;
		}
		mini->args[mini->index][j] = '\0';
	}
}
