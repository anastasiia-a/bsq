/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmeribal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 12:45:48 by tmeribal          #+#    #+#             */
/*   Updated: 2019/08/21 21:13:32 by tmeribal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs/includes/header.h"
#include <stdio.h>


//проблема с работой файла p
// выводит то, что в структуру записаны все поля, но при дальнейшей работе программы вылетает с ошибкой переполнения

//непонятно почему при запуске файлов с маленькими картами выдает ошибку, при работе с такими же картами в терминале все отлично, но если же запустить несколько файлов и сначала поставить большой, все карты выполнятся прекрасно
#define SIZE 20000

int			equalline(char *str)
{
	int		i;
	int		count;

	i = 0;
	while (str[i] != '\n')
		i++;
	i++;
	count = ft_strlen(&(str[i]));
	while (str[i] != '\0')
	{
		while (str[i] != '\n')
			i++;
		i++;
		if ((ft_strlen(&(str[i])) != count) && (str[i] != '\0'))
			return (0);
		count = ft_strlen(&(str[i]));
	}
	return (1);
}

int			countline(char *str)
{
	int		i;
	int		count;
	int		num;

	i = 0;
	count = -1;
	num = ft_atoi(str);
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			count++;
		i++;
	}
	if (count != num)
		return (0);
	return (1);
}

char		**readfile(char *buf)
{
	char	**lines;
	int		i;
	int		j;

	i = 0;
	lines = (char **)malloc((sizeof(char *) * ft_atoi(buf)) + 1);
	while (*buf != '\n')
		buf++;
	buf++;
	while (*buf != '\0')
	{
		j = 0;
		lines[i] = (char *)malloc(sizeof(char) * (ft_strlen(&(*buf)) + 1));
		while (*buf != '\n')
		{
			lines[i][j] = *buf;
			j++;
			buf++;
		}
		lines[i][j] = '\0';
		buf++;
		i++;
	}
	return (lines);
}

t_st		*createstruct(char *str)
{
	t_st	*s;

	s = malloc(sizeof(t_st) + 1);
	if (!s)
		return (0);
	if (countline(str) == 0)
		return (0);
	s->numlines = ft_atoi(str);
	while (*(str + 3) != '\n')
		str++;
	s->empty = *str;
    //printf("%c\n", s->empty);
	s->obs = *(str + 1);
    //printf("%c\n", s->obs);
	s->full = *(str + 2);
    //printf("%c\n", s->full);
	if (*(str + 3) != '\n')
		return (0);
	return (s);
}

int			main(int argc, char **argv)
{
	int		fd;
	int		res;
	char	buf[SIZE + 1];
	int		i;
	int		closef;

	i = 1;
	fd = 0;
	res = 0;
	while (i < argc)
	{
		fd = open(argv[i], O_RDONLY);
		if (fd == -1)
			write(1, "Error map.\n", 11);
		else
			readfiles(res, buf, SIZE, fd);
		if (i != (argc - 1))
			write(1, "\n", 1);
		closef = close(fd);
		i++;
	}
	if (argc == 1)
		readtext(buf);
	return (0);
}
