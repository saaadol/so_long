#include "so_long.h"
#include "get_next_line.h"

int **array_of_collectibles(t_list list)
{
	int i = 0;
	int x = 0;
	int y = 0;
	int flag = 0;
	int **list_of_collectibles;
	int *array;
	list_of_collectibles = calloc(sizeof(int *), list.coin + 1);
	list_of_collectibles[list.coin + 1] = 0;
	while (i < list.coin)
	{
		list_of_collectibles[i] = calloc(sizeof(int), 2);
		i++;
	}
	array = searching_for_collectibles(list);
	while (1)
	{
		if(array[0] == -1)
			break;
		list_of_collectibles[x][0] = array[0];
		list_of_collectibles[x][1] = array[1];
		free(array);
		array = searching_for_collectibles(list);
		x++;
	}
	free(array);
	i = 0;
	return list_of_collectibles;
}
int **array_of_enemies(t_list list, int flag)
{
	int i = 0;
	int x = 0;
	int y = 0;
	int **list_of_collectibles;
	int *array;
	list_of_collectibles = calloc(sizeof(int *), list.enemies + 2);
	while (i < list.enemies + 2)
	{
		list_of_collectibles[i] = calloc(sizeof(int), 2);
		i++;
	}
	array = searching_for_enemies(list, flag);

	while (1)
	{
		// if (x == 5)
		// 	exit(0);
		list_of_collectibles[x][0] = array[0];
		list_of_collectibles[x][1] = array[1];
		if(list_of_collectibles[x][0] == -1)
		{
			list_of_collectibles[x + 1] = NULL;
			break;
		}
		free(array);
		array = searching_for_enemies(list, 0);
		x++;
	}
	i = 0;
	// while (list_of_collectibles[i]) {
	// 	puts("hello");
	// 	printf("(%d, %d) ", list_of_collectibles[i][0], list_of_collectibles[i][1]);
	// 	i++;
	// }
	return list_of_collectibles;
}
int *searching_for_collectibles(t_list list)
{
	int *array;
	static int x = 0;
 	static int y = 0;
	array = calloc(sizeof(int), 2);
	while (list.array[x])
	{
		while(list.array[x][y])
		{
			if (list.array[x][y] == 'C')
			{
				array[0] = x;
				array[1] = y;
				y++;
				return array;
			}
			y++;
		}
		y = 0;
		x++;
	}
	if (x-1 == list.rows)
	{
		array[0] = -1;
		array[1] = -1;
		return array;
	}

	return array;
}
int *searching_for_enemies(t_list list,int flag)
{
	int *array;
	static int x = 0;
 	static int y = 0;
	array = calloc(sizeof(int), 2);
	if (flag == 1)
	{
		x = 0; 
		y = 0;
	}
	while (list.array[x])
	{
		while(list.array[x][y])
		{
			if (list.array[x][y] == 'N')
			{
				array[0] = x;
				array[1] = y;
				y++;
				return array;
			}
			y++;
		}
		y = 0;
		x++;
	}
	if (x - 1 == list.rows)
	{
		array[0] = -1;
		array[1] = -1;
		return array;
	}
	return array;
}
// int *searching_for_collectibles(t_list list)
// {
// 	int *array;
// 	int x = 0;
//  	int y = 0;
// 	array = malloc(sizeof(int) * 2);
// 	while (list.array[x])
// 	{
// 		y = 0;
// 		while(list.array[x][y])
// 		{
// 			if (list.array[x][y] == 'C')
// 			{
// 				array[0] = x;
// 				array[1] = y;
// 				return array;
// 			}
// 			y++;
// 		}
// 		x++;
// 	}
// 	if (x-1 == list.rows)
// 	{
// 		array[0] = -1;
// 		array[1] = -1;
// 		return array;
// 	}
// 	return array;
// }
int displaying_sprite(t_list *list)
{
		static int  i = 0;
		static int	j = 0;
		int x = 0;
		static int s = 0;
		static int b = 0;
		static int k = 0;
		int t;
		while (list->collectibles_pos[x])
		{
			if(list->collectibles_pos[x][0] == -1 && list->collectibles_pos[x][1] == -1)
			{
				x++;
			}
			if	(list->collectibles_pos[x])
			{
				mlx_put_image_to_window(list->mlx, list->mlx_win, list->water_img[j], list->collectibles_pos[x][1] * 64, list->collectibles_pos[x][0] * 64);
				x++;
			}
		}
		i = (i+1) % 3;
		if (s == 10)
		{
			if (k == 0)
				k = 1;
			else
				k = 0;
			s = 0;
		}
		if (!i)
		{
			j++;
			if (t == -1)
			{
				return 0;
			}
			if (k == 0)
			{
				list->enemy_pos = array_of_enemies(*list, 1);
				t = moving_enemy_left(list);
			}
			else
			{
				list->enemy_pos = array_of_enemies(*list, 1);
				t = moving_enemy_right(list);
			}
			if (t == 1)
				s++;
		}
		j = j % 3;
	

	return 0;
}
int moving_enemy_left(t_list *list)
{
	static int x = 0;
	int t = 0;

		if (list->enemy_pos[x][0] == -1)
		{
			x = 0;
			t = 0;
			list->enemy_pos = array_of_enemies(*list, 1);
		}
		if (list->array[list->enemy_pos[x][0]][list->enemy_pos[x][1] -1] == '0')
		{
			mlx_put_image_to_window(list->mlx, list->mlx_win, list->img_enemy, (list->enemy_pos[x][1] -1)*64, list->enemy_pos[x][0]*64);
			mlx_put_image_to_window(list->mlx, list->mlx_win, list->img_floor, list->enemy_pos[x][1]*64, list->enemy_pos[x][0]*64);
			list->array[list->enemy_pos[x][0]][list->enemy_pos[x][1] -1] = 'N';
			list->array[list->enemy_pos[x][0]][list->enemy_pos[x][1]] = '0';
		}
		else if (list->array[list->enemy_pos[x][0]][list->enemy_pos[x][1] -3] == 'N' )
		{
			return 1;	
		}
		else if (list->array[list->enemy_pos[x][0]][list->enemy_pos[x][1] - 1] == 'P' )
		{
			displaying_you_died(list);
			return -1;	
		}
		else
		{
			t++;
			if (t == list->enemies)
				return t;
		}
		x++;

	
	return t;
}
int moving_enemy_right(t_list *list)
{
	static int x = 0;
	int t = 0;
		if (list->enemy_pos[x][0] == -1)
		{
			x = 0;
			t = 0;
			list->enemy_pos = array_of_enemies(*list, 1);
		}
		if (list->array[list->enemy_pos[x][0]][list->enemy_pos[x][1] +1] == '0')
		{
			mlx_put_image_to_window(list->mlx, list->mlx_win, list->img_enemy, (list->enemy_pos[x][1] +1)*64, list->enemy_pos[x][0]*64);
			mlx_put_image_to_window(list->mlx, list->mlx_win, list->img_floor, list->enemy_pos[x][1]*64, list->enemy_pos[x][0]*64);
			list->array[list->enemy_pos[x][0]][list->enemy_pos[x][1] +1] = 'N';
			list->array[list->enemy_pos[x][0]][list->enemy_pos[x][1]] = '0';
		}
		else if (list->array[list->enemy_pos[x][0]][list->enemy_pos[x][1] +3] == 'N' )
			x++;
		else if (list->array[list->enemy_pos[x][0]][list->enemy_pos[x][1] +1] == 'P')
		{
			displaying_you_died(list);
			return -1;
		}	
		else
		{
			t++;
			if (t == list->enemies )
			{
				printf("%c \n", list->array[list->enemy_pos[x][0]][list->enemy_pos[x][1] +1]);
				return t;
			}
		}
		x++;
	
	return t;
}
int displaying_img(t_list list)
{
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
	list.water_img[0] = mlx_xpm_file_to_image(list.mlx, "1_water.xpm", &list.img_width, &list.img_height);
	list.water_img[1] = mlx_xpm_file_to_image(list.mlx, "2_water.xpm", &list.img_width, &list.img_height);
	list.water_img[2] = mlx_xpm_file_to_image(list.mlx, "3_water.xpm", &list.img_width, &list.img_height);
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
				// mlx_put_image_to_window(list.mlx, list.mlx_win, list.water_img[2], list.position_y*64, list.position_x*64);
				
				
				
				// list.array_collectibles = 0;
			
				// static int  i = 0;
				// i = (i+1) % 3;
				//displaying_sprite(list);
				
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
	
	
	//mlx_loop_hook(list.mlx, &moving_enemy, &list);
	mlx_loop_hook(list.mlx, &displaying_sprite, &list);
	mlx_hook(list.mlx_win, 2, 1<<0, moving_player, &list);
	mlx_loop(list.mlx);
	
	return 0;
}