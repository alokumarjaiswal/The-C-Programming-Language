#include <stdio.h>

#define MAXLINE 1000 // Maximum line length

int getline(char line[], int maxline);
void reverse(char line[]);

int main() {
  char line[MAXLINE];

  while (getline(line, MAXLINE) > 0) {
    reverse(line);
    printf("%s", line); // No need for additional '\n', as reverse keeps the
                        // newline intact
  }

  return 0;
}

// Read a line into 'line', return its length
int getline(char line[], int maxline) {
  int i, c;

  for (i = 0; i < maxline - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
    line[i] = c;
  }
  if (c == '\n') { // Include the newline character if present
    line[i] = c;
    ++i;
  }
  line[i] = '\0'; // Null-terminate the string

  return i;
}

// Reverse the string 'line' in place
void reverse(char line[]) {
  int i, j;
  char temp;

  // Find the length of the string (excluding '\0')
  for (i = 0; line[i] != '\0'; ++i)
    ;

  // Exclude the newline character from reversal if present
  if (i > 0 && line[i - 1] == '\n') {
    --i;
  }

  // Reverse the string in place
  for (j = 0; j < i / 2; ++j) {
    temp = line[j];
    line[j] = line[i - j - 1];
    line[i - j - 1] = temp;
  }
}
