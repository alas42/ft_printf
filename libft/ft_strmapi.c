/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 11:44:37 by avogt             #+#    #+#             */
/*   Updated: 2018/11/16 18:28:35 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*fresh;
	size_t			len;
	unsigned int	i;
	char			*ptr;

	i = 0;
	if (s != NULL && f != NULL)
	{
		len = ft_strlen(s);
		if (!(fresh = (char *)malloc(sizeof(char) * len + 1)))
			return (NULL);
		ptr = fresh;
		while (*s != '\0')
		{
			*fresh++ = f(i++, *s);
			s++;
		}
	}
	else
		return (NULL);
	*fresh = '\0';
	fresh = ptr;
	return (fresh);
}
