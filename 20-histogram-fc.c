#include <stdio.h>

#define ASCII_SIZE 128

/* Exercise 1-14. Write a program to print a histogram of
    the frequencies of different characters in its input.

    ASCII (American Standard Code for Information Interchange)
    has 128 encodings, ranging from 0 to 127.
    0 to 31 and 127 represent control characters and are unprintable.
    32 to 126 are printable characters.
    Well, each character has an ASCII value, so it is quite easy
    to get the frequency of characters ina an array.
*/

int main() {
  int c;
  int char_freq[ASCII_SIZE];

  for (int i = 0; i < ASCII_SIZE; ++i) {
    char_freq[i] = 0;
  }
  while ((c = getchar()) != EOF) {
    if (c >= 0 && c < ASCII_SIZE) {
      ++char_freq[c];
    }
  }

  for (int i = 0; i < ASCII_SIZE; ++i) {
    if (char_freq[i] > 0) {
      if (i >= 32 && i <= 126) {
        printf("%3c ", i); // Printable characters
      } else {
        printf("%3d ", i); // Non-printable characters, printing ASCII value
      }

      for (int j = 0; j < char_freq[i]; ++j) {
        putchar('*');
      }
      putchar('\n');
    }
  }

  return 0;
}