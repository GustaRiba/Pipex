/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorais- <gmorais-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 15:29:16 by gmorais-          #+#    #+#             */
/*   Updated: 2022/11/09 12:13:58 by gmorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*dst;

	dst = (char *)malloc((sizeof(char)) * (ft_strlen(str) + 1));
	if (!dst)
		return (0);
	ft_memcpy(dst, str, ft_strlen(str) + 1);
	return (dst);
}

/*passa o "str" para um espaco alocado de memoria (dst).
usa o ft_memcpy para fzr a copia de str para dst.*/