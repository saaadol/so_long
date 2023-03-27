#include "so_long.h"
#include "get_next_line.h"
void move_right_mandatory_util(t_list *list, int *counter, int *x)
{
	if (list->array[list->position_x][list->position_y+1] == '0' || list->array[list->position_x][list->position_y+1] == 'C')
	{
		if(list->array[list->position_x][list->position_y+1] == 'C')
		{
			mlx_put_image_to_window(list->mlx, list->mlx_win, list->img_floor, (list->position_y+1)*64, list->position_x*64);
			while (list->collectibles_pos[*x])
			{
				if (list->collectibles_pos[*x][0] == list->position_x && list->collectibles_pos[*x][1] == list->position_y+1)
				{
					list->collectibles_pos[*x][0]= -1;
					list->collectibles_pos[*x][1]= -1;
				}
				(*x)++;
			}
			(*counter)++;
		}
		mlx_put_image_to_window(list->mlx, list->mlx_win, list->img, (list->position_y+1)*64, list->position_x*64);
		mlx_put_image_to_window(list->mlx, list->mlx_win, list->img_floor, list->position_y*64, list->position_x*64);
		list->array[list->position_x][list->position_y+1] = 'P';
		list->array[list->position_x][list->position_y] = '0';
	}
}
int move_right_mandatory(t_list *list, int counter)
{
	list ->position_x = 0;
	list ->position_y = 0;
	int x = 0;
	locating_Start_point(list->array, &list->position_x, &list->position_y);
	move_right_mandatory_util(list, &counter, &x);
	if (list->array[list->position_x ][list->position_y+1] == 'E')
	{
		if (counter == list->coin)
		{
			mlx_destroy_window(list->mlx,list->mlx_win);
			exit(1);
		}
	}
	return counter;
}
void move_left_mandatory_util(t_list *list, int *counter, int *x)
{
	if (list->array[list->position_x][list->position_y-1] == '0' || list->array[list->position_x][list->position_y-1] == 'C')
	{
		if(list->array[list->position_x][list->position_y-1] == 'C')
		{
			mlx_put_image_to_window(list->mlx, list->mlx_win, list->img_floor, (list->position_y-1)*64, list->position_x*64);
			while (list->collectibles_pos[*x])
			{
				if (list->collectibles_pos[*x][0] == list->position_x && list->collectibles_pos[*x][1] == list->position_y-1)
				{
					list->collectibles_pos[*x][0]= -1;
					list->collectibles_pos[*x][1]= -1;
				}
				(*x)++;
			}
			(*counter)++;
		}
		mlx_put_image_to_window(list->mlx, list->mlx_win, list->img, (list->position_y-1)*64, list->position_x*64);
		mlx_put_image_to_window(list->mlx, list->mlx_win, list->img_floor, list->position_y*64, list->position_x*64);
		list->array[list->position_x][list->position_y-1] = 'P';
		list->array[list->position_x][list->position_y] = '0';
	}
} 
int move_left_mandatory(t_list *list,int counter)
{
	list ->position_x = 0;
	list ->position_y = 0;
	int x = 0;
	locating_Start_point(list->array, &list->position_x, &list->position_y);
	move_left_mandatory_util(list, &counter, &x);
	if (list->array[list->position_x][list->position_y-1] == 'E')
	{
		if (counter == list->coin)
		{
			mlx_destroy_window(list->mlx,list->mlx_win);
			exit(1);
		}
	}
	return counter;
}
void move_down_mandatory_util(t_list *list, int *counter, int *x)
{
	if (list->array[list->position_x + 1][list->position_y] == '0' || list->array[list->position_x+1][list->position_y] == 'C')
	{
		if(list->array[list->position_x+1][list->position_y] == 'C')
		{
			mlx_put_image_to_window(list->mlx, list->mlx_win, list->img_floor, list->position_y*64, (list->position_x+1)*64);
			while (list->collectibles_pos[*x])
			{
				if (list->collectibles_pos[*x][0] == list->position_x+1 && list->collectibles_pos[*x][1] == list->position_y)
				{
					list->collectibles_pos[*x][0]= -1;
					list->collectibles_pos[*x][1]= -1;
				}
				(*x)++;
			}
			(*counter)++;
		}
		mlx_put_image_to_window(list->mlx, list->mlx_win, list->img, list->position_y*64, (list->position_x+1)*64);
		mlx_put_image_to_window(list->mlx, list->mlx_win, list->img_floor, list->position_y*64, list->position_x*64);
		list->array[list->position_x + 1][list->position_y] = 'P';
		list->array[list->position_x][list->position_y] = '0';
	}
}

int move_down_mandatory(t_list *list,int counter)
{
	list ->position_x = 0;
	list ->position_y = 0;
	int x = 0;
	void *tmp;
	locating_Start_point(list->array, &list->position_x, &list->position_y);
	move_down_mandatory_util(list, &counter, &x);
	if (list->array[list->position_x + 1][list->position_y] == 'E')
	{
		if (counter == list->coin)
		{
			mlx_destroy_window(list->mlx,list->mlx_win);
			exit(1);
		}
	}
	return counter;
}
void move_up_mandatory_util(t_list *list, int *counter, int *x)
{
	if (list->array[list->position_x - 1][list->position_y] == '0' || list->array[list->position_x-1][list->position_y] == 'C')
	{
		if(list->array[list->position_x-1][list->position_y] == 'C')
		{
			mlx_put_image_to_window(list->mlx, list->mlx_win, list->img_floor, list->position_y*64, (list->position_x-1)*64);
			while (list->collectibles_pos[*x])
			{
				if (list->collectibles_pos[*x][0] == list->position_x-1 && list->collectibles_pos[*x][1] == list->position_y)
				{
					list->collectibles_pos[*x][0]= -1;
					list->collectibles_pos[*x][1]= -1;
				}
				(*x)++;
			}
			(*counter)++;
		}
		mlx_put_image_to_window(list->mlx, list->mlx_win, list->img, list->position_y*64, (list->position_x-1)*64);
		mlx_put_image_to_window(list->mlx, list->mlx_win, list->img_floor, list->position_y*64, list->position_x*64);
		list->array[list->position_x - 1][list->position_y] = 'P';
		list->array[list->position_x][list->position_y] = '0';
	}
}
int move_up_mandatory(t_list *list,int counter)
{
	list ->position_x = 0;
	list ->position_y = 0;
	int x = 0;
	locating_Start_point(list->array, &list->position_x, &list->position_y);
	move_up_mandatory_util(list, &counter, &x);
	if (list->array[list->position_x - 1][list->position_y] == 'E')
	{
		if (counter == list->coin)
		{
			mlx_destroy_window(list->mlx,list->mlx_win);
			exit(1);
		}
	}
	return counter;
}