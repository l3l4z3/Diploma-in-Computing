#include "stdio.h"
#include "iostream"
#include "stdlib.h"
#include "string.h"
using namespace std;
int count = 0;
int main(){

    char name[7] = {'w','i','n','h','t','u','t'};

//    printf("Enter a word to search :");
//    scanf("%s", name);
//    printf("The word you want to search : %s", name);
//    printf("\n");

    FILE *fptr;
    fptr = fopen("words.txt", "r");

    if (fptr == NULL){
        printf("File cannot open!");
    }

    char c = fgetc(fptr);
    while (!feof(fptr)){

        if(name[0] == c){
            printf("%c", c);
            c = fgetc(fptr);
            for (int j = 1; j < 7; j++) {
                if (name[j] == c){
                    printf("%c", c);
                    c = fgetc(fptr);
                }
            }
        }
        c = fgetc(fptr);
    }
    fclose(fptr);
    return 0;
}


//ရသလောက်လေးရေးထားတာပါဆရာ
//လည်နေလို့ပါ




