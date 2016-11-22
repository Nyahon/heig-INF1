
/*
 -----------------------------------------------------------------------------------
 Laboratoire : 05b
 Fichier     : Laboratoire05b_Demierre_Melly.cpp
 Auteur(s)   : Yann Demierre, Johanna Melly
 Date        : 21.11.2016

 But         :  Print the calendar of any year for each month. We take care of leap
                year, and start the year at the correct date.
                Add the possibility to choose the starting year and month.
                Print the number of each week of the year.

 Remarque(s) : 1.   Use of the Mike Keith algorihm to calulate the date of the first
                    day of the year.
               2.   Use of functions but no prototypes, given that our functions are
                    mostly one line long.
               3.   Use of english names

 Compilateur : g++ 4.8.1
 -----------------------------------------------------------------------------------
 */
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>
#include <climits>
#include <cmath>
#include <ctime>

#define VIDER_BUFFER cin.ignore(INT_MAX, '\n')

using namespace std;


const int WIDTH_TEXT = 30u;
const int WIDTH_INT  = 4u;
/*
 Asks the user if he wants to start the program again
 Checks the validity of the input
 Returns char that may end the program or not
*/


bool doAgain();
int input(string message, int limitMin, int limitMax, string error="Mauvaise saisie. Veuillez reessayez");
void printRoad(int lengthCirc,int amplitude,int widthRoad,int width);
void toQuit(string message);

int main() {
    const int   LENGTH_MIN      = 0,
                LENGTH_MAX      = 1000,
                AMP_MIN         = 1,
                AMP_MAX         = 3,
                WIDTH_ROAD_MIN  = 3,
                WIDHT_ROAD_MAX  = 10,
                WIDTH_MIN       = 20,
                WIDHT_MAX       = 50;

    int         lengthCirc,
                amplitude,
                widthRoad,
                width;

    srand(time(NULL));
    do{
        cout << "Ce programme affiche une route en fonction de différents paramètres" << endl << endl;

        lengthCirc  = input("Longueur du circuit", LENGTH_MIN, LENGTH_MAX);
        amplitude   = input("Amplitude max des virages", AMP_MIN, AMP_MAX);
        widthRoad   = input("Largeur de la route", WIDTH_ROAD_MIN, WIDHT_ROAD_MAX);
        width       = input("Largeur totale", WIDTH_MIN, WIDHT_MAX);

        printRoad(lengthCirc, amplitude, widthRoad, width);

    }while(doAgain());

    toQuit("Pressez ENTER pour quitter..");
    return EXIT_SUCCESS;
}

bool doAgain(){

    char const YES = 'Y';
    char const NO = 'N';
    char answer;
    bool isValid;
    do{
        cout << "Do you want to start again? ["<<YES<<"/"<<NO<<"]";
        isValid = bool(cin >> answer);
        if(isValid)
            cin.clear();
        VIDER_BUFFER;

        }while(!(isValid || toupper(answer) == YES || toupper(answer) == NO));

        return(toupper(answer)==YES);
}

int input(string message, int limitMin, int limitMax, string error){
    int userInput;
    bool isValid;
    do{                                      //Shut Clion about u long
        cout  << message << setw(WIDTH_TEXT-(int)message.length()) << ": [ " << setw(WIDTH_INT) << limitMin << " et " << setw(WIDTH_INT) << limitMax <<"] :" ;
        isValid = bool(cin >> userInput);

        if(!isValid || userInput < limitMin || userInput > limitMax ){
            cout << error << endl;
            cin.clear();
        }
        VIDER_BUFFER;

    }while(!isValid || userInput < limitMin || userInput > limitMax);

    return userInput;
}

void printRoad(int lengthCirc,int amplitude,int widthRoad,int width){

    const char CHAR_LIM     = '|';
    const char CHAR_ROAD    = '=';
    const char CHAR_SPACE   = ' ';

    int sizeSpace = (width-2-widthRoad)/2;
    int shift = 0;
    int shiftmp;
    for (int dist=0;dist<=lengthCirc;++dist){

        if(dist){
            shiftmp = rand()%((amplitude*2)+1)-amplitude;

            shift = sizeSpace-shiftmp <= -1 ? -abs(shiftmp) : width-2-widthRoad-sizeSpace+shiftmp <= -1 ? abs(shiftmp) : shiftmp;
        }
        cout    << setw(WIDTH_INT) << (dist%10 ? " " : to_string(dist))
                << CHAR_LIM
                << string(sizeSpace-shift,CHAR_SPACE) 
                << string(widthRoad,CHAR_ROAD)
                << string(width-2-widthRoad-sizeSpace+shift,CHAR_SPACE)
                << CHAR_LIM << endl;
        sizeSpace-=shift;
    }

}
void toQuit(string message){
    cout << message;
    cin.get();
}

