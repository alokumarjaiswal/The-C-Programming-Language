#include <stdio.h>

/* count lines in input
    The standard library ensures that an input text stream
    apppears as a sequence of lines,
    each terminated by a newline.
    Hence, counting lines is just counting newlines.

    A character written between single quotes represents
    an integer value equal to the numerical value of the
    character in the machine's character set.
    This is called a character constant,
    although it is just another way to write a small integer.
    'A' - 65, '\n' - 10
    Note that "\n" is a string constant that happens to
    contain only one character.
*/

int main() {
  int c, nl;

  nl = 0;
  while ((c = getchar()) != EOF) {
    if (c == '\n') {
      ++nl;
    }
  }
  printf("%d\n", nl);
}