#include <iostream>
#include <cstdlib>
#include <ctime>
 
char ROCK = 'r';
char PAPER = 'p';
char SCISSORS = 's';
float intRock = 1;
float intPaper = 1;
float intScissors = 1;

using namespace std;


 
char getComputerOption() {
    if(intRock == intPaper && intScissors == intPaper && intRock == intScissors) {
        srand(time(0));
        // Random number
        int num = rand() % 3 + 1;
        if(num==1) return 'r';
        if(num==2) return 'p';
        if(num==3) return 's';
    } else
    if(intRock == intPaper && intScissors < intPaper && intScissors < intRock) {
        srand(time(0));
        // Random number
        int num = rand() % 2 + 1;
        if(num==1) return 'r';
        if(num==2) return 'p';
    } else
    if(intScissors == intPaper && intRock < intPaper && intRock < intScissors) {
        srand(time(0));
        // Random number
        int num = rand() % 2 + 1;
        if(num==1) return 'p';
        if(num==2) return 's';
    } else
    if(intRock == intScissors && intRock > intPaper && intScissors > intPaper) {
        srand(time(0));
        // Random number
        int num = rand() % 2 + 1;
        if(num==1) return 'r';
        if(num==2) return 's';
    } else
    if(intRock > intPaper && intRock > intScissors) {
        return 'r';
    } else
    if(intPaper > intRock && intPaper > intScissors) {
        return 'p';
    } else
    if(intScissors > intPaper && intScissors > intRock) {
        return 's';
    }
}
 
char getUserOption() {
    char c;
    cout << "--------------------------------------------------------------------------------------"  << endl;
    cout << "Rock, Paper and Scissors Game!" << endl;
    cout << "Choose one of the following options"  << endl;
    cout << "-----------------------------------"  << endl;
    cout << "(r) for rock " << endl << "(p) for paper" << endl << "(s) for scissors " << endl << "(q) quit " << endl;
    cout << "\n";
    cin >> c;
    
    while (c!='r' && c!='p' && c!='s' && c!='q')
    {
        cout << "Please enter one of the following options only. " << endl;
        cout << "(r) for rock " << endl << "(p) for paper" << endl << "(s) for scissors " << endl << "(q) quit " << endl;
        cout << "\n";
        cin >> c;
    }
 
    return c;
}
 
void showSelectedOption(char option) {
    if (option == 'r') cout << "Rock" << endl;
    if (option == 'p') cout << "Paper" << endl;
    if (option == 's') cout << "Scissors" << endl;
}
 
void chooseWinner(char uChoice, char cChoice) {
    if (uChoice == ROCK && cChoice == PAPER) {
        intPaper = intPaper + 0.5;
        cout << "Computer Wins! Paper wraps Rock." << endl;
    }
    else if (uChoice == PAPER && cChoice == SCISSORS) {
        intScissors = intScissors + 0.5;
        cout << "Computer Wins! Scissors cut Paper." << endl;
    }
    else if (uChoice == SCISSORS && cChoice == ROCK) {
        intRock = intRock + 0.5;
        cout << "Computer Wins! Rock smashes Scissors." << endl;
    }
    else if (uChoice == ROCK && cChoice == SCISSORS) {
        intScissors = intScissors - 0.5;
        cout << "You Win! Rock smashes Scissors." << endl;
    }
    else if (uChoice == PAPER && cChoice == ROCK) {
        intRock = intRock - 0.5;
        cout << "You Win! Paper wraps Rock." << endl; 
    }
    else if (uChoice == SCISSORS && cChoice == PAPER) {
        intPaper = intPaper - 0.5;
        cout << "You Win! Scissors cut Paper." << endl;
    }
    else{
        cout << "Draw. Play again win the Game." << endl;
    }
}
 
int main() {
    //User's choice
    char uChoice;
    //Compter's choice
    char cChoice;
    uChoice = getUserOption();
    while(uChoice != 'q') {
        cout << "Your choice is: ";
        showSelectedOption(uChoice);
    
        cout << "Computer's choice is: ";
        cChoice = getComputerOption();
        showSelectedOption(cChoice);
    
        chooseWinner(uChoice, cChoice);

        cout << "Rock Score is : " << intRock << endl;
        cout << "Paper Score is : " << intPaper << endl;
        cout << "Scissors Score is : " << intScissors << endl;
        
        uChoice = getUserOption();

    }
 
    return 0;
}
