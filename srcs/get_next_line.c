/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uaupetit <uaupetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 12:12:15 by uaupetit          #+#    #+#             */
/*   Updated: 2023/03/09 11:41:44 by uaupetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line/includes/get_next_line.h"

void	error_flag(char *stash)
{
	free (stash);
	return ;
}

char	*get_next_line(int fd, int flag)
{
	static char	*stash;
	int			resread;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (flag == 1)
		return (error_flag(stash), NULL);
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	resread = 1;
	while (!(ft_strchr2(stash, '\n')) && (resread != 0))
	{
		resread = read(fd, buffer, BUFFER_SIZE);
		if (resread == -1 && !stash)
			return (free (buffer), NULL);
		buffer[resread] = '\0';
		stash = ft_strjoin2(stash, buffer);
	}
	free(buffer);
	buffer = ft_line(stash);
	stash = ft_delline(stash, resread);
	return (buffer);
}
