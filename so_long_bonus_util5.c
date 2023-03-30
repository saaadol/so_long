/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus_util5.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souledla <souledla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 10:50:15 by souledla          #+#    #+#             */
/*   Updated: 2023/03/30 07:14:09 by souledla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"

void	moving_enemy_right_util(t_list *list, int x)
{
	mlx_put_image_to_window(list->mlx, list->mlx_win, list->img_enemy,
		(list->enemy_pos[x][1] + 1) * 64, list->enemy_pos[x][0] * 64);
	mlx_put_image_to_window(list->mlx, list->mlx_win, list->img_floor,
		list->enemy_pos[x][1] * 64, list->enemy_pos[x][0] * 64);
	list->array[list->enemy_pos[x][0]][list->enemy_pos[x][1] +1] = 'N';
	list->array[list->enemy_pos[x][0]][list->enemy_pos[x][1]] = '0';
}

int	moving_enemy_right_util2(t_list *list, int x)
{
	if (list->array[list->enemy_pos[x][0]][list->enemy_pos[x][1] +1] == 'P')
	{
		list->flag = 1;
		displaying_you_died(list);
		return (-1);
	}
	return (0);
}

void	moving_enemy_left_util(t_list *list, int *x)
{
	int	i;

	if (list->enemy_pos[*x][0] == -1)
	{
		*x = 0;
		i = 0;
		while (i < list->enemies + 2)
			free(list->enemy_pos[i++]);
		free(list->enemy_pos);
		list->enemy_pos = array_of_enemies(*list, 1);
	}
}

int	moving_enemy_left_util2(t_list *list, int x)
{
	if (list->array[list->enemy_pos[x][0]]
	[list->enemy_pos[x][1] - 3] == 'N')
		return (1);
	else if (list->array[list->enemy_pos[x][0]]
	[list->enemy_pos[x][1] - 1] == 'P')
	{
		list->flag = 1;
		displaying_you_died(list);
		return (-1);
	}
	return (0);
}

void	moving_enemy_left_util3(t_list *list, int x)
{
	mlx_put_image_to_window(list->mlx, list->mlx_win, list->img_enemy,
		(list->enemy_pos[x][1] -1) * 64, list->enemy_pos[x][0] * 64);
	mlx_put_image_to_window(list->mlx, list->mlx_win, list->img_floor,
		list->enemy_pos[x][1] * 64, list->enemy_pos[x][0] * 64);
	list->array[list->enemy_pos[x][0]][list->enemy_pos[x][1] -1] = 'N';
	list->array[list->enemy_pos[x][0]][list->enemy_pos[x][1]] = '0';
}
