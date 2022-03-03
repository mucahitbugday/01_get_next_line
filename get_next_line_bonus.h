/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbugday <mbugday@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 12:45:54 by mbugday           #+#    #+#             */
/*   Updated: 2022/03/04 02:14:45 by mbugday          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

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
