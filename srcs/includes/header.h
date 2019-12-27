/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmeribal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 10:53:52 by tmeribal          #+#    #+#             */
/*   Updated: 2019/08/21 20:40:48 by tmeribal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef	struct		s_st
{
	int				numlines;
	char			empty;
	char			obs;
	char			full;
}					t_st;

typedef struct		s_max
{
	int				max;
	int				x;
	int				y;
}					t_max;

void				ft_putchar(char c);
void				ft_putstr(char *str);
int					ft_atoi(char *str);
int					ft_strlen(char *str);
int					**ft_strcpy(char **dest, t_st *st);
int					min(int a, int b, int c);
t_max				*bsq(int **lnum, t_st *st, char **str);
void				dobsq(char **lines, t_st *st);
void				printbsq(char **lines, t_st *st, t_max *square);
int					equalline(char *str);
int					countline(char *str);
char				**readfile(char *buf);
t_st				*createstruct(char *str);
void				readtext(char *buf);
void				readfiles(int res, char *buf, int size, int fd);

#endif
