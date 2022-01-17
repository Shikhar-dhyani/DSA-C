#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct bstt
{
    int data, height;
    struct bstt *left;
    struct bstt *right;
} bst;

int height(bst *root)
{
    if (root == NULL)
        return 0;
    return root->height;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int getBalance(bst *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}
bst *rightRotate(bst *y)
{
    bst *x = y->left;
    bst *T2 = x->right;
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(height(y->left),
                    height(y->right)) +
                1;
    x->height = max(height(x->left),
                    height(x->right)) +
                1;

    // Return new root
    return x;
}
bst *leftRotate(bst *x)
{
    bst *y = x->right;
    bst *T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(height(x->left),
                    height(x->right)) +
                1;
    y->height = max(height(y->left),
                    height(y->right)) +
                1;

    // Return new root
    return y;
}

bst *insert(bst *root, int Data)
{
    if (root == NULL)
    {
        bst *new = (bst *)malloc(sizeof(bst));
        new->data = Data;
        new->height = 1;
        new->left = NULL;
        new->right = NULL;
        return new;
    }
    if (Data >= root->data)
        root->right = insert(root->right, Data);
    else if (Data < root->data)
        root->left = insert(root->left, Data);
    else
        return root;
    root->height = height(root);
    int balance = getBalance(root);
    if (balance > 1 && Data < root->left->data)
        return rightRotate(root);
    if (balance < -1 && Data > root->right->data)
        return leftRotate(root);
    if (balance > 1 && Data > root->left->data)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (balance < -1 && Data < root->right->data)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}
void display(bst *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->data);
    display(root->left);
    display(root->right);
    return;
}

int main()
{
    int Data;
    bst *root = NULL;
    // while (1)
    // {
    //     printf("Enter 1 to add Node  0 to exit\n");
    //     scanf("%d", &Data);
    //     if (Data == 0)
    //         break;
    //     printf("Enter Data: ");
    //     scanf("%d", &Data);
    //     root = insert(root, Data);
    // }
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40); 
    root = insert(root, 50);
    root = insert(root, 25);
    display(root);

    return 0;
}