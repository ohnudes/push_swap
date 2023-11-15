#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "stack.h"

enum	e_loc
{
	TOP_A,
	BOTTOM_A,
	TOP_B,
	BOTTOM_B
};

typedef struct s_chunk
{
	enum e_loc	loc;
	int			size;
}				t_chunk;

typedef struct s_split_dest
{
	t_chunk		min;
	t_chunk		mid;
	t_chunk		max;
}				t_split_dest;

/* ft variants as utils */
int	ft_countwords(const char *str, char set);

#endif
