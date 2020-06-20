/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:06:47 by avogt             #+#    #+#             */
/*   Updated: 2018/11/21 13:17:06 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	j;
	size_t	x;
	size_t	needle_len;
	size_t	haystack_len;

	needle_len = ft_strlen(needle);
	if (!needle || needle_len == 0)
		return ((char *)haystack);
	haystack_len = ft_strlen(haystack);
	i = -1;
	while (++i < haystack_len)
	{
		j = 0;
		x = 0;
		while (j < needle_len && i + j < haystack_len)
		{
			if (haystack[i + j] == needle[j])
				x++;
			j++;
		}
		if (x == needle_len)
			return ((char *)&haystack[i]);
	}
	return (NULL);
}
