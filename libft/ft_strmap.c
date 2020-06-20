/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 18:04:29 by avogt             #+#    #+#             */
/*   Updated: 2018/11/16 18:28:28 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*fresh;
	size_t	len;
	char	*ptr;

	if (s != NULL && f != NULL)
	{
		len = ft_strlen(s);
		if (!(fresh = (char *)malloc(sizeof(char) * len + 1)))
			return (NULL);
		ptr = fresh;
		while (*s != '\0')
		{
			*(fresh++) = f(*s);
			s++;
		}
	}
	else
		return (NULL);
	*fresh = '\0';
	fresh = ptr;
	return (fresh);
}
