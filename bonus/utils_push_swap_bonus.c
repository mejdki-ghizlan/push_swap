/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_push_swap_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gel-mejd <gel-mejd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 03:00:48 by gel-mejd          #+#    #+#             */
/*   Updated: 2025/03/20 06:12:02 by gel-mejd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

int ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] == s2[i])
			i++;
		else
			return (0);
	}
	if (!s1[i] && !s2[i])
		return (1);
	return (0);
}

// void ft_free(char **str)
// {
// 	int i;

// 	i = 0;
// 	while (str[i])
// 	{
// 		free(str[i]);
// 		i++;
// 	}
// 	free(str);
// }
