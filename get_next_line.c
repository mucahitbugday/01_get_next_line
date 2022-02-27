/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbugday <mbugday@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 20:09:38 by rjaanit           #+#    #+#             */
/*   Updated: 2022/02/27 03:46:19 by mbugday          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

//bir sonraki kelimeye gecer.
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
	
	//fd dosyasından okunan karakterler için yer aç
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
	str = ft_readfile(str, fd);
	if (!str)
		return (NULL);
	ligne = ft_ligne(str);
	str = ft_next(str);
	return (ligne);
}
/*
#include <stdio.h>
#include <fcntl.h>
int	main(void)
{
	char	*line;
	int		i;
	int		fd1;

	fd1 = open("metin.txt", O_RDONLY);

	i = 1;
	while (i <= 5)
	{
		line = get_next_line(fd1);
		printf("line [%02d]: %s", i, line);
		free(line);
		i++;
	}
	close(fd1);

	return (0);
}
*/
