#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxChildren 26
#define maxUzunluk 20

typedef struct trieDugum {
    char deger;
    struct trieDugum* children[maxChildren];
    int isEndOfWord;
} trieDugum;

trieDugum* dugumOlustur(char deger);
void insertWord(trieDugum* root, char* word);
void sayiAra(trieDugum* root, char* number, char* prefix, int index) {
    if (index == strlen(number)) {
        if (root->isEndOfWord) {
            printf("%s\n", prefix);
        }
        return;
    }
    char keypad[10][5] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
int i;
    int digit = number[index] - '0';
    for ( i = 0; i < strlen(keypad[digit]); i++) {
        char currentChar = keypad[digit][i];
        int currentCharIndex = currentChar - 'a';

        if (root->children[currentCharIndex] != NULL) {
            char newPrefix[maxUzunluk];
            strcpy(newPrefix, prefix);
            int len = strlen(newPrefix);
            newPrefix[len] = currentChar;
            newPrefix[len + 1] = '\0';
            sayiAra(root->children[currentCharIndex], number, newPrefix, index + 1);
        }
    }
}


void freeTrie(trieDugum* node);

int main() {
	typedef struct trieDugum trieDugum;
    trieDugum* root = dugumOlustur('*'); 
    FILE* dictionaryFile = fopen("sozluk.txt", "r");
    if (dictionaryFile == NULL) {
        printf("dosya acilamadi!!\n");
        return 1;
    }
    char word[maxUzunluk];
    while (fgets(word, sizeof(word), dictionaryFile) != NULL) {
        word[strcspn(word, "\n")] = '\0';
        insertWord(root, word);
    }
    fclose(dictionaryFile);
	//int flag=1;
    char number[maxUzunluk];
    while (1) {
        printf("> ");
        fgets(number, sizeof(number), stdin);
        number[strcspn(number, "\n")] = '\0';

        if (strcmp(number, "q") == 0) {
            return 0;
        }

        sayiAra(root, number, "", 0);
    }
    freeTrie(root);

    return 0;
}

trieDugum* dugumOlustur(char deger) {
    int i;
    trieDugum* node = (trieDugum*)malloc(sizeof(trieDugum));
    node->deger = deger;
    node->isEndOfWord = 0;
    for (i = 0; i < maxChildren; i++) {
        node->children[i] = NULL;
    }
    return node;
}

void insertWord(trieDugum* root, char* word) {
	word[strcspn(word, "\n")] = '\0';
    int i;
    trieDugum* current = root;
    for (i = 0; i < strlen(word); i++) {
        int index = word[i] - 'a';
        if (current->children[index] == NULL) {
            current->children[index] = dugumOlustur(word[i]);
        }
        current = current->children[index];
    }
    current->isEndOfWord = 1;
}

void freeTrie(trieDugum* node) {
    int i;
    if (node == NULL) {
        return;
    }
    for (i = 0; i < maxChildren; i++) {
        freeTrie(node->children[i]);
    }
    free(node);
}
