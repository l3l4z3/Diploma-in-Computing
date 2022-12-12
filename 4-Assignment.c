#include "stdio.h"
#include "stdlib.h"
//Functions
void printWords();
void findWords();
void findWord2();
//Global Variable
int toFind1[10] = {119, 105, 110, 104, 116, 117, 116, 0, 0, 0};
//Main Function
int main(){

    // printWords();
    findWords();
    findWord2();

    return 0;
}

void printWords(){
    FILE *fptr;
    fptr = fopen("words.txt", "r");

    if(fptr == NULL) {
        printf("Your file can not open!");
    } else{
        char c = fgetc(fptr);
        while (!feof(fptr)){
            printf("%c", c);
            c = fgetc(fptr);
        }
    }
    fclose(fptr);
}

void findWords(){
    int startPoint = 103;
    int stopPoint = 120;
    int j = 106;
    int k = 107;
    int l = 108;
    int m = 109;
    int o = 111;
    int p = 112;
    int q = 113;
    int r = 114;
    int s = 115;
    int v = 118;

    int delChar[10]{106, 107, 108, 109, 111, 112, 113, 114, 115,118};

    FILE *fptr;
    fptr = fopen("words.txt", "r");

    char c = fgetc(fptr);
    while (!feof(fptr)) {


            if (c > startPoint && c < stopPoint) {

                printf("%c", c);
            }


        c = fgetc(fptr);
    }

    fclose(fptr);
}

void findWord2(){
    int index = 0;
    FILE *fptr;
    fptr = fopen("words.txt", "r");
    char c = fgetc(fptr);
    for (int i = 0; i < 10000; i++) {
        if(toFind1[index] == c ){
            printf("%c", c);
            index = index + 1;
        }
        c = fgetc(fptr);
    }
    fclose(fptr);

}

//ရသလောက်လေးရေးထားတာပါဆရာ
//လည်နေလို့ပါ




