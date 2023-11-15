
#ifndef STACK_H
# define STACK_H

# include "libft/includes/libft.h"
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>

typedef struct s_stack
{
	int	*stack;
	int	size;
	int	top;
	int	bottom;
}		t_stack;

typedef struct s_push_swap
{
	t_stack	a;
	t_stack b;
	t_list	*op_list;
	bool	writing_mode;
}		t_ps;

enum	e_op
{
	null_op,
	pa,
	pb,
	ra,
	rb,
	rr,
	rra,
	rrb,
	rrr,
	sa,
	sb,
	ss
};

#endif
