#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    // ais ships
    int ships[4][4] = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };
    
    int copyShips[4][4];
    
    // inserting ships randomly inside of the "ships" array
    srand(time(0));
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            ships[i][j] = rand() % 2;
        }
    }
    
    copyShips[0][0] = ships[0][0];
    copyShips[0][1] = ships[0][1];
    copyShips[0][2] = ships[0][2];
    copyShips[0][3] = ships[0][3];
    copyShips[1][0] = ships[1][0];
    copyShips[1][1] = ships[1][1];
    copyShips[1][2] = ships[1][2];
    copyShips[1][3] = ships[1][3];
    copyShips[2][0] = ships[2][0];
    copyShips[2][1] = ships[2][1];
    copyShips[2][2] = ships[2][2];
    copyShips[2][3] = ships[2][3];
    copyShips[3][0] = ships[3][0];
    copyShips[3][1] = ships[3][1];
    copyShips[3][2] = ships[3][2];
    copyShips[3][3] = ships[3][3];
    
    // finding out how many ship there are to be used in the future
    int counter {};
    
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (ships[i][j] == 1) {
                counter += 1;
            }
        }
    }
    
    // some vars for the player
    int hits = 0;
    int numberOfTurns = 0;

    // Allow the player to keep going until they have hit all four ships
    while (hits < counter) {
        string coordinates;

        cout << "Selecting coordinates" << endl;
        cout << "Choose a pair a coordinates like A1 or C4 or D3: ";
        cin >> coordinates;
        
        // checking for any invalid coordinates
        if (coordinates.length() != 2) {
            cout << "Please enter a proper set of coordinates or type (n) to close the program: ";
            cin >> coordinates;
            if (coordinates == "n") {
                return 0;
            } else if (coordinates.length() != 2 || coordinates[0] != 'A' && coordinates[0] != 'a' && coordinates[0] != 'B' && coordinates[0] != 'b' && coordinates[0] != 'C' && coordinates[0] != 'c' && coordinates[0] != 'D' && coordinates[0] != 'd') {
                cout << "You didn't listen...";
                return 0;
            }
        } else if (coordinates[0] != 'A' && coordinates[0] != 'a' && coordinates[0] != 'B' && coordinates[0] != 'b' && coordinates[0] != 'C' && coordinates[0] != 'c' && coordinates[0] != 'D' && coordinates[0] != 'd') {
            cout << "Please enter a proper set of coordinates or type (n) to close the program: ";
            cin >> coordinates;
            if (coordinates == "n") {
                return 0;
            } else if (coordinates.length() != 2 || coordinates[0] != 'A' && coordinates[0] != 'a' && coordinates[0] != 'B' && coordinates[0] != 'b' && coordinates[0] != 'C' && coordinates[0] != 'c' && coordinates[0] != 'D' && coordinates[0] != 'd') {
                cout << "You didn't listen...";
                return 0;
            }   
        }
        
        // converting char to int
        int column {};
        stringstream str;
        str << coordinates[1]; 
        str >> column;
        
        // all the logic to figure out what coordinate the player picked and if it was successful
        if (coordinates[0] == 'A' || coordinates[0] == 'a') {
            if (ships[0][column - 1]) {
                ships[0][column - 1] = 0;
                hits++;
                cout << "Hit! " << (counter-hits) << " left" << endl << endl;
            } else {
                cout << "Miss!" << (counter-hits) << " left" << endl << endl;
            }
        } else if (coordinates[0] == 'B' || coordinates[0] == 'b') {
            if (ships[1][column - 1]) {
                ships[1][column - 1] = 0;
                hits++;
                cout << "Hit! " << (counter-hits) << " left" << endl << endl;
            } else {
                cout << "Miss!" << (counter-hits) << " left" << endl << endl;
            }
        } else if (coordinates[0] == 'C' || coordinates[0] == 'c') {
            if (ships[2][column - 1]) {
                ships[2][column - 1] = 0;
                hits++;
                cout << "Hit! " << (counter-hits) << " left" << endl << endl;
            } else {
                cout << "Miss!" << (counter-hits) << " left" << endl << endl;
            }
        } else if (coordinates[0] == 'D' || coordinates[0] == 'd') {
            if (ships[3][column - 1]) {
                ships[3][column - 1] = 0;
                hits++;
                cout << "Hit! " << (counter-hits) << " left" << endl << endl;
            } else {
                cout << "Miss!" << (counter-hits) << " left" << endl << endl;
            }
        }
        // adding up the turns after every iteration
        numberOfTurns++;
    }
    
    // showing the final results
    cout << "Victory!" << endl;
    cout << "Theoretically the fastest turns possible: " << counter << endl;
    cout << "You won in " << numberOfTurns << " turns!" << endl;
    cout << "This is the ship map: " << endl;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (i < 4 && j < 3) {
                cout << copyShips[i][j] << " ";    
            } else if (i <= 3 && j == 3) {
                cout << copyShips[i][j] << endl;
            } 
        }
    }
    
    return 0;
}
