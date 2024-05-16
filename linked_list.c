#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
typedef char *str;
typedef struct node
{
    int num;
    struct node *next;
} node;

int main()
{
    node *list = NULL;
    node *n = malloc(sizeof(node));
    if (n == NULL)
    {
        return 1;
    }
    n->num = 1;
    n->next = NULL;
    list = n;

    n = malloc(sizeof(node));
    if (n == NULL)
    {
        free(list);
        return 1;
    }
    n->num = 2;
    n->next = NULL;
    list->next = n;

    n = malloc(sizeof(node));
    if (n == NULL)
    {
        free(list->next);
        free(list);
        return 1;
    }
    n->num = 3;
    n->next = NULL;
    list->next->next = n;

    n = malloc(sizeof(node));
    if (n != NULL)
    {
        n->num = 0;
        n->next = list->next;
        list->next = n;
    }

    for (node *temp = list; temp != NULL; temp = temp->next)
    {
        printf("%i \n", temp->num);
    }
    while (list != NULL)
    {
        node *temp = list->next;
        free(list);
        list = temp;
    }

    return 0;
}