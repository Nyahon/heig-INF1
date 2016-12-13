
/*
 -----------------------------------------------------------------------------------
 Laboratoire : 06
 Fichier     : Laboratoire06_Meyer_Melly.cpp
 Auteur(s)   : Yohann Meyer, Johanna Melly
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
 * Goal: asks the user if he want to restart or exit the program
 *       checks if the inputs are valids
 *
 * parameters:
 *      none
 *
 * @return:
 *      isValid: boolean containing the answer of the user to the question
 *               "do you want to start again?"
 */
bool doAgain();

/*
 * Goal: asks the user which vaules he want to use for the program
 *       checks if the inputs are valids
 *       if the inputs are not valids, asks again the user to enter the values
 *
 * parameters:
 *      @param message   : string that contains the message aasking the user about
 *                         the values needed in the program
 *      @param limitMin  : int that contains the lowest integer that the user
 *                         is allowed to enter
 *      @param limitMax  : int that contains the highest integer that the user
 *                         is allowed to enter
 *      @param error     : string that contains a message noticing the user that
 *                         he entered an invalid value
 *      @param WIDTH_INT : const int that contains the width of the left margin
 *      @param WIDTH_TEXT: const int that contains a width that will be used
 *                         to align the text that is displayed
 *       
 *
 * @return:
 *      userInput : int contianing the value that the user entered
 */
int input(string message, int limitMin, int limitMax, string error="Mauvaise saisie. Veuillez reessayez", const int WIDTH_INT=4u, const int WIDTH_TEXT=30u);

/*
 * Goal: randomly displays a road, using the values that the user entered before
 *       as constraints
 *
 * parameters:
 *      @param lengthCirc : int that contains the length of the road
 *      @param range      : int that contains the highest range possible
 *      @param widthRoad  : int that contains the width of the road
 *      @param width      : int that contains the total width (border to border)
 *      @param WIDTH_INT  : const int that contains the width of the left margin
 * 
 * @return:
 *      nothing
 */
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

/*
 * Goal: randomly displays a road using values entered by the user.
 *       Uses the function.
 *
 * parameters:
 *      none
 *
 * @return:
 *      EXIT_SUCCESS
 */
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
        range       = input("Amplitude max des virages", AMP_MIN, AMP_MAX);
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
    do{
        cout  << message << setw(WIDTH_TEXT-message.length()) << ": [ " << setw(WIDTH_INT) << limitMin << " et " << setw(WIDTH_INT) << limitMax <<"] :" ;
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
