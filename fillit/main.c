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

t_tetrimino *which_tetrimino(char **arr, int y, int x)
{
	int k;
	int p;

	//printf("x = %d y = %d\n", x, y);

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
			printf("figure %d\n\n", k);
			return (NULL);
		}
		k++;
	}
	return (NULL);
}

t_tetrimino *is_tetrimino(char *tetrimino)
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
				return (which_tetrimino(arr, y, x));
			x++;
		}
		y++;
	}
	return (NULL);
}

t_tetrimino **read_data(char *filename)
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
				is_tetrimino(buffer);
			}
		}
		return (NULL);
	}
	else
		exit(0);
}



int main(int argc, char **argv)
{
	if (argc == 2)
	{
		read_data(argv[1]);
	}
	else
		ft_putendl("Usage:");
	return (0);
}