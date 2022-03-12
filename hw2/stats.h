//
// File: stats.h 
// Description: stats.h is the interface for functions using simple statistics.
//
// @author csci243: Mechanics Course Account
// @author olr8350 Omar Ramirez-Chio
//
// @date 01/03/2022
// 
// // // // // // // // // // // // // // // // // // // // // // //

#ifndef _STATS_H_
#define _STATS_H_

/**
 * Returns the average of the collection, by taking the size of the
 * data array and the array containing the data.
 *
 * @param count    the size of the data array
 * @param scores[] the array containing the data
 * @returns        average of the given collection
 */

double average( int count, const int scores[] );

/**
 * Returns the sample standard deviation of the collection by using the 
 * sample standard deviation formula. Takes the size of the data array, 
 * the array containing the data, and the mean.
 *
 * @param count    the size of the data array
 * @param scores[] the data array
 * @param mean     the average of the data
 * @returns        the sample standard deviation
 */

double std_dev( int count, const int scores[], double mean );

/**
 * Prints the table showing the frequenices of each grade in the collection.
 * It checks each score against the grade scale for the plus/minus grading
 * scheme of this course, and counts how many of each is in the collection.
 *
 * @param count    the size of the data array
 * @param scores[] the array containing the data
 */

void histogram( int count, const int scores[] );

#endif
