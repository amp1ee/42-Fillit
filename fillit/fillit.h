#ifndef FILLIT_H
# define FILLIT_H

typedef int bool;

enum { false, true };

typedef struct	s_coordinates
{
    int x;
    int y;
}				t_coordinates;

typedef struct	s_tetrimino
{
    char letter;
    t_coordinates *blocks;
}				t_tetrimino;

t_coordinates	tetriminos[19][3] =
{
	{{ 1, 0 },
	{ 0, 1 },
	{ 1, 1 }},

	{{ -1, 1 },
	{ 0, 1 },
	{ 1, 1 }},

	{{ 0, 1 },
	{ 1, 1 },
	{ 0, 2 }},

	{{ -1, 1 },
	{ 0, 1 },
	{ 0, 2 }},

	{{ 1, 0 },
	{ 2, 0 },
	{ 1, 1 }},

	{{ 1, 0 },
	{ 2, 0 },
	{ 3, 0 }},

	{{ 0, 1 },
	{ 0, 2 },
	{ 0, 3 }},

	{{ 1, 0 },
	{ 0, 1 },
	{ 0, 2 }},

	{{ 1, 0 },
	{ 2, 0 },
	{ 2, 1 }},

	{{ 0, 1 },
	{ -1, 2 },
	{ 0, 2 }},

	{{ 0, 1 },
	{ 1, 1 },
	{ 2, 1 }},

	{{ 1, 0 },
	{ 1, 1 },
	{ 1, 2 }},

	{{ 1, 0 },
	{ 2, 0 },
	{ 0, 1 }},

	{{ 0, 1 },
	{ 0, 2 },
	{ 1, 2 }},

	{{ -2, 1 },
	{ -1, 1 },
	{ 0, 1 }},

	{{ 1, 0 },
	{ -1, 1 },
	{ 0, 1 }},

	{{ 0, 1 },
	{ 1, 1 },
	{ 1, 2 }},

	{{ 1, 0 },
	{ 1, 1 },
	{ 2, 1 }},

	{{ -1, 1 },
	{ 0, 1 },
	{ -1, 2 }},

};

#endif