/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus_util1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souledla <souledla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 16:20:39 by souledla          #+#    #+#             */
/*   Updated: 2023/03/30 08:17:46 by souledla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"

int	move_right_bonus(t_list *list, int counter)
{
	int	x;

	x = 0;
	if (list ->flag == 1)
		return (0);
	list ->position_x = 0;
	list ->position_y = 0;
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
	else if (list->array[list->position_x][list->position_y + 1] == 'N')
	{
		list->flag = 1;
		displaying_you_died(list);
	}
	return (counter);
}

int	move_left_bonus(t_list *list, int counter)
{
	int	x;

	x = 0;
	if (list ->flag == 1)
		return (0);
	list ->position_x = 0;
	list ->position_y = 0;
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
	else if (list->array[list->position_x][list->position_y - 1] == 'N')
	{
		list->flag = 1;
		displaying_you_died(list);
	}
	return (counter);
}

int	move_down_bonus(t_list *list, int counter)
{
	int	x;

	x = 0;
	if (list ->flag == 1)
		return (0);
	list ->position_x = 0;
	list ->position_y = 0;
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
	else if (list->array[list->position_x + 1][list->position_y] == 'N')
	{
		list->flag = 1;
		displaying_you_died(list);
	}
	return (counter);
}

int	move_up_bonus(t_list *list, int counter)
{
	int	x;

	x = 0;
	if (list ->flag == 1)
		return (0);
	list ->position_x = 0;
	list ->position_y = 0;
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
	else if (list->array[list->position_x - 1][list->position_y] == 'N')
	{
		list->flag = 1;
		displaying_you_died(list);
	}
	return (counter);
}

int	moving_player_bonus(int keycode, t_list *list)
{
	static int	x;
	static int	counter = 0;

	if (keycode == 13 || keycode == 126)
	{
		counter = move_up_bonus(list, counter);
		x++;
	}
	else if (keycode == 1 || keycode == 125)
	{
		counter = move_down_bonus(list, counter);
		x++;
	}
	else if (keycode == 0 || keycode == 123)
	{
		counter = move_left_bonus(list, counter);
		x++;
	}
	else if (keycode == 2 || keycode == 124)
	{
		counter = move_right_bonus(list, counter);
		x++;
	}
	executing_moving_player(keycode, list, x);
	return (counter);
}
