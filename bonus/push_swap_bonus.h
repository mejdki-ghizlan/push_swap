/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gel-mejd <gel-mejd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 01:26:22 by gel-mejd          #+#    #+#             */
/*   Updated: 2025/03/21 12:39:34 by gel-mejd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE 5

typedef struct s_node
{
	int				num;
	int				cost;
	int				position;
	int				index;
	struct s_node	*target;
	struct s_node	*next;
}					t_node;

// get_next_line
int	check_new_line(char *buffer);
char	*ft_get_line(char *buffer);
char	*next_line(char *buffer);
char	*ft_read(char *buffer, int fd);
char	*get_next_line(int fd);

// instractions_1
void	ft_push(t_node **src, t_node **target);
void	pa_bonus(t_node **stack_a, t_node **stack_b);
void	pb_bonus(t_node **stack_a, t_node **stack_b);
void	ft_reverse_rotate(t_node **stack);
void	rrr_bonus(t_node **stack_a, t_node **stack_b);

// istractions_2
void	ft_rotate(t_node **stack);
void	rr_bonus(t_node **stack_a, t_node **stack_b);
void	ra_bonus(t_node **stack_a);
void	rb_bonus(t_node **stack_a);
void	rrb_bonus(t_node **stack_b);

// instractions_3
void	ft_swap(t_node **stack);
void	sa_bonus(t_node **stack_a);
void	sb_bonus(t_node **stack_b);
void	ss_bonus(t_node **stack_a, t_node **stack_b);
void	rra_bonus(t_node **stack_a);

// is_valid_bonus
t_node				*new_node(int num);
void				add_back(t_node **lst, t_node *new);
int					is_duplicate(t_node *node, t_node **stack);
int					check_numbers(char **buff);
int					is_valid(char **str, t_node **stack);

// main_push_swap_bonus
void				read_instractions(char *input, t_node **stack_a, t_node **stack_b);
void				is_OK(t_node **stack_a, t_node **stack_b);
void				checker(t_node **stack_a, t_node **stack_b);

// utils_bonus
int					ft_atoi(char *str, int *check);
void				error(void);
int					list_size(t_node *list);
void				is_sorted(t_node **stack);
// void				ft_free_stack(t_node **stack);

// utils_get_next_line
int					ft_strlen(char *s);
char				*ft_strdup(char *str);
char				*ft_strjoin(char *s1, char *s2);
int					ft_strcpy(char *s1, char *s2);

// utils_push_swap_bonus
int					count_word(char *str);
void				helper_split(char **dst, char *str, int i, int *k);
char				**ft_split(char *str);
int					ft_strcmp(char *s1, char *s2);
// void				ft_free(char **str);

// free_functions
void				ft_free_stack(t_node **stack);
void          		free_exit(char ***av);
void				ft_free(char **str);

#endif
