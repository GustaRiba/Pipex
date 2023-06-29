/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorais- <gmorais-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:03:15 by gmorais-          #+#    #+#             */
/*   Updated: 2022/11/09 12:32:41 by gmorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_size;
	size_t	src_size;
	size_t	b;
	size_t	i;

	dst_size = ft_strlen(dst);
	src_size = ft_strlen(src);
	b = dst_size;
	i = 0;
	if (size == 0 || size <= b)
		return (src_size + size);
	while (src[i] && (i < (size - dst_size - 1)))
	{
		dst[b] = src[i];
		b++;
		i++;
	}
	dst[b] = '\0';
	return (dst_size + src_size);
}
/*une "dst" com "src".
retorna o tamanho final da uniao das stings.*/