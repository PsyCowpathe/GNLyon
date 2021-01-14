/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ugly_gnl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 18:42:26 by agirona           #+#    #+#             */
/*   Updated: 2020/12/11 18:42:38 by agirona          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int		get_next_line(int fd, char **line)
{
	static char		*save = NULL;
	char			*str;
	char			*tmp;
	int				ret;
	int				stop;

	int		i;
	i = 0;

	ret = 0;
	stop = 1;
	str = NULL;
	tmp = NULL;
	if (fd < 0 || (tmp = malloc(sizeof(char) * BUFFER_SIZE + 1)) == NULL)
		return (-1);
	tmp = clear(tmp);
	if (save)
	{
		*line = ft_strdup(save);
		save = clear(save);
		free(save);
		save = NULL;
	}
	while (stop == 1 && ((ret = read(fd, tmp, BUFFER_SIZE)) > 0))
	{
		tmp[ret] = '\0';
		if (*line)
			str = ft_strdup(*line);
		*line = ft_strjoin(str, tmp);
		tmp = clear(tmp);
		str = clear(str);
		if (newline(line, &save) == 1)
		{
			stop = 0;
		}
		if (newline(line, &save) == -1)
			return (-1);
	}
	if (ret == -1)
		return (-1);
	if (ret == 0 && !*line)
	{

		*line = malloc(sizeof(char) * 1);
		*line[0] = '\0';
		if (save)
			free(save);
		free(str);
		return (0);
	}
	if (ret == 0)
	{
		newline(line, &save);
		if (!save)
			return (0);
	}
	return (1);
}
