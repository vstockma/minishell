/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstockma <vstockma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:44:58 by vstockma          #+#    #+#             */
/*   Updated: 2023/05/08 15:51:56 by vstockma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include "./libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <sys/types.h>
#include <sys/wait.h>

typedef struct s_mini
{
    char *input;
    char **args;
    int argc;
    char **env;
    int input_fd;
    int output_fd;
    int append_fd;
    int stdin_copy;
    int stdout_copy;
    int index;
    int flag;

    int i;

    char **cmd1;
    char **cmd2;
}   t_mini;

//main.c
void    ft_read_input(t_mini *mini, char **envp);
void    ft_init_struct(t_mini *mini, char **envp);
void sigint_handler(int sig);
void execute_external(char *path, t_mini *mini, char **envp);
void    ft_search_and_execute(t_mini *mini, char **envp);

//split_input.c
void    ft_split_input(t_mini *mini);
int ft_count_argc(t_mini *mini);

//split_utils.c
void ft_skip_spaces(t_mini *mini, char *str);
void ft_if_semi(t_mini *mini);
void ft_if_double(t_mini *mini);
void ft_put_in_args(t_mini *mini);
void    ft_useless(t_mini *mini, int j, int x);


//get_len.c
int	ft_get_len_if_space(t_mini *mini, char *str);
int	ft_get_len_if_semi(t_mini *mini, char *str);
int	ft_get_len_if_double(t_mini *mini, char *str);
void	ft_look_for_pair(t_mini *mini);

//redirections.c
void    ft_redirect_left(t_mini *mini, int i);
void    ft_redirect_right(t_mini *mini, int i);
void    ft_double_reirect_right(t_mini *mini, int i);
void    ft_double_redirect_left(t_mini *mini, int i);
void    ft_handle_redirection(t_mini *mini);
void    ft_apply_redirection(t_mini *mini);

//pipes.c
int ft_check_pipes(t_mini *mini);
void    ft_pipe(t_mini *mini, char **envp);
void    ft_piper_at_the_gates_of_dawn(t_mini *mini, int pipe_index, char **envp);
void    ft_execute_built_ins(t_mini *mini, char *input, char **envp);
int ft_is_builtin(char *command);
void    ft_execute_parent_process(int *pipefd, t_mini *mini, char **envp);
void    ft_execute_child_process(int *pipefd, t_mini *mini, char **envp);

//builtins.c
void    ft_free_args(t_mini *mini);
void    ft_exit(char *input, t_mini *mini);
void    ft_change_directory(t_mini *mini);
void    ft_show_directory();
void    ft_show_environment(char **envp);
void    ft_handle_echo(t_mini *mini);
void ft_set_environment_variable(char *name, char *value, char **envp);
void    ft_unset_environment_variable(char *name, char **envp);
void    ft_handle_export(t_mini *mini, char **envp);


#endif