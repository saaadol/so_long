/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus_main_util.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souledla <souledla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 16:12:42 by souledla          #+#    #+#             */
/*   Updated: 2023/03/30 07:14:46 by souledla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"

void	check_collectibles(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == 'C')
			return ;
		i++;
	}
	write(1, "No collectibles\n", 16);
	exit(1);
}

int	counting_collectibles(char **buffer)
{
	int	counter;
	int	i;
	int	j;

	counter = 0;
	i = 0;
	j = 0;
	while (buffer[i])
	{
		j = 0;
		while (buffer[i][j])
		{	
			if (buffer[i][j] == 'C')
				counter++;
			j++;
		}
			i++;
	}
	return (counter);
}

int	counting_enemies(char **buffer)
{
	int	counter;
	int	i;
	int	j;

	counter = 0;
	i = 0;
	j = 0;
	while (buffer[i])
	{
		j = 0;
		while (buffer[i][j])
		{	
			if (buffer[i][j] == 'N')
				counter++;
			j++;
		}
			i++;
	}
	return (counter);
}

void	check_startpoint_exit(char *buffer)
{
	int	counter1;
	int	i;
	int	counter2;

	counter1 = 0;
	i = 0;
	counter2 = 0;
	while (buffer[i])
	{
		if (buffer[i] == 'P')
			counter1++;
		else if (buffer[i] == 'E')
			counter2++;
		else if (counter1 > 1 || counter2 > 1)
		{
			write(1, "too many Exits | Start points\n", 32);
			exit(1);
		}
		i++;
	}
	if (counter1 == 0 || counter2 == 0)
	{
		perror("No Exit point or Start point");
		exit(1);
	}
}

void	locating_start_point(char **array, int *i, int *j)
{
	while (array[*i])
	{
		*j = 0;
		while (array[*i][*j])
		{
			if (array[*i][*j] == 'P')
				return ;
			else if (array[*i][*j] == '\n')
				break ;
			(*j)++;
		}
		(*i)++;
	}
}
