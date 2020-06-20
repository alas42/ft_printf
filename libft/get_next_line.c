/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <avogt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 18:12:40 by avogt             #+#    #+#             */
/*   Updated: 2019/02/15 14:30:48 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	ft_lenl(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	return (i);
}

static int		ft_read(int fd, char **next)
{
	int		ret;
	char	tmp[BUFF_SIZE + 1];
	char	*t;

	t = NULL;
	ret = 0;
	if (*next != NULL && ft_strchr(*next, '\n') != NULL)
		return (1);
	while ((ret = read(fd, tmp, BUFF_SIZE)) > 0)
	{
		tmp[ret] = '\0';
		t = (*next != NULL) ? ft_strdup(*next) : ft_strdup("");
		if (*next != NULL)
			ft_strdel(next);
		*next = ft_strjoin(t, tmp);
		free(t);
		if (ft_strchr(*next, '\n') != NULL)
			return (1);
	}
	if (ret == -1)
		return (-1);
	return (1);
}

void			reduce_next(char **next)
{
	char		*tmp;

	tmp = ft_strsub(*next, ft_lenl(*next) + 1, ft_strlen(*next)
		- (ft_lenl(*next) + 1));
	ft_strdel(next);
	*next = ft_strdup(tmp);
	ft_strdel(&tmp);
}

int				get_next_line(int fd, char **line)
{
	static char	*next = NULL;

	if (fd < 0 || line == NULL || (ft_read(fd, &next) == -1))
		return (-1);
	if (next)
	{
		*line = (ft_strchr(next, '\n') != NULL)
			? ft_strsub(next, 0, ft_lenl(next)) : ft_strdup(next);
		if (ft_strchr(next, '\n') != NULL)
			reduce_next(&next);
		else
		{
			ft_strdel(&next);
			if (ft_strlen(*line) == 0)
			{
				if (*line)
					free(*line);
				return (0);
			}
		}
		return (1);
	}
	return (0);
}
