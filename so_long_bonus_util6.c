/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus_util6.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souledla <souledla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 10:58:31 by souledla          #+#    #+#             */
/*   Updated: 2023/03/30 07:14:15 by souledla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"

int	*moving_enemy_image(t_list *list, int flag)
{
	static int	array[2];
	static int	s;
	static int	k;
	int			t;

	reseting_flag(&s, &k, &array[2], flag);
	array[0] = (array[0] + 1) % 3;
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

int	displaying_sprite(t_list *list)
{
	int				x;
	int				t;
	static int		*array;

	x = 0;
	array = moving_enemy_image(list, list->flagingo);
	while (list->collectibles_pos[x])
	{
		if (list->collectibles_pos[x][0] == -1
		&& list->collectibles_pos[x][1] == -1)
			x++;
		if (list->collectibles_pos[x])
		{
			mlx_put_image_to_window(list->mlx, list->mlx_win,
				list->water_img[array[1]],
				list->collectibles_pos[x][1] * 64,
				list->collectibles_pos[x][0] * 64);
			x++;
		}
	}
	return (0);
}

void	logic2(int *t, t_list *list, int k, int *s)
{
	if (*t == -1)
	{
		logic2_util(list);
		return ;
	}
	if (k == 0)
	{
		list->enemy_pos = array_of_enemies(*list, 1);
		*t = moving_enemy_left(list);
		logic2_util(list);
	}
	else
	{
		list->enemy_pos = array_of_enemies(*list, 1);
		*t = moving_enemy_right(list);
		logic2_util(list);
	}
	if (*t == 1)
		(*s)++;
}

void	check_enemies(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == 'N')
			return ;
		i++;
	}
	write(1, "No enemies\n", 11);
	exit(1);
}
