/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaturan <nmaturan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 19:08:46 by nmaturan          #+#    #+#             */
/*   Updated: 2023/11/15 19:17:34 by nmaturan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stack.h"

//if 1. nothing in stack
//if 2. top of stack displaced, not at index 0
//else. top of stack = index 0
int	current_size(t_stack *stk)
{
	if (stk->top == stk->bottom && stk->stack[stk->top] == 0)
		return (0);
	if (stk->top > stk->bottom)
		return ((stk->size - stk->top) + (stk->bottom + 1));
	else
		return (stk->bottom - stk->top + 1);
}

//implement with pointer return? that would confirm use of t_stack *stk
int	next_down(t_stack *stk, int index)
{
	if (current_size(stk) == 0)
		return (index);
	if (index == stk->size - 1)
		return (0);
	else
		return (index + 1);
}

//returns value n from stack.
int	value(t_stack *stk, int n)
{
	int	i;

	i = stk->top;
	while (--n > 0)
		i = next_down(stk, i);//iterates the stack.
	return (stk->stack[i]);
}
