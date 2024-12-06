// COMSC-210 | Mauricio Espinosa | Lab 37 & 38

#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <list>
using namespace std;

// function to sum ascii values of a string
int gen_hash_index(const string& fileString)
{
    int index = 0;

    for (char c : fileString) {
        // convert the character to an int value and add that value to the sum variable
        index += (int) c;
    }

    return index % 1000;

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

    // map to store hash index and list of strings
    map <int, list<string>> hashTable;

    string dataString;
    int hashIndex = 0;

    while(getline(inputFile, dataString))
    {
        hashIndex = gen_hash_index(dataString);

        // insert the string in the map
        hashTable[hashIndex].push_back(dataString);
    }

    // output first 100 map entries
    int i = 0;
    for (const auto& entry : hashTable)
    {
        cout << "These strings are in Hash Index " << entry.first << ": ";

        for (const auto& str : entry.second)
        {
            cout << str << " ";
        }
        cout << endl << endl;

        i++;

        // limits to 100 output cycles
        if (i >= 100)
        {
            break;
        }

    }

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
