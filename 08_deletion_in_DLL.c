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

void deletionAtBeg()
{
    struct node *temp;
    if (head == NULL)
    {
        printf("list is empty");
    }
    else
    {
        temp = head;
        head = head->next;
        temp->next->prev = NULL;
        free(temp);
    }
}

void deletionAtEnd()
{
    struct node *temp;
    temp = tail;
    tail->prev->next = NULL;
    tail = temp->prev;
    free(temp);
} 

void deletionAtPos(){
    struct node *temp;
    int pos; 
    int i=1;
    temp = head;
    printf("enter the position:");
    scanf("%d",&pos);  
    while (i < pos-1){
        temp = temp->next;
        i++;
    } 
    if(head == NULL){
        printf("list is empty");
    } 
    else{
        struct node *ptr; 
        ptr = temp->next;
        temp->next = ptr->next;
        ptr->next->prev = temp;
        free(ptr);
    }

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
    deletionAtBeg();
    deletionAtEnd(); 
    deletionAtPos();
    display();

    return 0;
}
