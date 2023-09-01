/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorais- <gmorais-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 11:15:31 by gmorais-          #+#    #+#             */
/*   Updated: 2023/09/01 12:17:41 by gmorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	percentage_check(char c, va_list *args, int *len, int *i)
{
	if (c == 'c')
		ft_putchar(va_arg(*args, int), len);
	else if (c == 's')
		ft_putstr(va_arg(*args, char *), len);
	else if (c == 'p')
		ft_putadress(va_arg(*args, unsigned long), len);
	else if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(*args, int), len);
	else if (c == 'u')
		ft_unsigned_nbr(va_arg(*args, unsigned int), len);
	else if (c == 'x')
		ft_hexa(va_arg(*args, unsigned int), len, 'x');
	else if (c == 'X')
		ft_hexa(va_arg(*args, unsigned int), len, 'X');
	else if (c == '%')
		ft_putchar('%', len);
	else
		(*i)--;
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			percentage_check(str[i], &args, &len, &i);
			i++;
		}
		else
		{
			ft_putchar((char)str[i], &len);
			i++;
		}
	}
	va_end(args);
	return (len);
}
