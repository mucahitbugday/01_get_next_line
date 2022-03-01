/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbugday <mbugday@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 20:09:38 by rjaanit           #+#    #+#             */
/*   Updated: 2022/02/28 15:44:33 by mbugday          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
/////////////////////////////////////////////////////////////

char	*ft_strjoin(char *s1, char *s2)
{
	int		j;
	int		i;
	int		len;
	char	*ptr;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	ptr = (char *)malloc(sizeof(char) * len + 1);
	if (!ptr)
		return (NULL);
	j = 0;
	i = -1;
	while (s1[++i])
		ptr[i] = s1[i];
	while (s2[j])
		ptr[i++] = s2[j++];
	ptr[i] = '\0';
	free (s1);
	return (ptr);
}

char	*ft_strchr(char *s, int c)
{
	char	*str;
	char	ch;
	int		i;

	i = 0;
	str = (char *)s;
	ch = (char )c;
	if (!s)
		return (NULL);
	while (str[i] != ch)
	{
		if (str[i] == '\0')
		{
			return (0);
		}
		i++;
	}
	return (str + i);
}

size_t	ft_strlen(char *str)
{
	int		i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

/////////////////////////////////////////////////////////////
*/


//Okunan dosyanın 1. satırını yeni dizi üretim içerisine yazar 
char	*ft_ligne(char *str)
{
	char	*ptr;
	int		i;

	i = 0;
	if (!str[i])
		return (NULL);

	// \n görene kadar 1. satırdaki karakterleri sayar
	while (str[i] && str[i] != '\n')
		i++;

	// \n ve NULL icin iki tane fazka yer ayırır.
	ptr = (char *)malloc(sizeof(char) * (i + 2));
	
	if (!ptr)
		return (NULL);
	
	i = 0;
	
	//yeni oluşturulan dizinin 0. indisinden itibaren içerisine yazmaya başlar
	while (str[i] && str[i] != '\n')
	{
		ptr[i] = str[i];
		i++;
	}

	// 1. satırın son elemanına geldiyse girer ve sonuna \n koyar
	if (str[i] == '\n')
	{
		ptr[i] = str[i];
		i++;
	}
	
	//dizinin sonun NULL koyar
	ptr[i] = '\0';
	
	//1. satırı geri döner
	return (ptr);
}

//bir sonraki satıra gecer.
char	*ft_next(char *str)
{
	char	*ptr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	// satırdaki dizinin eleman sayısını sayar
	while (str[i] && str[i] != '\n')
		i++;
		
	if (!str[i])
	{
		free (str);
		return (NULL);
	}
  
	ptr = (char *)malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!ptr)
		return (NULL);
	i++;

	//1. satırın boyutundan itibaren yenidiziye atar.
	//dizi 3 elenanlı ise 4. elemndan itibaren yeni diziye atar
	while (str[i])
	{
		ptr[j++] = str[i++];
	}
	ptr[j] = '\0';
	free(str);
	return (ptr);
}


//dosya oku
//dosyadaki okudugu karakterleri geri döner
char	*ft_readfile(char *str, int fd)
{
	char	*buff;
	int		lire;

	lire = 1;
	
	buff = malloc(BUFFER_SIZE + 1);
	
	if (!buff)
		return (NULL);
		
	while (!ft_strchr(str, '\n') && lire != 0)
	{
		lire = read(fd, buff, BUFFER_SIZE);
		if (lire == -1)
		{
			free (buff);
			return (NULL);
		}
		buff[lire] = '\0';
		str = ft_strjoin(str, buff);
	}
	free (buff);
	return (str);
}

//Ana fonksiyon
char	*get_next_line(int fd)
{
	char		*ligne;
	static char	*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);

	//Dosyadaki bütün satırları okur 
	str = ft_readfile(str, fd);

	if (!str)
		return (NULL);

	//1. satırı geri göner
	ligne = ft_ligne(str);

	//1. satırı diziden çıkarır. 2. satıra geçer 
	str = ft_next(str);

	//oluşturulan 1. diziyi geri döner
	return (ligne);
}


#include <stdio.h>
#include <fcntl.h>
int	main2(void)
{
	char	*line;
	int		i;
	int		fd1;

	fd1 = open("metin.txt", O_RDONLY);

	i = 1;
	while (i <= 3)
	{
		line = get_next_line(fd1);
		printf("line [%02d]: %s", i, line);
		free(line);
		i++;
	}
	close(fd1);

	return (0);
}