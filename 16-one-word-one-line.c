#include <stdio.h>

#define IN 1
#define OUT 0

/* Exercise 1-12. Write a program that prints its input one word per line.
    We start outside a word.
    We use an if-else construct to handle this problem.
    If a separator is encountered and we are inside a word,
    end the word and alter the state. Otherwise, if we are
    not inside a word, do nothing.
    Else, if the character is not a separator, print it and
    switch to the other state.
    The main key here is that when a text stream is fed,
    it can either be a separator or not be a separator.
    If it is a separator, we further check if we are inside a word.
    This check avoids trailing spaces and consecutive blanks.
    If we were inside a word, we end the word and change the state
    due to before mentioned scenario.
*/

int main() {
  int c, state;

  state = OUT;

  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\t' || c == '\n') {
      if (state == IN) {
        putchar('\n');
        state = OUT;
      }
    } else {
      putchar(c);
      state = IN;
    }
  }

  return 0;
}
