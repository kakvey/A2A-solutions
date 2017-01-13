#include<stdio.h>
#include<stdlib.h>
/*Queue has five properties. capacity stands for the maximum number of elements Queue can hold.
  Size stands for the current size of the Queue and elements is the array of elements. front is the
 index of first element (the index at which we remove the element) and rear is the index of last element
 (the index at which we insert the element) */
typedef struct Queue
{
        int capacity;
        int size;
        int front;
        int rear;
        int *elements;
}Queue;
/* crateQueue function takes argument the maximum number of elements the Queue can hold, creates
   a Queue according to it and returns a pointer to the Queue. */
Queue * createQueue(int maxElements)
{
        /* Create a Queue */
        Queue *Q;
        Q = (Queue *)malloc(sizeof(Queue)); // not understand
        /* Initialise its properties */
        Q->elements = (int *)malloc(sizeof(int)*maxElements); // not understand
        Q->size = 0;
        Q->capacity = maxElements;
        Q->front = 0;
        Q->rear = -1;
        /* Return the pointer */
        return Q;
}
void Dequeue(Queue *Q)
{
        /* If Queue size is zero then it is empty. So we cannot pop */
        if(Q->size==0)
        {
                printf("Queue1 is Empty\n");
                /* If Queue size is zero then it is empty. So we cannot pop */
				/* If Queue size is zero then it is empty. So we cannot pop */
                return;
        }
        /* Removing an element is equivalent to incrementing index of front by one */
        else
        {
                Q->size--;
                Q->front++;
                /* As we fill elements in circular fashion */
                if(Q->front==Q->capacity)
                {
                        Q->front=0;
                }
        }
        return;
}
int front(Queue *Q)
{
        if(Q->size==0)
        {
                printf("Queue2 is Empty\n");
                exit(0);
        }
        /* Return the element which is at the front*/
        return Q->elements[Q->front];
}
void Enqueue(Queue *Q,int element)
{
        /* If the Queue is full, we cannot push an element into it as there is no space for it.*/
        if(Q->size == Q->capacity)
        {
                printf("Queue3 is Full\n");
        }
        else
        {
                Q->size++;
                Q->rear = Q->rear + 1;
                /* As we fill the queue in circular fashion */
                if(Q->rear == Q->capacity)
                {
                        Q->rear = 0;
                }
                /* Insert the element in its rear side */ 
                Q->elements[Q->rear] = element;
        }
        return;
}
// bcoz of size of real is -1 so if capacity of queue are 8 but it create 9
int main()
{
        Queue *Q = createQueue(5);
        Enqueue(Q,4);
        Enqueue(Q,2);
        Enqueue(Q,3);
        Enqueue(Q,1);
        Dequeue(Q);
        Dequeue(Q);
        
        printf("Front1j element is %d\n",front(Q));
        Enqueue(Q,5);
        Enqueue(Q,7);
        Enqueue(Q,8);
        Enqueue(Q,9);
        Enqueue(Q,10);
        Dequeue(Q);
        Dequeue(Q);
        Dequeue(Q);
        Dequeue(Q);
        Dequeue(Q);
        
        printf("Front element is %d\n",front(Q));
}


