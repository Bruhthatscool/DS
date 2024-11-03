#include<stdio.h>
#include<stdlib.h>

struct Node{

        int data;
        struct Node* link;

};

struct Node* top;    // points to top node of stack

void push(){

        // user input to push into stack
        int n;
        printf("\nEnter item to insert : ");
        scanf("%d", &n);

        // get new node
        struct Node* ptr;
        ptr = (struct Node*)malloc(sizeof(struct Node*));
        ptr->data = n;
        ptr->link = top->link;
        top->link = ptr;

        display();

}

void pop(){

        // check for stack underflow
        if(top->link == NULL){

                printf("\nStack underflow");

        }
        else{

                struct Node* ptr = top->link;
                top->link = ptr->link;

                if(top->link == NULL){

                        printf("\nStack now empty");

                }

                else{

                        display();

                }
                free(ptr);    // free memory
        }

}

void display(){

        struct Node* ptr = top->link;

        printf("\nStack : ");
        while(ptr->link != NULL){

                printf("%d ", ptr->data);
                ptr = ptr->link;

        }
        printf("%d ", ptr->data);

}

void main(){

        top = (struct Node*)malloc(sizeof(struct Node*));
        top->link = NULL;

        int ch;
        printf("\nMENU\n\n1. Insert\n2. Delete\n3. exit\n");    // choices
        do{

                printf("\nChoice[1/2/3] : ");    // enter choice 
                scanf("%d", &ch);
                switch(ch){

                        case 1 : push();
                                 break;
                        case 2 : pop();
                                 break;

                }

        }while(ch == 1 || ch == 2);    // while user wants to continue

}

