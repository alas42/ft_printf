/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 18:09:39 by avogt             #+#    #+#             */
/*   Updated: 2018/11/21 13:17:30 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned char c1;
	unsigned char c2;

	c1 = (unsigned char)*s1;
	c2 = (unsigned char)*s2;
	while (*s1 != '\0' && *s2 != '\0')
	{
		if (c1 != c2)
			return (c1 - c2);
		++s1;
		++s2;
		c1 = (unsigned char)*s1;
		c2 = (unsigned char)*s2;
	}
	return (c1 - c2);
}
