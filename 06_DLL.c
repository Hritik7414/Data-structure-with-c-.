#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head,*new;

void create(){
    head = NULL;
    int choice = 1;
    struct node *temp; 
    while(choice){
        new = (struct node*) malloc(sizeof(struct node));
        printf("enter the data:");
        scanf("%d",&new->data);

        new->next = NULL;
        new->prev = NULL;

        if(head == NULL){
            head = temp =new;
        } 
        else{
            temp->next = new;
            new->prev = temp;
            temp = new;
        }
        printf("do yo want to continue ");
        scanf("%d",&choice);
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
    display();
    
    return 0;
}