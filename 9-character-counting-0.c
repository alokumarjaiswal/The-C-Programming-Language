#include <stdio.h>

/* count characters in input; 1st version
    'long' integers are at least 32 bits.
    '%ld' tells 'printf' that the corresponding
    argument is a 'long' integer.

    'int' can be 16 bits or 32 bits depending on the machine.
    The output of this program may seem odd at first,
    but remember that it also counts every newline character.
*/

int main() {
  long nc;

  nc = 0;
  while (getchar() != EOF) {
    ++nc;
  }
  printf("%ld\n", nc);
}