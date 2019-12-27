/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmeribal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 13:12:35 by tmeribal          #+#    #+#             */
/*   Updated: 2019/08/21 20:19:45 by tmeribal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int					ft_atoi(char *str)
{
	int				index;
	int				res;
	int				digit;

	index = 0;
	res = 0;
	digit = 1;
	while ((str[index] == 32) || ((str[index] >= 13) && (str[index] <= 19)))
		index++;
	if ((str[index] == '-') || (str[index] == '+'))
	{
		if (str[index] == '-')
			digit = -1;
		index++;
	}
	while ((str[index] >= '0') && (str[index] <= '9')
			&& (str[index + 3] != ('\n' | '\0')))
	{
		res = (res * 10) + (str[index] - '0');
		index++;
	}
	return (res * digit);
}
