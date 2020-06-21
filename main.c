/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 16:36:52 by avogt             #+#    #+#             */
/*   Updated: 2020/06/21 13:46:07 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	char	c;
	int		champ;
	
	champ = 30;
	c = 'l';
	ft_printf("%30c\n", c);
	printf("ft_printf :\n");
	ft_printf("p4 %.5s\n", "aaaaa");
	printf("printf : \n");
	printf("p4 %.5s\n", "aaaaa");
	return (0);
}
