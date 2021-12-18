#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head, *tail;

void create()
{
    struct node *new;
    head = NULL;
    int choice = 1;
    while (choice)
    {
        new = (struct node *)malloc(sizeof(struct node));
        printf("enter the data:");
        scanf("%d", &new->data);
        new->next = NULL;
        new->prev = NULL;

        if (head == NULL)
        {
            head = tail = new;
        }
        else
        {
            tail->next = new;
            new->prev = tail;
            tail = new;
        }
        printf("do you want to continue");
        scanf("%d", &choice);
    }
} 
void reverse(){
    struct node*current,*nextnode;
    current = head;
    while(current != NULL){
        nextnode = current->next;
        current->next = current->prev;
        current->prev = nextnode; 
        current = nextnode;
    } 
    current = head;
    head = tail;
    tail = current;
}

void display()
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d", temp->data);
        temp = temp->next;
    }
}

int main()
{
    create(); 
    reverse();
    display();

    return 0;
}
