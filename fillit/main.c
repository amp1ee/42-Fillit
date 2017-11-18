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

#include "libft.h"
#include "fillit.h"
#include <unistd.h>
#include <fcntl.h> 
#include <stdio.h>

typedef int bool;

enum { false, true };

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
				printf("true\n");
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