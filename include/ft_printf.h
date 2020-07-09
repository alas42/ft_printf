/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <avogt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 16:03:26 by avogt             #+#    #+#             */
/*   Updated: 2020/07/09 19:20:51 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "../libft/libft.h"

typedef struct	s_arg
{
	char		flags[2];
	long int	width;
	long int	prec;
	char		specifier;
	short int	redirector;
}				t_arg;

typedef struct	s_tab
{
	const char	*format;
	char		*f_copy;
	char		*f_copy2;
	va_list		ap;
	int			len;
	size_t		i;
	t_arg		*arg;
}				t_tab;

int				ft_printf(const char *format, ...);
int				parse_fomat(t_tab *tab);
t_tab			*set_arg(t_tab *tab);
int				parse_arg(t_tab *tab);
t_tab			*check_flags(t_tab *tab);
t_tab			*check_field_width(t_tab *tab);
t_tab			*check_precision(t_tab *tab);
t_tab			*check_specifier(t_tab *tab);
t_tab			*handle_d(t_tab *tab);
t_tab			*handle_u(t_tab *tab);
t_tab			*handle_x(t_tab *tab);
t_tab			*handle_c(t_tab *tab);
t_tab			*handle_s(t_tab *tab);
t_tab			*handle_p(t_tab *tab);
t_tab			*handle_percent(t_tab *tab);
t_tab			*redirect(t_tab *tab);
long int		is_min(char *string, t_tab *tab, char *arg, long int pos);
void			display_char(t_tab *tab, char c, int len, int update_len);
#endif
