/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_get_next_line.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gel-mejd <gel-mejd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 02:10:43 by gel-mejd          #+#    #+#             */
/*   Updated: 2025/03/17 02:12:43 by gel-mejd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_strlen(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(char *str)
{
	char	*s;
	char	*p;

	if (!str)
		return (NULL);
	s = malloc(ft_strlen(str) + 1);
	if (!s)
		return (NULL);
	p = s;
	while (*str)
		*s++ = *str++;
	*s = '\0';
	return (p);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*buff;
	int		len;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	buff = malloc(len);
	if (!buff)
		return (NULL);
	i = ft_strcpy(buff, s1);
	while (s2[j])
		buff[i++] = s2[j++];
	buff[i] = '\0';
	return (buff);
}

int	ft_strcpy(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s2[i] && s2[i] != '\n')
	{
		s1[i] = s2[i];
		i++;
	}
	if (s2[i] == '\n')
	{
		s1[i] = s2[i];
		i++;
	}
	return (i);
}
