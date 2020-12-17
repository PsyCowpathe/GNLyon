/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 12:43:53 by agirona           #+#    #+#             */
/*   Updated: 2020/12/17 18:47:52 by agirona          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <unistd.h>
#include <fcntl.h>
#include <malloc/malloc.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		ft_putchar(str[i++]);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		ft_putchar('-');
		ft_putnbr(214748364);
		ft_putchar(8 + 48);
	}
	else if (nb < 0)
	{
		ft_putchar('-');
		ft_putnbr(nb * -1);
	}
	else if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putchar(nb % 10 + 48);
	}
	else
		ft_putchar(nb + 48);
}

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

/*int		ft_main(int argc, char	**argv)
{
	char	*res;
	int		fd;
	int		ret;
	(void)argc;
	(void)argv;

	res = NULL;
	ret = 1;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		while (1)
		{
			ret = get_next_line(fd, &res);
			if (ret == -1)
			{
				free(res);
				ft_putstr("error");
				return (0);
			}
			if (ret == 0)
			{
				free(res);
				res = NULL;
				return (1);
			}
			ft_putstr(res);
			free(res);
			res = NULL;
		}
	}
	else
		ft_putstr("usage ./a.out file");
	free(res);
	return (1);
}

int		main(int argc, char **argv)
{
	ft_main(argc, argv);
}*/
