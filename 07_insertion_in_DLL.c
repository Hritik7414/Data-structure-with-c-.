#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head,*tail;

void create(){
    head = NULL;
    int choice = 1;
    struct node *new; 
    while(choice){
        new = (struct node*) malloc(sizeof(struct node));
        printf("enter the data:");
        scanf("%d",&new->data);

        new->next = NULL;
        new->prev = NULL;

        if(head == NULL){
            head = tail =new;
        } 
        else{
            tail->next = new;
            new->prev = tail;
            tail = new;
        }
        printf("do yo want to continue ");
        scanf("%d",&choice);
    }

}

void insertionAtBeg(){
    
    struct node *new;
    new = (struct node *)malloc(sizeof(struct node));
    printf("enter data to insert at beginning ");
    scanf("%d",&new->data);

    new->next = NULL;
    new->prev = NULL; 

    head->prev = new;
    new->next = head;
    head = new; 

}

void insertionAtEnd(){
    struct node *new;
    new =  (struct node*)malloc(sizeof(struct node));
    printf("enter data to be inserted at end");
    scanf("%d",&new->data);

    new->next = NULL;
    new->prev = NULL;

    new->prev = tail;
    tail->next = new;
    tail = new;
}


void insertionAtPos(){
    struct node *new;
    int pos;
    new =  (struct node*)malloc(sizeof(struct node));
    printf("enter data to be inserted at pos");
    scanf("%d",&new->data); 
    new ->next= NULL;
    new ->prev = NULL;

    printf("\nenter the position:");
    scanf("%d",&pos); 
    
    if(pos == 1){
        insertionAtBeg();
    }
    else{
        struct node *ptr= head;
        int i = 1;
        while(i < pos-1){
            ptr = ptr->next;
            i++;
        }
        new->prev = ptr;
        new->next = ptr->next;
        ptr->next = new;
        new->next->prev = new; 
    }
    
}

void display(){
    struct node *temp=head;
    while(temp != NULL){
        printf("%d",temp->data);
        temp = temp->next;
    }

}

int main(){

    create();
    insertionAtBeg();
    insertionAtEnd();
    insertionAtPos();
    display();
    
    return 0;
} 
