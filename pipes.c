/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstockma <vstockma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:56:35 by vstockma          #+#    #+#             */
/*   Updated: 2023/05/03 14:36:11 by vstockma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    ft_execute_built_ins(t_mini *mini, char *input, char **envp)
{
    if (ft_strncmp(mini->args[0], "exit", ft_strlen(mini->args[0])) == 0)
        ft_exit(input, mini);
    else if (ft_strncmp(mini->args[0], "cd", ft_strlen(mini->args[0])) == 0)
        ft_change_directory(mini);
    else if (ft_strncmp(mini->args[0], "pwd", ft_strlen(mini->args[0])) == 0)
        ft_show_directory();
    else if (ft_strncmp(mini->args[0], "env", ft_strlen(mini->args[0])) == 0)
        ft_show_environment(envp);
    else if (ft_strncmp(mini->args[0], "echo", ft_strlen(mini->args[0])) == 0)
        ft_handle_echo(mini); 
     else if (ft_strncmp(mini->args[0], "unset", ft_strlen(mini->args[0])) == 0)
        ft_unset_environment_variable(mini->args[1], envp);
    else if (ft_strncmp(mini->args[0], "export", ft_strlen(mini->args[0])) == 0)
        ft_handle_export(mini, envp);
    else
        ft_printf("Command Not Found\n");
}

int ft_is_builtin(char *command)
{
    if (ft_strncmp(command, "cd", ft_strlen(command)) == 0 ||
        ft_strncmp(command, "echo", ft_strlen(command)) == 0 ||
        ft_strncmp(command, "env", ft_strlen(command)) == 0 ||
        ft_strncmp(command, "exit", ft_strlen(command)) == 0 ||
        ft_strncmp(command, "pwd", ft_strlen(command)) == 0 ||
        ft_strncmp(command, "unset", ft_strlen(command)) == 0 ||
        ft_strncmp(command, "export", ft_strlen(command)) == 0) 
    {
        return 1;
    }
    return 0;
}

void    ft_execute_child_process(int *pipefd, t_mini *mini, char **envp)
{
    close(pipefd[0]);
    dup2(pipefd[1], STDOUT_FILENO);
    close(pipefd[1]);

    if (ft_is_builtin(mini->cmd1[0]))
        ft_execute_built_ins(mini, NULL, envp);
    else
        ft_search_and_execute(mini, envp);
    exit(0);

}

void    ft_execute_parent_process(int *pipefd, t_mini *mini, char **envp)
{
    mini->stdin_copy = dup(STDIN_FILENO);
    close(pipefd[1]);
    dup2(pipefd[0], STDIN_FILENO);
    close(pipefd[0]);

    if (ft_is_builtin(mini->cmd2[0]))
        ft_execute_built_ins(mini, NULL, envp);
    else
        ft_search_and_execute(mini, envp);
    dup2(mini->stdin_copy, STDIN_FILENO);
    close(mini->stdin_copy);
}

void    ft_pipe(t_mini *mini, char **envp)
{
    int pipefd[2];
    if (pipe(pipefd) == -1)
    {
        perror("pipe");
        return ;
    }
    pid_t pid = fork();
    if (pid < 0) 
    {
        perror("fork");
        return ;
    }
    if (pid == 0) 
        ft_execute_child_process(pipefd, mini, envp);
    else
    {
        ft_execute_parent_process(pipefd, mini, envp);
        waitpid(pid, NULL, 0);
    }
}

int ft_check_pipes(t_mini *mini)
{
    int i;

    i = 0;
    while (mini->args[i] != NULL)
    {
        if (strcmp(mini->args[i], "|") == 0)
            return (i);
        i++;
    }
    return (-1);
}

void    ft_piper_at_the_gates_of_dawn(t_mini *mini, int pipe_index, char **envp)
{
    mini->args[pipe_index] = NULL;
    mini->cmd1 = mini->args;
    mini->cmd2 = &mini->args[pipe_index + 1];
    ft_pipe(mini, envp);
}