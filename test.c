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
	p = calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
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

void	ft_frees(int **str, size_t j)
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
}

static char	*ft_word(char const *s, char c)
{
	size_t	len_word;
	size_t	i;
	char	*word;

	i = 0;
	len_word = ft_strlen_checker(s, c);
	word = (char *)calloc(sizeof(char), (len_word + 1));
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
	str = (char **)calloc(sizeof(char *), (ft_count_word(s, c) + 1));
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
int counting_enemies(char **buffer)
{
	int counter = 0;
	int i = 0;
	int j = 0;
	while (buffer[i])
	{
		j = 0;
		while (buffer[i][j])
		{	
			if (buffer[i][j] == 'N')
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
	if (counter1 == 0 || counter2 == 0)
	{
		perror("No Exit point or Start point");
		exit(1);
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

void displaying_you_died(t_list *list)
{
	list->position_y = list->columns  / 2;
	list->position_x = (list->rows + 1) / 2;
	assigning_values_displaying_you_died(list);
	while (list->array[list->position_x])
	{
		list->position_y = 0;
		while (list->array[list->position_x][list->position_y])
		{
			if (list->array[list->position_x][list->position_y] == 'Y')
				mlx_put_image_to_window(list->mlx, list->mlx_win, list->img_Y, list->position_y*64, list->position_x*64);
			else if (list->array[list->position_x][list->position_y] == 'O')
				mlx_put_image_to_window(list->mlx, list->mlx_win, list->img_O, list->position_y*64, list->position_x*64);
			else if (list->array[list->position_x][list->position_y] == 'U')
				mlx_put_image_to_window(list->mlx, list->mlx_win, list->img_U, list->position_y*64, list->position_x*64);
			else if (list->array[list->position_x][list->position_y] == 'S')
				mlx_put_image_to_window(list->mlx, list->mlx_win, list->img_S, list->position_y*64, list->position_x*64);
			else if (list->array[list->position_x][list->position_y] == 'c')
				mlx_put_image_to_window(list->mlx, list->mlx_win, list->img_C, list->position_y*64, list->position_x*64);
			else if (list->array[list->position_x][list->position_y] == 'K')
				mlx_put_image_to_window(list->mlx, list->mlx_win, list->img_K, list->position_y*64, list->position_x*64);
		list->position_y++;
		}
		list->position_x++;
	}	
}
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
	if(!list->enemy_pos)
		return ;
	list->flag = 0;
	displaying_img(*list);
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
int checking_ber_extension(int ac, char *av)
{
	int fd;
	int len;
	if (ac > 2)
	{
		perror("More arguments than expected");
		exit(1);
	}
	fd = open(av, O_RDWR, 0777);
	if (fd == -1)
	{
		write(1,"No such file\n", 13);
		exit(1); 
	}
	len = ft_strlen(av);
	if (av[len-1] != 'r' && av[len-2] != 'e' && av[len-3] != 'b' && av[len-4] != '.' && av[0] != '.')
	{
		write(1,"File with extension unexpected\n",31);
		exit(1);
	}
	return fd;
}
int checking_files_permissions()
{
	if (open("1_water.xpm",O_RDONLY,077) == -1 || open("2_water.xpm",O_RDONLY,077) == -1 || open("3_water.xpm",O_RDONLY,077) == -1)
		return(write(1,"Permission denied or file deleted\n",35),exit(1),0);
	if (open("castle.xpm",O_RDONLY,077) == -1 || open("enemy.xpm",O_RDONLY,077) == -1 || open("floor.xpm",O_RDONLY,077) == -1)
		return(write(1,"Permission denied or file deleted\n",35),exit(1),0);
	if (open("sky.xpm",O_RDONLY,077) == -1 || open("trees.xpm",O_RDONLY,077) == -1 || open("water.xpm",O_RDONLY,077) == -1)
		return(write(1,"Permission denied or file deleted\n",35),exit(1),0);
	if (open("Y.xpm",O_RDONLY,077) == -1 || open("O.xpm",O_RDONLY,077) == -1 || open("U.xpm",O_RDONLY,077) == -1)
		return(write(1,"Permission denied or file deleted\n",35),exit(1),0);
	if (open("S.xpm",O_RDONLY,077) == -1 || open("C.xpm",O_RDONLY,077) == -1 || open("K.xpm",O_RDONLY,077) == -1)
		return(write(1,"Permission denied or file deleted\n",35),exit(1),0);
	if (open("player2_.xpm",O_RDONLY,077) == -1 || open("soil.xpm",O_RDONLY,077) == -1)
		return(write(1,"Permission denied or file deleted\n",35),exit(1),0);
	return 0;
}
int main(int ac, char *av[])
{
	t_list list;
	char *buffer;
	char *joined;
	int fd;
	
	fd = checking_ber_extension(ac, av[1]);
	checking_files_permissions();
	joined = get_next_line(fd);
	error_joined(joined);
	list.columns = ft_strlen(joined) - 1;
	list.rows = 1;
	checking_first_wall(joined);
	joined = filling_the_map(fd, buffer, joined, &list);
 	main_bonus_util(&list, joined);
}