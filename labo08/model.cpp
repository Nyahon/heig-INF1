//
// Created by nyahon on 13.12.16.
//

#include "model.h"

int genRandomVal(const int minVal, const int maxVal) {
    static bool first;
    if(!first)
        srand(time(NULL));

    //the minVal cannot be greater than maxVal
    if (minVal >= maxVal) {
        return EXIT_FAILURE;
    }
    int range;
    range = maxVal - minVal;
    first = true;
    //return a negative or a positive number
    return (rand() % ((range * 2 + 1) - range))+minVal ;


}
                            //PASS SIZE-1 DUMBASS
void throws(int tab[], int size, int nbThrows){

    for(int ite=0;ite<nbThrows;ite++){
        ++tab[genRandomVal(0, size)];
    }
}
double getPercent(int tabCell, int nbThrowns){
    return 100.*tabCell/nbThrowns;
}

                            //PASS SIZE-1 DUMBASS
void printThrows(const int tab[], int size){
    for(int ite=0;ite<size;ite++){
        double percent = getPercent(tab[ite], tab[size+1]);
        double percentbis = (percent-int(percent));
        percentbis = percentbis*10;
        cout << "tableau[" << ite << "]" <<  setw(WIDTH_INT_BASE*2) << percent << setw(WIDTH_TEXT_BASE/3) << " " << string(int(percent), '=') << string(int(percentbis), '.') << endl;
    }
}
void initTab(int tab[], const int min, const int max, int initVal){
    for(int ite=min;ite<max;ite++){
        tab[ite] = initVal;
    }
}