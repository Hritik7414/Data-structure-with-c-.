#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
}; 
void length(struct node *head){
    struct node *p=head;
    int count = 0;
    while(p != NULL){
        count++;
        p = p->next;
    }
    printf("%d",count);

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
    length(head);
    
    return 0;
}