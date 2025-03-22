/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push_swap_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gel-mejd <gel-mejd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 01:25:12 by gel-mejd          #+#    #+#             */
/*   Updated: 2025/03/21 11:58:45 by gel-mejd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void custom_exit(char *input, t_node **stack_a, t_node **stack_b)
{
	free(input);
	ft_free_stack(stack_a);
	ft_free_stack(stack_b);
	error();
}


void read_instractions(char *input, t_node **stack_a, t_node **stack_b)
{
	if (ft_strcmp(input, "sa"))
		sa_bonus(stack_a);
	else if (ft_strcmp(input, "sb"))
		sb_bonus(stack_b);
	else if (ft_strcmp(input, "ss"))
		ss_bonus(stack_a, stack_b);
	else if (ft_strcmp(input, "pa"))
		pa_bonus(stack_a, stack_b);
	else if (ft_strcmp(input, "pb"))
		pa_bonus(stack_a, stack_b);
	else if (ft_strcmp(input, "ra"))
		ra_bonus(stack_a);
	else if (ft_strcmp(input, "rb"))
		rb_bonus(stack_b);
	else if (ft_strcmp(input, "rr"))
		rr_bonus(stack_a, stack_a);
	else if (ft_strcmp(input, "rra"))
		rra_bonus(stack_a);
	else if (ft_strcmp(input, "rrb"))
		rrb_bonus(stack_b);
	else if (ft_strcmp(input, "rrr"))
		rrr_bonus(stack_a, stack_b);
	else
		custom_exit(input, stack_a, stack_b);
}

void is_OK(t_node **stack_a, t_node **stack_b)
{
	t_node	*tmp;
	int		flag;

	flag = 0;
	tmp = *stack_a;
	while (tmp)
	{
		if (tmp->next && (tmp->num > tmp->next->num))
		{
			flag = 1;
			break ;
		}
		tmp = tmp->next;
	}
	if (flag == 0 && !*stack_b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);	
}

void checker(t_node **stack_a, t_node **stack_b)
{
	char *input;
	
	input = get_next_line(0);
	// printf("%i \n", ft_strlen(input));
	while (input)
	{
		read_instractions(input, stack_a, stack_b);
		free(input);
		input = get_next_line(0);
		printf("%p\n",input);
	}
	free(input);
	is_OK(stack_a, stack_b);
}

int	main(int ac, char **av)
{
	int		k;
	char	**buff;
	t_node	*stack_a;
	t_node	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac >= 2)
	{
		k = 1;
		while (av[k])
		{
			buff = ft_split(av[k]);
			if (!buff || !*buff || !is_valid(buff, &stack_a))
			{
				ft_free_stack(&stack_a);
				free_exit(&buff);
			}
			k++;
			ft_free(buff);
		}
		is_sorted(&stack_a);
		checker(&stack_a, &stack_b);
	}
	ft_free_stack(&stack_a);
	ft_free_stack(&stack_b);
}
