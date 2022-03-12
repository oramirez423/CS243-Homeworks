//
// File: draw_squares.c
// Description: draws a square with a given length consisting
// of a given character.
//
// @author Omar Ramirez-Chio
// // // // // // // // // // // // // // // // // // // // //

#include <stdio.h>
#include <stdlib.h>

/**
 * draw_square(): Draws a square of a given size consisting of
 * a given character with a certain indentation from the left.
 */

void draw_square(int side, int indent, char ch){
	int counter = 0;
	
	//loop to do the appropriate amount of rows
	while(counter < side){
		//loop to get the correct indentation length
		for(int i = 0; i < indent; i++){
			printf( "%c", ' ');
		}
		//loop to print the characters the given length
		for(int j = 0; j < side; j++){
			printf("%c", ch);
		}
		printf("\n");
		//increases the counter to move on to the next row
		counter++;
	}
	printf("\n");
}

/// Main function for the program
int main ( void ) {
	draw_square(3, 2, '#');
	draw_square(5, 4, '*');
	draw_square(8, 3, '+');

	return EXIT_SUCCESS;
}
