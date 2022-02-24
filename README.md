# EVIL HANGMAN

A twist on the traditional game hangman, evil hangman tries it's best to make sure the player never wins.
The player goes up against the computer who chooses the word and has the user guess. However, when the user guesses
a letter the computer removes all words with that letter until all the tries of the user are expired. A random word 
which satisfies the word length is chosen and shown to the user as the chosen word.

### IMPLEMENTATION

There are 3 cases:

CASE 1:
the code reads the words in the dictionary and stores in an array of strings.
this case must be run before case 2 or 3.

CASE 2:
the user is given the lenght of the chosen word (chosen randomly) and asked for a guess once.
all words that contain that letter are removed from the array by traversing through the array.

CASE 3:
the user is given the lenght of the chosen word and is given 5 tries or lives to guess the correct word.
all the words with the guessed letters are removed and a random word that fits the length requirement is 
displayed as the chosen word.

note: to stop dictionary from being displayed every time words are removed, comment out the function displayarr
from case 2 and 3.

### IMPROVEMENTS

- Instead of an array a vector will better serve as the dictionary to store the words so that the user will not have to tell number of words in dictionary file before hand.
- To improve asymptotic complexity of the process, an AVL tree can be used as the dictionary. will complete deleting, inserting and searching in logrithmic time.

### HOW TO RUN
#### Prerequisites
* C++ 

#### Commands used to run
For Windows Users:
``` g++ evil_hangman.cpp -o <object file name>```
``` <object file name> <dictionary_file> <number_of_words_in_dictionary> <case_mode>```

For Linux Users
``` g++ evil_hangman.cpp -o <object file name>```
``` ./<object file name> <dictionary_file> <number_of_words_in_dictionary> <case_mode>```

##### note:
In this repository:
* dictionary_file = english2.txt
* number_of_words_in_dictionary = 65197
* case_mode = 1 or 2 or 3 (descriptions given above)
