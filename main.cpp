// COMSC-210 | Mauricio Espinosa | Lab 37 & 38

#include <iostream>
#include <string>
using namespace std;

// function to sum ascii values of a string
int sum_ascii(const string& userString)
{
    int sum = 0;

    for (char c : userString) {
        // convert the character to an int value and add that value to the sum variable
        sum += (int) c;
    }

    return sum;

}


int main() {

    string testString;

    cout << "Enter a string to test: ";
    getline(cin, testString);

    int asciiSum = sum_ascii(testString);

    cout << "The sum of ascii values for the string " << testString << " is: " << asciiSum << endl;

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
