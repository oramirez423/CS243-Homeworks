/// bad-life.c
///
/// This is derived from faulty code downloaded by copy-paste in 2015, and 
/// modified to use curses for screen display.
///
/// This code needs serious work in these areas:
/// <ol>
/// <li>  syntax: there are a number of warnings that cause errors.
/// </li>
/// <li>  semantics: the game algorithm implementation is incorrect.
/// </li>
/// <li>  design: the implementation needs function and value refactoring.
/// </li>
/// <li>  style: formatting is poor; the mix of TAB and spaces indentation
/// needs correction, and spacing between tokens is inconsistent.
/// The course style puts the '{' at the end of the function header, not
/// on a line of its own, and function headers belong at the left margin.
/// </li>
/// <li>  documentation is almost non-existent.
/// </li>
/// <li>  proper, public C documentation uses /// or /** ... */ format comments.
/// </li>
/// </ol>
///

#define _DEFAULT_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>
// curses programs need to link with the -lcurses flag 
// For manual pages, run 'man curses' and
// also see https://github.com/tony/NCURSES-Programming-HOWTO-examples/

/**
 * header(): Prints the introduction statement.
 */
void header(void) {
   printf("\n\t..Welcome to the Game of life..\n");
}

/**
 * getNeighbors(): Determines the number of neighbors next to a cell.
 * The value increases when one of the neighboring cells has a '*'.
 * Method was included as a redesign to the neighbors to wrap
 * around at the horizontal and vertical margins.
 *
 * @param size   the size of the matrix
 * @param life   the matrix
 * @param row    the current row value
 * @param col    the current col value
 * @returns      the int value of the neighbors
 */ 
int getNeighbors(int size, char life[][size], int row, int col){
   int neighbors = 0;   
   
   //fix1 was replacing the double quotes to single quotes   
   if(life[(row - 1) % size][(col - 1) % size] == '*') {
      ++neighbors;
   }
   if(life[(row - 1) % size][col] == '*') {
      ++neighbors;
   }
   if(life[(row - 1) % size][(col + 1) % size] == '*') {
      ++neighbors;
   }
   if(life[row][(col - 1) % size] == '*') {
      ++neighbors;
   }
   if(life[row][(col + 1) % size] == '*') {
      ++neighbors;
   }
   if(life[(row + 1) % size][(col - 1)] % size == '*') {
      ++neighbors;
   }
   if(life[(row + 1) % size][col] == '*') { // fix13 '=' to '=='
      ++neighbors;
   }
   if(life[(row + 1) % size][(col + 1) % size] == '*') { //fix10 '=' to '=='
      ++neighbors;
   }
   return neighbors;
}

/**
 * gameRules(): Fixed the algorithm and implemented Conway's
 * rules correctly all in one method, rather than three. 
 * Keeps a record of the entire grid before changing all the values
 * at once to represent the next generation.
 *
 * @param size    the size of the matrix
 * @param life    the matrix
 */
void gameRules(int size, char life[][size]) { // fix14 fixing parameters
   int row, col;
   int neighbors;
   char nextGen[size][size];

   //assigning blank values to the nextGen matrix
   for(row = 0; row<size; row++){
      for(col =0; col < size; col++){
         nextGen[row][col] = ' ';
      }
   }

   for(row = 0; row<size; row++) {
      for(col = 0; col<size; col++) {

	 //calling the getNeighbors function to get 
	 //correct number of neighbors
         neighbors = getNeighbors(size, life, row, col);

	 //game of life rules
         if(life[row][col] == '*'){
            if(neighbors == 2 || neighbors == 3){
               nextGen[row][col] = '*'; //fix15 changed '==' to '='
	    } else {
	       nextGen[row][col] = ' '; //fix9 '==' to '='
	    }
	 } else if(life[row][col] == ' ') {
            if(neighbors == 3){
               nextGen[row][col] = '*'; //fix12 '==' to '='
	    }
	 }
      }
   }

   //transferring the next generation to the current geneation
   for(row = 0; row < size; row++){
      for(col = 0; col < size; col++){
         life[row][col] = nextGen[row][col];
      }
      printf("\n");
   }
   return;
}
   	
/**
 * Main function for the game of life algorithm.
 */
int main(void) {
   int orgs;     //fix4 removed unused variable gens
   int i, row, col; //fix5 removed unused variables a,b
   int count = 0; //fix6 removed unusued variable char ans
   int numrows;   //fix16 removed unused variables int x, y
   int numcols;
   /// Replaced magic values by assigning them to variable
   int size = 20;
   char life[size][size];

   header();
   printf("\nPlease enter the initial number of organisms: ");
   scanf("%i", &orgs);
	  
   // start curses environment and find boundaries of window
   initscr();                            // Start curses mode 
   getmaxyx( stdscr, numrows, numcols);  // this is a MACRO; no & needed
   mvprintw( numrows - 1, numcols / 4,
            "screen is %d wide by %d high\n", 
	     numcols, numrows);
   refresh();
   srand( 31 );
   for(i = 0; i<orgs; i++) {
      row = rand();
      row %= size;
      col = rand();
      col %= size;
      life[row][col] = '*'; // fix3 changed == to =
   }
		 
   for(row = 0; row< size; row++) {
      for(col = 0; col< size; col++) {
         if(life[row][col] != '*') {
      	    life[row][col] = ' '; // fix3 changed == to =
	 }
      }
   }

   while ( 1 ) {
      move( 0, 0);
      for(row = 0; row< size; row++) {
         for(col = 0; col< size; col++) {       
            printw("%c", life[row][col]); // fix2 changed format from s to c
         }
  	 printw( "\n");
      }
      move(size, 0);
      refresh();
      printw("generation: %d\n", count);
      count++;
      gameRules(size, life);
      ///setting a decent viewing speed
      usleep( 820225L );
   } 
   endwin(); // End curses mode at the end of the program
   return 0;
}
