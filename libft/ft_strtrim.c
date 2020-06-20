/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 12:23:42 by avogt             #+#    #+#             */
/*   Updated: 2018/11/16 18:33:59 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_lenni(char const *s, unsigned int *i, size_t *len)
{
	while (s[*i] == ' ' || s[*i] == '\t' || s[*i] == '\n')
		(*i)++;
	while (s[*len - 1] == ' ' || s[*len - 1] == '\t' || s[*len - 1] == '\n')
		(*len)--;
}

char		*ft_strtrim(char const *s)
{
	char			*fresh;
	size_t			len;
	unsigned int	i;
	unsigned int	counter;

	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	i = 0;
	counter = 0;
	ft_lenni(s, &i, &len);
	if (i > len)
	{
		if (!(fresh = (char *)malloc(sizeof(char) * (1))))
			return (NULL);
	}
	else
	{
		if (!(fresh = (char *)malloc(sizeof(char) * (len - i + 1))))
			return (NULL);
	}
	while (i < len)
		fresh[counter++] = s[i++];
	fresh[counter] = '\0';
	return (fresh);
}
