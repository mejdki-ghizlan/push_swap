typedef struct s_node
{
    char *str;
    struct s_node *next;
    struct s_node *prev;
} node;

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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
} 
int main()
{
    // node a;
    // node b;
    // node c;
    // node d;
    // node z;

    // a.next = &b;
    // b.next = &c;
    // c.next = &d;
    // d.next = NULL;

    // a.prev = NULL;
    // b.prev = &a;
    // c.prev = &b;
    // d.prev = &c;

    // z.next = z.prev = NULL;
    // z.str = strdup("hello");

    // a.str = strdup("*");
    // b.str = strdup("**");
    // c.str = strdup("**");
    // d.str = strdup("*");

    // node *head = &a;
    // int len = 0;
    // while (head)
    // {
    //     head = head->next;
    //     len++;
    // }
    // head = &a;
    // int index = 1;
    // while (head && index < (len / 2))
    // {
    //     head = head->next;
    //     index ++;
    // }
    // z.prev = head;
    // z.next = head->next;
    // head->next = &z;
    // head->next->prev = &z;

    // node *tmp;
    // tmp = &a;

    // while (tmp->next != NULL)
    // {
    //     printf("%s\n", tmp->str);
    //     tmp = tmp->next;
    // }
    // printf("%s\n", tmp->str);

    // int dir = 1;
    // int end = 0;

    // while (!end || tmp->prev)
    // {
    //     if (tmp->prev == 0)
    //         dir = 0;
    //     else if (!tmp->next && !dir)
    //     {
    //         dir = 1;
    //         end = 1;
    //     }
    //     printf("%s\n", tmp->str);
    //     if (dir == 0)
    //         tmp = tmp->next;
    //     if (dir == 1)
    //         tmp = tmp->prev;
    //     if (end == 1 && tmp->prev == NULL)
    //         printf("%s\n", tmp->str);
    // }

    // printf("%p\n", &str);

    char *str = "ghizlan mejdki";

    // str = 
    // str++;
    // printf("%s\n", str[0]);
    // char **test;
    // test = str;
   
    // test++;
    // printf("%s\n", *test);

    char **dst;
    int len;
    int cw;
    int i;
    int j;

    cw = count_word(str);
    dst = malloc(cw * sizeof(char *) + 1);
    i = 0;
    while (i < cw)
    {
        j = 0;
        while (str[j] != ' ' && str[j])
        {
            len++;
            j++;
        }
        dst[i++] = malloc(len + 1);
        j = 0;
        while (dst[i])
        {
            *dst[i] = str[j++];
            (*dst)++;
        }
    }
   
    
    printf("%c\n", *str);
    printf("%s\n", *dst);
    printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
    printf("%c\n", **dst);
    (*str)++;
    printf("%c\n", **dst);
    printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
    printf("%p\n", &str);
    printf("%p\n", str);
    printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
    // str[1] = "daoud";
    printf("%c\n", str[1]);
    printf("%c\n", *dst[1]);
}

// while (head->next != NULL)
// {
//     printf("%s\n", head->str);
//     head = head->next;
// }
// printf("%s\n", head->str);

// while (head->prev)
// {
//     printf("%s\n", head->str);
//     head = head->prev;
// }
// printf("%s\n", head->str);