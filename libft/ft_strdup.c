/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 12:18:25 by avogt             #+#    #+#             */
/*   Updated: 2018/11/21 13:13:11 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*cpy;

	len = ft_strlen(s1);
	if (!(cpy = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	len = 0;
	while (s1[len] != '\0')
	{
		cpy[len] = s1[len];
		len++;
	}
	cpy[len] = '\0';
	return (cpy);
}
