#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node * insertionAtBeg(struct node *head,int data){
    struct node *new;
    new = (struct node *)malloc(sizeof(struct node));
    new->data = data;
    new->next = head;
    head = new;
    return head;
    
} 

struct node * insertionAtIndex(struct node *head,int index,int data){
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = data;
    struct node *p = head;
    
    while (--index)
    {
        p = p->next;
        
    }
    new->next = p->next;
    p->next = new;

    return head;
    
}

struct node * insertionAtEnd(struct node * head,int data){
    struct node *new ;
    new = (struct node *)malloc(sizeof(struct node));
    new->data = data;
    new->next = NULL;

    struct node *ptr = head;
    while(ptr->next != NULL){
        ptr = ptr->next;
    }

    ptr->next = new;
    return head;
}

void display(struct node *temp){
    while(temp != NULL){
        printf("%d",temp->data);
        temp = temp->next;
    }
}

int main(){

    struct node *head,*second,*third;
    head = (struct node*) malloc(sizeof(struct node));
    second = (struct node*) malloc(sizeof(struct node));
    third = (struct node*) malloc(sizeof(struct node));

    head->data = 6;
    head->next = second;

    second->data = 7;
    second->next = third;

    third->data = 8;
    third->next = NULL;

    display(head);
    printf("\n");
    head = insertionAtBeg(head,3);

    display(head);
    printf("\n");
    head = insertionAtEnd(head,1);
    display(head); 

    printf("\n");
    head = insertionAtIndex(head,2,2);
    display(head);

    return 0;
}