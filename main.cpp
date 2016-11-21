
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
#include <limits>
#include <cmath>

using namespace std;

/*
 Asks the user if he wants to start the program again
 Checks the validity of the input
 Returns char that may end the program or not
*/


bool doAgain();
void askUser(string message, int limitMin, int limitMax);

int main() {
    char YES = 'Y';
    char answer;
    string message;
    
    
    do{
        
        
        
        
        
        
        answer = doAgain();
    }while(answer);
    
    return EXIT_SUCCESS;
}


bool doAgain(){
    
    char const YES = 'Y';
    char const NO = 'N';
    char answer;
    
    do{
        cout << "Do you want to start again? [y/n]";
        cin >> answer;
        if(answer == YES){
            answer = tolower(YES);
        }
        }while(answer != YES || answer != tolower(NO) && answer != NO);
       
        
        return(answer==YES);
}

void askUser(string message, int limitMin, int limitMax){
    int userInput;
    do{
        cout << message;
        cin >> userInput;
        
    }while(userInput < limitMin || userInput > limitMax);
    
    return userInput; 
}