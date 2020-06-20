/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 15:37:01 by avogt             #+#    #+#             */
/*   Updated: 2018/11/21 13:10:38 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t				counter;
	unsigned char		cc;

	cc = (unsigned char)c;
	counter = 0;
	while (counter++ < n)
	{
		*((unsigned char *)dst) = *((const unsigned char *)src);
		if (*((unsigned char *)dst) == cc)
			return (++dst);
		dst++;
		src++;
	}
	return (NULL);
}
