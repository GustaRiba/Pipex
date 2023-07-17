/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorais- <gmorais-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 10:57:28 by gmorais-          #+#    #+#             */
/*   Updated: 2023/07/12 16:30:00 by gmorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	wordcount(char const *str, char separ)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	if (!str)
		return (i);
	while (*str)
	{
		if (*str != separ && flag == 0)
		{
			flag = 1;
			i++;
		}
		else if (*str == separ)
			flag = 0;
		str++;
	}
	return (i);
}

/*conta o numero de palavras.
sempre q encontra 2 separadores seguidos
ignora e avanca na string*/

static int	ft_size_word(char const *s, char c, int i)
{
	int	size;

	size = 0;
	while (s[i] != c && s[i])
	{
		size++;
		i++;
	}
	return (size);
}

/*vai escrever para dentro da memoria alocada
a nova palavra*/

char	**ft_split(char const *s, char c)
{
	int		i;
	int		wordsize;
	char	**newstr;
	int		j;
	int		strsize;

	i = 0;
	j = -1;
	wordsize = wordcount(s, c);
	newstr = malloc((wordsize + 1) * sizeof(char *));
	if (!newstr)
		return (NULL);
	while (++j < wordsize)
	{
		while (s[i] == c)
			i++;
		strsize = ft_size_word(s, c, i);
		newstr[j] = ft_substr(s, i, strsize);
		i += strsize;
	}
	newstr[j] = NULL;
	return (newstr);
}

/*ptr vai estar a alocar mem para tds as string
que vao existir*/