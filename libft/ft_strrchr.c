/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 16:58:17 by avogt             #+#    #+#             */
/*   Updated: 2018/11/21 13:16:30 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;
	char	to_find;
	int		counter;

	counter = ft_strlen(s);
	to_find = (char)c;
	ptr = (char *)&s[counter];
	while (counter >= 0)
	{
		if (s[counter] == to_find)
			return (ptr);
		ptr--;
		counter--;
	}
	return (NULL);
}
