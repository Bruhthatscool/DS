#include<stdio.h>
#include<stdlib.h>

struct Node{

        int data;
        struct Node* link;

};

void enqueue(struct Node* front, struct Node* rear){

        // user input to enqueue
        int n;
        printf("\nEnter item to insert : ");
        scanf("%d", &n);

        struct Node* ptr;
        ptr = (struct Node*)malloc(sizeof(struct Node));
        ptr->data = n;
        ptr->link = NULL;

        // check if first node
        if(rear->link == NULL){

                front->link = rear->link = ptr;

        }
        else{

                rear->link->link = ptr;
                rear->link = ptr;
        }

        display(front, rear);

}


void dequeue(struct Node* front, struct Node* rear){

        // check for queue underflow
        if(front->link == NULL){

                printf("\nQueue underflow");

        }
        else{

                // delete node
                struct Node* ptr = front->link;
                front->link = ptr->link;

                if(front->link == NULL){

                        printf("\nQueue now empty");
                        rear->link = NULL;

                }
                else{

                        display(front, rear);

                }
                free(ptr);    // free memory
        }

}

void display(struct Node* front, struct Node* rear){

        struct Node* ptr = front->link;

        printf("\nQueue : ");
        while(ptr->link != NULL){

                printf("%d ", ptr->data);
                ptr = ptr->link;

        }
        printf("%d ", ptr->data);

}

void main(){

        struct Node* front;
        front = (struct Node*)malloc(sizeof(struct Node));
        struct Node* rear;
        rear = (struct Node*)malloc(sizeof(struct Node));
        front->link = NULL;
        rear->link = NULL;

        int ch;
        // menu
        printf("\nMENU\n\n1. Insert\n2. Delete\n3. exit\n");
        do{

                printf("\nChoice[1/2/3] : ");    // enter choice
                scanf("%d", &ch);
                switch(ch){

                        case 1 : enqueue(front, rear);
                                 break;
                        case 2 : dequeue(front, rear);
                                 break;

                }

        }while(ch == 1 || ch == 2);   // while user wants to continue

}




