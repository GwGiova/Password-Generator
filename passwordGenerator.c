/* 
Project Name: Password Generator
Author: GwMan
Version 1.0.0
Description: A simple CLI password generator written in C
Start Date: 27/02/2026 09:21
Finish Date 27/02/2026 10:48
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_LENGTH 100

void menu(){
    
    printf("WELCOME TO THE PASSWORD GENERATOR!\n");
    printf("1) Set the password\n");
    printf("2) Exit program\n");
    printf("Insert your choice here: ");

}

void exit_message(){

    printf("Exiting the password generator..");

}

void pWordCreator(char password[]){

    char upperLetters[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

    char lowerLetters[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

    char numbers[] = {'0','1','2','3','4','5','6','7','8','9'};

    char specialCharacters[] = {'!','$','%','&','/','(',')','=','?','^','+','-','*','_',':','.',','};

    //Counter of the characters inserted in the password[] array
    short counter = 0;

    //Password lenght selected by the user
    int pLenght;

    //Character selected randomly from any of the arrays, which will be a password's character
    char character;

    short chooseCharacter;

    printf("Insert the lenght of your password (Max %d characters): ", MAX_LENGTH);

    scanf("%d", &pLenght);

    while(pLenght <= 0 || pLenght > 100){

        printf("Write a number between 1 and 100: ");

        scanf("%d", &pLenght);

    }

    while(counter < pLenght){

        int chooseArray;

        chooseArray = 0 + rand() % 4;
        
        switch(chooseArray){

            case 0:

                chooseCharacter = 0 + rand() % 26;

                character = upperLetters[chooseCharacter];

                password[counter] = character;

            break;

            case 1:

                chooseCharacter = 0 + rand() % 26;

                character = lowerLetters[chooseCharacter];

                password[counter] = character;

            break;

            case 2:

                chooseCharacter = 0 + rand() % 10;

                character = numbers[chooseCharacter];

                password[counter] = character;

            break;

            case 3:

                chooseCharacter = 0 + rand() % 17;

                character = specialCharacters[chooseCharacter];

                password[counter] = character;

            break;

        }
        
        counter++;

    }

    password[counter] = '\0';

}

int main(){
    
    int menu_choice = 0;

    char password[MAX_LENGTH];

    srand(time(NULL));
    
    while(menu_choice != 3){

        menu();

        scanf("%d", &menu_choice);

        switch(menu_choice){

            case 1:

                pWordCreator(password);

                printf("Password created: %s\n", password);

            break;

            case 2:

                exit_message();

                return 0;

            break;

            default:

            break;

        }

    }

}
