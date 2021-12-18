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
void deletionAtBeg(){
    struct node *temp;
    temp = tail->next;
    if(tail == NULL){
        printf("list is empty");
    }
    else if(temp->next == temp){
        tail = NULL;
        free(temp);
    }
    else{
        tail->next = temp->next;
        free(temp);
    }
} 
void deletionAtEnd(){
    struct node *prev;
    struct node *current ;
    current = tail->next;
    while(current->next != tail->next){
        prev = current;
        current = current->next;
    } 
    if(tail == NULL){
        printf("list is empty");
    }
    else if(current->next == current){
        tail = NULL;
        free(current);
    }
    else{
        prev->next = tail->next;
        tail = prev;
        free(current);
    }

} 

void deletionAtPos(){
    struct node *current;
    struct node *nex;
    int pos ;
    int i=1;
    current = tail->next;
    printf("enter the position");
    scanf("%d",&pos);  
     if(pos == 1){
        deletionAtBeg();
    }
    else{
        while (i<pos-1)
        {
            current = current->next;
            i++;
        }
        nex = current->next;
        current->next = nex->next;
        free(nex);
    
    }
} 

int  length(){
    struct node *temp;
    temp = tail->next;
    int count = 1;
    while(temp->next != tail->next){
        
        temp = temp->next;
        count ++;
    }
    printf("length is :%d",count);
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
    deletionAtBeg();
    deletionAtEnd();
    deletionAtPos();
    
    display();
    printf("\n");
    length();

    return 0;
}