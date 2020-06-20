/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 12:49:20 by avogt             #+#    #+#             */
/*   Updated: 2018/11/16 18:31:48 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_lstpushback(t_list **lst, t_list *elem)
{
	while (*lst)
		lst = &(*lst)->next;
	*lst = elem;
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_lst;
	t_list	*piece;

	piece = NULL;
	new_lst = NULL;
	while (lst)
	{
		piece = f(lst);
		if (piece != NULL)
			ft_lstpushback(&new_lst, piece);
		else
			return (NULL);
		lst = lst->next;
	}
	return (new_lst);
}
