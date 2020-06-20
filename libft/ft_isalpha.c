/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 13:21:05 by avogt             #+#    #+#             */
/*   Updated: 2018/11/16 12:55:47 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isalpha(int c)
{
	int char_c;

	char_c = c;
	if (char_c > 64 && char_c < 91)
		return (1);
	else if (char_c > 96 && char_c < 123)
		return (1);
	return (0);
}
