#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *tail;

void create()
{
   struct node *new ; 
   tail = NULL;
   int choice =1;
   while(choice){
    new = (struct node *)malloc(sizeof(struct node));
    printf("enter data:");
    scanf("%d",&new->data); 
    new->next = NULL;
    if(tail == NULL){
        tail = new;
        tail->next = new;
    }
    else{
        new->next = tail->next;
        tail->next = new;
        tail = new;
    }
    printf("press 1 to continue and 0 to exit");
    scanf("%d",&choice);
   }

}

void display()
{
    struct node *temp;
    temp = tail->next;
    while(temp->next != tail->next){
        printf("%d",temp->data);
        temp = temp->next;
    }
    printf("%d",tail->data);
}

int main()
{
    create();
    display();

    return 0;
}