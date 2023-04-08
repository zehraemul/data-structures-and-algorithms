#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct kilit{
    int value;
    struct kilit *prev;
    struct kilit *next;
} kilit;

// linked list için gerekli fonksiyonlarý tanýmlýyoruz
void ekle(kilit **bas, kilit **son, int value) {
    kilit *yeni_kilit = (kilit*)malloc(sizeof(kilit));
    yeni_kilit->value = value;
    yeni_kilit->next = NULL;
    if(*bas == NULL) {
        yeni_kilit->prev = NULL;
        *bas = yeni_kilit;
        *son = yeni_kilit;
    }
    else {
        yeni_kilit->prev = *son;
        (*son)->next = yeni_kilit;
        *son = yeni_kilit;
    }
}

void yazdir(kilit *bas) {
    while(bas != NULL) {
        printf("%d ", bas->value);
        bas = bas->next;
    }
    printf("\n");
}

int rastgeleSayi(int N) {
    return rand()%N + 1;
}

void sil(kilit *bas) {
    kilit *temp;
    while (bas != NULL) {
        temp = bas;
        bas = bas->next;
        free(temp);
    }
}

int main() {
    srand(time(NULL));

    int N=NULL; //kullanicidan N ve M degerlerini aliyoruz.
	int M=NULL;
	int i,flag=0;
	srand(time(NULL));
	printf("Kilit programinda M ifadesi carkta kac adet sayi olacagini belirtir.\n");
	printf("Kilit programinde N ifadesi carktaki sayilarin 1-N arasindaki sayilardan olusacagini belirtir.\n");
	printf("Lutfen bu bilgiler dogrultusunda N ve M ifadelerini girin.\n");
	
	printf("M sayisini girin:");
	scanf("%d",&M);
	
	if(M<3){ //M iicn kontrol ediyorum.
		while(M<3){
				printf("Lutfen gecerli bir sayi girin!\n");
				printf("M sayisini girin:");
				scanf("%d",&M);
		}
	}
	
	printf("N sayisini girin:"); 
	scanf("%d",&N);
	
	if(M>N){
		while(M>N){ //N icin kontrol ediyoruz.
				printf("Lutfen gecerli bir sayi girin!\n");
				printf("N sayisini girin:");
				scanf("%d",&N);
		}
	}
	
	printf("M ve N degerlerini soyle belirlediniz: M->[%d] N->[%d]\n",M,N);
    
    kilit *ortak_kilit = NULL;
    kilit *birinci_liste_bas = NULL, *birinci_liste_son = NULL;
    kilit *ikinci_liste_bas = NULL, *ikinci_liste_son = NULL;
    kilit *ucuncu_liste_bas = NULL, *ucuncu_liste_son = NULL;

    int ortak_sayi = rastgeleSayi(N); //ortak sayi urettim.
    printf("Ortak sayi: %d\n", ortak_sayi);
    
	//birinci carki olusturdum.
	ekle(&birinci_liste_bas, &birinci_liste_son, ortak_sayi);
    int deger;
	for( i = 0; i < M-1; i++) {
		deger = rastgeleSayi(N);
		while(deger == ortak_sayi){
			deger = rastgeleSayi(N);
		}
		ekle(&birinci_liste_bas, &birinci_liste_son, deger);
    }
	//ikinci carki olusturdum.
	ekle(&ikinci_liste_bas, &ikinci_liste_son, ortak_sayi);
    for( i = 0; i < M-1; i++) {
        deger = rastgeleSayi(N);
		while(deger == ortak_sayi){
			deger = rastgeleSayi(N);
		}
		ekle(&ikinci_liste_bas, &ikinci_liste_son, deger);
    }
	//ucuncu carki olusturdum.
	ekle(&ucuncu_liste_bas, &ucuncu_liste_son, ortak_sayi);
    for( i = 0; i < M-1; i++) {
        deger = rastgeleSayi(N);
		while(deger == ortak_sayi){
			deger = rastgeleSayi(N);
		}
        ekle(&ucuncu_liste_bas, &ucuncu_liste_son, deger);
    }
    printf("Birinci linked list: ");
    yazdir(birinci_liste_bas);
    printf("Ikinci linked list: ");
    yazdir(ikinci_liste_bas);
    printf("Ucuncu linked list: ");
    yazdir(ucuncu_liste_bas);
    
    sil(birinci_liste_bas);
    sil(ikinci_liste_bas);
    sil(ucuncu_liste_bas);

    return 0;
}

