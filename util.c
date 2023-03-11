#include "so_long.h"
#include "get_next_line.h"

void displaying_img(t_list list)
{
	// int counter = 0;
	// printf("%d \n",list.columns);
	int i = 0;
	int j = 0;
	int x = 0;
	int y = 0;
	list.position_y= 0;
	list.position_x=0;
	list.mlx = mlx_init();
	list.img_path = "player2_.xpm";
	list.mlx_win = mlx_new_window(list.mlx, ((list.columns) * 64), ((list.rows+1)* 64), "New window");
	list.img = mlx_xpm_file_to_image(list.mlx, list.img_path, &list.img_width, &list.img_height);
	list.img_wall = mlx_xpm_file_to_image(list.mlx, "wall.xpm", &list.img_width, &list.img_height);
	list.img_tree = mlx_xpm_file_to_image(list.mlx, "trees.xpm", &list.img_width, &list.img_height);
	list.img_sky = mlx_xpm_file_to_image(list.mlx, "sky.xpm", &list.img_width, &list.img_height);
	list.img_floor = mlx_xpm_file_to_image(list.mlx, "floor.xpm", &list.img_width, &list.img_height);
	list.img_soil = mlx_xpm_file_to_image(list.mlx, "soil.xpm", &list.img_width, &list.img_height);
	list.img_castle = mlx_xpm_file_to_image(list.mlx, "castle.xpm", &list.img_width, &list.img_height);
	list.img_water = mlx_xpm_file_to_image(list.mlx, "water.xpm", &list.img_width, &list.img_height);
	list.img_enemy = mlx_xpm_file_to_image(list.mlx, "enemy.xpm", &list.img_width, &list.img_height);
	//printf("%d",mlx_key_hook(list.mlx_win, key_hook, &list));
	
	//mlx_put_image_to_window(list.mlx, list.mlx_win, list.img, list.img_width, list.img_height);
	// while (list.array[i])
	// {
	// 	printf("%s\n", list.array[i++]);
	// }
	
	while (list.array[list.position_x])
	{
		list.position_y = 0;
		while (list.array[list.position_x][list.position_y])
		{
			if (list.array[list.position_x][list.position_y] == '1')
			{
				if (list.position_x == 0)
					mlx_put_image_to_window(list.mlx, list.mlx_win, list.img_sky, list.position_y*64, list.position_x*64);
				else if (list.position_x == list.rows)
					mlx_put_image_to_window(list.mlx, list.mlx_win, list.img_soil, list.position_y*64, list.position_x*64);
				else
				{
					mlx_put_image_to_window(list.mlx, list.mlx_win, list.img_floor, list.position_y*64, list.position_x*64);
					mlx_put_image_to_window(list.mlx, list.mlx_win, list.img_tree, list.position_y*64, list.position_x*64);
				}
			}
			else if (list.array[list.position_x][list.position_y] == '0')
				mlx_put_image_to_window(list.mlx, list.mlx_win, list.img_floor, list.position_y*64, list.position_x*64);
			else if (list.array[list.position_x][list.position_y] == 'P')
			{
				mlx_put_image_to_window(list.mlx, list.mlx_win, list.img_floor, list.position_y*64, list.position_x*64);
				mlx_put_image_to_window(list.mlx, list.mlx_win, list.img, list.position_y*64, list.position_x*64);
			}
			else if (list.array[list.position_x][list.position_y] == 'E')
			{
				mlx_put_image_to_window(list.mlx, list.mlx_win, list.img_floor, list.position_y*64, list.position_x*64);
				mlx_put_image_to_window(list.mlx, list.mlx_win, list.img_castle, list.position_y*64, list.position_x*64);
			}
			else if (list.array[list.position_x][list.position_y] == 'C')
			{
				mlx_put_image_to_window(list.mlx, list.mlx_win, list.img_floor, list.position_y*64, list.position_x*64);
				mlx_put_image_to_window(list.mlx, list.mlx_win, list.img_water, list.position_y*64, list.position_x*64);
			}
			else if (list.array[list.position_x][list.position_y] == 'N')
			{
				mlx_put_image_to_window(list.mlx, list.mlx_win, list.img_floor, list.position_y*64, list.position_x*64);
				mlx_put_image_to_window(list.mlx, list.mlx_win, list.img_enemy, list.position_y*64, list.position_x*64);
			}
			else if (list.array[list.position_x][list.position_y] == '\n')
				break;
			list.position_y++;
		}
		list.position_x++;
	}
	mlx_hook(list.mlx_win, 2, 1<<0, moving_player, &list);
	
	
	mlx_loop(list.mlx);
}