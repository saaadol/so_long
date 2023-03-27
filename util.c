#include "so_long.h"
#include "get_next_line.h"
void reseting_flag(int *a, int *b, int array[], int flag)
{
	if (flag == 0)
	{
		*a = 0;
		*b = 0;
		array[0] = 0;
		array[1] = 0;
	}
}
void logic(int *s, int *k)
{
	if ((*s) == 10)
	{
		if (*k == 0)
			*k = 1;
		else
			*k = 0;
		*s = 0;
	}
}
void logic2(int *t, t_list *list, int k, int *s)
{
	int i;
	if (*t == -1)
	{
		i = 0;
		while (i < list->enemies + 2)
			free(list->enemy_pos[i++]);
		free(list->enemy_pos);
		return ;
	}
	if (k == 0)
	{
		list->enemy_pos = array_of_enemies(*list, 1);
		*t = moving_enemy_left(list);
		i =0;
		while (i < list->enemies + 2)
			free(list->enemy_pos[i++]);
		free(list->enemy_pos);
	}
	else
	{
		list->enemy_pos = array_of_enemies(*list, 1);
		*t = moving_enemy_right(list);
		i = 0;
		while (i < list->enemies + 2)
			free(list->enemy_pos[i++]);
		free(list->enemy_pos);
	}
	if (*t == 1)
		(*s)++;
}
int *moving_enemy_image(t_list *list, int flag)
{
	static int array[2];
	static int s;
	static int k;
	int t;
	reseting_flag(&s, &k, &array[2],flag);
	array[0] = (array[0]+1) % 3;
	logic(&s, &k);
	if (!array[0])
	{
		array[1]++;
		logic2(&t, list, k, &s);
	}
	array[1] = array[1] % 3;
	list->flagingo = 1;
	return (array);
}

int displaying_sprite(t_list *list)
{
		static int *array;
		int x;
		int t;

		x = 0;
		array = moving_enemy_image(list, list->flagingo);
		while (list->collectibles_pos[x])
		{
			if(list->collectibles_pos[x][0] == -1 && list->collectibles_pos[x][1] == -1)
				x++;
			if	(list->collectibles_pos[x])
			{
				mlx_put_image_to_window(list->mlx, list->mlx_win, list->water_img[array[1]], list->collectibles_pos[x][1] * 64, list->collectibles_pos[x][0] * 64);
				x++;
			}
		}
	return 0;
}
int moving_enemy_left(t_list *list)
{
	static int x = 0;
	int t = 0;
	int i = 0;
		if (list->enemy_pos[x][0] == -1)
		{
			x = 0;
			t = 0;
			i = 0;
			while (i < list->enemies + 2)
				free(list->enemy_pos[i++]);
			free(list->enemy_pos);
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
			i = 0;
			list->flag = 1;
			displaying_you_died(list);
			return -1;	
		}
		else
		{
			t++;
			if (t == list->enemies)
			{
				return t;
			}
		}
		x++;
	return t;
}
int moving_enemy_right(t_list *list)
{
	static int x = 0;
	int t = 0;
	int i = 0;
		if (list->enemy_pos[x][0] == -1)
		{ 
			x = 0;
			t = 0;
			i = 0;
			while (i < list->enemies + 2)
				free(list->enemy_pos[i++]);
			free(list->enemy_pos);
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
		{
			x++;
		}
		else if (list->array[list->enemy_pos[x][0]][list->enemy_pos[x][1] +1] == 'P')
		{
			list->flag = 1;
			displaying_you_died(list);
			return -1;	
		}	
		else
		{
			
			t++;
			if (t == list->enemies)
			{
				return t;
			}
		}
		x++;	
	return t;
}
