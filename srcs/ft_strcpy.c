/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmeribal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 13:56:58 by tmeribal          #+#    #+#             */
/*   Updated: 2019/08/21 20:21:21 by tmeribal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header.h"

int	**ft_strcpy(char **src, t_st *st)
{
	int **dest;
	int i;
	int j;

	i = 0;
    //printf("%c\n", st->empty);
    //printf("%c\n", st->obs);
    //printf("%c\n\n", st->full);
	dest = (int **)malloc(sizeof(int *) * st->numlines);
	while (src[i] != NULL)
	{
		j = 0;
		dest[i] = (int *)malloc(sizeof(int) * (ft_strlen(src[i]) + 1));
		while (src[i][j] != ('\0'))
		{
           //printf("%c", src[i][j]);
			if (src[i][j] == st->empty)
				dest[i][j] = 1;
			else if (src[i][j] == st->obs)
				dest[i][j] = 0;
			//else if (src[i][j] == st->full)
				//dest[i][j] = 1;
			else if ((src[i][j] != (st->empty && st->obs ) || src[i][j] == st->full)
                     && src[i][j] != 16)
            {
                if (src[i][j] == st->full)
                    printf("%s\n", "bred");
                if (src[i][j] != (st->empty && st->obs ))
                    printf("%s\n", "bred22");
                printf("%d\n", src[i][j]);
                //printf("%s\n", "Здесь ошибка");
                //printf("%d\n", src[i][j]);
				return (0);
            }
			j++;
		}
        // printf("%s\n", "");
		i++;
	}
	return (dest);
}
