/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 17:39:08 by avogt             #+#    #+#             */
/*   Updated: 2018/11/16 18:28:16 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	size_t	i;
	char	*new_str;

	new_str = NULL;
	i = 0;
	if (!(new_str = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	while (i <= size)
		new_str[i++] = '\0';
	return (new_str);
}
