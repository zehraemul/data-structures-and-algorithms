#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXSIZE 100

typedef struct BSTNode{
    int data;
    struct BSTNode* left;
    struct BSTNode* right;
}BSTNode;

typedef struct Stack{
	int top;
	int items[MAXSIZE];
}Stack;

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
 BSTNode* search( BSTNode* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }
    if (data < root->data) {
        return search(root->left, data);
    }
    return search(root->right, data);
    
}

int isFull(Stack *stack){
	return stack->top==MAXSIZE-1;
}

int isEmpty(Stack *stack){
	return stack->top==-1;
}

void push(Stack *stack, int data){
	if(isFull(stack)){
		printf("Stack is full!\n");
	}else{
		stack->top++;
		stack->items[stack->top]=data;
	}
}

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

void printStack(Stack *stack){
	int i;
	printf("---------\n");
	for(i=0;i<=stack->top;i++){
		printf("    %d\n",stack->items[i]);
	}
	printf("---------\n");
}

BSTNode* createNode(int data) {
    BSTNode* node = (BSTNode*)malloc(sizeof(BSTNode));
    node->data=data;
    node->left= NULL;
    node->right = NULL;
    return node;
}

BSTNode* insert(BSTNode* root,int data) {
    if (root==NULL) {
        root = createNode(data);
    } else if (data <= root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

BSTNode* createBST(int m,int n) {
	srand(time(NULL));
	int i;
    BSTNode* root=NULL;
    int data;
    for (i = 0; i< m; i++) {
        data = rand() % n + 1;
        root = insert(root, data);
    }
    return root;
}

void printBST(BSTNode* root) {
    if (root != NULL) {
        printBST(root->left);
        printf("%d ", root->data);
        printBST(root->right);
    }

}

BSTNode* minValueNode(BSTNode* node) {
    BSTNode* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

BSTNode* deleteNode(BSTNode* root, int node, Stack* stack) {
    if (root == NULL) {
        return root;
    }

    if (node < root->data) {
        root->left = deleteNode(root->left, node, stack);
    }
    else if (node > root->data) {
        root->right = deleteNode(root->right, node, stack);
    }
    else {
        if (root->left == NULL) {
            BSTNode* temp = root->right;
            push(stack, root->data);
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            BSTNode* temp = root->left;
            push(stack, root->data);
            free(root);
            return temp;
        }
        else {
            BSTNode* temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data, stack);
        }
    }
    return root;
}

BSTNode* updateNode(BSTNode* root, int data,int new_value) {
    if(root== NULL) {
        return root;
    }
    else if(data<root->data) {
        root->left= updateNode(root->left, data, new_value);
    }
    else if(data>root->data) {
        root->right=updateNode(root->right, data, new_value);
    }
    else{
        root->data=new_value;
    }
    return root;
}



int main(){
	printf("** welcome to the FALLING FRUITS game! **\n");
	int n, m;
	int k,p,num;
    printf("enter the maximum weight of the fruits (N): ");
    scanf("%d", &n);
    printf("enter the number of fruits (M): ");
    scanf("%d", &m);
    BSTNode* root = createBST(m,n);
    printf("Binary tree : \n");
	printBST(root);
    printf("\n\n");
	 Stack* stack = newStack();
    while(root!=NULL){
    	printf("enter the weight of the fruit you want to drop (k) ");
    	scanf("%d",&k);
    	printf("enter the shooting power (p) ");
    	scanf("%d",&p);
    	printf("here is the weight and shot power of the fruit you chose. fruit (k) -> %d shooting power (p) -> %d\n",k,p);
    	num=(k-p);
    	if(num>0){
    		while(num>0){
    		updateNode(root,k,num);
    		num = num-p;
			}
			updateNode(root,k,num);		
			root=deleteNode(root,k,stack);
   		 if(root!=NULL) printBST(root);
        }else{
            root = deleteNode(root,k,stack);
            if(root!=NULL) printBST(root);
        }
        printf("\n");
    }
    	if(root!=NULL) {
    	deleteNode(root,k,stack);
			}else{
		printf("you dropped all the fruit on the tree!\n");
	}
	printf("fruits in the bucket:\n");
	printStack(stack);
	
	return 0;

}

