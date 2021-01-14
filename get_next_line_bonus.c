/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 12:43:53 by agirona           #+#    #+#             */
/*   Updated: 2021/01/13 18:08:35 by agirona          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		newline(char **str, char **save)
{
	int		i;
	int		c;

	i = 0;
	c = 0;
	while (*str && str[0][i])
	{
		if (str[0][i] == '\n')
		{
			str[0][i] = '\0';
			i++;
			if ((*save = ft_strdup(str[0] + i, 0)) == NULL)
				return (-1);
			if ((str[0] = ft_strdup(str[0], 1)) == NULL)
				return (-1);
			return (1);
		}
		i++;
	}
	return (0);
}

int		freevar(char **var1, char **var2, int ret)
{
	if (var1 != NULL && *var1 != NULL)
	{
		free(*var1);
		*var1 = NULL;
	}
	if (var2 != NULL && *var2 != NULL)
	{
		free(*var2);
		*var2 = NULL;
	}
	return (ret);
}

int		get_next_line(int fd, char **line)
{
	int				ret;
	char			*buff;
	static char		*save[OPEN_MAX] = {NULL};

	ret = -1;
	*line = NULL;
	if (fd < 0 || (buff = malloc(sizeof(char) * BUFFER_SIZE + 1)) == NULL)
		return (freevar(&save[fd], NULL, -1));
	if (save[fd] && (line[0] = ft_strdup(save[fd], 0)) == NULL)
		return (freevar(&buff, &save[fd], -1));
	else if (save[fd])
		freevar(&save[fd], NULL, 0);
	while (ret != 0 && (ret = newline(line, &save[fd])) == 0)
	{
		ret = read(fd, buff, BUFFER_SIZE);
		if (ret < 0)
			return (freevar(&buff, &save[fd], -1));
		buff[ret] = '\0';
		if ((line[0] = ft_strjoin(line[0], buff)) == NULL)
			return (-1);
	}
	if (save[fd] && ret != -1)
		return (freevar(&buff, NULL, 1));
	return (freevar(&save[fd], &buff, ret));
}
