/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabenjam <jabenjam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 12:10:24 by jabenjam          #+#    #+#             */
/*   Updated: 2020/08/09 10:22:44 by jabenjam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char			*get_remain(char *remain)
{
	char		*new;
	int			i;
	int			j;

	i = 0;
	j = 0;
	if (!remain)
		return (0);
	while (remain && remain[i] != '\0' && remain[i] != '\n')
		i++;
	if (remain[i] == '\0')
	{
		free(remain);
		return (0);
	}
	if (!(new = malloc(sizeof(char) * (ft_strlen(remain) - i) + 1)))
		return (0);
	i++;
	while (remain && remain[i] != '\0')
		new[j++] = remain[i++];
	new[j] = '\0';
	free(remain);
	return (new);
}

char			*get_line(char *remain)
{
	int			i;
	char		*new;

	i = 0;
	while (remain && remain[i] != '\0' && remain[i] != '\n')
		i++;
	if (!(new = malloc(sizeof(char) * (i + 1))))
		return (0);
	i = 0;
	while (remain && remain[i] != '\0' && remain[i] != '\n')
	{
		new[i] = remain[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

int				get_next_line(int fd, char **line)
{
	char		buffer[BUFFER_SIZE + 1];
	static char	*remain;
	int			out;

	out = 1;
	if (fd < 0 || !line || BUFFER_SIZE <= 0 || read(fd, buffer, 0) < 0)
		return (-1);
	while (!ft_findn(remain) && out != 0)
	{
		if ((out = read(fd, buffer, BUFFER_SIZE)) == -1)
			return (-1);
		buffer[out] = '\0';
		remain = ft_strjoin(remain, buffer);
	}
	*line = get_line(remain);
	remain = get_remain(remain);
	if (out == 0)
		return (0);
	return (1);
}
