#ifndef GAME_H
#define GAME_H

int wordSize(char secretWord[]);
void arrayInit(int *foundLetter, int size);
int win(int *foundLetter, int numberOfLetters);
char readCharacter();
int searchLetter(char userLetter, char secretWord[], int* foundLetter);
extern const char* arrayWithWords[10];
const char* getRandomWord();
void writeProposedLetter(char userLetter, char lettersArray[]);

#endif
