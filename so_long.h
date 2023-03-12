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
	int position_x;
	int position_y;
	char *img_path;
} t_list;
void displaying_img(t_list list);
int moving_player(int keycode, t_list *list);
int move_up(t_list *list,int counter, int *flag);
int move_down(t_list *list,int counter, int *flag);
int move_left(t_list *list,int counter, int *flag);
int move_right(t_list *list,int counter, int *flag);
void displaying_you_died(t_list *list);
#endif
