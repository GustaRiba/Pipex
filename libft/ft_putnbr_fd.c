/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorais- <gmorais-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 11:19:25 by gmorais-          #+#    #+#             */
/*   Updated: 2022/11/09 11:35:59 by gmorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n >= INT_MIN && n <= __INT_MAX__)
	{
		if (n >= 10)
		{
			ft_putnbr_fd(n / 10, fd);
			ft_putnbr_fd((n % 10), fd);
		}
		else if (n == -2147483648)
		{
			write(fd, "-", 1);
			write(fd, "2", 1);
			write(fd, "147483648", 9);
		}
		else if (n < 0)
		{
			n = -n;
			write(fd, "-", 1);
			ft_putnbr_fd(n, fd);
		}
		else
		{
			n = n + 48;
			write(fd, &n, 1);
		}
	}
}

/*escreve o numero que pedimos.*/