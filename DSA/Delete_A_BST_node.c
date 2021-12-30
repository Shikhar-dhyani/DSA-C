#include <stdio.h>
#include <stdlib.h>

typedef struct bstt
{
    int data;
    // bool thread;
    struct bstt *left;
    struct bstt *right;
} bst;

bst *insert(bst *root, int Data)
{
    if (root == NULL)
    {
        bst *new = (bst *)malloc(sizeof(bst));
        new->data = Data;
        new->left = NULL;
        new->right = NULL;
        return new;
    }
    if (Data >= root->data)
        root->right = insert(root->right, Data);
    else if (Data < root->data)
        root->left = insert(root->left, Data);
    return root;
}

void display(bst *root)
{
    if (root == NULL)
        return;
    display(root->left);
    printf("%d ", root->data);
    display(root->right);
    return;
}

bst *findINorder(bst *root)
{
    if (root == NULL)
        return NULL;
    if (root->right == NULL)
        return root;
    return findINorder(root->right);
}

bst *delete (bst *root, int data)
{
    if (root == NULL)
        return NULL;
    else if (data > root->data)
        root->right = delete (root->right, data);
    else if (data < root->data)
        root->left = delete (root->left, data);
    else
    {
        if ((!root->left) && (!root->right))
        {
            free(root);
            return NULL;
        }
        else if ((!root->left) || (!root->right))
        {
            if (root->left == NULL)
            {
                root->data = root->right->data;
                free(root->right);
                root->right = NULL;
            }
            else
            {
                root->data = root->left->data;
                free(root->left);
                root->left = NULL;
            }
        }
        else
        {
            bst *preInorder = findINorder(root->left);
            root->data = preInorder->data;
            root->left = delete (root->left, preInorder->data);
        }
    }
    return root;
}
int main()
{
    int Data;
    bst *root = NULL;

    while (1)
    {
        printf("Enter your choice :\n 1.insert node 2.delete node 3.display ");
        scanf("%d", &Data);
        switch (Data)
        {
        case 1:
            printf("Enter your Node Data");
            scanf("%d", &Data);
            root = insert(root, Data);
            break;
        case 2:
            printf("Enter Node Data to be deleted\n");
            scanf("%d", &Data);
            root = delete (root, Data);
            break;
        case 3:
            display(root);
            break;
        default:
            return 0;
        }
    }
    return 0;
}