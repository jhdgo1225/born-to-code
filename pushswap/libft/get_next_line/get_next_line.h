/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghopa <jonghopa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 13:00:18 by jonghopa          #+#    #+#             */
/*   Updated: 2023/07/16 15:14:32 by jonghopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

int		is_newline(const char *str);
char	*get_next_line(int fd);
char	*get_text(char **backup);
ssize_t	read_buf(int fd, char **backup);
int		backup_update(char **backup);
size_t	gnl_strlen(const char *str);
char	*gnl_strchr(const char *str, int c);
char	*gnl_strndup(const char *str, size_t size);
char	*gnl_strjoin(const char *s1, const char *s2);

#endif
