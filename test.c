/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souledla <souledla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:59:42 by souledla          #+#    #+#             */
/*   Updated: 2023/03/30 05:53:29 by souledla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <mlx.h>
#include "so_long.h"

void	main_bonus_util_util(t_list *list)
{
	int	i;

	i = 0;
	while (list->array[i])
		free(list->array[i++]);
	free(list->array);
	while (list->collectibles_pos[i])
		i++;
	ft_frees(list->collectibles_pos, i);
	i = 0;
	while (list->enemy_pos[i])
		i++;
	ft_frees(list->enemy_pos, i);
}

void	main_bonus_util(t_list *list, char *joined)
{
	check_collectibles(joined);
	check_enemies(joined);
	check_startpoint_exit(joined);
	checking_other_characters(joined);
	list->array = ft_split(joined, '\n');
	checking_size_map(list->array, *list);
	list->player_x = 0;
	list->player_y = 0;
	locating_start_point(list->array, &list->player_x, &list->player_y);
	filling_map_with_x(list->array, list->player_x, list->player_y);
	checking_valid_path(list->array);
	list->array = ft_split(joined, '\n');
	list->coin = counting_collectibles(list->array);
	list->collectibles_pos = array_of_collectibles(*list);
	list->coin = counting_collectibles(list->array);
	list->enemies = counting_enemies(list->array);
	list->enemy_pos = array_of_enemies(*list, 0);
	if (!list->enemy_pos)
		return ;
	list->flag = 0;
	displaying_img(*list);
	main_bonus_util_util(list);
}

int	checking_ber_extension(int ac, char *av)
{
	int	fd;
	int	len;

	if (ac > 2)
	{
		write(1, "More arguments than expected\n", 29);
		exit(1);
	}
	fd = open(av, O_RDWR, 0777);
	if (fd == -1)
	{
		write(1, "No such file\n", 13);
		exit(1);
	}
	len = ft_strlen(av);
	if (av[len - 1] != 'r' && av[len - 2] != 'e' && av[len - 3]
		!= 'b' && av[len - 4] != '.' && av[0] != '.')
	{
		write(1, "File with extension unexpected\n", 31);
		exit(1);
	}
	return (fd);
}

int	checking_files_permissions(void)
{
	if (open("1_water.xpm", O_RDONLY, 077) == -1
		|| open("2_water.xpm", O_RDONLY, 077) == -1
		|| open("3_water.xpm", O_RDONLY, 077) == -1)
		return (write(1, "Permission denied or file deleted\n", 35), exit(1), 0);
	if (open("castle.xpm", O_RDONLY, 077) == -1
		|| open("enemy.xpm", O_RDONLY, 077) == -1
		|| open("floor.xpm", O_RDONLY, 077) == -1)
		return (write(1, "Permission denied or file deleted\n", 35), exit(1), 0);
	if (open("sky.xpm", O_RDONLY, 077) == -1
		|| open("trees.xpm", O_RDONLY, 077) == -1
		|| open("water.xpm", O_RDONLY, 077) == -1)
		return (write(1, "Permission denied or file deleted\n", 35), exit(1), 0);
	if (open("Y.xpm", O_RDONLY, 077) == -1
		|| open("O.xpm", O_RDONLY, 077) == -1
		|| open("U.xpm", O_RDONLY, 077) == -1)
		return (write(1, "Permission denied or file deleted\n", 35), exit(1), 0);
	if (open("S.xpm", O_RDONLY, 077) == -1
		|| open("C.xpm", O_RDONLY, 077) == -1
		|| open("K.xpm", O_RDONLY, 077) == -1)
		return (write(1, "Permission denied or file deleted\n", 35), exit(1), 0);
	if (open("player2_.xpm", O_RDONLY, 077) == -1
		|| open("soil.xpm", O_RDONLY, 077) == -1)
		return (write(1, "Permission denied or file deleted\n", 35), exit(1), 0);
	return (0);
}

int	main(int ac, char *av[])
{
	t_list	list;
	char	*buffer;
	char	*joined;
	int		fd;

	fd = checking_ber_extension(ac, av[1]);
	checking_files_permissions();
	joined = get_next_line(fd);
	error_joined(joined);
	list.columns = ft_strlen(joined) - 1;
	printf("%d", list.columns);
	list.rows = 1;
	checking_first_wall(joined);
	joined = filling_the_map(fd, buffer, joined, &list);
	main_bonus_util(&list, joined);
}
