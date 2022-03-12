//
// File: program.c
// Program.c is an example of a documented file.
// The file also offers TODO notes of advice; delete or replace these.
// @author Omar Ramirez-Chio
// // // // // // // // // // // // // // // // // // // // // // //

#include <stdio.h>
#include <stdlib.h>

/**
 * Prints the number of arguments and the argument that was inputted.
 * @param argc  number of command line arguments, including program name
 * @param argv  supplied command line arguments, including program name
 * @returns error_code  EXIT_SUCCESS if no error or EXIT_FAILURE
*/

int main( int argc, char* argv[] ) {
    printf( "The argument count of load module %s is %d.\n",
            argv[0], argc );

    return EXIT_SUCCESS ;
}

