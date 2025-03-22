/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gel-mejd <gel-mejd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 02:04:27 by gel-mejd          #+#    #+#             */
/*   Updated: 2025/03/17 02:05:09 by gel-mejd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	check_new_line(char *buffer)
{
	if (!buffer)
		return (1);
	while (*buffer)
	{
		if (*buffer == '\n')
			return (0);
		buffer++;
	}
	return (1);
}

char	*ft_get_line(char *buffer)
{
	int		i;
	char	*line;

	i = 0;
	if (!buffer)
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	i = ft_strcpy(line, buffer);
	line[i - 1] = '\0';
	if (i == 0)
	{
		free(line);
		line = NULL;
	}
	return (line);
}

char	*next_line(char *buffer)
{
	int		i;
	int		j;
	char	*next;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\0')
		return (free(buffer), buffer = NULL, NULL);
	if (buffer[i] == '\n')
		i++;
	next = malloc(ft_strlen(buffer) - i + 1);//
	if (!next)
		return (free(buffer), buffer = NULL, NULL);
	j = 0;
	while (buffer[i])
		next[j++] = buffer[i++];
	next[j] = '\0';
	return (free(buffer), buffer = NULL, next);
}

char	*ft_read(char *buffer, int fd)
{
	int		x;
	char	*bs;
	char	*tmp;

	x = 1;
	bs = malloc(BUFFER_SIZE + 1);
	if (!bs)
		return (free(buffer), buffer = NULL, NULL);
	while (check_new_line(buffer) && x != 0)
	{
		x = read(fd, bs, BUFFER_SIZE);
		if (x == -1)
			return (free(bs), free(buffer), buffer = NULL, NULL);
		bs[x] = '\0';
		tmp = buffer;
		buffer = ft_strjoin(buffer, bs);
		free(tmp);
	}
	free(bs);
	return (buffer);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (free(buffer), buffer = NULL, NULL);
	buffer = ft_read(buffer, fd);
	line = ft_get_line(buffer);
	if (!line)
		return (free(line), free(buffer), buffer = NULL, NULL);
	buffer = next_line(buffer);
	return (line);
}
