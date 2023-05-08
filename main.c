/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstockma <vstockma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:44:19 by vstockma          #+#    #+#             */
/*   Updated: 2023/05/08 16:00:34 by vstockma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void execute_external(char *path, t_mini *mini, char **envp)
{
    pid_t pid = fork();

    if (pid == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    } 
    else if (pid == 0)
    {

        execve(path, mini->args, envp);
        perror("execv");
        exit(EXIT_FAILURE);
    } 
    else 
    {
        int status;
        waitpid(pid, &status, 0);
    }
}

void    ft_search_and_execute(t_mini *mini, char **envp)
{
    char *path_env = getenv("PATH");
    char **dirs = ft_split(path_env, ':');
    int i = 0;

    while (dirs[i]) 
    {
        char *dir_path = ft_strjoin(dirs[i], "/");
        char *path = ft_strjoin(dir_path, mini->args[0]);
        free(dir_path);
        
        if (access(path, F_OK | X_OK) == 0) 
        {          
            execute_external(path, mini, envp);
            free(path);
            ft_free_args(mini);
            return;
        }
        free(path);
        i++;
    }
    ft_printf("Command not found: %s\n", mini->args[0]);
    ft_free_args(mini);
}

void    ft_read_input(t_mini *mini, char **envp)
{
    (void)envp;
    ft_split_input(mini);

    int i = 0;
    while (i < mini->index)
    {
        printf("arg[%i]= %s\n", i, mini->args[i]);
        i++;
    }

    if (mini->args[0] == NULL)
    {
        return ;
    }
    ft_handle_redirection(mini);
    ft_apply_redirection(mini);
    if (ft_check_pipes(mini) != -1)
        ft_piper_at_the_gates_of_dawn(mini, ft_check_pipes(mini), envp);
    
}

void    ft_init_struct(t_mini *mini, char **envp)
{
    mini->env = envp;
    mini->input_fd = -1;
    mini->output_fd = -1;
    mini->append_fd = -1;
    mini->stdin_copy = -1;
    mini->stdout_copy = -1;
    mini->index = 0;
    mini->flag = 0;
    mini->i = 0;
}

void sigint_handler(int sig)
{
    (void)sig;
    ft_printf("\n"); // Display a new line
    rl_on_new_line(); // Move to a new line
    rl_replace_line("", 0); // Clear the current input line
    rl_redisplay(); // Redraw the prompt
}

void    ft_free_input(t_mini *mini)
{
    int i = 0;
    while (i < mini->index)
    {
        free(mini->args[i]);
        i++;
    }
    free(mini->args);
    mini->index = 0;
}

int main(int ac, char **av, char **envp)
{
    t_mini  mini;

    (void)av;
    ft_init_struct(&mini, envp);

    if (ac >= 2)
        return(1);

    signal(SIGINT, sigint_handler);
    
    while (1)
    {
        mini.input =readline("~$ ");
        if (mini.input == NULL)
        {
            ft_printf("exit\n");
            free(mini.input);
            exit(0);
        }
        if (mini.input && *mini.input)
            add_history(mini.input);
        ft_read_input(&mini, envp);
        ft_free_input(&mini);
    }
    return (0);
}