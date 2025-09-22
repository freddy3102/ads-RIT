#include<stdio.h>
#include<stdlib.h>

int max=5;
int q[10], front= -1, rear = -1;

void enqueue(){
    int n;
    if((rear%max)+1 == front){
        printf("\nQueue full ");
    }
    else{
        printf("Enter the element : ");
        scanf("%d", &n);
        if (rear == -1 && front == -1){
            rear = 1;
            front = 1; 
        }
        else
            rear = (rear%max)+1;
        q[rear] = n;
    }

}

void dequeue(){
    int temp;
    if (front == -1){
        printf("\nQueue is empty");
    }
    else if(front == rear){
        temp = q[front];
        front = -1;
        rear = -1;
    }
    else{
        temp = q[front];
        front = (front%max)+1;
    }
    printf("%d is deleted",temp);
}

void traversal(){
    if(front < rear){
        for(int i = front; i<=rear; i++){
            printf("%d\n",q[i]);
        }
    }
    else{
        for(int i=front; i<=max; i++ ){
            printf("%d\n", q[i]);
        }
        for(int i=1; i<=rear; i++){
            printf("%d\n",q[i]);
        }

    }

}

void main(){
    int c;
    while(1){
        printf("\n---------------------------\n");
        printf("\n1.Enqueue\n2.Dequeue\n3.Traversal\n4.Exit\n");
        printf("Enter your choice : ");
        scanf("%d",&c);

        switch(c){
            case 1: enqueue();
                    break;
            case 2: dequeue();
                    break;
            case 3: traversal();
                    break;
            case 4: exit(0);

            default: printf("\n Invalid Choice");
                    break;
        }
    }
}