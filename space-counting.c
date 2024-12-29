#include <stdio.h>

/* Write a program to count blanks, tabs and newlines.
 */

int main() {
  int c, ns;

  ns = 0;
  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\t' || c == '\n') {
      ++ns;
    }
  }
  printf("%d", ns);
}