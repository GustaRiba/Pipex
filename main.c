/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorais- <gmorais-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 17:15:00 by gmorais-          #+#    #+#             */
/*   Updated: 2023/07/12 16:26:15 by gmorais-         ###   ########.fr       */
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
	dup2(fd[1], STDOUT_FILENO);
	dup2(fin, STDIN_FILENO);
	close(fin);
	close(fd[1]);
	close(fd[0]);
	exec(argv[2], env);
}

void	parent_pro(char **argv, char **env, int *fd)
{
	int	fileout;

	fileout = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fileout == -1)
	{
		error();
		close(fd[1]);
		close(fd[0]);
		close(fileout);
	}
	dup2(fd[0], STDIN_FILENO);
	dup2(fileout, STDOUT_FILENO);
	close(fd[1]);
	close(fd[0]);
	close(fileout);
	exec(argv[3], env);
}

void	error(void)
{
	perror("error");
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv, char **env)
{
	int		fd[2];
	pid_t	pid1;

	if (argc == 5)
	{
		if (pipe(fd) == -1)
			error();
		pid1 = fork();
		if (pid1 == -1)
			error();
		if (pid1 == 0)
			child_pro(argv, env, fd);
		waitpid(pid1, NULL, 1);
		parent_pro(argv, env, fd);
		close(fd[0]);
		close(fd[1]);
	}
	else
		ft_putstr_fd("Error!", 2);
	return (0);
}
