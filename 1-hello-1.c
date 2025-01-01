#include <stdio.h>

/* This produces the same output as '0-hello-0.c'.
    It showcases the nature of 'printf' function.
    It never supplies a newline automatically.
    It shows how escape sequences are used to represent
    hard-to-type or invisible characters.
    '\n' is called a newline character,
    as it advances the output to the left margin on the new line.
*/

int main() {
  printf("hello, ");
  printf("world");
  printf("\n");
}
