#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
typedef char *str;

typedef struct node
{
    int num;
    struct node *left;
    struct node *right;
} node;

node *create_node(int value)
{
    node *new_node = (node *)malloc(sizeof(node));
    if (new_node == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    new_node->num = value;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void free_tree(node *root)
{
    if (root == NULL)
        return;
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}

void tr(node *root)
{
    if (root == NULL)
        return;
    tr(root->left);
    printf("%i \n", root->num);
    tr(root->right);
}

int search(node *tree, int n)
{
    if (tree == NULL)
    {
        printf("not found\n");
        return 1;
    }
    else if (n < tree->num)
    {
        printf("go left\n");
        return search(tree->left, n);
    }
    else if (n > tree->num)
    {
        printf("go right\n");
        return search(tree->right, n);
    }
    else
    {
        printf("found\n");
        return 0;
    }
}

int main()
{
    node *tree = create_node(4);
    tree->left = create_node(2);
    tree->right = create_node(6);
    tree->left->left = create_node(1);
    tree->left->right = create_node(3);
    tree->right->left = create_node(5);
    tree->right->right = create_node(7);
    tr(tree);

    int x;
    scanf("%i", &x);
    search(tree, x);

    free_tree(tree);
    return 0;
}
