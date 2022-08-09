#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

int random(int num1, int num2) {
    srand(time(0));
    int random = num1 + (rand() % num2);
    while (random > num2) {
        random = num1 + (rand() % num2);
    } 
    return random;
}

int aiPick;
string userPick;
string aiPicked;
string playAgain;

int main() {
    for (int i = 0; i < 1; i++) {
        cout << "What is your pick? (r|p|s) ";
        cin >> userPick;
        
        if (userPick != "rock" && userPick != "Rock" && userPick != "r" && userPick != "Paper" && userPick != "paper" && userPick != "p" && userPick != "Scissors" && userPick != "scissors" && userPick != "s") {
            cout << "Please enter a valid answer (r|p|s) or you may enter (n) to close the program: ";
            cin >> userPick;
            if (userPick == "n") {
                return 0;
            } else if (userPick != "rock" && userPick != "Rock" && userPick != "r" && userPick != "Paper" && userPick != "paper" && userPick != "p" && userPick != "Scissors" && userPick != "scissors" && userPick != "s") {
                cout << "Because you kept entering invalid parameters, the program was forced to be terminated";
                return 0;
            }
        }
        
        
        aiPick = random(1, 3);
        
        switch (aiPick) {
            case 1:
                aiPicked = "Rock";
                break;
            case 2: 
                aiPicked = "Paper";
                break;
            case 3:
                aiPicked = "Scissors";
                break;
        }
        
        if (userPick == "r" && aiPicked == "Scissors") {
            cout << "You won!" << endl;
            cout << "You picked Rock, while the AI picked Scissors!" << endl;
        } else if (userPick == "r" && aiPicked == "Paper") {
            cout << "You lost!" << endl;
            cout << "Your picked Rock, while the AI picked Paper!" << endl;
        } else if (userPick == "p" && aiPicked == "Rock") {
            cout << "You won!" << endl;
            cout << "Your picked Paper, while the AI picked Rock!" << endl;
        } else if (userPick == "p" && aiPicked == "Scissors") {
            cout << "You lost!" << endl;
            cout << "Your picked Paper, while the AI picked Scissors!" << endl;
        } else if (userPick == "s" && aiPicked == "Paper") {
            cout << "You won!" << endl;
            cout << "Your picked Scissors, while the AI picked Paper!" << endl;
        } else if (userPick == "s" && aiPicked == "Rock") {
            cout << "You lost!" << endl;
            cout << "Your picked Scissors, while the AI picked Rock!" << endl;
        } else if (userPick == "r" && aiPicked == "Rock") {
            cout << "You tied!" << endl;
            cout << "Your picked Rock, while the AI picked Rock!" << endl;
        } else if (userPick == "p" && aiPicked == "Paper") {
            cout << "You tied!" << endl;
            cout << "Your picked Paper, while the AI picked Paper!" << endl;
        } else if (userPick == "s" && aiPicked == "Scissors") {
            cout << "You tied!" << endl;
            cout << "Your picked Scissors, while the AI picked Scissors!" << endl;
        }
        
        cout << "Would you like to play again? (y|n) ";
        cin >> playAgain;
        
        if (playAgain != "y" && playAgain != "n") {
            cout << "Please enter a valid answer (y|n) you may enter (n) to close the program: ";
            cin >> playAgain;
            if (playAgain != "y" && playAgain != "n") {
                cout << "Because you kept entering invalid parameters, the program was forced to be terminated";
            } 
        }
        
        if (playAgain == "y") {
            i-= 1;
        } else if (playAgain == "n") {
            return 0;
        } 
    }
}