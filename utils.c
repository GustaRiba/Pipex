/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorais- <gmorais-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 17:27:07 by gmorais-          #+#    #+#             */
/*   Updated: 2023/09/01 16:32:47 by gmorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_path(char *cmd, char **env, int i)
{
	char	**paths;
	char	*path;
	char	*part_path;

	if (!cmd)
		return (0);
	while (ft_strnstr(env[i], "PATH", 4) == 0)
		i++;
	paths = ft_split(env[i] + 5, ':');
	i = -1;
	while (paths[++i])
	{
		part_path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(part_path, cmd);
		free(part_path);
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
	}
	i = -1;
	while (paths[++i])
		free(paths[i]);
	free(paths);
	return (0);
}

void	exec(char *argv, char **env)
{
	char	**cmd;
	int		i;
	char	*path;

	i = -1;
	cmd = ft_split(argv, ' ');
	path = find_path(cmd[0], env, 0);
	if (!path)
	{
		write(2, "pipex: command not found: ", 26);
		write(2, cmd[0], ft_strlen(cmd[0]));
		write(2, "\n", 1);
		check_path();
		while (cmd[++i])
			free(cmd[i]);
		free(cmd);
	}
	if (execve(path, cmd, env) == -1)
	{
		close(1);
		close(0);
	}
	error();
}

void	check_path(void)
{
	close(1);
	close(0);
	exit(EXIT_FAILURE);
}

int	check(char *cmd)
{
	int	flag;
	int	i;

	flag = 0;
	i = 0;
	if (!cmd)
		return (0);
	while (cmd[i] != '\0')
	{
		if (cmd[i] == '/')
			flag = 1;
		if (flag == 1)
		{
			if (access(cmd, F_OK) == 0)
				return (1);
		}
		i++;
	}
	return (0);
}
