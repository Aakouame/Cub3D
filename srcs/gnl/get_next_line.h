/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <akouame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 17:18:47 by akouame           #+#    #+#             */
/*   Updated: 2022/12/15 15:23:42 by yaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 1
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_substrs(char *s, unsigned int start, size_t len);
size_t	ft_strlens(const char *s);
char	*ft_strjoins(char *s1, char *s2);
char	*ft_strdups(char *s1);
char	*ft_frees(char **str);

#endif
