#include <stdio.h>

#define IN 1  // inside a word
#define OUT 0 // outside a word

/* count lines, words, and characters in input
        Everytime the program encounters the first character of a word,
        it counts one more word.
        Using symbolic constants when magic numbers appear,
        makes the program more readable and easier to change.

        The line,
                nc = nw = nl = 0;
        is a consequence of the fact that an assignment is an expression
        with a value and assignments associate from right to left.
                nc = (nw = (nl = 0));

        Expressions connected by && or || are evaluated left to right,
        and it is guaranteed that evaluation will stop
        as soon as the truth or falsehood is known.
        If 'c' is a blank,
        there is no need to test whether it is a newline or tab,
        so these tests are not made.

                The general form of if-else is,
                        if (expression)
                                statement1
                        else
                                statement2
                One and only one of the two statements
                associated with an if-else statement is performed.

                Exercise 1-11. How would you test the word count program?
                What kinds of input are most likely to uncover bugs if there are
   any?
*/

int main() {
  int c, nc, nw, nl, state;

  state = OUT;
  nc = nw = nl = 0;
  while ((c = getchar()) != EOF) {
    ++nc;

    if (c == '\n') {
      ++nl;
    }

    if (c == ' ' || c == '\t' || c == '\n') {
      state = OUT;
    } else if (state == OUT) {
      state = IN;
      ++nw;
    }
  }
  printf("%d %d %d\n", nc, nw, nl);

  return 0;
}