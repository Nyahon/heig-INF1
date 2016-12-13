
#include <iostream>
#include "model.h"

int main() {

    const int   MIN_VALUE = 0,
                MAX_VALUE = 100,
                MIN_THROWS = 0 ,
                MAX_THROWS = (int)1e5;
    int nbThrows,
        maxValue;


    do{
        maxValue = input("nombre d'elements", MIN_VALUE, MAX_VALUE);
        int tab[maxValue+1];
        nbThrows = input("nombre de lancers", MIN_THROWS, MAX_THROWS);
        initTab(tab, 0x00, maxValue+1, 0b00);

            tab[maxValue+1] = nbThrows;
        cout << tab[maxValue+1];

        throws(tab, maxValue, nbThrows);
        printThrows(tab, maxValue);


    }while(doAgain());
}