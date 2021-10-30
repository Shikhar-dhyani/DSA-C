#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    int data;
    struct Node *next;
};

struct node *insertafter(struct node *head, int ele)
{
    int data;
    struct node *ptr = head;
    while (ptr != NULL && ptr->data != ele)
        ptr = ptr->next;
    if (ptr == NULL)
    {
        printf("Element not found \n");
        return head;
    }
    struct node *new = (struct node *)malloc(sizeof(struct node));
    printf("Enter data : ");
    scanf("%d", &data);
    new->data = data;
    new->next = ptr->next;
    ptr->next = new;
    return head;
}

struct node *insertBefore(struct node *head, int ele)
{

    int data;
    struct node *new = (struct node *)malloc(sizeof(struct node));
    struct node *ptr = head, *ptr1 = NULL;
    if (head->data == ele)
    {
        printf("Enter data : ");
        scanf("%d", &data);
        new->data = data;
        new->next = head;
        head = new;
        return head;
    }
    while (ptr != NULL && ptr->data != ele)
    {
        ptr1 = head;
        ptr = ptr->next;
    }
    if (ptr == NULL)
    {
        printf("Element not found \n");
        return head;
    }
    printf("Enter data : ");
    scanf("%d", &data);
    new->data = data;
    new->next = ptr;
    ptr1->next = new;
    return head;
}

struct node *delete (struct node *head, int ele)
{
    struct node *temp;
    if (head->data == ele)
    {
        temp = head->next;
        free(head);
        head = temp;
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
                printf("Linked list is empty.");
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
