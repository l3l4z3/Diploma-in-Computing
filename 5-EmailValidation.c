#include "stdio.h"
#include "stdlib.h"
#define SIZE 100

//Structure
struct Worker{
    int id;
    int age;
    char name[30];
    char email[30];
    char pass[30];
};

struct Worker info[SIZE];

//Global variable
int globalEfound = -1;
int globalPfound = -1;
int globalIndex = 0;

//Functions Declaration
void printData();
int charCounting(char totalChar[30]);
void myStrCmp(char userInputChar[30]);
void login();
void passChecker(char userPass[30], int userIndex);
void printDataToFile();
void userActionSector();
void loadingAllDataFromFile();
void homePage();
void registration();
void validEmailChecker(char registerEmail[30]);

//Main Function
int main(){

    loadingAllDataFromFile();
    printData();
    homePage();

    return 0;
}

// Print Data Function
void printData(){

    for (int j = 0; j < globalIndex; j++) {
        printf("***** Printing the User Data (%d)... *****\n", j+1);
        printf("ID - %d\n", info[j].id);
        printf("Name - %s\n", info[j].name);
        printf("Age - %d\n", info[j].age);
        printf("Email - %s\n", info[j].email);
        printf("Password - %s\n", info[j].pass);
    }
}

//StrCMP function
void myStrCmp(char userInputChar[30]){

    int sameWordCount = 0;
    int second = charCounting(userInputChar);

    for (int i = 0; i < globalIndex; i++) {
        int first = charCounting(info[i].email);

        if(first == second){

            for (int j = 0; j < first ; j++) {
                if(info[i].email[j] != userInputChar[j]){
                    break;
                } else {
                    sameWordCount++;
                }
            }
        }

        if (second == sameWordCount){
            globalEfound = i;
            break;
        }
    }
}

//Character Counting Function
int charCounting(char totalChar[30]){

    int charCount = 0;
    for (int i = 0; i < 30; i++) {
        if(totalChar[i] == '\0'){
            break;
        } else{
            charCount++;
        }
    }

    return charCount;
}

//Login Function
void login(){
    char loginEmail[30];
    char loginPass[30];

    printf("[+] This is Login form ... \n");
    //Email Getting
    printf("Enter your Email to Login : ");
    scanf(" %[^\n]", &loginEmail);

    globalEfound = -1;
    myStrCmp(loginEmail);

    //Password Getting
    printf("Enter your Password to Login : ");
    scanf(" %[^\n]", &loginPass);

    globalPfound = -1;
    passChecker(loginPass, globalEfound);

    //Validation
    if(globalEfound != -1 && globalPfound == 1) {
        userActionSector();
    } else {
        printf("[+]Invalid Email or Password! Try again ... !\n");
        login();
    }
}

//Password Checking Function
void passChecker(char userPass[30], int userIndex){
    int userInputPassCount = charCounting(userPass);
    int dbPassCount = charCounting(info[userIndex].pass);
    int sameCount = 0;

    if(userInputPassCount == dbPassCount){

        for (int i = 0; i < userInputPassCount; i++) {
            if(userPass[i] == info[userIndex].pass[i]){
                sameCount++;
            } else {
                break;
            }
        }

        if(sameCount == dbPassCount){
            globalPfound = 1;
        }
    }
}

//Printing Data to File
void printDataToFile(){
    FILE *fptr;
    fptr = fopen("DB.txt", "w");

    if(fptr == NULL){
        printf("[+] The File does not exist!...");
    } else {
        for (int i = 0; i < globalIndex; i++) {
            fprintf(fptr, "%d %d %s %s %s\n", info[i].id, info[i].age, info[i].name, info[i].email, info[i].pass);
        }
        printf("[+] Data is saved into file!");
    }
    fclose(fptr);
}

//User Action Sector Function
void userActionSector(){
    int userOption = 0;

    printf("***** Welcome to Our Site ... *****\n");
    printf("[+] Login User : %s\n", info[globalEfound].name);

    printf("***** Main Menu *****\n");
    printf("Press 1 to User Action Sector.\n");
    printf("Press 2 to Home.\n");
    printf("Press 3 to Exit.\n");


    printf("Choose an option : ");
    scanf("%d",&userOption);

    if(userOption == 1){
        printf("This is User Action Sector!\n");
    } else if(userOption == 2){
        login();
    } else if(userOption == 3){
        printDataToFile();
    } else {
        printf("[+] Invalid Option.\n");
        userActionSector();
    }
}

//Reading Data from File
void loadingAllDataFromFile(){
    FILE *fptr;
    fptr = fopen("DB.txt", "r");

    if(fptr == NULL){
        printf("[+] File cannot open!");
    } else{
        for (int i = 0; i < SIZE; i++) {
            fscanf(fptr, "%d %d %s %s %s", &info[i].id, &info[i].age, &info[i].name, &info[i].email, &info[i].pass);

            if(info[i].name[0] == '\0'){
                break;
            }
            globalIndex++;
        }
    }
    fclose(fptr);
}

//Home Page
void homePage(){
    int option = 0;
    printf("***** This is Home Page *****\n");
    printf("Press 1 to Register.\n");
    printf("Press 2 to Login.\n");
    printf("Press 3 to Exit.\n");
    printf("Please Choose an Option : ");
    scanf("%d", &option);

    if(option == 1){
        registration();
    } else if(option == 2){
        login();
    } else if(option == 3){
        printDataToFile();
        exit(1);
    } else {
        printf("[+] Invalid Option!\n");
        homePage();
    }
}

//Registration Page
void registration(){
    char regEmail[30];
    printf("***** This is Registration Page *****\n");
    printf("Please Enter your Email to register: ");
    scanf(" %[^\n]", &regEmail);
    //Valid Email format check
    validEmailChecker(regEmail);
    //Email Exist check
    printf("[+] Checking the registering email exists in the database.\n");
    globalEfound = -1;
    myStrCmp(regEmail);
    if(globalEfound == -1){
        printf("You can register with this email.\n");
    } else{
        printf("You have already registered with this email! Choose another.\n");
        registration();
    }

    char regPass[30];
    printf("Please Enter your Password to register: ");
    scanf(" %[^\n]", &regPass);

    int regID = 0;
    printf("Please Enter your ID :");
    scanf(" %d", &regID);

    char regName[30];
    printf("Please Enter your name :");
    scanf(" %[^\n]", &regName);

    int regAge = 0;
    printf("Please Enter your Age :");
    scanf(" %d", &regAge);

    FILE *fptr;
    fptr = fopen("DB.txt", "a");
    if(fptr == NULL){
        printf("[-] The Database is broken!");
    } else{
        fprintf(fptr, "%d %d %s %s %s\n", regID, regAge, regName, regEmail, regPass);
    }
    fclose(fptr);

    printf("[+] You are successfully registered.\n");
    printf("Please login with your Registered Email.\n");
    login();
}

//Email Validation
void validEmailChecker(char registerEmail[30]){
    int formatCount = 0;
    int emailWords = 0;
    char emailFormat[30] = "@gmail.com";
    int sameWord = 10;

    for (int j = 0; j < 30; j++) {

        if(registerEmail[j] == '\0'){
            break;
        } else if(registerEmail[j] == emailFormat[emailWords]){
            formatCount++;
            emailWords++;
        }
    }

    if(formatCount == sameWord){
        printf("[+] Valid Email Format...\n");
    } else {
        printf("[-] Invalid Email Format! Try again...\n");
        printf("[-] Email format : username@gmail.com\n");
        registration();
    }

}
