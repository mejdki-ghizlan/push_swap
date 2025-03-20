/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gel-mejd <gel-mejd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 20:08:08 by gel-mejd          #+#    #+#             */
/*   Updated: 2025/03/20 05:48:31 by gel-mejd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*new_node(int num)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->num = num;
	node->next = NULL;
	node->target = NULL;
	return (node);
}

void	add_back(t_node **lst, t_node *new)
{
	t_node	*tmp;

	if (*lst == NULL)
		*lst = new;
	else
	{
		tmp = *lst;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void	is_duplicate(t_node *node, t_node **stack)
{
	t_node	*tmp;

	tmp = *stack;
	while (tmp)
	{
		if (node->num == tmp->num)
		{
			ft_free_stack(stack);
			error();
		}
		tmp = tmp->next;
	}
}

void	check_numbers(char **buff)
{
	int	i;
	int	j;

	i = 0;
	while (buff[i])
	{
		j = 0;
		if (buff[i][j] && (buff[i][0] == '-' || buff[i][0] == '+'))
		{
			if (!buff[i][1])
				error();                // ??????????????????????
			j++;
		}
		while (buff[i] && buff[i][j])
		{
			if (!(buff[i][j] >= '0' && buff[i][j] <= '9'))
				error();                // ??????????????????????
			j++;
		}
		i++;
	}
}

void	is_valid(char **str, t_node **stack)
{
	int		i;
	int		num;
	t_node	*node;

	i = 0;
	check_numbers(str);
	while (str[i])
	{
		num = ft_atoi(str[i]);
		node = new_node(num);
		is_duplicate(node, stack);
		add_back(stack, node);
		i++;
	}
}
