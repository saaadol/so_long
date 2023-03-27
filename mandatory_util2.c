#include "so_long.h"
#include "get_next_line.h"


void assigning_values(t_list *list)
{
	list->position_y = 0;
	list->position_x=0;
	list->mlx = mlx_init();
	list->img_path = "player2_.xpm";
	list->mlx_win = mlx_new_window(list->mlx, ((list->columns) * 64), ((list->rows+1)* 64), "New window");
	list->img = mlx_xpm_file_to_image(list->mlx, list->img_path, &list->img_width, &list->img_height);
	list->water_img[0] = mlx_xpm_file_to_image(list->mlx, "1_water.xpm", &list->img_width, &list->img_height);
	list->water_img[1] = mlx_xpm_file_to_image(list->mlx, "2_water.xpm", &list->img_width, &list->img_height);
	list->water_img[2] = mlx_xpm_file_to_image(list->mlx, "3_water.xpm", &list->img_width, &list->img_height);
	list->img_wall = mlx_xpm_file_to_image(list->mlx, "wall.xpm", &list->img_width, &list->img_height);
	list->img_tree = mlx_xpm_file_to_image(list->mlx, "trees.xpm", &list->img_width, &list->img_height);
	list->img_sky = mlx_xpm_file_to_image(list->mlx, "sky.xpm", &list->img_width, &list->img_height);
	list->img_floor = mlx_xpm_file_to_image(list->mlx, "floor.xpm", &list->img_width, &list->img_height);
	list->img_soil = mlx_xpm_file_to_image(list->mlx, "soil.xpm", &list->img_width, &list->img_height);
	list->img_castle = mlx_xpm_file_to_image(list->mlx, "castle.xpm", &list->img_width, &list->img_height);
	list->img_water = mlx_xpm_file_to_image(list->mlx, "water.xpm", &list->img_width, &list->img_height);
}
void displaying_wall_util(t_list *list)
{
	if (list->array[list->position_x][list->position_y] == '1')
			{
				if (list->position_x == 0)
					mlx_put_image_to_window(list->mlx, list->mlx_win, list->img_sky, list->position_y*64, list->position_x*64);
				else if (list->position_x == list->rows)
					mlx_put_image_to_window(list->mlx, list->mlx_win, list->img_soil, list->position_y*64, list->position_x*64);
				else
				{
					mlx_put_image_to_window(list->mlx, list->mlx_win, list->img_floor, list->position_y*64, list->position_x*64);
					mlx_put_image_to_window(list->mlx, list->mlx_win, list->img_tree, list->position_y*64, list->position_x*64);
				}
			}
			else if (list->array[list->position_x][list->position_y] == '0')
				mlx_put_image_to_window(list->mlx, list->mlx_win, list->img_floor, list->position_y*64, list->position_x*64);
			else if (list->array[list->position_x][list->position_y] == 'P')
			{
				mlx_put_image_to_window(list->mlx, list->mlx_win, list->img_floor, list->position_y*64, list->position_x*64);
				mlx_put_image_to_window(list->mlx, list->mlx_win, list->img, list->position_y*64, list->position_x*64);
			}
			else if(list->array[list->position_x][list->position_y] == 'E')
			{
				mlx_put_image_to_window(list->mlx, list->mlx_win, list->img_floor, list->position_y*64, list->position_x*64);
				mlx_put_image_to_window(list->mlx, list->mlx_win, list->img_castle, list->position_y*64, list->position_x*64);
			}
}
int displaying_img_mandatory(t_list list)
{
	assigning_values(&list);
	while (list.array[list.position_x])
	{
		list.position_y = 0;
		while (list.array[list.position_x][list.position_y])
		{
			displaying_wall_util(&list);
			if (list.array[list.position_x][list.position_y] == 'C')
				mlx_put_image_to_window(list.mlx, list.mlx_win, list.img_floor, list.position_y*64, list.position_x*64);
			else if (list.array[list.position_x][list.position_y] == '\n')
				break;
			list.position_y++;
		}
		list.position_x++;
	}
	mlx_loop_hook(list.mlx, &displaying_sprite_mandatory, &list);
	mlx_hook(list.mlx_win, 2, 1<<0, moving_player_mandatory, &list);
	mlx_hook(list.mlx_win, 17, 0, closing_window, &list);
	mlx_loop(list.mlx);	
	return 0;
}
void reseting_flag_mandatory(int array[], int flag)
{
	if (flag == 0)
		{
			array[0] = 0;
			array[1] = 0;
		}
	}
int *moving_water(t_list *list)
{
	static int array[2];
	if (list ->flagingo == 0)
		reseting_flag_mandatory(array,0);
	if (!array[0])
		array[1]++;
	array[0] = (array[0]+1) % 3;
	array[1] = array[1] % 3;
	list ->flagingo = 1;
	return array;
}
int displaying_sprite_mandatory(t_list *list)
{
		static int *array; 
		int x;
		int t;

		array = moving_water(list); 
		x = 0;
		while (list->collectibles_pos[x])
		{
			if(list->collectibles_pos[x][0] == -1 && list->collectibles_pos[x][1] == -1)
			{
				x++;
			}
			if	(list->collectibles_pos[x])
			{
				mlx_put_image_to_window(list->mlx, list->mlx_win, list->water_img[array[1]], list->collectibles_pos[x][1] * 64, list->collectibles_pos[x][0] * 64);
				x++;
			}
		}
	return 0;
}

int moving_player_mandatory(int keycode, t_list *list)
{
	static int x;
	static int counter = 0;

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
	executing_moving_player(keycode, list, x);
	return(counter);
}

void executing_moving_player(int keycode, t_list *list, int x)
{
	char *lmfao; 
	
	if (keycode == 53)
	{
		mlx_destroy_window(list->mlx,list->mlx_win)	;
		exit(1);
	}
	lmfao = ft_itoa(x);
	mlx_put_image_to_window(list->mlx, list->mlx_win, list->img_sky, 0,0);
	mlx_string_put(list->mlx, list->mlx_win, 0, 0, 17,lmfao);
	free(lmfao);
}