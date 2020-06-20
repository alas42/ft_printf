/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 11:45:24 by avogt             #+#    #+#             */
/*   Updated: 2018/11/16 13:01:37 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	if (s1 != NULL && s2 != NULL)
	{
		while (*s1 != '\0' && *s2 != '\0')
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
	if (*s1 != *s2)
		return (0);
	return (1);
}
