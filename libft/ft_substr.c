/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorais- <gmorais-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 12:49:44 by gmorais-          #+#    #+#             */
/*   Updated: 2022/11/09 16:50:15 by gmorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	char	*prt;

	s_len = ft_strlen(s);
	if (start > s_len)
	{
		prt = malloc(sizeof(char));
		*prt = 0;
		return (prt);
	}
	if (len >= s_len)
		len = s_len - start;
	prt = malloc(len + 1);
	if (!prt)
		return (NULL);
	prt[len] = '\0';
	return (ft_memcpy(prt, s + start, len));
}

/*vai se dar um separador e a funcao vai eliminar td
ate ao primeiro separador e td o q esta para a
frente do segundo
ex: s1 = www.google.com, set = '.'
res: google*/