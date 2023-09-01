/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorais- <gmorais-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 17:15:00 by gmorais-          #+#    #+#             */
/*   Updated: 2023/09/01 16:28:22 by gmorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_pro(char **argv, char **env, int *fd)
{
	int	fin;

	fin = open(argv[1], O_RDONLY, 0644);
	if (fin == -1)
	{
		error();
		close(fin);
		close(fd[1]);
		close(fd[0]);
	}
	close(fd[0]);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	dup2(fin, STDIN_FILENO);
	close(fin);
	exec(argv[2], env);
}

void	parent_pro(char **argv, char **env, int *fd)
{
	int	fileout;
	int	dups[2];

	fileout = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fileout == -1)
	{
		close(fd[1]);
		close(fd[0]);
		close(fileout);
		error();
	}
	dups[0] = dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	dups[1] = dup2(fileout, STDOUT_FILENO);
	close(fileout);
	exec(argv[3], env);
	close(dups[0]);
	close(dups[1]);
}

void	error(void)
{
	perror("error");
	exit(EXIT_FAILURE);
}

void	creat_pid(char **argv, char **env, int *fd)
{
	pid_t	pid1;
	pid_t	pid2;

	pid1 = fork();
	if (pid1 == -1)
		error();
	if (pid1 == 0)
		child_pro(argv, env, fd);
	close(fd[1]);
	pid2 = fork();
	if (pid2 == -1)
		error();
	if (pid2 == 0)
		parent_pro(argv, env, fd);
	close(fd[0]);
	return ;
}

int	main(int argc, char **argv, char **env)
{
	int		fd[2];

	if (argc == 5)
	{
		if (pipe(fd) == -1)
			error();
		creat_pid(argv, env, fd);
		close(fd[0]);
		close(fd[1]);
		waitpid(-1, NULL, WUNTRACED);
	}
	else
		ft_putstr_fd("Error!\n", 2);
	return (0);
}
