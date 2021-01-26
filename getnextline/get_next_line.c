/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihorcada <ihorcada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 14:19:38 by ihorcada          #+#    #+#             */
/*   Updated: 2020/02/18 18:53:18 by ihorcada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_lane_copied(char **buf_copy, int fd, char **line)
{
	char *temp;

	if (!buf_copy[fd])
	{
		*line = ft_strdup("");
		return (0);
	}
	if (newline_check(buf_copy[fd], '\n'))
	{
		*line = ft_substr(buf_copy[fd], 0, ft_strlen(buf_copy[fd])
			- (ft_strlen(newline_check(buf_copy[fd], '\n'))));
		temp = ft_strdup(newline_check(buf_copy[fd], '\n') + 1);
		free(buf_copy[fd]);
		buf_copy[fd] = temp;
		return (1);
	}
	else
		*line = ft_strdup(buf_copy[fd]);
	free(buf_copy[fd]);
	buf_copy[fd] = NULL;
	return (0);
}

int	get_next_line(int fd, char **line)
{
	char		*buf;
	int			bytes_read;
	static char *buf_copy[4096];
	char		*temp;

	if (line == NULL || fd < 0 || BUFFER_SIZE <= 0 ||
	!(buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1))
	|| read(fd, buf, 0) == -1)
		return (-1);
	while ((bytes_read = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[bytes_read] = '\0';
		if (!buf_copy[fd])
			buf_copy[fd] = ft_strdup(buf);
		else
		{
			temp = ft_strjoin(buf_copy[fd], buf);
			free(buf_copy[fd]);
			buf_copy[fd] = temp;
		}
		if (newline_check(buf, '\n'))
			break ;
	}
	free(buf);
	return (ft_lane_copied(buf_copy, fd, line));
}
