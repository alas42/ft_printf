/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 14:31:42 by avogt             #+#    #+#             */
/*   Updated: 2019/09/16 16:11:13 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, char *s2, size_t n)
{
	size_t	lendest;
	size_t	i;

	lendest = ft_strlen(s1);
	i = 0;
	while (s2[i] != '\0' && i < n)
	{
		s1[lendest + i] = s2[i];
		i++;
	}
	s1[lendest + i] = '\0';
	return (s1);
}
