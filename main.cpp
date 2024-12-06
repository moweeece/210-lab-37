// COMSC-210 | Mauricio Espinosa | Lab 37 & 38

#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <list>
using namespace std;

// function prototypes
int gen_hash_index(const string& fileString);
void print_entries(const map<int, list<string>>& hash_table);
void search_key(const map<int, list<string>>& hash_table);
void add_key(map<int, list<string>>& hash_table);
void remove_key(map<int, list<string>>& hash_table);
void modify_key(map<int, list<string>>& hash_table);


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

     // close the file
    inputFile.close();

    // switch case menu
    while (true)
    {
        int userChoice;

        cout << "==========Menu==========\n";
        cout << "[1] Print first 100 entries\n";
        cout << "[2] Search for a key\n";
        cout << "[3] Add a key\n";
        cout << "[4] Remove a key\n";
        cout << "[5] Modify a key\n";
        cout << "[6] Exit\n";
        cout << "Selection: ";
        cin >> userChoice;

        switch(userChoice)
        {
            case 1:
                print_entries(hashTable);
                break;
            
            case 2:
                search_key(hashTable);
                break;
            
            case 3:
                add_key(hashTable);
                break;

            case 4:
                remove_key(hashTable);
                break;

            case 5:
                modify_key(hashTable);
                break;

            case 6:
                cout << "Exiting the program.\n";
                return 0;
            
            default:
                cout << "Invalid choice.\n";

        }

    }

    return 0;
}


/*
These targets are present in the dataset and can be used for testing:
536B9DFC93AF
1DA9D64D02A0
666D109AA22E
E1D2665B21EA
*/


// function definitions

// function to generate a hash index number
int gen_hash_index(const string& fileString)
{
    int index = 0;

    for (char c : fileString) {
        // convert the character to an int value and add that value to the sum variable
        index += (int) c;
    }

    return index % 1000;
}

// function to print the first 100 entries
void print_entries(const map<int, list<string>>& hash_table)
{
    // output first 100 map entries
    int i = 0;
    for (const auto& entry : hash_table)
    {
        cout << "These strings are in Hash Index " << entry.first << ": ";

        for (const auto& strPrint : entry.second)
        {
            cout << strPrint << " ";
        }
        cout << endl << endl;

        i++;

        // limits to 100 output cycles
        if (i >= 100)
        {
            break;
        }

    }

}

// function to search for a key
void search_key(const map<int, list<string>>& hash_table)
{
    int searchKey;
    cout << "Enter a hash index to search: ";
    cin >> searchKey;

    auto it = hash_table.find(searchKey);
    // if the iterator is not at the end, then a value is found
    if(it != hash_table.end())
    {
        cout << "Hash Index: " << it->first << " contains strings: ";
        for (const auto& strSearch : it->second)
        {
            cout << strSearch << " ";
        }
        cout << endl << endl;
    }
    else
    {
        cout << "Key not found.\n";
    }
}

// function to add a key
void add_key(map<int, list<string>>& hash_table)
{
    int newKey;
    string newString;

    cout << "Enter new hash index: ";
    cin >> newKey;
    cin.ignore();

    cout << "Enter new string to add: ";
    cin >> newString;

    hash_table[newKey].push_back(newString);
    cout << "String " << newString << " added!" << endl;
}

// function to remove a key
void remove_key(map<int, list<string>>& hash_table)
{

}

// function to modify a key
void modify_key(map<int, list<string>>& hash_table)
{

}