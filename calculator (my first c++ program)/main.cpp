#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>

using namespace std;

int main() {
    // declaring the neccesary vars
    long double power;
    long double num1;
    long double num2;
    string operation;
    string decider;
    // making it so that the user can decide if they want to do multiple operations
    for (int i = 0; i < 1; i++) {
        //asking the operator
        cout << "The operation you would like to use please: (a|s|m|d|sq) ";
        cin >> operation;
        
        // checks for false operations
        if (operation != "a" && operation != "m" && operation != "s" && operation != "d" && operation != "sq") {
            cout << "Make sure to properly enter (a|s|m|d|sq) to get a good result otherwise enter (n) to close the program: ";
            cin >> operation;
            if (operation == "n") {
                return 0;
            } else if (operation != "a" && operation != "m" && operation != "s" && operation != "d" && operation != "sq") {
                cout << "you didn't listen..." << endl;
                return 0;
            }
        }
        
        // checking if the operator is a specific operation for all of them
        if (operation == "+" || operation == "a" || operation == "add") {
            cout << "Your first number please: ";
            cin >> num1;
            cout << "Your second number please: ";
            cin >> num2;
            
            cout << num1 + num2 << endl;
        }
        
        if (operation == "-" || operation == "s" || operation == "subtract" || operation == "sub") {
            cout << "Your first number please: ";
            cin >> num1;
            cout << "Your second number please: ";
            cin >> num2;
            
            cout << num1 - num2 << endl;
        }
        
        if (operation == "*" || operation == "m" || operation == "x" || operation == "multiply") {
            cout << "Your first number please: ";
            cin >> num1;
            cout << "Your second number please: ";
            cin >> num2;
            
            cout << num1 * num2 << endl;
        } 
        
        if (operation == "/" || operation == "d" || operation == "division") {
            cout << "Your first number please: ";
            cin >> num1;
            cout << "Your second number please: ";
            cin >> num2;
            
            cout << num1 / num2 << endl;
        }
        
        if (operation == "square" || operation == "sq") {
            cout << "Your power to raise please: ";
            cin >> power;
            cout << "Your number please: ";
            cin >> num1;
    
            cout << pow(num1, power) << endl;
        }
        
        // asks if user want to do another operation
        cout << "Would you like to do another operation? (y|n) ";
        cin >> decider;
        
        // if yes it says "i-= 1;" so that the program reruns one more iteration
        if (decider == "yes" || decider == "y" || decider == "ye") {
            i-= 1;
        } else if (decider == "n" || decider == "no" || decider == "nah") {
            return 0;
        } else {
            cout << "Please properly enter (y|n) to close or keep the program open: (y|n) ";
            cin >> decider;
            if (decider == "n" || decider == "no" || decider == "nah") {
                return 0;
            } else if (decider == "yes" || decider == "y" || decider == "ye") {
                i -= 1;
            } else {
                cout << "you didn't listen...";
                return 0;
            }
        }
    }
}
