/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gel-mejd <gel-mejd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 22:02:40 by gel-mejd          #+#    #+#             */
/*   Updated: 2025/02/26 19:25:47 by gel-mejd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

char *ft_strdup(char *str)
{
    int i;
    char *dst;

    dst = malloc(ft_strlen(str) + 1);
    i = 0;
    while (str[i])
    {
        *dst = str[i];
        dst++;
        i++;
    }
    return (dst);
}
int count_word(char *str)
{
    int counter;

    counter = 0;
    while (*str != '\0')
    {
        while (*str == ' ')
            str++;
        if (*str == '\0')
            break ;
        while (*str != ' ')
            str++;
        counter++;
    }
    return (counter);
}                               // "     k"
char **ft_split(char *str)
{
    char **dst;
    int len;
    int cw;
    int i;
    int j;

    if (*str == '\0')
        return (NULL);
    // len = ft_strlen()
    cw = count_word(str);
    dst = malloc(cw * sizeof(char *) + 1);
    i = 0;
    while (i < cw)
    {
        j = 0;
        while (str[j] && str[j] != ' ')
        {
           len++;
            j++;    
        }
        dst[i] = malloc(len + 1);
        j = 0;
        while (dst[i])
        {
            *dst[i] = str[j++];
            (*dst)++;
        }
    }
    return (dst);
}
int main()
{
    char *str = "ab cd fr de";
    char **res;
    res = ft_split(str);
    printf("%s\n", *res);
    return (0);
}