#include <stdio.h>

/* copy input to output; 2nd version
    The precedence of != is higher than that of =,
    which means in the absence of parenthesis
    the relational test != would be done before the assignment =.
    So, the statement
        c = getchar() != EOF
    is equivalent to
        c = (getchar() != EOF)
    This has the undesired effect of setting 'c' to 0 or 1,
    depending on whether or not the call of 'getchar' encountered end of file.

    Verify that the expression getchar() != EOF is 0 or 1.
    Write a program to print the value of EOF.
*/

int main() {
  int c;

  printf("Enter a character (Ctrl+D to signal EOF on Unix/Linux, Ctrl+Z on "
         "Windows):\n");
  c = getchar() != EOF;
  printf("%d\n", c);
  putchar(c);

  printf("\nThe value of EOF is %d.\n", EOF);

  while ((c = getchar()) != EOF) {
    putchar(c);
  }
}