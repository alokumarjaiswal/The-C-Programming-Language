#include <stdio.h>
#define MAXLINE 1000

/* Exercise 1-18. Write a program to remove trailing blanks and tabs from each
        line of input, and to delete entirely blank lines.
*/

int getline_trim(char line[], int maxline);
void remove_trailing_blanks(char line[]);

int main() {
  char line[MAXLINE];

  while (getline_trim(line, MAXLINE) > 0) {
    remove_trailing_blanks(line);
    if (line[0] != '\0') { // If the line is not empty after trimming
      printf("%s\n", line);
    }
  }

  return 0;
}

// getline_trim: read a line into 'line', return its length
int getline_trim(char line[], int maxline) {
  int c, i;

  for (i = 0; i < maxline - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
    line[i] = c;
  }

  if (c == '\n') {
    line[i] = c;
    ++i;
  }

  line[i] = '\0';
  return i;
}

// remove_trailing_blanks: remove trailing blanks and tabs from a line
void remove_trailing_blanks(char line[]) {
  int i;

  // Find the end of the line
  for (i = 0; line[i] != '\0'; ++i)
    ;

  // Step back from the end of the line and remove trailing spaces or tabs
  while (i > 0 &&
         (line[i - 1] == ' ' || line[i - 1] == '\t' || line[i - 1] == '\n')) {
    --i;
  }

  line[i] = '\0'; // Null-terminate the line
}
