#include "../../libft/libft.h"
#include "tetris.h"

/*
** NOT SO RANDOM
*/

static int	*rand_om(int max, unsigned int size)
{
	int	*random;

	if (!(random = (int *)malloc(sizeof(int) * (size + 1))) )
		return (NULL);
	random[size] = -1;
	while (size)
	{
		srand(time(NULL) + size--);
		random[size] = rand() % (max + 1);
	}
	return (random);
}

static char	**generate_map(unsigned int size)
{
	char	**tetra;
	int	*random;
	int	y;
	int	x;
	int	x_off, y_off;
	int	t_x_off, t_y_off, t_y, t_size;

	random = rand_om(T_SHAPES - 1, size);
	if (!(tetra = (char **)malloc(sizeof(char *) * size)))
		return (NULL);
	t_size = size;
	while (size--)
	{
		y = (blocks[random[size]]).h;
		x = (blocks[random[size]]).w;
		x_off = (4 - x) ? rand_om((4 - x), size + 1)[size] : 0;
		y_off = (4 - x) ? rand_om((4 - y), size + 1)[size] : 0;
		t_x_off = x_off;
		t_y_off = y_off;
		t_y = y;
		tetra[size] = ft_strnew(20);
		while (y_off--)
			tetra[size] = ft_strcat(tetra[size], "....\n");
		while (y--)
		{
			x_off = t_x_off;
			while (x_off--)
				tetra[size] = ft_strcat(tetra[size], ".");
			tetra[size] = ft_strcat(tetra[size], (blocks[random[size]]).data[y]);
			while (++x_off < (4 - t_x_off - x))
				tetra[size] = ft_strcat(tetra[size], ".");
			tetra[size] = ft_strcat(tetra[size], "\n");
		}
		while (++y_off < (4 - t_y_off - t_y))
			tetra[size] = ft_strcat(tetra[size], "....\n");
	}
	tetra[t_size - 1][19] = 0;
	return (tetra);
}

static void	free_map(char **map, int size)
{
	while (size--)
		ft_strdel(&map[size]);
	free(map);
	map = NULL;
}

static void	print_map(unsigned int size)
{
	char		**map;
	unsigned int	i;

	map = generate_map(size);
	i = 0;
	while (i < size)
		ft_putendl(map[i++]);
	free_map(map, size);
}

int		main(int ac, char **av)
{
	if (ac == 2)
		print_map((unsigned int)(ft_atoi(av[1])));
	else
		ft_putendl("Usage: ./map_gen size");
	return (0);
}
