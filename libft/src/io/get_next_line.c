/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <mmoussou@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 10:03:00 by mmoussou          #+#    #+#             */
/*   Updated: 2024/01/11 23:39:41 by mmoussou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define BUFFER_SIZE 42

char	*read_line(int fd, char *stash)
{
	char	*str;
	int		c;

	str = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!str)
		return (NULL);
	c = 1;
	while (!ft_strchr(stash, '\n') && c)
	{
		c = read(fd, str, BUFFER_SIZE);
		if (c < 0)
		{
			free(str);
			free(stash);
			return (NULL);
		}
		str[c] = 0;
		stash = ft_strjoin_free_s1(stash, str);
		if (!stash)
			free(str);
		if (!stash)
			return (NULL);
	}
	free(str);
	return (stash);
}

char	*get_line(char *stash)
{
	char	*str;
	int		i;

	if (!stash)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		str[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
		str[i++] = '\n';
	str[i] = 0;
	return (str);
}

char	*get_stash(char *stash)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	str = malloc(sizeof(char) * (ft_strlen(stash) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (stash[i])
	{
		str[j++] = stash[i++];
	}
	str[j] = 0;
	free(stash);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*stash[1024] = {NULL};
	char		*line;

	if (fd < 0 || fd > 1023 || BUFFER_SIZE < 1)
		return (NULL);
	line = 0;
	stash[fd] = read_line(fd, stash[fd]);
	if (!stash[fd] || !stash[fd][0])
	{
		if (stash[fd] && !stash[fd][0])
			free(stash[fd]);
		stash[fd] = NULL;
		return (NULL);
	}
	line = get_line(stash[fd]);
	stash[fd] = get_stash(stash[fd]);
	return (line);
}
