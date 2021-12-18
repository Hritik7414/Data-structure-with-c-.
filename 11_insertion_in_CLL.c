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
void insertionAtBeg(){
    struct node *new;
    new = (struct node *)malloc(sizeof(struct node));
    printf("enter data to be inserted at Beg :");
    scanf("%d",&new->data);
    new->next = NULL;
    if(tail == NULL){
        tail = new;
        tail->next = new;
    }
    else{
        struct node *temp;
        temp = tail->next;
        new->next = temp;
        tail->next = new;
    }
}
void insertionAtEnd(){
    struct node *new;
    new = (struct node *)malloc(sizeof(struct node));
    printf("enter data to be inserted at End :");
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
}

void insertionAtPos(){
    struct node *new; 
    int pos;
    new = (struct node *)malloc(sizeof(struct node));
    printf("enter data to be inserted at pos :");
    scanf("%d",&new->data);
    new->next = NULL; 
    printf("enter the pos :");
    scanf("%d",&pos); 
    int i =1;
    struct node *temp;
    temp = tail->next;
    while(i < pos-1)
    {
        temp = temp->next;
        i++;
    }
    if(pos == 1){
        insertionAtBeg();
    } 
    else{
        new->next = temp->next;
        temp->next = new;
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
    //insertionAtBeg();
    insertionAtPos();
   // insertionAtEnd();
    display();

    return 0;
}