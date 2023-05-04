/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstockma <vstockma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:44:19 by vstockma          #+#    #+#             */
/*   Updated: 2023/05/04 16:21:32 by vstockma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    ft_read_input(t_mini *mini, char **envp)
{
    (void)envp;
    ft_split_input(mini);
    if (mini->args[0] == NULL)
    {
        free(mini->args);
        return ;
    }    
}

void    ft_init_struct(t_mini *mini, char **envp)
{
    mini->input = NULL;
    mini->env = envp;
    mini->input_fd = -1;
    mini->output_fd = -1;
    mini->append_fd = -1;
    mini->stdin_copy = -1;
    mini->stdout_copy = -1;
    mini->index_of_arg = 0;
}

int main(int ac, char **av, char **envp)
{
    t_mini  mini;

    ft_init_struct(&mini, envp);
   (void)ac;
    mini.input = av[1];
    if (mini.input == NULL)
    {
        printf("exit\n");
        free(mini.input);
        exit(0);
    }
    ft_read_input(&mini, envp);
    return (0);
}
