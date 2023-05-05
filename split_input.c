/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:09:49 by vstockma          #+#    #+#             */
/*   Updated: 2023/05/05 15:55:45 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_count_argc(t_mini *mini)
{
    (void)mini;
    return (1000);
}

void    ft_split_input(t_mini *mini)
{
    int i;

    i = 0;
    mini->argc = ft_count_argc(mini);
    mini->args = malloc(sizeof(char *) * mini->argc);
    while (mini->input[i])
    {
        i = ft_skip_spaces(mini->input, i);
        if (mini->input[i] == '\0')
            break ;
        if (mini->input[i] == '\'')
            i = ft_if_semi(mini, i);
        else if (mini->input[i] == '"')
            i = ft_if_double(mini, i);
        else
            i = ft_put_in_args(mini, i);
    }
}