/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 12:45:28 by agirona           #+#    #+#             */
/*   Updated: 2020/12/15 18:09:28 by agirona          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdlib.h>

int		get_next_line(int fd, char **line);
int		ft_strlen(const char *str);
char	*clear(char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s1, int leaks);

#endif
