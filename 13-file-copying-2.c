#include <stdio.h>

/* Exercise 1-9. Write a program to copy its input to its output,
    replacing each string of one or more blanks by a single blank.
    It turns out that the logical OR expression,
      cc != ' ' || lc != ' ',
    executes every time except only when
    the current and last character are blank.
    OR is True even if only one condition is true.
    It is False only when both conditions are false.
*/

int main() {
  int cc;     // current character
  int lc = 0; // last character

  while ((cc = getchar()) != EOF) {
    if (cc != ' ' || lc != ' ') {
      putchar(cc);
    }
    lc = cc;
  }

  return 0;
}