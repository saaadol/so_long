/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus_main_util2.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souledla <souledla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 16:20:42 by souledla          #+#    #+#             */
/*   Updated: 2023/03/30 08:17:29 by souledla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"

void	locating_end_point(char **array, int *i, int *j)
{
	while (array[*i])
	{
		*j = 0;
		while (array[*i][*j])
		{
			if (array[*i][*j] == 'E')
				return ;
			else if (array[*i][*j] == '\n')
				break ;
			(*j)++;
		}
		(*i)++;
	}
}

void	filling_map_with_x(char **array, int i, int j)
{
	if (array[i][j] == '1' || array[i][j] == 'E' || array[i][j] == 'x')
		return ;
	else if (array[i][j] == '0' || array[i][j] == 'P' || array[i][j] == 'C' ||
		array[i][j] == 'N')
	{
		array[i][j] = 'x';
		filling_map_with_x(array, i + 1, j);
		filling_map_with_x(array, i - 1, j);
		filling_map_with_x(array, i, j + 1);
		filling_map_with_x(array, i, j - 1);
	}
}

void	checking_valid_path(char **array)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	locating_end_point(array, &i, &j);
	if (array[i + 1][j] != 'x' &&
	array[i - 1][j] != 'x' && array[i][j + 1] != 'x' && array[i][j - 1] != 'x')
	{
		write(1, "Invalid Map \n", 13);
		exit(1);
	}
	checking_if_collectibles_still_there(array);
}

void	checking_if_collectibles_still_there(char **array)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (array[i])
	{
		j = 0;
		while (array[i][j])
		{
			if (array[i][j] == 'C')
			{
				write(1, "Collectible still there \n", 25);
				exit(1);
			}
			j++;
		}
		i++;
	}
}

void	checking_first_wall(char *buffer)
{
	int	i;
	int	len;
	int	counter;

	i = 0;
	len = ft_strlen(buffer);
	counter = 0;
	while (buffer[i] && i < len - 1)
	{
		if (buffer[i] != '1' || buffer[len - 1] != '\n')
		{
			perror("Invalid Wall");
			exit(1);
		}
		i++;
	}
}
