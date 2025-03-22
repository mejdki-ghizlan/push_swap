/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gel-mejd <gel-mejd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 10:20:00 by gel-mejd          #+#    #+#             */
/*   Updated: 2025/03/21 10:30:36 by gel-mejd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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