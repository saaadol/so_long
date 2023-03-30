/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandatory_util_util2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souledla <souledla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:49:55 by souledla          #+#    #+#             */
/*   Updated: 2023/03/30 08:17:11 by souledla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "so_long.h"

void	move_up_mandatory_util(t_list *list, int *counter, int *x)
{
	if (list->array[list->position_x - 1][list->position_y] == '0' ||
	list->array[list->position_x - 1][list->position_y] == 'C')
	{
		move_up_mandatory_util_util(list, counter, x);
		mlx_put_image_to_window(list->mlx, list->mlx_win, list->img,
			list->position_y * 64, (list->position_x - 1) * 64);
		mlx_put_image_to_window(list->mlx, list->mlx_win, list->img_floor,
			list->position_y * 64, list->position_x * 64);
		list->array[list->position_x - 1][list->position_y] = 'P';
		list->array[list->position_x][list->position_y] = '0';
	}
}

void	move_down_mandatory_util(t_list *list, int *counter, int *x)
{
	if (list->array[list->position_x + 1][list->position_y] == '0' ||
	list->array[list->position_x + 1][list->position_y] == 'C')
	{
		move_down_mandatory_util_util(list, counter, x);
		mlx_put_image_to_window(list->mlx, list->mlx_win, list->img,
			list->position_y * 64, (list->position_x + 1) * 64);
		mlx_put_image_to_window(list->mlx, list->mlx_win, list->img_floor,
			list->position_y * 64, list->position_x * 64);
		list->array[list->position_x + 1][list->position_y] = 'P';
		list->array[list->position_x][list->position_y] = '0';
	}
}

void	move_left_mandatory_util(t_list *list, int *counter, int *x)
{
	if (list->array[list->position_x][list->position_y - 1] == '0' ||
	list->array[list->position_x][list->position_y - 1] == 'C')
	{
		move_left_mandatory_util_util(list, counter, x);
		mlx_put_image_to_window(list->mlx, list->mlx_win, list->img,
			(list->position_y - 1) * 64, list->position_x * 64);
		mlx_put_image_to_window(list->mlx, list->mlx_win, list->img_floor,
			list->position_y * 64, list->position_x * 64);
		list->array[list->position_x][list->position_y - 1] = 'P';
		list->array[list->position_x][list->position_y] = '0';
	}
}

void	move_right_mandatory_util(t_list *list, int *counter, int *x)
{
	if (list->array[list->position_x][list->position_y + 1] == '0' ||
	list->array[list->position_x][list->position_y + 1] == 'C')
	{
		move_right_mandatory_util_util(list, counter, x);
		mlx_put_image_to_window(list->mlx, list->mlx_win, list->img,
			(list->position_y + 1) * 64, list->position_x * 64);
		mlx_put_image_to_window(list->mlx, list->mlx_win, list->img_floor,
			list->position_y * 64, list->position_x * 64);
		list->array[list->position_x][list->position_y + 1] = 'P';
		list->array[list->position_x][list->position_y] = '0';
	}
}
