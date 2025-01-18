#include <stdio.h>

#define MAXLINE 1000 // maximum input line size
#define THRESHOLD 80 // Exercise 1-17

/* Character Arrays
    We are writing a program that reads a set of text lines
    and prints the longest.
    The outline is simple enough:
            while (there's another line)
                    if (it's longer than the previous longest)
                            save it
                            save its length
            print longest line

    We are writing two functions, 'getline' and 'copy'.
    'getline' is used to fetch the next line of input.
    At the minimum, 'getline' has to return a signal about
    possible end of file; a more useful design would be to
    return the length of line, or zero if end of file is encountered.
    Zero is an acceptable end-of-file return because it is never a valid
    line length. Every text line has at least one character; even a line
    containing only a newline has length 1.
    'copy' is used to copy the new line to a safe place.
    main program is used to control 'getline' and 'copy'.

    'getline' puts the character '\0' (the null character, whose value is
   zero) at the end of the array it is creating, to mark the end of the string
   of characters. This convention is also used by the C language: when a string
   constant like "hello\n" appears in a C program, it is stored as an array of
   characters containing the characters of the string and terminated with a '\0'
   to mark the end.
                        | h | e | l | l | o | \n | \0 |
   The '%s' format specification in 'printf' expects the corresponding argument
   to be a string represented in this form.
   'copy' also relies on the fact that its input argument is terminated by '\0'
   and it copies this character into the output argument. All of this implies
   that '\0' is not part of normal text.

   Exercise 1-16. Revise the main routine of the longest-line program so it will
   correctly print the length of arbitrarily long input lines, and as much as
   possible of the text.
   Exercise 1-17. Write a program to print all input lines that are longer than
   80 characters.
*/

int getline(char line[], int maxline);
void copy(char to[], char from[]);

// print longest input line
int main() {
  int len;               // current line length
  int max;               // maximum length seen so far
  char line[MAXLINE];    // current input line
  char longest[MAXLINE]; // longest line saved here

  max = 0;
  while ((len = getline(line, MAXLINE)) > 0) {
    if (len > THRESHOLD) {
      printf("%s", line);
    }
    if (len > max) {
      max = len;
      copy(longest, line);
    }
  }
  if (max > 0) { // there was a line
    printf("%s", longest);
    printf("%d", max);
  }

  return 0;
}

// getline: read a line into s, return length
int getline(char s[], int lim) {
  int c, i;

  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
    s[i] = c;
  }
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';

  return i;
}

// copy: copy 'from' into 'to'; assume 'to' is big enough
void copy(char to[], char from[]) {
  int i = 0;

  while ((to[i] = from[i]) != '\0') {
    ++i;
  }
}