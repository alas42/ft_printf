/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 11:48:11 by avogt             #+#    #+#             */
/*   Updated: 2018/11/16 13:01:42 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (s1 != NULL && s2 != NULL)
	{
		while (*s1 != '\0' && *s2 != '\0' && i++ < n)
		{
			if (*s1 != *s2)
				return (0);
			s1++;
			s2++;
		}
	}
	else if (s1 == NULL && s2 == NULL)
		return (1);
	else
		return (0);
	if (*s1 != *s2 && i < n)
		return (0);
	return (1);
}
