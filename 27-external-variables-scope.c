#include <stdio.h>

#define MAXLINE 1000 // maximum input line size

int max;               // maximum length seen so far
char line[MAXLINE];    // current input line
char longest[MAXLINE]; // longest line saved here

/* External Variables and Scope
    Each local variable in a function comes into existence only when
    the function is called, and disappears when the function is exited.
    This is why such variables are usually known as 'automatic' variables.
    Because automatic variables come and go with function invocation, they
    do not retain their values from one call to the next, and must be explicitly
    set upon each entry.
    If they are not set, they will contain garbage.
    As an alternative to automatic variables, it is possible to define
    variables that are 'external' to all functions, that is, variables that
    can be accessed by name by any function.
    Because external variables are globally accessible, they can be used
    instead of argument lists to communicate data between functions.
    Furthermore, because external variables remain in existence permanently,
    rather than appearing and disappearing as functions are called and exited,
    they retain their values even after the functions that set them have
   returned. An external variable must be 'defined', exactly once, outside of
   any function; this sets aside storage for it. The variable must also be
   'declared' in each function that wants to access it; this states the type of
   the variable. The declaration maybe an explicit 'extern' statement or may be
   implicit from context. If the definition of an external variable occurs in
   the source file before its use in a particular function, then there is no
   need for an 'extern' declaration in the function. The 'extern' declarations
   in 'main', 'getline' and 'copy' are thus redundant. In fact, common practice
   is to place definitions of all external variables at the beginning of the
   source file, and then omit all 'extern' declarations. If the program is in
   several source files, and a variable is 'defined' in 'file1' and used in
   'file2' and 'file3', then 'extern' declarations are needed in 'file2' and
   'file3' to connect the occurrences of the variable. The usual practice is to
   collect 'extern' declarations of variables and functions in a separate file,
   historically called a 'header', that is include by '#include' at the front of
   each source file. The suffix '.h' is conventional for header names. The
   functions of the standard library, for example, are declared in headers like
   '<stdio.h>'. Since the specialized versions of 'getline' and 'copy' have no
   arguments, logic would suggest that their prototypes at the beginning of the
   file should be 'getline()' and 'copy()'. But for compatibility with older C
   programs the standard takes an empty list as an old-style declaration, and
   turns off all argument list checking; the word 'void' must be used for an
   explicitly empty list. "Definition" refers to the place where the variable is
   created oe assigned storage; "declaration" refers to places where the nature
   of the variable is stated but no storage is allocated. Argument lists are
   short and variables are always there when you want them. But external
   variables are always there even when you don't want them. Relying too heavily
   on external variables is fraught with peril since it leads to programs whose
   data connections are not at all obvious - variables can be changed in
   unexpectd and even inadvertent ways, and the program is hard to modify. This
   version of the longest-line program is inferior to the first, partly for
    these reasons, and partly because it destroys the generality of two useful
    functions by wiring into them the names of the variables they manipulate.
*/

int getline(void);
void copy(void);

// print longest input line; specialized version
int main() {
  int len;
  extern int max;
  extern char longest[];

  max = 0;
  while ((len = getline()) > 0) {
    if (len > max) {
      max = len;
      copy();
    }
  }
  if (max > 0) {
    printf("%s", longest);
  }

  return 0;
}

// getline: specialized version
int getline(void) {
  int c, i;
  extern char line[];

  for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
    line[i] = c;
  }
  if (c == '\n') {
    line[i] = c;
    ++i;
  }
  line[i] = '\0';

  return i;
}

// copy: specialized version
void copy(void) {
  int i = 0;
  extern char line[], longest[];

  while ((longest[i] = line[i]) != '\0') {
    ++i;
  }
}