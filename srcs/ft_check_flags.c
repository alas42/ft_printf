/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <avogt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 14:26:25 by avogt             #+#    #+#             */
/*   Updated: 2020/05/11 12:56:28 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_attribut(int *flags, char *s, int *i)
{
	int	c;

	c = -1;
	while (++c <= 1)
		flags[c] = 0;
	while (s[*i] != '\0' && (s[*i] == '-' || s[*i] == '0'))
	{
		if (s[*i] == '-')
			flags[0] = 1;
		else if (s[*i] == '0')
			flags[1] = 1;
		*i += 1;
	}
}

int		check_champ(char *s, int *i)
{
	unsigned int	start;
	int				lengthchamp;
	int				champ;
	char			*new;
	char			*tmp;

	start = *i;
	tmp = ft_strsub(s, start, ft_strlen(s) - *i);
	champ = 0;
	lengthchamp = 0;
	champ = ft_atoi(tmp);
	new = ft_itoa(champ);
	lengthchamp = (champ == 0) ? 0 : ft_strlen(new);
	*i += lengthchamp;
	ft_strdel(&tmp);
	ft_strdel(&new);
	return (champ);
}

int		check_precision(char *s, int *i)
{
	unsigned int	start;
	unsigned int	length;
	char			*new;
	char			*tmp;
	int				precision;

	precision = 0;
	start = 0;
	length = 0;
	if (s[*i] == '.')
	{
		*i += 1;
		start = *i;
		tmp = ft_strsub(s, start, ft_strlen(s) - *i);
		precision = ft_atoi(tmp);
		new = ft_itoa(precision);
		length = ft_strlen(new);
		*i += length;
		ft_strdel(&tmp);
		ft_strdel(&new);
		precision = (precision < 0) ? 0 : precision;
		return (precision);
	}
	return (-1);
}

int		check_conversion(char *s, int *i)
{
	static char	type[] = "cspdiuxX\0";
	int			c;

	c = -1;
	if (s[*i] == 'd' || s[*i] == 'i' || s[*i] == 'u'
		|| s[*i] == 'x' || s[*i] == 'c' || s[*i] == 'X'
		|| s[*i] == 's' || s[*i] == 'p')
	{
		*i += 1;
		while (type[++c] != '\0')
			if (s[*i - 1] == type[c])
				return (c);
	}
	return (-1);
}
