#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    int data;
    struct node *next;
};

void insert(struct node **head, int data)
{
    struct node *ptr = *head;
    if (*head == NULL)
    {
        *head = (struct node *)malloc(sizeof(struct node));
        (*head)->data = data;
        (*head)->next = NULL;
        return;
    }
    while (ptr->next != NULL)
        ptr = ptr->next;
    ptr->next = (struct node *)malloc(sizeof(struct node));
    ptr->next->data = data;
    ptr->next->next = NULL;
    return;
}

void display(struct node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
    return;
}

struct node *reverse(struct node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    struct node *new_head = reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return new_head;
}

int main()
{
    struct node *head = NULL;
    int l = 1;
    while (l)
    {
        printf("Enter 1st ll : ");
        printf("1.Insert   2.Exit \n");
        int choice, value, data;
        scanf("%d", &choice);                               
        switch (choice)
        {
        case 1:
            printf("Enter Element : ");
            scanf("%d", &data);
            insert(&head, data);
            break;
        case 2:
            l = 0;
            break;
        }
    }
    display(head);
    head = reverse(head);
    display(head);
    return 0;
}