/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus_main_util4.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souledla <souledla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 16:40:26 by souledla          #+#    #+#             */
/*   Updated: 2023/03/28 16:50:15 by souledla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"

void	displaying_you_died(t_list *list)
{
	list->position_y = list->columns / 2;
	list->position_x = (list->rows + 1) / 2;
	assigning_values_displaying_you_died(list);
	while (list->array[list->position_x])
	{
		list->position_y = 0;
		while (list->array[list->position_x][list->position_y])
		{
			assigning_values_displaying_you_died_util(list);
			list->position_y++;
		}
		list->position_x++;
	}	
}
