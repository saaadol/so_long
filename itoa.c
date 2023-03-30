/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souledla <souledla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 08:15:21 by souledla          #+#    #+#             */
/*   Updated: 2023/03/30 08:15:38 by souledla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"

static int	len_counter(long c)
{
	int	counter;

	counter = 0;
	while (c > 9)
	{
		c = c / 10;
		counter++;
	}
	return (counter);
}

static void	dev(long c, char *x, int temp, int flag)
{
	int	m;
	int	t;

	t = temp +1;
	while (c > 9)
	{
		m = c % 10;
		c = c / 10;
		x[temp--] = m + '0';
	}
	if (c < 10)
		x[temp] = c + '0';
	if (flag == 1)
		x[t++] = '\0';
	else
		x[t] = '\0';
}

static char	*allocation(int *flag, char *x, int *temp)
{
	if (*flag == 1)
	{
		x = (char *)malloc(sizeof(char) * ((*temp) + 2));
		if (!x)
			return (0);
		x[0] = '-';
	}
	else
	{
		x = (char *)malloc(sizeof(char) * ((*temp) + 1));
		if (!x)
			return (0);
		(*temp)--;
	}
	return (x);
}

char	*ft_itoa(int c1)
{
	char	*x;
	int		temp;
	int		flag;
	long	c;

	c = c1;
	x = NULL;
	flag = 0;
	if (c < 0)
	{
		c = -c;
		flag = 1;
	}
	temp = len_counter(c) + 1;
	x = allocation(&flag, x, &temp);
	if (!x)
		return (0);
	dev(c, x, temp, flag);
	return (x);
}
