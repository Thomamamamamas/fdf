/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 16:53:36 by tcasale           #+#    #+#             */
/*   Updated: 2023/01/06 11:08:11 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE	1

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*get_actual_line(char *save);
char	*save_next_line(char *save);
char	*gnl_ft_strchr(char *s, int c);
size_t	gnl_ft_strlen(char *s);
char	*gnl_ft_strjoin(char *s1, char *s2);

#endif
