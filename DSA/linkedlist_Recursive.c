#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *insertafter(struct node *head, int ele)
{
    if (head == NULL)
    {
        printf("Element not found \n");
    }
    else if (head->data == ele)
    {
        struct node *new = (struct node *)malloc(sizeof(struct node));
        int data;
        scanf("%d", &data);
        new->data = data;
        new->next = head->next;
        head->next = new;
    }
    else
    {
        head->next = insertafter(head->next, ele);
    }
    return head;
}

struct node *insertBefore(struct node *head, int ele)
{
    if (head == NULL)
    {
        printf("Element not found \n");
        return head;
    }
    else if (head->data == ele)
    {
        struct node *new = (struct node *)malloc(sizeof(struct node));
        int data;
        scanf("%d", &data);
        new->data = data;
        new->next = head;
        return new;
    }
    else
        head->next = insertBefore(head->next, ele);
    return head;
}

struct node *delete (struct node *head, int ele)
{
    if (head == NULL)
    {
        printf("Element not found \n");
    }
    else if (head->data == ele)
    {
        struct node *temp = head->next;
        free(head);
        return temp;
    }
    else
    {
        head->next = delete (head->next, ele);
    }
    return head;
}

void display(struct node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    return;
}

int main()
{
    struct node *head = NULL;
    while (1)
    {
        printf("Enter Your choice : ");
        printf("1.Insert   2.Delete   3.Exit \n");
        int choice, value, data;
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            if (head == NULL)
            {
                printf("linked list is empty .\n  Enter head data : ");
                scanf("%d", &value);
                head = (struct node *)malloc(sizeof(struct node));
                head->data = value;
                break;
            }
            else
            {
                printf("Enter Element : ");
                scanf("%d", &data);
                printf("Data Should be inserted after or before : 1.After 2.Before ");
                scanf("%d", &value);
                switch (value)
                {
                case 1:
                    head = insertafter(head, data);
                    break;
                case 2:
                    head = insertBefore(head, data);
                    break;
                }
                break;
            }
        case 2:
            if (head == NULL)
            {
                printf("Linked list is empty.");
            }
            else
            {
                printf("Enter Element : ");
                scanf("%d", &data);
                head = delete (head, data);
            }
            break;
        case 3:
            display(head);
            return 0;
        }
    }
    return 0;
}