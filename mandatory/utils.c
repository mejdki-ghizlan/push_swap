/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gel-mejd <gel-mejd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 22:34:17 by gel-mejd          #+#    #+#             */
/*   Updated: 2025/03/21 10:31:03 by gel-mejd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(char *str, int *check)
{
	int		i;
	long	s;
	long	r;

	r = 0;
	s = 1;
	i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			s = s * (-1);
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		r = r * 10 + (str[i] - 48);
		if ((r * s) < -2147483648 || (r * s) > 2147483647)
			*check = 1;
		i++;
	}
	return (r * s);
}

void	error(void)
{
	write(2, "Error\n", 6);
	exit(2);
}

int	list_size(t_node *list)
{
	int		len;
	t_node	*tmp;

	len = 0;
	if (!list)
		return (0);
	tmp = list;
	while (tmp)
	{
		tmp = tmp->next;
		len++;
	}
	return (len);
}

void	is_sorted(t_node **stack)
{
	t_node	*tmp;
	int		flag;

	flag = 0;
	tmp = *stack;
	while (tmp)
	{
		if (tmp->next && tmp->num > tmp->next->num)
		{
			flag = 1;
			break ;
		}
		tmp = tmp->next;
	}
	
	if (flag == 0)
	{
		ft_free_stack(stack);
		exit(0);
	}
}
