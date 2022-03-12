//
// File: review_grades.c
// Description: Receives grades from command line and will complete
// computations to provide the average, standard deviation, and a 
// table representing the frequencies of each letter grade.
//
// @author olr8350 Omar Ramirez-Chio
// // // // // // // // // // // // // // // // // // // // // // //  

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "stats.h"

/**
 * str_to_int gets a string passed in and will produce the 
 * corresponding int.
 *
 * Note: this function will ignore everything other than digits. 
 *
 * @param str   the string being passed in
 * @returns     the corresponding integer
 */

int str_to_int( char *str ){
   int value = 0;
   int length = strlen(str);
   
   // loop through the string, char by char
   // to get the corresponding digits and become
   // a numeric value

   for(int i = 0; i < length; i++){
      if(isdigit(str[i]) != 0){
         value = value * 10 + ((int)(str[i]) - 48);
      } else {
         break;
      }
   }
   return value;
}

/**
 * Main function for review_grades.c
 *
 * @param argc   int number of command line arguments includes program name
 * @param argv   strings: program-name commandline-arguments
 * @returns EXIT_SUCCESS if no error, or EXIT_FAILURE on error
 */

int main(int argc, char *argv[]) {

   // checks the number of command line arguments 
   // and if it's less than two, will print to stderr,
   // and exit with EXIT_FAILURE
 
   if(argc < 2){
      fprintf( stderr, "usage: review_grades score1 [score2 ...]\n");
      fprintf( stderr, "note: ignores negative score values.\n");
      return EXIT_FAILURE;
   }
   printf("input population: %d\n", argc-1);

   // for loop to get the quantity of integers
   // that can be used for the program. Only
   // allows strings that begin with numberic values
   int adjusted_population = 0;
   for(int i = 1; i < argc; i++){
      if(isdigit(argv[i][0]) != 0){
    	 adjusted_population++;
      }
   }
   
   // this will be the array that gets passed to
   // the computational functions
   int adj_grades[adjusted_population];  
   int counter = 0;

   // for loop to pass the strings that begin with
   // numerical values to the str_to_int function
   // to get their according integer value, and will
   // put the values in an array
   for(int j = 1; j < argc; j++){
      if(isdigit(argv[j][0]) != 0){
         int checked_value = str_to_int(argv[j]);
	 printf("%d ", checked_value);
         adj_grades[counter] = checked_value;
	 counter++;
      }
   }
   printf("\nadjusted population: %d\n", adjusted_population);
   
   // calls the computational functions in stats and gets the return
   double mean = average(adjusted_population, adj_grades);
   double std_deviation = std_dev(adjusted_population, adj_grades, mean);
   printf("mean: %f\n", mean);
   printf("std deviation: %g\n", std_deviation);

   histogram(adjusted_population, adj_grades);

   return EXIT_SUCCESS;
}
