/*
 * Name       : Muhammad Usman Zafar
 * Reg No     : L1F25BSCS0217
 * Assignment : 02 - File Handling
 * Question   : Q5 - Expense Tracker
 */

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main() {
    int choice;

    do {
        cout << "===== Expense Tracker =====" << endl;
        cout << "1. Add an expense" << endl;
        cout << "2. Show all expenses" << endl;
        cout << "3. Show total of a category" << endl;
        cout << "4. Clear all expenses" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            char category[20];
            int amount;
            cout << "Enter category: ";
            cin >> category;
            cout << "Enter amount: ";
            cin >> amount;
            if (amount <= 0) {
                cout << "Invalid amount!" << endl;
            } else {
                ofstream out("expenses.txt", ios::app);
                out << category << " " << amount << endl;
                out.close();
                cout << "Expense saved." << endl;
            }
        }
        else if (choice == 2) {
            ifstream in("expenses.txt");
            char cat[100][20];
            int amt[100];
            int n = 0;
            if (in) {
                while (n < 100 && in >> cat[n] >> amt[n]) {
                    n++;
                }
                in.close();
            }
            if (n == 0) {
                cout << "No expenses yet." << endl;
            } else {
                int total = 0, big = 0;
                for (int i = 0; i < n; i++) {
                    cout << i + 1 << ". " << cat[i] << " " << amt[i] << endl;
                    total = total + amt[i];
                    if (amt[i] > amt[big]) {
                        big = i;
                    }
                }
                cout << "Total spent: " << total << endl;
                cout << "Largest expense: " << cat[big] << " (" << amt[big] << ")" << endl;
            }
        }
        else if (choice == 3) {
            char wanted[20], cat[20];
            int amt, count = 0, total = 0;
            cout << "Enter category: ";
            cin >> wanted;
            ifstream in("expenses.txt");
            if (in) {
                while (in >> cat >> amt) {
                    if (strcmp(cat, wanted) == 0) {
                        count++;
                        total = total + amt;
                    }
                }
                in.close();
            }
            if (count == 0) {
                cout << "No expenses found for " << wanted << endl;
            } else {
                cout << "Expenses in " << wanted << ": " << count << endl;
                cout << "Total for " << wanted << ": " << total << endl;
            }
        }
        else if (choice == 4) {
            ofstream out("expenses.txt");
            out.close();
            cout << "All expenses cleared." << endl;
        }
        else if (choice == 5) {
            cout << "Goodbye!" << endl;
        }
        else {
            cout << "Invalid choice!" << endl;
        }
    } while (choice != 5);

    return 0;
}