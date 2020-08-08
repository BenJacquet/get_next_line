/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabenjam <jabenjam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 16:41:05 by jabenjam          #+#    #+#             */
/*   Updated: 2020/08/08 16:41:06 by jabenjam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "get_next_line.c"
#include "get_next_line_utils.c"


int		main(int ac, char **av)
{
	int		ret = 0;
	int		i = 0;
	int		fd = 0;
	char	*line;
	
	ac = (int)ac;
	fd = open(av[1], O_RDONLY);
	while ((ret = get_next_line(fd, &line) > 0))
	{
		printf("line %d (%d) = %s\n", i, ret, line);
		free(line);
		i++;
	}
	printf("line %d (%d) = %s\n", i, ret, line);
	free(line);
	system("leaks a.out");
}
