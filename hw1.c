#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node{
	int value;
	struct node *next;
	struct node *prev;
}Node;

int carkKontrol(Node *head, int tmp){
	int var=1;
	Node *temp = head;
	while(temp->next != NULL) {
		if(temp->value == tmp) {
			var = 0;
		}
		temp= temp->next;
	}
	return var;
}

Node *createNewNode(int value){
	Node *newNode=(Node*)malloc(sizeof(Node));
	if(newNode==NULL){
		printf("Allocation error");
	}
	newNode->value=value;
	newNode->next=NULL;
	newNode->prev=NULL;
	return newNode;	
}

void createList(Node **head , Node **head1, Node **head2, int M, int N, int ortak_sayi,int indeks){
	Node *tmp1 = (*head1);
	Node *tmp2 = (*head2);
	int i, random;
	int flag=0, flag1, flag2;
	for(i=0;i<M;i++){
		while(random==ortak_sayi || !carkKontrol(*head, random) || flag==0){
			random=rand()%N+1;
			flag1 = carkKontrol(tmp1, random);
			flag2 = carkKontrol(tmp2, random);
			flag = flag1 + flag2;
			//printf("\n flag = %d\n",flag);
		}
		if((i+1)==indeks){
			Node *newNode=createNewNode(ortak_sayi);
			newNode->next=(*head);
			(*head)->prev=newNode;
			(*head)=newNode;
		}/*else if(i==0){
			Node *newNode=createNewNode(random);
			newNode->next=(*head);
			(*head)->prev=newNode;
			(*head)=newNode;
		}*/else{
//		    flag=carkKontrol(*head, random);
//		    while(!flag) {
//		    	random=rand()%N+1;
//		    	flag=carkKontrol(*head, random);
//
//			}

			Node *newNode=createNewNode(random);
			newNode->next=(*head);
			(*head)->prev=newNode;
			(*head)=newNode;
		}
	}
}
void printList(Node **head, int M){
	Node *current = (*head);
	int i;
	for(i = 0; i<M; i++){
		printf("%d ",current->value);
		current=current->next;
	}
	/*
	while(current->next!=NULL){
		printf("%d ",current->value);
		current=current->next;
	}*/
	printf("\n");
}

int  *ortak_sayiBul(Node* head1, Node* head2,  Node* head3, int ortak_sayi,int M) {
	int *array=(int *)malloc(sizeof(int)*3);
	int i;
    int indeks1=0, indeks2=0, indeks3=0;
    //while (head1 != NULL || head2 != NULL || head3 != NULL) {
    for(i=0;i<M;i++){
    	
        if (head1->value == ortak_sayi) {
            printf("Ortak sayi birinci linked listte %d. eleman\n", indeks1+1);
			array[0]=indeks1;
        }
        if ( head2->value == ortak_sayi) {
            printf("Ortak sayi ikinci linked listte %d. eleman\n", indeks2+1);
			array[1]=indeks2;
        }
        if ( head3->value == ortak_sayi) {
            printf("Ortak sayi ucuncu linked listte %d. eleman\n", indeks3+1);
			array[2]=indeks3;
        }
        
            head1 = head1->next;
			head2 = head2->next;
			head3 = head3->next;
            indeks1++;
            indeks2++;
            indeks3++;
        
    }
   
    
    
    return array;
}

void kaydir(Node **head, int kaydirma_sayisi,int M) {
	int i;/*
  if (*head==NULL||kaydirma_sayisi ==0){
  	printf("kaydirma yapilmadi.\n");
  }
   Node *son = *head;
  int boyut=1;
  while (son->next != NULL){
    son = son->next;
    boyut++;
  }
  son->next = *head;
  int yeni_baslangic =boyut-(kaydirma_sayisi-boyut);
   Node *yeni_baslangic_noktasi = *head;
  for (i=0; i<yeni_baslangic;i++){
    yeni_baslangic_noktasi = yeni_baslangic_noktasi->next;
  }
  *head=yeni_baslangic_noktasi;
  son=*head;
  for (i=1; i< boyut; i++){
    son = son->next;
  }
  son->next=NULL;
  */
  if(kaydirma_sayisi<0){
  	kaydirma_sayisi=kaydirma_sayisi+M;
  }
  for(i=0;i<kaydirma_sayisi;i++){
  	(*head)=(*head)->prev;
  	
  }
}


