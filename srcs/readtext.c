/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readtext.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmeribal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 17:30:43 by tmeribal          #+#    #+#             */
/*   Updated: 2019/08/21 21:12:44 by tmeribal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header.h"
#include <stdio.h>

#define SIZE 20000

void		readfiles(int res, char *buf, int size, int fd)
{
    res = read(fd, buf, size);
	buf[res] = '\0';
    //printf("%d\n", res);
	if ((createstruct(buf) != 0) && (res != 0) && (equalline(buf)))
    {
		dobsq(readfile(buf), createstruct(buf));
        //buf[0]='\0';
    }
	else
		write(1, "Error map.\n", 11);
}

void		readtext(char *buf)
{
	char	c;
	int		i;

	i = 0;
	while (read(0, &c, 1) == 1)
	{
		buf[i] = c;
		i++;
	}
	buf[i] = '\0';
	write(1, "\n", 1);
	if ((createstruct(buf) != 0) && (i != 0) && (equalline(buf) != 0))
    {
		dobsq(readfile(buf), createstruct(buf));
        //buf[0]='\0';
    }
	else
		write(1, "Error map.\n", 11);
}
