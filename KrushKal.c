#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
typedef struct N
{
    struct N *next;
    struct ver *orig;
    int weight;
    int vertexno;
} node;

typedef struct ver
{

    int Data;
    node *pt;

} vertex;

typedef struct gra
{

    int v;
    vertex *arr;

} graph;

typedef struct LIST
{
    int sr, des, weight;
    struct LIST *next;
} list;

graph *create(int a)
{
    graph *g = (graph *)malloc(sizeof(graph));
    g->v = a;
    g->arr = (vertex *)malloc(sizeof(vertex) * a);
    for (int i = 0; i < a; i++)
    {
        printf("Enter data of %d node :", i + 1);
        scanf("%d", &g->arr[i].Data);
        g->arr[i].pt = NULL;
    }
    return g;
}

void addconnection(graph *g, int sr, int des, int w)
{
    node *new = (node *)malloc(sizeof(node));
    new->orig = &(g->arr[des - 1]);
    new->weight = w;
    new->vertexno = des;
    node *temp = g->arr[sr - 1].pt;
    new->next = temp;
    g->arr[sr - 1].pt = new;
}

void print(graph *g)
{
    printf("\n\nGraph is :\n");
    for (int i = 0; i < g->v; i++)
    {
        printf("%d node data is %d and is connected to : \n", i + 1, g->arr[i].Data);
        node *temp = g->arr[i].pt;
        if (temp == NULL)
            printf("No other vertex\n");
        else
            while (temp)
            {
                printf("%d node (Data is %d) and weight of edge between them is %d \n", temp->vertexno, temp->orig->Data, temp->weight);
                temp = temp->next;
            }
        printf("\n");
    }
    printf("\n\n Graph is printed\n\n\n\n\n");
}

void select(list *head, int n)
{
    if (head->next == NULL)
    {
        free(head);
        return;
    }
    if (n == 0)
    {
        select(head->next, 0);
        free(head);
        return;
    }
    if (n == 1)
    {
        select(head->next, 0);
        head->next = NULL;
        return;
    }
    select(head->next, n - 1);
    return;
}
list *sortl(list *head, int sr, int des, int w)
{
    if (head == NULL)
    {
        head = (list *)malloc(sizeof(list));
        head->sr = sr;
        head->des = des;
        head->next = NULL;
        head->weight = w;
        return head;
    }
    if (head->weight > w)
    {
        list *temp = (list *)malloc(sizeof(list));
        temp->sr = sr;
        temp->des = des;
        temp->next = head;
        temp->weight = w;
        return temp;
    }
    head->next = sortl(head->next, sr, des, w);
    return head;
}

int find(int parent[], int i)
{
    if (parent[i] == -1)
        return i;
    return find(parent, parent[i]);
}

list *make_list(graph *g)
{
    list *head = NULL;
    int *parent = (int *)malloc(g->v * sizeof(int));
    memset(parent, -1, sizeof(int) * g->v);
    for (int i = 0; i < g->v; i++)
    {
        node *temp = g->arr[i].pt;
        if (temp != NULL)
            while (temp)
            {
                int check1 = find(parent, i);
                int check2 = find(parent, temp->vertexno - 1);
                if ((check1 == -1 && check2 == -1) || check1 != check2)
                {
                    head = sortl(head, i + 1, temp->vertexno, temp->weight);
                    parent[temp->vertexno - 1] = i;
                }
                temp = temp->next;
            }
    }
    return head;
}
void printlist(list *head)
{
    if (head == NULL)
        return;
    printf("edge: %d --%d   weight : %d\n", head->sr, head->des, head->weight);
    printlist(head->next);
}
int main()
{
    int v;
    printf("Enter No. of Nodes/vertex of graph \n");
    scanf("%d", &v);
    graph *Graph = create(v);
    while (1)
    {
        int ch, sr, des, weight;
        printf("Enter 1 to add connection and 0 to exit:\n");
        scanf("%d", &ch);
        if (ch == 0)
            break;
        printf("Enter Node No.s to be connected and edge weight:\n");
        scanf("%d%d%d", &sr, &des, &weight);
        addconnection(Graph, sr, des, weight);
    }
    print(Graph);
    list *head = make_list(Graph);
    printlist(head);
    return 0;
}