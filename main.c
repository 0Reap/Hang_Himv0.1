#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "game.h"


int main(int argc, char* argv[])
{
    char userLetter = 0;
    char secretWord[] = "GREEN";
    int Remainingattempt = 10;
    int numberOfLetters = wordSize(secretWord);
    int *foundLetter = NULL;
    foundLetter = malloc(numberOfLetters * sizeof(int));
    arrayInit(foundLetter, numberOfLetters);

    printf("Welcome to this small game Hang_Him !");

    while(Remainingattempt > 0 && !win(foundLetter, numberOfLetters))
          {
              printf("\n\nYou remain %d attempt", Remainingattempt);
              printf("\nWhat is the secret word ?");

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
                printf("\n Let's go ! The secret word was %s congrats\n", secretWord);
              else
                printf("\n\n Damn, I think you just lost, the secret word was %s \n", secretWord);

              free(foundLetter);
              return 0;

}


