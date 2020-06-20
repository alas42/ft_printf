/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 13:01:28 by avogt             #+#    #+#             */
/*   Updated: 2018/11/21 13:14:37 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	counter;
	size_t	lensrc;

	lensrc = ft_strlen(src);
	counter = 0;
	while (counter < len)
	{
		if (counter > lensrc)
			dst[counter] = '\0';
		else
			dst[counter] = src[counter];
		counter++;
	}
	return (dst);
}
