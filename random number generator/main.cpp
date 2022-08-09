#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

long long int num1;
long long int num2;
string decider;

int random(int a, int b) {
    srand(time(0));
    int random = a + (rand() % b);
    while (random > b) {
        random = a + (rand() % b);
    }
    return random;
}

int main () {
    for (int i = 0; i < 1; i++) {
        cout << "Your first number: ";
        cin >> num1;
        
        cout << "Your second number: ";
        cin >> num2;
        
        if (num1 > num2) {
            cout << "Make sure you first number is less then you second number, try again with the correct parameters or the program will terminate" << endl;
            cout << "Your first number: ";
            cin >> num1;
            cout << "Your second number: ";
            cin >> num2;
            if (num1 > num2) {
                "The program will terminate because you keep entering invalid parameters";
                return 0;
            } 
        }
        
        cout << random(num1, num2) << endl;
        
        cout << "Would you like to generate a random number again? (y|n) ";
        cin >> decider;
        
        if (decider != "y" && decider != "n") {
            cout << "Please enter a proper answer or enter (n) to close the program: ";
            cin >> decider;
            
            if (decider != "y" && decider != "n") {
                cout << "You didn't listen...";
                return 0;
            } else if (decider == "n") {
                return 0;
            }
        }
        
        if (decider == "n") {
            return 0;
        } else if (decider == "y") {
            i--;
        }
    }
}