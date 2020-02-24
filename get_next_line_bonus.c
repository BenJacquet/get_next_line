/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabenjam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 15:15:20 by jabenjam          #+#    #+#             */
/*   Updated: 2019/11/02 16:09:58 by jabenjam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

static t_list		*new_file(int fd)
{
	static t_list		*file;
	char				*buf[BUFFER_SIZE + 1];

	if (read(fd, buf, O_RDONLY) < 0)
		return (NULL);
	if (!(file = (t_list*)malloc(sizeof(*file))))
		return (NULL);
	file->fd = fd;
	if (!(file->rem = (char*)malloc(sizeof(file->rem))))
		return (NULL);
	file->rem[0] = '\0';
	file->next = NULL;
	return (file);
}

void		del_list(t_list **begin)
{
	t_list		*current;
	t_list		*previous;

	current = *begin;
	previous = *begin;
	if (!begin)
		return ;
	while (current)
	{
		previous = current;
		free(previous->rem);
		free(previous);
		current = current->next;
	}
}

static t_list		*get_file(t_list *dat, int fd)
{
	if (!dat)
	{
		dat = new_file(fd);
		return (dat);
	}
	while (dat)
	{
		if (dat->fd == fd)
			return (dat);
		if (dat->next == NULL)
		{
			dat->next = new_file(fd);
			return (dat->next);
		}
		dat = dat->next;
	}
	dat = new_file(fd);
	return (dat);
}

int			get_line(char **line, t_list *dat)
{
	int				i;
	char			*tmp;

	i = ft_strlenc(dat->rem, '\n');
	tmp = dat->rem;
	if (!(*line = ft_substr(dat->rem, 0, i)))
		return (-1);
	if (dat->rem[i] == '\n')
		ft_strcpy(dat->rem, dat->rem + i + 1);
	else
		dat->rem[0] = '\0';
	return (1);
}

int			get_next_line(int fd, char **line)
{
	char			buff[BUFFER_SIZE + 1];
	int				out;
	static t_list	*dat;
	char 			*tmp;

	if (!fd || !line || BUFFER_SIZE <= 0 ||
			(out = read(fd, buff, 0) < 0), !(dat = get_file(dat, fd)))
		return (-1);
	while ((!ft_findc(dat->rem, '\n')) &&
			(out = read(fd, buff, BUFFER_SIZE > 0)))
	{
		buff[out] = '\0';
		tmp = dat->rem;
		if (!(dat->rem = ft_strjoin(dat->rem, buff)))
			return (-1);
		free(tmp);
	}
	if (out < 0 || (!out && dat->rem[0] == '\0'))
	{
		del_list(&dat);
		return (out);
	}
	else
		return (get_line(line, dat));
}

int				main(int ac, char **av)
{
	char 		*line;
	int			fd1;
	int			fd2;

	fd1 = open(av[1], O_RDONLY);
//	fd2 = open(av[2], O_RDONLY);
	while (get_next_line(fd1, &line))
	{
			printf("%s\n", line);
			free(line);
	}
}
