#include <stdio.h>
#include <stdlib.h>
#include<math.h>

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
void reverse(){
    struct  node *prev,*current,*nextnode;
    current = tail->next;
    nextnode = current->next;
    if(tail== NULL){
        printf("list is empty");
    }
    else{
        while(current != tail){
            prev = current;
            current = nextnode;
            nextnode = current->next;
            current->next = prev;
        }
        nextnode->next = tail;
        tail =nextnode;
    }
}


void display()
{
    struct node *temp;
    temp = tail->next;
0    while(temp->next != tail->next){
        printf("%d",temp->data);
        temp = temp->next;
    }
    printf("%d",tail->data);
}

int main()
{

    create();
  
    display();
    printf("\n");
    reverse();
    display();
 

    return 0;
}