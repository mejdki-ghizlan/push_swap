#include "push_swap_bonus.h"

void          free_exit(char ***av)
{
	int	i;

	i = 0;
	if (!av || !(*av))
		error();
	while ((*av)[i])
	{
		free((*av)[i]);
		i++;
	}
	free(*av);
	*av = NULL;
	error();
}

void ft_free_stack(t_node **stack)
{

	t_node	*tmp;

	if (!stack || !*stack)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

void ft_free(char **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}
