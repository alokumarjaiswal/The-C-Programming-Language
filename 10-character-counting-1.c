#include <stdio.h>

/* count characters in input; 2nd version
    The isolated semicolon, called a null statement,
    is there to satisfy the requirement for the 'for' statement
    to have a body.

    'double' makes it possible to cope with very big numbers.
    '%f' is used for both 'float' and 'double'.
 */

int main() {
  double nc;

  for (nc = 0; getchar() != EOF; ++nc) {
    ;
  }
  printf("%.0f\n", nc);
}
