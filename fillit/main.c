/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 12:36:46 by vbrazhni          #+#    #+#             */
/*   Updated: 2017/11/18 12:36:50 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "fillit.h"
#include <unistd.h>
#include <fcntl.h> 
#include <stdio.h>

bool is_valid(char *tetrimino)
{
	int i;
	int hashes;

	i = 0;
	hashes = 0;
	while (tetrimino[i])
	{
		if ((i == 4 || i == 9 || i == 14 || i == 19))
		{
			if (tetrimino[i] != '\n')
				return (false);
			else
			{
				i++;
				continue;
			}
		}
		else if (!(tetrimino[i] == '#' || tetrimino[i] == '.'))
			return (false);
		else if (tetrimino[i] == '#')
			hashes++;
		i++;
	}
	if (hashes != 4)
		return (false);
	return (true);
}

t_tetrimino *which_tetrimino(char **arr, int y, int x, int i)
{
	int k;
	int p;
	t_tetrimino		*tetr;

	k = 0;
	while (k < 19)
	{
		p = 0;
		while (p < 3)
		{
			if (!((y + tetriminos[k][p].y) >= 0 && (y + tetriminos[k][p].y) <= 3
				&& (x + tetriminos[k][p].x) >= 0 && (x + tetriminos[k][p].x) <= 3
				&& arr[y + tetriminos[k][p].y][x + tetriminos[k][p].x] == '#'))
			{
				break;
			}
			p++;
		}
		if (p == 3)
		{
			printf("figure %d\n", k);
			tetr = (t_tetrimino *)malloc(sizeof(t_tetrimino));
			tetr->letter = 'A' + i;
			printf("letter %c\n\n", tetr->letter);
			tetr->blocks = tetriminos[k];
			return (tetr);
		}
		k++;
	}
	return (NULL);
}

t_tetrimino *is_tetrimino(char *tetrimino, int i)
{
	int x;
	int y;
	char **arr;

	arr = ft_strsplit(tetrimino, '\n');
	printf("%s\n", arr[0]);
	printf("%s\n", arr[1]);
	printf("%s\n", arr[2]);
	printf("%s\n", arr[3]);

	y = 0;
	while (arr[y])
	{
		x = 0;
		while (x < 4)
		{
			if (arr[y][x] == '#')
				return (which_tetrimino(arr, y, x, i));
			x++;
		}
		y++;
	}
	return (NULL);
}

t_tetrimino **read_data(char *filename, int *i, t_tetrimino **tetrs)
{
	int fd;
	char *buffer;
	size_t size;

	if (((fd = open(filename, O_RDONLY)) != -1) && (buffer = ft_strnew(22)))
	{
		while ((size = read(fd, buffer, 21)))
		{
			if (size == 21 && buffer[20] != '\n')
			{
				printf("error\n");
				exit(0);
			}
			*(buffer + 20) = '\0';
			if (!is_valid(buffer))
			{
				printf("error\n");
				exit(0);
			}
			else
			{
				if (tetrs)
					tetrs[*i] = is_tetrimino(buffer, (*i));
				(*i)++;
			}
		}
		return (tetrs);
	}
	else
		exit(0);
}

int main(int argc, char **argv)
{
	int			i;
	t_tetrimino **tetrs;

	i = 0;
	if (argc == 2)
	{
		read_data(argv[1], &i, NULL);
		tetrs = (t_tetrimino **)malloc(sizeof(t_tetrimino) * i);
		i = 0;
		tetrs = read_data(argv[1], &i, tetrs);
	}
	else
		ft_putendl("Usage:");
	return (0);
}