/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 14:41:34 by avogt             #+#    #+#             */
/*   Updated: 2019/09/16 16:10:32 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"

size_t	ft_strlcat(char *dst, char *src, size_t size)
{
	size_t	lendest;
	size_t	lensrc;
	size_t	i;

	lensrc = ft_strlen(src);
	lendest = ft_strlen(dst);
	i = 0;
	if (size < lendest)
		return (size + lensrc);
	while (lendest + i < size - 1)
	{
		if (src[i] == '\0')
		{
			dst[lendest + i] = src[i];
			return (lendest + lensrc);
		}
		dst[lendest + i] = src[i];
		i++;
	}
	dst[lendest + i] = '\0';
	return (lendest + lensrc);
}
