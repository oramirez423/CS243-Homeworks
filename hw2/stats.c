//
// File: stats.c
// Description: stats.c computes statistic calculations for a set of grades.
//
// @author olr8350 Omar Ramirez-Chio
//
// // // // // // // // // // // // // // // // // // // // // // // // // // 

#include <stdio.h>
#include <math.h>

#include "stats.h"

/**
 * average(): Determines the average of the grades.
 */

double average( int count, const int scores[] ){
   double sum = 0;
   double average = 0;

   // looping through all the elements in scores
   // to add their values to the sum variable

   for(int i = 0; i < count; i++){
      double value = (double)(scores[i]);    //typecasting for math
      sum += value;                          //to be done correctly
   }
   average = sum / count;
   return average;
}

/**
 * std_dev(): Determines the standard deviation of the grades.
 */

double std_dev( int count, const int scores[], double mean ){
   double sum_of_differences = 0;

   // looping through all the elements in scores
   // and getting their differences, squaring it, 
   // and adding it to the sum. Typecasting
   // is also done here to get correct results.
   
   for(int i = 0; i < count; i++){
      double differences = (double)(scores[i]) - mean;
      double d_squared = differences * differences;
      sum_of_differences += d_squared;

   }
   double divided_value = sum_of_differences / (double)(count-1);
   double standard_deviation = sqrt(divided_value);
   return standard_deviation;
}


/**
 * histogram(): Created a table showing the frequencies of each grade.
 */

void histogram( int count, const int scores[] ){
   // values will hold the frequency of a letter grade
   // letter_grades is all the possible grades student can receive
   int values[10] = { 0 };
   char *letter_grades[10] = {
	   			   "A", 
				   "A-",
				   "B+", 
				   "B", 
				   "B-", 
				   "C+",
				   "C", 
				   "C-",
				   "D",
				   "F"
  			       };
   // for all the values in scores,
   // when the given score falls between the range,
   // it will increment the values array at correct index.

   for(int i = 0; i < count; i++){
      if( 92 <= scores[i] && scores[i] <= 100 ){
         values[0]++;

      } else if ( 89 <= scores[i] && scores[i] <= 91 ) {
         values[1]++;

      } else if ( 85 <= scores[i] && scores[i] <= 88 ) {
	 values[2]++;

      } else if ( 82 <= scores[i] && scores[i] <= 84 ) {
	 values[3]++;

      } else if ( 79 <= scores[i] && scores[i] <= 81 ) {
	 values[4]++;

      } else if ( 75 <= scores[i] && scores[i] <= 78 ) {  
         values[5]++;

      } else if ( 72 <= scores[i] && scores[i] <= 74 ) {
	 values[6]++;

      } else if ( 69 <= scores[i] && scores[i] <= 71 ) {
	 values[7]++;

      } else if ( 60 <= scores[i] && scores[i] <= 68 ) { 
	 values[8]++;

      } else {
         values[9]++;
      }
   }
   // prints the table with each letter grade and frequency

   for(int j = 0; j < 10; j++){
      printf("%s:\t%d\n", letter_grades[j], values[j]);
   }
}







