#include <stdio.h>

/* Character Input and Output
    A text stream is a sequence of characters divided into lines; 
    each line consists of zero or more characters followed by '\n'.
    Input is read from a text stream, i.e., from keyboard or a file.
    After, c = getchar(); 'c' contains the next character of input.
    putchar(c); prints the contents of the integer variable 'c' as a character.

    File Copying
    read a character
    while (character is not end-of-file indicator)
        output the character just read
        read a character

    copy input to output; 1st version
    EOF is a symbolic constant, for 'end of file'.
    It is an integer defined in '<stdio.h>'.
    EOF is the reason 'c' is declared as 'int' and not 'char'.
    'c' must be big enough to hold EOF in addition to any possible 'char'.
    EOF is used to solve the problem which is distinguishing 
    the end of input from valid data.
    The solution is that 'getchar' returns a distinctive value 
    when there is no more input, a value that cannot be confused 
    with any real character.
*/

int main() 
{
    int c;

    c = getchar();
    while(c != EOF) {
        putchar(c);
        c = getchar();
    }
}