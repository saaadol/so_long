void main_bonus_util(t_list *list, char *joined)
{
	int i = 0;
	check_collectibles(joined);
	check_startpoint_exit(joined);
	checking_other_characters(joined);
	list->array =  ft_split(joined, '\n');
	checking_size_map(list->array, *list);
	list->player_x = 0;
	list->player_y = 0;
	locating_Start_point(list->array, &list->player_x, &list->player_y);
	filling_map_with_x(list->array, list->player_x, list->player_y);
	checking_valid_path(list->array);
	list->array = ft_split(joined, '\n');
	list->coin = counting_collectibles(list->array);
	list->collectibles_pos = array_of_collectibles(*list);
	list->coin = counting_collectibles(list->array);
	list->enemies = counting_enemies(list->array);
	list->enemy_pos = array_of_enemies(*list,0);
	list->flag = 0;
	displaying_img(*list);
	while (list->array[i])
		free(list->array[i++]);
	free(list->array);
	i = 0;
	while (list->collectibles_pos[i])
		i++;
	ft_frees(list->collectibles_pos, i);
	i = 0;
	while (list->enemy_pos[i])
		i++;
	ft_frees(list->enemy_pos, i);	

}
// int main()
// {
// 	t_list list;
// 	char *buffer;
// 	char *joined;

// 	int fd = open("maps", O_RDWR, 0777);
// 	joined = get_next_line(fd);
// 	error_joined(joined);
// 	list.columns = ft_strlen(joined) - 1;
// 	list.rows = 1;
// 	checking_first_wall(joined);
// 	joined = filling_the_map(fd, buffer, joined, &list); 
//  	main_bonus_util(&list, joined);
// 	// while(list.enemy_pos[i])
// 	// {
// 	// 	printf("(%d %d)\n", list.enemy_pos[i][0],list.enemy_pos[i][1]);
// 	// 	i++;
// 	// }
// 	// printf("%d", t[0]);
// 	// printf("%d", t[1]);
	
// 	// t = searching_for_collectibles(list);
// 	//printf("%d",t);
	
// 	//printf("hello");
// }
