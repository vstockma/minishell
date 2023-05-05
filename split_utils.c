/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 12:47:54 by valentin          #+#    #+#             */
/*   Updated: 2023/05/05 15:57:03 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_skip_spaces(char *str, int i)
{
    while (str[i] && str[i] == ' ')
        i++;
    return (i);
}

int ft_if_semi(t_mini *mini, int i)
{
    int j;

    j = 0;
    mini->args[mini->index] = malloc(sizeof(char) * (ft_get_len_if_semi(mini->input, i) + 1));
    ft_look_for_pair(mini, i);
    while (mini->input[i])
    {
        mini->args[mini->index][j] = mini->input[i];
        j++;
        i++;
        if (mini->input[i] == '\'')
            break ;
    }
    if (mini->flag == 1)
    {
        mini->flag = 0;
        mini->args[mini->index][j] = '\'';
        i++;
    }
    mini->index++;
    return (i);
}

int ft_if_double(t_mini *mini, int i)
{
    int j;

    j = 0;
    mini->args[mini->index] = malloc(sizeof(char) * (ft_get_len_if_double(mini->input, i) + 1));
    while (mini->input[i])
    {
        mini->args[mini->index][j] = mini->input[i];
        j++;
        i++;
        if (mini->input[i] == '"')
            break ;
    }
    mini->args[mini->index][j] = '"';
    i++;
    mini->index++;
    return (i);
}

int ft_put_in_args(t_mini *mini, int i)
{
    int j;

    j = 0;
    i = ft_skip_spaces(mini->input, i);
    mini->args[mini->index] = malloc(sizeof(char) * (ft_get_len_if_space(mini->input, i) + 1));
    while (mini->input[i])
    {
        if (mini->input[i] == ' ')
            break ;
        else if (mini->input[i] == '\'' || mini->input[i] == '"')
        {
            ft_look_for_pair(mini, i);
            if (mini->flag == 1)
            {
                mini->flag = 0;
                break ;
            }
        }
        mini->args[mini->index][j] = mini->input[i];
        j++;
        i++;
    }
    mini->index++;
    return (i);
}

