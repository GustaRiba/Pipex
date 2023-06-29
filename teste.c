/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorais- < gmorais-@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 17:15:00 by gmorais-          #+#    #+#             */
/*   Updated: 2023/06/29 17:57:01 by gmorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_pro(char **argv, char **env, int *fd)
{
	int fin;

	fin = open(argv[1], O_RDONLY, 0777);
	if (fin == -1)
		error();
	dup2(fd[1], STDOUT_FILENO);
	dup2(fin, STDIN_FILENO);
	close(fd[0]);
	exec(argv[2], env);
}

void	parent_pro(char **argv, char **env, int *fd)
{
	int	fileout;
	
	fileout = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fileout == -1)
		error();
	dup2(fd[0], STDIN_FILENO);
	dup2(fileout, STDOUT_FILENO);
	close(fd[1]);
	exec(argv[3], env);
}

void	error(void)
{
	perror("error");
	exit(EXIT_FAILURE);
}

int main(int argc, char **argv, char **env)
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
		waitpid(pid1, NULL, 0);
		parent_pro(argv, env, fd);
	}
	else
		ft_putstr_fd("Error!", 2);
	return (0);
}
