/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_len.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 14:12:43 by valentin          #+#    #+#             */
/*   Updated: 2023/05/05 15:44:36 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_get_len_if_space(char *str, int i)
{
    int j;

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

int ft_get_len_if_semi(char *str, int i)
{
    int j;

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

int ft_get_len_if_double(char *str, int i)
{
    int j;

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

void    ft_look_for_pair(t_mini *mini, int i)
{
    if (mini->input[i] == '\'')
    {
        i++;
        while (mini->input[i])
        {
            if (mini->input[i] == '\'')
            {
                mini->flag = 1;
                break ;
            }
            i++;
        }
    }
    else if (mini->input[i] == '"')
    {
        i++;
        while (mini->input[i])
        {
            if (mini->input[i] == '"')
            {
                mini->flag = 1;
                break ;
            }
            i++;
        }
    }
}