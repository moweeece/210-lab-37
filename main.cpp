// COMSC-210 | Mauricio Espinosa | Lab 37 & 38

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// function to sum ascii values of a string
int sum_ascii(const string& fileString)
{
    int sum = 0;

    for (char c : fileString) {
        // convert the character to an int value and add that value to the sum variable
        sum += (int) c;
    }

    return sum;

}


int main() {

    // open the file
    ifstream inputFile("data.txt");

    // file open validation
    if (!inputFile)
    {
        cerr << "Error opening the file!" << endl;
        return 1; // to exit if no file found
    }

    string dataString;
    int grandTotal = 0;

    while(getline(inputFile, dataString))
    {
        grandTotal += sum_ascii(dataString);
    }

    cout << "The grand total of all ASCII values is: " << grandTotal << endl;

    // close the file
    inputFile.close();

/*
    char a = 'A';
    cout << a << endl;
    cout << (int) a << endl;
    int b = 66;
    cout << b << endl;
    cout << (char) b << endl;
*/

    return 0;
}


/*
These targets are present in the dataset and can be used for testing:
536B9DFC93AF
1DA9D64D02A0
666D109AA22E
E1D2665B21EA
*/
