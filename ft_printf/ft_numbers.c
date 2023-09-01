/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorais- <gmorais-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:15:16 by gmorais-          #+#    #+#             */
/*   Updated: 2023/09/01 12:17:47 by gmorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	ft_putadress(unsigned long n, int *len)
{
	char	str[25];
	char	*hexo;
	int		i;

	i = 0;
	hexo = "0123456789abcdef";
	if (n == 0)
	{
		write(1, "(nil)", 5);
		(*len) += 5;
		return ;
	}
	else
	{
		write(1, "0x", 2);
		(*len) += 2;
	}
	while (n != 0)
	{
		str[i] = hexo[n % 16];
		n /= 16;
		i++;
	}
	while (i--)
		ft_putchar(str[i], len);
}

void	ft_putnbr(int n, int *len)
{
	char	c;

	c = n + 48;
	if (n >= INT_MIN && n <= __INT_MAX__)
	{
		if (n > 9)
		{
			ft_putnbr(n / 10, len);
			ft_putnbr(n % 10, len);
		}
		else if (n == -2147483648)
		{
			write(1, "-2147483648", 11);
			(*len) += 11;
			return ;
		}
		else if (n < 0)
		{
			n = -n;
			ft_putchar('-', len);
			ft_putnbr(n, len);
		}
		else
			ft_putchar(c, len);
	}
}

void	ft_unsigned_nbr(unsigned int n, int *len)
{
	if (n >= 10)
		ft_unsigned_nbr(n / 10, len);
	ft_putchar(n % 10 + '0', len);
}

void	ft_hexa(unsigned int n, int *len, char esc)
{
	char	str[25];
	char	*hexo;
	int		i;

	i = 0;
	if (n == 0)
		ft_putchar('0', len);
	if (esc == 'x')
		hexo = "0123456789abcdef";
	else
		hexo = "0123456789ABCDEF";
	while (n != 0)
	{
		str[i] = hexo[n % 16];
		n = n / 16;
		i++;
	}
	while (i--)
	{
		ft_putchar(str[i], len);
	}
}
