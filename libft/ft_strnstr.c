/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:25:20 by avogt             #+#    #+#             */
/*   Updated: 2018/11/16 13:31:01 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needle_len;
	size_t	i;
	size_t	j;
	size_t	x;

	needle_len = ft_strlen(needle);
	if (!needle || needle_len == 0)
		return ((char *)haystack);
	i = -1;
	while (++i < len)
	{
		j = 0;
		x = 0;
		while (j < needle_len && i + j < len)
		{
			if (i + j > len || haystack[i + j] == '\0')
				return (NULL);
			if (haystack[i + j] == needle[j])
				x++;
			j++;
		}
		if (x == needle_len)
			return ((char *)&haystack[i]);
	}
	return (NULL);
}
