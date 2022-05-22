# ma335_course_project

**Dictionary Loader**

You should only need to run this if you change the master list of words: all_words.txt.

Compile: gcc separate_words.c -o separate_words
Run: ./separate_words

**Wordle Solver**

Compile: mpicc wordle_bot.c -o wordle_bot
Run: mpirun wordle_bot

While running:
  1. Enter in the number of letters you are using to select your dictionary.
  2. If you would like to play in hard mode select yes. Else, select no.
  3. A list of three guesses will populate, but you can choose any viable word. If you do not like the three suggestions, you can search through the list in        guesses_1.txt.
  4. You will then be prompted to enter the colors yielded in the game: g for green, y for yellow, and w for gray.
  5. Repreat steps three and four until solved. (After the first guess, words are not always populated so check temp.txt or guesses_2.txt for a list.)
  6. After solving, Ctrl+C to exit. (Success conditions yielding faulty results.)

ALSO NOTE NOT ALL WORDS IN THE DICTIONARY ARE IN all_words.txt.
