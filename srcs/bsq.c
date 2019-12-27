/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmeribal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 17:19:38 by tmeribal          #+#    #+#             */
/*   Updated: 2019/08/21 20:59:50 by tmeribal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header.h"

int			min(int a, int b, int c)
{
	if ((a <= b) && (a <= c))
		return (a);
	else if ((b <= a) && (b <= c))
		return (b);
	else
		return (c);
}

t_max		*bsq(int **lnum, t_st *st, char **str)
{
	int		i;
	int		j;
	t_max	*square;

    i = st->numlines - 1;
	square = malloc(sizeof(t_max));
	square->max = 0;
    if (i == 0)
    {
        square->max = 1;
        square->x = 0;
        square->y = 0;
    }
	while ((--i) >= 0)
	{
       // printf("%d\n", 5);
		j = ft_strlen(str[0]) - 1;
		while ((--j) >= 0)
			if (lnum[i][j] != 0)
			{
				lnum[i][j] = min(lnum[i + 1][j],
						lnum[i][j + 1], lnum[i + 1][j + 1]) + 1;
				if (lnum[i][j] >= square->max)
				{
					square->max = lnum[i][j];
					square->x = i;
					square->y = j;
				}
			}
	}
   // printf("%d\n", square->max);
   // printf("%d\n", square->x);
   //printf("%d\n", square->y);
	return (square);
}

void		dobsq(char **lines, t_st *st)
{
	int		**a;

	a = ft_strcpy(lines, st);
	if (a != 0)
		printbsq(lines, st, bsq(a, st, lines));
	else
		write(1, "Error map.\n", 11);
	free(st);
}

void		printbsq(char **lines, t_st *st, t_max *square)
{
	int		i;
	int		j;

	i = 0;
	while (lines[i])
	{
		j = 0;
		while (lines[i][j])
		{
			if ((square->max == 1) && (i == square->x) && (j == square->y))
				lines[i][j] = st->full;
			else if ((i >= square->x) && (i <= (square->x + square->max - 1))
					&& (j >= square->y) && (j <= (square->y + square->max - 1)))
				lines[i][j] = st->full;
			else if (lines[i][j] == st->full)
				lines[i][j] = st->empty;
			j++;
		}
		ft_putstr(lines[i]);
		write(1, "\n", 1);
		i++;
	}
}
