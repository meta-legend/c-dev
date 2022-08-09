#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string fileName;
string fileExtension;
string fileDirectory;
string fileContent;

int main () {
    cout << "Optional, File content, or enter (n) to decline: ";
    getline(cin, fileContent);
    if (fileContent == "n") {
        fileContent == "";
    }

    cout << "File Directory: ";
    getline(cin, fileDirectory);
    cout << "File name: ";
    cin >> fileName;
    cout << "File extension: ";
    cin >> fileExtension;
    
    ofstream file;
    file.open(fileDirectory + fileName + fileExtension);
    file << fileContent;
    file.close();
}