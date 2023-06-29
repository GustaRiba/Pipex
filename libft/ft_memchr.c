/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorais- <gmorais-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:48:57 by gmorais-          #+#    #+#             */
/*   Updated: 2022/11/09 12:10:56 by gmorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t len)
{
	unsigned char	*s2;
	unsigned char	b;
	size_t			i;

	i = 0;
	s2 = (unsigned char *)s;
	b = (unsigned char)c;
	while (i < len && s2[i] != b)
		i++;
	if (i < len && s2[i] == b)
		return (&s2[i]);
	return (NULL);
}

/*procura dentro do "*s" o "c".
se encontrar, returna o "*s" comecando no "c".
len define por quantos caracteres percorrer*/