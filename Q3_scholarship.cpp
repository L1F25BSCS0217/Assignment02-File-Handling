/*
 * Name       : Muhammad Usman Zafar
 * Reg No     : L1F25BSCS0217
 * Assignment : 02 - File Handling
 * Question   : Q3 - Scholarship List
 */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main() {
    char path[100];
    cout << "Enter the file name: ";
    cin.getline(path, 100);

    ifstream inFile(path);
    if (!inFile.is_open()) {
        cout << "Could not open " << path << "!" << endl;
        return 1;
    }

    int n = 0;
    inFile >> n;
    inFile.ignore(100, '\n');
    if (n > 30) {
        cout << "Too many students!" << endl;
        return 1;
    }

    ofstream out("scholarship.txt");

    char name[30], topName[30] = "";
    double cgpa, total = 0, top = -1;
    int count = 0, eligible = 0;

    for (int i = 0; i < n; i++) {
        if (!inFile.getline(name, 30, ',')) {
            break;
        }
        if (!(inFile >> cgpa)) {
            break;
        }
        inFile.ignore(100, '\n');

        cout << "[" << name << "] CGPA: " << cgpa << endl;
        count++;
        total = total + cgpa;
        if (cgpa >= 3.5) {
            out << name << "," << cgpa << endl;
            eligible++;
        }
        if (cgpa > top) {
            top = cgpa;
            strcpy(topName, name);
        }
    }
    inFile.close();
    out.close();

    if (count < n) {
        cout << "Warning: only " << count << " of " << n << " records found." << endl;
    }
    if (count == 0) {
        cout << "No students found!" << endl;
        return 0;
    }

    cout << "Students: " << count << endl;
    cout << "Average CGPA: " << total / count << endl;
    cout << "Eligible for scholarship: " << eligible << endl;
    cout << "Top student: " << topName << " (" << top << ")" << endl;
    return 0;
}