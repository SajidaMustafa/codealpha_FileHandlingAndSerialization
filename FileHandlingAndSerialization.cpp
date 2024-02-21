
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
vector<string> readDataFromFile(const string& filename) {
    vector<string> data;
    ifstream inputFile(filename);
    string word;

    if (!inputFile) {
        cerr << "Error opening file: " << filename << endl;
        return data;
    }
    while (inputFile >> word) {
        data.push_back(word);
    }
    inputFile.close();
    return data;
}
void writeDataToFile(const string& filename, const vector<string>& data) {
    ofstream outputFile(filename);

    if (!outputFile) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    for (const string& word : data) {
        outputFile << word << endl;
    }

    outputFile.close();
}
void displayFileContents(const vector<string>& data) {
    cout << "Contents of the file:" << endl;
    for (const auto& word : data) {
        cout << word << endl;
    }
}
int main() {
    string inputFilename;
    string outputFilename;
    bool run = true;
    int choice;
    while (run != false) {
        cout << "Press 1 to read file."<<endl;
        cout << "Press 2 to sort file." << endl;
        cout << "Press 3 to exit." << endl;
        cout << "Enter the choice: ";
        cin >> choice;
        if (choice == 1) {
            cout << "Enter file name: ";
            cin >> inputFilename;
            vector<string> data = readDataFromFile(inputFilename);
            displayFileContents(data);
        }
        else if (choice == 2) {
            cout << "Enter input file name: ";
            cin >> inputFilename;
            cout << "Enter output file name: ";
            cin >> outputFilename;
            vector<string> data = readDataFromFile(inputFilename);
            sort(data.begin(), data.end());
            writeDataToFile(outputFilename, data);
            cout << "Data sorted and written to file: " << outputFilename << endl;
        }
        else if (choice == 3) {
            run = false;
        }
        else {
            cout << "You entered the wrong choice..!" << endl;
        }
        cout << "_________________________________________________________________________________________" << endl;
    }


    return 0;
}

