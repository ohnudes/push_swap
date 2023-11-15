#include "./push_swap.h"
#include "libft/includes/libft.h"

void	free_data(t_ps *data)
{
	if (data->a.stack)
		free(data->a.stack);
	if (data->b.stack)
		free(data->b.stack);
}

void	error(t_ps *data)
{
	free_data(data);
	ft_putendl_fd("Error", 2);
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
