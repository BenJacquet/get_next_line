/*int		main(int ac, char **av)
{
	int		ret = 0;
	int		i = 0;
	int		fd = 0;
	char	*line;
	
	ac = (int)ac;
	fd = open(av[1], O_RDONLY);
	while ((ret = get_next_line(fd, &line)))
	{
		printf("line %d (%d) = %s\n", i, ret, line);
		free(line);
		i++;
	}
	printf("line %d (%d) = %s\n", i, ret, line);
	free(line);
	system("leaks a.out");
}*/
