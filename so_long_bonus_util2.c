/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus_util2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souledla <souledla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 16:12:38 by souledla          #+#    #+#             */
/*   Updated: 2023/03/30 08:18:01 by souledla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"

void	assigning_values_displaying_you_died(t_list *list)
{
	list->array[list->position_x][list->position_y - 3] = 'Y';
	list->array[list->position_x][list->position_y - 2] = 'O';
	list->array[list->position_x][list->position_y - 1] = 'U';
	list->array[list->position_x][list->position_y + 1] = 'S';
	list->array[list->position_x][list->position_y + 2] = 'U';
	list->array[list->position_x][list->position_y + 3] = 'c';
	list->array[list->position_x][list->position_y + 4] = 'K';
	list->position_x = 0;
	list->position_y = 0;
	list->img_y = mlx_xpm_file_to_image(list->mlx, "Y.xpm",
			&list->img_width, &list->img_height);
	list->img_o = mlx_xpm_file_to_image(list->mlx, "O.xpm",
			&list->img_width, &list->img_height);
	list->img_u = mlx_xpm_file_to_image(list->mlx, "U.xpm",
			&list->img_width, &list->img_height);
	list->img_s = mlx_xpm_file_to_image(list->mlx, "S.xpm",
			&list->img_width, &list->img_height);
	list->img_c = mlx_xpm_file_to_image(list->mlx, "C.xpm",
			&list->img_width, &list->img_height);
	list->img_k = mlx_xpm_file_to_image(list->mlx, "K.xpm",
			&list->img_width, &list->img_height);
}

void	displaying_img_util(t_list list)
{
	mlx_put_image_to_window(list.mlx, list.mlx_win,
		list.img_floor, list.position_y * 64, list.position_x * 64);
	mlx_put_image_to_window(list.mlx, list.mlx_win,
		list.img_enemy, list.position_y * 64, list.position_x * 64);
}

int	displaying_img(t_list list)
{
	assigning_values(&list);
	list.img_enemy = mlx_xpm_file_to_image(list.mlx, "enemy.xpm",
			&list.img_width, &list.img_height);
	while (list.array[list.position_x])
	{
		list.position_y = 0;
		while (list.array[list.position_x][list.position_y])
		{
			displaying_wall_util(&list);
			if (list.array[list.position_x][list.position_y] == 'C')
				mlx_put_image_to_window(list.mlx, list.mlx_win,
					list.img_floor, list.position_y * 64, list.position_x * 64);
			else if (list.array[list.position_x][list.position_y] == 'N')
			{
				displaying_img_util(list);
			}
			else if (list.array[list.position_x][list.position_y] == '\n')
				break ;
			list.position_y++;
		}
		list.position_x++;
	}
	executing_loops(&list);
	return (0);
}

int	closing_window(t_list *list)
{
	mlx_destroy_window(list->mlx, list->mlx_win);
	exit(0);
	return (0);
}

void	executing_loops(t_list *list)
{
	int	x;

	x = 0;
	mlx_loop_hook(list->mlx, &displaying_sprite, list);
	mlx_hook(list->mlx_win, 2, 1 << 0, moving_player_bonus, list);
	mlx_hook(list->mlx_win, 17, 0, closing_window, list);
	mlx_loop(list->mlx);
}
