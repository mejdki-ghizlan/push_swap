/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gel-mejd <gel-mejd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 20:08:08 by gel-mejd          #+#    #+#             */
/*   Updated: 2025/03/21 12:13:06 by gel-mejd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

int	is_duplicate(t_node *node, t_node **stack)
{
	t_node	*tmp;

	tmp = *stack;
	while (tmp)
	{
		if (node->num == tmp->num)
			return (0);	
		tmp = tmp->next;
	}
	return (1);
}

int	check_numbers(char **buff)
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
				return (0);
			j++;
		}
		while (buff[i] && buff[i][j])
		{
			if (!(buff[i][j] >= '0' && buff[i][j] <= '9'))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	is_valid(char **str, t_node **stack)
{
	int		i;
	int		num;
	int		check;
	t_node	*node;

	i = 0;
	check = 0;
	if (!check_numbers(str))
		return (0);
	while (str[i])
	{
		num = ft_atoi(str[i], &check);
		node = new_node(num);
		if (is_duplicate(node, stack) == 0 || check == 1)
		{
			free(node);
			return(0);
		}
		add_back(stack, node);
		i++;
	}
	return (1);
}
