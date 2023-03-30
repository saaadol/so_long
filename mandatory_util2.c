/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandatory_util2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souledla <souledla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:26:18 by souledla          #+#    #+#             */
/*   Updated: 2023/03/30 08:04:46 by souledla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"

void	assigning_values_util(t_list *list)
{
	list->img_wall = mlx_xpm_file_to_image(list->mlx, "wall.xpm",
			&list->img_width, &list->img_height);
	list->img_tree = mlx_xpm_file_to_image(list->mlx, "trees.xpm",
			&list->img_width, &list->img_height);
	list->img_sky = mlx_xpm_file_to_image(list->mlx, "sky.xpm",
			&list->img_width, &list->img_height);
	list->img_floor = mlx_xpm_file_to_image(list->mlx, "floor.xpm",
			&list->img_width, &list->img_height);
	list->img_soil = mlx_xpm_file_to_image(list->mlx, "soil.xpm",
			&list->img_width, &list->img_height);
	list->img_castle = mlx_xpm_file_to_image(list->mlx, "castle.xpm",
			&list->img_width, &list->img_height);
	list->img_water = mlx_xpm_file_to_image(list->mlx, "water.xpm",
			&list->img_width, &list->img_height);
}

void	assigning_values(t_list *list)
{
	list->position_y = 0;
	list->position_x = 0;
	list->mlx = mlx_init();
	list->img_path = "player2_.xpm";
	list->mlx_win = mlx_new_window(list->mlx, ((list->columns) * 64),
			((list->rows + 1) * 64), "New window");
	list->img = mlx_xpm_file_to_image(list->mlx, list->img_path,
			&list->img_width, &list->img_height);
	list->water_img[0] = mlx_xpm_file_to_image(list->mlx, "1_water.xpm",
			&list->img_width, &list->img_height);
	list->water_img[1] = mlx_xpm_file_to_image(list->mlx, "2_water.xpm",
			&list->img_width, &list->img_height);
	list->water_img[2] = mlx_xpm_file_to_image(list->mlx, "3_water.xpm",
			&list->img_width, &list->img_height);
	assigning_values_util(list);
}

void	displaying_wall_util_util(t_list *list)
{
	if (list->array[list->position_x][list->position_y] == 'P')
	{
		mlx_put_image_to_window(list->mlx, list->mlx_win, list->img_floor,
			list->position_y * 64, list->position_x * 64);
		mlx_put_image_to_window(list->mlx, list->mlx_win, list->img,
			list->position_y * 64, list->position_x * 64);
	}
	else if (list->array[list->position_x][list->position_y] == 'E')
	{
		mlx_put_image_to_window(list->mlx, list->mlx_win, list->img_floor,
			list->position_y * 64, list->position_x * 64);
		mlx_put_image_to_window(list->mlx, list->mlx_win, list->img_castle,
			list->position_y * 64, list->position_x * 64);
	}
}

void	displaying_wall_util(t_list *list)
{
	if (list->array[list->position_x][list->position_y] == '1')
	{
		if (list->position_x == 0)
			mlx_put_image_to_window(list->mlx, list->mlx_win, list->img_sky,
				list->position_y * 64, list->position_x * 64);
		else if (list->position_x == list->rows)
			mlx_put_image_to_window(list->mlx, list->mlx_win, list->img_soil,
				list->position_y * 64, list->position_x * 64);
		else
		{
			mlx_put_image_to_window(list->mlx, list->mlx_win, list->img_floor,
				list->position_y * 64, list->position_x * 64);
			mlx_put_image_to_window(list->mlx, list->mlx_win, list->img_tree,
				list->position_y * 64, list->position_x * 64);
		}
	}
	else if (list->array[list->position_x][list->position_y] == '0')
		mlx_put_image_to_window(list->mlx, list->mlx_win, list->img_floor,
			list->position_y * 64, list->position_x * 64);
	displaying_wall_util_util(list);
}

int	displaying_img_mandatory(t_list list)
{
	assigning_values(&list);
	while (list.array[list.position_x])
	{
		list.position_y = 0;
		while (list.array[list.position_x][list.position_y])
		{
			displaying_wall_util(&list);
			if (list.array[list.position_x][list.position_y] == 'C')
				mlx_put_image_to_window(list.mlx, list.mlx_win, list.img_floor,
					list.position_y * 64, list.position_x * 64);
			else if (list.array[list.position_x][list.position_y] == '\n')
				break ;
			list.position_y++;
		}
		list.position_x++;
	}
	mlx_loop_hook(list.mlx, &displaying_sprite_mandatory, &list);
	mlx_hook(list.mlx_win, 2, 1 << 0, moving_player_mandatory, &list);
	mlx_hook(list.mlx_win, 17, 0, closing_window, &list);
	mlx_loop(list.mlx);
	return (0);
}
