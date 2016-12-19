//
// Created by nyahon on 13.12.16.
//
#ifndef LABO07_MODEL_H
#define LABO07_MODEL_H
#include "utils.h"
#include <cmath>

int genRandomVal(const int minVal, const int maxVal);
                            //PASS SIZE-1 DUMBASS
void throws(int tab[], int size, int nbThrows);
double getPercent(int tabCell, int nbThrowns);


                            //PASS SIZE-1 DUMBASS
void printThrows(const int tab[], int size);
void initTab(int tab[], const int min, const int max, int initVal);

#endif