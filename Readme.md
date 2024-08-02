# Hangman Game

This is a simple console-based Hangman game written in C++. The game selects a random word from a provided text file, and the player has to guess the word letter by letter. The player has a limited number of incorrect guesses before they lose the game.

## Components

- **`Game.h`**: Contains the declaration of the `Game` class, which handles the game logic, displays, and user interactions.
- **`Game.cpp`**: Implements the `Game` class methods, including gameplay logic, displaying hangman stages, and game status.
- **`WordProvider.h`**: Declares the `WordProvider` class, which manages loading words from a file and providing random words.
- **`WordProvider.cpp`**: Implements the `WordProvider` class methods for loading words from a file and generating random words.
- **`main.cpp`**: Entry point of the application that initializes the `WordProvider` and `Game` classes and starts the game.

## Dependencies

- **Compiler**: Ensure you have a C++ compiler like GCC or MinGW installed.
- **C++ Standard**: The code is compatible with C++11 and later.

## Compilation

To compile the project, run:

```sh
g++ main.cpp Game.cpp WordProvider.cpp -o hangman
```

## Usage

1. **Prepare the Word List**: Create a text file named `words.txt` in the same directory. Each line should contain one word.

2. **Run the Game**: Execute the compiled binary:

   ```sh
   ./hangman
   ```

3. **Play**: Follow the on-screen instructions to guess the word. You will be given a certain number of attempts to guess the word correctly.

## File Descriptions

### `Game.h`

Contains the declaration of the `Game` class with methods for:
- Playing the game
- Displaying game status and hangman stages
- Processing user guesses

### `Game.cpp`

Implements the methods declared in `Game.h`. Key functionalities include:
- Initializing the game
- Updating and displaying game status
- Handling user input and guessing logic

### `WordProvider.h`

Contains the declaration of the `WordProvider` class with methods for:
- Loading words from a file
- Providing a random word

### `WordProvider.cpp`

Implements the methods declared in `WordProvider.h`. It reads words from a file and selects a random word for the game.

### `main.cpp`

The main entry point of the application. Initializes the `WordProvider` to load words and the `Game` to start playing.

## Acknowledgments

- Inspired by classic text-based games.
- Developed as a simple example of C++ programming concepts.