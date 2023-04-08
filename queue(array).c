#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 30

struct Queue{
	int items[MAXSIZE];
	int front;
	int rear;
};

typedef struct Queue queue;


void init(queue *q){
	q->front=-1;
	q->rear=-1;
}

int isFull(queue *q) {
  return (q->rear == MAXSIZE -1);
}

int isEmpty(queue *q) {
  return (q->front==-1 && q->rear== -1);
}

void enqueue(queue *q, int value){
	if(isFull(q)){
		printf("queue is full\n");
	}else{
		if(isEmpty(q)){
			q->front=q->rear=0;
		}else{
			q->rear++;
		}
		q->items[q->rear]=value;
		printf("insterted %d into queue\n",value);
	}
}

void dequeue(queue *q){
	if(isEmpty(q)){
		printf("queue is empty\n");
	}else{
		printf("removed %d from queue\n",q->items[q->front]);
		if(q->front==q->rear){
			q->front=q->rear=-1;
		}else{
			q->front++;
		}
	}
}

void printQueue(queue *q){
	int i;
	if(isEmpty(q)){
		printf("queue is empty\n");
	}else{
		printf("queue elements are ");
		for(i=q->front;i<=q->rear;i++){
			printf("%d ",q->items[i]);
		}
		printf("\n");
	}
}

int main() {
  queue q;
  init(&q);

  enqueue(&q, 1);
  enqueue(&q, 2);
  enqueue(&q, 3);

  printQueue(&q);

  dequeue(&q);

  printQueue(&q);

  return 0;
}














