/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 12:15:37 by agirona           #+#    #+#             */
/*   Updated: 2020/12/17 18:16:59 by agirona          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_putnbr(int n);
void	ft_putchar(char c);
void	ft_putstr(char *str);
#include <malloc/malloc.h>

int		ft_strlen(const char *str)
{
	int		i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		c;
	char	*res;

	i = 0;
	c = 0;
	res = NULL;
	if (!s1 && !s2)
		return (NULL);
	if (!(res = (char *)malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1)))
	{
		free((char *)s2);
		return (NULL);
	}
	res[0] = '\0';
	while (s1 && s1[c])
		res[i++] = s1[c++];
	c = 0;
	while (s2 && s2[c])
		res[i++] = s2[c++];
	res[i] = '\0';
	free((char *)s1);
	return (res);
}

char	*ft_strdup(const char *s1, int leaks)
{
	char	*str;
	int		i;

	i = 0;
	str = NULL;
	if ((str = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1)) == NULL)
	{
		if (leaks == 1)
			free((char *)s1);
		return (NULL);
	}
	str[0] = '\0';
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	if (leaks == 1)
	{
		free((char *)s1);
		s1 = NULL;
	}
	return (str);
}
