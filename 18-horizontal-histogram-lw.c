#include <stdio.h>

#define IN 1
#define OUT 0
#define MAX_WORD_LENGTH 20

/* Exercise 1-13. Write a program to print a histogram of the
    lengths of words in its input.
    It is easy to draw the histogram with the bars horizontal;
    a vertical orientation is more challenging.

    Here, the array's index is used as the length parameter and
    the number of words of that index's length is stored at that
    index in the array.
    We are doing only the horizontal one in this.
*/

int main() {
  int c, lw, state;
  int word_lengths[MAX_WORD_LENGTH + 1]; // A word cannot be length 0

  lw = 0;
  state = OUT;
  for (int i = 1; i <= (MAX_WORD_LENGTH + 1); ++i) {
    word_lengths[i] = 0;
  }
  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\n' || c == '\t') {
      if (state == IN) {
        state = OUT;
        if (lw > 0 && lw <= MAX_WORD_LENGTH) {
          ++word_lengths[lw];
        } else if (lw > MAX_WORD_LENGTH) {
          ++word_lengths[MAX_WORD_LENGTH];
        }
        lw = 0;
      }
    } else {
      state = IN;
      ++lw;
    }
  }

  for (int i = 1; i <= MAX_WORD_LENGTH; ++i) {
    if (i == MAX_WORD_LENGTH) {
      printf("%2d+ |", MAX_WORD_LENGTH);
    } else {
      printf("%2d  |", i);
    }

    for (int j = 0; j < word_lengths[i]; ++j) {
      putchar('*');
    }
    putchar('\n');
  }

  return 0;
}