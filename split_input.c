/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstockma <vstockma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:09:49 by vstockma          #+#    #+#             */
/*   Updated: 2023/05/08 15:42:58 by vstockma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_count_argc(t_mini *mini)
{
	(void)mini;
	return (1000);
}

void	ft_split_input(t_mini *mini)
{
	mini->i = 0;
	mini->argc = ft_count_argc(mini);
	mini->args = malloc(sizeof(char *) * mini->argc);
	if (!mini->args)
	{
		free(mini->args);
		return ;
	}
	while (mini->input[mini->i])
	{
		ft_skip_spaces(mini, mini->input);
		if (mini->input[mini->i] == '\0')
			break ;
		if (mini->input[mini->i] == '\'')
			ft_if_semi(mini);
		else if (mini->input[mini->i] == '"')
			ft_if_double(mini);
		else
			ft_put_in_args(mini);
	}
}
