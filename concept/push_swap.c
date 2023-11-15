
#include "push_swap.h"
#include "libft/includes/libft.h"

/* STACK OPERATIONS */
void	swap_stk(t_stack *stk)
{
	int	next;
	int	swp;

	next = next_down(stk, stk->top);
	swp = stk->stack[next];
	stk->stack[next] = stk->stack[stk->top];
	*stk->stack = swp;
}

void	swap_data(t_ps *data);
void	rotate_stk(t_stack *stk);
void	rotate_data(t_ps *data);
void	reverse_rotate_stk(t_stack *stk);
void	reverse_rotate_data(t_ps *data);
void	push_stk(t_stack *src, t_stack *dst);

/* SORT */

void	sort_five_a(t_ps *data)
{

}

void	sort_three_a(t_ps *data)
{
	int	first;
	int	second;
	int	third;

	first = value(&data->a, 1);//returns av = 1
	second = value(&data->a, 2);
	third = value(&data->a, 3);
	if (first > second && second < third && first > third)
		rotate_stk(&data->a);
	else if (first > second && second < third && first < third)
		swap_stk(&data->a);
	else if (first < second && second > third && first > third)
		reverse_rotate_stk(&data->a);
	else if (first < second && second > third && first < third)
	{
		swap_stk(&data->a);
		rotate_stk(&data->a);
	}
	else if (first > second && second > third)
	{
		swap_stk(&data->a);
		reverse_rotate_stk(&data->a);
	}
}

bool	is_sorted(const t_ps data)
{
	int	i;
	int	rank;

	i = data->a.top;//int representing index 0 of stack.
	rank = 1;
	while (rank <= data->a.size)//total args to order
	{
		if (data->a.stack[i] != rank)//check if ranked value corresponds to rank.
			return (false);
		rank++;//rank +1, given natural increments
		i = next_down(&data->a, i);//since the stk[0] isnt fixed but 
								   //rather dynamic, 'i' can't be
								   //naturally incremented
	}
	return (true);
}
/* MY TAKE */
int	my_is_sorted(t_ps *data)
{
	int	i;

	i = data->a.top + 1;
	while (i <= data->a.size)
	{
		if (data->a.stack[i - 1] != i)
			return (0);
		i++;
	}
	return (true);
}

void	sort(t_ps *data)
{
	if (data->a.size <= 1 || is_sorted(*data))
		return ;
	else if (data->a.size == 3)
		sort_three_a(data);
	else if (data->a.size == 5)
		sort_five_a(data);
	else
		chunk_sort(data);
	post_sort_optimization(data);
}
/* END SORT */

/* INIT */

bool	valid_arg(char *str)
{
	long	nb;
	int		sign;

	nb = 0;
	sign = '+';
	if (*str == '+' || *str == '-')
		sign = *str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (false);
		nb = (nb * 10) + *str++ - '0';
	}
	if (sign == '-')
		nb = -nb;
	if (nb > INT_MAX || nb < INT_MIN)
		return (false);
	return (true);
}

void	random_to_rank(int *numbers, int *stack, int size)
{
	size_t	i;
	size_t	j;
	size_t	smaller_than;

	i = 0;
	while (i < size)
	{
		j = 0;
		smaller_than = 0;
		while (j < size)
			if (numbers[j++] <= numbers[i])
				smaller_than++;
		stack[i] = smaller_than;
		i++;
	}
}

void	check_duplication(t_ps *data, int *numbers, int size)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (numbers[i] == numbers[j])
			{
				free(numbers);
				error(data);
			}
			j++;
		}
		i++;
	}
}

void	fill_stack(t_ps *data, t_stack *stk, int size, char **arg)
{
	int	*numbers;
	int	i;

	numbers = malloc(sizeof(int) * size);
	if (!numbers)
		error(data);
	i = 0;
	while (arg[i])
	{
		if (!valid_arg(arg[i]))
			error(data);
		numbers[i] = ft_atoi(arg[i]);
		i++;
	}
	check_duplication(data, numbers, size);
	random_to_rank(numbers, stk->stack, size);
	stk->bottom = size - 1;
	free(numbers);
}

void	init_stack(t_ps *data, t_stack *stk, int size)
{
	stk->stack = malloc(sizeof(int) * size);
	if (!stk->stack)
		error(data);
	stk->top = 0;
	stk->bottom = 0;
	stk->size = 0;
	ft_memset(stk->stack, 0, sizeof(int) * size);
}

void	init_data(t_ps *data, int argc, char **argv, bool writing_mode)
{
	init_stack(data, &data->a, argc);
	init_stack(data, &data->b, argc);
	fill_stack(data, &data->a, argc, argv);
	data->writing_mode = writing_mode;
	data->op_list = NULL;
}

/* END INIT */

int	main(int argc, char **argv)
{
	t_ps	data;
	char	**quotation_str;

	if (argc == 1 || (argc == 2 && !argv[1][0]))
			return(ft_putendl_fd("error", 2), 1);
	else if (argc == 2)
	{
		quotation_str = ft_split(argv[1], ' ');
		init_data(&data, ft_countwords(argv[1], ' '), quotation_str, true);
		free(quotation_str);
	}
	else
		init_data(&data, --argc, ++argv, true);
	sort(&data);
	print_operations(data.op_list);
	free_data(&data);
	exit(EXIT_SUCCESS);
}
