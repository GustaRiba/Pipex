/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorais- <gmorais-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 18:32:36 by gmorais-          #+#    #+#             */
/*   Updated: 2022/11/09 11:19:56 by gmorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	a;
	int	b;
	int	rent;

	a = 0;
	b = 1;
	rent = 0;
	while (nptr[a] == 32 || nptr[a] == '\n' || nptr[a] == '\t' || \
		nptr[a] == '\v' || nptr[a] == '\f' || nptr[a] == '\r')
		a++;
	if (nptr[a] == '-' || nptr[a] == '+')
	{
		if (nptr[a] == '-')
			b = -1;
		a++;
	}
	while (nptr[a] >= '0' && nptr[a] <= '9')
	{
		rent = (rent * 10) + (nptr[a] - '0');
		a++;
	}
	return (rent * b);
}
