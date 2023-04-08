#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 30

typedef struct Stack{
	int top;
	int items[MAXSIZE];
};


//Yeni bir stack olusturmak icin 
	Stack *newStack(){
	Stack *stack = (Stack*)malloc(sizeof(Stack));
	if(stack==NULL){
		printf("Allocation error!\n");
		exit(1);
	}else{
		stack->top=-1;
		return stack;
	}
}

//Stack dolu mu ve bos mu kontrolleri 
int isFull(Stack *stack){
	return stack->top==MAXSIZE-1;
}

int isEmpty(Stack *stack){
	return stack->top==-1;
}

//Stacke eleman pushlama
void push(Stack *stack, int data){
	if(isFull(stack)){
		printf("Stack is full!\n");
	}else{
		stack->top++;
		stack->items[stack->top]=data;
	}
}

//Stackten pop yapma
int pop(Stack *stack){
	if(isEmpty(stack)){
		printf("Stack is empty!\n");
		return -1;
	}else{
		int data = stack->items[stack->top];
		stack->top--;
		return data;
	}
}

//stackteki ust elemani gosterir
int peek(Stack *stack){
	if(isEmpty(stack)){
		printf("stack is empty!\n");
		return -1;
	}else{
		return stack->items[stack->top];
	}
}

//stack printleme
void printStack(Stack *stack){
	int i;
	printf("Stack\n");
	//printf("[\  ");
	printf("---------\n");
	for(i=0;i<=stack->top;i++){
		printf("    %d\n",stack->items[i]);
	}
	//printf("]\n");
	printf("---------\n");
}

int main() {
   Stack* stack = newStack();
   push(stack,1);
   push(stack,2);
   push(stack,3);
   push(stack,4);
   push(stack,5);

   printStack(stack);

   printf("tstteki eleman: %d\n", peek(stack));

   printf("cikan eleman: %d\n", pop(stack));
   printf("cikan eleman: %d\n", pop(stack));

   printStack(stack);

   return 0;
}



