#include "get_next_line.h"
#include <mlx.h>
#include "so_long.h"

char	*ft_join(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*p;

	i = 0;
	j = 0;
	if (!s2)
		return (NULL);
	p = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!p)
		return (NULL);
	while (s1[i])
	{
		p[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		p[i + j] = s2[j];
		j++;
	}
	p[i + j] = 0;
	return (s1 = NULL, p);
}
static size_t	ft_count_word(char const *s, char c)
{
	size_t	i;
	size_t	count;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		if (s[i] != '\0')
			count++;
		while (s[i] != '\0' && s[i] != c)
			i++;
	}
	return (count);
}

static size_t	ft_strlen_checker(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

char	**ft_free(char **str, size_t j)
{
	int	i;

	i = j;
	while (i >= 0)
	{
		if (i == 0)
		{
			free(str[i]);
			str[i] = 0;
			break ;
		}
		free(str[i]);
		str[i] = 0;
		i--;
	}
	free(str);
	str = 0;
	return (0);
}

static char	*ft_word(char const *s, char c)
{
	size_t	len_word;
	size_t	i;
	char	*word;

	i = 0;
	len_word = ft_strlen_checker(s, c);
	word = (char *)malloc(sizeof(char) * (len_word + 1));
	if (!word)
		return (0);
	while (i < len_word)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}



char	**ft_split(char const *s, char c)
{
	char	**str;
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	str = (char **)malloc(sizeof(char *) * (ft_count_word(s, c) + 1));
	if (!str)
		return (0);
	while (*s != '\0')
	{
		while (*s != '\0' && *s == c)
			s++;
		if (*s != '\0')
		{
			str[i] = ft_word(s, c);
			if (!(str[i]))
				return (ft_free(str, i));
			i++;
		}
		while (*s && *s != c)
			s++;
	}
	str[i] = 0;
	return (str);
}


int	ft_strchr2(char *s, int c)
{
	int	i;
	int	len;

	len = ft_strlen(s);
	i = 0;
	while (i <= len)
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (0);
}
void check_collectibles(char *buffer)
{
	int i = 0;
	while (buffer[i])
	{
		if (buffer[i] == 'C')
		 	return ;
		i++;
	}
	perror("No collectibles");
	exit(1);

}
int counting_collectibles(char **buffer)
{
	int counter = 0;
	int i = 0;
	int j = 0;
	while (buffer[i])
	{
		j = 0;
		while (buffer[i][j])
		{	
			if (buffer[i][j] == 'C')
				counter++;
			j++;
		}
			i++;
	}
	return counter;
}
void check_startpoint_exit(char *buffer)
{
	int i = 0;
	int counter1 = 0;
	int counter2 = 0;
	while (buffer[i])
	{
		if (buffer[i] == 'P')
			counter1++;
		else if (buffer[i] == 'E')
			counter2++;
		else if (counter1 > 1 || counter2 > 1)
			{
				perror("too many Exits | Start points");
				exit(1);
			}
		i++;
	}
}


// void checking_wall(char *buffer)
// {
// 	int i = 0;
// 	int len = ft_strlen(buffer);
// 	while (buffer[i] && i <= len -1)
// 	{
// 		if (buffer[i] != '1')
// 		{
// 			perror("No wall");
// 			exit(1);
// 		}
// 		 i++;
// 	}
// }
void locating_Start_point(char **array, int *i, int *j)
{
	while(array[*i])
	{
		*j = 0;
		while (array[*i][*j])
		{
			if (array[*i][*j] == 'P')
				return ;
			else if (array[*i][*j] == '\n')
				break;
			(*j)++;
		}
		(*i)++;
	} 
}
void locating_END_point(char **array, int *i, int *j)
{
	while(array[*i])
	{
		*j = 0;
		while (array[*i][*j])
		{
			if (array[*i][*j] == 'E')
				return ;
			else if (array[*i][*j] == '\n')
				break;
			(*j)++;
		}
		(*i)++;
	} 
}
void filling_map_with_x(char **array, int i, int j)
{
	if (array[i][j] == '1' || array[i][j] == 'E' || array[i][j] == 'x')
		return ;
	else if (array[i][j] == '0' || array[i][j] == 'P' || array[i][j] == 'C')
	{
		array[i][j] = 'x';
		filling_map_with_x(array, i + 1, j);
		filling_map_with_x(array, i - 1, j);
		filling_map_with_x(array, i, j + 1);
		filling_map_with_x(array, i, j - 1);
	}
}
void checking_valid_path(char **array)
{
	int i;
	int j;

	i = 0;
	j = 0;
	locating_END_point(array, &i, &j);
	if (array[i + 1][j] != 'x' && array[i - 1][j] != 'x' && array[i][j + 1] != 'x' && array[i][j - 1] != 'x')
	{
		perror("Invalid map");
		exit(1);
	}
	i = 0;
	j = 0;
	while (array[i])
	{
		j = 0;
		while (array[i][j])
		{
			if (array[i][j] == 'C')
			{
				perror("Collectible still there");
				exit(1);
			}
			j++;
		}
		i++;
	}
}
void checking_first_wall(char *buffer)
{
	int i = 0;
	int len = ft_strlen(buffer);
	int counter = 0;

	while (buffer[i] && i < len-1)
	{
		if (buffer[i] != '1' || buffer[len-1] != '\n')
		{
			perror("Invalid Wall");
			exit(1);
		}
		i++;
	}
}

void checking_last_wall(char *buffer)
{
	int i = 0;
	int len = ft_strlen(buffer);
	int counter = 0;

	while (buffer[i])
	{
		if (buffer[i] != '1')
		{
			perror("Invalid Wall");
			exit(1);
		}
		i++;
	}
}
void checking_other_characters(char *array)
{
	int i = 0;
	while (array[i])
	{
			if (array[i] != '\n' && array[i] != '1' && array[i] != '0' && array[i] != 'C' && array[i] != 'P' && array[i] != 'E' && array[i] != 'N')
			{	
				perror("Invalid character");
				exit(1);
			}
			i++;
		}
}

void checking_size_map(char **array, t_list list)
{
	int i = 0;
	while (array[i])
	{	
		if ((ft_strlen(array[i]) != list.columns))
		{
			perror("map not rectangular");
			exit(1);
		}
		i++;
	}
}

int moving_player(int keycode, t_list *list)
{
	static int counter = 0;
	static int flag = 0;
	if (keycode == 13 || keycode == 126)
	{
		int fd = open("moves1", O_CREAT | O_TRUNC| O_WRONLY, 0777);
		dup2(fd, 1);
		//printf("hello");
		counter = move_up(list, counter, &flag);
		printf("%d", counter);
	}
	else if (keycode == 1 || keycode == 125)
		counter = move_down(list, counter, &flag);
	else if (keycode == 0 || keycode == 123)
		{
			counter = move_left(list, counter, &flag);
		}
	else if (keycode == 2 || keycode == 124)
		counter = move_right(list, counter, &flag);
	else if (keycode == 53)
	{
		mlx_destroy_window(list->mlx,list->mlx_win)	;
		exit(1);
	}
	return(counter);
}

int move_up(t_list *list,int counter, int *flag)
{
	list ->position_x = 0;
	list ->position_y = 0;
	void *tmp;
	if (!flag)
		return 0;
	locating_Start_point(list->array, &list->position_x, &list->position_y);
	if (list->array[list->position_x - 1][list->position_y] == '0' || list->array[list->position_x-1][list->position_y] == 'C')
	{
		if(list->array[list->position_x-1][list->position_y] == 'C')
					{
						mlx_put_image_to_window(list->mlx, list->mlx_win, list->img_floor, list->position_y*64, (list->position_x-1)*64);
						counter++;
					}
		mlx_put_image_to_window(list->mlx, list->mlx_win, list->img, list->position_y*64, (list->position_x-1)*64);
		mlx_put_image_to_window(list->mlx, list->mlx_win, list->img_floor, list->position_y*64, list->position_x*64);
		list->array[list->position_x - 1][list->position_y] = 'P';
		list->array[list->position_x][list->position_y] = '0';
	}
	else if (list->array[list->position_x - 1][list->position_y] == 'E')
	{
		if (counter == list->coin)
		{
			mlx_destroy_window(list->mlx,list->mlx_win);
			exit(1);
		}
	}
	else if (list->array[list->position_x-1 ][list->position_y] == 'N')
	{
		*flag = 1;
		displaying_you_died(list);
	}
	return counter;
}
int move_down(t_list *list,int counter, int *flag)
{
	list ->position_x = 0;
	list ->position_y = 0;
	void *tmp;
	if (*flag == 1)
		return 0;
	locating_Start_point(list->array, &list->position_x, &list->position_y);
	if (list->array[list->position_x + 1][list->position_y] == '0' || list->array[list->position_x+1][list->position_y] == 'C')
	{
		if(list->array[list->position_x+1][list->position_y] == 'C')
		{
			mlx_put_image_to_window(list->mlx, list->mlx_win, list->img_floor, list->position_y*64, (list->position_x+1)*64);
			counter++;
		}
		mlx_put_image_to_window(list->mlx, list->mlx_win, list->img, list->position_y*64, (list->position_x+1)*64);
		mlx_put_image_to_window(list->mlx, list->mlx_win, list->img_floor, list->position_y*64, list->position_x*64);
		list->array[list->position_x + 1][list->position_y] = 'P';
		list->array[list->position_x][list->position_y] = '0';
	}
	else if (list->array[list->position_x + 1][list->position_y] == 'E')
	{
		if (counter == list->coin)
		{
			mlx_destroy_window(list->mlx,list->mlx_win);
			exit(1);
		}
	}
	else if (list->array[list->position_x+1][list->position_y] == 'N')
	{
		*flag = 1;
		displaying_you_died(list);
	}
	return counter;
}

int move_left(t_list *list,int counter, int *flag)
{
	list ->position_x = 0;
	list ->position_y = 0;
	void *tmp;
	locating_Start_point(list->array, &list->position_x, &list->position_y);
	if (*flag == 1)
		return -1;
	if (list->array[list->position_x][list->position_y-1] == '0' || list->array[list->position_x][list->position_y-1] == 'C')
	{
		if(list->array[list->position_x][list->position_y-1] == 'C')
		{
			mlx_put_image_to_window(list->mlx, list->mlx_win, list->img_floor, (list->position_y-1)*64, list->position_x*64);
			counter++;
		}
		mlx_put_image_to_window(list->mlx, list->mlx_win, list->img, (list->position_y-1)*64, list->position_x*64);
		mlx_put_image_to_window(list->mlx, list->mlx_win, list->img_floor, list->position_y*64, list->position_x*64);
		list->array[list->position_x][list->position_y-1] = 'P';
		list->array[list->position_x][list->position_y] = '0';
	}
	else if (list->array[list->position_x][list->position_y-1] == 'E')
	{
		if (counter == list->coin)
		{
			mlx_destroy_window(list->mlx,list->mlx_win);
			exit(1);
		}
	}
	else if (list->array[list->position_x ][list->position_y-1] == 'N')
	{
		*flag = 1;
		displaying_you_died(list);
	}
	return counter;
}
int move_right(t_list *list, int counter, int *flag)
{
	list ->position_x = 0;
	list ->position_y = 0;
	void *tmp;
	if (*flag == 1)
		return 0;
	locating_Start_point(list->array, &list->position_x, &list->position_y);
	if (list->array[list->position_x][list->position_y+1] == '0' || list->array[list->position_x][list->position_y+1] == 'C')
	{
		if(list->array[list->position_x][list->position_y+1] == 'C')
		{
			mlx_put_image_to_window(list->mlx, list->mlx_win, list->img_floor, (list->position_y+1)*64, list->position_x*64);
			counter++;
		}
		mlx_put_image_to_window(list->mlx, list->mlx_win, list->img, (list->position_y+1)*64, list->position_x*64);
		mlx_put_image_to_window(list->mlx, list->mlx_win, list->img_floor, list->position_y*64, list->position_x*64);
		list->array[list->position_x][list->position_y+1] = 'P';
		list->array[list->position_x][list->position_y] = '0';
	}
	else if (list->array[list->position_x ][list->position_y+1] == 'E')
	{
		if (counter == list->coin)
		{
			mlx_destroy_window(list->mlx,list->mlx_win);
			exit(1);
		}
	}
	else if (list->array[list->position_x ][list->position_y+1] == 'N')
	{
		*flag = 1;
		displaying_you_died(list);
	}

	return counter;
}
void displaying_you_died(t_list *list)
{


	list->position_y = list->columns  / 2;
	list->position_x = (list->rows + 1) / 2;
	list->array[list->position_x][list->position_y - 3] = 'Y';
	list->array[list->position_x][list->position_y - 2] = 'O';
	list->array[list->position_x][list->position_y - 1] = 'U';
	list->array[list->position_x][list->position_y+1] = 'S';
	list->array[list->position_x][list->position_y+2] = 'U';
	list->array[list->position_x][list->position_y+3] = 'c';
	list->array[list->position_x][list->position_y+4] = 'K';
	list->position_x = 0;
	list->position_y = 0;
	list->img_Y = mlx_xpm_file_to_image(list->mlx, "Y.xpm", &list->img_width, &list->img_height);
	list->img_O = mlx_xpm_file_to_image(list->mlx, "O.xpm", &list->img_width, &list->img_height);
	list->img_U = mlx_xpm_file_to_image(list->mlx, "U.xpm", &list->img_width, &list->img_height);
	list->img_S = mlx_xpm_file_to_image(list->mlx, "S.xpm", &list->img_width, &list->img_height);
	list->img_C = mlx_xpm_file_to_image(list->mlx, "C.xpm", &list->img_width, &list->img_height);
	list->img_K = mlx_xpm_file_to_image(list->mlx, "K.xpm", &list->img_width, &list->img_height);
	while (list->array[list->position_x])
	{
		list->position_y = 0;
		while (list->array[list->position_x][list->position_y])
		{
			if (list->array[list->position_x][list->position_y] == 'Y')
			{
				mlx_put_image_to_window(list->mlx, list->mlx_win, list->img_Y, list->position_y*64, list->position_x*64);
			}
			else if (list->array[list->position_x][list->position_y] == 'O')
			{
				mlx_put_image_to_window(list->mlx, list->mlx_win, list->img_O, list->position_y*64, list->position_x*64);
			}
			else if (list->array[list->position_x][list->position_y] == 'U')
			{
				mlx_put_image_to_window(list->mlx, list->mlx_win, list->img_U, list->position_y*64, list->position_x*64);
			}
			else if (list->array[list->position_x][list->position_y] == 'S')
			{
				mlx_put_image_to_window(list->mlx, list->mlx_win, list->img_S, list->position_y*64, list->position_x*64);
			}
			else if (list->array[list->position_x][list->position_y] == 'c')
			{
				mlx_put_image_to_window(list->mlx, list->mlx_win, list->img_C, list->position_y*64, list->position_x*64);
			}
			else if (list->array[list->position_x][list->position_y] == 'K')
			{
				mlx_put_image_to_window(list->mlx, list->mlx_win, list->img_K, list->position_y*64, list->position_x*64);
			}
		list->position_y++;
		}
		list->position_x++;

	}	
}
int main()
{
	t_list list;
	char **array;
	int fd = open("maps", O_RDWR, 0777);
	int i = 0;
	char *buffer;
	list.player_x = 0;
	list.player_y = 0;
	char *joined = get_next_line(fd);
	if (!joined)
	{
		perror("No such map");
		exit(1);
	}
	list.columns = ft_strlen(joined) - 1;
	list.rows = 1;
	checking_first_wall(joined);
	while(1)
	{
		buffer = get_next_line(fd);
		if (!buffer)
			break;
		if (buffer[0] != '1' || buffer[ft_strlen(buffer) - 2] != '1')
		{
			perror("Invalid borders");
			exit(1);
		} 
		if (!ft_strchr(buffer, '\n'))
		{
			checking_last_wall(buffer);
			joined = ft_join(joined, buffer);
			break;
		}
		joined = ft_join(joined, buffer);
		list.rows++;
	}
	check_collectibles(joined);
	check_startpoint_exit(joined);
	checking_other_characters(joined);
	list.array =  ft_split(joined, '\n');
	checking_size_map(list.array, list);
	locating_Start_point(list.array, &list.player_x, &list.player_y);
	filling_map_with_x(list.array, list.player_x, list.player_y);
	checking_valid_path(list.array);
	list.array = ft_split(joined, '\n');
	list.coin = counting_collectibles(list.array);
	i = 0;
	// while (list.array[i])
	// {
	// 	printf("%s\n", list.array[i++]);
	// }
	// char url[] = "https://www.youtube.com/watch?v=w99vz_wj1S0";
	// char command[1024];
    // sprintf(command, "open \"%s\"", url);
    // system(command);
    // return 0;
	displaying_img(list);
	//printf("hello");
}
