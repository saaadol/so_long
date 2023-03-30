/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus_main_util3.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souledla <souledla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 16:29:47 by souledla          #+#    #+#             */
/*   Updated: 2023/03/30 08:18:25 by souledla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"

void	checking_last_wall(char *buffer)
{
	int	i;
	int	len;
	int	counter;

	i = 0;
	len = ft_strlen(buffer);
	counter = 0;
	while (buffer[i])
	{
		if (buffer[i] != '1')
		{
			perror("Invalid Wall");
			exit(1);
		}
		i++;
	}
}

void	checking_other_characters(char *array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		if (array[i] != '\n' && array[i] != '1'
			&& array[i] != '0' && array[i] != 'C'
			&& array[i] != 'P' && array[i] != 'E' && array[i] != 'N')
		{	
			perror("Invalid character");
			exit(1);
		}
		i++;
	}
}

void	checking_other_characters_mandatory(char *array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		if (array[i] != '\n' && array[i] != '1'
			&& array[i] != '0' && array[i] != 'C'
			&& array[i] != 'P' && array[i] != 'E')
		{	
			perror("Invalid character");
			exit(1);
		}
		i++;
	}
}

void	checking_size_map(char **array, t_list list)
{
	int	i;

	i = 0;
	while (array[i])
	{	
		if ((ft_strlen(array[i]) != list.columns))
		{
			perror("map not rectangular");
			exit(1);
		}
		i++;
	}
}

void	assigning_values_displaying_you_died_util(t_list *list)
{
	if (list->array[list->position_x][list->position_y] == 'Y')
		mlx_put_image_to_window(list->mlx, list->mlx_win, list->img_y,
			list->position_y * 64, list->position_x * 64);
	else if (list->array[list->position_x][list->position_y] == 'O')
		mlx_put_image_to_window(list->mlx, list->mlx_win, list->img_o,
			list->position_y * 64, list->position_x * 64);
	else if (list->array[list->position_x][list->position_y] == 'U')
		mlx_put_image_to_window(list->mlx, list->mlx_win, list->img_u,
			list->position_y * 64, list->position_x * 64);
	else if (list->array[list->position_x][list->position_y] == 'S')
		mlx_put_image_to_window(list->mlx, list->mlx_win, list->img_s,
			list->position_y * 64, list->position_x * 64);
	else if (list->array[list->position_x][list->position_y] == 'c')
		mlx_put_image_to_window(list->mlx, list->mlx_win, list->img_c,
			list->position_y * 64, list->position_x * 64);
	else if (list->array[list->position_x][list->position_y] == 'K')
		mlx_put_image_to_window(list->mlx, list->mlx_win, list->img_k,
			list->position_y * 64, list->position_x * 64);
}
