/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 12:43:53 by agirona           #+#    #+#             */
/*   Updated: 2020/12/17 18:56:46 by agirona          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		newline(char **str, char **save)
{
	int		i;
	int		c;
	(void)save;

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
	if (var1)
	{
		free(*var1);
		*var1 = NULL;
	}
	if (var2)
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
	static char		*save = NULL;

	ret = -1;
	if (fd < 0 || (buff = malloc(sizeof(char) * BUFFER_SIZE + 1)) == NULL)
		return (freevar(&save, NULL, -1));
	if (save)
	{
		if ((line[0] = ft_strdup(save, 0)) == NULL)
			return (freevar(&buff, &save, -1));
		freevar(&save, NULL, 0);
	}
	while (ret != 0 && (ret = newline(line, &save)) == 0)
	{
		ret = read(fd, buff, BUFFER_SIZE);
		if (ret < 0)
			return (freevar(&buff, &save, -1));
		buff[ret] = '\0';
		if ((line[0] = ft_strjoin(line[0], buff)) == NULL)
			return (-1);
	}
	if (save && ret != -1)
		return (freevar(&buff, NULL, 1));
	return (freevar(&save, &buff, ret));
}
