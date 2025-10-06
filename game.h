#ifndef GAME_H
#define GAME_H

int wordSize(char secretWord[]);
void arrayInit(int *foundLetter, int size);
int win(int *foundLetter, int numberOfLetters);
char readCharacter();
int searchLetter(char userLetter, char secretWord[], int* foundLetter);

#endif
