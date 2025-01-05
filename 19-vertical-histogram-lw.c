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
    This is the vertical histogram.
    The vertical formatting of histogram requires some explanation.
    First, the maximum count is found from the array, which means
    we have the highest frequency or height upto which the histogram
    is to be printed.
    Since, formatting is done horizontally as there is no way, at least
    now to go up once we come down. The logic hence is designed to print
    the histogram row by row.
    The maximum count gives the number of rows. Then, we iterate through
    the array with the condition that if the current index value is greater
    than or equal to the number of rows, we print '*', else ' '. The '>' sign,
    is necessary as when the number of rows is decreased, and we run through the
    loop again, the '*' will be printed again below the '*', which was printed
    previously in the above row.
*/

int main() {
  int c, lw, state, max_count;
  int word_lengths[MAX_WORD_LENGTH + 1];

  lw = 0;
  state = OUT;
  max_count = 0;
  for (int i = 1; i <= (MAX_WORD_LENGTH + 1); ++i) {
    word_lengths[i] = 0;
  }

  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\n' || c == '\t') {
      if (state == IN) {
        state = OUT;
        if (lw >= MAX_WORD_LENGTH) {
          ++word_lengths[MAX_WORD_LENGTH];
        } else if (lw > 0 && lw < MAX_WORD_LENGTH) {
          ++word_lengths[lw];
        }
        lw = 0;
      }
    } else {
      ++lw;
      state = IN;
    }
  }

  for (int i = 1; i <= (MAX_WORD_LENGTH + 1); ++i) {
    if (word_lengths[i] > max_count) {
      max_count = word_lengths[i];
    }
  }

  for (int row = max_count; row > 0; --row) {
    for (int i = 1; i <= MAX_WORD_LENGTH; i++) {
      if (word_lengths[i] >= row) {
        printf(" * ");
      } else {
        printf("   ");
      }
    }

    putchar('\n');
  }

  for (int i = 0; i <= MAX_WORD_LENGTH; i++) {
    printf("----");
  }
  putchar('\n');
  for (int i = 1; i <= MAX_WORD_LENGTH; ++i) {
    if (i == MAX_WORD_LENGTH) {
      printf("%3d+", i);
    } else {
      printf("%3d", i);
    }
  }
  putchar('\n');

  return 0;
}