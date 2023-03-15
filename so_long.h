#ifndef SO_LONG_H
#define SO_LONG_H
# include <stdio.h>
# include <mlx.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "get_next_line.h"

typedef struct t_list
{
	char **array; 
	int coin;
	int player_x;
	int player_y;
	int rows;
	int columns;
	void *mlx;
	void *img;
	void *img_wall;
	void *img_floor;
	void *img_soil;
	void *img_you_died;
	void *water_img[3];
	void *img_water_2;
	void *img_water_3;
	void *img_Y;
	void *img_O;
	void *img_U;
	void *img_S;
	void *img_C;
	void *img_K;
	void *img_castle;
	void *img_water;
	void *img_enemy;
	void *img_tree;
	void *img_sky;
	void *mlx_win;
	int img_width;
	int img_height;
	int *array_collectibles;
	int position_x;
	int position_y;
	char *img_path;
	int **collectibles_pos;
} t_list;
int displaying_img(t_list list);
int moving_player(int keycode, t_list *list);
int move_up(t_list *list,int counter, int *flag);
int move_down(t_list *list,int counter, int *flag);
int move_left(t_list *list,int counter, int *flag);
int move_right(t_list *list,int counter, int *flag);
void displaying_you_died(t_list *list);
int displaying_sprite(t_list *list);
int *searching_for_collectibles(t_list list);
int **array_of_collectibles(t_list list);
void locating_Start_point(char **array, int *i, int *j);
char	*ft_itoa(int c1);
#endif
