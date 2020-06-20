/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 12:53:42 by avogt             #+#    #+#             */
/*   Updated: 2018/11/21 13:14:02 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	int len;

	len = 0;
	while (src[len] != '\0')
	{
		dst[len] = src[len];
		len++;
	}
	dst[len] = src[len];
	return (dst);
}
