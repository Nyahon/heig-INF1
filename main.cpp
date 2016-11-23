
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

 Remarque(s) : 1.   We were allowed to use default parameter in function by Mr Breguet
                    after asking for the best solution not to use global variables
                    defining spaces for print.
                    At 0844 - 23.11.2016.
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

#define CLEAR_BUFFER cin.ignore(INT_MAX, '\n')

using namespace std;

/*
 Asks the user if he wants to start the program again
 Checks the validity of the input
 Returns char that may end the program or not
*/


bool doAgain();
int input(string message, int limitMin, int limitMax, string error="Mauvaise saisie. Veuillez reessayez", const int WIDTH_INT=4u, const int WIDTH_TEXT=30u);

void printRoad(int lengthCirc, int range, int widthRoad, int width, const int WIDTH_INT=4u);
/*
 * Goal: Show a prompt for the user to definitely quit the program.
 *
 * parameters:
 *      @param message : string containing the exit message
 *
 * @return:
 *      nothing
 */
void toQuit(string message);

int main() {
    const int   LENGTH_MIN      = 0,
                LENGTH_MAX      = 1000,
                AMP_MIN         = 1,
                AMP_MAX         = 3,
                WIDTH_ROAD_MIN  = 3,
                WIDTH_ROAD_MAX  = 10,
                WIDTH_MIN       = 20,
                WIDTH_MAX       = 50;

    int         lengthCirc,
                range,
                widthRoad,
                width;

    srand(time(NULL));
    do{
        cout << "Ce programme affiche une route en fonction de différents paramètres" << endl << endl;

        lengthCirc  = input("Longueur du circuit", LENGTH_MIN, LENGTH_MAX);
        range   = input("range max des virages", AMP_MIN, AMP_MAX);
        widthRoad   = input("Largeur de la route", WIDTH_ROAD_MIN, WIDTH_ROAD_MAX);
        width       = input("Largeur totale", WIDTH_MIN, WIDTH_MAX);

        printRoad(lengthCirc, range, widthRoad, width);

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
        cout << "Voulez-vous recommencer ? ["<<YES<<"/"<<NO<<"]";
        isValid = bool(cin >> answer);
        if(isValid)
            cin.clear();
        CLEAR_BUFFER;

        }while(!(isValid || toupper(answer) == YES || toupper(answer) == NO));

        return(toupper(answer)==YES);
}

int input(string message, int limitMin, int limitMax, string error, const int WIDTH_INT, const int WIDTH_TEXT){
    int userInput;
    bool isValid;
    do{                                      //Shut Clion about u long
        cout  << message << setw(WIDTH_TEXT-(int)message.length()) << ": [ " << setw(WIDTH_INT) << limitMin << " et " << setw(WIDTH_INT) << limitMax <<"] :" ;
        isValid = bool(cin >> userInput);

        if(!isValid || userInput < limitMin || userInput > limitMax ){
            cout << error << endl;
            cin.clear();
        }
        CLEAR_BUFFER;

    }while(!isValid || userInput < limitMin || userInput > limitMax);

    return userInput;
}

void printRoad(int lengthCirc,int range,int widthRoad,int width, const int WIDTH_INT){

    const char CHAR_LIM     = '|';
    const char CHAR_ROAD    = '=';
    const char CHAR_SPACE   = ' ';

    int sizeSpace = (width-2-widthRoad)/2;
    int shift = 0;
    string widthRoadPrint = string(widthRoad,CHAR_ROAD);
    for (int dist=0;dist<=lengthCirc;++dist){

        if(dist){
            shift = rand()%((range*2)+1)-range;

            shift = sizeSpace-shift <= -1 ? -abs(shift) : width-2-widthRoad-sizeSpace+shift <= -1 ? abs(shift) : shift;
        }
        cout    << setw(WIDTH_INT) << (dist%10 ? " " : to_string(dist))
                << CHAR_LIM
                << string(sizeSpace-shift,CHAR_SPACE)
                << widthRoadPrint
                << string(width-2-widthRoad-sizeSpace+shift,CHAR_SPACE)
                << CHAR_LIM << endl;
        sizeSpace-=shift;
    }

}
void toQuit(string message){
    cout << message;
    cin.get();
}
