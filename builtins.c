/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstockma <vstockma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:26:11 by vstockma          #+#    #+#             */
/*   Updated: 2023/05/08 10:49:19 by vstockma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    ft_free_args(t_mini *mini)
{
    int i;

    i = 0;
    while (mini->args[i] != NULL)
    {
        free(mini->args[i]);
        i++;
    }
    free(mini->args);
}

void    ft_exit(char *input, t_mini *mini)
{
    free(input);
    rl_clear_history();
    ft_free_args(mini);
    exit (0);
}

void    ft_change_directory(t_mini *mini)
{
    if (chdir(mini->args[1]) != 0)
        perror("cd");
}

void    ft_show_directory()
{
    char cwd[1024];
    
    if (getcwd(cwd, sizeof(cwd)) != NULL) 
        printf("%s\n", cwd);
    else 
        perror("getcwd() error");
}

void    ft_show_environment(char **envp)
{
    char **env = envp;
    while (*env != NULL) 
    {
        printf("%s\n", *env);
        env++;
    }  
}

void    ft_handle_echo(t_mini *mini)
{
    if (ft_strncmp(mini->args[1], "-n", ft_strlen(mini->args[1])) != 0)
    {
        //ft_echo(mini->args, 1);
        write(1,"\n",1);        
    }
    else
    {
        //ft_echo(mini->args, 2);
        write(1,"\n",1); 
    }
}

void ft_set_environment_variable(char *name, char *value, char **envp) 
{
    int i;
    char *new_envp;

    i = 0;
    while (envp[i] != NULL) 
    {
        if (ft_strncmp(name, envp[i], ft_strlen(name)) == 0) 
        {           
            new_envp = ft_strjoin(ft_strjoin(name, "="), value);
            free(envp[i]);
            envp[i] = new_envp;
            return;
        }
        i++;
    }   
    if (value != NULL)
        new_envp = ft_strjoin(ft_strjoin(name, "="), value);
    else 
        new_envp = ft_strdup(name);    
    envp[i] = new_envp;
    envp[i + 1] = NULL;
}

void    ft_unset_environment_variable(char *name, char **envp)
{
    int i = 0;
    int j = 0;
    int found = 0;

    while (envp[i] != NULL)
    {
        if (ft_strncmp(name, envp[i], ft_strlen(name)) == 0 &&
            envp[i][ft_strlen(name)] == '=')
        {
            found = 1;
            free(envp[i]);
            while (envp[i + j + 1] != NULL)
            {
                envp[i + j] = envp[i + j + 1];
                j++;
            }
        }
        i++;
    }
    if (!found)
        ft_printf("unset: %s: No such variable in environment.\n", name);
}

void    ft_handle_export(t_mini *mini, char **envp)
{
    if (mini->args[1] != NULL)
    {
        char *name = mini->args[1];
        char *value = "";
        if (mini->args[2] != NULL) 
            value = mini->args[2];        
        ft_set_environment_variable(name, value, envp);
    } 
    else 
        ft_show_environment(envp);
}