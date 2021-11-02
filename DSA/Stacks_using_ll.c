#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *insert(struct node *head)
{
    int data;
    printf("Enter data to be inserted : ");
    scanf("%d", &data);
    if (head == NULL)
    {
        head = (struct node *)malloc(sizeof(struct node));
        head->data = data;
        head->next = NULL;
        return head;
    }
    else
    {
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        temp->data = data;
        temp->next = head;
        return temp;
    }
}

struct node *pop(struct node *head)
{
    if (head == NULL)
        printf("Stack is Empty \n");
    else
    {
        struct node *temp = head->next;
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
    struct node *head = NULL, *temp = NULL;
    while (1)
    {
        printf("Enter Your choice : ");
        printf("1.PUSH   2.POP   3.TOP   4. EXIT\n");
        int choice, value, data;
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            head = insert(head); 
            break;
        case 2:
            head = pop(head);
            break;
        case 3:
            printf("%d is top element \n", head->data);
            break;
        case 4:
            display(head);
            return 0;
        }
    }
    return 0;
}