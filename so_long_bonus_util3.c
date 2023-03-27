#include "so_long.h"
#include "get_next_line.h"
int **array_of_collectibles(t_list list)
{
	int i;
	int x;
	int **list_of_collectibles;
	int *array;
	
	x = 0;	
	i = 0;
	list_of_collectibles = calloc(sizeof(int *), list.coin + 1);
	list_of_collectibles[list.coin + 1] = 0;
	while (i < list.coin)
		list_of_collectibles[i++] = calloc(sizeof(int), 2);
	array = searching_for_collectibles(list, 0);
	while (1)
	{
		if(array[0] == -1)
			break;
		list_of_collectibles[x][0] = array[0];
		list_of_collectibles[x][1] = array[1];
		free(array);
		array = searching_for_collectibles(list,4);
		x++;
	}
	free(array);
	return list_of_collectibles;
}
int *whiling_over_array_for_collectibles(t_list list, int *x, int *y ,int *array)
{
	while (list.array[*x])
	{
		while(list.array[*x][*y])
		{
			if (list.array[*x][*y] == 'C')
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
int *searching_for_collectibles(t_list list, int flag)
{
	int *array;
	static int x;
 	static int y;

	if (flag == 0)
	{
		x = 0;
		y = 0;
	}
	array = calloc(sizeof(int), 2);
	array = whiling_over_array_for_collectibles(list,  &x, &y, array);
	if (array != 0)
		return (array);
	return 0;
}