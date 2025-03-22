/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gel-mejd <gel-mejd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 21:14:44 by gel-mejd          #+#    #+#             */
/*   Updated: 2025/03/21 10:21:11 by gel-mejd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int count_word(char *str)
{
	int counter;

	counter = 0;
	while (*str != '\0')
	{
		while (*str && *str == ' ')
			str++;
		if (*str == '\0')
			break;
		while (*str && *str != ' ')
			str++;
		counter++;
	}
	return (counter);
}

void helper_split(char **dst, char *str, int i, int *k)
{
	int len;
	int j;
	int c;

	j = *k;
	while (str[j] == ' ')
		j++;
	len = 0;
	while (str[j + len] && str[j + len] != ' ')
		len++;
	dst[i] = malloc(len + 1);
	c = 0;
	while (c < len)
	{
		dst[i][c] = str[j + c];
		c++;
	}
	dst[i][c] = '\0';
	j += len;
	*k = j;
}

char **ft_split(char *str)
{
	char **dst;
	int cw;
	int i;
	int j;

	if (!str || *str == '\0')
		return (NULL);
	cw = count_word(str);
	dst = malloc((cw + 1) * sizeof(char *));
	if (!dst)
		return (NULL);
	i = 0;
	j = 0;
	while (i < cw)
	{
		helper_split(dst, str, i, &j);
		i++;
	}
	dst[i] = NULL;
	return (dst);
}

int	main(int ac, char **av)
{
	int k;
	char **buff;
	t_node *stack_a;
	t_node *stack_b;
	
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
		best_move(&stack_a, &stack_b);
	}
	ft_free_stack(&stack_a);
}
