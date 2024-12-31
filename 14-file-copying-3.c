#include <stdio.h>

/* Exercise 1-10. Write a program to copy its input to its output,
    replacing each tab by '\t', each backspace by '\b',
    and each backlash by '\\'.
    This makes tabs and backspaces visible in an unambiguous way.

    "\\t" is an escape sequence to print \t. Similarly,
    "\\b" is for \b, and "\\\\" is for backslash(\).
*/

int main() {
  int c;

  while ((c = getchar()) != EOF) {
    if (c == '\t') {
      printf("\\t");
    } else if (c == '\b') {
      printf("\\b");
    } else if (c == '\\') {
      printf("\\\\");
    } else {
      putchar(c);
    }
  }

  return 0;
}