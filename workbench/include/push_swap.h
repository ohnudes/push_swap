#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "../libft/includes/libft.h"

typedef struct s_node
{
	int				index;
	int				value;

	struct s_node	*prev;
	struct s_node	*next;
}				t_node;

int	err_relay(void);

#endif
