/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandatory_util_util.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souledla <souledla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:47:56 by souledla          #+#    #+#             */
/*   Updated: 2023/03/30 05:50:52 by souledla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "so_long.h"

void	move_right_mandatory_util_util(t_list *list, int *counter, int *x)
{
	if (list->array[list->position_x][list->position_y + 1] == 'C')
	{
		mlx_put_image_to_window(list->mlx, list->mlx_win, list->img_floor,
			(list->position_y + 1) * 64, list->position_x * 64);
		while (list->collectibles_pos[*x])
		{
			if (list->collectibles_pos[*x][0] == list->position_x &&
			list->collectibles_pos[*x][1] == list->position_y + 1)
			{
				list->collectibles_pos[*x][0] = -1;
				list->collectibles_pos[*x][1] = -1;
			}
			(*x)++;
		}
		(*counter)++;
	}
}

void	move_left_mandatory_util_util(t_list *list, int *counter, int *x)
{
	if (list->array[list->position_x][list->position_y - 1] == 'C')
	{
		mlx_put_image_to_window(list->mlx, list->mlx_win, list->img_floor,
			(list->position_y - 1) * 64, list->position_x * 64);
		while (list->collectibles_pos[*x])
		{
			if (list->collectibles_pos[*x][0] == list->position_x &&
			list->collectibles_pos[*x][1] == list->position_y - 1)
			{
				list->collectibles_pos[*x][0] = -1;
				list->collectibles_pos[*x][1] = -1;
			}
			(*x)++;
		}
		(*counter)++;
	}
}

void	move_down_mandatory_util_util(t_list *list, int *counter, int *x)
{
	if (list->array[list->position_x + 1][list->position_y] == 'C')
	{
		mlx_put_image_to_window(list->mlx, list->mlx_win, list->img_floor,
			list->position_y * 64, (list->position_x + 1) * 64);
		while (list->collectibles_pos[*x])
		{
			if (list->collectibles_pos[*x][0] == list->position_x + 1 &&
			list->collectibles_pos[*x][1] == list->position_y)
			{
				list->collectibles_pos[*x][0] = -1;
				list->collectibles_pos[*x][1] = -1;
			}
			(*x)++;
		}
		(*counter)++;
	}
}

void	move_up_mandatory_util_util(t_list *list, int *counter, int *x)
{
	if (list->array[list->position_x - 1][list->position_y] == 'C')
	{
		mlx_put_image_to_window(list->mlx, list->mlx_win, list->img_floor,
			list->position_y * 64, (list->position_x - 1) * 64);
		while (list->collectibles_pos[*x])
		{
			if (list->collectibles_pos[*x][0] == list->position_x - 1 &&
			list->collectibles_pos[*x][1] == list->position_y)
			{
				list->collectibles_pos[*x][0] = -1;
				list->collectibles_pos[*x][1] = -1;
			}
			(*x)++;
		}
		(*counter)++;
	}
}

void	executing_moving_player_mandatory(int keycode, t_list *list, int x)
{
	char	*lmfao;

	if (keycode == 53)
	{
		mlx_destroy_window(list->mlx, list->mlx_win);
		exit(1);
	}
	printf("Number of moves: %d\n", x);
}
