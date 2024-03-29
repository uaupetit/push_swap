/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uaupetit <uaupetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 12:41:55 by uaupetit          #+#    #+#             */
/*   Updated: 2023/03/08 12:30:38 by uaupetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

int		ft_strlen2(char *s);
char	*ft_line(char *stash);
char	*get_next_line(int fd, int flag);
char	*ft_delline(char *stash, int resread);
char	*ft_strjoin2(char *s1, char *s2);
char	*ft_strchr2(char *s, int c);
void	error_flag(char *stash);

#endif
