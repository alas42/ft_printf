/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 16:36:52 by avogt             #+#    #+#             */
/*   Updated: 2020/06/21 15:48:56 by avogt            ###   ########.fr       */
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
	printf("p4 %ds\n fegzf g ygfezgf %s\n", 4, "aaaaa");
	printf("%+*d\n", -5, -50);
	printf("%+-*d\n", 5, -50);
	printf("%-5d\n", -50);
	return (0);
}
