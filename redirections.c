/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstockma <vstockma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:39:01 by vstockma          #+#    #+#             */
/*   Updated: 2023/05/03 11:53:14 by vstockma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    ft_redirect_left(t_mini *mini, int i)
{
    mini->args[i] = NULL;
    mini->input_fd = open(mini->args[i + 1], O_RDONLY);
    if (mini->input_fd < 0)
    {
        perror("open input file");
        exit(1);
    }
}

void    ft_redirect_right(t_mini *mini, int i)
{
    mini->args[i] = NULL;
    mini->output_fd = open(mini->args[i + 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (mini->output_fd < 0)
    {
        perror("open output file");
        exit(1);
    }
}

void    ft_double_reirect_right(t_mini *mini, int i)
{
    mini->args[i] = NULL;
    mini->append_fd = open(mini->args[i + 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (mini->append_fd < 0)
    {
        perror("open output file");
        exit(1);
    }
}

void    ft_double_redirect_left(t_mini *mini, int i)
{
    (void)mini;
    i++;
}

void    ft_handle_redirection(t_mini *mini)
{
    int i;

    i = 0;
    while (mini->args[i] != NULL)
    {
        if (strcmp(mini->args[i], "<") == 0)
            ft_redirect_left(mini, i);
        else if (strcmp(mini->args[i], ">") == 0)
            ft_redirect_right(mini, i);
        else if (strcmp(mini->args[i], ">>") == 0)
            ft_double_reirect_right(mini, i);
        else if (strcmp(mini->args[i], "<<") == 0)
            ft_double_redirect_left(mini, i);
        i++;
    }
}

void    ft_apply_redirection(t_mini *mini)
{
    if (mini->input_fd != -1)
    {
        mini->stdin_copy = dup(STDIN_FILENO);
        dup2(mini->input_fd, STDIN_FILENO);
    }
    if (mini->output_fd != -1)
    {
        mini->stdout_copy = dup(STDOUT_FILENO);
        dup2(mini->output_fd, STDOUT_FILENO);
    }
    if (mini->append_fd != -1)
    {
        mini->stdout_copy = dup(STDOUT_FILENO);
        dup2(mini->append_fd, STDOUT_FILENO);
    }
}