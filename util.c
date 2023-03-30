/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souledla <souledla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 09:12:44 by souledla          #+#    #+#             */
/*   Updated: 2023/03/30 08:18:36 by souledla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"

void	reseting_flag(int *a, int *b, int array[], int flag)
{
	if (flag == 0)
	{
		*a = 0;
		*b = 0;
		array[0] = 0;
		array[1] = 0;
	}
}

void	logic(int *s, int *k)
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

void	logic2_util(t_list *list)
{
	int	i;

	i = 0;
	while (i < list->enemies + 2)
		free(list->enemy_pos[i++]);
	free(list->enemy_pos);
}

int	moving_enemy_left(t_list *list)
{
	int			t;
	int			i;
	static int	x = 0;

	t = 0;
	moving_enemy_left_util(list, &x);
	if (moving_enemy_left_util2(list, x) == 1)
		return (1);
	else if (moving_enemy_left_util2(list, x) == -1)
		return (-1);
	else if (list->array[list->enemy_pos[x][0]]
		[list->enemy_pos[x][1] -1] == '0')
		moving_enemy_left_util3(list, x);
	else
	{
		if (t++ == list->enemies)
			return (t);
	}
	x++;
	return (t);
}

int	moving_enemy_right(t_list *list)
{
	int			t;
	int			i;
	static int	x = 0;

	t = 0;
	moving_enemy_left_util(list, &x);
	if (moving_enemy_right_util2(list, x) == -1)
		return (-1);
	else if (list->array[list->enemy_pos[x][0]]
	[list->enemy_pos[x][1] +1] == '0')
		moving_enemy_right_util(list, x);
	else if (list->array[list->enemy_pos[x][0]]
	[list->enemy_pos[x][1] +3] == 'N' )
		x++;
	else
	{
		if (t++ == list->enemies)
			return (t);
	}
	x++;
	return (t);
}
