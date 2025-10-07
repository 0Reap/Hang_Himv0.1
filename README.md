# Hang Him - Hangman in C (Version 0.2)

## How to compile
gcc main.c game.c -o hanghim

## How to play
Run the program and guess letters in the secret word. 

## What's new in version 0.2
- Secure input: the user can only enter a single alphabetic letter.
- Added a table of letters already proposed that is displayed each turn.
- Added a list of 10 words with a random word chosen at the start of each game.
- Improved code structure and readability.

## Version history
| Version | Description |
|---------|-------------|
| 0.1     | First version — basic hangman logic, simple input |
| 0.2     | Added input validation, letters tracking, random word selection |