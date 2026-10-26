/*
 * Name       : Muhammad Usman Zafar
 * Reg No     : L1F25BSCS0217
 * Assignment : 02 - File Handling
 * Question   : Q1 - Stock Report (Debugging)
 */

// FIX 1: <fstream> was missing, so ifstream and ofstream were unknown types
#include <fstream>
#include <iostream>
using namespace std;

int main() {
    ifstream inFile("stock.txt");
    // FIX 2: the check was inverted; the error must show when the file did NOT open, so we need !inFile
    if (!inFile) {
        cout << "stock.txt not found!" << endl;
        return 1;
    }

    // FIX 3: a plain ofstream erases reorder.txt; ios::app keeps the old lines and adds at the end
    ofstream reorder("reorder.txt", ios::app);

    char code[10];
    int qty, count = 0, low = 0;
    double price;
    // FIX 4: total was an int, so the decimals (like .5 and .99) were cut off; it must be a double
    double total = 0;

    // FIX 5: the first line of stock.txt is a header (Code Qty Price) and must be skipped before reading items
    inFile.ignore(200, '\n');

    while (count < 50 && inFile >> code >> qty >> price) {
        count++;
        total = total + qty * price;
        if (qty < 10) {
            // FIX 6: endl was missing, so all low-stock items ended up on one line instead of one item per line
            reorder << code << " " << qty << endl;
            low++;
        }
    }
    inFile.close();
    reorder.close();

    cout << "Items: " << count << endl;
    cout << "Total stock value: " << total << endl;
    cout << "Low stock items: " << low << endl;
    return 0;
}