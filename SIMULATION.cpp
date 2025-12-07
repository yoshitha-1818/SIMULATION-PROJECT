#include <iostream>
using namespace std;

int main() {
    const int MAX = 100;      // Maximum items
    string name[MAX];         // Item names
    float price[MAX];         // Item prices
    int count = 0;            // Number of items added
    int choice;

    do {
        cout << "\n===== GROCERY BILLING SYSTEM =====\n";
        cout << "1. Add Item\n";
        cout << "2. Display Bill\n";
        cout << "3. Apply Discount\n";
        cout << "4. Find Most Expensive Item\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {

            // ---------------- ADD ITEM ----------------
            case 1: {
                if (count < MAX) {
                    cout << "Enter item name: ";
                    cin >> name[count];

                    cout << "Enter price: ";
                    cin >> price[count];

                    count++;
                    cout << "Item added successfully!\n";
                } else {
                    cout << "Item list is full!\n";
                }
                break;
            }

            // ---------------- DISPLAY BILL ----------------
            case 2: {
                if (count == 0) {
                    cout << "No items added yet!\n";
                } else {
                    float total = 0;
                    cout << "\n----- BILL DETAILS -----\n";
                    for (int i = 0; i < count; i++) {
                        cout << i+1 << ". " << name[i] << " - Rs." << price[i] << endl;
                        total += price[i];
                    }
                    cout << "Total Amount: Rs." << total << endl;
                }
                break;
            }

            // ---------------- APPLY DISCOUNT ----------------
            case 3: {
                if (count == 0) {
                    cout << "No items to apply discount!\n";
                } else {
                    float total = 0, discount, finalAmount;

                    for (int i = 0; i < count; i++)
                        total += price[i];

                    cout << "Enter discount percentage: ";
                    cin >> discount;

                    finalAmount = total - (total * discount / 100);

                    cout << "Original Amount: Rs." << total << endl;
                    cout << "After " << discount << "% discount: Rs." << finalAmount << endl;
                }
                break;
            }

            // ---------------- MOST EXPENSIVE ITEM ----------------
            case 4: {
                if (count == 0) {
                    cout << "No items added yet!\n";
                } else {
                    int index = 0;
                    for (int i = 1; i < count; i++) {
                        if (price[i] > price[index])
                            index = i;
                    }
                    cout << "Most Expensive Item: " << name[index]
                         << " (Rs." << price[index] << ")\n";
                }
                break;
            }

            // ---------------- EXIT ----------------
            case 5:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while(choice != 5);

    return 0;
}

