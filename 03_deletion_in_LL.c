#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node * deletionAtBeg(struct node *head){
    struct node *ptr=head;
    head = head->next;
    free(ptr);
    return head;
} 

struct node * deletionAtEnd(struct node * head){
    struct node *ptr=head;
    struct node *q ;
    while(ptr->next != NULL){
        q = ptr;
        ptr = ptr->next;
    }
    q->next  = NULL;
    free(ptr);
            
    return head;
} 

struct node *deletionAtIndex(struct node *head,int index){
    struct node *p=head;  
    while(--index){
        p = p->next;
    }
    struct node *q=p->next;
    p->next = q->next;
    free(q);
    return head;

}

void display(struct node *temp){
    while(temp != NULL){
        printf("%d",temp->data);
        temp = temp->next;
    }
}

int main(){

    struct node *head,*second,*third,*fourth;
    head = (struct node*) malloc(sizeof(struct node));
    second = (struct node*) malloc(sizeof(struct node));
    third = (struct node*) malloc(sizeof(struct node));
    fourth = (struct node*) malloc(sizeof(struct node));

    head->data = 6;
    head->next = second;

    second->data = 7;
    second->next = third;

    third->data = 8;
    third->next = fourth;

    fourth->data = 9;
    fourth->next = NULL;

    display(head);
    printf("\n");
    head =  deletionAtBeg(head);
    display(head);
    printf("\n");
    // head = deletionAtEnd(head);
    // display(head);
    head = deletionAtIndex(head,1);
    display(head);

    return 0;
}