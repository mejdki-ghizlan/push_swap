/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gel-mejd <gel-mejd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 22:44:07 by gel-mejd          #+#    #+#             */
/*   Updated: 2025/03/21 10:25:58 by gel-mejd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	indexing(t_node *stack)
{
	int		i;
	t_node	*tmp;

	i = 0;
	tmp = stack;
	while (tmp)
	{
		tmp->index = i;
		i++;
		tmp = tmp->next;
	}
}

void	min_target(t_node *stack_a, t_node *node)   
{
	t_node	*tmp;
	t_node	*small;

	tmp = stack_a;
	small = stack_a;
	while (tmp)
	{
		if (small->num > tmp->num)
			small = tmp;
		tmp = tmp->next;
	}
	node->target = small;
}

void	target(t_node *stack_a, t_node *stack_b)    
{
	t_node	*tmp_b;
	t_node	*tmp_a;

	tmp_b = stack_b;
	tmp_a = stack_a;
	while (tmp_b)
	{
		tmp_b->target = tmp_a;
		while (tmp_a)
		{
			if (tmp_a->num > tmp_b->num)
			{
				if (tmp_b->num > tmp_b->target->num || tmp_a->num < tmp_b->target->num)
					tmp_b->target = tmp_a;
			}
			tmp_a = tmp_a->next;
		}
		if (tmp_b->num > tmp_b->target->num)
			min_target(stack_a, tmp_b);
		tmp_a = stack_a;
		tmp_b = tmp_b->next;
	}
}
        

void	position(t_node *stack)
{
	int		len;
	t_node	*tmp;

	tmp = stack;
	len = list_size(stack) / 2;
	while (tmp)
	{
		if (tmp->index <= len)
			tmp->position = 0;
		else
			tmp->position = 1;
		tmp = tmp->next;
	}
}

void	cost(t_node *stack)
{
	int		len;
	t_node	*tmp;

	if (!stack)
		return ;
	len = list_size(stack);
	tmp = stack;
	while (tmp)
	{
		if (tmp->position == 0)
			tmp->cost = tmp->index;
		if (tmp->position == 1)
			tmp->cost = len - tmp->index;
		tmp = tmp->next;
	}
}
