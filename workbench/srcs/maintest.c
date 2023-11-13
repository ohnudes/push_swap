
#include "../include/push_swap.h"
#include "../libft/includes/libft.h"
#include <stdio.h>

/* UTILS */

void	free_data(t_ps *data)
{
	if (data->a.stack)
		free(data->a.stack);
	if (data->b.stack)
		free(data->b.stack);
}

void	error(t_ps *data, char *msg)
{
	free_data(data);
	ft_putendl_fd(msg, 2);
	exit(EXIT_FAILURE);
}

int	ft_countwords(const char *str, char set)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (*str != set)
			count++;
		while (*str && *str != set)
			str++;
		while (*str && *str == set)
			str++;			
	}
	return (count);
}

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
		nb = (nb * 10) + *str - '0';
		str++;
	}
	if (sign == '-')
		nb = -nb;
	if (nb > INT_MAX || nb < INT_MIN)
		return (false);
	return (true);
}

void	random_to_rank(int *numbers, int *stack, int size)
{
	int	i;
	int	j;
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
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (numbers[i] == numbers[j])
			{
				free(numbers);
				error(data, "check_duplication: error");
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
		error(data, "fill_stack/malloc: error");
	i = 0;
	while (arg[i])
	{
		if (!valid_arg(arg[i]))
			error(data, "fill_stack/valid_arg: error");
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
		error(data, "init_stack/malloc: error");
	stk->top = 0;
	stk->bottom = 0;
	stk->size = 0;
	ft_memset(stk->stack, 0, sizeof(int) * size);
}

void	init_data(t_ps *data, int argc, char **argv, bool writing_mode)
{
	//int *print;

	init_stack(data, &data->a, argc);
	init_stack(data, &data->b, argc);
	fill_stack(data, &data->a, argc, argv);
	//print = data->a.stack;
	//printf("size	%d\n", data->a.size);
//while (*print && data->a.size-- > 0)
//		printf("stack a	%p	%d\n", data->a.stack, *print++);
	data->writing_mode = writing_mode;
	data->op_list = NULL;
}

/* END INIT */

int	main(int argc, char **argv)
{
	t_ps	data;
	char	**quotation_str;

	if (argc == 1 || (argc == 2 && !argv[1][0]))
			return(ft_putendl_fd("argc/argv: error", 2), 1);
	else if (argc == 2)
	{
		quotation_str = ft_split(argv[1], ' ');
		init_data(&data, ft_countwords(argv[1], ' '), quotation_str, true);
		free(quotation_str);
	}
	else
		init_data(&data, --argc, ++argv, true);
	free_data(&data);
	exit(EXIT_SUCCESS);
}
