#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "game.h"

// The array with a selection of 10 words for the game.

const char* arrayWithWords[10] =
{
    "TRYHARD", "CLOWN", "RESILIENCE", "SUSTAINABILITY","WHISPER",
    "QUIRK", "SYMPHONY", "PONDER", "RESPOND", "BARGAIN"
};

// A function to get a random word inside this array

const char* getRandomWord(){
    int randomNumber = rand() % 10;
    return arrayWithWords[randomNumber];
}

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

    do {
        character = getchar();

        while (getchar() != '\n');
        if (!isalpha(character)) {
            printf("Please enter a valid letter (A-Z):");
        }
    }
    while (!isalpha(character));

    character = toupper(character);
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

// to write all the letters proposed by the player.

void writeProposedLetter(char userLetter, char lettersArray[])
{
    int alreadyProposed = 0;
    int i;

    for (i = 0; i < 26; i++) {
        if (lettersArray[i] == userLetter) {
            alreadyProposed = 1;
            break;
        }
    }

    if (!alreadyProposed) {
        for (i = 0; i < 26; i++) {
            if (lettersArray[i] == '\0') {
                lettersArray[i] = userLetter;
                break;
            }
        }
    }

    printf("\nThe letters you already proposed are : ");
    for (int i = 0; i < 26; i++) {
        if (lettersArray[i] != '\0') {
            printf("%c ", lettersArray[i]);
        }
    }
    printf("\n");
}
