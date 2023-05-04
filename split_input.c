/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstockma <vstockma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:09:49 by vstockma          #+#    #+#             */
/*   Updated: 2023/05/04 16:47:42 by vstockma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_count_argc(t_mini *mini)
{
    (void)mini;
    return (100);
}


int ft_skip_spaces(char *str, int i)
{
    while (str[i] && str[i] == ' ')
        i++;
    return (i);
}

int ft_put_in_args(t_mini *mini, int i)
{
    int j;
    static int index;
    j = 0;
    i = ft_skip_spaces(mini->input, i);
    while (mini->input[i] && (mini->input[i] != ' ' || mini->input[i] != 39 || mini->input[i] != '"'))
    {
        mini->args[index] = mini->input;
        j++;
        i++;
    }
    index++;
    return (i);
}

void    ft_split_input(t_mini *mini)
{
    int i;

    i = 0;
    mini->argc = ft_count_argc(mini);
    mini->args = malloc(sizeof(char *) * mini->argc);
    while (mini->input[i] == ' ')
        i++;
    mini->start = i;
    while (mini->input[i])
    {
        if (mini->input[i] == ' ')
        {
            i = ft_put_in_args(mini, i);
        }
        i++;
    }
    while (i < 5)
    {
        printf("%s", mini->args[i]);
        i++;
    }
}