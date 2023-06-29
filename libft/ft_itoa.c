/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorais- <gmorais-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 10:45:13 by gmorais-          #+#    #+#             */
/*   Updated: 2022/11/09 11:19:38 by gmorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	contagem(int n)
{
	if (n > 0)
		return (0);
	return (1);
}

static int	negativo(int n)
{
	if (n > 0)
		return (1);
	return (-1);
}

char	*ft_itoa(int n)
{
	long	num;
	char	*res;
	size_t	len;

	len = contagem(n);
	num = (long)n * negativo(n);
	while (n)
	{
		n = n / 10;
		len++;
	}
	res = (char *)malloc(len + 1);
	if (!res)
		return (0);
	*(res + len--) = '\0';
	while (num > 0)
	{
		*(res + len--) = num % 10 + 48;
		num /= 10;
	}
	if (len == 0 && res[1] == '\0')
		*(res + len) = 48;
	else if (len == 0 && res[1] != '\0')
		*(res + len) = '-';
	return (res);
}

/*transforma um int em um char.
escreve de traz para a frente*/