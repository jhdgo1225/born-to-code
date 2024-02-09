/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghopa <jonghopa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 12:59:14 by jonghopa          #+#    #+#             */
/*   Updated: 2023/07/16 15:13:11 by jonghopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

ssize_t	read_buf(int fd, char **backup)
{
	char	buf[BUFFER_SIZE + 1];
	char	*temp;
	int		read_chk;

	read_chk = read(fd, buf, BUFFER_SIZE);
	if (read_chk == -1)
	{
		free(*backup);
		*backup = 0;
		return (-1);
	}
	if (read_chk == 0)
		return (0);
	buf[read_chk] = 0;
	temp = gnl_strjoin(*backup, buf);
	if (temp == 0)
	{
		free(*backup);
		*backup = 0;
		return (-1);
	}
	free(*backup);
	*backup = temp;
	return (read_chk);
}

int	is_newline(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		if (str[len++] == '\n')
			return (1);
	return (0);
}

int	backup_update(char **backup)
{
	char	*new_chk;
	size_t	backup_len;
	size_t	update_len;
	char	*temp;

	backup_len = gnl_strlen(*backup);
	new_chk = gnl_strchr(*backup, '\n');
	if (new_chk == 0)
	{
		free(*backup);
		*backup = 0;
	}
	else
	{
		update_len = backup_len - (new_chk - *backup + 1);
		temp = gnl_strndup(new_chk + 1, update_len);
		if (temp == 0)
			return (1);
		free(*backup);
		*backup = 0;
		*backup = temp;
	}
	return (0);
}

char	*get_text(char **backup)
{
	char	*text;
	char	*new;
	int		len;
	int		check;

	new = gnl_strchr(*backup, '\n');
	if (new == 0)
	{
		len = gnl_strlen(*backup);
		if (len == 0)
		{
			free(*backup);
			*backup = 0;
			return (0);
		}
	}
	else
		len = new - *backup + 1;
	text = gnl_strndup(*backup, len);
	if (text == 0)
		return (0);
	check = backup_update(backup);
	if (check)
		return (0);
	return (text);
}

char	*get_next_line(int fd)
{
	static char	*backup;
	char		*text;
	int			read_chk;

	if (BUFFER_SIZE <= 0)
		return (0);
	if (backup == 0)
	{
		backup = (char *)malloc(1);
		if (backup == 0)
			return (0);
		backup[0] = '\0';
	}
	while (is_newline(backup) == 0)
	{
		read_chk = read_buf(fd, &backup);
		if (read_chk == -1 || (read_chk == 0 && backup == 0))
			return (0);
		if (read_chk == 0 && backup != 0)
			break ;
	}
	text = get_text(&backup);
	if (text == 0)
		return (0);
	return (text);
}
