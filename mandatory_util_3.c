/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandatory_util_3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souledla <souledla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:59:04 by souledla          #+#    #+#             */
/*   Updated: 2023/03/30 08:16:11 by souledla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"

void	reseting_flag_mandatory(int array[], int flag)
{
	if (flag == 0)
	{
		array[0] = 0;
		array[1] = 0;
	}
}

int	*moving_water(t_list *list)
{
	static int	array[2];

	if (list ->flagingo == 0)
		reseting_flag_mandatory(array, 0);
	if (!array[0])
		array[1]++;
	array[0] = (array[0] + 1) % 3;
	array[1] = array[1] % 3;
	list ->flagingo = 1;
	return (array);
}

int	displaying_sprite_mandatory(t_list *list)
{
	static int	*array;
	int			x;
	int			t;

	array = moving_water(list);
	x = 0;
	while (list->collectibles_pos[x])
	{
		if (list->collectibles_pos[x][0] == -1 &&
		list->collectibles_pos[x][1] == -1)
		{
			x++;
		}
		if (list->collectibles_pos[x])
		{
			mlx_put_image_to_window(list->mlx, list->mlx_win,
				list->water_img[array[1]],
				list->collectibles_pos[x][1] * 64,
				list->collectibles_pos[x][0] * 64);
			x++;
		}
	}
	return (0);
}

int	moving_player_mandatory(int keycode, t_list *list)
{
	static int	x;
	static int	counter = 0;

	if (keycode == 13 || keycode == 126)
	{
		counter = move_up_mandatory(list, counter);
		x++;
	}
	else if (keycode == 1 || keycode == 125)
	{
		counter = move_down_mandatory(list, counter);
		x++;
	}
	else if (keycode == 0 || keycode == 123)
	{
		counter = move_left_mandatory(list, counter);
		x++;
	}
	else if (keycode == 2 || keycode == 124)
	{
		counter = move_right_mandatory(list, counter);
		x++;
	}
	executing_moving_player_mandatory(keycode, list, x);
	return (counter);
}

void	executing_moving_player(int keycode, t_list *list, int x)
{
	char	*lmfao;

	if (keycode == 53)
	{
		mlx_destroy_window(list->mlx, list->mlx_win);
		exit(1);
	}
	lmfao = ft_itoa(x);
	mlx_put_image_to_window(list->mlx, list->mlx_win, list->img_sky, 0, 0);
	mlx_string_put(list->mlx, list->mlx_win, 0, 0, 17, lmfao);
	free(lmfao);
}
