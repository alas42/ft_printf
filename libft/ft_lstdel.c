/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 18:01:56 by avogt             #+#    #+#             */
/*   Updated: 2018/11/16 13:03:58 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *ptr;

	ptr = NULL;
	while (*alst)
	{
		del((*alst)->content, (*alst)->content_size);
		ptr = *alst;
		*alst = (*alst)->next;
		free(ptr);
	}
	*alst = NULL;
}
