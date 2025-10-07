#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include "game.h"

int main(int argc, char* argv[])
{
    srand(time(NULL));
    char userLetter = 0;
    const char* secretWord = getRandomWord();
    int Remainingattempt = 10;
    int numberOfLetters = wordSize(secretWord);
    int *foundLetter = NULL;

    foundLetter = malloc(numberOfLetters * sizeof(int));
    arrayInit(foundLetter, numberOfLetters);

    printf("Welcome to this small game Hang_Him !");

    char lettersArray[26] = {0};

    while(Remainingattempt > 0 && !win(foundLetter, numberOfLetters))
          {
              printf("\n\nCan you guess the secret word ?");
              printf("\nYou remain %d attempt", Remainingattempt);
              writeProposedLetter(userLetter, lettersArray);

              for (int i = 0; i < numberOfLetters; i++)
              {
                    if(foundLetter[i])
                        printf("%c", secretWord[i]);
                    else
                        printf("*");
              }

              printf("\nTry a letter : ");
              userLetter = readCharacter();

                if (!searchLetter(userLetter, secretWord, foundLetter))
                {
                    Remainingattempt--;
                }
          }
              if(win(foundLetter, numberOfLetters))
                printf("\n Let's go ! The secret word was %s congratulation\n", secretWord);
              else
                printf("\n\n Damn, I think you just lost, the secret word was %s \n", secretWord);

              free(foundLetter);
              return 0;

}


