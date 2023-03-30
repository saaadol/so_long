/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_mandatory.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souledla <souledla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:12:38 by souledla          #+#    #+#             */
/*   Updated: 2023/03/30 05:48:17 by souledla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"

void	error_joined(char *joined)
{
	if (!joined)
	{
		perror("No such map");
		exit(1);
	}
}

void	error_borders(void)
{
	perror("Invalid borders");
	exit(1);
}

void	main_util(t_list *list, char *joined)
{
	int	i;

	i = 0;
	check_collectibles(joined);
	check_startpoint_exit(joined);
	checking_other_characters_mandatory(joined);
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
	list ->flagingo = 0;
	displaying_img_mandatory(*list);
	while (list->array[i])
		free(list->array[i++]);
	free(list->array);
	i = 0;
	while (list->collectibles_pos[i])
		i++;
	ft_frees(list->collectibles_pos, i);
}

char	*filling_the_map(int fd, char *buffer, char *joined, t_list *list)
{
	while (1)
	{
		buffer = get_next_line(fd);
		if (!buffer)
			break ;
		if (buffer[0] != '1' || buffer[ft_strlen(buffer) - 2] != '1')
			error_borders();
		if (!ft_strchr(buffer, '\n'))
		{
			checking_last_wall(buffer);
			joined = ft_strjoin(joined, buffer);
			free(buffer);
			break ;
		}
		joined = ft_strjoin(joined, buffer);
		free(buffer);
		list->rows++;
	}
	return (joined);
}

// int	main(int ac, char **av)
// {
// 	t_list	list;
// 	char	*buffer;
// 	char	*joined;
// 	int		fd;

// 	fd = checking_ber_extension(ac, av[1]);
// 	checking_files_permissions();
// 	joined = get_next_line(fd);
// 	error_joined(joined);
// 	list.columns = ft_strlen(joined) - 1;
// 	list.rows = 1;
// 	checking_first_wall(joined);
// 	joined = filling_the_map(fd, buffer, joined, &list);
// 	main_util(&list, joined);
// }
