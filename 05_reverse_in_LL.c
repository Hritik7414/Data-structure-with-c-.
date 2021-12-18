 #include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
}; 
struct node *head; 
struct node * reverse(struct node *head){

struct node *prevnode,*current,*nextnode;
prevnode=NULL;
current=nextnode=head; 
while(nextnode!=NULL)
{
	nextnode=nextnode->next;
	current->next=prevnode;
	prevnode=current;
	current=nextnode;
}
	head=prevnode;
    return head;
} 

void display(struct node *temp){
    while(temp != NULL){
        printf("%d",temp->data);
        temp = temp->next;
    }
}

int main(){

    struct node *head ,*second,*third; 

    head = (struct node*) malloc(sizeof(struct node));
    second = (struct node*) malloc(sizeof(struct node));
    third = (struct node*) malloc(sizeof(struct node));

    head->data = 6;
    head->next = second;

    second->data = 7;
    second->next = third;

    third->data = 8;
    third->next = NULL;

    // display(head);
    // printf("\n");
    head = reverse(head);
    display(head);

    return 0;
} 
