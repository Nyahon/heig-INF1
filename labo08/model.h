//
// Created by nyahon on 13.12.16.
//
#ifndef LABO07_MODEL_H
#define LABO07_MODEL_H
#include "utils.h"
#include <cmath>

/**
 * @brief: generate random value with min and max.
 *
 * parameters:
 *      @param minVal : minimal value
 *      @param maxVal : maximal value 
 *
 * @return:
 *      the int random value
 **/
int genRandomVal(const int minVal, const int maxVal);

/**
 * @brief: do the number of throws and add generate value to the table
 *
 * parameters:
 *      @param tab[]  : table for the generate value
 *      @param size   : table size. 
 *      @param nbThrows: number of Throws
 *
 * @return:
 *      nothing.
 **/
void throws(int tab[], int size, int nbThrows);

/**
 * @brief: calcul a percent of the number add in one table case.
 *
 * parameters:
 *      @param tabCell  : case of the table
 *      @param size   : table size. 
 *
 * @return:
 *     the percent value in double.
 **/
double getPercent(int tabCell, int nbThrowns);

/**
 * @brief: print the table of throws.
 *
 * parameters:
 *      @param tab[]  : table for the generate value
 *      @param size   : table size.
 *
 * @return:
 *     nothing
 **/
void printThrows(const int tab[], int size);

/**
 * @brief: initialize the table.
 *
 * parameters:
 *      @param tab[] : table for the generate value
 *      @param min   : case location for the first value.
 *      @param max   : case location for the last value.
 *      @param initVal: value in the different case of the table.
 * @return: 
 *     nothing
 **/
void initTab(int tab[], const int min, const int max, int initVal);

#endif