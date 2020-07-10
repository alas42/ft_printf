/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 16:36:52 by avogt             #+#    #+#             */
/*   Updated: 2020/07/09 18:07:26 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	char			*s;
	char			c;
	unsigned int	test;
	int 			champ;
	int 			precision;

	s = (char *)malloc(sizeof(char) * (20 + 1));
	s = ft_strdup("Hello World, test!");
	champ = 10;
	precision = 5;
	test = 30;
	c = 'l';
	ft_putnbr(ft_printf("%*s\n", -10, "Hello"));
	ft_putnbr(printf("%*s\n", -10, "Hello"));
	ft_putnbr(ft_printf("%u\n", test));
	ft_putnbr(printf("%u\n", test));
	ft_putnbr(ft_printf("%5u\n", test));
	ft_putnbr(printf("%5u\n", test));
	ft_putnbr(ft_printf("%.5u\n", test));
	ft_putnbr(printf("%.5u\n", test));
	ft_putnbr(ft_printf("%-5u\n", test));
	ft_putnbr(printf("%-5u\n", test));
	ft_putnbr(ft_printf("%05u\n", test));
	ft_putnbr(printf("%05u\n", test));
	
	ft_putnbr(ft_printf("%x\n", test));
	ft_putnbr(printf("%x\n", test));
	ft_putnbr(ft_printf("%5x\n", test));
	ft_putnbr(printf("%5x\n", test));
	ft_putnbr(ft_printf("%.5x\n", test));
	ft_putnbr(printf("%.5x\n", test));
	ft_putnbr(ft_printf("%-5x\n", test));
	ft_putnbr(printf("%-5x\n", test));
	ft_putnbr(ft_printf("%05x\n", test));
	ft_putnbr(printf("%05x\n", test));

	ft_putnbr(ft_printf("%X\n", test));
	ft_putnbr(printf("%X\n", test));
	ft_putnbr(ft_printf("%5X\n", test));
	ft_putnbr(printf("%5X\n", test));
	ft_putnbr(ft_printf("%.5X\n", test));
	ft_putnbr(printf("%.5X\n", test));
	ft_putnbr(ft_printf("%-5X\n", test));
	ft_putnbr(printf("%-5X\n", test));
	ft_putnbr(ft_printf("%05X\n", test));
	ft_putnbr(printf("%05X\n", test));

	ft_putnbr(ft_printf("%c\n", c));
	ft_putnbr(printf("%c\n", c));
	ft_putnbr(ft_printf("%5c\n", c));
	ft_putnbr(printf("%5c\n", c));
	ft_putnbr(ft_printf("%-5c\n", c));
	ft_putnbr(printf("%-5c\n", c));
	ft_putnbr(ft_printf("%-5c 0\n", c));
	ft_putnbr(printf("%-5c 0\n", c));
	ft_putnbr(ft_printf("%5c 45\n", c));
	ft_putnbr(printf("%5c 45\n", c));

	ft_putnbr(ft_printf("%s\n", s));
	ft_putnbr(printf("%s\n", s));
	ft_putnbr(ft_printf("%5s\n", s));
	ft_putnbr(printf("%5s\n", s));
	ft_putnbr(ft_printf("%-5s\n", s));
	ft_putnbr(printf("%-5s\n", s));
	ft_putnbr(ft_printf("%-s 0\n", s));
	ft_putnbr(printf("%-s 0\n", s));
	ft_putnbr(ft_printf("%.5s 45\n", s));
	ft_putnbr(printf("%.5s 45\n", s));
	
	ft_putnbr(ft_printf("%d\n", -333));
	ft_putnbr(printf("%d\n", -333));
	ft_putnbr(ft_printf("%5d\n", -333));
	ft_putnbr(printf("%5d\n", -333));
	ft_putnbr(ft_printf("%10.5d\n", -333));
	ft_putnbr(printf("%10.5d\n", -333));
	ft_putnbr(ft_printf("%-40.5d 0\n", -333));
	ft_putnbr(printf("%-40.5d 0\n", -333));
	ft_putnbr(ft_printf("%-.10d 45\n", -333));
	ft_putnbr(printf("%-.10d 45\n", -333));

	ft_putnbr(ft_printf("%p\n", &test));
	ft_putnbr(printf("%p\n", &test));
	ft_putnbr(ft_printf("%5p\n", &test));
	ft_putnbr(printf("%5p\n", &test));
	ft_putnbr(ft_printf("%-5p\n", &test));
	ft_putnbr(printf("%-5p\n", &test));
	ft_putnbr(ft_printf("%-p 0\n", &test));
	ft_putnbr(printf("%-p 0\n", &test));
	ft_putnbr(ft_printf("%45p 45\n", &test));
	ft_putnbr(printf("%45p 45\n", &test));
	free(s);
	system("leaks a.out");
	return (0);
}
