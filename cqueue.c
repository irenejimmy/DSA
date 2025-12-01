#include<stdio.h>                                                                                                                                                                                                            #include <stdio.h>

int main() {
    int n, item, op;
    int front = -1, rear = -1;

    printf("Enter the number of elements (max 5): ");
    scanf("%d", &n);

    if(n > 5 || n <= 0) {
        printf("Invalid size! Setting queue size to 5.\n");
        n = 5;
    }

    int queue[n];

    while(1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &op);

        switch(op) {

            case 1:
                if((rear + 1) % n == front) {
                    printf("Queue is full\n");
                } else {
                    printf("Enter element to enqueue: ");
                    scanf("%d", &item);

                    if(front == -1)
                        front = 0;

                    rear = (rear + 1) % n;
                    queue[rear] = item;

                    printf("%d enqueued\n", item);
                }
                break;

            case 2:
                if(front == -1) {
                    printf("Queue is empty\n");
                } else {
                    item = queue[front];

                    if(front == rear) {
                        front = rear = -1;
                    } else {
                        front = (front + 1) % n;
                    }

                    printf("%d dequeued\n", item);
                }
                break;

            case 3:
                if(front == -1) {
                    printf("Queue is empty\n");
                } else {
                    printf("Queue elements: ");
                    int i = front;
                    while(1) {
                        printf("%d ", queue[i]);
                        if(i == rear)
                            break;
                        i = (i + 1) % n;
                    }
                    printf("\n");
                }
                break;

            case 4:
                return 0; // exit program properly

            default:
                printf("Enter valid choice\n");
        }
    }

    return 0;
}
