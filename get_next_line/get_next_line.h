/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbugday <mbugday@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 13:39:05 by mbugday           #+#    #+#             */
/*   Updated: 2022/03/02 04:27:14 by mbugday          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# include<unistd.h>
# include<stdlib.h>

char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr( char *s, int c);
size_t	ft_strlen(char *str);
char	*get_next_line(int fd);
char	*ft_readfile(char *str, int fd);
char	*ft__next(char *str);
char	*ft_ligne(char *str);
#endif