/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorais- <gmorais-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:28:56 by gmorais-          #+#    #+#             */
/*   Updated: 2022/11/09 10:41:25 by gmorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*lst1;

	if (!lst || !*lst)
		return ;
	while (*lst)
	{
		lst1 = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = lst1;
	}
	lst = 0;
}
