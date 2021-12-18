#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

void display(struct node *temp){
    while(temp != NULL){
        printf("%d",temp->data);
        temp = temp->next;
    }
}

int main(){

    struct node *first,*second,*third;
    first = (struct node*) malloc(sizeof(struct node));
    second = (struct node*) malloc(sizeof(struct node));
    third = (struct node*) malloc(sizeof(struct node));

    first->data = 6;
    first->next = second;

    second->data = 7;
    second->next = third;

    third->data = 8;
    third->next = NULL;

    display(first);

    return 0;
}