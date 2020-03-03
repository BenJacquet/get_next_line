/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabenjam <jabenjam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 14:45:32 by jabenjam          #+#    #+#             */
/*   Updated: 2020/03/03 11:59:19 by jabenjam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>

typedef struct		s_list
{
	int				fd;
	char			*rem;
	struct s_list	*next;
}					t_list;

size_t				ft_strlenc(char *str, char c);
char				*ft_strcpy(char *dest, char *src);
char				*ft_strjoin(char *s1, char *s2);
char				*ft_substr(char *s, unsigned int start, size_t len);
int					ft_findc(char *s, int c);
int					get_next_line(int fd, char **line);
int					get_line(char **line, t_list *dat);
static t_list		*get_file(t_list *dat, int fd);
void				del_list(t_list **begin);
static t_list		*new_file(int fd);

#endif

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 4096
#endif
