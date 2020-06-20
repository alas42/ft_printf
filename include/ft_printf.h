/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <avogt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 16:03:26 by avogt             #+#    #+#             */
/*   Updated: 2020/06/19 16:16:22 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "../libft/libft.h"

/*
 * Using the same names as the one from tutorialspoint 
 * Flags are 0 - # + ' '
 * Specifiers are csdiouxX
 * Width and precision are self-explanatory
 *  
 * ap is the list of argument
 * len is the number of character that was printed
 * i is the actual position on the virtual cursor as we process what 
 * is stored in format
 */

typedef struct	s_tab
{
	const char  *format;
	char	    *f_copy;
	char	    *f_treat;
	va_list	    ap;
	int		    len;
	size_t	    i;
	char		*specifiers;
	char		*flags;
    t_arg       argument;    
}               t_tab;

typedef struct  s_arg
{
    char		flags[6];
    long int	width;
    long int	precision;
	char		specifier;
}               t_arg;

int		ft_printf(const char *format, ...);
t_tab   set_tab(t_tab *tab);
int     parse_fomat(t_tab *tab);
t_tab   set_arg(t_tab *tab);
int     parse_arg(t_tab *tab);
#endif
