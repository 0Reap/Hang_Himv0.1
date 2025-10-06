#include <stdio.h>
#include <ctype.h>
#include "game.h"

// to calculate the size of the word
int wordSize(char secretWord[])
{
    int numberOfLetters = 0;
    for(int i = 0; secretWord[i] != '\0'; i++)
    {
        numberOfLetters++;
    }
    return numberOfLetters;
}

// to initiat every value with 0 in the array
void arrayInit(int *foundLetter, int size)
{
    for(int i = 0; i<size; i++)
    {
        foundLetter[i]=0;
    }
}

// to know if the player won
int win(int *foundLetter, int numberOfLetters)
{
    int i = 0;
    int playerWin = 1;
    for (i=0; i < numberOfLetters; i++)
    {
        if(foundLetter[i] == 0)
            playerWin = 0;
    }

    return playerWin;
}

// to read character

char readCharacter()
{
    char character = 0;

    character = getchar();
    character = toupper(character);

    while (getchar() != '\n') ;

    return character;
}

//to found the letter

int searchLetter(char userLetter, char secretWord[], int* foundLetter)
{
    int i = 0;
    int goodLetter = 0;

    //search in secretWord if the letter stand there.
    for (i = 0 ; secretWord[i] != '\0' ; i++)
    {
        if (userLetter == secretWord[i])
        {
            goodLetter = 1;
            foundLetter[i] = 1; // to put 1 in the array in order to indicate that the letter was found.
        }
    }

    return goodLetter;
}
