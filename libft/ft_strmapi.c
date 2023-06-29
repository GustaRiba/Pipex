/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorais- <gmorais-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:11:09 by gmorais-          #+#    #+#             */
/*   Updated: 2022/11/09 12:53:03 by gmorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*dst;
	int		i;

	if (!s || !f)
		return (0);
	i = 0;
	dst = ft_strdup(s);
	if (!dst)
		return (0);
	while (dst[i])
	{
		dst[i] = f(i, dst[i]);
		i++;
	}
	return (dst);
}

/*aplica a funcao "f" em todos os carteres da string.
e adicona a string num espaco de memoria alocado.
chamo a funcao strdup para alocar memoria.*/