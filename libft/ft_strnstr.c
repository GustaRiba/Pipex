/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorais- <gmorais-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 14:42:04 by gmorais-          #+#    #+#             */
/*   Updated: 2022/10/28 15:03:35 by gmorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	b;
	size_t	a;

	b = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[b] != '\0')
	{
		a = 0;
		while (big[b + a] == little[a] && (b + a) < len)
		{
			if (big[b + a] == '\0' && little[a] == '\0')
				return ((char *)&big[b]);
			a++;
		}
		if (little[a] == '\0')
			return ((char *)big + b);
		b++;
	}
	return (0);
}
