/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 11:55:38 by avogt             #+#    #+#             */
/*   Updated: 2018/12/07 17:00:48 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*fresh;
	unsigned int	i;

	fresh = NULL;
	if (s == NULL)
		return (fresh);
	if (!(fresh = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (i < len)
		fresh[i++] = s[start++];
	fresh[i] = '\0';
	return (fresh);
}
