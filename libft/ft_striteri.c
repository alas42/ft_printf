/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 18:01:15 by avogt             #+#    #+#             */
/*   Updated: 2018/11/16 13:00:56 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t index;

	index = 0;
	if (s != NULL && f != NULL)
	{
		while (*s != '\0')
		{
			f(index++, &(*s));
			s++;
		}
	}
}
