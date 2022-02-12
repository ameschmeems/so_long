/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpucylo <kpucylo@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 15:02:50 by kpucylo           #+#    #+#             */
/*   Updated: 2022/01/25 15:36:52 by kpucylo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*move_line(char *s)
{
	char	*dest;

	dest = ft_strchr(s, '\n');
	if (!dest)
	{
		free(s);
		return (NULL);
	}
	if (*(dest + 1))
		dest = ft_strdup(dest + 1);
	else
		dest = NULL;
	free(s);
	return (dest);
}

char	*get_next_line(int fd)
{
	static char	*s[9999];
	char		*dest;
	char		buffer[BUFFER_SIZE + 1];
	int			size;

	size = read(fd, buffer, BUFFER_SIZE);
	if (size == -1)
		return (NULL);
	buffer[size] = 0;
	while (size > 0)
	{
		if (!s[fd])
			s[fd] = ft_strdup(buffer);
		else
			s[fd] = ft_strjoin(s[fd], buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
		size = read(fd, buffer, BUFFER_SIZE);
		buffer[size] = 0;
	}
	dest = ft_substr(s[fd], 0, ft_strchr(s[fd], '\n') - s[fd] + 1);
	s[fd] = move_line(s[fd]);
	return (dest);
}
