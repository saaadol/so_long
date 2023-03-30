/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souledla <souledla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 08:00:27 by souledla          #+#    #+#             */
/*   Updated: 2023/03/30 08:17:21 by souledla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdio.h>
# include <mlx.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "get_next_line.h"

typedef struct t_list
{
	int		flagingo;
	int		coin;
	int		img_width;
	int		img_height;
	int		*array_collectibles;
	int		position_x;
	int		position_y;
	int		**collectibles_pos;
	int		**enemy_pos;
	int		enemies;
	int		flag;
	int		player_x;
	int		player_y;
	int		rows;
	int		columns;
	void	*mlx;
	void	*img;
	void	*img_wall;
	void	*img_floor;
	void	*img_soil;
	void	*img_you_died;
	void	*water_img[3];
	void	*img_water_2;
	void	*img_water_3;
	void	*img_y;
	void	*img_o;
	void	*img_u;
	void	*img_s;
	void	*img_c;
	void	*img_k;
	void	*img_castle;
	void	*img_water;
	void	*img_enemy;
	void	*img_tree;
	void	*img_sky;
	void	*mlx_win;
	char	*img_path;
	char	**array;

}	t_list;
void	displaying_you_died(t_list *list);
void	locating_start_point(char **array, int *i, int *j);
void	logic2_util(t_list *list);
void	checking_last_wall(char *buffer);
void	checking_other_characters(char *array);
void	checking_size_map(char **array, t_list list);
void	checking_valid_path(char **array);
void	allocating_enemies(t_list list, int ***list_of_collectibles);
void	filling_map_with_x(char **array, int i, int j);
void	locating_end_point(char **array, int *i, int *j);
void	locating_start_point(char **array, int *i, int *j);
void	check_startpoint_exit(char *buffer);
void	check_collectibles(char *buffer);
int		displaying_img(t_list list);
int		moving_player(int keycode, t_list *list);
int		move_up(t_list *list, int counter);
int		move_up_mandatory(t_list *list, int counter);
int		move_down(t_list *list, int counter);
int		move_down_mandatory(t_list *list, int counter);
int		move_left(t_list *list, int counter);
int		move_left_mandatory(t_list *list, int counter);
int		move_right(t_list *list, int counter);
int		move_right_mandatory(t_list *list, int counter);
int		displaying_sprite(t_list *list);
int		*searching_for_collectibles(t_list list, int flag);
int		**array_of_collectibles(t_list list);
int		counting_enemies(char **buffer);
int		**array_of_enemies(t_list list, int flag);
int		*searching_for_enemies(t_list list, int flag, int flag1);
int		moving_enemy(t_list *list);
int		moving_enemy_left(t_list *list);
int		moving_enemy_right(t_list *list);
int		displaying_img_mandatory(t_list list);
int		moving_player_mandatory(int keycode, t_list *list);
int		displaying_img_mandatory(t_list list);
int		move_up_bonus(t_list *list, int counter);
int		move_down_bonus(t_list *list, int counter);
int		move_left_bonus(t_list *list, int counter);
int		move_right_bonus(t_list *list, int counter);
int		**array_of_collectibles(t_list list);
int		counting_collectibles(char **buffer);
int		closing_window(t_list *list);
int		*moving_enemy_image(t_list *list, int flag);
int		checking_ber_extension(int ac, char *av);
int		checking_files_permissions(void);
int		moving_player_bonus(int keycode, t_list *list);
int		moving_enemy_left_util2(t_list *list, int x);
int		displaying_sprite_mandatory(t_list *list);
int		ft_strchr2(char *s, int c);
int		moving_enemy_right_util2(t_list *list, int x);
char	**ft_split(char const *s, char c);
char	**ft_free(char **str, size_t j);
void	executing_moving_player_mandatory(int keycode, t_list *list, int x);
char	*ft_join(char *s1, char *s2);
void	checking_first_wall(char *buffer);
void	assigning_values(t_list *list);
void	displaying_wall_util(t_list *list);
void	executing_moving_player(int keycode, t_list *list, int x);
char	*filling_the_map(int fd, char *buffer, char *joined, t_list *list);
void	ft_frees(int **str, size_t j);
void	check_enemies(char *buffer);
void	assigning_values_displaying_you_died(t_list *list);
void	move_up_mandatory_util(t_list *list, int *counter, int *x);
void	move_down_mandatory_util(t_list *list, int *counter, int *x);
void	move_right_mandatory_util(t_list *list, int *counter, int *x);
void	move_left_mandatory_util(t_list *list, int *counter, int *x);
void	executing_loops(t_list *list);
void	reseting_flag(int *a, int *b, int array[], int flag);
void	logic(int *s, int *k);
void	logic2(int *t, t_list *list, int k, int *s);
void	reseting_flag_mandatory(int array[], int flag);
void	error_borders(void);
void	error_joined(char *joined);
void	checking_other_characters_mandatory(char *array);
void	move_left_mandatory_util_util(t_list *list, int *counter, int *x);
void	move_down_mandatory_util_util(t_list *list, int *counter, int *x);
void	move_right_mandatory_util_util(t_list *list, int *counter, int *x);
void	move_up_mandatory_util_util(t_list *list, int *counter, int *x);
size_t	ft_count_word(char const *s, char c);
size_t	ft_strlen_checker(char const *s, char c);
void	checking_if_collectibles_still_there(char **array);
void	assigning_values_displaying_you_died_util(t_list *list);
void	moving_enemy_right_util(t_list *list, int x);
void	moving_enemy_left_util(t_list *list, int *x);
void	moving_enemy_left_util3(t_list *list, int x);
char	*ft_itoa(int c1);
char	**ft_free(char **str, size_t j);
#endif