int main(){
	srand(time(NULL));
	int N=NULL,M=NULL;
	printf("Kilit programinda M ifadesi carkta kac adet sayi olacagini belirtir.\n");
	printf("Kilit programinde N ifadesi carktaki sayilarin 1-N arasindaki sayilardan olusacagini belirtir.\n");
	printf("Lutfen bu bilgiler dogrultusunda N ve M ifadelerini girin.\n");
	
	printf("M sayisini girin:");
	scanf("%d",&M);
	
	if(M<2){ //M iicn kontrol ediyorum.
		while(M<2){
				printf("Lutfen gecerli bir sayi girin!\n");
				printf("M sayisini girin:");
				scanf("%d",&M);
		}
	}
	
	printf("N sayisini girin:"); 
	scanf("%d",&N);
	
	if(M>2*N-1){
		while(M>2*N-1){ //N icin kontrol ediyoruz.
				printf("Lutfen gecerli bir sayi girin!\n");
				printf("N sayisini girin:");
				scanf("%d",&N);
		}
	}
	
	printf("M ve N degerlerini soyle belirlediniz: M->[%d] N->[%d]\n",M,N);
	int ortak_sayi=rand()%N+1;
	printf("ortak sayi : %d\n",ortak_sayi);
	
	//int random = rand()%N+1;
	
	Node *head1=(Node*)malloc(sizeof(Node));
	Node *head2=(Node*)malloc(sizeof(Node));
	Node *head3=(Node*)malloc(sizeof(Node));
	head1->prev = NULL;
	head2->prev = NULL;
	head3->prev = NULL;
	head1->next = NULL;
	head2->next = NULL;
	head3->next = NULL;
	Node *tail1= head1;
	Node *tail2= head2;
	Node *tail3= head3;
	int indeks1,indeks2,indeks3;
	indeks1=rand()%M+1;
	indeks2=rand()%M+1;
	while(indeks1==indeks2){
		indeks2=rand()%M+1;
	}
	indeks3=rand()%M+1;
	while(indeks2==indeks3||indeks1==indeks3){
		indeks3=rand()%M+1;
	}
	
	createList(&head1,&head2,&head3,M,N,ortak_sayi,indeks1);
	createList(&head2,&head1,&head3,M,N,ortak_sayi,indeks2);
	createList(&head3,&head2,&head1,M,N,ortak_sayi,indeks3);
	tail1 = tail1->prev;
	tail2 = tail2->prev;
	tail3 = tail3->prev;
	
	tail1->next = head1;
	tail2->next = head2;
	tail3->next = head3;
	head1->prev = tail1;
	head2->prev = tail2;
	head3->prev = tail3;
	printList(&head1, M);
	printList(&head2, M);
	printList(&head3, M);
	
	int *tmp = ortak_sayiBul(head1, head2, head3, ortak_sayi,M);
	//printf("%d\n",tmp[0]);
	//printf(" kaydirma sayisi : %d\n",tmp[1]);
	//printf("%d\n",tmp[2]);
	
	//linkedlistKaydir(head1,head2,head3,ortak_sayi);
	
	//printList(&head2, M);
	
	kaydir(&head2,tmp[0]-tmp[1],M);
	kaydir(&head3,tmp[0]-tmp[2],M);
	
	printf("Carklarin donmus hali:\n");
	printList(&head1,M);
	printList(&head2, M);
	printList(&head3, M);
	
	return 0;
	
}


