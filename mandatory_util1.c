/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandatory_util1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souledla <souledla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:14:33 by souledla          #+#    #+#             */
/*   Updated: 2023/03/30 05:43:50 by souledla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"

int	move_right_mandatory(t_list *list, int counter)
{
	int	x;

	list ->position_x = 0;
	list ->position_y = 0;
	x = 0;
	locating_start_point(list->array, &list->position_x, &list->position_y);
	move_right_mandatory_util(list, &counter, &x);
	if (list->array[list->position_x][list->position_y + 1] == 'E')
	{
		if (counter == list->coin)
		{
			mlx_destroy_window(list->mlx, list->mlx_win);
			exit(1);
		}
	}
	return (counter);
}

int	move_left_mandatory(t_list *list, int counter)
{
	int	x;

	list ->position_x = 0;
	list ->position_y = 0;
	x = 0;
	locating_start_point(list->array, &list->position_x, &list->position_y);
	move_left_mandatory_util(list, &counter, &x);
	if (list->array[list->position_x][list->position_y - 1] == 'E')
	{
		if (counter == list->coin)
		{
			mlx_destroy_window(list->mlx, list->mlx_win);
			exit(1);
		}
	}
	return (counter);
}

int	move_down_mandatory(t_list *list, int counter)
{
	int	x;

	list ->position_x = 0;
	list ->position_y = 0;
	x = 0;
	locating_start_point(list->array, &list->position_x, &list->position_y);
	move_down_mandatory_util(list, &counter, &x);
	if (list->array[list->position_x + 1][list->position_y] == 'E')
	{
		if (counter == list->coin)
		{
			mlx_destroy_window(list->mlx, list->mlx_win);
			exit(1);
		}
	}
	return (counter);
}

int	move_up_mandatory(t_list *list, int counter)
{
	int	x;

	list ->position_x = 0;
	list ->position_y = 0;
	x = 0;
	locating_start_point(list->array, &list->position_x, &list->position_y);
	move_up_mandatory_util(list, &counter, &x);
	if (list->array[list->position_x - 1][list->position_y] == 'E')
	{
		if (counter == list->coin)
		{
			mlx_destroy_window(list->mlx, list->mlx_win);
			exit(1);
		}
	}
	return (counter);
}
