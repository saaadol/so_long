#include "get_next_line.h"
#include "so_long.h"

int **array_of_enemies(t_list list, int flag)
{
	int i;
	int **list_of_collectibles;
	int *array;
	
	i = 0;
	list_of_collectibles = calloc(sizeof(int *), list.enemies + 2);
	if(!list_of_collectibles)
		return 	NULL;
	while (i < list.enemies+1)
		list_of_collectibles[i++] = calloc(sizeof(int), 2);
	array = searching_for_enemies(list, flag,0);
	i =0;
	while (1)
	{
		list_of_collectibles[i][0] = array[0];
		list_of_collectibles[i][1] = array[1];
		free(array);
		if(list_of_collectibles[i][0] == -1)
		{
			list_of_collectibles[i + 1] = NULL;
			break;
		}
		array = searching_for_enemies(list, 0,4);
		i++;
	}
	return list_of_collectibles;
}

int *whiling_over_array_for_enemies(t_list list, int *x, int *y ,int *array)
{
	while (list.array[*x])
	{
		while(list.array[*x][*y])
		{
			if (list.array[*x][*y] == 'N')
			{
				array[0] = *x;
				array[1] = *y;
				(*y)++;
				return array;
			}
			(*y)++;
		}
		*y = 0;
		(*x)++;
	}
	if ((*x)-1 == list.rows)
	{
		array[0] = -1;
		array[1] = -1;
		return array;
	}
	return 0;
}
int *searching_for_enemies(t_list list,int flag, int flag1)
{
	int *array;
	static int x;
 	static int y;
	if (flag1 == 0 || flag == 1)
	{
		x = 0;
		y = 0;
	}
	array = calloc(sizeof(int), 2);
	if(!array)
		return(0);
	array = whiling_over_array_for_enemies(list,  &x, &y, array);
	if (array != 0)
		return (array);
	return (free(array), NULL);
}