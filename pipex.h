/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorais- <gmorais-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 17:13:15 by gmorais-          #+#    #+#             */
/*   Updated: 2023/09/01 14:52:59 by gmorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <string.h>

void	exec(char *argv, char **env);
void	error(void);
int		check(char *cmd);
int		ft_printf(const char *str, ...);
void	ft_putstr(char *str, int *len);
void	ft_putchar(char c, int *len);
void	percentage_check(char c, va_list *args, int *len, int *i);
void	ft_putadress(unsigned long n, int *len);
void	ft_putnbr(int n, int *len);
void	ft_unsigned_nbr(unsigned int n, int *len);
void	ft_hexa(unsigned int n, int *len, char esc);
void	check_path(void);

#endif