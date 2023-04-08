#include <stdio.h>
#include <stdlib.h>

struct Node{
  int data;
  struct Node *next;
};

struct Queue {
  struct Node *front;
  struct Node *rear;
};

typedef struct Queue queue;
typedef struct Node node;

void init(queue *q) {
  q->front = NULL;
  q->rear = NULL;
}

int isEmpty(queue *q) {
  return (q->front == NULL);
}

void enqueue(queue *q, int value) {
  node *newNode = ( node*) malloc(sizeof( node));
  newNode->data = value;
  newNode->next = NULL;

  if (isEmpty(q)) {
    q->front = q->rear = newNode;
  } else {
    q->rear->next = newNode;
    q->rear = newNode;
  }
  printf("inserted %d into queue\n", value);
}

void dequeue(queue *q) {
  if (isEmpty(q)) {
    printf("queue is empty\n");
  } else {
     node *temp = q->front;
    printf("removed %d from queue\n", temp->data);

    if (q->front == q->rear) {
      q->front = q->rear = NULL;
    } else {
      q->front = q->front->next;
    }

    free(temp);
  }
}

void display(queue *q) {
  if (isEmpty(q)) {
    printf("queue is empty\n");
  } else {
     node *temp = q->front;
    printf("queue elements are: ");
    while (temp != NULL) {
      printf("%d ", temp->data);
      temp = temp->next;
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

  display(&q);
  dequeue(&q);
  display(&q);
  return 0;
}

