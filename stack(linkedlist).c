#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int data;
	struct Node *next;
}Node;

//yeii duguum olustur
Node *newNode(int data){
	Node *node=(Node *)malloc(sizeof(Node));
	if(node==NULL){
		printf("Allocation error!");
	}else{
		node->data=data;
		node->next=NULL;
		return node;
	}
}

typedef struct Stack{
	struct Node *head;//stack basi
	int size;//stack boyut
}Stack;

Stack *newStack(){
	Stack *stack=(Stack *)malloc(sizeof(Stack));
	if(stack==NULL){
		printf("Allocation error!");
	}else{
		stack->head=NULL;
		stack->size=0;
		return stack;
	}
}

//stack push 
void push(Stack *stack, int data){
	Node *node = newNode(data);
	node->next=stack->head;
	stack->head=node;
	stack->size++;
}

int pop( Stack* stack) {
   if (stack->head == NULL) {
      printf("Stack boþ.\n");
      return -1;
   }
   int data = stack->head->data;
   Node* temp = stack->head;
   stack->head = stack->head->next;
   free(temp);
   stack->size--;
   return data;
}

int peek(Stack *stack){
	if(stack->head==NULL){
		printf("stack is empty\n");
		//return -1;
	}return stack->head->data;
}


int isEmpty( Stack* stack) {
   return stack->head == NULL;
}


int size(Stack* stack) {
   return stack->size;
}


void printStack(Stack *stack){
	Node *tmp=stack->head;
	
	printf("Stack\n");
	printf("--------\n");
	while(tmp!=NULL){
		printf("   %d\n",tmp->data);
		tmp=tmp->next;
	}
		printf("--------\n");
}

int main() {
   Stack* stack = newStack();

   push(stack, 1);
   push(stack, 2);
   push(stack, 3);
   push(stack, 4);
   push(stack, 5);

   printStack(stack);

   printf("ustteki eleman: %d\n", peek(stack));

   printf("cikarilan eleman: %d\n", pop(stack));
   printf("cikarilan eleman: %d\n", pop(stack));

   printStack(stack);

   return 0;
}










